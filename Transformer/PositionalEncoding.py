import torch
import torch.nn as nn
from torch import Tensor
import math
import copy

class PositionalEncoding(nn.Module):
  def __init__(self, d_model: int, dropout: float = 0.1, max_length: int = 5000):
    """
    Args:
      d_model:      dimension of embeddings
      dropout:      randomly zeroes-out some of the input
      max_length:   max sequence length
    """
    # inherit from Module
    super().__init__()     

    # initialize dropout                  
    self.dropout = nn.Dropout(p=dropout)      

    # create tensor of 0s
    pe = torch.zeros(max_length, d_model)    

    # create position column   
    k = torch.arange(0, max_length).unsqueeze(1)  

    # calc divisor for positional encoding 
    div_term = torch.exp(                                 
            torch.arange(0, d_model, 2) * -(math.log(10000.0) / d_model)
    )

    # calc sine on even indices
    pe[:, 0::2] = torch.sin(k * div_term)    

    # calc cosine on odd indices   
    pe[:, 1::2] = torch.cos(k * div_term)  

    # add dimension     
    pe = pe.unsqueeze(0)          

    # buffers are saved in state_dict but not trained by the optimizer                        
    self.register_buffer("pe", pe)                        

  def forward(self, x: Tensor):
    """
    Args:
      x:        embeddings (batch_size, seq_length, d_model)
    
    Returns:
                embeddings + positional encodings (batch_size, seq_length, d_model)
    """
    # add positional encoding to the embeddings
    x = x + self.pe[:, : x.size(1)].requires_grad_(False) 

    # perform dropout
    return self.dropout(x)

class Embeddings(nn.Module):
  def __init__(self, vocab_size: int, d_model: int):
    """
    Args:
      vocab_size:     size of vocabulary
      d_model:        dimension of embeddings
    """
    # inherit from nn.Module
    super().__init__()   
     
    # embedding look-up table (lut)                          
    self.lut = nn.Embedding(vocab_size, d_model)   

    # dimension of embeddings 
    self.d_model = d_model                          

  def forward(self, x: Tensor):
    """
    Args:
      x: input Tensor (batch_size, seq_length)
      
    Returns:
        embedding vector
    """
    # embeddings by constant sqrt(d_model)
    # return self.lut(x) * math.sqrt(self.d_model)  
    return self.lut(x) 


class MultiHeadAttention(nn.Module):
  def __init__(self, d_model: int = 512, n_heads: int = 8, dropout: float = 0.1):
    """
    Args:
        d_model:      dimension of embeddings
        n_heads:      number of self attention heads
        dropout:      probability of dropout occurring
    """
    super().__init__()
    assert d_model % n_heads == 0            # ensure an even num of heads
    self.d_model = d_model                   # 512 dim
    self.n_heads = n_heads                   # 8 heads
    self.d_key = d_model // n_heads          # assume d_value equals d_key | 512/8=64

    self.Wq = nn.Linear(d_model, d_model)    # query weights
    self.Wk = nn.Linear(d_model, d_model)    # key weights
    self.Wv = nn.Linear(d_model, d_model)    # value weights
    self.Wo = nn.Linear(d_model, d_model)    # output weights

    self.dropout = nn.Dropout(p=dropout)     # initialize dropout layer  

  def forward(self, query: Tensor, key: Tensor, value: Tensor, mask: Tensor = None):
    """
    Args:
       query:         query vector         (batch_size, q_length, d_model)
       key:           key vector           (batch_size, k_length, d_model)
       value:         value vector         (batch_size, s_length, d_model)
       mask:          mask for decoder     

    Returns:
       output:        attention values     (batch_size, q_length, d_model)
       attn_probs:    softmax scores       (batch_size, n_heads, q_length, k_length)
    """
    batch_size = key.size(0)                  
        
    # calculate query, key, and value tensors
    Q = self.Wq(query)                       # (32, 10, 512) x (512, 512) = (32, 10, 512)
    K = self.Wk(key)                         # (32, 10, 512) x (512, 512) = (32, 10, 512)
    V = self.Wv(value)                       # (32, 10, 512) x (512, 512) = (32, 10, 512)

    # split each tensor into n-heads to compute attention

    # query tensor
    Q = Q.view(batch_size,                   # (32, 10, 512) -> (32, 10, 8, 64) 
               -1,                           # -1 = q_length
               self.n_heads,              
               self.d_key
               ).permute(0, 2, 1, 3)         # (32, 10, 8, 64) -> (32, 8, 10, 64) = (batch_size, n_heads, q_length, d_key)
    # key tensor
    K = K.view(batch_size,                   # (32, 10, 512) -> (32, 10, 8, 64) 
               -1,                           # -1 = k_length
               self.n_heads,              
               self.d_key
               ).permute(0, 2, 1, 3)         # (32, 10, 8, 64) -> (32, 8, 10, 64) = (batch_size, n_heads, k_length, d_key)
    # value tensor
    V = V.view(batch_size,                   # (32, 10, 512) -> (32, 10, 8, 64) 
               -1,                           # -1 = v_length
               self.n_heads, 
               self.d_key
               ).permute(0, 2, 1, 3)         # (32, 10, 8, 64) -> (32, 8, 10, 64) = (batch_size, n_heads, v_length, d_key)
       
    # computes attention
    # scaled dot product -> QK^{T}
    scaled_dot_prod = torch.matmul(Q,        # (32, 8, 10, 64) x (32, 8, 64, 10) -> (32, 8, 10, 10) = (batch_size, n_heads, q_length, k_length)
                                   K.permute(0, 1, 3, 2)
                                   ) / math.sqrt(self.d_key)      # sqrt(64)
        
    # fill those positions of product as (-1e10) where mask positions are 0
    if mask is not None:
      scaled_dot_prod = scaled_dot_prod.masked_fill(mask == 0, -1e10)

    # apply softmax 
    attn_probs = torch.softmax(scaled_dot_prod, dim=-1)
        
    # multiply by values to get attention
    A = torch.matmul(self.dropout(attn_probs), V)       # (32, 8, 10, 10) x (32, 8, 10, 64) -> (32, 8, 10, 64)
                                                        # (batch_size, n_heads, q_length, k_length) x (batch_size, n_heads, v_length, d_key) -> (batch_size, n_heads, q_length, d_key)

    # reshape attention back to (32, 10, 512)
    A = A.permute(0, 2, 1, 3).contiguous()              # (32, 8, 10, 64) -> (32, 10, 8, 64)
    A = A.view(batch_size, -1, self.n_heads*self.d_key) # (32, 10, 8, 64) -> (32, 10, 8*64) -> (32, 10, 512) = (batch_size, q_length, d_model)
        
    # push through the final weight layer
    output = self.Wo(A)                                 # (32, 10, 512) x (512, 512) = (32, 10, 512) 

    return output, attn_probs                           # return attn_probs for visualization of the scores

def build_vocab(data):
  # tokenize the data and remove duplicates
  vocab = list(set(tokenize(data)))
  # sort the vocabulary
  vocab.sort()
  # assign an integer to each word
  stoi = {word:i for i, word in enumerate(vocab)}

  return stoi

def tokenize(sequence):
  # remove punctuation
  for punc in ["!", ".", "?"]:
    sequence = sequence.replace(punc, "")
  
  # split the sequence on spaces and lowercase each token
  return [token.lower() for token in sequence.split(" ")]

if __name__ == "__main__":

    d_model = 8
    max_length = 10
    drop_out = 0
    
    # set the output to 2 decimal places without scientific notation
    torch.set_printoptions(precision=2, sci_mode=False)
    sequences = ["I wonder what will come next!",
             "This is a basic example paragraph.",
             "Hello what is a basic split?"]
    
    # build the vocab
    example = "Hello! This is an example of a paragraph that has been split into its basic components. I wonder what will come next! Any guesses?"
    stoi = build_vocab(example)
    
    # tokenize the sequences
    tokenized_sequences = [tokenize(seq) for seq in sequences]
    # index the sequences 
    indexed_sequences = [[stoi[word] for word in seq] for seq in tokenized_sequences]

    # convert the sequences to a tensor
    tensor_sequences = torch.tensor(indexed_sequences).long()
    
    

    # vocab size
    vocab_size = len(stoi)


    tokenized_sequences = [tokenize(seq) for seq in sequences]

    pe = PositionalEncoding(d_model, drop_out, max_length)
    
    lut = nn.Embedding(vocab_size, d_model) # look-up table (lut)
    embeddings = lut(tensor_sequences)
    
    
    # print('pe: \n', pe.state_dict()['pe'])
    # print('lut: \n', lut.state_dict()['weight'])
    
    # print('tensor_sequences: \n', tensor_sequences)
    # print('embeddings: \n', embeddings)
    
    X = pe(embeddings)
    print("X: \n", X)
    
    Wq = nn.Linear(d_model, d_model)
    Wk = nn.Linear(d_model, d_model)
    Wv = nn.Linear(d_model, d_model)
    
    print('Wq.state_dict()[\'weight\']: \n', Wq.state_dict()['weight'])

    Q = Wq(X) # (3,6,8)x(broadcast 8,8) = (3,6,8)
    K = Wk(X) # (3,6,8)x(broadcast 8,8) = (3,6,8)
    V = Wv(X) # (3,6,8)x(broadcast 8,8) = (3,6,8)    
    
    print("Q: \n", Q)
    
    batch_size = Q.size(0)   
    n_heads = 4
    d_key = d_model//n_heads # 8/4 = 2

    # query tensor | -1 = query_length | (3, 6, 8) -> (3, 6, 4, 2)
    Q = Q.view(batch_size, -1, n_heads, d_key)

    # value tensor | -1 = key_length | (3, 6, 8) -> (3, 6, 4, 2) 
    K = K.view(batch_size, -1, n_heads, d_key)

    # value tensor | -1 = value_length | (3, 6, 8) -> (3, 6, 4, 2) 
    V = V.view(batch_size, -1, n_heads, d_key)   
    
    print("Q: \n", Q)    
    
    
    # query tensor | (3, 6, 4, 2) -> (3, 4, 6, 2) 
    Q = Q.permute(0, 2, 1, 3)
    # key tensor | (3, 6, 4, 2) -> (3, 4, 6, 2) 
    K = K.permute(0, 2, 1, 3)
    # value tensor | (3, 6, 4, 2) -> (3, 4, 6, 2) 
    V = V.permute(0, 2, 1, 3)    
    
    print("Q: \n", Q[0])   
    print("Q: \n", Q[1])            

    # calculate scaled dot product
    scaled_dot_prod = torch.matmul(Q, K.permute(0, 1, 3, 2)) / math.sqrt(d_key) # (batch_size, n_heads, Q_length, K_length)
    # apply softmax to get context for each token and others
    attn_probs = torch.softmax(scaled_dot_prod, dim=-1) # (batch_size, n_heads, Q_length, K_length)
    
    print('scaled_dot_prod: \n', scaled_dot_prod)
    print('attn_probs: \n', attn_probs)
    
    
    A = torch.matmul(attn_probs, V) # (batch_size, n_heads, Q_length, d_key)
    print("A: \n", A)
    
    # transpose from (3, 4, 6, 2) -> (3, 6, 4, 2)
    A = A.permute(0, 2, 1, 3).contiguous()

    # reshape from (3, 6, 4, 2) -> (3, 6, 8) = (batch_size, Q_length, d_model)
    A = A.view(batch_size, -1, n_heads*d_key)
    print("A: \n", A)
    
    Wo = nn.Linear(d_model, d_model)

    # (3, 6, 8) x (broadcast 8, 8) = (3, 6, 8)
    output = Wo(A)  
    print("output: \n", output)