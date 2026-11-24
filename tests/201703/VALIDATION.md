# 本地验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0590c2e5d1fced2e45825c)。 | `e5a6d59c7ebece9853da31b346bc28411b02a481dff0e89d14bde85669c615e2` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059151e5d1fced2e4583e7)。 | `29092b495277b75adc72c28a4b82105772a8a5c026bb80e58368fa34d8eb778b` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0591a3e5d1fced2e45843c)。 | `5da1a28e4415820a747867320b761de28d3dce4f6ff3a1f791e7a1aed5d30b16` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0591f2e5d1fced2e458494)。 | `a1fd8e40139d11a16065ca49338b4679025d2de78b880287046a968b4032535c` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059244e5d1fced2e45852e)。 | `07ab64d1159ffd1dd1846e132f02bb15310f1ecd10f93e0304c3f30b3cd2b0e1` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

场次：201703。该本地验证阶段未进行本轮在线提交；题解中的原版评测链接仍属于原版。

| 题目 | 不同输入 | 保存样例 | 原有独立对拍 | 新增边界 |
|---|---:|---:|---:|---:|
| A | 62 | 1 | 60 | 1 |
| B | 101 | 1 | 99 | 1 |
| C | 103 | 2 | 100 | 1 |
| D | 92 | 1 | 90 | 1 |
| E | 87 | 4 | 80 | 3 |

合计 445 个不同输入，优化版和 UBSan 版分别全部通过。没有编译警告或 sanitizer 诊断。

重放：从工作区根目录运行：

```sh
python3 tools/nightly/site_style_verify.py --contest 201703 --repo /path/to/original/repository
```

编译使用 C++17，优化版 `-O2 -Wall -Wextra -Wshadow`；检查版 `-O1 -g -fsanitize=undefined -fno-sanitize-recover=all`。

[逐题源码哈希、输入集哈希与计数](refactor-report.json)。

## B 后续风格复验

结尾换行改用puts空字符串，输出字节仍为一个换行。 当前O2、UBSan（含-Wshadow）编译无诊断，各通过1个定向输入；历史完整对拍不重复计数。[本轮结果](b-newline-followup-report.json)，复现 `python3 tools/nightly/verify_four_style.py --repo /path/to/repository`。

- `B.cpp` 当前 SHA-256：`29092b495277b75adc72c28a4b82105772a8a5c026bb80e58368fa34d8eb778b`

## D 后续风格复验

find改为递归路径压缩，保留按集合大小合并；深度增加要求集合大小至少翻倍，所以n≤100000时递归深度至多约17层。原92个输入和额外10万点等大小分层合并构造全部通过。 当前O2、UBSan（含-Wshadow）编译无诊断，各通过93个定向输入；历史完整对拍不重复计数。[本轮结果](d-find-followup-report.json)，复现 `python3 tools/nightly/verify_four_style.py --repo /path/to/repository`。

- `D.cpp` 当前 SHA-256：`b7c62ee770bba184db3451f9a337e889b0ee3850ae0de05382761696b94c3b9f`

## D 局部 lambda 捕获复验

排序比较器按用户偏好从 `[]` 改为 `[&]`，比较表达式不变。比较器仅在当前 `sort` 调用中使用，且函数体未引用外部自动变量。当前源码以 GNU g++ 16、C++17 编译，O2、UBSan 均无诊断，并各通过 93 个已有输入：90 组独立 minimax 对拍、1 个保存样例、10 万点链和等大小合并构造。

报告：[d-lambda-report.json](d-lambda-report.json)；复现：[verify-d-lambda.py](verify-d-lambda.py)。本轮复验不增加此前不同输入数，该本地验证阶段未进行本轮在线提交。

- `D.cpp` 当前 SHA-256：`a1fd8e40139d11a16065ca49338b4679025d2de78b880287046a968b4032535c`
