# 202305 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0562cae5d1fced2e4517d5)。 | `cf469ba06e4fcf69f36739059d8813f8a687b8238017030be00322c08f063b5a` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b056336e5d1fced2e4518e7)。 | `aaa4eda6f66102f27861a8bce3e279db42d0c0f5d35271ea5dfa1c8a5be14477` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05638ee5d1fced2e4519f7)。 | `e6772cbcb6503ca3c3c3b84f4a7f3111231e1435f584e6b2709a583138302bc2` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0563eee5d1fced2e451a95)。 | `24b806a5a2dcf465c54404ff0bfe23a090b2461fd9184f738602fda7ef28f1ec` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05644fe5d1fced2e451b76)。 | `6e1d292cd7725bb031fd47b1cef08670b2c3725e6e9ef023318fe215168dd41c` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

该本地验证阶段未进行本轮在线提交。题解保留的在线评测记录属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **797 个不同输入**，UBSan 通过 **794 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|63|63|
|B|103|102|
|C|124|123|
|D|284|284|
|E|223|222|

输入来源：retained_independent：474；additional_independent：311；saved_sample：9；constructive_stress：3。

Complete board comparison; direct Q*K-transpose then V multiplication; independently encoded Snappy streams; exhaustive label assignment; raw-route state Dijkstra without edge dominance or SOS preprocessing.

A 逐字符比较棋盘；B 保留直接先算 QK^T 再乘 V 的独立 oracle；C 从已知原文独立构造字面量与前向引用流，覆盖长度 60/61、256/257、65536/65537、重叠复制和约 2 MiB 数据；D 全枚举所有点选址，补 K4 核心及细分边；E 对原始线路直接运行状态 Dijkstra，不使用支配删边或 SOS 预处理。

B 额外通过 n=10000、d=20、全部元素为 1000 的构造，输出项为 2×10^17；C 最大字面量约 2 MiB 解压正确；E 覆盖十目标字母环路。O2 本次分别约 0.049 秒、0.156 秒、0.008 秒，时间仅代表本次运行。

复现：`python3 202305/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 源码 SHA-256

- `A.cpp`：`cf469ba06e4fcf69f36739059d8813f8a687b8238017030be00322c08f063b5a`
- `B.cpp`：`7e75691807092dcfebc7aeed29458cfc4f8eb20d2d8b3912b7fa96c6a2300f78`
- `C.cpp`：`e6772cbcb6503ca3c3c3b84f4a7f3111231e1435f584e6b2709a583138302bc2`
- `D.cpp`：`96fe79c09a7aa926f3c7594c010ba82119be1208a731add10af6721460683c6d`
- `E.cpp`：`e433104ce39f9850193b6f2d9bae98b875e994acc9e6def0e719c6bb1be3c079`

## 最终命名与常量复核

掩码使用 `S`，模数使用 `mod`；小于十万的容量常量展开为普通整数。仅调整本场涉及的命名或等值常量，原算法与历史独立对拍记录保留。当前源码重新通过 O2、UBSan 编译及全部保存样例，详见 [nightly-review-followup.json](nightly-review-followup.json)。

- `A.cpp` 当前 SHA-256：`cf469ba06e4fcf69f36739059d8813f8a687b8238017030be00322c08f063b5a`
- `B.cpp` 当前 SHA-256：`aaa4eda6f66102f27861a8bce3e279db42d0c0f5d35271ea5dfa1c8a5be14477`
- `C.cpp` 当前 SHA-256：`e6772cbcb6503ca3c3c3b84f4a7f3111231e1435f584e6b2709a583138302bc2`
- `D.cpp` 当前 SHA-256：`96fe79c09a7aa926f3c7594c010ba82119be1208a731add10af6721460683c6d`
- `E.cpp` 当前 SHA-256：`e433104ce39f9850193b6f2d9bae98b875e994acc9e6def0e719c6bb1be3c079`

## 全局辅助状态复验

D 的 dfn/low/fa/cnt/sep/st/ord/label 改为 `N=10010` 的全局数组，迭代栈使用 `top`；每次 low-link 检查清空标记并重置栈，森林 DP 每次重新初始化父节点和序列长度。E 的优先队列改为全局对象，每轮 Dijkstra 完整弹空后再处理下一个起点。

O2 重新通过 D286、E223 共509个不同输入，UBSan通过其中508个。D含10000点、10标签的链与星，分别覆盖最大栈深和删根后9999个分量，答案均由统一费用直接确定为29998。[本轮当前哈希与完整结果](global-storage-followup.json)；复现 [verify-global-storage.py](verify-global-storage.py)。原报告保留为历史版本。

- `D.cpp`：`24b806a5a2dcf465c54404ff0bfe23a090b2461fd9184f738602fda7ef28f1ec`
- `E.cpp`：`6e1d292cd7725bb031fd47b1cef08670b2c3725e6e9ef023318fe215168dd41c`
