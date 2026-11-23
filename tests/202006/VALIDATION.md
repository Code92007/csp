# 202006 本地验证

本次重构未重新提交在线评测。题解保留的在线评测记录属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **809 个不同输入**，UBSan 通过 **805 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|62|62|
|B|102|101|
|C|123|122|
|D|269|268|
|E|253|252|

输入来源：retained_independent：435；additional_independent：363；saved_sample：7；constructive_stress：4。

Direct signs and sparse dictionaries; explicit line-by-line Markdown rendering; literal simultaneous substitution and substring enumeration; exhaustive product purchase quantities with original dependency rules.

A 检查一般、竖直与水平直线；新增用例保证点不在线上。B 以稀疏字典/直接相同下标乘积对拍。C 保留逐行实际渲染 oracle，并补 250000 行、约 20 MiB 的单段文本，宽度 80 时答案恰为 250000。

D 用逐字符同时替换后直接匹配作独立 oracle，覆盖 n=0、单字符和重叠模式；十亿轮、十万字符全 1 模式的构造答案为 0，因为替换结果不会出现相邻的两个 1。E 直接枚举不购买或购买的每种整数数量，并按原题两种依赖筛选方案，覆盖负收益、凹凸函数及循环依赖。

最大构造还包含两个五十万非零项向量（答案 5×10^13）和一万商品依赖链（答案 10^7）。O2 对 B/C/D/E 四组构造本次约 0.068/0.309/0.007/0.005 秒，仅代表此次运行。

复现：`python3 202006/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 源码 SHA-256

- `A.cpp`：`499159d30459e793344c3cde4357bd3f74d4ec0937103476fb8b231f74f6186a`
- `B.cpp`：`69870b23476a53266183dbff56366f91b08a729eff4cd95169f9a8a559fe3d4c`
- `C.cpp`：`c3cdb976a0b8511c2dc56748901abf641cccdcf39f62fcb54cf034e63be1dd9b`
- `D.cpp`：`215ba10451621e37fbcbcb3e54951aebe93119aafd30024735e46e2579f4b328`
- `E.cpp`：`7bd7e46548bbf9b36cfb1f2b4229f2adc9f896bc375ab312ced748fab75afa27`

## 最终命名与常量复核

掩码使用 `S`，模数使用 `mod`；小于十万的容量常量展开为普通整数。仅调整本场涉及的命名或等值常量，原算法与历史独立对拍记录保留。当前源码重新通过 O2、UBSan 编译及全部保存样例，详见 [nightly-review-followup.json](nightly-review-followup.json)。

- `A.cpp` 当前 SHA-256：`499159d30459e793344c3cde4357bd3f74d4ec0937103476fb8b231f74f6186a`
- `B.cpp` 当前 SHA-256：`69870b23476a53266183dbff56366f91b08a729eff4cd95169f9a8a559fe3d4c`
- `C.cpp` 当前 SHA-256：`c3cdb976a0b8511c2dc56748901abf641cccdcf39f62fcb54cf034e63be1dd9b`
- `D.cpp` 当前 SHA-256：`0167f3e95faee47f37bab8b18205ba577f9c80e37850668f40acc8e7b6791f68`
- `E.cpp` 当前 SHA-256：`7bd7e46548bbf9b36cfb1f2b4229f2adc9f896bc375ab312ced748fab75afa27`

## B 后续短语句排版

相邻的 `++i`、`++j` 放在同一行，执行顺序与表达式均未改变。当前版本重新通过 O2、UBSan clean 编译及保存样例，历史全量对拍不重复计数。 [本轮结果与当前哈希](b-increment-followup.json)，复现 `python3 tools/nightly/verify_short_review.py --repo /path/to/repository`。

- `B.cpp` 当前 SHA-256：`28bc09c0fa003b727c263298127472f21b0d17004dfc29d9201861aefda3f941`
