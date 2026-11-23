# 本地验证记录

场次：201703。重构版未重新提交在线评测；题解中的原版评测链接仍属于原版。

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
