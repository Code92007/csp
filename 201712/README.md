---
title: "CSP 201712 五题题解"
contest: "201712"
contest_month: "2017-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "排序", "相邻元素", "队列", "循环模拟", "日期计算", "字符串解析", "枚举", "最短路", "Floyd", "分层图", "Dijkstra", "树形DP", "李超线段树", "启发式合并", "斜率优化"]
status: "published"
problems: [{"id": "A", "title": "最小差值", "tags": ["排序", "相邻元素"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://www.cnblogs.com/wydxry/p/10730131.html"}], "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "B", "title": "游戏", "tags": ["队列", "循环模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；270 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201712B"}, {"label": "公开题面存档", "url": "https://blog.51cto.com/u_15346485/3677111"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda75c74ace1cba9a1fccc"}}, {"id": "C", "title": "Crontab", "tags": ["日期计算", "字符串解析", "枚举", "排序"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://www.cnblogs.com/imane/p/15095778.html"}], "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "D", "title": "行车路线", "tags": ["最短路", "Floyd", "分层图", "Dijkstra"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://www.dreamwings.cn/ccf201712-4/5213.html"}], "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "E", "title": "商路", "tags": ["树形DP", "李超线段树", "启发式合并", "斜率优化"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "题面转录与转移式核对", "url": "https://bigrandall.io/u/randall/blog/20-chun-xiao-xue-qi-cheng-xu-she-ji-shi-yan-bao-gao#2-ccf-201712-5-商路"}], "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}]
---

# CSP 201712 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 最小差值

标签：`排序` · `相邻元素`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

给n个正整数，求任意两个元素差的绝对值的最小值，允许存在重复数。n≤1000。

来源：[公开题面存档](https://www.cnblogs.com/wydxry/p/10730131.html)。

### 题解

先排序，再扫描相邻元素差取最小。若两数排序后不相邻，它们之间至少有一个数；整段差是相邻差之和，必不小于其中某个相邻差，所以最小差一定可在相邻位置找到。

重复数排序后相邻并产生0，直接参与最小值即可，不能先去重。时间 $O(n\log n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    long long answer = numeric_limits<long long>::max();
    for (int i = 1; i < n; i++)
        answer = min(answer, a[i] - a[i - 1]);
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 游戏

标签：`队列` · `循环模拟`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；270 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adda75c74ace1cba9a1fccc)（复刻评测）。

### 题意

n个小朋友围成一圈，从1号开始连续报1、2、3…，报数为k的倍数或个位为k者退出，求最后剩余编号。n≤1000，1≤k≤9。

来源：[公开题面存档](https://blog.51cto.com/u_15346485/3677111)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201712B)。

### 题解

队列按当前报数顺序保存存活者。每次弹出队首，用全局报数检查淘汰规则；未淘汰则放回队尾，淘汰则不再入队。报数每次加一，不因淘汰或转一圈而重置。

队列始终恰好是从下一个报数者开始的存活顺序，因而模拟与环形游戏等价。至少每k次报数淘汰一人，总报数次数不超过k(n-1)，时间 $O(nk)$，空间 $O(n)$；n=1直接输出1。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    int count = 1;
    while (q.size() > 1) {
        int child = q.front();
        q.pop();
        if (count % k != 0 && count % 10 != k)
            q.push(child);
        ++count;
    }
    cout << q.front() << '\n';
}
```

<a id="problem-c"></a>

## C. Crontab

标签：`日期计算` · `字符串解析` · `枚举` · `排序`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。

### 题意

给定至多 20 条 Crontab 规则，五个字段分别限制分钟、小时、月内日期、月份、星期。支持 *、逗号并集、闭区间和不区分大小写的英文月／星期缩写。输出 [s,t) 内所有满足全部五个字段的任务，按时间升序，同刻按输入顺序。日期在 1970—2099 年，保证输出不超过一万行。

来源：[公开题面存档](https://www.cnblogs.com/imane/p/15095778.html)。

### 题解

先把每个字段解析成允许值的布尔表：逗号分片、连字符展开区间，英文缩写先转小写再映射。重叠区间只置同一个布尔位，不能重复执行。

从已知的 1970-01-01 星期四开始按天推进，正确处理闰年。每一天先判断日期区间，再对每条规则检查月份、月内日期、星期三个条件；全部通过后只枚举该规则允许的小时、分钟。过滤 [s,t) 边界后，把当天事件按 `(时间,规则编号)` 排序输出。

每天只生成满足五项条件的事件，枚举又覆盖每种可能时间；排序保证同刻顺序。设扫描天数 D、生成事件数 K，时间 $O(Dn+K\log K)$（首尾边界日额外至多 $2880n$ 次候选），空间为规则与单日事件。无需调用系统时间 API，不受时区和夏令时影响。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using Field = array<bool, 60>;
int value(string s, int kind) {
    for (char &c : s)
        c = tolower(static_cast<unsigned char>(c));
    if (isdigit(s[0]))
        return stoi(s);
    string names = kind == 3 ? "janfebmaraprmayjunjulaugsepoctnovdec" : "sunmontuewedthufrisat";
    return int(names.find(s) / 3) + (kind == 3);
}
Field parse(string s, int kind) {
    const int lo[] = {0, 0, 1, 1, 0}, hi[] = {59, 23, 31, 12, 6};
    Field a{};
    if (s == "*") {
        for (int i = lo[kind]; i <= hi[kind]; i++)
            a[i] = true;
        return a;
    }
    istringstream in(s);
    string part;
    while (getline(in, part, ',')) {
        size_t p = part.find('-');
        int l = value(part.substr(0, p), kind),
            r = p == string::npos ? l : value(part.substr(p + 1), kind);
        for (int i = l; i <= r; i++)
            a[i] = true;
    }
    return a;
}
struct Rule {
    array<Field, 5> fields;
    vector<int> minutes, hours;
    string command;
};
bool leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long start, finish;
    cin >> n >> start >> finish;
    vector<Rule> rules(n);
    for (auto &r : rules) {
        for (int j = 0; j < 5; j++) {
            string s;
            cin >> s;
            r.fields[j] = parse(s, j);
        }
        cin >> r.command;
        for (int i = 0; i < 60; i++)
            if (r.fields[0][i])
                r.minutes.push_back(i);
        for (int i = 0; i < 24; i++)
            if (r.fields[1][i])
                r.hours.push_back(i);
    }
    int weekday = 4;
    int lengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int y = 1970; y <= finish / 100000000; y++)
        for (int mo = 1; mo <= 12; mo++)
            for (int d = 1; d <= lengths[mo] + (mo == 2 && leap(y));
                 d++, weekday = (weekday + 1) % 7) {
                long long date = (y * 10000 + mo * 100 + d) * 10000LL;
                if (date + 2359 < start || date >= finish)
                    continue;
                vector<pair<long long, int>> events;
                for (int i = 0; i < n; i++) {
                    auto &r = rules[i];
                    if (!r.fields[2][d] || !r.fields[3][mo] || !r.fields[4][weekday])
                        continue;
                    for (int h : r.hours)
                        for (int m : r.minutes) {
                            long long t = date + h * 100 + m;
                            if (start <= t && t < finish)
                                events.push_back({t, i});
                        }
                }
                sort(events.begin(), events.end());
                for (auto [t, i] : events)
                    cout << t << ' ' << rules[i].command << '\n';
            }
}
```

<a id="problem-d"></a>

## D. 行车路线

标签：`最短路` · `Floyd` · `分层图` · `Dijkstra`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

道路分两类：大道（类型 0）每公里增加 1 点疲劳；连续走的一整段小道（类型 1），若总长为 s，疲劳为 $s^2$。走过大道后，下一段小道重新累计。输入 n,m 和每条双向道路 `类型 端点1 端点2 长度`，求从 1 到 n 的最小疲劳值。n 至多 500。

来源：[公开题面存档](https://www.dreamwings.cn/ccf201712-4/5213.html)。

### 题解

不能仅记录“到路口 u 的最小疲劳”和该最优路线的小道长度，因为稍贵但连续小道长度更短的到达方式，后续可能反而更优。

**先把一整段连续小道合成一条边。** 只用小道运行 Floyd，得到任意两点间最短小道长度 s；若存在这段路，其费用为 $s^2$。固定这一段的端点时，平方函数在非负数上单调，所以只需保留最短长度。

建立两类状态：0 表示刚走过大道或还没出发，1 表示刚走完一整段小道。从两种状态都可走一条大道，转入 0；只有状态 0 能走合成小道边，转入 1。禁止 1 直接接另一条合成小道，否则会把本应 $(a+b)^2$ 的连续费用错误拆成 $a^2+b^2$。在这张非负权分层图上运行 Dijkstra，终点两种状态取较小值。

任意真实路线按最大连续小道段分割，可转成不更贵的分层路径；每条合成边也有真实小道路线可展开，且两段之间必须经过大道。因此两者最优值相等。Floyd 时间 $O(n^3)$，随后朴素 Dijkstra $O(n^2)$，空间 $O(n^2)$。平方与总费用用 64 位整数。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;
constexpr i64 INF = 4000000000000000000LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<i64>> small(n, vector<i64>(n, INF)), large = small;
    for (int i = 0; i < n; ++i)
        small[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int type, u, v;
        i64 w;
        cin >> type >> u >> v >> w;
        --u;
        --v;
        auto &a = type ? small : large;
        a[u][v] = a[v][u] = min(a[u][v], w);
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            if (small[i][k] < INF)
                for (int j = 0; j < n; ++j)
                    if (small[k][j] < INF)
                        small[i][j] = min(small[i][j], small[i][k] + small[k][j]);
    vector<i64> distance(2 * n, INF);
    vector<bool> done(2 * n);
    distance[0] = 0;
    for (int step = 0; step < 2 * n; ++step) {
        int state = -1;
        for (int i = 0; i < 2 * n; ++i)
            if (!done[i] && (state == -1 || distance[i] < distance[state]))
                state = i;
        if (state == -1 || distance[state] == INF)
            break;
        done[state] = true;
        int u = state / 2, previous = state % 2;
        for (int v = 0; v < n; ++v) {
            if (large[u][v] < INF)
                distance[v * 2] = min(distance[v * 2], distance[state] + large[u][v]);
            if (previous == 0 && v != u && small[u][v] < INF)
                distance[v * 2 + 1] =
                    min(distance[v * 2 + 1], distance[state] + small[u][v] * small[u][v]);
        }
    }
    cout << min(distance[2 * n - 2], distance[2 * n - 1]) << '\n';
}
```

<a id="problem-e"></a>

## E. 商路

标签：`树形DP` · `李超线段树` · `启发式合并` · `斜率优化`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。

### 题意

每座城市除根外都有一个编号更小的父亲，连边长度为 $s_i$。城市 $u$ 的商路从它出发，每一步可以跳到任意后代 $v$，该段收益为 $v_u-(f_u-dist(u,v))^2$，再从 $v$ 继续向下；也可以立即停止、收益为 0。求每个城市最优收益之和模 $10^{18}$。输入测试组数，每组输入 $n$，随后各城市的 `父亲 s v f`，根的前两项为 0。本题题名是《商路》。

来源：[题面转录与转移式核对](https://bigrandall.io/u/randall/blog/20-chun-xiao-xue-qi-cheng-xu-she-ji-shi-yan-bao-gao#2-ccf-201712-5-商路)

### 题解

令 $dp[u]$ 为从 $u$ 出发的最优收益，$D_u$ 为根到 $u$ 的距离。直接转移为

$$dp[u]=\max\left(0,\max_{v\text{是真后代}}\{dp[v]+v_u-(f_u-D_v+D_u)^2\}\right).$$

设查询横坐标 $x=D_u+f_u$，展开平方得

$$dp[u]=\max(0,v_u-x^2+\max_v\{2D_vx+dp[v]-D_v^2\}).$$

每个后代 $v$ 提供直线 $y=2D_vx+dp[v]-D_v^2$。问题变成合并所有孩子的直线集合，再在 $x=D_u+f_u$ 处查询最大值。查询完成后才插入 $u$ 的直线，避免把自身错误地当作真后代。

**李超树加启发式合并。** 所有查询横坐标预先离散化；李超线段树在每个区间保存中点处更优的直线，剩下一条只可能在一侧胜出，递归插入那一侧。每个子树同时保存直线编号列表；合并时把小列表中的线逐条插入大列表对应的李超树。每条线所在集合的大小每次至少翻倍，所以最多被搬动 $O(\log n)$ 次。

父亲编号小于孩子，可以按编号从大到小处理，省去递归遍历。线段树节点采用下标引用，递归插入可能扩容 `vector`，因此不能跨递归保留其元素引用。平方和比较使用 128 位整数，最终累加再按 $10^{18}$ 取模。

**正确性。** DP 枚举了停止或选择下一个后代的全部方案，展开没有改变数值；子树合并恰好维护所有真后代的直线，李超树查询保持其逐点最大值。**复杂度：** $O(n\log^2 n)$ 时间，代码保留历次合并产生的李超节点，空间上界 $O(n\log n)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using Int = __int128_t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> parent(n + 1), root(n + 1);
        vector<ll> depth(n + 1), value(n + 1), ideal(n + 1), xs;
        vector<Int> dp(n + 1);
        vector<vector<int>> lines(n + 1);
        for (int i = 1; i <= n; ++i) {
            ll length;
            cin >> parent[i] >> length >> value[i] >> ideal[i];
            depth[i] = depth[parent[i]] + length;
            xs.push_back(depth[i] + ideal[i]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        struct Node {
            int line = 0, left = 0, right = 0;
        };
        vector<Node> tree(1);
        auto eval = [&](int i, ll x) {
            return Int(2) * depth[i] * x + dp[i] - Int(depth[i]) * depth[i];
        };
        function<int(int, int, int, int)> insert = [&](int u, int line, int lo, int hi) {
            if (!u) {
                tree.push_back({line, 0, 0});
                return int(tree.size()) - 1;
            }
            int mid = (lo + hi) / 2;
            if (eval(line, xs[mid]) > eval(tree[u].line, xs[mid]))
                swap(line, tree[u].line);
            if (lo == hi)
                return u;
            if (eval(line, xs[lo]) > eval(tree[u].line, xs[lo])) {
                int child = insert(tree[u].left, line, lo, mid);
                tree[u].left = child;
            } else if (eval(line, xs[hi]) > eval(tree[u].line, xs[hi])) {
                int child = insert(tree[u].right, line, mid + 1, hi);
                tree[u].right = child;
            }
            return u;
        };
        auto query = [&](int u, ll x) {
            int lo = 0, hi = xs.size() - 1;
            Int best = -(Int(1) << 120);
            while (u) {
                best = max(best, eval(tree[u].line, x));
                int mid = (lo + hi) / 2;
                if (x <= xs[mid]) {
                    hi = mid;
                    u = tree[u].left;
                } else {
                    lo = mid + 1;
                    u = tree[u].right;
                }
            }
            return best;
        };
        ll answer = 0;
        const ll MOD = 1000000000000000000LL;
        for (int u = n; u >= 1; --u) {
            ll x = depth[u] + ideal[u];
            if (root[u])
                dp[u] = max(Int(0), query(root[u], x) - Int(x) * x + value[u]);
            answer = (answer + ll(dp[u] % MOD)) % MOD;
            root[u] = insert(root[u], u, 0, xs.size() - 1);
            lines[u].push_back(u);
            int p = parent[u];
            if (!p)
                continue;
            if (lines[p].size() < lines[u].size()) {
                swap(lines[p], lines[u]);
                swap(root[p], root[u]);
            }
            for (int line : lines[u]) {
                root[p] = insert(root[p], line, 0, xs.size() - 1);
                lines[p].push_back(line);
            }
            vector<int>().swap(lines[u]);
        }
        cout << answer << '\n';
    }
}
```
