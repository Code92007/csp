# 前四题完成与验证记录

2026-10-24，按 D → C → B → A、同题号从新到旧的顺序，补齐工程原有 32 场中缺少的 120 道前四题。202609、202605 的前四题已存在；202605E 随后根据用户补充资料另行完成，单独记录在 gather-report.json 中。

每题包含题意概述、算法与正确性说明、复杂度和 C++17 代码；文章与独立 CPP 一致。全部 32 场的 A–D 已实现，加上第五题，全工程共 160 份完整实现。

| 题号 | 本轮新增 | 独立校验用例 | 逐题报告 | 复现命令 |
|---|---:|---:|---|---|
| D | 30 | 3080 | [fourth-report.json](../tests/fourth-report.json) | `make random-fourth` |
| C | 30 | 3100 | [third-report.json](../tests/third-report.json) | `make random-third` |
| B | 30 | 3160 | [second-report.json](../tests/second-report.json) | `make random-second` |
| A | 30 | 1800 | [first-report.json](../tests/first-report.json) | `make random-first` |
| 合计 | 120 | 11140 | | |

最终 `make check` 已编译 160 题并通过 265 个保存样例/回归用例，汇总见 [content-report.json](../tests/content-report.json)。

先在工程根目录运行 `make check`：核对全部 160 对 Markdown 代码块与 CPP，编译 C++17，并执行保存的样例/回归用例。之后执行表中的命令，可使用固定种子重现对拍结果。

独立校验覆盖随机数据、小规模穷举和专门边界构造。代表性方法包括：用暴力重算核对动态数据结构；用分数精确消元核对化学方程式判秩；用原始字符串替换核对文本分词；用全时刻事件表核对神经元环形缓冲区；用数组扫描核对 DHCP 堆实现；用独立语法生成器核对 Markdown 渲染。对于 HTTP、补丁和 Markdown 等格式敏感输出，比较保留空格与内部换行。

第五题原有的对拍记录在 [fifth-report.json](../tests/fifth-report.json)，本次没有重复计入。第四题压力构造见 [fourth-stress-report.json](../tests/fourth-stress-report.json)。

这些结果验证的是保存样例与生成数据上的一致性，尚未提交正式评测。随机对拍不是完整证明，也不能保证达到官方时间、内存限制。202605E 的完整实现另做 2042 组独立对拍和 7 组十万点构造，不计入上表。
