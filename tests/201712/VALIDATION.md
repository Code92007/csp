# 201712 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058f03e5d1fced2e457dd4)。 | `6fc42e40bb1d9761bd65bb5da357b51978d7e76ca806bb63365c92b6121446a6` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058f85e5d1fced2e457e64)。 | `b489c509ec3ae7efd90cb1b410ead15985a5359796ca5324c6710e735898b43d` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058fcfe5d1fced2e457f62)。 | `5fc6ca3c588cafe593063d09f8f9eb76dfc14510241b400f94f441ffee588c66` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059027e5d1fced2e458041)。 | `9ca9b5a00588b6aa332bb68faf6a9e6cc0ba4a7dac011a4026a0e0616b719a0d` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059079e5d1fced2e4581c6)。 | `ba6f4bb1d05f855acbc23500ed70be702497d6203fe6da7f1e65f31838000a10` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

该本地验证阶段未进行本轮在线提交。题解保留的在线评测记录属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **1216 个不同输入**，UBSan 通过 **1213 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|63|63|
|B|540|540|
|C|162|162|
|D|219|217|
|E|232|231|

输入来源：retained_independent：576；saved_sample：7；additional_independent：630；constructive_stress：3。

All-pair differences, live-circle deletion, Python datetime minute enumeration, direct road-state Dijkstra with current consecutive-small-road length, ancestor/descendant DP with exact Python integers.

A 直接枚举数对差值，并补一千个重复元素。B 用存活编号数组独立模拟环形删除，覆盖 n=1..30、k=1..9。C 以 Python datetime 逐分钟枚举，补 2000 年闰日、英文大小写、逗号重复值与右端点排除。D 独立状态为“城市、当前连续小道长度”，每走一条小道按增量 (s+w)^2-s^2 加疲劳，不复用 Floyd 合成算法。

E 独立枚举每个真后代的 DP，使用 Python 任意精度整数；新增 150 个三组数据输入检验全局状态重置。李超树比较保留 128 位整数，节点存区间端点并以下标访问。

构造包括 n=500 的全小道链（答案 499^2）、大道小道交替链（答案 499），以及 E 十万节点零收益长链（答案 0），O2 本次约 0.023、0.004、0.027 秒。原版 A/C/D/E 无在线 Accepted 记录，本次该本地验证阶段未进行本轮在线提交；只有 B 保留原版的已有 Accepted 链接。

复现：`python3 201712/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 源码 SHA-256

- `A.cpp`：`6fc42e40bb1d9761bd65bb5da357b51978d7e76ca806bb63365c92b6121446a6`
- `B.cpp`：`b489c509ec3ae7efd90cb1b410ead15985a5359796ca5324c6710e735898b43d`
- `C.cpp`：`5fc6ca3c588cafe593063d09f8f9eb76dfc14510241b400f94f441ffee588c66`
- `D.cpp`：`8e72a9eff1ee30609be8961b85325834bf88a123f67562c260ad2fc62486f2f7`
- `E.cpp`：`9bcc8d2346a125766fcc25a371cde44cc6d64f03d68b12f13ce015beecbee07b`

## 最终命名与常量复核

掩码使用 `S`，模数使用 `mod`；小于十万的容量常量展开为普通整数。仅调整本场涉及的命名或等值常量，原算法与历史独立对拍记录保留。当前源码重新通过 O2、UBSan 编译及全部保存样例，详见 [nightly-review-followup.json](nightly-review-followup.json)。

- `A.cpp` 当前 SHA-256：`6fc42e40bb1d9761bd65bb5da357b51978d7e76ca806bb63365c92b6121446a6`
- `B.cpp` 当前 SHA-256：`b489c509ec3ae7efd90cb1b410ead15985a5359796ca5324c6710e735898b43d`
- `C.cpp` 当前 SHA-256：`5fc6ca3c588cafe593063d09f8f9eb76dfc14510241b400f94f441ffee588c66`
- `D.cpp` 当前 SHA-256：`8e72a9eff1ee30609be8961b85325834bf88a123f67562c260ad2fc62486f2f7`
- `E.cpp` 当前 SHA-256：`6c7b2c04e8a6bc12a5b80fd955a15b5ace8b6f5adf2379971789221a7e0ae3db`

## D／E 最新 review 复验

D 将两处较长的最短路松弛分支加上大括号、展开换行。E 将城市状态、离散坐标和李超节点池改为全局普通数组；原直线编号集合改用 head／tail／nxt／sz 数组链表，合并后直接拼接。算法与 128 位比较保持一致，每组重置根、链表、DP 及节点计数。

节点池一次插线至多分配一个节点；每条线由小集合搬入大集合时，集合大小至少翻倍，因此至多搬动 16 次。n≤100000 时包含首次插入在内至多分配 17n 个节点，M=18N 留有 0 号哨兵及容量余量。实际编译测得 node 为 20 字节，全部用户静态数据约 41.203 MiB，低于该题 512 MiB 限制。

本轮保留并重放 D 原有 219 个输入、E 原有 232 个输入；E 另补 120 个十组独立暴力输入及 4 个大规模／复位压力输入，覆盖 n=1、十万节点长链与平衡树、星形、极值 v/f/s，以及大小测试组交替。GNU G++ 16 优化版与 Clang UBSan 版均通过 D 219、E 356，共 575 个不同输入；此次也包含原先未跑 UBSan 的最大构造，无编译警告或 sanitizer 诊断。历史批次报告与输入计数保留，不将重复重放累计成新增输入。

数据上界和 512 MiB 限制核对：[当前 OJ 题面](https://oj.shumeng.tech/p/CSP201712E)。本地复验：[源码哈希、容量证明及结果](de-array-followup-report.json)；[复现脚本](verify-de-followup.py)。仍该本地验证阶段未进行本轮在线提交。

- `D.cpp` 最新 SHA-256：`9ca9b5a00588b6aa332bb68faf6a9e6cc0ba4a7dac011a4026a0e0616b719a0d`
- `E.cpp` 最新 SHA-256：`ba6f4bb1d05f855acbc23500ed70be702497d6203fe6da7f1e65f31838000a10`
