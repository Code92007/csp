# 201809 本地验证

当前重构版通过 C++17 编译与下列本地验证，尚未重新提交在线评测。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 卖菜 | 1 | 60 | 1 | 62 | 62 |
| B. 买菜 | 1 | 100 | 1 | 102 | 102 |
| C. 元素选择器 | 1 | 100 | 1 | 102 | 102 |
| D. 再卖菜 | 1 | 90 | 2 | 93 | 93 |
| E. 线性递推式 | 3 | 580 | 4 | 587 | 587 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 201809
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6adda03c74ace1cba9a1f8b7)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6adda10674ace1cba9a1f946)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6adda1a174ace1cba9a1f972)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6adda24c74ace1cba9a1f9b0)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6adda98c74ace1cba9a1fe91)。

最新命名及容量书写复核：[naming-followup.json](naming-followup.json)。报告保留各轮源码哈希，当前源码与对应通过记录的匹配索引见 [current-sources.json](current-sources.json)。

## E：用户 NTT 模板复验

采用用户板子的倒位序拷贝、分层根表、四组蝶形展开与 `reverse+DFT` 逆变换。生成函数、牛顿迭代高半段截断、快速平方求余和频域缓存均保留。附件容量 `1<<18` 扩为本题所需的 `1<<19`；只移植所需 NTT，不引入原板子无关的二次剩余和主程序。

使用实际交付的 GNU G++ 16、C++17、`-Wall -Wextra` 编译，无预包含兼容头。O2 与 UBSan 各通过原有 587 组：580 组独立递推对拍、3 个保存样例、4 个最大规模解析用例。另各通过 397 项专项验证：40 项按定义直接求 DFT、120 项正逆变换、172 项卷积、65 项朴素求逆；涵盖长度 1、2、4、直接乘法阈值两侧、全部二次幂到 524288，以及全零、模数减一、交错、单脉冲与随机系数。

最大规模用例含 $m=10^5$、$l=10^{12}$、300001 项输出；答案来自全零、周期和等比序列的解析式，而非旧版程序。O2 单例最慢约 0.44 秒。延迟取模在最大长度时，最后一层乘法的上界为 $(18\cdot998244353-1)(998244353-1)<2^{64}$；不能未检查数值上界就继续扩大该缓冲容量。

复现：`python3 201809/reports/verify-e-ntt.py`。当前源码 SHA-256 为 `857a65556a45f3bd2f793d83b888cc8c3d9915fba6f8cf957c0b991e7b411482`；逐项计数、命令和压力耗时见 [e-ntt-report.json](e-ntt-report.json)。原版在线记录归属保留，本轮结果仅为本地验证。
