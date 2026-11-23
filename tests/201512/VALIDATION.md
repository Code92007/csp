# 201512 本地验证

本次重构未重新提交在线评测。题解保留的在线评测记录属于原版代码。

五题均通过 C++17 O2 与 UBSan 编译，无编译警告；O2 通过 **1249 个不同输入**，UBSan 通过 **1248 个小规模及边界输入**。

|题目|O2 输入数|UBSan 输入数|
|---|---:|---:|
|A|67|67|
|B|614|614|
|C|103|103|
|D|233|233|
|E|232|231|

输入来源：retained_independent：401；additional_independent：840；saved_sample：7；constructive_stress：1。

Digit strings, maximal equal-color runs before simultaneous elimination, literal canvas simulation, exhaustive edge-mask Euler trail search, direct GF(2) matrix exponentiation independent of Krylov polynomials.

A 以十进制字符串求和；B 穷举所有 3×3 二色棋盘，基于完整同色段同时标记；C 保留独立画布模拟，额外检查隔墙重复同色填充及横竖交叉；D 用带已用边掩码的完整欧拉路线搜索，直接比较字典序最小序列，包含断连与奇度无解。

E 对小矩阵直接做 GF(2) 矩阵乘方、作用于向量，独立于 Krylov 线性基/湮灭多项式算法，涵盖 k=0、10^9、零向量与退化关系；补 m=1000 的循环移位矩阵，轨道次数为 1000，五个查询结果由单位向量位置 k mod 1000 直接确定。O2 该构造本次约 0.009 秒。

复现：`python3 201512/reports/verify.py --repo /path/to/repository`。脚本使用仓库保存样例与独立 oracle，不执行在线提交。

完整记录：[report.json](report.json)；复现脚本：[verify.py](verify.py)；oracle 捕获工具：[retained_oracles.py](retained_oracles.py)。

## 源码 SHA-256

- `A.cpp`：`5e60cd1085007422b523f3d09bfb3f5bd2fc57566df6204f6f6947d6dd3e869a`
- `B.cpp`：`5ada26eb6c299b8d9a4d7b216b8c34dd794f01723bc8058e110dd16f74b0b5ac`
- `C.cpp`：`5759c34089bab4c9928854999b052a174e339b4c6aa8e79bb489b6791a6da8e0`
- `D.cpp`：`48408a0fbad390414fb835efcd315a8711520a6d7983d6c19b500784e3dc0f7b`
- `E.cpp`：`65ae8c42e9b69b9442054dd9d7285ae7212d14e1c05e03e0c144fda2d21309c0`

## 最终命名与常量复核

掩码使用 `S`，模数使用 `mod`；小于十万的容量常量展开为普通整数。仅调整本场涉及的命名或等值常量，原算法与历史独立对拍记录保留。当前源码重新通过 O2、UBSan 编译及全部保存样例，详见 [nightly-review-followup.json](nightly-review-followup.json)。

- `A.cpp` 当前 SHA-256：`5e60cd1085007422b523f3d09bfb3f5bd2fc57566df6204f6f6947d6dd3e869a`
- `B.cpp` 当前 SHA-256：`5ada26eb6c299b8d9a4d7b216b8c34dd794f01723bc8058e110dd16f74b0b5ac`
- `C.cpp` 当前 SHA-256：`5759c34089bab4c9928854999b052a174e339b4c6aa8e79bb489b6791a6da8e0`
- `D.cpp` 当前 SHA-256：`48408a0fbad390414fb835efcd315a8711520a6d7983d6c19b500784e3dc0f7b`
- `E.cpp` 当前 SHA-256：`cbeb1b0de2a061342f295153b50317d5dee5cefcc73bdd5427e78c88e391cb0c`

## D 辅助数组与 E 命名复验

D 的 vis、pos、st、ans 改为全局数组，容量分别覆盖点数10000、边数100000以及最多100001项的栈和答案；每次输入显式清空访问标记、游标并重置top/cnt。额外10000点、100000边欧拉图检查了起点、路线长度和每条无向边的使用次数，小图继续由全枚举oracle检验字典序最优。E 的expr改f、reduce改rem，保留原多项式运算。

O2与UBSan各通过D234、E232共466个输入，含1000维循环矩阵解析压力。[当前哈希与结果](array-name-followup-report.json) · [复现脚本](verify-array-name-followup.py)。原完整对拍与前轮哈希保留为历史。

- `D.cpp`：`90a4c0063b35f9fb8011a7fb8464938a8b09af724602e6e176fc317bb4defa79`
- `E.cpp`：`2379b70633a90f2df0d66ee0a465c94838e2afcfc565c42205f28619dac07431`
