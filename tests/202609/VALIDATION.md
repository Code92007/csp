# 202609 重构版验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053aaee5d1fced2e44d256)。 | `dd814f4d41176bf7e0954ae14c1a672c74a0aacd048054526d93459dd2009af7` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053b70e5d1fced2e44d372)。 | `4103c0cd5c428919f97be1c656c9c02c8137e0ecbbdf8b3db172df611d1c530e` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053bfae5d1fced2e44d470)。 | `022f313e6279caf09fa08cc7963adc8e67ef5ab39475f0efe7835a1dc5bffd59` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053ca3e5d1fced2e44d560)。 | `b66586cebc5f4c41bdf7c1fc3614ca36cce5df9b07ea676104ae58cad1e30a35` |
| E | 重构版评测：50 分 Time Exceeded（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053d35e5d1fced2e44d671)。 | `0d3ca8a7b3c3aece6ae414592803001d2cf9e4a96af421933b0608f9fec3999f` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

验证日期：2026-11-24。对应 [完整题解](../../202609/README.md) 及同目录的 `A.cpp` 至 `E.cpp`。

五题均使用 `scanf/printf`、万能头文件和简短命名，没有 `cin/cout`、关闭同步语句、下划线命名或通用小数读入封装。A 题使用 `mu`、`var`、`sum`，临时变量 `id` 在查表循环前局部声明。

循环与函数体展开；多语句分支按含义组织，相关短操作可合理成组，极短的单语句分支可省略大括号。`else` 单独起行，较长的声明分行，`&&`、`||` 两侧保留空格，范围循环使用引用，合并函数命名为 `merge`。数组长度使用 `N`、`M` 等大写单字母常量。

下方保留算法重构时的完整对拍与测试点记录。后续代码风格调整均重新编译验证；本轮受影响的 C、D、E 另作样例回归，D 题同时检查最优组数和分组合法性。

## 编译

Apple Clang 21.0.0，C++17，`-O2 -Wall -Wextra`，五题均编译成功，无警告。

本机 Clang 不自带 GNU 的 `bits/stdc++.h`，首次验证时在 `/tmp/csp202609-check/include/bits/stdc++.h` 提供了仅包含标准库头文件的兼容头，通过 `-I` 引入。交付代码保持 `#include<bits/stdc++.h>`；该阶段未使用 GCC，新增 GNU 验证单独列于下方。

## 对拍与现有数据

复用工作区原有题目包中的独立暴力、逐毫秒模拟及分组检查器，不以输出与重构代码相同作为唯一依据。

| 题目 | 独立对拍 | 现有样例与测试点 | 结果 |
| --- | --- | --- | --- |
| A | 292 组高精度查表比较 | 13 个 | 全部通过 |
| B | 250 组子集枚举 | 21 个 | 全部通过 |
| C | 400 组逐毫秒模拟 | 21 个 | 全部通过 |
| D | 600 组暴力染色 | 22 个，检查最优组数、元素覆盖和组内无冲突 | 全部通过 |
| E | 300 组无序点对枚举 | 21 个 | 全部通过 |

合计 1842 组独立对拍、98 个现有样例与测试点。E 题现有数据包含十万点规模，最慢单点本机约 2.44 秒；这是本机运行时间，不代表其他评测环境。

对拍命令如下，其中 `X` 对应 `A` 至 `E`，题号对应 `1` 至 `5`：

```bash
clang++ -std=c++17 -O2 -Wall -Wextra -I /tmp/csp202609-check/include 202609/X.cpp -o /tmp/csp202609-check/bin/X
python3 CSP45-T题号/tools/brute_check.py /tmp/csp202609-check/bin/X
```

该本地验证阶段未进行本轮在线提交，原网页代码的 Accepted 记录不作为本版的新提交结果。

E 按最新 review 将位掩码 `mask` 统一为 `S`，没有改变类型或作用域关系。优化版及 UBSan 版重新通过 300 组无序点对独立暴力与 21 个现有样例／测试点，含十万点数据；重复复验不增加上表不同输入数量。[当前 E 源码哈希与检查](e-mask-followup-report.json)。

## B、D 最终风格复验

B 的界改为 `(ll)1e8*m*m`，明确从整数类型开始计算；D 的组数选择改为 `if/else`，不使用嵌套三目。两项均为等价风格修改，当前源码经 O2、UBSan 无诊断编译，B 各通过 250 组独立子集枚举与 21 个保存输入，D 各通过 600 组独立染色枚举与 22 个保存输入，并检查分组覆盖与冲突合法性。

报告：[bd-final-report.json](bd-final-report.json)；复现：[verify-bd-final.py](verify-bd-final.py)。重复复验不增加此前不同输入数，该本地验证阶段未进行本轮在线提交。

- `B.cpp` 当前 SHA-256：`4103c0cd5c428919f97be1c656c9c02c8137e0ecbbdf8b3db172df611d1c530e`

- `D.cpp` 当前 SHA-256：`b66586cebc5f4c41bdf7c1fc3614ca36cce5df9b07ea676104ae58cad1e30a35`

## A、C 当前哈希的 GNU 16 复验

当前源码以 GNU G++ 16、`-std=c++17 -O2 -Wall -Wextra` 直接编译，无预置头、兼容头或诊断。A 原样重跑 292 组高精度比较、3 个保存样例和 10 个保存数据，共 305 次运行；C 原样重跑 400 组逐毫秒独立模拟、1 个保存样例和 20 个保存数据，共 421 次运行，全部通过。去除重复输入后，分别为 295、420 个不同输入。

此次只重放原验证范围，不增加历史不同输入数，该本地验证阶段未进行本轮在线提交。当前哈希、独立验证器哈希、编译命令和逐次结果见 [GNU 复验报告](current-hash-gnu-revalidation.json)；复现命令为 `python3 tools/nightly/verify_2026_hash_gaps.py`（在工作区根目录运行）。B、D 的当前版本验证见上一节，E 的当前版本验证见位掩码命名复验记录。

- `A.cpp` 当前 SHA-256：`dd814f4d41176bf7e0954ae14c1a672c74a0aacd048054526d93459dd2009af7`
- `C.cpp` 当前 SHA-256：`022f313e6279caf09fa08cc7963adc8e67ef5ab39475f0efe7835a1dc5bffd59`
