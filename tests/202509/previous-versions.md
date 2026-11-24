# 202509 历史版本与评测记录

[返回当前题解](../../202509/README.md#problem-d) · [验证记录](VALIDATION.md)

本页保存旧版本的判题归属与性能调整记录。当前题解只展示已获满分的线性做法。

<a id="problem-d"></a>

## D. 造题计划（上）

| 版本 | 判题记录 | 源码 SHA-256 |
|---|---|---|
| 原版 | [100 分 Accepted](https://oj.shumeng.tech/record/6adce73ba67df0b81749b69a) | 原判题记录中的代码 |
| 首轮重构版 | [70 分 Time Exceeded](https://oj.shumeng.tech/record/6b0546dee5d1fced2e44e4b5) | `9132211a9175bee8afe2165aeadf144a23c9c91edacdb0749e661f94a1bd09da` |
| 当前线性版 | [100 分 Accepted](https://oj.shumeng.tech/record/6b05ab06e5d1fced2e45bdac) | `6d340704052cfdf30dbaba52b2636e7ec91a72a16cdf56e81188759e3b19f632` |

首轮重构版使用树上路径查询结构，未通过全部时限。当前版本利用点权为排列这一条件，将路径 mex 转为路径外最小值，线性预处理后常数时间回答查询，总时间为 $O(n+m)$。

当前版本已通过独立路径枚举对拍及最大规模链、星形树检查：[本地结果](performance-revision/202509D/initial-linear-report.json)、[独立复核](performance-revision/202509D/independent-review-review.md)、[采用记录](performance-revision-D.json)。旧判题和历史验证报告保持各自原有归属，不作为当前源码的新评测记录。
