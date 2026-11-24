# 201312 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a668e5d1fced2e45b50c)。 | `1eccdb2025f426ed406db7a660c25cb024db017cbe6f803985d44905290e3513` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a6a5e5d1fced2e45b641)。 | `fe3211ab6d5ca2d92327fd7077c405543541d5b39cabcafd2cf4233c46746b12` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a6e3e5d1fced2e45b6b2)。 | `d085dc5bf3906bb95b8fad9584b206335929af9001f16ff4ea68a4a959985dbc` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a720e5d1fced2e45b767)。 | `888315c8f29416a93ef4a41861647fd99a890c0961eb2cfa410a54f39196d655` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a75ee5d1fced2e45b7f7)。 | `6df458c6bbf3b4908a85ba0405fcfd6c517cca44bda4008661c64449774d01d2` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

该本地验证阶段未进行本轮在线提交。题解保留的在线评测记录属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **2888 个不同输入**，UBSan 通过 **2885 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|102|102|
|B|304|304|
|C|1255|1254|
|D|103|103|
|E|1124|1122|

输入来源：retained_independent：321；additional_independent：2554；saved_sample：10；constructive_stress：3。

Frequency counter/minimum tie, independent ISBN weighted checksum, exhaustive subinterval histogram minima, combinatorial digit-count/interleaving formula independent of bitmask DP, literal forward reachability from every reachable cell independent of reverse BFS.

A 补随机计数和最小值同分规则；B 分别验证合法校验码与错误校验码（含 X）；C 穷举长度 1…6、高度 1…3 的全部直方图，逐个枚举区间与区间最低柱求最大面积，并补 10 万根、高度 10^9 的面积 10^14 构造。

D 的新增 oracle 不使用掩码 DP，而是枚举 0/1 与 2/3 两个有序序列的正计数，再组合交错：首位必须为 2，选 k 个 0/1 数字占据剩余 n−1 位中的位置，累加 (k−1)(n−k−1)C(n−1,k)。逐项核对 n=1…100，并以一份 T=1000 的输入覆盖 n=1…1000，检验原单组与存档多组格式。

E 穷举所有 S/T 位置不同的 2×2 小网格、固定 S/T 的全部 2×3 字符组合，补随机单向与墙格案例。oracle 对每个从 S 可达格单独进行正向可达性搜索判断能否到 T，独立于源码的反向图 BFS。另有 50×50 全连通与墙面分隔构造。本题组为第 0 次练习题组，保留原版在线记录，不新增在线提交结论。

复现：`python3 201312/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 源码 SHA-256

- `A.cpp`：`1eccdb2025f426ed406db7a660c25cb024db017cbe6f803985d44905290e3513`
- `B.cpp`：`fe3211ab6d5ca2d92327fd7077c405543541d5b39cabcafd2cf4233c46746b12`
- `C.cpp`：`d085dc5bf3906bb95b8fad9584b206335929af9001f16ff4ea68a4a959985dbc`
- `D.cpp`：`514714fd7b66484fb9555d004256e28ce4a42c10bae2eac68238aa7df26eb752`
- `E.cpp`：`6df458c6bbf3b4908a85ba0405fcfd6c517cca44bda4008661c64449774d01d2`

## 最终命名与常量复核

掩码使用 `S`，模数使用 `mod`；小于十万的容量常量展开为普通整数。仅调整本场涉及的命名或等值常量，原算法与历史独立对拍记录保留。当前源码重新通过 O2、UBSan 编译及全部保存样例，详见 [nightly-review-followup.json](nightly-review-followup.json)。

- `A.cpp` 当前 SHA-256：`1eccdb2025f426ed406db7a660c25cb024db017cbe6f803985d44905290e3513`
- `B.cpp` 当前 SHA-256：`fe3211ab6d5ca2d92327fd7077c405543541d5b39cabcafd2cf4233c46746b12`
- `C.cpp` 当前 SHA-256：`d085dc5bf3906bb95b8fad9584b206335929af9001f16ff4ea68a4a959985dbc`
- `D.cpp` 当前 SHA-256：`888315c8f29416a93ef4a41861647fd99a890c0961eb2cfa410a54f39196d655`
- `E.cpp` 当前 SHA-256：`6df458c6bbf3b4908a85ba0405fcfd6c517cca44bda4008661c64449774d01d2`
