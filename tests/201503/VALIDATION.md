# 201503 本地验证

<!-- refactor-online-validation:start -->

## 当前重构版在线评测

本节来自冻结提交计划与真实判题账本；下方本地验证记录保留其历史归属。

| 题目 | 结果 | 当前源码 SHA-256 |
|---|---|---|
| A | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a174e5d1fced2e45a8a8)。 | `eb172ff1edc4b6f7e8372f1438f28e64d002bba4447ee3630a7dee323b1c56cf` |
| B | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a1bde5d1fced2e45a934)。 | `4c1b99eca36b4960a21f631f6d76dfa73bb0c1b038f1ae8d93cbcc51d5b21777` |
| C | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a1fae5d1fced2e45a978)。 | `4f8c6fb2c746626a41873acc6cc643c1aba0cf47a384fd749f1d510adebab959` |
| D | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a238e5d1fced2e45aa04)。 | `9292f658455c5ecb0e9e27f93a5f74f248aa6ea73775202ee860f00f1cfe1f9a` |
| E | 重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a275e5d1fced2e45aa5d)。 | `eb886831bb320184de9bc4d4911588ebe81beb9af93da842cc5fecaf8ec6a489` |

[逐题在线结果与原版记录](online-verdicts.json)。

<!-- refactor-online-validation:end -->

当前重构版通过 C++17 编译与下列本地验证，该本地验证阶段未进行本轮在线提交。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 图像旋转 | 1 | 60 | 1 | 62 | 62 |
| B. 数字排序 | 1 | 100 | 1 | 102 | 102 |
| C. 节日 | 1 | 100 | 7 | 108 | 108 |
| D. 网络延时 | 2 | 79 | 1 | 82 | 82 |
| E. 最小花费 | 1 | 257 | 4 | 262 | 262 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 201503
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6addb6f774ace1cba9a20ceb)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6addb77c74ace1cba9a20d2d)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6addb88c74ace1cba9a20dc5)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6addb91774ace1cba9a20e42)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6addb9a174ace1cba9a20ea0)。

最后的局部行长复核将 D/E 的 `add` 函数邻接表写入逐条拆行，顺序不变。当前 D 的 82 组、E 的 262 组原独立/保存/边界/压力输入在 O2、UBSan 下均通过且无编译警告，详见 [add-followup.json](add-followup.json)。
