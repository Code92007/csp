# 本地验证记录

场次：202409。重构版未重新提交在线评测；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 62 | 1 | 60 | 1 |
| B | 102 | 1 | 100 | 1 |
| C | 125 | 4 | 120 | 1 |
| D | 123 | 1 | 120 | 2 |
| E | 62 | 1 | 60 | 1 |

合计 474 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 202409 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

A 按 review 将嵌套三目改为 if/else 分支后，重新编译并复验同一批 62 个不同输入，两版均通过。[当前 A 源码哈希](a-style-followup-report.json)。原批次报告中的 A 哈希保留为历史版本。

E 按 review 将 pushup 移为 node 成员后，重新编译并复验同一批 62 个不同输入，含十万段／近十万次切割，两版均通过。[当前 E 源码哈希](e-style-followup-report.json)。原批次报告中的 E 哈希保留为历史版本。

E 继续把读入与初始化封装进 node::read 后，同样重新编译并复验 62 个不同输入，优化版及 UBSan 版均通过；[最新报告](e-style-followup-report.json)保留前版指针。
