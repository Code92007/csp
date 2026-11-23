# 201503 本地验证

当前重构版通过 C++17 编译与下列本地验证，尚未重新提交在线评测。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

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
