# 202406 本地验证

当前重构版通过 C++17 编译与下列本地验证，尚未重新提交在线评测。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 矩阵重塑（其一） | 2 | 60 | 1 | 63 | 63 |
| B. 矩阵重塑（其二） | 2 | 100 | 1 | 103 | 103 |
| C. 文本分词 | 1 | 130 | 2 | 133 | 133 |
| D. 货物调度 | 2 | 100 | 1 | 103 | 103 |
| E. 哥德尔机 | 2 | 648 | 3 | 653 | 653 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 202406
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6adce81ca67df0b81749bb2f)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6adce81da67df0b81749bb39)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6adce81fa67df0b81749bb49)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6adce821a67df0b81749bb75)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6addaa6774ace1cba9a1ff5b)。

用户风格复核已合并到本次整场重跑：A 的取模比较显式括号，B 的重塑使用短赋值分支，C 的相邻更新按同类操作成组；E 仅拆开含额外算术的下标自增减，保留 `id[pos[r]++]` 这类完整下标的单独自增。

E 的矩形、排序索引、计数表、并查集和包络坐标/值缓冲使用有明确容量的普通全局数组。每次建包络重新初始化并查集和有效值区间，合并时清空小型游标状态；计数表只在单次主流程首次使用，依靠全局零初态。实际包络池和标准区间记录表保留动态存储，后者建树后释放，避免预留巨大且常驻的理论记录上限。

E 通过648组独立矩形扫描、2个保存用例和3组50万规模解析构造，共653组，O2与UBSan均通过。三组压力实测的最大RSS约176.4 MiB；这只是所测构造的内存记录，不是所有输入的峰值证明。见 [内存报告](array-memory.json)，复现当前版本可运行 [array-memory.py](array-memory.py)。较早的风格复核报告保留历史哈希，当前全部源码哈希以 `summary.json` 为准；最初汇总另存 `summary-initial.json`。

最新命名及容量书写复核：[constants-followup.json](constants-followup.json)。报告保留各轮源码哈希，当前源码与对应通过记录的匹配索引见 [current-sources.json](current-sources.json)。
