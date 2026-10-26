---
title: "CSP 202109 五题题解"
contest: "202109"
contest_month: "2021-09"
date: "2026-10-23"
updated: "2026-10-26"
tags: ["CSP", "贪心", "前缀最大值", "差分", "阈值枚举", "模拟", "循环数组", "浮点数", "事件延迟", "概率DP", "状态压缩", "期望", "动态树", "LCT", "倍增", "历史版本"]
status: "published"
problems: [{"id": "A", "title": "数组推导", "tags": ["贪心", "前缀最大值"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "sources": [{"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16026"}], "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490510"}, "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "B", "title": "非零段划分", "tags": ["差分", "阈值枚举"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；4 个保存样例/回归用例通过；150 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "sources": [{"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16027"}], "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490539"}, "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "C", "title": "脉冲神经网络", "tags": ["模拟", "循环数组", "浮点数", "事件延迟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "sources": [{"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16028"}], "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490605"}, "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "D", "title": "收集卡牌", "tags": ["概率DP", "状态压缩", "期望"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202109D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16029"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce96fa67df0b81749c194"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305945496", "source_sha256": "d0054cc4dee11a8f6a87b53aa508d7c4dff26aeb6418407984f5a70260c5dbdc"}}, {"id": "E", "title": "箱根山岳险天下", "tags": ["动态树", "LCT", "倍增", "历史版本"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "sources": [{"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16030"}], "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490619"}, "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}]
---

# CSP 202109 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 数组推导

标签：`贪心` · `前缀最大值`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490510)。

### 题意

给出非负数组A的前缀最大值B，求所有可能A中元素和的最大值与最小值，先输出最大值。B保证单调不降。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16026)。

### 题解

每个A[i]都不能超过B[i]，全部取B[i]即可满足前缀最大值，因此最大和是ΣB[i]。若B[i]>B[i-1]，新最大值必须由A[i]=B[i]产生；若相等，最小可取0。令B[0]=0即可统一第一项。

这些下界同时可达，选择不会影响未来必须出现的新最大值，所以最小和就是所有严格上升位置的B之和。时间 $O(n)$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long previous = 0, low = 0, high = 0;
    while (n--) {
        long long b;
        cin >> b;
        high += b;
        if (b > previous)
            low += b;
        previous = b;
    }
    cout << high << '\n' << low << '\n';
}
```

<a id="problem-b"></a>

## B. 非零段划分

标签：`差分` · `阈值枚举`

状态：**已实现**。C++17 编译通过；4 个保存样例/回归用例通过；150 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490539)。

### 题意

选正整数阈值 p，把数组中小于 p 的值归零，使剩余非零连续段尽可能多。n≤$5\times10^5$，值在0…10000。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16027)。

### 题解

每个非零段有且只有一个起点。位置 i 在阈值 p 下成为起点，当且仅当 A[i]≥p 且前一个值 A[i-1]<p（令 A[0]=0）。因此它贡献1的阈值恰为整数区间 `[A[i-1]+1,A[i]]`，仅当右端不小于左端时有效。

对每个有效区间做差分加1，最后扫描所有阈值，前缀和就是该阈值下的段数，取最大值。这个计数直接按段起点建立一一对应，避免删除连续等高元素时的顺序问题。时间 $O(n+V)$，空间 $O(V)$，V=10000。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> diff(10002);
    int previous = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x > previous) {
            ++diff[previous + 1];
            --diff[x + 1];
        }
        previous = x;
    }
    int current = 0, answer = 0;
    for (int p = 1; p <= 10000; p++) {
        current += diff[p];
        answer = max(answer, current);
    }
    cout << answer << '\n';
}
```

<a id="problem-c"></a>

## C. 脉冲神经网络

标签：`模拟` · `循环数组` · `浮点数` · `事件延迟`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490605)。

### 题意

按指定离散方程更新脉冲神经网络。每步先按编号为脉冲源调用固定随机函数；神经元利用上一时刻 v、u 和当前输入强度更新，v≥30 则发放脉冲并重置。边有严格正的传播延迟。输出 T 时刻神经元 v 的最小／最大值及整个过程发放次数最小／最大值。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16028)。

### 题解

邻接表保存出边。若某结点在 t 发放，就把每条出边权重加到接收者的 t+D 时刻输入。最大延迟为 Dmax，只需长度 Dmax+1 的循环数组保存未来输入；消费当前槽后清零。正延迟保证当前时刻的发放不会影响本时刻其他神经元的更新。

更新前保存旧 v、u，两个新变量都必须使用旧值；输入 I 直接加在 v 上，不再乘 dt。达到阈值时先计数，再执行 v=c、u+=d。随机数使用无符号 64 位整数溢出，并且每个时刻每个源都调用一次，不能只为有出边的源调用。

循环数组中的每个槽始终等于对应未来时刻所有已发放脉冲的权重和，逐时刻归纳得到正确模拟。时间 $O(T(N+P+S))$，空间 $O(N(Dmax+1)+S+P)$。使用 double，最后按三位小数输出。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct Neuron {
    double v, u, a, b, c, d;
    int count = 0;
};
struct Edge {
    int to, delay;
    double weight;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, p, T;
    double dt;
    cin >> n >> s >> p >> T >> dt;
    vector<Neuron> a;
    while (int(a.size()) < n) {
        int count;
        Neuron x;
        cin >> count >> x.v >> x.u >> x.a >> x.b >> x.c >> x.d;
        while (count--)
            a.push_back(x);
    }
    vector<int> r(p);
    for (int &x : r)
        cin >> x;
    vector<vector<Edge>> g(n + p);
    int delay = 0;
    while (s--) {
        int u, v, d;
        double w;
        cin >> u >> v >> w >> d;
        g[u].push_back({v, d, w});
        delay = max(delay, d);
    }
    int ring = delay + 1;
    vector<vector<double>> input(ring, vector<double>(n));
    uint64_t seed = 1;
    auto emit = [&](int u, int t) {
        for (auto e : g[u])
            if (t + e.delay <= T)
                input[(t + e.delay) % ring][e.to] += e.weight;
    };
    for (int t = 1; t <= T; t++) {
        for (int j = 0; j < p; j++) {
            seed = seed * 1103515245 + 12345;
            int value = (seed / 65536) % 32768;
            if (r[j] > value)
                emit(n + j, t);
        }
        for (int j = 0; j < n; j++) {
            auto &x = a[j];
            double v = x.v, u = x.u;
            x.v = v + dt * (0.04 * v * v + 5 * v + 140 - u) + input[t % ring][j];
            x.u = u + dt * x.a * (x.b * v - u);
            input[t % ring][j] = 0;
            if (x.v >= 30) {
                x.v = x.c;
                x.u += x.d;
                ++x.count;
                emit(j, t);
            }
        }
    }
    double low = a[0].v, high = low;
    int lc = a[0].count, hc = lc;
    for (auto x : a) {
        low = min(low, x.v);
        high = max(high, x.v);
        lc = min(lc, x.count);
        hc = max(hc, x.count);
    }
    cout << fixed << setprecision(3) << low << ' ' << high << '\n' << lc << ' ' << hc << '\n';
}
```

<a id="problem-d"></a>

## D. 收集卡牌

标签：`概率DP` · `状态压缩` · `期望`

状态：**完整实现，已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce96fa67df0b81749c194)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305945496)（民间复刻评测）。

### 题意

有 $n$ 种卡牌，每次独立抽中第 i 种的概率为 $p_i$。重复卡变成一枚硬币，k 枚硬币可换一张未拥有的卡。求集齐全部卡牌的最小期望抽卡次数。可以等硬币足够补齐所有缺卡时一次性兑换。$n\le16,k\le5$，输出允许绝对误差 $10^{-4}$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16029)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202109D)。

### 题解

**为什么可以推迟兑换？** 提前兑换某张卡后若再抽到它，只获得一枚硬币；如果此前不兑换，就直接得到这张卡，同时保留原来准备兑换所用的 k 枚硬币。因为 $k\ge1$，推迟兑换不会更差。因此只在硬币足够补齐缺卡时停止抽卡即可。

用位掩码 $S$ 表示已经抽到的卡种，c 表示硬币数。设 $E[S][c]$ 为从此状态出发还需抽卡的期望。若 $c\ge k(n-|S|)$，直接兑换，期望为 0。否则先花一次抽卡，然后按抽中卡种分解：

$$E[S][c]=1+\left(\sum_{i\in S}p_i\right)E[S][c+1]+\sum_{i\notin S}p_iE[S\cup\{i\}][c].$$

重复卡使 c 增加，新卡使集合严格增大，所以没有自环，也无需在等式两侧解未知数。按掩码从大到小、硬币数从大到小计算即可；所有严格超集的二进制数都更大。初始答案为 $E[0][0]$。

全概率公式覆盖一次抽卡的全部互斥结果，终止状态与兑换条件一致，故反向 DP 正确。最多 nk 枚硬币就足够，时间 $O(2^n n^2k)$，空间 $O(2^n nk)$。保留足够小数位输出。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<double> p(n);
    for (auto &x : p)
        cin >> x;
    int masks = 1 << n, max_coins = n * k;
    vector<int> count(masks);
    for (int s = 1; s < masks; ++s)
        count[s] = count[s >> 1] + (s & 1);
    vector<vector<double>> expected(masks, vector<double>(max_coins + 1));
    for (int s = masks - 2; s >= 0; --s) {
        int need = (n - count[s]) * k;
        double duplicate = 0;
        for (int i = 0; i < n; ++i)
            if (s >> i & 1)
                duplicate += p[i];
        for (int coins = need - 1; coins >= 0; --coins) {
            double value = 1 + duplicate * expected[s][coins + 1];
            for (int i = 0; i < n; ++i)
                if (!(s >> i & 1))
                    value += p[i] * expected[s | (1 << i)][coins];
            expected[s][coins] = value;
        }
    }
    cout << fixed << setprecision(12) << expected[0][0] << '\n';
}
```

<a id="problem-e"></a>

## E. 箱根山岳险天下

标签：`动态树` · `LCT` · `倍增` · `历史版本`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490619)。

### 题意

维护一份会在末尾加入成员或删除末尾成员的名单。操作还能选择第 $s$ 天结束时名单中第 $l$ 至 $r$ 位成员，对这些成员的当前权值乘以 $y$，或者查询当前权值之和，结果模 $p$。名单是历史版本，权值不是历史快照：退出名单的人仍可能在旧名单查询中出现。输入 `m p T`，操作 1 为入队或退队，2 为乘法，3 为求和；指定参数按原题异或最近答案解码。$m\le3\times10^5$。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16030)

### 题解

**把所有名单版本组成一棵历史树。** 每次加入新成员，新建一个点，其父亲是加入前的名单末尾。删除末尾只把当前指针移到父亲。每一天记录末尾节点 `tail[day]`。于是任何一天的名单，都恰好是虚拟根到该末尾的一条祖先链；成员顺序对应树深度。

预处理新点的倍增祖先。给定历史末尾 $u$ 和名单位置 $l,r$，分别跳到深度为 $l,r$ 的两个祖先，就得到要操作的路径端点。特别注意 $s$ 等于当前操作日时，要使用当前末尾，而不是尚未写入的 `tail[s]`。

**历史树固定身份，动态树维护当前数值。** 用 Link-Cut Tree 对这棵只增点的树支持路径乘、路径和。暴露端点路径后，其辅助树聚合值就是答案；乘法懒标记同时作用于节点权值、子树和及已有标记。反转路径时交换左右孩子并翻转反转标记，数值乘法与反转可独立下传。

新成员只需创建一个独立辅助树节点，将其路径父亲设为当时末尾；退队不删除树节点、不撤销乘法，也不切断历史边。否则查询旧名单就会丢失成员。输入解码只针对题面指定的 $x,y$，不能擅自解码历史日期和位置。

**正确性。** 父亲关系逐步记录了每次入队前的完整名单，倍增定位因此准确。历史名单区间是祖先链上的连续路径，LCT 对该路径的更新作用于同一批成员的当前值，恰好符合题意。**复杂度：** 每次操作摊还 $O(\log m)$，祖先表空间 $O(m\log m)$；模乘使用 64 位，覆盖 $p<2^{30}$ 的乘积。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct LCT {
    struct Node {
        int child[2]{}, parent = 0;
        ll value = 0, sum = 0, mul = 1;
        bool rev = false;
    };
    vector<Node> t;
    vector<int> stack;
    ll mod;
    LCT(int n, ll p) : t(n + 1), mod(p) {
        stack.reserve(n);
    }
    bool isRoot(int x) {
        int p = t[x].parent;
        return t[p].child[0] != x && t[p].child[1] != x;
    }
    void pull(int x) {
        t[x].sum = (t[x].value + t[t[x].child[0]].sum + t[t[x].child[1]].sum) % mod;
    }
    void multiply(int x, ll v) {
        if (!x)
            return;
        t[x].value = t[x].value * v % mod;
        t[x].sum = t[x].sum * v % mod;
        t[x].mul = t[x].mul * v % mod;
    }
    void flip(int x) {
        if (x) {
            swap(t[x].child[0], t[x].child[1]);
            t[x].rev ^= 1;
        }
    }
    void push(int x) {
        if (t[x].rev) {
            flip(t[x].child[0]);
            flip(t[x].child[1]);
            t[x].rev = false;
        }
        if (t[x].mul != 1) {
            multiply(t[x].child[0], t[x].mul);
            multiply(t[x].child[1], t[x].mul);
            t[x].mul = 1;
        }
    }
    void rotate(int x) {
        int p = t[x].parent, g = t[p].parent, d = t[p].child[1] == x, v = t[x].child[d ^ 1];
        if (!isRoot(p))
            t[g].child[t[g].child[1] == p] = x;
        t[x].parent = g;
        t[x].child[d ^ 1] = p;
        t[p].parent = x;
        t[p].child[d] = v;
        if (v)
            t[v].parent = p;
        pull(p);
        pull(x);
    }
    void splay(int x) {
        stack.clear();
        int y = x;
        stack.push_back(y);
        while (!isRoot(y)) {
            y = t[y].parent;
            stack.push_back(y);
        }
        for (auto it = stack.rbegin(); it != stack.rend(); ++it)
            push(*it);
        while (!isRoot(x)) {
            int p = t[x].parent, g = t[p].parent;
            if (!isRoot(p))
                rotate((t[p].child[1] == x) == (t[g].child[1] == p) ? p : x);
            rotate(x);
        }
    }
    void access(int x) {
        for (int y = 0, u = x; u; y = u, u = t[u].parent) {
            splay(u);
            t[u].child[1] = y;
            pull(u);
        }
        splay(x);
    }
    void path(int u, int v) {
        access(u);
        flip(u);
        access(v);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, mod, T;
    cin >> m >> mod >> T;
    LCT tree(m, mod);
    vector<array<int, 20>> up(m + 1);
    vector<int> depth(m + 1), tail(m + 1);
    int current = 0, count = 0, last = 0;
    auto atDepth = [&](int u, int d) {
        int step = depth[u] - d;
        for (int b = 0; b < 20; ++b)
            if (step >> b & 1)
                u = up[u][b];
        return u;
    };
    for (int day = 1; day <= m; ++day) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            x ^= T * last;
            if (!x)
                current = up[current][0];
            else {
                int u = ++count;
                up[u][0] = current;
                depth[u] = depth[current] + 1;
                for (int b = 1; b < 20; ++b)
                    up[u][b] = up[up[u][b - 1]][b - 1];
                tree.t[u].value = tree.t[u].sum = x % mod;
                tree.t[u].parent = current;
                current = u;
            }
        } else {
            int s, l, r;
            cin >> s >> l >> r;
            int endpoint = s == day ? current : tail[s];
            int u = atDepth(endpoint, l), v = atDepth(endpoint, r);
            tree.path(u, v);
            if (op == 2) {
                int y;
                cin >> y;
                y ^= T * last;
                tree.multiply(v, y % mod);
            } else {
                last = tree.t[v].sum;
                cout << last << '\n';
            }
        }
        tail[day] = current;
    }
}
```
