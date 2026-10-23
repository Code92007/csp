---
title: "CSP 201412 五题题解"
contest: "201412"
contest_month: "2014-12"
date: "2026-10-23"
updated: "2026-10-24"
tags: ["CSP", "在线计数", "矩阵遍历", "对角线", "前缀和", "排序", "整数精度", "模拟", "最小生成树", "Kruskal", "并查集", "费用流", "时间展开图", "周期调度"]
status: "published"
problems: [{"id": "A", "title": "门禁系统", "tags": ["在线计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412A/"}]}, {"id": "B", "title": "Z 字形扫描", "tags": ["矩阵遍历", "对角线"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412B/"}]}, {"id": "C", "title": "集合竞价", "tags": ["前缀和", "排序", "整数精度", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412C/"}]}, {"id": "D", "title": "最优灌溉", "tags": ["最小生成树", "Kruskal", "并查集"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412D/"}]}, {"id": "E", "title": "货物调度", "tags": ["费用流", "时间展开图", "周期调度"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412E/"}]}]
---

# CSP 201412 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 门禁系统

标签：`在线计数`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

按时间给出读者来访编号，输出每条记录中的读者截至该次是第几次出现。编号在1…n。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412A/)。

### 题解

为每个编号维护已出现次数。读取id后先递增count[id]再输出，其他编号计数不变。

处理前i条后，计数数组恰好记录该前缀中每人的出现次数，因此输出就是所需序号。不要先统计全文频次再统一输出。时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> count(n + 1);
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (i)
            cout << ' ';
        cout << ++count[id];
    }
    cout << '\n';
}
```

<a id="problem-b"></a>

## B. Z 字形扫描

标签：`矩阵遍历` · `对角线`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

对n×n矩阵从左上角开始按Z字形扫描，输出全部元素。相邻斜对角线上的方向交替，n≤500。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412B/)。

### 题解

同一条反对角线满足i+j=s，依次枚举s=0…2n-2。合法行号范围为 `max(0,s-n+1)` 到 `min(n-1,s)`；s为奇数时行号从小到大，偶数时从大到小，列号由j=s-i确定。

每个格子唯一属于一条反对角线，枚举范围恰好包含所有合法格子，交替方向符合Z字形。时间 $O(n^2)$，存矩阵空间 $O(n^2)$，无需复杂地模拟碰边转向。

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
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    bool first = true;
    for (int s = 0; s <= 2 * n - 2; s++) {
        int lo = max(0, s - n + 1), hi = min(n - 1, s);
        for (int k = lo; k <= hi; k++) {
            int i = s % 2 ? k : lo + hi - k, j = s - i;
            if (!first)
                cout << ' ';
            first = false;
            cout << a[i][j];
        }
    }
    cout << '\n';
}
```

<a id="problem-c"></a>

## C. 集合竞价

标签：`前缀和` · `排序` · `整数精度` · `模拟`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

记录买单、卖单及按输入行号撤单。对一个委托候选价，买量是报价不低于它的有效买单之和，卖量是报价不高于它的有效卖单之和，成交量取两者较小值。选最大成交量，同分选最高价。记录不超过 5000，单笔股数可达 $10^8$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412C/)。

### 题解

先读完全部记录并标记撤销，行号包括 cancel 行，不能只给买卖单编号。价格按字符串转为整数“分”，避免浮点比较误差；按价格聚合买量和卖量。

价格从低到高扫描。初始 buyers 是全部买量，sellers=0；到价格 p 时先把该价卖量加入 sellers，此时 buyers 与 sellers 分别准确等于不低于 p 的买量、不高于 p 的卖量。计算最小值并在不小于当前最优时更新，以保留较高价格；最后再扣掉该价买量。

买卖量只在委托价处变化，常规集合竞价枚举这些候选价即可；存在正成交量时，最高最优价格必落在某个有效买单报价处。前后缀不变量保证每个候选价的成交量正确。时间 $O(n\log n)$，空间 $O(n)$，总股数用 64 位。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Order {
    string type;
    int price = 0;
    long long quantity = 0;
    bool active = true;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Order> orders(1);
    string type;
    while (cin >> type) {
        Order o;
        o.type = type;
        if (type == "cancel") {
            int i;
            cin >> i;
            orders[i].active = false;
            o.active = false;
        } else {
            string p;
            cin >> p >> o.quantity;
            size_t dot = p.find('.');
            o.price = stoi(p.substr(0, dot)) * 100 + stoi(p.substr(dot + 1));
        }
        orders.push_back(o);
    }
    map<int, pair<long long, long long>> levels;
    long long buyers = 0;
    for (auto o : orders)
        if (o.active && o.quantity) {
            auto &b = levels[o.price];
            if (o.type == "buy") {
                b.first += o.quantity;
                buyers += o.quantity;
            } else
                b.second += o.quantity;
        }
    long long sellers = 0, best = -1;
    int price = 0;
    for (auto [p, v] : levels) {
        sellers += v.second;
        long long volume = min(buyers, sellers);
        if (volume >= best) {
            best = volume;
            price = p;
        }
        buyers -= v.first;
    }
    cout << price / 100 << '.' << setfill('0') << setw(2) << price % 100 << ' ' << max(0LL, best)
         << '\n';
}
```

<a id="problem-d"></a>

## D. 最优灌溉

标签：`最小生成树` · `Kruskal` · `并查集`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。

### 题意

给定 n 块麦田和可建水渠的 m 条无向带权边，第 1 块有水井。选择一些水渠使全部麦田连通，求总费用最小值。$n\le1000,m\le10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412D/)。

### 题解

所有田地都能从水井获得水，当且仅当选择的边使整张图连通。由于费用为正，环上可以删去一条边而保持连通，所以最优方案可以是一棵生成树。

使用 Kruskal：边按费用升序，只有两端还在不同并查集时才选取并合并。对于一次连接两个分量的最便宜边，任意最优生成树若没选它，加入后形成的环上必有另一条跨这两个分量的边；用当前边替换不会更贵。这一交换论证保证每一步均可包含在某棵最优树中。

累加所有选中边费用即可。排序为 $O(m\log m)$，并查集操作近线性，空间 $O(n+m)$。这是“最小生成树总权重”，与只问 1 到 n 的瓶颈路径题不同。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct Edge {
    int u, v, w;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    vector<int> parent(n + 1), size(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
    auto find = [&](int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };
    long long answer = 0;
    for (auto e : edges) {
        int u = find(e.u), v = find(e.v);
        if (u == v)
            continue;
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        answer += e.w;
    }
    cout << answer << '\n';
}
```

<a id="problem-e"></a>

## E. 货物调度

标签：`费用流` · `时间展开图` · `周期调度`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；未提交正式评测。

### 题意

每座城市在一周七天分别生产、消耗一定量货物。城市间道路可当天运输任意数量，单位运费已知；每城仓库有容量限制和单位每夜保管费。要求每周按同一流程循环，求最低每周费用。输入 `n m`，每城一行七日产量、七日需求、仓库容量和费用，随后道路。$n\le100,m\le500$，题面保证可行。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412E/)

### 题解

**把“城市”和“星期几”一起作为节点。** 建 $7n$ 个节点 $(i,d)$。源点连到每个节点，容量为该日生产量、费用 0；各节点连汇点，容量为该日需求量、费用 0。

道路 $(u,v)$ 在每一天各建两个方向的边，容量足够大、费用为单位运费。仓储则建 $(i,d)\to(i,(d+1)\bmod7)$，容量为仓库容量，费用为每夜保管费。尤其不能漏掉星期日到下星期一这条边：题目求稳定的周期调度，第一天可以使用上一周结转的库存。

求从源到汇、流量等于总需求的最小费用流。每一单位流表示一吨货物，它穿过道路边时支付运输费用，穿过跨日边时占用一晚仓库并支付存储费。周末环边准确表达周期条件，而不是凭空增加免费货物：所有流仍受生产与需求平衡约束。

代码使用逐次最短增广路和势能 Dijkstra。初始所有正容量边费用非负，势能可以从 0 开始；每次最短路后更新可达节点势能，使残量图中的可用边折算费用继续非负。反向边费用是正向费用的相反数，用于撤回不再最优的分配。

**正确性。** 可行循环调度与满足源汇总量的流互相转换，边容量对应库存上限，边费用对应实际支出。最小费用最大流因此给出最优调度。**复杂度：** 设增广次数为 $K$，时间 $O(KE\log V)$，空间 $O(V+E)$；这里 $V=7n+2,E=O(n+m)$。这是按实际增广次数给出的界，不应误称为一次最短路即可完成。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
struct MinCostFlow {
    struct Edge {
        int to, reverse, capacity, cost;
    };
    vector<vector<Edge>> g;
    explicit MinCostFlow(int n) : g(n) {}
    void add(int u, int v, int cap, int cost) {
        Edge a{v, int(g[v].size()), cap, cost}, b{u, int(g[u].size()), 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }
    ll solve(int source, int sink, int required) {
        int n = g.size();
        vector<ll> potential(n), dist(n);
        vector<int> parent(n), index(n);
        ll answer = 0;
        const ll INF = 1LL << 60;
        while (required) {
            fill(dist.begin(), dist.end(), INF);
            dist[source] = 0;
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
            q.push({0, source});
            while (!q.empty()) {
                auto [d, u] = q.top();
                q.pop();
                if (d != dist[u])
                    continue;
                for (int j = 0; j < int(g[u].size()); ++j) {
                    auto e = g[u][j];
                    ll nd = d + e.cost + potential[u] - potential[e.to];
                    if (e.capacity && nd < dist[e.to]) {
                        dist[e.to] = nd;
                        parent[e.to] = u;
                        index[e.to] = j;
                        q.push({nd, e.to});
                    }
                }
            }
            if (dist[sink] == INF)
                return -1;
            for (int u = 0; u < n; ++u)
                if (dist[u] != INF)
                    potential[u] += dist[u];
            int flow = required;
            for (int v = sink; v != source; v = parent[v])
                flow = min(flow, g[parent[v]][index[v]].capacity);
            for (int v = sink; v != source; v = parent[v]) {
                auto &e = g[parent[v]][index[v]];
                answer += ll(flow) * e.cost;
                e.capacity -= flow;
                g[v][e.reverse].capacity += flow;
            }
            required -= flow;
        }
        return answer;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int source = 7 * n, sink = source + 1, total = 0;
    MinCostFlow flow(sink + 1);
    for (int i = 0; i < n; ++i) {
        array<int, 7> a{}, b{};
        for (int &v : a)
            cin >> v;
        for (int &v : b)
            cin >> v;
        int cap, cost;
        cin >> cap >> cost;
        for (int j = 0; j < 7; ++j) {
            flow.add(source, 7 * i + j, a[j], 0);
            flow.add(7 * i + j, sink, b[j], 0);
            flow.add(7 * i + j, 7 * i + (j + 1) % 7, cap, cost);
            total += b[j];
        }
    }
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        for (int j = 0; j < 7; ++j) {
            flow.add(7 * u + j, 7 * v + j, 1000000000, c);
            flow.add(7 * v + j, 7 * u + j, 1000000000, c);
        }
    }
    cout << flow.solve(source, sink, total) << '\n';
}
```
