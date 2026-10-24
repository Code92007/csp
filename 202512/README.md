---
title: "CSP 202512 五题题解"
contest: "202512"
contest_month: "2025-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "集合比较", "异或", "哈希冲突", "位运算", "枚举", "预处理", "模拟", "逆向操作", "坐标变换", "数论", "线性筛", "积性函数", "容斥", "Trie", "图染色", "可合并数据结构"]
status: "published"
problems: [{"id": "A", "title": "集合", "tags": ["集合比较", "异或", "哈希冲突"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce72ea67df0b81749b5e6"}}, {"id": "B", "title": "数字变换", "tags": ["位运算", "枚举", "预处理"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；30 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce72fa67df0b81749b607"}}, {"id": "C", "title": "图片解码", "tags": ["模拟", "逆向操作", "坐标变换"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce731a67df0b81749b611"}}, {"id": "D", "title": "C 形阵", "tags": ["数论", "线性筛", "积性函数", "容斥"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；3 个保存样例/回归用例通过；160 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce733a67df0b81749b625"}}, {"id": "E", "title": "数据抢修", "tags": ["Trie", "图染色", "可合并数据结构"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce734a67df0b81749b63c"}}]
---

# CSP 202512 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 集合

标签：`集合比较` · `异或` · `哈希冲突`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

集合S的摘要为对应a[i]的异或和，小C用摘要相等判断集合相等。对每对已升序且无重复的S、T，判断这一结论是否正确。输入先给全部S，再给全部T。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202512A)。

### 题解

读取每个S时保存有序元素数组并计算异或值；再逐个读T，分别比较真实数组是否相等、异或摘要是否相等。两种布尔结论相同输出correct，否则wrong。

数组已严格升序，因此数组逐项相同等价于集合相同；异或值可能碰撞，不能代替真实比较。实际上只会出现“集合不同但摘要相同”的误判。时间与输入元素总数线性相关，空间为全部S及一个T的大小。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), hash(m);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> sets(m);
    for (int i = 0; i < m; i++) {
        int size;
        cin >> size;
        sets[i].resize(size);
        for (int &x : sets[i]) {
            cin >> x;
            hash[i] ^= a[x];
        }
    }
    for (int i = 0; i < m; i++) {
        int size, value = 0;
        cin >> size;
        vector<int> other(size);
        for (int &x : other) {
            cin >> x;
            value ^= a[x];
        }
        bool actual = sets[i] == other, predicted = hash[i] == value;
        cout << (actual == predicted ? "correct" : "wrong") << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 数字变换

标签：`位运算` · `枚举` · `预处理`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；30 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

将九位数拆为三个三位数 (a,b,c)，一轮密钥 k 变换为 $(b,c\oplus f(b,k),a\oplus f(c,k))$，其中 $f(x,k)=((x^2+k^2)\bmod8)\oplus k$。给定至多 1000 轮密钥及至多 $5\times10^5$ 个最终值，恢复初始值。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202512B)。

### 题解

输入状态只有 512 种，逐一枚举初始值并执行全部密钥，记录 inverse[最终值]=初始值。之后每个查询直接查表，不要为每个查询再执行所有轮。

每轮可逆：若输出为 (A,B,C)，则 b=A，c=B⊕f(b,k)，a=C⊕f(c,k)，所以整轮和多轮复合都是双射，逆表不会冲突。实现时三段分别用右移、按位与拆出，再以左移和按位或拼回。时间 $O(512m+n)$，空间 $O(m+512)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int f(int x, int k) {
    return ((x * x + k * k) % 8) ^ k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> keys(m);
    for (int &k : keys)
        cin >> k;
    int inverse[512];
    for (int initial = 0; initial < 512; initial++) {
        int x = initial;
        for (int k : keys) {
            int a = x >> 6, b = (x >> 3) & 7, c = x & 7;
            x = (b << 6) | ((c ^ f(b, k)) << 3) | (a ^ f(c, k));
        }
        inverse[x] = initial;
    }
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (i)
            cout << ' ';
        cout << inverse[x];
    }
    cout << '\n';
}
```

<a id="problem-c"></a>

## C. 图片解码

标签：`模拟` · `逆向操作` · `坐标变换`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

原图先在右下方补问号成 Z×Z 方图，再执行两类加密：局部至多 10×10 正方形顺时针旋转 d 度，随后全图逆时针旋转 r 次；或对至多 10×10 矩形上下／左右翻转。给出最终图和全部操作密钥，恢复原图并输出行列数及内容。$Z\le400,t\le5\times10^4$。密钥首数为 t，每个操作再占六个整数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202512C)。

### 题解

可逆操作必须倒序撤销。对于旋转操作，先撤销最后发生的全图旋转，再撤销局部旋转；翻转自身就是逆操作。

全图旋转若逐次搬动字符会达到 $O(tZ^2)$。这里只记录一个方向值，访问逻辑坐标时再旋转坐标映射到实际数组。顺时针旋转图像后，新坐标 `(i,j)` 的值来自旧坐标 `(Z-1-j,i)`，因此坐标映射方向与图像转动方向相反，不能混用。

局部操作只涉及至多 100 个字符，先把逻辑矩形复制到临时数组，再按逆映射写回，防止覆盖尚未读取的字符。全部撤销后，原图在左上角，问号只在补齐区域；沿第一列和第一行读到问号前的长度即可恢复尺寸。

每个逆操作与对应加密互为逆映射，按逆序复合后恰好回到原图。时间 $O(Z^2+100t)$，空间 $O(Z^2+t)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int z;
    cin >> z;
    vector<string> image(z);
    for (auto &row : image)
        cin >> row;
    int key_length, t;
    cin >> key_length >> t;
    vector<array<int, 6>> ops(t);
    for (auto &op : ops)
        for (auto &x : op)
            cin >> x;
    int orientation = 0;
    auto at = [&](int r, int c) -> char & {
        for (int i = 0; i < orientation; ++i) {
            int next = c;
            c = z - 1 - r;
            r = next;
        }
        return image[r][c];
    };
    for (auto it = ops.rbegin(); it != ops.rend(); ++it) {
        auto op = *it;
        if (op[0] == 1) {
            int u = op[1] - 1, v = op[2] - 1, length = op[3], turns = op[4] / 90;
            orientation = (orientation + 4 - op[5]) % 4;
            vector<string> copy(length, string(length, ' '));
            for (int i = 0; i < length; ++i)
                for (int j = 0; j < length; ++j)
                    copy[i][j] = at(u + i, v + j);
            for (int i = 0; i < length; ++i)
                for (int j = 0; j < length; ++j) {
                    int r = i, c = j;
                    for (int k = 0; k < turns; ++k) {
                        int next = c;
                        c = length - 1 - r;
                        r = next;
                    }
                    at(u + i, v + j) = copy[r][c];
                }
        } else {
            int u = op[1] - 1, d = op[2] - 1, l = op[3] - 1, r = op[4] - 1;
            vector<string> copy(d - u + 1, string(r - l + 1, ' '));
            for (int i = u; i <= d; ++i)
                for (int j = l; j <= r; ++j)
                    copy[i - u][j - l] = at(i, j);
            for (int i = u; i <= d; ++i)
                for (int j = l; j <= r; ++j)
                    at(i, j) = op[5] == 1 ? copy[d - i][j - l] : copy[i - u][r - j];
        }
    }
    int n = 0, m = 0;
    while (n < z && at(n, 0) != '?')
        ++n;
    while (m < z && at(0, m) != '?')
        ++m;
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << at(i, j);
        cout << '\n';
    }
}
```

<a id="problem-d"></a>

## D. C 形阵

标签：`数论` · `线性筛` · `积性函数` · `容斥`

状态：**已实现**。C++17 编译通过；3 个保存样例/回归用例通过；160 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

正整数七元组 $(A,B,C,D,E,F,G)$ 满足 $AC=B^2$、$EG=F^2$、$ABC=CDE=EFG$。大小为 $B$，价值为 $D$。给定 `op n`：`op=0` 时求大小不超过 $n$ 的全部阵的价值之和；`op=1` 时只统计七个位置中恰有六种数值的阵。答案模 $998244353$，$n\le10^7$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202512D)。

### 题解

**从七个数降到两个选择。** 比例关系给出 $ABC=B^3$ 和 $EFG=F^3$，所以 $B=F=b$。选定 $C,E$ 后，另外三个数唯一确定为 $A=b^2/C$、$G=b^2/E$、$D=b^3/(CE)$。

固定一个质因子 $p^e\parallel b$，令 $C,E$ 在该质因子上的指数分别为 $e+x,e+y$。正整数条件等价于 $-e\le x,y\le e$、$x+y\le e$；该方案贡献给价值的因子为 $p^{e-x-y}$。不同质因子的指数可以独立选择，故固定 $b$ 的价值和是积性函数。

**处理恰好六种数值。** $B=F$ 已经贡献一次相等，因此还需 $A,B,C,D,E,G$ 两两不同。把所有质因子的 $x,y$ 看作向量 $X,Y$；比较六个数的指数，可将全部额外相等归为六条关系：$X=0,Y=0,X=Y,X=-Y,Y=-2X,X=-2Y$。例如 $A=D$ 等价于 $Y=0$，$C=D$ 等价于 $Y=-2X$。

任意两条不同关系同时成立，都会推出 $X=Y=0$。设总函数为 $T$，四种代表性坏函数分别对应 $X=0,X=Y,X=-Y,Y=-2X$，记作 $U,V,W,Z$；另两种由对称性得到相同的和。所有坏条件的共同交集只有七个数都为 $b$ 的阵，价值是 $b$。因此完美阵在大小 $b$ 下贡献

$$T(b)-2U(b)-V(b)-W(b)-2Z(b)+5b.$$

系数 5 来自六个集合的容斥：直接减了六遍共同交集，而本来只应减一遍。

**用筛法计算。** 对每个质数幂 $p^e$，枚举上述 $(x,y)$ 求出五个局部函数值。筛出每个数的最小质因子，将 $i=p^er$（$p\nmid r$）分解后，用 $F(i)=F(p^e)F(r)$ 计算。大于 $\sqrt n$ 的质数只会出现一次，局部值直接用多项式：$T(p)=p^3+2p^2+3p+2$，$U(p)=p^2+p+1$，$V(p)=p^3+p$，$W(p)=3p$，$Z(p)=p$。

筛法与积性递推保证每个指数选择恰被计入一次，容斥则恰好剔除有额外相等的方案。空间 $O(n)$；主体筛与枚举数值为线性量级，提取最小质因子的幂次数可用 $O(n\log n)$ 的保守上界，局部表预处理至多 $O(\sqrt n\log^3 n)$。`op=0` 时只保存一个函数数组。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;
constexpr int MOD = 998244353;
using Values = array<int, 5>;
Values local(int p, int exponent) {
    vector<i64> power(3 * exponent + 1, 1);
    for (int i = 1; i <= 3 * exponent; ++i)
        power[i] = power[i - 1] * p % MOD;
    Values ans{};
    for (int x = -exponent; x <= exponent; ++x) {
        for (int y = -exponent; y <= exponent; ++y) {
            if (x + y > exponent)
                continue;
            int w = power[exponent - x - y];
            auto add = [&](int index) { ans[index] = (ans[index] + w) % MOD; };
            add(0);
            if (x == 0)
                add(1);
            if (x == y)
                add(2);
            if (x == -y)
                add(3);
            if (y == -2 * x)
                add(4);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int op, n;
    cin >> op >> n;
    int limit = sqrt(n);
    vector<int> least(n + 1), primes;
    for (int i = 2; i <= n; ++i) {
        if (!least[i]) {
            least[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > least[i] || i64(p) * i > n)
                break;
            least[i * p] = p;
        }
    }
    vector<vector<Values>> table(limit + 1);
    for (int p : primes) {
        if (p > limit)
            break;
        table[p].push_back({});
        for (i64 power = p, e = 1; power <= n; power *= p, ++e)
            table[p].push_back(local(p, int(e)));
    }
    int count = op ? 5 : 1;
    vector<vector<int>> f(count, vector<int>(n + 1));
    for (auto &row : f)
        row[1] = 1;
    i64 answer = op ? 0 : 1;
    for (int i = 2; i <= n; ++i) {
        int p = least[i], rest = i, exponent = 0;
        do {
            rest /= p;
            ++exponent;
        } while (rest % p == 0);
        Values v;
        if (p <= limit)
            v = table[p][exponent];
        else {
            i64 p2 = i64(p) * p % MOD, p3 = p2 * p % MOD;
            v = {int((p3 + 2 * p2 + 3LL * p + 2) % MOD), int((p2 + p + 1) % MOD),
                 int((p3 + p) % MOD), int(3LL * p % MOD), p};
        }
        for (int j = 0; j < count; ++j)
            f[j][i] = i64(f[j][rest]) * v[j] % MOD;
        i64 value = f[0][i];
        if (op)
            value += -2LL * f[1][i] - f[2][i] - f[3][i] - 2LL * f[4][i] + 5LL * i;
        answer = (answer + value) % MOD;
    }
    cout << (answer + MOD) % MOD << '\n';
}
```

<a id="problem-e"></a>

## E. 数据抢修

标签：`Trie` · `图染色` · `可合并数据结构`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

每个数据包是允许重复元素的多重集。把它分成若干非空子包，要求同一子包内任意两个不同元素的权值异或至少为 $W$，最少分包数就是维修代价。维护插入、把包 $v$ 并入包 $u$ 并注销 $v$、查询全部活跃包代价之和。空包代价为零。第一行 `n W`；每包一行元素数和元素；随后操作数及 `1 u x`、`2 u v`、`3`。初始元素总数与操作数均不超过 $5\times10^5$，权值不超过 $10^9$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202512E)。

### 题解

**把“不能放一起”画成边。** 当 $x\oplus y<W$ 时，两元素冲突；分包就是给冲突图染色。令 $h$ 为 $W$ 的最高位。比 $h$ 更高的前缀不同的元素完全不冲突，所以可以复用颜色，包的答案取各前缀答案的最大值。在一个固定前缀内，按第 $h$ 位分成两侧；每侧内部都是团。冲突图的补图是二分图，根据二分图的匹配与点覆盖定理，最少颜色数等于最大团大小。

**低位递归。** 记 $L=W-2^h$，需要在左右两侧各选一些元素，使所有跨侧异或严格小于 $L$。若当前阈值位为 0，跨侧只能取相同位，两种递归分支不能混用；还要允许只取左侧或只取右侧全部元素。若阈值位为 1，同位组合已经严格小于阈值，限制只留在两组异位组合上，两组最优值可以相加。所有位相等时不满足严格小于，只能选一侧。

**让两棵 Trie 对齐。** 对第 $h$ 位为 1 的元素，将低 $h$ 位异或 $L$，再删除第 $h$ 位。这样递归中需要配对的两侧前缀，恰好落入同一 Trie 节点。节点记录两侧元素数和最优值：高位取两个孩子的最大值；低位阈值为 1 时取孩子之和；其余情况取两侧计数及孩子答案的最大值。重复元素通过计数保留，不能去重。

插入仅改一条 Trie 路径；合并递归合并同位置节点并重新计算。每个被消耗的节点只消失一次，故所有合并访问总数受已创建节点数约束。操作前减去旧包答案，操作后加入新答案，即可常数时间回答总和。

**正确性。** 高位分组允许颜色复用，组内二分图补图保证团数等于染色数；低位的三种递归完整划分跨侧限制，Trie 聚合正好计算该团数。**复杂度：** 设全部插入元素数为 $N$、位数为 $B\le30$，构建、插入及全部合并共 $O(NB+q)$，空间 $O(NB+n)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// At each lower-bit node, two sides are internally cliques.
struct Node {
    int child[2]{}, count[2]{}, best = 0;
};
vector<Node> trie(1);
int highest, threshold;
int fresh() {
    trie.emplace_back();
    return int(trie.size()) - 1;
}
void pull(int u, int bit) {
    int l = trie[u].child[0], r = trie[u].child[1];
    if (bit >= highest)
        trie[u].best = max(trie[l].best, trie[r].best);
    else if (bit >= 0 && (threshold >> bit & 1))
        trie[u].best = trie[l].best + trie[r].best;
    else
        trie[u].best = max({trie[u].count[0], trie[u].count[1], trie[l].best, trie[r].best});
}
int insert(int u, unsigned key, int side, int bit) {
    if (!u)
        u = fresh();
    ++trie[u].count[side];
    if (bit >= 0) {
        int c = key >> bit & 1;
        // Do not keep references into vector across a possible reallocation.
        int v = insert(trie[u].child[c], key, side, bit - 1);
        trie[u].child[c] = v;
    }
    pull(u, bit);
    return u;
}
int mergeTree(int u, int v, int bit) {
    if (!u || !v)
        return u | v;
    for (int s = 0; s < 2; ++s)
        trie[u].count[s] += trie[v].count[s];
    if (bit >= 0)
        for (int c = 0; c < 2; ++c)
            trie[u].child[c] = mergeTree(trie[u].child[c], trie[v].child[c], bit - 1);
    pull(u, bit);
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long W;
    if (!(cin >> n >> W))
        return 0;
    vector<int> roots(n + 1), sizes(n + 1);
    // All input values are below 2^30.
    bool allConflict = W >= (1LL << 30);
    highest = 0;
    while ((1LL << (highest + 1)) <= W && highest < 30)
        ++highest;
    threshold = int(W - (1LL << highest));
    auto add = [&](int u, unsigned x) {
        ++sizes[u];
        if (allConflict)
            return;
        int side = x >> highest & 1;
        unsigned low = x & ((1u << highest) - 1);
        if (side)
            low ^= threshold;
        unsigned key = ((x >> (highest + 1)) << highest) | low;
        roots[u] = insert(roots[u], key, side, 28);
    };
    auto value = [&](int u) { return allConflict ? sizes[u] : trie[roots[u]].best; };
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        while (m--) {
            unsigned x;
            cin >> x;
            add(i, x);
        }
        total += value(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u;
            unsigned x;
            cin >> u >> x;
            total -= value(u);
            add(u, x);
            total += value(u);
        } else if (op == 2) {
            int u, v;
            cin >> u >> v;
            total -= value(u) + value(v);
            sizes[u] += sizes[v];
            sizes[v] = 0;
            if (!allConflict)
                roots[u] = mergeTree(roots[u], roots[v], 28);
            roots[v] = 0;
            total += value(u);
        } else
            cout << total << '\n';
    }
}
```
