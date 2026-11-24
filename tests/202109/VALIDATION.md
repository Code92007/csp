# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版未提交：当前账号缺少隐藏题查看权限（View hidden problems）；未产生新提交或判题结论。 | `0f0643fb30b01f546b5c713ef4e29746d675cca7d03c2365068f49dfbbb6616d` |
| B | 重构版未提交：当前账号缺少隐藏题查看权限（View hidden problems）；未产生新提交或判题结论。 | `ebd926e838ef6bf5ce5dbd0389057e68d9ac29a15e6c8a8a1967de4668bf27e9` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058795e5d1fced2e456787)。 | `3a600da8f273ec2ba089c53b2c334a2e4d89cbd6554e49fbfa2501601bf5bc81` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0587fbe5d1fced2e4568c7)。 | `3a8c7d9f84fb8b9d91f1567ed36a0f36d35070f9261811c33a7765604f522b6e` |
| E | 重构版未提交：当前账号缺少隐藏题查看权限（View hidden problems）；未产生新提交或判题结论。 | `408ece0b2576d64719dfed3593b52b4c44aa09b885db792a88e3c97b276bbbfc` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

场次：202109。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 45 | 2 | 42 | 1 |
| B | 155 | 4 | 150 | 1 |
| C | 83 | 2 | 80 | 1 |
| D | 77 | 2 | 73 | 2 |
| E | 83 | 2 | 80 | 1 |

合计 443 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 202109 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

B 按最新 review 将万级容量 `1e4+10` 展开为 `10010`，数值不变；优化版与 UBSan 版重新通过 155 个不同输入。[当前 B 源码哈希与检查](b-capacity-followup-report.json)。原批次报告保留历史源码哈希。

D 按最新 review 将 double 的 `printf` 格式改为等价的 `%.12lf`，输入仍保留 `%lf`；优化版与 UBSan 版重新通过 77 个不同输入。[当前 D 源码哈希与检查](d-printf-followup-report.json)。原报告保留历史源码哈希。
