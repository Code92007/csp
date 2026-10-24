---
title: "CSP 202503 五题题解"
contest: "202503"
contest_month: "2025-03"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "枚举", "求和", "动态规划", "完全背包", "表达式解析", "记忆化搜索", "依赖图", "数论", "gcd", "状态压缩", "动态树", "Link-Cut Tree", "树形动态规划"]
status: "published"
problems: [{"id": "A", "title": "数值积分", "tags": ["枚举", "求和"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b9a67df0b81749b958"}}, {"id": "B", "title": "机器人饲养指南", "tags": ["动态规划", "完全背包"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7bba67df0b81749b972"}}, {"id": "C", "title": "模板展开", "tags": ["表达式解析", "记忆化搜索", "依赖图"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7bda67df0b81749b97b"}}, {"id": "D", "title": "集体锻炼", "tags": ["数论", "gcd", "状态压缩"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；130 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7bea67df0b81749b983"}}, {"id": "E", "title": "收费标准评估", "tags": ["动态树", "Link-Cut Tree", "树形动态规划"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c0a67df0b81749b987"}}]
---

# CSP 202503 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 数值积分

标签：`枚举` · `求和`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

在闭区间[l,r]中取所有偶数x，计算二次函数x²+bx+c的值之和再乘2。l、r≤1000，b、c可为负。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503A/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503A)。

### 题解

若l为奇数，先加一得到第一个偶数；之后每次加2，直到超过r，将2*(x*x+b*x+c)累加。

该枚举恰好包含闭区间内全部偶数且不重复，按题目公式逐项加和即可。注意端点r若为偶数也要计入，不能擅自改成真正的解析积分。时间 $O(r-l+1)$，额外空间 $O(1)$，使用64位整数。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    long long b, c, l, r, answer = 0;
    cin >> b >> c >> l >> r;
    if (l % 2)
        ++l;
    for (long long x = l; x <= r; x += 2)
        answer += 2 * (x * x + b * x + c);
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 机器人饲养指南

标签：`动态规划` · `完全背包`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

共有 n 个苹果，每天可喂 1 到 m 个，喂 i 个产生快乐 A[i]。天数不限，A 不保证单调。求把全部苹果喂完的最大总快乐，n≤10000、m≤100。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503B/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503B)。

### 题解

设 dp[x] 为恰好喂掉 x 个苹果的最大快乐，dp[0]=0。枚举最后一天喂 i 个，有 `dp[x]=max(dp[x-i]+A[i])`，其中 1≤i≤min(m,x)。按 x 从小到大计算。

任意方案删去最后一天都得到一个更小规模方案；若该前缀不是最优，可替换为更优前缀。因此转移覆盖所有方案并保持最优。不要按 A[i]/i 贪心，剩余苹果可能使比例最高的组合不合适。时间 $O(nm)$，空间 $O(n+m)$，使用 64 位收益。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(m + 1), dp(n + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int used = 1; used <= n; used++)
        for (int today = 1; today <= m && today <= used; today++)
            dp[used] = max(dp[used], dp[used - today] + a[today]);
    cout << dp[n] << '\n';
}
```

<a id="problem-c"></a>

## C. 模板展开

标签：`表达式解析` · `记忆化搜索` · `依赖图`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

变量初始为空串。语句 `1 var expr` 立即求表达式并保存结果，`2 var expr` 保存动态表达式、每次使用时重新按当前变量求值，`3 var` 输出当前值长度模 $10^9+7$。表达式由字面量及 `$变量名` 拼接，动态依赖保证无环。语句至多 2000，变量至多 1000，每个表达式至多 100 项。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503C/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503C)。

### 题解

只需输出长度，字符串拼接可改成长度相加并取模，避免构造指数增长的字符串。每个变量保存“固定长度”或“表达式操作数列表”；字面量操作数只记录长度，引用记录变量编号。

计算动态变量时递归计算依赖，再累加。用语句编号作为缓存时间戳：同一语句内变量值不变，可以记忆化；执行下一语句后缓存自动失效，使动态变量能反映新的赋值。直接赋值要先算完整右侧，再覆盖左侧，这样 `1 a $a $a` 使用的是 a 的旧值。

无环保证递归终止，按依赖顺序计算所得长度与真实拼接长度一致。直接赋值冻结计算结果，间接赋值保留引用，分别符合两种语义。设 V 为变量数，E 为当前表达式引用与字面量总数，单次求值 $O(V+E)$，总时间 $O(q(V+E))$，空间 $O(V+E)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
constexpr long long MOD = 1000000007;
struct Operand {
    bool variable;
    int value;
};
struct Variable {
    bool indirect = false;
    long long value = 0;
    vector<Operand> expression;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    unordered_map<string, int> ids;
    vector<Variable> vars(1001);
    vector<int> stamp(1001, -1);
    vector<long long> memo(1001);
    int epoch = 0;
    auto id = [&](const string &name) {
        auto it = ids.find(name);
        if (it != ids.end())
            return it->second;
        int index = ids.size();
        ids[name] = index;
        return index;
    };
    function<long long(int)> evaluate = [&](int u) {
        if (stamp[u] == epoch)
            return memo[u];
        long long value = vars[u].value;
        if (vars[u].indirect) {
            value = 0;
            for (auto operand : vars[u].expression)
                value =
                    (value + (operand.variable ? evaluate(operand.value) : operand.value)) % MOD;
        }
        stamp[u] = epoch;
        return memo[u] = value;
    };
    while (n--) {
        ++epoch;
        getline(cin, line);
        istringstream input(line);
        int op;
        string name;
        input >> op >> name;
        int target = id(name);
        if (op == 3) {
            cout << evaluate(target) << '\n';
            continue;
        }
        vector<Operand> expr;
        string token;
        while (input >> token) {
            if (token[0] == '$')
                expr.push_back({true, id(token.substr(1))});
            else
                expr.push_back({false, int(token.size())});
        }
        if (op == 1) {
            long long value = 0;
            for (auto operand : expr)
                value =
                    (value + (operand.variable ? evaluate(operand.value) : operand.value)) % MOD;
            vars[target].indirect = false;
            vars[target].value = value;
            vars[target].expression.clear();
        } else {
            vars[target].indirect = true;
            vars[target].expression = std::move(expr);
        }
    }
}
```

<a id="problem-d"></a>

## D. 集体锻炼

标签：`数论` · `gcd` · `状态压缩`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；130 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

输入长度为 $n$ 的正整数数组，求所有非空连续区间的 $l\times r\times\gcd(a_l,\ldots,a_r)$ 之和，结果模 $998244353$。下标从 1 开始，$n,a_i\le10^6$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503D/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503D)。

### 题解

**固定右端点，并把相同 gcd 的区间合并。** 处理到位置 $r$ 时，一组状态 $(g,s)$ 表示若干以 $r$ 结尾、gcd 都为 $g$ 的区间，$s$ 是它们的左端点下标之和。新加入 $a_r$ 时，先产生单点状态 $(a_r,r)$；旧状态 $(g,s)$ 延伸后变成 $(\gcd(g,a_r),s)$。相邻状态若 gcd 相同，就把 $s$ 相加。

从短区间向长区间观察，gcd 只能变为原数的约数。每次严格变小，至少减半，所以至多有 $1+\lfloor\log_2\max a_i\rfloor$ 组。旧状态中相邻分组变换后仍然有这个整除顺序，只合并相邻项就足够。

每一组对答案的贡献为 $rgs$。所有以 $r$ 结尾的区间，要么是单点区间，要么唯一地来自以 $r-1$ 结尾的区间；因此转移无重无漏。按右端点累加便得到全体区间的答案。

状态转移次数为 $O(n\log A)$、空间 $O(\log A)$，其中 $A=\max a_i$；计入欧几里得算法的单次复杂度，可给出 $O(n\log^2 A)$ 的保守时间上界。下标之和与乘积须使用 64 位，连续乘法之间取模。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
constexpr long long MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, long long>> groups, next;
    long long answer = 0;
    for (int r = 1; r <= n; ++r) {
        int x;
        cin >> x;
        next.clear();
        next.push_back({x, r});
        for (auto [g, sum] : groups) {
            int value = gcd(g, x);
            if (next.back().first == value)
                next.back().second = (next.back().second + sum) % MOD;
            else
                next.push_back({value, sum});
        }
        groups.swap(next);
        for (auto [g, sum] : groups)
            answer = (answer + sum * r % MOD * g) % MOD;
    }
    cout << answer << '\n';
}
```

<a id="problem-e"></a>

## E. 收费标准评估

标签：`动态树` · `Link-Cut Tree` · `树形动态规划`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

带正负点权的树，初始根为 1。基本费用是包含当前根的非空连通子图的最大权和。操作 `1 u` 查询当前根意义下 $u$ 子树中的任意非空连通子图最大权和；`2 u x` 改点权；`3 u` 换根；`4 a b c d` 删边 $a-b$、加边 $c-d$，保证仍为树。先输出一次基本费用，之后每次输出该操作的答案；操作 1 输出子树答案，其他操作输出基本费用。$n,m\le10^5$，权值绝对值不超过 $10^9$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503E/)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503E)。

### 题解

**静态 DP 是所有结构的依据。** 令 $F_u$ 为子树内必须包含 $u$ 的最优权和，$G_u$ 为子树内任意非空连通子图的最优权和：$F_u=a_u+\sum_v\max(0,F_v)$，$G_u=\max(F_u,\max_vG_v)$。负贡献的孩子可以不接入，但所选子图至少包含一个点，不能把全部答案初始化为零。

**把一条实链压成可合并信息。** Link-Cut Tree 把孩子分为实孩子和虚孩子。设虚孩子对 $F$ 的正贡献之和为 $s$，虚孩子的最大 $G$ 为 $b$。当前点作为链上的一个位置，其有效权值为 $a_u+s$，但链内最优还可能完全落在某个虚子树中，因此至少为 $b$。每段实链维护四项：整段权和 `sum`、必须接触左端的最优 `first`、必须接触右端的最优 `last`、内部任意最优 `best`。

合并相邻链段 $A,B$：`sum=A.sum+B.sum`；`first=max(A.first,A.sum+B.first)`；`last` 对称；`best=max(A.best,B.best,A.last+B.first)`。最后一项对应连通子图跨过两段交界。这个公式也解释了为什么只维护链上最大值不够。

**实虚切换不可漏更新。** `access` 把旧实孩子改为虚孩子，加入其 `max(0,first)` 和 `best`；把新实孩子从虚集合中删除。正贡献用总和维护，最大值用可删除的 multiset 维护。链翻转时交换 `first,last`。修改前先 `access`，保证旧贡献已正确移出祖先的虚集合。

换根到当前根后再 `access(u)`，$u$ 的左实链是祖先；$u$ 自身和虚子树恰好是题目要求的子树，因此查询 `local(u).best`。基本费用对根查询 `local(root).first`。断边和连边分别用标准 LCT 操作，并同步虚贡献。

**复杂度。** 每次均摊 $O(\log^2 n)$，空间 $O(n)$；权和使用 `long long`。正确性由静态 DP、链段合并和实虚贡献守恒三条不变式共同保证。

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
        ll weight = 0, sideSum = 0;
        multiset<ll> sideBest;
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
        ll x = t[u].weight + t[u].sideSum;
        ll y = t[u].sideBest.empty() ? NEG : *t[u].sideBest.rbegin();
        return {x, x, x, max(x, y)};
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
        t[u].sideSum += max(0LL, t[v].data.first);
        t[u].sideBest.insert(t[v].data.best);
    }
    void virtualRemove(int u, int v) {
        if (!v)
            return;
        t[u].sideSum -= max(0LL, t[v].data.first);
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
    DynamicTree dt(n);
    for (int i = 1; i <= n; ++i) {
        cin >> dt.t[i].weight;
        dt.pull(i);
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        dt.link(u, v);
    }
    int root = 1;
    cout << dt.rootedValue(root) << '\n';
    while (m--) {
        int op, u;
        cin >> op >> u;
        if (op == 1) {
            cout << dt.subtreeBest(root, u) << '\n';
            continue;
        }
        if (op == 2) {
            ll x;
            cin >> x;
            dt.setWeight(u, x);
        }
        if (op == 3)
            root = u;
        if (op == 4) {
            int v, c, d;
            cin >> v >> c >> d;
            dt.cut(u, v);
            dt.link(c, d);
        }
        cout << dt.rootedValue(root) << '\n';
    }
}
```
