# 201412 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a2b3e5d1fced2e45ab01)。 | `6c7e91b84554d18fc0c9ff20faeebe5621cdde0cfb39e72114d1624efd30f80e` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a2f0e5d1fced2e45aba2)。 | `f1ac108f70335eac6e2634659bcb92e877f0a5672614b4c9bf521d3b808858df` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05db38e5d1fced2e45d776)。 | `38fc56230c8c14912879cf00d876c9922f955d70cb1b3f4dddd3b83dd203b96c` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a37ee5d1fced2e45adb3)。 | `25fd3e17b3e6c1964c0eff41c751c6656f70a3b7e062ce3eef3024e2fcb0b825` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a3bce5d1fced2e45ae6f)。 | `2e79fb9fc9a3ad92ec794ce610a4396df0bcf0670ba5c48cbc5a7b47db55bf6f` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

[历史版本与验证记录](previous-versions.md)：正文移出的旧版本成绩、失败尝试及原有链接集中保存在此；下方既有验证记录继续保留其历史归属。

该本地验证阶段未进行本轮在线提交。题解保留的在线评测记录属于原版代码。**C 原版仍为 90 分 Wrong Answer，本地对拍未解决该问题。**

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **856 个不同输入**，UBSan 通过 **851 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|63|62|
|B|32|31|
|C|322|321|
|D|216|215|
|E|223|222|

输入来源：retained_independent：268；saved_sample：9；constructive_stress：5；additional_independent：574。

Visit-prefix counts, literal Z-walk retained oracle, direct candidate-price order summation (current zero-volume convention only), exhaustive spanning-tree subsets, exhaustive cyclic end-of-day inventory DP with literal production choices (independent of min-cost flow).

A 加入 1000 次同一编号；B 包含 500×500 方阵；C 加入 5000 笔、总成交量 250000000000 的 64 位构造；D 包含 1000 点、10 万条边的等权图。C 对拍按当前候选价格与零成交约定计算，原版 90 分 Wrong Answer 的问题仍未解决，不将这些本地通过描述为修复或满分。

E 新增 220 组两城七日实例，以全枚举初末库存、每日生产量及两城净运输量的循环库存 DP 为 oracle，独立于费用流、残量图和势能。另有必须使用星期日到下周星期一库存的定向案例，及 100 城、500 条道路的零费用解析构造；本次最大构造约 0.038 秒。

复现：`python3 201412/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 源码 SHA-256

- `A.cpp`：`0d3c6bff615e0b424d56378fe2a9bdb76fa557bafadc1d24c7379e3c0a509ab7`
- `B.cpp`：`f1ac108f70335eac6e2634659bcb92e877f0a5672614b4c9bf521d3b808858df`
- `C.cpp`：`61cde8c0dc2cb7f794980bc29258c927c4247eb451a5b0117ad9e43efe4f0b7d`
- `D.cpp`：`5083d4e22952af2df30fe21fbff24385c3058d4bfd3f46a7c2907a4152641bbc`
- `E.cpp`：`a957f8de16d46fd9dee32d030800df5133b098fb4e90744a7dafa20e8843351e`

## 最终命名与常量复核

掩码使用 `S`，模数使用 `mod`；小于十万的容量常量展开为普通整数。仅调整本场涉及的命名或等值常量，原算法与历史独立对拍记录保留。当前源码重新通过 O2、UBSan 编译及全部保存样例，详见 [nightly-review-followup.json](nightly-review-followup.json)。

- `A.cpp` 当前 SHA-256：`6c7e91b84554d18fc0c9ff20faeebe5621cdde0cfb39e72114d1624efd30f80e`
- `B.cpp` 当前 SHA-256：`f1ac108f70335eac6e2634659bcb92e877f0a5672614b4c9bf521d3b808858df`
- `C.cpp` 当前 SHA-256：`61cde8c0dc2cb7f794980bc29258c927c4247eb451a5b0117ad9e43efe4f0b7d`
- `D.cpp` 当前 SHA-256：`25fd3e17b3e6c1964c0eff41c751c6656f70a3b7e062ce3eef3024e2fcb0b825`
- `E.cpp` 当前 SHA-256：`a957f8de16d46fd9dee32d030800df5133b098fb4e90744a7dafa20e8843351e`

## C 输出表达式复验

先计算ans=max(0ll,ans)，再输出价格与成交量，保持原值和零成交候选价约定。O2、UBSan均无诊断，各通过322个不同输入，含5000笔委托与2.5×10¹¹成交量构造；**该次仅改输出的验证尚未解决原版 90 分 Wrong Answer；后续读入修复见文末**。[本轮当前哈希与结果](c-output-followup-report.json) · [复现脚本](verify-c-output-followup.py)。

- `C.cpp`：`da9a660760de1b35e3ac5bd1bbdb3564bea4419d3d694e26f8d18b4fede45504`

## E 网络流模板复验

E 改为 `struct MCMF`，使用 `head/cnt/e[].v,nxt,w,cost` 的链式前向星、SPFA 和路径瓶颈增广。距离与费用使用 64 位整数，环形队列不会因累计多次入队越界；最多 702 个节点、18200 条残量弧，分别落在 `N=710,M=18210` 内。

当前 E 源码的 O2、UBSan 均无诊断，并各通过 354 个不同输入。包括原先 221 组独立库存 DP、120 组额外满足周总产需平衡的库存 DP、两份样例、零需求，以及 100 城 500 边的最短路、Hungarian 运输分配、跨周仓储和就地平衡构造。另保留一组超出“保证可行”前提的无解鲁棒性输入，预期为 -1。最大规模构造的 O2 单例用时不超过 0.034 秒；这只是本机测例结果，不是所有输入的性能保证。

报告：[e-mcmf-report.json](e-mcmf-report.json)；用例：[e-mcmf-cases.json](e-mcmf-cases.json)；复现：[verify-e-mcmf.py](verify-e-mcmf.py)。该本地验证阶段未进行在线提交，C 当时为 90 分 Wrong Answer；后续读入修复见文末。

- `E.cpp` 当前 SHA-256：`2e79fb9fc9a3ad92ec794ce610a4396df0bcf0670ba5c48cbc5a7b47db55bf6f`


先前重构版：[历史记录](https://oj.shumeng.tech/record/6b05a32ee5d1fced2e45ac6f)。


## C 本轮修复验证

当前源码 `38fc56230c8c14912879cf00d876c9922f955d70cb1b3f4dddd3b83dd203b96c` 对应 [100 分 Accepted](https://oj.shumeng.tech/record/6b05db38e5d1fced2e45d776)。[本地验证及源码绑定](optimization-20261125/verification.json) · [本轮提交详情](optimization-20261125/submission.json)。

C 仅改变价格读入方式，720 组标准格式与原程序等价，720 组扩展格式通过 O2/UBSan；100 万个合法整数分全部通过转换检查。题面仍按两位小数描述，隐藏测试输入未公开，不将诊断假设写成已知数据事实。
