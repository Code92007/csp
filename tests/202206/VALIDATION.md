# 202206 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05830ae5d1fced2e455719)。 | `be41560514213ca80e4beff5b50d2ec8585db76e2cca82355d10348b83f89892` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0583a4e5d1fced2e4558bf)。 | `736f5e3862eac6c8747b5803578afbee351c494986490822e0c6cdc9a21ec5f7` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058437e5d1fced2e455a13)。 | `b18f838e56e8901b5d12ee81e51d038440278b987d334e9c23d66bf2f779ba35` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0584d0e5d1fced2e455c99)。 | `c4a6adfccafac181025c18c3263f54963f6fed2e7d261f772babfca324a7637d` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05850ee5d1fced2e455d90)。 | `0aa0f4041561176d9d95fb2ae5323dbaed900444308329b95684c7029b04d39b` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

当前重构版通过 C++17 编译与下列本地验证，该本地验证阶段未进行本轮在线提交。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 归一化处理 | 1 | 60 | 1 | 62 | 62 |
| B. 寻宝！大冒险！ | 2 | 100 | 1 | 103 | 103 |
| C. 角色授权 | 1 | 100 | 1 | 102 | 102 |
| D. 光线追踪 | 1 | 100 | 2 | 103 | 103 |
| E. PS 无限版 | 2 | 260 | 1 | 263 | 263 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 202206
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6adce920a67df0b81749c03a)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6adce921a67df0b81749c040)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6adce923a67df0b81749c046)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6adce925a67df0b81749c04d)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6addcb9374ace1cba9a21e80)。
