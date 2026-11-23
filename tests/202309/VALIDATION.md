# 202309 本地验证

当前重构版通过 C++17 编译与下列本地验证，尚未重新提交在线评测。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 坐标变换（其一） | 1 | 60 | 0 | 61 | 61 |
| B. 坐标变换（其二） | 2 | 601 | 9 | 612 | 612 |
| C. 梯度求解 | 2 | 100 | 0 | 102 | 102 |
| D. 阴阳龙 | 1 | 820 | 261 | 1082 | 1082 |
| E. 阻击 | 1 | 80 | 2 | 83 | 83 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 202309
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6adce8c8a67df0b81749bdf6)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6addb80574ace1cba9a20d52)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6adce8cca67df0b81749be25)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6ade253b74ace1cba9a24563)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6adce8cfa67df0b81749be4d)。

最新命名及容量书写复核：[naming-followup.json](naming-followup.json)、[constants-followup.json](constants-followup.json)。报告保留各轮源码哈希，当前源码与对应通过记录的匹配索引见 [current-sources.json](current-sources.json)。
