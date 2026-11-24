# 202406 E. 哥德尔机：历史版本与验证记录

本页保存从题解正文移出的版本成绩、尝试与当时的本地验证说明。正文只展示最终满分做法；当前源码与评测绑定见 [本场验证记录](VALIDATION.md)。旧阶段的“本版验证”等表述仅指当时的代码，不替代当前源码的验证结论。

## 评测记录

| 版本 | 实际结果 | 记录 |
| --- | --- | --- |
| 旧包络版本（页面复核） | 70 分 Time Exceeded | [真实记录](https://oj.shumeng.tech/record/6addaa6774ace1cba9a1ff5b) |
| 首轮重构版 | 70 分 Time Exceeded | [真实记录](https://oj.shumeng.tech/record/6b055c45e5d1fced2e450b84) |
| 包络查询优化尝试，未采用 | 70 分 Time Exceeded | [真实记录](https://oj.shumeng.tech/record/6b05ab73e5d1fced2e45be79) |
| 较早的离线版本，未采用 | 70 分 Time Exceeded | [真实记录](https://oj.shumeng.tech/record/6b05dee5e5d1fced2e45efd2) |
| 当前满分版 | 100 分 Accepted | [真实记录](https://oj.shumeng.tech/record/6b05e3ede5d1fced2e45f094) |
| 用户手动提交的满分版 | 100 分 Accepted | [真实记录](https://oj.shumeng.tech/record/6b05e35ee5d1fced2e45f047) |

## 从正文移出的说明

本版验证：O2、UBSan 各通过 120 组独立小例、5 组满规模构造及读取边界检查，详见 [验证记录](VALIDATION.md)。此前包络版本的 653 组本地验证单独保留。

先前重构版记录：[保留当时的 70 分 Time Exceeded](https://oj.shumeng.tech/record/6b055c45e5d1fced2e450b84)。

查询优化候选另获 [70 分 Time Exceeded](https://oj.shumeng.tech/record/6b05ab73e5d1fced2e45be79)。该次优化未采用，其源码与判题归属单独保存在 [复测记录](performance-attempt/202406E/attempt.json) 中。

旧记录于 2026-11-24 复核，同样为 **70 分 Time Exceeded**；原元数据中的 100 分 AC 与当前页面不一致，以可见判题记录为准。[复核证据](prior-record-observation.json)。

用户手动提交也获 [100 分 Accepted](https://oj.shumeng.tech/record/6b05e35ee5d1fced2e45f047)。两份满分记录的程序内容相同，仅文件末尾是否有换行不同。较早的离线版本曾获 [70 分 Time Exceeded](https://oj.shumeng.tech/record/6b05dee5e5d1fced2e45efd2)，最终版进一步调整了读入与数据布局。

原版评测：[记录](https://oj.shumeng.tech/record/6addaa6774ace1cba9a1ff5b)（当前页面复核为 70 分 Time Exceeded）。
