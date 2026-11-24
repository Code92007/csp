# 201412 C. 集合竞价：历史版本与验证记录

本页保存从题解正文移出的版本成绩、尝试与当时的本地验证说明。正文只展示最终满分做法；当前源码与评测绑定见 [本场验证记录](VALIDATION.md)。旧阶段的“本版验证”等表述仅指当时的代码，不替代当前源码的验证结论。

## 评测记录

| 版本 | 实际结果 | 记录 |
| --- | --- | --- |
| 原版 | 90 分 Wrong Answer | [真实记录](https://oj.shumeng.tech/record/6addbb4574ace1cba9a20fa8) |
| 首轮重构版 | 90 分 Wrong Answer | [真实记录](https://oj.shumeng.tech/record/6b05a32ee5d1fced2e45ac6f) |
| 零成交价格归零尝试，未采用 | 90 分 Wrong Answer | [真实记录](https://oj.shumeng.tech/record/6b05d88ee5d1fced2e45d6a5) |
| 当前价格读入修复版 | 100 分 Accepted | [真实记录](https://oj.shumeng.tech/record/6b05db38e5d1fced2e45d776) |

## 从正文移出的说明

原版评测：[曙梦 OJ 90 分 Wrong Answer](https://oj.shumeng.tech/record/6addbb4574ace1cba9a20fa8)。重构版本地验证见 [VALIDATION.md](VALIDATION.md)。

先前重构版记录：[保留当时的 90 分 Wrong Answer](https://oj.shumeng.tech/record/6b05a32ee5d1fced2e45ac6f)。

**价格读入与验证**

价格不超过 10000.00，对全部 100 万个合法整数分逐一转换，均可恢复原值。新的读法也兼容省略小数末尾零的写法；例如 `3.5` 会得到 350 分，而拆成两个整数直接拼接会得到 305 分。

本次只调整读入，保留原来的撤单、成交量和同分取最高价逻辑。720 组标准格式用例与原程序输出一致，另通过 720 组扩展格式检查；O2 和 UBSan 均通过。当前源码已获曙梦 OJ 100 分 Accepted。隐藏测试输入不可见，不能据此断言原来两个错误点的具体格式。

另试过零成交时将价格归零，仍为 [90 分 Wrong Answer](https://oj.shumeng.tech/record/6b05d88ee5d1fced2e45d6a5)，未采用该修改。

历史审计：[本地审计结果](../../tests/auction-report.json) · [独立验证器](../../tests/auction_regressions.py) · [后续审计统计](../../tests/auction-review-v2-report.json)。
