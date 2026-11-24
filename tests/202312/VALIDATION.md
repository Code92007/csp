# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055e8ee5d1fced2e450e72)。 | `710a79b37c5eb67b6cfa08008c8c827b32aa67d576a3c39863e25d78cf67b0cf` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055f06e5d1fced2e451057)。 | `e5c90cc994df3c3c5864791d0c7023407fdeba9a494dace9901649c1bfe1646c` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055f64e5d1fced2e451151)。 | `26c33898ee789f478bd67652b4cc6d910c22182d1ccf129e9a0280a55892ee67` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055fc8e5d1fced2e451250)。 | `a0f4375d0c7528854e6cfa934b3783bdef1b8f14fc5681a24dd85ac8fd72261c` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b056032e5d1fced2e4512f0)。 | `7035b3ceb3c58de35a5ded1bb1ee44a370671d4d101f21e63011cbfdb6731f9b` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

[历史版本与评测记录](previous-versions.md#problem-d)。

场次：202312。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 62 | 1 | 60 | 1 |
| B | 102 | 1 | 100 | 1 |
| C | 102 | 1 | 100 | 1 |
| D | 813 | 1 | 110 | 702 |
| E | 62 | 1 | 60 | 1 |

合计 1141 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 202312 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

C 按 review 将重复的 DFS 序包含判断提为 `anc(t,x)`，其中 `t` 为被包含点、`x` 为祖先；两版重新通过 102 个不同输入。[当前 C 源码哈希](c-style-followup-report.json)。D 将模数名称 `P` 改为 `mod`，两版重新通过 813 个不同输入，另已核对仅名称与常量声明分行变化。[当前 D 源码哈希](d-style-followup-report.json)。原批次报告保留历史源码哈希。

E 按最新 review 将位掩码 `mask` 统一为 `S`，并先保存 `int c=col[v]` 再进行移位与置位；优化版与 UBSan 版重新通过同一批 62 个不同输入。[当前 E 源码哈希与检查](e-mask-followup-report.json)。原报告保留历史源码哈希。

D 文字终审时删除未使用的 `ll` 别名，未改动可执行语句；GNU GCC 16 优化版和 Clang UBSan 版均重新通过 1 个保存样例。[当前 D 源码哈希与检查](d-alias-followup-report.json)。此前 813 组对拍报告保留历史源码哈希，本次未重复计数。
