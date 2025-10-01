import numpy as np
from typing import List, Tuple, Optional

class MultiHeadAttention:
    """多头注意力机制"""
    
    def __init__(self, d_model: int, num_heads: int):
        """
        Args:
            d_model: 模型维度
            num_heads: 注意力头数
        """
        self.d_model = d_model
        self.num_heads = num_heads
        self.d_k = d_model // num_heads  # 每个头的维度
        
        # 初始化权重矩阵
        self.W_q = np.random.randn(d_model, d_model) * 0.01
        self.W_k = np.random.randn(d_model, d_model) * 0.01
        self.W_v = np.random.randn(d_model, d_model) * 0.01
        self.W_o = np.random.randn(d_model, d_model) * 0.01
    
    def split_heads(self, x: np.ndarray) -> np.ndarray:
        """
        将输入分割成多个头
        Args:
            x: shape (seq_len, d_model)
        Returns:
            shape (num_heads, seq_len, d_k)
        """
        seq_len = x.shape[0]
        x = x.reshape(seq_len, self.num_heads, self.d_k)
        return x.transpose(1, 0, 2)
    
    def scaled_dot_product_attention(self, 
                                     Q: np.ndarray, 
                                     K: np.ndarray, 
                                     V: np.ndarray,
                                     mask: Optional[np.ndarray] = None,
                                     verbose: bool = False) -> Tuple[np.ndarray, np.ndarray]:
        """
        缩放点积注意力
        
        Args:
            Q: Query, shape (seq_len_q, d_k)
            K: Key, shape (seq_len_k, d_k)
            V: Value, shape (seq_len_k, d_k)
            mask: 注意力掩码
        """
        d_k = Q.shape[-1]
        
        # 1. 计算注意力分数: Q @ K^T / sqrt(d_k)
        scores = np.matmul(Q, K.T) / np.sqrt(d_k)
        
        if verbose:
            print(f"      原始注意力分数:")
            print(f"      {scores.round(3)}")
        
        # 2. 应用因果掩码
        if mask is not None:
            scores = np.where(mask == 0, -1e9, scores)
            if verbose:
                print(f"      应用因果掩码后:")
                print(f"      {scores.round(3)}")
        
        # 3. Softmax
        attention_weights = self.softmax(scores)
        
        
        
        # 4. 加权求和
        output = np.matmul(attention_weights, V)
        
        if verbose:
            print(f"      注意力权重 (每行和为1):")
            print(f"      {attention_weights.round(3)}")
            print(f"      output:")
            print(f"      {output.round(3)}")
        
        return output, attention_weights
    
    def softmax(self, x: np.ndarray, axis: int = -1) -> np.ndarray:
        """Softmax 函数"""
        exp_x = np.exp(x - np.max(x, axis=axis, keepdims=True))
        return exp_x / np.sum(exp_x, axis=axis, keepdims=True)
    
    def forward(self, 
                x: np.ndarray,
                mask: Optional[np.ndarray] = None,
                verbose: bool = False) -> Tuple[np.ndarray, np.ndarray]:
        """
        多头注意力前向传播
        
        Args:
            x: shape (seq_len, d_model)
            mask: shape (seq_len, seq_len)
        """
        if verbose:
            print(f"    [Multi-Head Attention]")
            print(f"      输入 shape: {x.shape}")
        
        # 1. 线性变换: Q, K, V (注意: 都来自同一个输入 x)
        Q = np.matmul(x, self.W_q)
        K = np.matmul(x, self.W_k)
        V = np.matmul(x, self.W_v)
        
        # 2. 分割成多个头
        Q = self.split_heads(Q)
        K = self.split_heads(K)
        V = self.split_heads(V)
        
        # 3. 对每个头计算注意力
        outputs = []
        all_attention_weights = []
        
        for i in range(self.num_heads):
            if verbose and i == 0:
                print(f"\n      === 头 {i+1} 详细计算 ===")
            
            output, attn_weights = self.scaled_dot_product_attention(
                Q[i], K[i], V[i], mask, verbose=(verbose and i == 0)
            )
            outputs.append(output)
            all_attention_weights.append(attn_weights)
        
        # 4. 拼接所有头
        outputs = np.concatenate(outputs, axis=-1)
        all_attention_weights = np.stack(all_attention_weights, axis=0)
        
        # 5. 最后的线性变换
        output = np.matmul(outputs, self.W_o)
        
        if verbose:
            print(f"      输出 shape: {output.shape}\n")
        
        return output, all_attention_weights


class FeedForward:
    """前馈神经网络: FFN(x) = max(0, xW1 + b1)W2 + b2"""
    
    def __init__(self, d_model: int, d_ff: int):
        self.W1 = np.random.randn(d_model, d_ff) * 0.01
        self.b1 = np.zeros(d_ff)
        self.W2 = np.random.randn(d_ff, d_model) * 0.01
        self.b2 = np.zeros(d_model)
    
    def forward(self, x: np.ndarray, verbose: bool = False) -> np.ndarray:
        if verbose:
            print(f"    [Feed Forward Network]")
            print(f"      输入 shape: {x.shape}")
        
        hidden = np.maximum(0, np.matmul(x, self.W1) + self.b1)  # ReLU
        output = np.matmul(hidden, self.W2) + self.b2
        
        if verbose:
            print(f"      隐藏层 shape: {hidden.shape}")
            print(f"      输出 shape: {output.shape}\n")
        
        return output


class DecoderOnlyBlock:
    """
    Decoder-Only Block (GPT-style)
    只有自注意力 + FFN,没有交叉注意力!
    """
    
    def __init__(self, d_model: int, num_heads: int, d_ff: int):
        self.self_attention = MultiHeadAttention(d_model, num_heads)
        self.feed_forward = FeedForward(d_model, d_ff)
        self.layer_norm_eps = 1e-6
    
    def layer_norm(self, x: np.ndarray) -> np.ndarray:
        """Layer Normalization"""
        mean = np.mean(x, axis=-1, keepdims=True)
        std = np.std(x, axis=-1, keepdims=True)
        return (x - mean) / (std + self.layer_norm_eps)
    
    def forward(self,
                x: np.ndarray,
                mask: Optional[np.ndarray] = None,
                verbose: bool = False) -> Tuple[np.ndarray, np.ndarray]:
        """
        Args:
            x: shape (seq_len, d_model)
            mask: 因果掩码
            
        Returns:
            output: shape (seq_len, d_model)
            attention_weights: 注意力权重
        """
        if verbose:
            print(f"  步骤1: 掩码自注意力 (Masked Self-Attention)")
        
        # 1. 自注意力 (Q, K, V 都来自 x)
        attn_output, attn_weights = self.self_attention.forward(
            x, mask=mask, verbose=verbose
        )
        x = self.layer_norm(x + attn_output)  # Add & Norm
        
        if verbose:
            print(f"  步骤2: 前馈网络 (Feed Forward)")
        
        # 2. 前馈网络
        ff_output = self.feed_forward.forward(x, verbose=verbose)
        x = self.layer_norm(x + ff_output)  # Add & Norm
        
        return x, attn_weights


class GPTDecoder:
    """
    GPT-style Decoder-Only 模型
    特点:
    - 只有自注意力,没有交叉注意力
    - 使用因果掩码防止看到未来信息
    - 适用于文本生成任务
    """
    
    def __init__(self, 
                 vocab_size: int,
                 d_model: int = 32,
                 num_heads: int = 4,
                 num_layers: int = 2,
                 d_ff: int = 256,
                 max_seq_len: int = 100):
        self.vocab_size = vocab_size
        self.d_model = d_model
        self.max_seq_len = max_seq_len
        
        # Token Embedding
        self.token_embedding = np.random.randn(vocab_size, d_model) * 0.01
        
        # Positional Encoding
        self.pos_encoding = self.create_positional_encoding(max_seq_len, d_model)
        
        # Decoder Blocks (注意: 只有自注意力!)
        self.blocks = [DecoderOnlyBlock(d_model, num_heads, d_ff) 
                       for _ in range(num_layers)]
        
        # 输出映射到词表
        self.output_projection = np.random.randn(d_model, vocab_size) * 0.01
    
    def create_positional_encoding(self, max_len: int, d_model: int) -> np.ndarray:
        """创建正弦位置编码"""
        pe = np.zeros((max_len, d_model))
        position = np.arange(0, max_len).reshape(-1, 1)
        div_term = np.exp(np.arange(0, d_model, 2) * -(np.log(10000.0) / d_model))
        
        pe[:, 0::2] = np.sin(position * div_term)
        pe[:, 1::2] = np.cos(position * div_term)
        
        return pe
    
    def create_causal_mask(self, seq_len: int) -> np.ndarray:
        """
        创建因果掩码 (下三角矩阵)
        
        例如 seq_len=4:
        [[1, 0, 0, 0],    位置0只能看位置0
         [1, 1, 0, 0],    位置1可以看0,1
         [1, 1, 1, 0],    位置2可以看0,1,2
         [1, 1, 1, 1]]    位置3可以看所有
        """
        mask = np.tril(np.ones((seq_len, seq_len)))
        return mask
    
    def forward(self, 
                input_ids: np.ndarray,
                verbose: bool = False) -> Tuple[np.ndarray, List]:
        """
        前向传播
        
        Args:
            input_ids: shape (seq_len,)
            
        Returns:
            logits: shape (seq_len, vocab_size)
            all_attentions: 所有层的注意力权重
        """
        seq_len = len(input_ids)
        
        if verbose:
            print(f"\n{'='*70}")
            print(f"GPT Decoder-Only 前向传播")
            print(f"{'='*70}")
            print(f"输入序列长度: {seq_len}")
            print(f"输入 token IDs: {input_ids}")
        
        # 1. Embedding + Positional Encoding
        x = self.token_embedding[input_ids]
        x = x + self.pos_encoding[:seq_len]
        
        if verbose:
            print(f"Embedding + 位置编码后 shape: {x.shape}")
        
        # 2. 创建因果掩码
        causal_mask = self.create_causal_mask(seq_len)
        
        if verbose:
            print(f"\n因果掩码 (Causal Mask):")
            print(causal_mask.astype(int))
            print(f"  → 保证每个位置只能看到自己和之前的位置\n")
        
        # 3. 通过所有 Decoder Block
        all_attentions = []
        
        for i, block in enumerate(self.blocks):
            if verbose:
                print(f"{'='*70}")
                print(f"Decoder Block {i+1}/{len(self.blocks)}")
                print(f"{'='*70}")
            
            x, attn = block.forward(x, mask=causal_mask, verbose=verbose)
            all_attentions.append(attn)
        
        # 4. 映射到词表
        logits = np.matmul(x, self.output_projection)
        
        if verbose:
            print(f"{'='*70}")
            print(f"输出层: 映射到词表")
            print(f"{'='*70}")
            print(f"最终 logits shape: {logits.shape}")
            print(f"  → 每个位置都有 {self.vocab_size} 个词的分数\n")
        
        return logits, all_attentions
    
    def generate(self,
                 prompt_ids: List[int],
                 max_new_tokens: int = 10,
                 temperature: float = 1.0,
                 top_k: int = 0,
                 top_p: float = 1.0,
                 verbose: bool = False) -> List[int]:
        """
        自回归生成
        
        Args:
            prompt_ids: 初始提示的 token IDs
            max_new_tokens: 最多生成多少个新 token
            temperature: 温度参数
            top_k: top-k 采样
            top_p: top-p 采样
        """
        generated = prompt_ids.copy()
        
        if verbose:
            print(f"\n{'='*70}")
            print(f"自回归生成过程")
            print(f"{'='*70}")
            print(f"初始提示: {prompt_ids}")
            print(f"最大生成长度: {max_new_tokens}")
            print(f"{'='*70}\n")
        
        for step in range(max_new_tokens):
            # 1. 前向传播获取 logits
            input_array = np.array(generated)
            logits, _ = self.forward(input_array, verbose=False)
            
            # 2. 只取最后一个位置的 logits
            next_token_logits = logits[-1] / temperature
            
            # 3. 采样
            probs = self.softmax(next_token_logits)
            
            # Top-k 采样
            if top_k > 0:
                indices_to_remove = probs < np.sort(probs)[-top_k]
                probs[indices_to_remove] = 0
                probs = probs / np.sum(probs)
            
            # Top-p 采样
            if top_p < 1.0:
                sorted_indices = np.argsort(probs)[::-1]
                sorted_probs = probs[sorted_indices]
                cumulative_probs = np.cumsum(sorted_probs)
                
                remove_indices = cumulative_probs > top_p
                if np.any(remove_indices):
                    remove_idx = np.where(remove_indices)[0][0] + 1
                    indices_to_remove = sorted_indices[remove_idx:]
                    probs[indices_to_remove] = 0
                    probs = probs / np.sum(probs)
            
            next_token = np.random.choice(len(probs), p=probs)
            generated.append(next_token)
            
            if verbose:
                print(f"步骤 {step+1}: 生成 token {next_token} (概率: {probs[next_token]:.4f})")
        
        return generated
    
    def softmax(self, x: np.ndarray) -> np.ndarray:
        exp_x = np.exp(x - np.max(x))
        return exp_x / np.sum(exp_x)


def demo_gpt_decoder():
    """演示 GPT-style Decoder-Only 模型"""
    
    # 词表
    vocab = {
        0: '<PAD>',
        1: '<BOS>',
        2: '<EOS>',
        3: '今天',
        4: '天气',
        5: '很',
        6: '好',
        7: '我',
        8: '很',
        9: '开心',
        10: '。',
    }
    
    id_to_word = vocab
    word_to_id = {v: k for k, v in vocab.items()}
    
    vocab_size = len(vocab)
    
    # 创建 GPT Decoder
    model = GPTDecoder(
        vocab_size=vocab_size,
        d_model=8,
        num_heads=1,
        num_layers=1,
        d_ff=256
    )
    
    print("="*70)
    print("示例: GPT-style Decoder-Only 模型")
    print("="*70)
    print("\n特点:")
    print("  ✓ 只有自注意力 (Self-Attention)")
    print("  ✗ 没有交叉注意力 (Cross-Attention)")
    print("  ✓ 使用因果掩码防止看到未来")
    print("  ✓ 适合文本生成任务\n")
    
    # 输入序列: "今天 天气 很"
    input_text = ["今天", "天气", "很"]
    input_ids = [word_to_id[w] for w in input_text]
    
    print(f"输入文本: {' '.join(input_text)}")
    print(f"输入 IDs: {input_ids}")
    
    # 前向传播
    logits, attentions = model.forward(
        np.array(input_ids),
        verbose=True
    )
    
    # 分析预测结果
    print(f"\n{'='*70}")
    print(f"预测下一个词")
    print(f"{'='*70}")
    
    last_logits = logits[-1]
    probs = np.exp(last_logits) / np.sum(np.exp(last_logits))
    top_k = 5
    top_indices = np.argsort(probs)[-top_k:][::-1]
    
    print(f"\n位置 '{input_text[-1]}' 之后的 Top-5 预测:")
    for idx in top_indices:
        print(f"  {id_to_word[idx]}: {probs[idx]:.4f}")
    
    # 可视化注意力权重
    print(f"\n{'='*70}")
    print(f"注意力权重可视化 (Layer 1, Head 1)")
    print(f"{'='*70}")
    
    attn = attentions[0][0]  # 第一层，第一个头
    print(f"\n注意力矩阵 shape: {attn.shape}")
    print(f"每一行表示该位置对所有位置的注意力分布:\n")
    
    for i, row in enumerate(attn):
        print(f"位置 {i} ('{input_text[i]}'):")
        for j, weight in enumerate(row):
            if j <= i:  # 因果掩码只能看到之前的
                print(f"  → 对 '{input_text[j]}' 的注意力: {weight:.3f}")
        print()
    
    # 自回归生成
    print(f"{'='*70}")
    print(f"自回归生成示例")
    print(f"{'='*70}")
    
    prompt = [word_to_id["今天"], word_to_id["天气"]]
    generated_ids = model.generate(
        prompt_ids=prompt,
        max_new_tokens=3,
        temperature=1.0,
        verbose=True
    )
    
    generated_text = ' '.join([id_to_word[i] for i in generated_ids])
    print(f"\n生成结果: {generated_text}")


if __name__ == "__main__":
    demo_gpt_decoder()