---
title: "CSP 201403 五题题解"
contest: "201403"
contest_month: "2014-03"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "集合", "相反数", "层次顺序", "模拟", "字符串解析", "状态机", "有序映射", "分层BFS", "最短路", "几何判定", "动态规划", "资源调度", "状态压缩"]
status: "published"
problems: [{"id": "A", "title": "相反数", "tags": ["集合", "相反数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U281236"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403A/"}], "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305650472"}}, {"id": "B", "title": "窗口", "tags": ["层次顺序", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc14d74ace1cba9a2189b"}}, {"id": "C", "title": "命令行选项", "tags": ["字符串解析", "状态机", "有序映射"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U281238"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403C/"}], "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305653686"}}, {"id": "D", "title": "无线网络", "tags": ["分层BFS", "最短路", "几何判定"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；50 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U281240"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403D/"}], "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305643544"}}, {"id": "E", "title": "任务调度", "tags": ["动态规划", "资源调度", "状态压缩"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc1d874ace1cba9a218be"}}]
---

# CSP 201403 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 相反数

标签：`集合` · `相反数`

状态：**完整实现，洛谷已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305650472)。

### 题意

给若干非零、互不相同的整数，统计同时存在a和-a的无序数对个数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403A)。

洛谷练习：[同题民间复刻](https://www.luogu.com.cn/problem/U281236)。

### 题解

全部放入集合，仅枚举正数x并检查-x是否存在。每对非零相反数有且只有一个正数，故每个合法数对被计数一次。

时间 $O(n\log n)$，空间 $O(n)$。非零和互异是题目保证，不能把它泛化成含重复值时的组合数计数。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> a;
    while (n--) {
        int x;
        cin >> x;
        a.insert(x);
    }
    int answer = 0;
    for (int x : a)
        if (x > 0 && a.count(-x))
            ++answer;
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 窗口

标签：`层次顺序` · `模拟`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addc14d74ace1cba9a2189b)（复刻评测）。

### 题意

窗口按从底到顶给出。每次点击选中包含该点的最顶层窗口并把它移到顶层，其他窗口相对顺序不变；边界也算窗口内，无窗口则输出IGNORED。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403B)。

### 题解

vector始终按底到顶排列，窗口记录独立的原始编号。每次从尾向前查找第一个包含点的矩形，找到后输出编号、删除该项、追加到末尾；未找到时不改变顺序。

逆序查找保证选中最顶层，删除后追加既置顶又保留其他相对顺序，因此每次操作后顺序不变量继续成立。时间 $O(NM)$，空间 $O(N)$，N、M≤10。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
struct Window {
    int x1, y1, x2, y2, id;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<Window> w(n);
    for (int i = 0; i < n; i++) {
        auto &v = w[i];
        cin >> v.x1 >> v.y1 >> v.x2 >> v.y2;
        v.id = i + 1;
    }
    while (m--) {
        int x, y, found = -1;
        cin >> x >> y;
        for (int i = n - 1; i >= 0; i--) {
            auto v = w[i];
            if (v.x1 <= x && x <= v.x2 && v.y1 <= y && y <= v.y2) {
                found = i;
                break;
            }
        }
        if (found < 0)
            cout << "IGNORED\n";
        else {
            auto v = w[found];
            cout << v.id << '\n';
            w.erase(w.begin() + found);
            w.push_back(v);
        }
    }
}
```

<a id="problem-c"></a>

## C. 命令行选项

标签：`字符串解析` · `状态机` · `有序映射`

状态：**完整实现，洛谷已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305653686)。

### 题意

依据格式字符串解析命令行选项。字母后有冒号表示该选项必须带下一个词作为参数；否则无参数。遇到非法选项或无法取得必需参数时停止。重复无参选项只输出一次，带参选项保留最后一次完整出现的参数，按字母排序输出。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403C)。

洛谷练习：[同题民间复刻](https://www.luogu.com.cn/problem/U281238)。

### 题解

预处理 26 个字母的类型：不支持、无参数、有参数。逐行分词，跳过工具名；每次读取一个词，要求恰好是减号加一个支持的小写字母。带参选项无条件消费紧随的下一个词，即使它以减号开头；若没有下一个词，直接停止且不覆盖之前的有效记录。

用 map 保存已确认的选项，更新前已完成语法和参数检查，因此其中始终是已解析合法前缀的最终结果。停止后不再扫描剩余词，输出 map 自动按字母排序。时间 $O(L+26\log26)$，空间 $O(L)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string format, line;
    int n;
    cin >> format >> n;
    int kind[26] = {};
    for (size_t i = 0; i < format.size(); i++)
        if (format[i] != ':')
            kind[format[i] - 'a'] = i + 1 < format.size() && format[i + 1] == ':' ? 2 : 1;
    getline(cin, line);
    for (int test = 1; test <= n; test++) {
        getline(cin, line);
        istringstream in(line);
        string word;
        in >> word;
        map<char, string> found;
        while (in >> word) {
            if (word.size() != 2 || word[0] != '-' || word[1] < 'a' || word[1] > 'z' ||
                !kind[word[1] - 'a'])
                break;
            char c = word[1];
            string value;
            if (kind[c - 'a'] == 2 && !(in >> value))
                break;
            found[c] = value;
        }
        cout << "Case " << test << ':';
        for (auto [c, value] : found) {
            cout << " -" << c;
            if (kind[c - 'a'] == 2)
                cout << ' ' << value;
        }
        cout << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 无线网络

标签：`分层BFS` · `最短路` · `几何判定`

状态：**完整实现，洛谷已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；50 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305643544)。

### 题意

已有 n 个路由器，另有 m 个候选安装位置，最多新增 k 个。两位置欧氏距离不超过 r 时可以通讯。求已有路由器 1 到 2 最少经过多少个中转路由器，原网络保证连通。$n,m\le100$，坐标绝对值不超过 $10^8$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403D)。

洛谷练习：[同题民间复刻](https://www.luogu.com.cn/problem/U281240)。

### 题解

先对所有已有与候选位置两两检查，用距离平方与 $r^2$ 比较建无向边，避免浮点误差；坐标差平方必须用 64 位。

只记到某个点的最短路不够，因为它可能消耗更多新路由器名额。BFS 状态设为 `(位置 u，已使用新增数 c)`。走到已有点不增加 c，走到候选点则加 1，超过 k 的状态不入队。所有边消耗一步，所以第一次弹出路由器 2 时即得到最少边数；中转点数比边数少 1。

最优路线可以取简单路径：若重复经过某点，删除中间环路只会减少长度与新增需求。因此按路径经过候选点次数计数足够，不必另外记录已安装的集合。所有合法简单路径都能在分层图中表达，故 BFS 最优值与原题相同。

设 $V=n+m$，建图 $O(V^2)$，BFS $O(kV^2)$，空间 $O(V^2+kV)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    long long radius;
    cin >> n >> m >> k >> radius;
    int total = n + m;
    vector<long long> x(total), y(total);
    for (int i = 0; i < total; ++i)
        cin >> x[i] >> y[i];
    vector<vector<int>> graph(total);
    for (int i = 0; i < total; ++i)
        for (int j = 0; j < i; ++j) {
            long long dx = x[i] - x[j], dy = y[i] - y[j];
            if (dx * dx + dy * dy <= radius * radius) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    vector<vector<int>> distance(total, vector<int>(k + 1, -1));
    vector<pair<int, int>> queue{{0, 0}};
    distance[0][0] = 0;
    for (size_t head = 0; head < queue.size(); ++head) {
        auto [u, used] = queue[head];
        if (u == 1) {
            cout << distance[u][used] - 1 << '\n';
            return 0;
        }
        for (int v : graph[u]) {
            int next = used + (v >= n);
            if (next <= k && distance[v][next] < 0) {
                distance[v][next] = distance[u][used] + 1;
                queue.push_back({v, next});
            }
        }
    }
}
```

<a id="problem-e"></a>

## E. 任务调度

标签：`动态规划` · `资源调度` · `状态压缩`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addc1d874ace1cba9a218be)（复刻评测）。

### 题意

有两个 CPU 和一个 GPU，$n\le40$ 个互不依赖的任务。任务 $i$ 可选单 CPU、双 CPU、单 CPU 加 GPU、双 CPU 加 GPU，耗时分别为 $a_i,b_i,c_i,d_i$，均在 1 至 10 之间。执行期间独占使用的设备，不能中断。求最短总完成时间。输入任务数及各任务四种耗时。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403E)。

### 题解

**先把调度顺序化为资源负载。** 同时使用双 CPU 的任务无法与任何其他任务并行，它们可以统一挪到一个串行时段，耗时选 $\min(b_i,d_i)$。剩下的任务分别分配到两个 CPU，部分任务还占 GPU。

设两 CPU 负载为 $x,y$，GPU 负载为 $z$，双 CPU 串行耗时为 $s$。完成时间的下界是 $s+\max(x,y,z)$，而这个下界能达到：将 CPU1 上占 GPU 的任务排在最前，将 CPU2 上占 GPU 的任务排在最后；两段 GPU 任务总长度不超过 $\max(x,y,z)$，不会冲突，其余 CPU 任务放在各自剩余位置即可。

因此 DP 只需记 `dp[x][y][z]` 为处理若干任务后达到这三个负载所需的最小 $s$。每题有五个转移：单 CPU 放到 1 或 2，CPU+GPU 放到 1 或 2，或者用双 CPU 串行执行。交换两个 CPU 不改变答案，统一令 $x\le y$ 合并对称状态。

**把状态范围收紧。** 先计算仅用单 CPU 分配时的最优最大负载（普通背包），再与全部双 CPU 串行执行比较，得到已知上界 $U$。只需保存 $s+\max(x,y,z)<U$ 的状态，最后也保留答案 $U$；被剪掉的状态以后负载只增，不可能改进上界。$a_i\le10,n\le40$ 保证 $U\le200$。若 $c_i\ge a_i$，CPU+GPU 方式被单 CPU 支配；若 $\min(b_i,d_i)\ge a_i$，双 CPU 方式也被单 CPU 支配，可省略。

代码用两个扁平数组滚动，并只枚举实际到达的状态。**复杂度：** 最坏 $O(nU^3)$ 时间、$O(U^3)$ 空间，实际受支配删除和可达状态限制。关键证明是上述调度构造；只写资源总量下界而不证明可排程，不能构成完整题解。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 4>> jobs(n);
    int sum = 0, serial = 0;
    for (auto &job : jobs) {
        for (int &x : job)
            cin >> x;
        sum += job[0];
        serial += min(job[1], job[3]);
    }
    vector<bool> possible(sum + 1);
    possible[0] = true;
    for (auto job : jobs)
        for (int s = sum; s >= job[0]; --s)
            possible[s] = possible[s] || possible[s - job[0]];
    int bound = serial;
    for (int s = 0; s <= sum; ++s)
        if (possible[s])
            bound = min(bound, max(s, sum - s));
    int base = bound, volume = base * base * base;
    const unsigned short INF = 1000;
    vector<unsigned short> dp(volume, INF), next(volume, INF);
    vector<int> active{0}, following;
    dp[0] = 0;
    for (auto job : jobs) {
        int a = job[0], c = job[2], both = min(job[1], job[3]);
        following.clear();
        auto put = [&](int x, int y, int z, int cost) {
            if (cost + max({x, y, z}) >= bound)
                return;
            if (x > y)
                swap(x, y);
            int id = (x * base + y) * base + z;
            if (next[id] == INF)
                following.push_back(id);
            next[id] = min<int>(next[id], cost);
        };
        for (int id : active) {
            int z = id % base, y = id / base % base, x = id / base / base, cost = dp[id];
            put(x + a, y, z, cost);
            put(x, y + a, z, cost);
            if (c < a) {
                put(x + c, y, z + c, cost);
                put(x, y + c, z + c, cost);
            }
            if (both < a)
                put(x, y, z, cost + both);
        }
        for (int id : active)
            dp[id] = INF;
        dp.swap(next);
        active.swap(following);
    }
    int answer = bound;
    for (int id : active)
        answer = min(answer, int(dp[id]) + max({id % base, id / base % base, id / base / base}));
    cout << answer << '\n';
}
```
