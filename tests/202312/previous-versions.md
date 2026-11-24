# 202312 历史版本与评测记录

[返回当前题解](../../202312/README.md#problem-d) · [验证记录](VALIDATION.md)

本页保存旧版本的判题记录与实现比较。当前题解只展示已获满分的线段树做法。

<a id="problem-d"></a>

## D. 宝藏

| 版本 | 判题记录 |
|---|---|
| 旧根号分块版 | [曙梦 OJ 85 分超时](https://oj.shumeng.tech/record/6addc9ec74ace1cba9a21d5a)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490650) |
| 原线段树版 | [曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305810434) |
| 当前重构版 | [曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6b055fc8e5d1fced2e451250) |

旧根号分块版重交曙梦 OJ 仍为 85 分超时。改用线段树后，原版已通过 1 个保存样例、700 组独立朴素对拍与 6 组 10 万规模压力测试。同机这 6 组上界构造较旧版快约 8–36 倍；本地耗时不等同评测机耗时。

当前重构版的源码 SHA-256 为 `a0f4375d0c7528854e6cfa934b3783bdef1b8f14fc5681a24dd85ac8fd72261c`。本轮独立验证及后续等价风格调整见[验证记录](VALIDATION.md)；上述原版测试与洛谷记录仍归属各自当时的代码，未冒充当前源码的新提交。
