# 202603 重构版验证记录

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b054042e5d1fced2e44daec)。 | `de29a053c8345ce35e59e77553b7d5ff176c6306317cbd5ec0be3da0348b35cb` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0540bde5d1fced2e44db7b)。 | `126affaa1c48033d3ea928d4e2fed4405d0fc46df267613fd8f9ad5a95a4a8c0` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05412ee5d1fced2e44dc62)。 | `1dd893b262b746a8cdfa612ef0c5db16aae39f52bfaddc60cdddfa41163ea65d` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05419ee5d1fced2e44dd46)。 | `a5f31a574a1152c95fe64b38033f2200e205ee5990300c2c613c515b121352d2` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05420ee5d1fced2e44de3f)。 | `377bb7588db67ae5074d3055d808050e2f03803d28ac5e56abeda676f00e990c` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

验证日期：2026-11-24。

五题均已按当前代码风格编译、独立对拍，并核对 Markdown 代码块与独立源码一致。
本记录对应本地重构版；题解中保留的曙梦 OJ 100 分记录属于原版，没有将本地验证写成新的在线 Accepted。

## 结果

| 题目 | 保留的独立测试 | 保存样例/回归 | 新增边界、随机及压力 | 合计 |
| --- | ---: | ---: | ---: | ---: |
| A | 60 | 2 | 862 | 924 |
| B | 100 | 3 | 370 | 473 |
| C | 100 | 2 | 226 | 328 |
| D | 100 | 2 | 338 | 440 |
| E | 60 | 1 | 303 | 364 |
| 总计 | 420 | 10 | 2099 | 2529 |

D 的 440 组包含基础集合中的 102 组，表格已扣除重复计数。
UBSan 重跑不计作新增输入。A 最新全局变量版通过 144 组；B/C 延用先前通过的 99 组；D 在线段树封装后通过全部 440 组，后续模板排版与输入变量调整又通过两个保存样例；E 最新具名分布版通过 300 组小规模测试。均无诊断。

**A：按二进制文本核对**

oracle 将数转换为有效二进制字符串，直接比较 0 和 1 的个数。
新增集合覆盖所有正的 16 位以内整数、二次幂附近、平衡位布局，以及 $10^9$ 附近和最大长度输入。

**B：精确分数枚举**

枚举普通任务的整组选择，并枚举灵活任务的全买、不买和至多一项部分购买，用 `Fraction` 计算精确最优值。
覆盖同收益率、接近收益率、互质分母、整组购买临界点、全部灵活任务，以及 $n=200,m=1000$。

全部输入满足 $1\le a_i\le100$、$0<b_i<t_i\le10^4$。
本批新增测试最大绝对误差约为 $4.95\times10^{-9}$。

**C：从占用区间重建空闲段**

oracle 每次从实际占用区间重新找出空洞，不复用源码的双有序集合与合并状态；小规模另用逐字节占用表交叉检查。
覆盖最优适应的并列规则、左右合并、末尾收缩、队列编号变化、发送指针轮转。

压力输入包含 8000 次操作、单次长度 500000，尾地址达到 39.5 亿，并检查超过 32 位的发送地址和。

**D：逐元素数位运算**

oracle 逐元素修改，并通过完整数位循环与末尾残块直接求 $f(x)$。
该计数 oracle 另与定义中的字面递推核对了 6000 个值。

覆盖 17 种奇数进制、合数、接近 $10^9$ 的进制、$10^{12}$ 边界、重叠修改及懒标记下放。
两组压力均有 50 万元素，其中 $k=11$ 的一组包含 10000 次操作。

改成 `struct segtree`、内层节点左右端点、`pushup/pushdown`、全局 `a/ans` 后重新运行了全部 440 组。随后按 review 调整宏位置、端点赋值排版、`1e12` 和全局输入变量，编译及两个保存样例再次通过；最终基础集合的 102 组 D 测试也已通过。
节点数组预留 296 MiB；普通版与 UBSan 版均通过。

**E：BFS 路径与大树独立计数**

小规模 oracle 用 BFS 恢复实际路径，逐边统计相邻维修站之间尚未翻修的边数。
覆盖链、星形、二叉形和随机树，0 到 20 个维修站，重复及反向计划，`X=0/1` 和连续修路后的查询。

三组大规模输入均有 10 万点、10 万计划，199999 次操作：

- 无维修站的链：用修路前缀对应的计划生效阈值计数。
- 20 个维修站的链：按站点分段后独立计算生效阈值。
- 星形树：按被修边关联的计划直接计数。

E 已按最新 `BIT` 封装、`namespace HLD` 缩进和具名随机分布重新编译、验证。
随机见证只影响运行时间，答案由独立 oracle 精确比较。

## 报告与复现

- [基础 430 组结果](retained-report.json) · [冻结输入与预期答案](retained-cases.json) · [运行入口](verify-retained.py)
- [A 全局变量版验证](a-global-report.json) · [复验入口](verify-a-global.py)
- [D 模板细节复验](d-template-followup-report.json)
- [A/B/C 新增验证结果](abc-boundary-report.json) · [独立生成与验证脚本](verify-abc.py)
- [D 数位边界及压力结果](d-boundary-report.json) · [独立生成与验证脚本](verify-d.py)
- [E 路径对拍及压力结果](e-report.json) · [独立生成与验证脚本](verify-e.py)

各 JSON 记录源码 SHA-256、输入集合摘要和固定随机种子，避免将旧版二进制的结果套到新源码上。
基础测试的独立生成器来自发布仓库 `tests/first_all.py`、`second_first.py`、`third_first.py`、`fourth_first.py`、`fifth_extra.py`；冻结输入保存了本轮实际使用的预期答案。

在项目根目录准备 `.build/202603-prep/refactored/`，用支持 `bits/stdc++.h` 的 C++17 编译器将五题编译为 `A` 到 `E`。
同目录另编译带 `-fsanitize=undefined -fno-sanitize-recover=all` 的 `A-ubsan` 到 `E-ubsan`。

```sh
python3 202603/reports/verify-retained.py --bin-dir .build/202603-prep/refactored
python3 202603/reports/verify-abc.py
python3 202603/reports/verify-d.py
python3 202603/reports/verify-e.py --bin .build/202603-prep/refactored/E --ubsan .build/202603-prep/refactored/E-ubsan
```

验证结论限于保存的样例、独立测试和这些压力构造，不替代在线评测记录。
