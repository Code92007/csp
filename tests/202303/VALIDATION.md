# 本地验证记录

场次：202303。重构版未重新提交在线评测；题解中的原版评测链接仍属于原版。

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
