---
title: "CSP 201503 五题题解"
contest: "201503"
contest_month: "2015-03"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "矩阵旋转", "坐标映射", "频率统计", "自定义排序", "日期计算", "枚举", "树的直径", "BFS", "点分治", "倍增", "贪心", "树上查询"]
status: "published"
problems: [{"id": "A", "title": "图像旋转", "tags": ["矩阵旋转", "坐标映射"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb6f774ace1cba9a20ceb"}}, {"id": "B", "title": "数字排序", "tags": ["频率统计", "自定义排序"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb77c74ace1cba9a20d2d"}}, {"id": "C", "title": "节日", "tags": ["日期计算", "枚举"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb88c74ace1cba9a20dc5"}}, {"id": "D", "title": "网络延时", "tags": ["树的直径", "BFS"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb91774ace1cba9a20e42"}}, {"id": "E", "title": "最小花费", "tags": ["点分治", "倍增", "贪心", "树上查询"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503E/"}]}]
---

# CSP 201503 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 图像旋转

标签：`矩阵旋转` · `坐标映射`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb6f774ace1cba9a20ceb)（复刻评测）。

### 题意

把n×m矩阵逆时针旋转90度，输出m×n结果。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503A)。

### 题解

原矩阵第j列从上到下，变成结果第m-1-j行从左到右。因此按原列从右到左、列内原行从上到下输出。

坐标映射为(i,j)→(m-1-j,i)，它对全部格子一一对应且表示逆时针旋转。用非方阵样例核对方向最直观。时间 $O(nm)$，空间 $O(nm)$。

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
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (i)
                cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 数字排序

标签：`频率统计` · `自定义排序`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb77c74ace1cba9a20d2d)（复刻评测）。

### 题意

统计n个整数的出现次数，按次数递减输出，次数相同时按数值递增。每种数只输出一次。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503B)。

### 题解

用map统计频次，再构造二元组 `(-次数,数值)` 放入数组，按默认字典序排序。第一关键字的负号把降序变成升序，第二关键字自然使同频率的小数先输出。

计数字典把相同整数归为一项，排序键精确对应题目两级顺序。设不同数个数为u，时间 $O(n\log u+u\log u)$，空间 $O(u)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<int, int> count;
    while (n--) {
        int x;
        cin >> x;
        ++count[x];
    }
    vector<pair<int, int>> order;
    for (auto [x, c] : count)
        order.push_back({-c, x});
    sort(order.begin(), order.end());
    for (auto [c, x] : order)
        cout << x << ' ' << -c << '\n';
}
```

<a id="problem-c"></a>

## C. 节日

标签：`日期计算` · `枚举`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb88c74ace1cba9a20dc5)（复刻评测）。

### 题意

求 y1 到 y2 各年 a 月第 b 个星期 c 的日期，不存在则输出 none。星期一至日用 1—7，年份范围 1850—2050；已知 1850-01-01 是星期二。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503C)。

### 题解

维护每年元旦星期，用前一年天数推进；再加上目标月之前各月天数，得到该月 1 日星期 f。第一个目标星期的日号为 `1+(c-f+7)%7`（统一把星期日映射为 0），第 b 个再加 `7*(b-1)`。

同一星期每隔七天重复，因此该公式列出的正是从小到大的目标星期日号；超过本月天数则不存在。闰年条件为“被 400 整除，或被 4 整除但不被 100 整除”，1900 和 2000 必须区别处理。扫描 Y 年时间 $O(12Y)$，额外空间 $O(1)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iomanip>
#include <iostream>
using namespace std;
bool leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
int main() {
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int first = 2;
    for (int y = 1850; y <= y2; y++) {
        if (y >= y1) {
            int weekday = first;
            for (int m = 1; m < a; m++)
                weekday = (weekday + month[m] + (m == 2 && leap(y))) % 7;
            int day = 1 + (c % 7 - weekday + 7) % 7 + 7 * (b - 1);
            if (day > month[a] + (a == 2 && leap(y)))
                cout << "none\n";
            else
                cout << y << '/' << setfill('0') << setw(2) << a << '/' << setw(2) << day << '\n';
        }
        first = (first + 365 + leap(y)) % 7;
    }
}
```

<a id="problem-d"></a>

## D. 网络延时

标签：`树的直径` · `BFS`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb91774ace1cba9a20e42)（复刻评测）。

### 题意

有 n 台交换机和 m 台终端电脑。交换机 2 到 n 各连到一个编号更小的父交换机，每台电脑再连到一台交换机，整个网络是一棵树。求任意两台设备之间最多要经过多少条连接。$n,m\le10^4$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503D)。

### 题解

把交换机和电脑都当作普通树节点，问题就是树的直径。先从任意节点 BFS，找到最远点 u；再从 u BFS，所得到的最大距离即直径长度。

树上两点间路径唯一。任意起点的最远点总能作为某条直径的端点：若它还位于一条更长路径内部，就能沿更远一端继续增加距离，与“最远”矛盾。以这个端点再求最远点，就得到最长路径。

输入中前 n-1 个父编号对应交换机，接下来的 m 个父编号对应电脑，可把电脑依次编号为 n+1 到 n+m 后统一建双向边。两次 BFS 都是 $O(n+m)$，空间同阶。这个性质依赖网络是树，不能直接推广到任意无向图。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + m);
    for (int u = 1; u < n + m; ++u) {
        int p;
        cin >> p;
        --p;
        graph[u].push_back(p);
        graph[p].push_back(u);
    }
    auto farthest = [&](int start) {
        vector<int> distance(n + m, -1), queue{start};
        distance[start] = 0;
        for (size_t i = 0; i < queue.size(); ++i)
            for (int v : graph[queue[i]])
                if (distance[v] < 0) {
                    distance[v] = distance[queue[i]] + 1;
                    queue.push_back(v);
                }
        int u = max_element(distance.begin(), distance.end()) - distance.begin();
        return pair<int, int>{u, distance[u]};
    };
    auto [endpoint, unused] = farthest(0);
    cout << farthest(endpoint).second << '\n';
}
```

<a id="problem-e"></a>

## E. 最小花费

标签：`点分治` · `倍增` · `贪心` · `树上查询`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。

### 题意

树上城市的食物价格不同，沿边每走一单位长度消耗一单位食物。可以在经过的城市提前购买任意数量的食物，但不能绕路。对每个有向起终点对 $(s,t)$，求沿唯一简单路径旅行的最低费用。输入 `n m`、价格、带长度的树边以及查询；$n,m\le10^5$。方向不能忽略，同一路径反向旅行的费用通常不同。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503E)。

### 题解

**单条路径的贪心。** 每一段路所消耗的食物，都应该以“此前经过城市中的最低价格”购买。遇到更低价城市之前，可以提前囤粮；更高价城市无需买。于是答案是边长乘此前最低价的总和。

**点分治把查询分成向中心走、从中心走两段。** 对当前重心 $c$，把分量临时根设为 $c$。记录距离 $D_u$、根路径最低价 $min_u$，以及从 $c$ 出发的费用 `down[u]`。后者满足 `down[child]=down[parent]+边长*min[parent]`。

再算从每个 $u$ 到 $c$ 的费用 `upCost[u]`。设 $v$ 为最近的价格严格低于 $price[u]$ 的祖先，则

$$upCost[u]=price[u](D_u-D_v)+upCost[v].$$

用倍增祖先和祖先段最低价跳过所有不更便宜的城市；若没有更低价祖先，就用当前价走到中心。按父亲先于孩子的顺序处理，式中 `upCost[v]` 已知。

对于经过中心的查询 $(s,t)$，到中心的费用是 `upCost[s]`，手上可继续使用的最低购买价是 $p=min_s$。若 $c\to t$ 路径没有更低价，后半程为 $pD_t$。否则用倍增找到从中心出发第一个使根路径最低价小于 $p$ 的点 $v$，后半程为

$$pD_v+down[t]-down[v].$$

到达 $v$ 的最后一条边仍使用旧价格，故公式使用 $D_v$，不能提前在其父亲处切换。起终点在重心同一分支的查询，交给该分支递归；其余在本层回答。

**正确性。** 贪心独立最小化每一段路的购买价；分治只把唯一真实路径拆成两段，中心前取得的最低价作为后半段初始条件，因而拼接没有损失。每个查询在第一次跨分支的层次恰好回答一次。**复杂度：** $O((n+m)\log^2 n)$ 时间，$O(n\log n+m)$ 空间，费用用 64 位。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int LOG = 18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> price(n + 1);
    price[0] = 2000000000;
    for (int i = 1; i <= n; ++i)
        cin >> price[i];
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<pair<int, int>> queries(m);
    for (auto &q : queries)
        cin >> q.first >> q.second;
    vector<ll> answer(m), distance(n + 1), upCost(n + 1), downCost(n + 1);
    vector<int> parent(n + 1), size(n + 1), branch(n + 1), prefixMin(n + 1);
    vector<bool> removed(n + 1);
    vector<array<int, LOG>> up(n + 1), minimum(n + 1);
    minimum[0].fill(price[0]);
    struct Task {
        int start;
        vector<int> ids;
    };
    vector<Task> tasks(1);
    tasks[0].start = 1;
    tasks[0].ids.resize(m);
    iota(tasks[0].ids.begin(), tasks[0].ids.end(), 0);
    while (!tasks.empty()) {
        Task task = std::move(tasks.back());
        tasks.pop_back();
        if (task.ids.empty())
            continue;
        vector<int> order{task.start};
        parent[task.start] = 0;
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i];
            for (auto [v, w] : g[u])
                if (!removed[v] && v != parent[u]) {
                    parent[v] = u;
                    order.push_back(v);
                }
        }
        int total = order.size(), center = task.start;
        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            int u = *it;
            size[u] = 1;
            int largest = 0;
            for (auto [v, w] : g[u])
                if (!removed[v] && parent[v] == u) {
                    size[u] += size[v];
                    largest = max(largest, size[v]);
                }
            if (max(largest, total - size[u]) <= total / 2)
                center = u;
        }
        order = {center};
        parent[center] = 0;
        branch[center] = -1;
        distance[center] = upCost[center] = downCost[center] = 0;
        prefixMin[center] = price[center];
        vector<int> roots;
        for (auto [v, w] : g[center])
            if (!removed[v])
                roots.push_back(v);
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i], p = parent[u];
            up[u][0] = p;
            minimum[u][0] = price[p];
            for (int j = 1; j < LOG; ++j) {
                up[u][j] = up[up[u][j - 1]][j - 1];
                minimum[u][j] = min(minimum[u][j - 1], minimum[up[u][j - 1]][j - 1]);
            }
            if (p) {
                int v = u;
                for (int j = LOG - 1; j >= 0; --j)
                    if (up[v][j] && minimum[v][j] >= price[u])
                        v = up[v][j];
                int lower = parent[v];
                upCost[u] = ll(price[u]) * (distance[u] - distance[lower]) + upCost[lower];
            }
            int rootIndex = 0;
            for (auto [v, w] : g[u])
                if (!removed[v] && v != p) {
                    parent[v] = u;
                    distance[v] = distance[u] + w;
                    prefixMin[v] = min(prefixMin[u], price[v]);
                    downCost[v] = downCost[u] + ll(w) * prefixMin[u];
                    branch[v] = u == center ? rootIndex++ : branch[u];
                    order.push_back(v);
                }
        }
        vector<vector<int>> pending(roots.size());
        for (int id : task.ids) {
            auto [s, t] = queries[id];
            if (s != center && t != center && branch[s] == branch[t]) {
                pending[branch[s]].push_back(id);
                continue;
            }
            ll cost = upCost[s];
            int p = prefixMin[s];
            if (prefixMin[t] >= p)
                cost += ll(p) * distance[t];
            else {
                int v = t;
                for (int j = LOG - 1; j >= 0; --j)
                    if (up[v][j] && prefixMin[up[v][j]] < p)
                        v = up[v][j];
                cost += ll(p) * distance[v] + downCost[t] - downCost[v];
            }
            answer[id] = cost;
        }
        removed[center] = true;
        for (size_t i = 0; i < roots.size(); ++i)
            if (!pending[i].empty())
                tasks.push_back({roots[i], std::move(pending[i])});
    }
    for (ll x : answer)
        cout << x << '\n';
}
```
