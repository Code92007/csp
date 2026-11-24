# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b054d84e5d1fced2e44efe4)。 | `3bcb74d3952c1f6de0b6b1a903d1eb920af8d67e8ddf47f25eceb91f2abe9ea4` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05531de5d1fced2e44f9a7)。 | `0e69c7258195d5c5019875ce1c29b4aa3aadac5102e613d10a044b195898b673` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055380e5d1fced2e44faa1)。 | `500837767022031d280ebcf635869a3f11505db5391f41bf85e93d5b97459521` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0553dce5d1fced2e44fb4f)。 | `4785fd2db7b5d58c48f3de914cf866399d1500a9577e20606ba5da3210841620` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055437e5d1fced2e44fc3e)。 | `51d8ecd0ceb1a648be49fadf554848ef88a68921309bef255504294fcc3f660e` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

场次：202506。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 62 | 1 | 60 | 1 |
| B | 100 | 2 | 95 | 3 |
| C | 102 | 1 | 100 | 1 |
| D | 78 | 3 | 71 | 4 |
| E | 97 | 1 | 93 | 3 |

合计 439 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 202506 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

B 按 review 调整成对坐标递减与合法性函数后，重新编译并复验同一批 100 个不同输入，优化版及 UBSan 版均通过。[当前 B 源码哈希](b-style-followup-report.json)。原批次报告中的 B 哈希保留为历史版本。

C 按 review 简化函数命名及相关赋值后，重新编译并复验同一批 102 个不同输入，优化版及 UBSan 版均通过。[当前 C 源码哈希](c-style-followup-report.json)。原批次报告中的 C 哈希保留为历史版本。

D 按 review 调整 typedef 顺序、f 函数和成对赋值后，重新编译并复验同一批 78 个不同输入，优化版及 UBSan 版均通过。[当前 D 源码哈希](d-style-followup-report.json)。原批次报告中的 D 哈希保留为历史版本。

D 按最新 review 将模数 `P` 改为 `mod`，保留 pair 类型别名的命名习惯；两版重新通过 78 个不同输入，另已核对仅名称与常量声明分行变化。[当前 D 源码哈希](d-mod-followup-report.json)。此前 D 报告保留为历史版本。
