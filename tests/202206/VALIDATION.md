# 202206 本地验证

当前重构版通过 C++17 编译与下列本地验证，尚未重新提交在线评测。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

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
