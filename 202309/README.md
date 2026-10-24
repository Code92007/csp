---
title: "CSP 202309 五题题解"
contest: "202309"
contest_month: "2023-09"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "累加", "平移变换", "前缀积", "前缀和", "旋转变换", "自动微分", "表达式", "栈", "有序集合", "几何", "模拟", "动态树", "树的直径", "动态规划"]
status: "published"
problems: [{"id": "A", "title": "坐标变换（其一）", "tags": ["累加", "平移变换"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16054"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c8a67df0b81749bdf6"}}, {"id": "B", "title": "坐标变换（其二）", "tags": ["前缀积", "前缀和", "旋转变换"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 80 分 Wrong Answer（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16055"}], "oj": {"status": "failed", "score": 80, "verdict": "Wrong Answer", "record": "https://oj.shumeng.tech/record/6adce8caa67df0b81749be0c"}}, {"id": "C", "title": "梯度求解", "tags": ["自动微分", "表达式", "栈"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16056"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8cca67df0b81749be25"}}, {"id": "D", "title": "阴阳龙", "tags": ["有序集合", "几何", "模拟"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 15 分 Time Exceeded（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16057"}], "oj": {"status": "failed", "score": 15, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6adce8cda67df0b81749be44"}}, {"id": "E", "title": "阻击", "tags": ["动态树", "树的直径", "动态规划"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16058"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8cfa67df0b81749be4d"}}]
---

# CSP 202309 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 坐标变换（其一）

标签：`累加` · `平移变换`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定n次平移(dx,dy)，求m个起点各自按相同操作序列平移后的坐标。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16054)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309A)。

### 题解

平移对两坐标分别加法，先累计全部dx和dy，再给每个点加上这两个总位移。

加法结合律保证合并后的平移等于逐次执行，所有点可共用预处理结果。时间 $O(n+m)$，额外空间 $O(1)$，累加使用64位。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    long long dx = 0, dy = 0;
    while (n--) {
        long long x, y;
        cin >> x >> y;
        dx += x;
        dy += y;
    }
    while (m--) {
        long long x, y;
        cin >> x >> y;
        cout << x + dx << ' ' << y + dy << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 坐标变换（其二）

标签：`前缀积` · `前缀和` · `旋转变换`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 80 分 Wrong Answer（复刻评测）。

### 题意

操作为围绕原点等比例缩放或逆时针旋转。每次查询一个连续操作区间作用于点后的坐标。操作和查询各至多$10^5$，缩放系数为正且任意区间乘积有界。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16055)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309B)。

### 题解

等比例缩放与旋转可交换，两次旋转角度相加，两次缩放系数相乘。预处理缩放前缀积 P 和角度前缀和 S；区间缩放为 P[j]/P[i-1]，区间旋转为 S[j]-S[i-1]。题目限定旋转角最多三位小数，所以把角度乘以 1000 后作为整数累计，区间相减不再有浮点前缀误差。

查询时将整数角度差除以 1000，再按 $2\pi$ 取模。最后只应用一次公式：`(x*cosθ-y*sinθ, x*sinθ+y*cosθ)`，再乘缩放。复合规律保证该结果与逐次操作一致，前缀相除／相减准确提取指定区间。时间 $O(n+m)$，空间 $O(n)$；题目按绝对误差判定，输出足够小数。旧版浮点角度前缀在曙梦 OJ 得到 80 分；本次修正尚待复交。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long double> scale(n + 1, 1);
    vector<long long> angleMillis(n + 1);
    const long double turn = 2 * acosl(-1.0L);
    for (int i = 1; i <= n; i++) {
        int type;
        string value;
        cin >> type >> value;
        scale[i] = scale[i - 1];
        angleMillis[i] = angleMillis[i - 1];
        if (type == 1)
            scale[i] *= stold(value);
        else
            angleMillis[i] += llround(stold(value) * 1000);
    }
    cout << fixed << setprecision(10);
    while (m--) {
        int i, j;
        long double x, y;
        cin >> i >> j >> x >> y;
        long double s = scale[j] / scale[i - 1];
        long double a = fmodl((angleMillis[j] - angleMillis[i - 1]) / 1000.0L, turn);
        cout << s * (x * cosl(a) - y * sinl(a)) << ' ' << s * (x * sinl(a) + y * cosl(a)) << '\n';
    }
}
```

<a id="problem-c"></a>

## C. 梯度求解

标签：`自动微分` · `表达式` · `栈`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定由整数、变量 x1…xn 和加减乘构成的后缀表达式。每次给出所有变量的值及一个变量编号，求表达式对该变量的偏导数模 $10^9+7$。表达式至多 120 个操作数／运算符，n、查询数均不超过 100。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16056)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309C)。

### 题解

求导和求值可以一起做。栈中每项保存 `(当前值,当前导数)`：常数导数为 0，当前求导变量的导数为 1，其余变量导数为 0。遇到运算符弹出右、左操作数，分别按加法、减法和乘积求导公式合并。乘法产生 `(uv,u'v+uv')`，不能只把两个导数相乘。

后缀表达式的每个运算符前，其两个完整子表达式已经入栈。对表达式树归纳，二元组的两部分分别等于子表达式值和偏导数，因此最终栈顶就是答案。每一步取模；负常数、减法结果都规范到非负余数。每次查询时间 $O(L+n)$、空间 $O(L+n)$，L 为表达式长度。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll norm(ll x) {
    return (x % MOD + MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string line, t;
    getline(cin, line);
    getline(cin, line);
    istringstream in(line);
    vector<string> tokens;
    while (in >> t)
        tokens.push_back(t);
    while (m--) {
        int var;
        cin >> var;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = norm(a[i]);
        }
        vector<pair<ll, ll>> st;
        for (auto &s : tokens) {
            if (s == "+" || s == "-" || s == "*") {
                auto [v, d] = st.back();
                st.pop_back();
                auto [u, c] = st.back();
                st.pop_back();
                if (s == "+")
                    st.push_back({(u + v) % MOD, (c + d) % MOD});
                else if (s == "-")
                    st.push_back({norm(u - v), norm(c - d)});
                else
                    st.push_back({u * v % MOD, (c * v + u * d) % MOD});
            } else if (s[0] == 'x') {
                int id = stoi(s.substr(1));
                st.push_back({a[id], id == var});
            } else
                st.push_back({norm(stoll(s)), 0});
        }
        cout << st.back().second << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 阴阳龙

标签：`有序集合` · `几何` · `模拟`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 15 分 Time Exceeded（复刻评测）。

### 题意

在 $n\times m$ 网格中有 $p$ 名位置互异的员工。事件 $(u,v,t)$ 从中心向右、右上、上、左上、左、左下、下、右下观察，找到这八条射线上最近员工的距离 $k$，不考虑中心员工；但 $k$ 还必须满足八个方向走 $k$ 步均未越界，否则本次不动。把恰在这八个距离为 $k$ 的位置上的员工同时逆时针轮转 $t$ 个方向。处理 $q$ 次事件后输出 $\bigoplus_{i=1}^p(i x_i+y_i)$。$n,m\le10^9,p,q\le10^5$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16057)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309D)。

### 题解

八条射线其实来自四条直线：水平、竖直、斜率 1、斜率 -1。分别建立四个有序集合，键写作 $(y,x)$、$(x,y)$、$(x-y,x)$、$(x+y,x)$。第一维区分直线，第二维给出线上顺序。

每次事件在四个集合中各找严格前驱和严格后继；检查第一维相同，便得到八个方向的最近员工。用严格比较排除与中心重合的员工。最近距离还需不大于 $\min(u-1,n-u,v-1,m-v)$，因为题目要求八个位置都在边界内，不能只检查有员工的那个方向。

得到 $k$ 后，查八个候选坐标上的员工编号。先从四个集合中删除全部需要移动的员工，再计算新方向并全部插入。若边删边插，新位置可能覆盖另一名尚未移动的员工，因此必须分成两步。另用坐标到编号的哈希表定位员工。

有序集合的邻点就是各射线最近点，取最小值得到题目定义的 $k$；四集合始终同步保存所有员工，轮转又同时应用，所以按事件归纳可知最终位置正确。时间 $O((p+q)\log p)$，空间 $O(p)$；异或前的 $ix_i+y_i$ 用 64 位。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using i64 = long long;
using Point = pair<i64, i64>;
uint64_t code(i64 x, i64 y) {
    return (uint64_t(x) << 32) | uint64_t(y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, m;
    int p, q;
    cin >> n >> m >> p >> q;
    vector<Point> position(p + 1);
    array<set<Point>, 4> lines;
    unordered_map<uint64_t, int> who;
    who.reserve(p * 2);
    auto keys = [](i64 x, i64 y) {
        return array<Point, 4>{Point{y, x}, Point{x, y}, Point{x - y, x}, Point{x + y, x}};
    };
    auto insert = [&](int id) {
        auto [x, y] = position[id];
        auto k = keys(x, y);
        for (int j = 0; j < 4; ++j)
            lines[j].insert(k[j]);
        who[code(x, y)] = id;
    };
    auto erase = [&](int id) {
        auto [x, y] = position[id];
        auto k = keys(x, y);
        for (int j = 0; j < 4; ++j)
            lines[j].erase(k[j]);
        who.erase(code(x, y));
    };
    for (int i = 1; i <= p; ++i) {
        cin >> position[i].first >> position[i].second;
        insert(i);
    }
    const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    while (q--) {
        i64 u, v;
        int t;
        cin >> u >> v >> t;
        i64 boundary = min({u - 1, n - u, v - 1, m - v}), distance = boundary + 1;
        auto k = keys(u, v);
        for (int j = 0; j < 4; ++j) {
            auto [line, coordinate] = k[j];
            auto after = lines[j].upper_bound(k[j]);
            if (after != lines[j].end() && after->first == line)
                distance = min(distance, after->second - coordinate);
            auto before = lines[j].lower_bound(k[j]);
            if (before != lines[j].begin()) {
                --before;
                if (before->first == line)
                    distance = min(distance, coordinate - before->second);
            }
        }
        if (distance > boundary)
            continue;
        vector<pair<int, int>> moved;
        for (int d = 0; d < 8; ++d) {
            auto it = who.find(code(u + distance * dx[d], v + distance * dy[d]));
            if (it != who.end())
                moved.push_back({it->second, (d + t) % 8});
        }
        for (auto [id, d] : moved)
            erase(id);
        for (auto [id, d] : moved) {
            position[id] = {u + distance * dx[d], v + distance * dy[d]};
            insert(id);
        }
    }
    i64 answer = 0;
    for (int i = 1; i <= p; ++i)
        answer ^= i * position[i].first + position[i].second;
    cout << answer << '\n';
}
```

<a id="problem-e"></a>

## E. 阻击

标签：`动态树` · `树的直径` · `动态规划`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

一棵树的每条边有宝物收益 $w_e$ 和阻击损失 $b_e$。选择两个城市，允许相同，敌军沿它们之间的简单路径行动，总损失为 $\sum(b_e-w_e)$。先输出初始最大总损失，再处理 $m$ 次把指定边的 $w_e$ 改成新值的操作，每次输出新的最优值。输入 `n m`，随后 $n-1$ 行 `u v w b`、$m$ 行 `边编号 新w`。$n,m\le10^5$，单项权值不超过 $10^9$。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16058)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309E)。

### 题解

**先认出真正维护的量。** 令边权 $c_e=b_e-w_e$，题目变成允许负边的动态树直径。负边破坏了“两次找最远点”的常用结论，不能直接套正权直径算法。

把每条边拆成一个权值为 $c_e$ 的新点，原城市的点权为 0，边修改变成点修改。拆边点的度为 2；一条路径即使在拆边点结束，也能延伸到相邻的零权城市而不降低值，所以最大点权路径与原问题等价。

**维护一条实链和挂在它上面的虚子树。** 使用 Link-Cut Tree。每个链段记录四个量：`sum` 为实链点权和；`first` 为从左端出发、可进入一棵虚子树的最大路径；`last` 对称；`best` 为整个链段及其虚子树内的最大路径。合并相邻段 $A,B$：

$$sum=sum_A+sum_B,$$
$$first=\max(first_A,sum_A+first_B),\quad last=\max(last_B,sum_B+last_A),$$
$$best=\max(best_A,best_B,last_A+first_B).$$

对于单个实链点 $u$，用两个多重集合保存各虚孩子的 `first` 与 `best`。设最大的两个非负虚分支贡献为 $a,b$，则局部状态是 $(w_u,w_u+a,w_u+a,\max(\text{虚子树best},w_u+a+b))$。注意 `sum` 只包含链上点权，不能把旁支算进去。

`access` 改变实虚边时，把旧实右子树加入集合，把新实右子树从集合删除；集合必须按一次出现删除，不能把同值贡献全部删掉。修改前先 `access`，才能确保祖先保存的虚信息仍与旧值一致。最后把城市 1 作为根，查询整树 `best`，再与 0 取最大值，涵盖起终点相同的选择。

**正确性。** 最优路径要么完全位于一个孩子结构内，要么经过当前连接点，至多使用两个分支；上述分类正好被局部状态和链合并式覆盖。**复杂度：** 多重集合让一次修改摊还 $O(\log^2 n)$，空间 $O(n)$。这份实现比只支持正权的直径模板通用，但需要先理解 Splay、实虚边与路径 DP。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
const ll NEG = -(1LL << 60);
struct Summary {
    ll sum = 0, first = NEG, last = NEG, best = NEG;
};
Summary join(Summary a, Summary b) {
    return {a.sum + b.sum, max(a.first, a.sum + b.first), max(b.last, b.sum + a.last),
            max({a.best, b.best, a.last + b.first})};
}
struct DynamicTree {
    struct Node {
        int child[2]{}, parent = 0;
        bool reverse = false;
        ll weight = 0;
        multiset<ll> sideFirst, sideBest;
        Summary data;
    };
    vector<Node> t;
    vector<int> path;
    explicit DynamicTree(int n) : t(n + 1) {
        path.reserve(n);
    }
    bool auxiliaryRoot(int u) {
        int p = t[u].parent;
        return t[p].child[0] != u && t[p].child[1] != u;
    }
    Summary local(int u) {
        ll first = 0, second = 0;
        auto it = t[u].sideFirst.rbegin();
        if (it != t[u].sideFirst.rend()) {
            first = max(0LL, *it);
            ++it;
        }
        if (it != t[u].sideFirst.rend())
            second = max(0LL, *it);
        ll w = t[u].weight, b = t[u].sideBest.empty() ? NEG : *t[u].sideBest.rbegin();
        return {w, w + first, w + first, max(b, w + first + second)};
    }
    void pull(int u) {
        t[u].data = join(join(t[t[u].child[0]].data, local(u)), t[t[u].child[1]].data);
    }
    void flip(int u) {
        if (!u)
            return;
        swap(t[u].child[0], t[u].child[1]);
        swap(t[u].data.first, t[u].data.last);
        t[u].reverse ^= 1;
    }
    void push(int u) {
        if (t[u].reverse) {
            flip(t[u].child[0]);
            flip(t[u].child[1]);
            t[u].reverse = false;
        }
    }
    void rotate(int u) {
        int p = t[u].parent, g = t[p].parent, d = t[p].child[1] == u, v = t[u].child[d ^ 1];
        if (!auxiliaryRoot(p))
            t[g].child[t[g].child[1] == p] = u;
        t[u].parent = g;
        t[u].child[d ^ 1] = p;
        t[p].parent = u;
        t[p].child[d] = v;
        if (v)
            t[v].parent = p;
        pull(p);
        pull(u);
    }
    void splay(int u) {
        path.clear();
        int v = u;
        path.push_back(v);
        while (!auxiliaryRoot(v)) {
            v = t[v].parent;
            path.push_back(v);
        }
        for (auto it = path.rbegin(); it != path.rend(); ++it)
            push(*it);
        while (!auxiliaryRoot(u)) {
            int p = t[u].parent, g = t[p].parent;
            if (!auxiliaryRoot(p))
                rotate((t[p].child[1] == u) == (t[g].child[1] == p) ? p : u);
            rotate(u);
        }
    }
    void virtualAdd(int u, int v) {
        if (!v)
            return;
        t[u].sideFirst.insert(t[v].data.first);
        t[u].sideBest.insert(t[v].data.best);
    }
    void virtualRemove(int u, int v) {
        if (!v)
            return;
        t[u].sideFirst.erase(t[u].sideFirst.find(t[v].data.first));
        auto it = t[u].sideBest.find(t[v].data.best);
        t[u].sideBest.erase(it);
    }
    void access(int u) {
        for (int v = 0, x = u; x; v = x, x = t[x].parent) {
            splay(x);
            virtualAdd(x, t[x].child[1]);
            virtualRemove(x, v);
            t[x].child[1] = v;
            pull(x);
        }
        splay(u);
    }
    void makeRoot(int u) {
        access(u);
        flip(u);
    }
    void link(int u, int v) {
        makeRoot(u);
        access(v);
        t[u].parent = v;
        virtualAdd(v, u);
        pull(v);
    }
    void cut(int u, int v) {
        makeRoot(u);
        access(v);
        t[v].child[0] = 0;
        t[u].parent = 0;
        pull(v);
    }
    void setWeight(int u, ll w) {
        access(u);
        t[u].weight = w;
        pull(u);
    }
    ll rootedValue(int root) {
        makeRoot(root);
        access(root);
        return local(root).first;
    }
    ll subtreeBest(int root, int u) {
        makeRoot(root);
        access(u);
        return local(u).best;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DynamicTree dt(2 * n);
    vector<long long> loss(n);
    for (int i = 1; i <= n; ++i)
        dt.pull(i);
    for (int i = 1; i < n; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w >> loss[i];
        int node = n + i;
        dt.t[node].weight = loss[i] - w;
        dt.pull(node);
        dt.link(u, node);
        dt.link(node, v);
    }
    cout << max(0LL, dt.subtreeBest(1, 1)) << '\n';
    while (m--) {
        int edge;
        long long value;
        cin >> edge >> value;
        dt.setWeight(n + edge, loss[edge] - value);
        cout << max(0LL, dt.subtreeBest(1, 1)) << '\n';
    }
}
```
