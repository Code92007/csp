# 202112 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058553e5d1fced2e455ef2)。 | `a14fca2b4fef02c62a318bd095b890086e374181af1173cba480221517c1df64` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0585bae5d1fced2e456053)。 | `df03115fd864f57e5ea881a48baa56ab4d01395ba3897fda4795869c12b4857a` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0585f7e5d1fced2e4561db)。 | `ae8c78fb105bfb0112312c2e9052528d87a04e6a6a43a2cfeba6f0f493e1e920` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05863be5d1fced2e4562db)。 | `bb1a1e84c7a4339da29af7d64f102125d4bb97e829478501e6d6073f3f377d96` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058679e5d1fced2e456373)。 | `29b11094b69fc9d3165ab9c39c61d5b4fd7d2d765730d78e25cf6b41cbec1e85` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

该本地验证阶段未进行本轮在线提交。题解保留的在线评测记录属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **1560 个不同输入**，UBSan 通过 **1555 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|167|167|
|B|258|258|
|C|142|142|
|D|322|322|
|E|671|666|

输入来源：retained_independent：407；additional_independent：999；saved_sample：9；constructive_stress：3；compatibility_stress：2；additional_independent_checker：140。

Direct point-by-point sequence queries; independently constructed barcode polynomial checks; cell-by-cell disk owner/value/history; exhaustive actual tree paths. Maximum random trees additionally compare the historical accepted source, classified separately.

A/B 逐整数求函数值并累加，补足小 N、相邻断点与 r=1。C 另写字符模式转移表构造数据前缀，并在 3^j（1≤j≤k）上用 Horner 法检查完整码字多项式为零，覆盖 s=-1..8；当前 C 为 2 个保存样例加 140 个独立性质检查输入，没有把旧生成器直接 subprocess 检查的 100 组虚计入本次捕获数。

D 使用逐格主人、历史和值模拟，另覆盖 10^9 磁盘边界与删除恢复。E 使用真实树路径的最小/最大编号独立枚举，覆盖 600 个新增小树；另有 n=500000 的顺序链、零容差星形与全合法星形三个解析构造。三个构造 O2 约 0.182 秒、0.043 秒、0.049 秒，仅代表本次运行。

两组 n=500000 随机树仅作为原版 Accepted 源码的兼容/性能补充（compatibility_stress），不充作独立正确性 oracle。E 保留位图分块、基数排序、低分支重心计数与整体合法判定，移除快读类后使用 scanf；图准备函数返回后自动释放临时图缓冲区。

复现：`python3 202112/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 源码 SHA-256

- `A.cpp`：`a14fca2b4fef02c62a318bd095b890086e374181af1173cba480221517c1df64`
- `B.cpp`：`df03115fd864f57e5ea881a48baa56ab4d01395ba3897fda4795869c12b4857a`
- `C.cpp`：`dd596c795524a03c4b7cba19033769deb0aaedf75479d7c67a9a9eabb3d23074`
- `D.cpp`：`e44f7d7a98a1d4e5c3b5cf2504668c2b2cb9539434a8bdb89c537b0761b97c76`
- `E.cpp`：`f199ef82a6377fd37ecf8b04ab1072c9982792942953d656638d391cdf448e69`

## 最终命名与常量复核

掩码使用 `S`，模数使用 `mod`；小于十万的容量常量展开为普通整数。仅调整本场涉及的命名或等值常量，原算法与历史独立对拍记录保留。当前源码重新通过 O2、UBSan 编译及全部保存样例，详见 [nightly-review-followup.json](nightly-review-followup.json)。

- `A.cpp` 当前 SHA-256：`a14fca2b4fef02c62a318bd095b890086e374181af1173cba480221517c1df64`
- `B.cpp` 当前 SHA-256：`df03115fd864f57e5ea881a48baa56ab4d01395ba3897fda4795869c12b4857a`
- `C.cpp` 当前 SHA-256：`ae8c78fb105bfb0112312c2e9052528d87a04e6a6a43a2cfeba6f0f493e1e920`
- `D.cpp` 当前 SHA-256：`e44f7d7a98a1d4e5c3b5cf2504668c2b2cb9539434a8bdb89c537b0761b97c76`
- `E.cpp` 当前 SHA-256：`230d1274c7769486ac2f389fd2283885575238c9699e475bf3f69ceb0f17317b`

## 后续函数与变量命名复验

D 的 `value` 方法改名为 `op`；E 的基数排序频次数组改名为 `cnt`、位移轮次改名为 `b`，实际计算函数 `calc` 保留。D 与 E 的 O2、UBSan 编译均无诊断；O2 分别通过322和671个输入，UBSan分别通过322和666个输入。E 的五十万点随机树检查覆盖基数排序分支，其中两个旧程序兼容性压力检查单独分类，没有冒充独立暴力。

[当前源码哈希与结果](name-followup-report.json) · [复现脚本](verify-name-followup.py)。原报告与前轮命名记录保留为历史。

- `D.cpp` 当前 SHA-256：`bb1a1e84c7a4339da29af7d64f102125d4bb97e829478501e6d6073f3f377d96`
- `E.cpp` 当前 SHA-256：`29b11094b69fc9d3165ab9c39c61d5b4fd7d2d765730d78e25cf6b41cbec1e85`
