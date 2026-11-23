# 本地验证记录

场次：201409。重构版未重新提交在线评测；题解中的原版评测链接仍属于原版。

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
