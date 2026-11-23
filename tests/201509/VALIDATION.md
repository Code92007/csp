# 本地验证记录

场次：201509。重构版未重新提交在线评测；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 62 | 1 | 60 | 1 |
| B | 118 | 2 | 100 | 16 |
| C | 102 | 1 | 100 | 1 |
| D | 97 | 1 | 94 | 2 |
| E | 62 | 1 | 59 | 2 |

合计 441 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 201509 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

E 按最新 review 将 AC 自动机的节点数组、计数及插入／构建函数归入 `namespace AC`，矩阵运算保留在外；两处长条件分支加大括号并展开。优化版与 UBSan 版重新通过 62 个不同输入，包含 101 个自动机状态及文章长度 `1e15` 的边界。[当前 E 源码哈希与检查](e-ac-followup-report.json)。原报告保留历史源码哈希。
