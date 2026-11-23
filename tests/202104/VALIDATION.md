# 202104 本地验证

当前重构版通过 C++17 编译与下列本地验证，尚未重新提交在线评测。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 灰度直方图 | 2 | 60 | 1 | 63 | 63 |
| B. 邻域均值 | 2 | 100 | 1 | 103 | 103 |
| C. DHCP 服务器 | 2 | 100 | 1 | 103 | 103 |
| D. 校门外的树 | 2 | 95 | 4 | 101 | 101 |
| E. 疫苗运输 | 3 | 60 | 2 | 65 | 65 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 202104
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6adce971a67df0b81749c1a2)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6adce972a67df0b81749c1b8)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6adceb1074ace1cba9a1bca0)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6adceb1274ace1cba9a1bca8)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6add984074ace1cba9a1f29d)。

最新命名及容量书写复核：[naming-followup.json](naming-followup.json)、[constants-followup.json](constants-followup.json)。报告保留各轮源码哈希，当前源码与对应通过记录的匹配索引见 [current-sources.json](current-sources.json)。

## E 输出换行复核

按最新风格将单独换行改为 `puts("")`，输出语义不变；O2、UBSan 无诊断编译，各重放 65 组既有独立与保存输入。源码及两份题解同步，报告：[newline-followup.json](newline-followup.json)。

- `E.cpp` 当前 SHA-256：`9c0d36402afe1f772f3622f837f6ea1e05c2b9ed92c6e3ac9cd7f85b61d17d14`
