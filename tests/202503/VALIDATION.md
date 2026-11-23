# 202503 本地验证

当前重构版通过 C++17 编译与下列本地验证，尚未重新提交在线评测。原版的在线记录保留原有归属；本地通过不记作新的在线 Accepted。

| 题目 | 保存用例 | 独立对拍 | 边界/压力 | 优化版总数 | UBSan 总数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| A. 数值积分 | 2 | 60 | 4 | 66 | 66 |
| B. 机器人饲养指南 | 2 | 100 | 2 | 104 | 104 |
| C. 模板展开 | 2 | 100 | 1 | 103 | 103 |
| D. 集体锻炼 | 2 | 130 | 1 | 133 | 133 |
| E. 收费标准评估 | 1 | 320 | 3 | 324 | 324 |

独立对拍复用原仓库的 Python 暴力/检查器，捕获后直接运行当前源码；没有用旧版程序的输出代替独立答案。新增边界与压力的生成方式见 [extra.py](extra.py)。

复现：

```bash
python3 tools/nightly/verify_personal.py 202503
```

记录：[编译命令](compile.json) · [全部输入及独立答案](cases.json) · [结果与源码哈希](summary.json)。

原版评测记录：

- A：[accepted / 100 分](https://oj.shumeng.tech/record/6adce7b9a67df0b81749b958)。
- B：[accepted / 100 分](https://oj.shumeng.tech/record/6adce7bba67df0b81749b972)。
- C：[accepted / 100 分](https://oj.shumeng.tech/record/6adce7bda67df0b81749b97b)。
- D：[accepted / 100 分](https://oj.shumeng.tech/record/6adce7bea67df0b81749b983)。
- E：[accepted / 100 分](https://oj.shumeng.tech/record/6adce7c0a67df0b81749b987)。

本次风格复核：C 将重复的条件表达式保存为 `ll v`，D 在确认 `h` 非空后用 `P &w=h.back()` 修改当前项。两题分别重跑 103、133 组，O2 和 UBSan 均通过且无编译警告。初次汇总保留历史源码哈希，当前 C/D 哈希及复现入口见 [后续报告](style-followup.json) 与 [脚本](style-followup.py)。

E 按用户 LinkCutTree 板子组织为分离数组、访问宏与熟悉的操作函数，保留本题虚子树正贡献总和及多重集合。祖先标记使用迭代栈下推，避免长链递归。当前封装另外通过200组连通子集枚举及十万节点全负星形换根、查询、切连边压力，连同原有123组，共324组；O2和UBSan均通过且无编译警告。当前E源码哈希及全部输入见 [LCT复核](lct-followup.json)、[输入与答案](lct-cases.json)，复现脚本为 [lct-followup.py](lct-followup.py)。初次summary保留历史哈希。

最新命名及容量书写复核：[naming-followup.json](naming-followup.json)、[constants-followup.json](constants-followup.json)。报告保留各轮源码哈希，当前源码与对应通过记录的匹配索引见 [current-sources.json](current-sources.json)。
