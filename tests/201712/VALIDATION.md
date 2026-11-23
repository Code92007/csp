# 201712 本地验证

本次重构未重新提交在线评测。题解保留的在线评测记录属于原版代码。

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

E 独立枚举每个真后代的 DP，使用 Python 任意精度整数；新增 150 个三组数据输入检验全局状态重置。李超树比较保留 128 位整数，节点存区间端点，使用下标避免 vector 扩容后悬空引用。

构造包括 n=500 的全小道链（答案 499^2）、大道小道交替链（答案 499），以及 E 十万节点零收益长链（答案 0），O2 本次约 0.023、0.004、0.027 秒。原版 A/C/D/E 无在线 Accepted 记录，本次也未在线提交；只有 B 保留原版的已有 Accepted 链接。

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
