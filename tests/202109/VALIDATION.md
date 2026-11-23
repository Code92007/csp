# 本地验证记录

场次：202109。重构版未重新提交在线评测；题解中的原版评测链接仍属于原版。

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
