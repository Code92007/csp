# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a3fae5d1fced2e45aeb9)。 | `9479dd8401bd3c673c4276e82c5cbacda77b472ce6d1bb026df64d67d9f04f24` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a43ce5d1fced2e45af87)。 | `2c5c82af0cd1afde575aa2cbff37b22afcffec95197e535d728594b901536247` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a47ae5d1fced2e45b01f)。 | `b3a839e2b26d73c7353f1ddab30d26d505c2bc8fe38872a9ab55e60799cffaf9` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a4b7e5d1fced2e45b0b6)。 | `aaa7c38a2377bfba59e3dc0ca48e33c89a4f0de974f9d48c513d5377552dc13e` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a4f5e5d1fced2e45b154)。 | `6ac324fc58dec85d44a521b16b3bd50bc1ef0ce65f121c758324b8c0463d635a` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

场次：201409。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 63 | 2 | 60 | 1 |
| B | 103 | 2 | 100 | 1 |
| C | 103 | 2 | 100 | 1 |
| D | 83 | 2 | 80 | 1 |
| E | 28 | 2 | 20 | 6 |

合计 380 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 201409 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

E 按最新 review 将模数 `P` 改为 `mod`；两版重新通过 28 个不同输入，另已核对仅名称变化。[当前 E 源码哈希](e-mod-followup-report.json)。原批次报告保留历史源码哈希。

E 按最新 review 将 DFS 的位掩码参数 `mask` 改为 `S`，优化版与 UBSan 版重新通过同一批 28 个不同输入。[当前 E 源码哈希与检查](e-mask-followup-report.json)。此前报告保留历史源码哈希。

E 按最新 review 展开矩阵乘法中的较长条件分支，优化版与 UBSan 版重新通过 28 个不同输入。[当前 E 源码哈希与检查](e-branch-followup-report.json)。此前报告保留历史源码哈希。
