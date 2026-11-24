# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0595a1e5d1fced2e458fb2)。 | `9f8ba329e7af53e8ba768be958fe8f289a125d8c04c9a06f9544185f9a1dacce` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05962ce5d1fced2e45919d)。 | `32b602eb95a1befeb590c4177d98978e56f3fb9186444b022ff95f6e03adbd3a` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05966fe5d1fced2e45928f)。 | `19434c89a349c3355a02321aadf37909690da2e71c0445097e8a058f5e447449` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a0d2e5d1fced2e45a733)。 | `42f18622e1c2e80c3951a09d35fdb88e90843accaad97c3f8d76eff31ddf27b3` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a119e5d1fced2e45a801)。 | `e679621282d692f8715d9800fe0d0daed97c54a77baf8858b0258116e2227d50` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

场次：201509。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

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
