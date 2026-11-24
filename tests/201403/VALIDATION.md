# 201403 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a533e5d1fced2e45b1a8)。 | `54d1cb07286ac63df531463a356f83997e19851dda626c9adca41c78e0186586` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a571e5d1fced2e45b25d)。 | `0681f45fd8d972c9a42b87d8f64bdbc4c18b88568301990c6ec3f41f938b9470` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a5aee5d1fced2e45b390)。 | `0867e0bab71f1a6634739d9386dcfc735358afc700fb873120d0efafc4a2243a` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a5ece5d1fced2e45b433)。 | `eadefb37c29f5073a705550d0b81140ea299cf0caf31d3f2cf59157e413864d8` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a62ae5d1fced2e45b4a9)。 | `9dd76afe748889fd99ded737f5c968ff3a9d6a7777a0e7fc7b5f9b9ddd00e3d6` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

当前重构版通过 C++17 编译与下列本地验证，该本地验证阶段未进行本轮在线提交。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 相反数 | 2 | 60 | 1 | 63 | 63 |
| B. 窗口 | 2 | 100 | 0 | 102 | 102 |
| C. 命令行选项 | 2 | 100 | 1 | 103 | 103 |
| D. 无线网络 | 2 | 109 | 2 | 113 | 113 |
| E. 任务调度 | 2 | 150 | 6 | 158 | 158 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 201403
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6addcd3974ace1cba9a21f70)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6addc14d74ace1cba9a2189b)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6addf69574ace1cba9a22df8)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6addf9b174ace1cba9a22fa2)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6addc1d874ace1cba9a218be)。
- A 原版洛谷民间评测：[accepted / 100 分](https://www.luogu.com.cn/record/305650472)。
- C 原版洛谷民间评测：[accepted / 100 分](https://www.luogu.com.cn/record/305653686)。
- D 原版洛谷民间评测：[accepted / 100 分](https://www.luogu.com.cn/record/305643544)。

新增独立检查包括：D 枚举安装位置子集后做普通 BFS；E 的 70 组小任务按实际设备掩码与完成事件运行 Dijkstra，枚举非抢占调度，而非仅复刻负载 DP。E 另含 6 组 40 任务解析/计数组合压力，覆盖上界 200、CPU/GPU 重叠及支配删除。16 位状态的无穷大使用 `0x3f3f`，大于至多 400 的串行费用；两轮滚动保留必要初始化与 `dp[0]=0`。

## E 命名复验

按 review 将编码基数改为 `bs`，串行费用上界与当前界分别改为 `tot/lim`，算法不变。当前 E 经 O2、UBSan 无诊断编译，各通过 158 组已有独立与边界输入，源码和两份题解代码块一致。报告：[names-followup.json](names-followup.json)。

- `E.cpp` 当前 SHA-256：`9dd76afe748889fd99ded737f5c968ff3a9d6a7777a0e7fc7b5f9b9ddd00e3d6`
