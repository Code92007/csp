# 202609 E. 奇：历史版本与验证记录

本页保存从题解正文移出的版本成绩、尝试与当时的本地验证说明。正文只展示最终满分做法；当前源码与评测绑定见 [本场验证记录](VALIDATION.md)。旧阶段的“本版验证”等表述仅指当时的代码，不替代当前源码的验证结论。

## 评测记录

| 版本 | 实际结果 | 记录 |
| --- | --- | --- |
| 旧网页版本（页面复核） | 50 分 Time Exceeded | [真实记录](https://oj.shumeng.tech/record/6adce90ea67df0b81749bfe2) |
| 首轮重构版 | 50 分 Time Exceeded | [真实记录](https://oj.shumeng.tech/record/6b053d35e5d1fced2e44d671) |
| 查询优化尝试，未采用 | 50 分 Time Exceeded | [真实记录](https://oj.shumeng.tech/record/6b05aa50e5d1fced2e45bc4d) |
| 当前满分版 | 100 分 Accepted | [真实记录](https://oj.shumeng.tech/record/6b05d79ce5d1fced2e45d666) |

## 从正文移出的说明

本版验证：已通过 C++17 编译、300 组无序点对枚举对拍、21 个现有样例与测试点。

先前重构版记录：[保留当时的 50 分 Time Exceeded](https://oj.shumeng.tech/record/6b053d35e5d1fced2e44d671)。

查询优化候选另获 [50 分 Time Exceeded](https://oj.shumeng.tech/record/6b05aa50e5d1fced2e45bc4d)。该次查询优化未采用，其源码与判题归属单独保存在 [复测记录](performance-attempt/202609E/attempt.json) 中。

旧记录于 2026-11-24 复核，同样为 **50 分 Time Exceeded**；原元数据中的 100 分 AC 与当前页面不一致，以可见判题记录为准。[复核证据](prior-record-observation.json)。

原版评测记录：[历史记录 1](https://oj.shumeng.tech/record/6adce90ea67df0b81749bfe2)。
