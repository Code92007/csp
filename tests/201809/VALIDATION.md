# 201809 本地验证

当前重构版通过 C++17 编译与下列本地验证，尚未重新提交在线评测。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 卖菜 | 1 | 60 | 1 | 62 | 62 |
| B. 买菜 | 1 | 100 | 1 | 102 | 102 |
| C. 元素选择器 | 1 | 100 | 1 | 102 | 102 |
| D. 再卖菜 | 1 | 90 | 2 | 93 | 93 |
| E. 线性递推式 | 3 | 580 | 4 | 587 | 587 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 201809
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6adda03c74ace1cba9a1f8b7)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6adda10674ace1cba9a1f946)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6adda1a174ace1cba9a1f972)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6adda24c74ace1cba9a1f9b0)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6adda98c74ace1cba9a1fe91)。

最新命名及容量书写复核：[naming-followup.json](naming-followup.json)。报告保留各轮源码哈希，当前源码与对应通过记录的匹配索引见 [current-sources.json](current-sources.json)。
