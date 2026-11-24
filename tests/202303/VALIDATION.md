# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0564bde5d1fced2e451c23)。 | `38c9ef51ee2f3a55cf4f572ac78b6b61eeaef2be618b4d6ad4e8b4c028d60b9a` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b056519e5d1fced2e451c8b)。 | `74d9999e08c6ce5a64765fd7a25a0b3e8ef0d1ca9e00762c27b5ea4f59a62b01` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05812fe5d1fced2e454ffc)。 | `b7ab663741efaf5e3ca6d2f7a89891453be7399151021c214a9ab3262baae0ab` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0581bbe5d1fced2e455238)。 | `d8c261b1711c863971ed5ddef82c35fc090c4c9747cfa34eac9a95d5ee6130d2` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058247e5d1fced2e455484)。 | `a24464b151f4e0eaee241f63faebff0c5e9ac2e90763ac3454e39cbb8abbe32b` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

场次：202303。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 62 | 1 | 60 | 1 |
| B | 103 | 2 | 100 | 1 |
| C | 703 | 1 | 100 | 602 |
| D | 102 | 1 | 100 | 1 |
| E | 83 | 1 | 80 | 2 |

合计 1053 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 202303 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

E 按最新 review 将左右递归答案分别累加到 `ans`，再单独返回，优化版与 UBSan 版重新通过 83 个不同输入。[当前 E 源码哈希与检查](e-style-followup-report.json)。原批次报告保留历史源码哈希。
