# 202509 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b054563e5d1fced2e44e250)。 | `ebec3287fd4999bc4e9b986691e1526e7b58bc3e2651034abfb9c2f4d83fada7` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0545cfe5d1fced2e44e2f0)。 | `0b3b127e87de2706f8c194544025e02b807687714d7f0d380b4512344bd0a2d8` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05464fe5d1fced2e44e407)。 | `e9d6976a5a6a902e5cfa1f3f6320acead297ab8fff6b12b84f709036476ca2a9` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05ab06e5d1fced2e45bdac)。 | `6d340704052cfdf30dbaba52b2636e7ec91a72a16cdf56e81188759e3b19f632` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05477ce5d1fced2e44e5ea)。 | `f30997019754ecdbad11e1e9a94bec8515d9360f4681cd3deeaded7e9d073288` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

[历史版本与评测记录](previous-versions.md#problem-d)。

该本地验证阶段未进行本轮在线提交。题解中保留的 100 分 Accepted 链接属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **1442 个不同输入**，UBSan 通过其中 **1440 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|独立验证方法|
|---|---:|---:|---|
|A|65|65|整数几何计数，负零、整数与一/两位小数、圆周边界|
|B|68|68|逐阈值逐位置直接匹配，空图案与最大灰度范围|
|C|103|103|直接生成 Huffman 编码及头表模拟，转义、补零、容量淘汰|
|D|312|311|显式搜索树上路径求 mex，四点以内递归树及全部点权排列|
|E|894|893|枚举每日造/验选择的余额 DP，三天费用组合与所有小预算|

共复用 490 个已有独立 oracle 输入、10 个保存样例，新增 940 个独立边界/穷举输入和 2 个最大规模构造。两份程序对比不作为独立正确性证据。

D 额外通过 200000 点长链构造（全路径 mex 为 n、缺零路径 mex 为 0）；E 额外通过 500000 天等费用构造（答案 250000）。这两组 O2 构造分别约用时 0.06 秒、0.49 秒，时间只表示本机此次运行。

复现：`python3 202509/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例和独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；原 oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 初版全量验证源码 SHA-256

- `A.cpp`：`ebec3287fd4999bc4e9b986691e1526e7b58bc3e2651034abfb9c2f4d83fada7`
- `B.cpp`：`3e756a2b9f936b5f4f10ddc831ecd4c3735518b7d141b3471089a03bb58cf087`
- `C.cpp`：`834ebd52033b63dcd96dfbfab3a6886d38590b5d78fd28ec8b6ee966cb7d30a8`
- `D.cpp`：`6f09013511acaaf01629bcd02bc7e294b41a3142bee1cdb306db185f7517d4bb`
- `E.cpp`：`9a44c2a9a289ec5056b78fb4ec43394929ad0ab61957630a529eeaf3fe89c591`

## Review 后的当前版本

按用户 review 调整 B 字模、C 命名、D 短赋值与输出、E 显式类型及二分结果变量，均未改变算法。O2 与 UBSan 分别重新通过 B 的 2 个样例、C 的全部 103 个输入、D 的全部 312 个输入和 E 的全部 894 个输入（共 1311 个，包括 D/E 最大构造）。A 源码保持原哈希。

定向验证记录：[style-followup-report.json](style-followup-report.json)；复现：[verify-style-followup.py](verify-style-followup.py)。原 report.json 保留上一次全量验证历史。

- 当前 `B.cpp`：`0b3b127e87de2706f8c194544025e02b807687714d7f0d380b4512344bd0a2d8`
- 当前 `C.cpp`：`e9d6976a5a6a902e5cfa1f3f6320acead297ab8fff6b12b84f709036476ca2a9`
- 当前 `D.cpp`：`9132211a9175bee8afe2165aeadf144a23c9c91edacdb0749e661f94a1bd09da`
- 当前 `E.cpp`：`f30997019754ecdbad11e1e9a94bec8515d9360f4681cd3deeaded7e9d073288`

<!-- performance-revision:D:start -->

## D 性能复测与当前源码

当前线性版本真实结果为 [100 分 Accepted](https://oj.shumeng.tech/record/6b05ab06e5d1fced2e45bdac)，源码 SHA-256 为 `6d340704052cfdf30dbaba52b2636e7ec91a72a16cdf56e81188759e3b19f632`。首轮版本的判题与哈希归属见[历史版本记录](previous-versions.md#problem-d)。

本次未重新运行历史测试；独立对拍、边界和压力结果来自所附原始审查，C++17 编译来自已冻结记录。下方原本地记录及“当前版本”字样均保留其历史阶段归属；现行哈希与结论以本节和顶部五题表为准。证据见 [修复验证汇总](performance-revision-D.json)及[随附审查](performance-revision/202509D/independent-review-review.md)。

<!-- performance-revision:D:end -->
