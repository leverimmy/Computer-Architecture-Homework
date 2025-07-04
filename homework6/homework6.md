# 第 6 次作业

## 第 1 题（教材 5.8）

> 假设有一条长流水线，仅对条件转移指令使用分支目标缓冲。假设分支预测错误的开销为 $4$ 个时钟周期，缓存不命中的开销为 $3$ 个时钟周期。假设：命中率为 $90\%$，预测精度为 $90\%$，分支频率为 $15\%$，没有分支的基本 CPI 为 $1$。
>
> (1) 求程序执行的 CPI。
>
> (2) 相对于采用固定的 $2$ 个时钟周期延迟的分支处理，采用哪种方法能使程序执行速度更快？

(1) 有两种开销：缓存不命中，或者是缓存命中但分支预测错误。程序执行的 CPI 为：

$$
\begin{align*}
\text{CPI}_1 & = 1 + 15\% \times\left(10\% \times 3 + 90\% \times (10\%\times 4)\right) \\
& = 1.099
\end{align*}
$$

(2) 如果采用固定的 $2$ 个时钟周期延迟的分支处理，则只有一种开销：每条分支指令都会引入延迟。程序执行的 CPI 为：

$$
\begin{align*}
\text{CPI}_2 & = 1 + 15\% \times 2 \\
& = 1.3
\end{align*}
$$

由于 $\text{CPI}_1 < \text{CPI}_2$，因此第一种方法能使程序执行速度更快。

## 第 2 题（教材 5.9）

> 假设分支目标缓冲的命中率为 $90\%$，程序中无条件转移指令的比例为 $5\%$，没有无条件转移指令的程序 CPI 值为 $1$。假设分支目标缓冲中包含分支目标指令，允许无条件转移指令进入分支目标缓冲，则程序的 CPI 值为多少？假设原来的 $\text{CPI} = 1.1$。

设分支预测错误的开销为 $x$ 个时钟周期，则原来的 CPI 为

$$
1.1 = 1 + 5\% \cdot x
$$

解得 $x = 2$。

现在无条件转移指令可以进入 BTB，额外开销只有一种可能：该指令为无条件转移指令，且 BTB 未命中。现在程序的 CPI 值为：

$$
\begin{align*}
\text{CPI} & = 1 + 5\% \times 10\% \cdot x \\
& = 1 + 5\% \times 10\% \times 2 \\
& = 1.01
\end{align*}
$$
