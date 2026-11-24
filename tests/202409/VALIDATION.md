# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0558d8e5d1fced2e450400)。 | `aa3519dbde3db6a904503b4f292e3dcda9545937bdd1f323f0f4392374600416` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055939e5d1fced2e4504d2)。 | `cfa3bb0f480444b172a00f353498829944afa3c38bab492cb606b29832834741` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055990e5d1fced2e450567)。 | `827d17ce65341ec4bb91616039be78490877e3c94ea816cd07f7c428bd50f58d` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0559efe5d1fced2e450627)。 | `adf1a5e335811fe555ecdf8068400d3fbc60e884d959956bce392c4507839d1f` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055a58e5d1fced2e4506f8)。 | `220a98f7c4a7d492ac4641b2e87d9dea4740f18306507330834eba8e55325a81` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

场次：202409。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

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

E 按最新 review 将 size、read、pushup 三个成员函数全部在 node 内定义，并保留 0 号静态哨兵。重新以 GNU GCC 优化版和 Clang UBSan 版复验同一批 62 个不同输入，含十万段切割边界，均通过且无警告或 sanitizer 诊断。[本轮源码哈希及结果](e-node-inline-followup-report.json)。历史报告保留原版本哈希，不重复累计输入数。
