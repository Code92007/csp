# 202412 本地验证

本次重构未重新提交在线评测。题解保留的在线评测记录属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **1221 个不同输入**，UBSan 通过 **1218 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|76|75|
|B|252|252|
|C|251|251|
|D|416|415|
|E|226|225|

输入来源：retained_independent：567；additional_independent：644；saved_sample：7；constructive_stress：3。

Independent step simulation, initial-energy feasibility, list-based cache simulation, explicit graph BFS, interval make/kill DP.

A 穷举小场地四步指令，另测一百万字符指令流；B 逐一枚举初始能量并直接执行行程；C 以普通列表独立维护缓存；D 以完整边枚举 BFS 对拍；E 递归枚举左右攻击选择，并测试修改不累积与原数组恢复。

最大规模构造：D 为十万格、跳跃上限 10^9，答案 1；E 为二百万梦魔、等防御等收益，连续两次查询均应为 10^9。O2 本次分别约 0.011 秒与 0.208 秒，均非普遍性能保证。

复现：`python3 202412/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 初版全量验证源码 SHA-256

- `A.cpp`：`fe39fd7880e10e9da3d6b833b2cc868b2f8f72189564cae735d7ee95c325fd67`
- `B.cpp`：`c2319119bc4d46c845be647885b597f61bc21db2e0e2c24f1ad6fdd51a1b7455`
- `C.cpp`：`b2de022babdf4bf41269f23bbe1219cfbacc356b98d1e7fd9a68a19eeb107c53`
- `D.cpp`：`3a25bb512f48002f27b21559bc763469cfe6a0e9dc64d27c5f925bbf4a11751b`
- `E.cpp`：`4a18baeac5da9ea0c8a82c1df3c68684d7a5d132b19f9c980cc3c15b73b004bd`

## sizeof 写法复核

两处 memcpy 分别改用 `sizeof *a`、`sizeof *b`，类型仍为 int，复制长度不变。E 单独以 O2、UBSan 各重新通过 226 个输入（包含二百万规模构造），无编译或运行诊断。原 report.json 保留历史哈希。

当前 E.cpp SHA-256：`7ae5e5f1e5eed6aa0bd9083b1c74bc0619a098ade17b779b4c8d52bce0f93511`。

记录：[e-sizeof-followup-report.json](e-sizeof-followup-report.json)；复现：[verify-e-sizeof.py](verify-e-sizeof.py)。
