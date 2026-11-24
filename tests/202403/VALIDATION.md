# 202403 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055caae5d1fced2e450bcb)。 | `46dcec9c7c37722118b60ae8b644e4e48b983b7852424db54862772aa5ce6845` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055d18e5d1fced2e450c43)。 | `f4af6528d2b1e5ee7cc980c2793f4e4523d1f09d4fe81ec584a7ac06300b80bb` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055d7be5d1fced2e450c99)。 | `0bf263fdafe6f1cc25241d3dcac911f22deadf7e83bbd9f4454af39e6c7e8add` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055dd5e5d1fced2e450da5)。 | `6e3a2ecf632d0c96f9168e73c5961d9c57a6f36c6a9c2e8c6b6bcfe31888c3e8` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055e2ce5d1fced2e450e1f)。 | `bd8198461f1d1aea7e989e516d124e7996419cfbf83fba1627762d0c795df149` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

该本地验证阶段未进行本轮在线提交。题解保留的在线评测记录属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **986 个不同输入**，UBSan 通过 **984 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|63|63|
|B|106|105|
|C|273|273|
|D|322|322|
|E|222|221|

输入来源：retained_independent：450；saved_sample：11；additional_independent：523；constructive_stress：2。

Per-article sets, normalized string sets, exact rational matrix rank, literal water dictionary/minimum explosion simulation, explicit live-parent folder merging.

A 用每篇文章的集合与总频数直接统计；B 用统一大小写的集合运算；C 以 Fraction 精确有理数高斯消元对拍，不以模素数算法自证；D 用字典保存存活水量、每步重选最左待爆位置；E 显式修改活节点父亲，直接数祖先路径，独立验证一层合并。

额外覆盖 C 的 40×40 满秩/重复列矩阵、D 连锁爆炸顺序、E 大整数数据量与合并后再次合并。B 五十万重复单词、E 五十万节点星形树构造在 O2 通过，分别约 0.051 秒、0.049 秒，时间仅代表本机此次运行。

复现：`python3 202403/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 源码 SHA-256

- `A.cpp`：`46dcec9c7c37722118b60ae8b644e4e48b983b7852424db54862772aa5ce6845`
- `B.cpp`：`f4af6528d2b1e5ee7cc980c2793f4e4523d1f09d4fe81ec584a7ac06300b80bb`
- `C.cpp`：`5830665c266d28d4d4119eab6f15068ed4b7af364a3428c76473c97a30bf2ef6`
- `D.cpp`：`6e3a2ecf632d0c96f9168e73c5961d9c57a6f36c6a9c2e8c6b6bcfe31888c3e8`
- `E.cpp`：`15d3c9902b74090184f00cc268192c82cf4cd5279e0cb545323491847e7398fe`

## 后续风格调整

C 的素数起点写作 `1e9+7`，与原整数值相同。E 的离栈标记改为 `ed`，避免与标准库 `exit` 名字混淆；深度查询先保存 `ans` 再输出。本轮 O2 重新通过 C 的 273 个、E 的 222 个不同输入，UBSan 通过其中 494 个；包括精确有理数秩 oracle、直接父子关系模拟与五十万点构造。两份题解已同步。

原始 [report.json](report.json) 保留历史源码哈希；当前源码、编译和定向验证见 [style-followup-report.json](style-followup-report.json)，复现脚本为 [verify-style-followup.py](verify-style-followup.py)。

- C：`0bf263fdafe6f1cc25241d3dcac911f22deadf7e83bbd9f4454af39e6c7e8add`
- E：`bd8198461f1d1aea7e989e516d124e7996419cfbf83fba1627762d0c795df149`
