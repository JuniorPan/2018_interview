import numpy as np
from typing import List, Tuple, Optional

class MultiHeadAttention:
    """多头注意力机制"""
    
    def __init__(self, d_model: int, num_heads: int, seed: Optional[int] = None):
        """
        Args:
            d_model: 模型维度
            num_heads: 注意力头数
            seed: 随机种子（用于可复现性）
        """
        self.d_model = d_model
        self.num_heads = num_heads
        self.d_k = d_model // num_heads  # 每个头的维度
        
        # 使用更大的初始化范围，产生更多样的注意力模式
        if seed is not None:
            np.random.seed(seed)
        
        scale = 0.1  # 增大初始化范围
        self.W_q = np.random.randn(d_model, d_model) * scale
        self.W_k = np.random.randn(d_model, d_model) * scale
        self.W_v = np.random.randn(d_model, d_model) * scale
        self.W_o = np.random.randn(d_model, d_model) * scale
        
        # RoPE 频率
        self.rope_freqs = self.create_rope_frequencies(self.d_k)
    
    def create_rope_frequencies(self, d_k: int, max_len: int = 10000, base: float = 10000.0) -> np.ndarray:
        """为每个注意力头创建 RoPE 频率"""
        inv_freq = 1.0 / (base ** (np.arange(0, d_k, 2).astype(float) / d_k))
        positions = np.arange(max_len)
        freqs = np.outer(positions, inv_freq)
        return freqs
    
    def apply_rope(self, x: np.ndarray, seq_len: int) -> np.ndarray:
        """
        应用 RoPE 到 Q 或 K
        Args:
            x: shape (num_heads, seq_len, d_k)
            seq_len: 序列长度
        """
        num_heads, seq_len, d_k = x.shape
        
        # 对每个头应用 RoPE
        for h in range(num_heads):
            # 重塑为复数
            x_complex = x[h].reshape(seq_len, -1, 2)
            x_complex = x_complex[..., 0] + 1j * x_complex[..., 1]
            
            # 旋转
            freqs_complex = np.exp(1j * self.rope_freqs[:seq_len])
            x_rotated = x_complex * freqs_complex
            
            # 转回实数
            x[h] = np.stack([x_rotated.real, x_rotated.imag], axis=-1).reshape(seq_len, d_k)
        
        return x
    
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
        
        if verbose:
            print(f"      注意力权重 (每行和为1):")
            print(f"      {attention_weights.round(3)}")
        
        # 4. 加权求和
        output = np.matmul(attention_weights, V)
        
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
        多头注意力前向传播 (使用 RoPE)
        
        Args:
            x: shape (seq_len, d_model)
            mask: shape (seq_len, seq_len)
        """
        seq_len = x.shape[0]
        
        if verbose:
            print(f"    [Multi-Head Attention with RoPE]")
            print(f"      输入 shape: {x.shape}")
        
        # 1. 线性变换: Q, K, V (都来自同一个输入 x)
        Q = np.matmul(x, self.W_q)
        K = np.matmul(x, self.W_k)
        V = np.matmul(x, self.W_v)
        
        # 2. 分割成多个头
        Q = self.split_heads(Q)  # (num_heads, seq_len, d_k)
        K = self.split_heads(K)
        V = self.split_heads(V)
        
        # 3. 应用 RoPE 到 Q 和 K (不对 V 应用)
        Q = self.apply_rope(Q, seq_len)
        K = self.apply_rope(K, seq_len)
        
        if verbose:
            print(f"      应用 RoPE 位置编码")
        
        # 4. 对每个头计算注意力
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
        
        # 5. 拼接所有头
        outputs = np.concatenate(outputs, axis=-1)
        all_attention_weights = np.stack(all_attention_weights, axis=0)
        
        # 6. 最后的线性变换
        output = np.matmul(outputs, self.W_o)
        
        if verbose:
            print(f"      输出 shape: {output.shape}\n")
        
        return output, all_attention_weights


class FeedForward:
    """前馈神经网络: FFN(x) = max(0, xW1 + b1)W2 + b2"""
    
    def __init__(self, d_model: int, d_ff: int, seed: Optional[int] = None):
        if seed is not None:
            np.random.seed(seed + 1)  # 不同的种子
        
        self.W1 = np.random.randn(d_model, d_ff) * 0.1
        self.b1 = np.zeros(d_ff)
        self.W2 = np.random.randn(d_ff, d_model) * 0.1
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
    
    def __init__(self, d_model: int, num_heads: int, d_ff: int, seed: Optional[int] = None):
        self.self_attention = MultiHeadAttention(d_model, num_heads, seed=seed)
        self.feed_forward = FeedForward(d_model, d_ff, seed=seed)
        self.layer_norm_eps = 1e-6
    
    def rms_norm(self, x: np.ndarray) -> np.ndarray:
        """
        RMS Normalization (Root Mean Square Normalization)
        RMSNorm(x) = x / RMS(x) * scale
        其中 RMS(x) = sqrt(mean(x^2))
        
        相比 LayerNorm:
        - 不减去均值 (没有 re-centering)
        - 只做缩放归一化
        - 计算更快,效果相当
        """
        # 计算 RMS: sqrt(mean(x^2) + eps)
        rms = np.sqrt(np.mean(x ** 2, axis=-1, keepdims=True) + self.layer_norm_eps)
        
        # 归一化
        x_norm = x / rms
        
        # 可学习的缩放参数 (这里简化为1)
        # 实际中这是可学习的: x_norm * self.scale
        return x_norm
    
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
        
        # 1. 自注意力 (Q, K, V 都来自 x, 使用RoPE)
        attn_output, attn_weights = self.self_attention.forward(
            x, mask=mask, verbose=verbose
        )
        x = self.rms_norm(x + attn_output)  # Add & RMSNorm
        
        if verbose:
            print(f"  步骤2: 前馈网络 (Feed Forward)")
        
        # 2. 前馈网络
        ff_output = self.feed_forward.forward(x, verbose=verbose)
        x = self.rms_norm(x + ff_output)  # Add & RMSNorm
        
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
                 d_model: int = 64,
                 num_heads: int = 4,
                 num_layers: int = 2,
                 d_ff: int = 256,
                 max_seq_len: int = 100,
                 seed: Optional[int] = None):
        self.vocab_size = vocab_size
        self.d_model = d_model
        self.max_seq_len = max_seq_len
        
        if seed is not None:
            np.random.seed(seed)
        
        # Token Embedding (不需要单独的位置编码，RoPE在Attention中应用)
        self.token_embedding = np.random.randn(vocab_size, d_model) * 0.5
        
        # Decoder Blocks (使用 RoPE 和 RMSNorm)
        self.blocks = [
            DecoderOnlyBlock(d_model, num_heads, d_ff, seed=seed+i if seed else None) 
            for i in range(num_layers)
        ]
        
        # 输出映射到词表
        self.output_projection = np.random.randn(d_model, vocab_size) * 0.5
    
    def create_rope_frequencies(self, d_model: int, max_len: int = 10000, base: float = 10000.0) -> np.ndarray:
        """
        创建 RoPE 的旋转频率
        RoPE (Rotary Position Embedding): 通过旋转变换来编码位置信息
        """
        # 计算每个维度对的频率
        # theta_i = base^(-2i/d) for i in [0, d/2)
        inv_freq = 1.0 / (base ** (np.arange(0, d_model, 2).astype(float) / d_model))
        
        # 为每个位置生成角度
        # positions: [0, 1, 2, ..., max_len-1]
        positions = np.arange(max_len)
        
        # freqs shape: (max_len, d_model/2)
        freqs = np.outer(positions, inv_freq)
        
        return freqs
    
    def apply_rope(self, x: np.ndarray, freqs: np.ndarray) -> np.ndarray:
        """
        应用 RoPE 旋转位置编码
        
        Args:
            x: shape (seq_len, d_model) 或 (seq_len, num_heads, d_k)
            freqs: shape (seq_len, d_model/2)
        """
        # 确保是 2D
        original_shape = x.shape
        if len(x.shape) == 3:
            seq_len, num_heads, d_k = x.shape
            x = x.reshape(seq_len, -1)
        
        seq_len, d_model = x.shape
        
        # 将 x 重塑为复数形式: (seq_len, d_model/2)
        # 每对相邻维度看作复数的实部和虚部
        x_complex = x.reshape(seq_len, -1, 2)
        x_complex = x_complex[..., 0] + 1j * x_complex[..., 1]
        
        # 创建旋转矩阵 e^(i*theta)
        freqs_complex = np.exp(1j * freqs[:seq_len])
        
        # 应用旋转
        x_rotated = x_complex * freqs_complex
        
        # 转回实数形式
        x_out = np.stack([x_rotated.real, x_rotated.imag], axis=-1)
        x_out = x_out.reshape(seq_len, d_model)
        
        # 恢复原始形状
        if len(original_shape) == 3:
            x_out = x_out.reshape(original_shape)
        
        return x_out
    
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
        前向传播 (使用 RoPE 和 RMSNorm)
        
        Args:
            input_ids: shape (seq_len,)
            
        Returns:
            logits: shape (seq_len, vocab_size)
            all_attentions: 所有层的注意力权重
        """
        seq_len = len(input_ids)
        
        if verbose:
            print(f"\n{'='*70}")
            print(f"GPT Decoder-Only 前向传播 (RoPE + RMSNorm)")
            print(f"{'='*70}")
            print(f"输入序列长度: {seq_len}")
            print(f"输入 token IDs: {input_ids}")
        
        # 1. Token Embedding (不加位置编码，RoPE在Attention中应用)
        x = self.token_embedding[input_ids]
        
        if verbose:
            print(f"Token Embedding shape: {x.shape}")
            print(f"  → 不需要加位置编码，位置信息由 RoPE 提供")
        
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


def compare_rope_vs_sinusoidal():
    """对比 RoPE 和传统正弦位置编码"""
    print("\n" + "="*70)
    print("RoPE vs 传统正弦位置编码对比")
    print("="*70)
    
    print("\n【传统正弦位置编码】")
    print("  方式: 加性 (Additive)")
    print("  公式: x = token_embedding + pos_embedding")
    print("  特点:")
    print("    - 位置信息直接加到 embedding 上")
    print("    - 绝对位置编码")
    print("    - 固定的位置向量")
    
    print("\n【RoPE 旋转位置编码】")
    print("  方式: 乘性 (Multiplicative) - 通过旋转")
    print("  公式: Q' = rotate(Q, θ*pos), K' = rotate(K, θ*pos)")
    print("  特点:")
    print("    ✓ 相对位置编码 (注意力分数只依赖相对位置)")
    print("    ✓ 更好的长度外推性")
    print("    ✓ 不增加额外参数")
    print("    ✓ 位置信息在 Attention 计算中自然融入")
    
    print("\n  数学原理:")
    print("    将相邻维度看作复数: (x[0], x[1]) → x[0] + i*x[1]")
    print("    旋转 θ 角度: z' = z * e^(iθ)")
    print("    结果: Q_m · K_n = f(m-n) ← 只依赖相对位置差!")
    
    print("\n  为什么更好?")
    print("    例: 训练时最长 512 tokens")
    print("    正弦编码: 处理 1024 tokens 时位置 513-1024 从未见过")
    print("    RoPE: 可以自然外推到更长序列 ✓")


def compare_rmsnorm_vs_layernorm():
    """对比 RMSNorm 和 LayerNorm"""
    print("\n" + "="*70)
    print("RMSNorm vs LayerNorm 对比")
    print("="*70)
    
    print("\n【LayerNorm】")
    print("  公式: y = (x - μ) / σ * γ + β")
    print("  其中: μ = mean(x), σ = std(x)")
    print("  步骤:")
    print("    1. 计算均值 μ")
    print("    2. 计算标准差 σ")
    print("    3. 去中心化: (x - μ)")
    print("    4. 归一化: / σ")
    print("    5. 缩放和平移: * γ + β")
    
    print("\n【RMSNorm】")
    print("  公式: y = x / RMS(x) * γ")
    print("  其中: RMS(x) = sqrt(mean(x²) + ε)")
    print("  步骤:")
    print("    1. 计算均方根 RMS")
    print("    2. 归一化: x / RMS")
    print("    3. 缩放: * γ")
    print("  ")
    print("  简化:")
    print("    ✗ 不计算均值 (省略去中心化)")
    print("    ✗ 不需要 bias β")
    print("    ✓ 计算更快 (~7-64% 更快)")
    print("    ✓ 数值更稳定")
    
    print("\n  实际效果:")
    print("    - T5: 使用 RMSNorm 后效果相当或更好")
    print("    - LLaMA: 全面采用 RMSNorm")
    print("    - Gopher: 实验表明 RMSNorm 训练更稳定")
    
    # 数值示例
    print("\n  数值示例:")
    x = np.array([1.0, 2.0, 3.0, 4.0])
    
    # LayerNorm
    mean = np.mean(x)
    std = np.std(x)
    ln_out = (x - mean) / std
    
    # RMSNorm
    rms = np.sqrt(np.mean(x ** 2))
    rms_out = x / rms
    
    print(f"    输入 x: {x}")
    print(f"    LayerNorm:  {ln_out.round(3)} (去中心化)")
    print(f"    RMSNorm:    {rms_out.round(3)} (保持分布)")


def visualize_rope_mechanism():
    """可视化 RoPE 工作机制"""
    print("\n" + "="*70)
    print("RoPE 工作机制详解")
    print("="*70)
    
    print("\n【步骤1: 构造复数】")
    print("  将相邻维度配对为复数:")
    print("  Q = [q₀, q₁, q₂, q₃, ...]")
    print("  →  [q₀+iq₁, q₂+iq₃, ...]")
    print("      ↑        ↑")
    print("    复数1    复数2")
    
    print("\n【步骤2: 计算旋转角度】")
    print("  对于位置 m 和维度对 i:")
    print("  θᵢ = m / (10000^(2i/d))")
    print("  ")
    print("  例如 d=64, 位置m=5:")
    print("    维度对0: θ₀ = 5 / 10000^(0/64) = 5.000")
    print("    维度对1: θ₁ = 5 / 10000^(2/64) = 4.442")
    print("    维度对2: θ₂ = 5 / 10000^(4/64) = 3.944")
    print("    ...")
    print("  → 不同维度对使用不同的旋转频率")
    
    print("\n【步骤3: 应用旋转】")
    print("  对每个复数 z 旋转 θ 角度:")
    print("  z' = z * e^(iθ)")
    print("  ")
    print("  几何意义:")
    print("    复平面上的旋转")
    print("      ↑ Im")
    print("      |")
    print("      |  z' (旋转后)")
    print("      | /θ")
    print("      |/ ")
    print("    ──┼───→ Re")
    print("      |z (原始)")
    
    print("\n【步骤4: 相对位置的魔法】")
    print("  Q在位置m: Q'ₘ = Qₘ * e^(iθₘ)")
    print("  K在位置n: K'ₙ = Kₙ * e^(iθₙ)")
    print("  ")
    print("  注意力分数:")
    print("  Q'ₘ · K'ₙ = (Qₘ * e^(iθₘ)) · (Kₙ * e^(iθₙ))")
    print("           = (Qₘ · Kₙ) * e^(iθ(m-n))")
    print("           = (Qₘ · Kₙ) * e^(iθΔ)")
    print("  ")
    print("  关键: 只依赖相对位置差 Δ = m - n ✓")
    print("  ")
    print("  例子:")
    print("    位置3看位置1: θ(3-1) = θ₂")
    print("    位置5看位置3: θ(5-3) = θ₂  ← 相同!")
    print("    → 相同的相对距离 = 相同的注意力模式")


def show_modern_llm_architecture():
    """展示现代 LLM 的完整架构"""
    print("\n" + "="*70)
    print("现代 LLM 架构演进")
    print("="*70)
    
    print("\n【经典 Transformer (2017)】")
    print("  Token Embedding")
    print("    + 正弦位置编码")
    print("  ↓")
    print("  × N layers:")
    print("    - Multi-Head Attention")
    print("    - LayerNorm")
    print("    - FFN (ReLU)")
    print("    - LayerNorm")
    print("  ↓")
    print("  Linear → Softmax")
    
    print("\n【GPT-3 (2020)】")
    print("  Token Embedding")
    print("    + 学习的位置编码")
    print("  ↓")
    print("  × 96 layers:")
    print("    - LayerNorm (Pre-LN)")
    print("    - Multi-Head Attention")
    print("    - LayerNorm")
    print("    - FFN (GELU)")
    print("  ↓")
    print("  LayerNorm → Linear")
    
    print("\n【LLaMA (2023) - 现代架构】")
    print("  Token Embedding")
    print("    (无额外位置编码)")
    print("  ↓")
    print("  × 32-80 layers:")
    print("    - RMSNorm (Pre-Norm) ← 更快")
    print("    - Attention + RoPE ← 相对位置")
    print("    - RMSNorm")
    print("    - SwiGLU FFN ← 更好的激活")
    print("  ↓")
    print("  RMSNorm → Linear")
    
    print("\n【关键改进总结】")
    improvements = [
        ("位置编码", "绝对正弦", "RoPE 相对位置", "更好的外推性"),
        ("归一化", "LayerNorm", "RMSNorm", "更快更稳定"),
        ("归一化位置", "Post-Norm", "Pre-Norm", "训练更稳定"),
        ("激活函数", "ReLU", "SwiGLU", "表达能力更强"),
        ("注意力", "标准MHA", "GQA/MQA", "推理更快"),
    ]
    
    print("\n  组件         | 传统方案    | 现代方案      | 优势")
    print("  " + "-"*60)
    for component, old, new, benefit in improvements:
        print(f"  {component:12} | {old:11} | {new:13} | {benefit}")


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
    
    # 首先展示理论知识
    compare_rope_vs_sinusoidal()
    compare_rmsnorm_vs_layernorm()
    visualize_rope_mechanism()
    show_modern_llm_architecture()
    
    # 创建 GPT Decoder (使用随机种子让每次运行结果不同)
    model = GPTDecoder(
        vocab_size=vocab_size,
        d_model=64,
        num_heads=4,
        num_layers=2,
        d_ff=256,
        seed=None  # 设为 None 让每次运行都不同，或设置固定值如 42 让结果可复现
    )
    
    print("\n" + "="*70)
    print("实际运行: GPT-style Decoder-Only 模型")
    print("="*70)
    print("\n模型配置:")
    print(f"  词表大小: {vocab_size}")
    print(f"  模型维度: 64")
    print(f"  注意力头数: 4")
    print(f"  层数: 2")
    print(f"  FFN 维度: 256")
    print("\n架构特点:")
    print("  ✓ 只有自注意力 (Self-Attention)")
    print("  ✗ 没有交叉注意力 (Cross-Attention)")
    print("  ✓ 使用因果掩码防止看到未来")
    print("  ✓ RoPE: 旋转位置编码 (替代传统正弦位置编码)")
    print("  ✓ RMSNorm: 均方根归一化 (替代 LayerNorm)")
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
        print(f"位置 {i} ('{input_text[i]}') 的注意力分布:")
        
        # 创建可视化柱状图
        max_bar_length = 40
        for j, weight in enumerate(row):
            if j <= i:  # 因果掩码只能看到之前的
                bar_length = int(weight * max_bar_length)
                bar = '█' * bar_length
                print(f"  → '{input_text[j]:4s}': {weight:.3f} {bar}")
        
        # 显示注意力是否集中
        entropy = -np.sum(row[:i+1] * np.log(row[:i+1] + 1e-10))
        max_entropy = np.log(i + 1)
        concentration = 1 - (entropy / max_entropy if max_entropy > 0 else 0)
        
        if concentration > 0.7:
            print(f"       [注意力集中 ★★★]")
        elif concentration > 0.4:
            print(f"       [注意力适中 ★★]")
        else:
            print(f"       [注意力分散 ★]")
        print()
    
    # 自回归生成
    print(f"{'='*70}")
    print(f"自回归生成示例")
    print(f"{'='*70}")
    
    prompt = [word_to_id["今天"], word_to_id["天气"]]
    
    print("\n生成 3 次，观察随机性:")
    for run in range(3):
        print(f"\n--- 第 {run+1} 次生成 ---")
        generated_ids = model.generate(
            prompt_ids=prompt.copy(),
            max_new_tokens=3,
            temperature=1.0,
            verbose=False
        )
        
        generated_text = ' '.join([id_to_word[i] for i in generated_ids])
        print(f"结果: {generated_text}")


if __name__ == "__main__":
    demo_gpt_decoder()