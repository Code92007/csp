# 201604 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059294e5d1fced2e45859f)。 | `27d88683255a5d09be05ffc2bcf1f18fe671e1dd572d1763fbc9f542f698ff65` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059315e5d1fced2e45874f)。 | `12fd5ff0d46471dc167332d7ed78cedc2c2b7cf0c9838a24e915832540603d96` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059359e5d1fced2e458859)。 | `28f32713b74769230bb19018acabc706552366946bc4350d74c9409bb2da91eb` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0593a2e5d1fced2e458989)。 | `4cfb2a6bcf223cb1e9fb3d9d58d2baa399b6c95cb6709810117d30e73e9b1191` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0593dfe5d1fced2e458a3f)。 | `82f9682e208f9618d97df7b7cc755db4d8aa82121dd31fbb04fe2a27b43bfd0d` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

当前重构版通过 C++17 编译与下列本地验证，该本地验证阶段未进行本轮在线提交。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 折点计数 | 1 | 60 | 2 | 63 | 63 |
| B. 俄罗斯方块 | 1 | 100 | 0 | 101 | 101 |
| C. 路径解析 | 1 | 100 | 1 | 102 | 102 |
| D. 游戏 | 1 | 94 | 1 | 96 | 96 |
| E. 网络连接 | 1 | 184 | 4 | 189 | 189 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 201604
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6addad4c74ace1cba9a20424)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6addaddf74ace1cba9a20472)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6addae9574ace1cba9a2058d)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6addaf1b74ace1cba9a20648)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6addb00e74ace1cba9a206db)。

用户最后复核将 E 的普通小并查集改为递归路径压缩板。重跑当前 E 的全部 189 个不同输入（184 独立、1 保存、4 边界/压力），O2 与 UBSan 均通过且无编译警告，当前源码哈希见 [dsu-followup.json](dsu-followup.json)。
