---
title: "CSP 201604 五题题解"
contest: "201604"
contest_month: "2016-04"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "局部极值", "数组扫描", "碰撞检测", "网格模拟", "栈", "路径解析", "字符串", "BFS", "时间状态", "网格", "状态压缩", "连通性DP", "Steiner树", "轮廓线DP"]
status: "published"
problems: [{"id": "A", "title": "折点计数", "tags": ["局部极值", "数组扫描"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addad4c74ace1cba9a20424"}}, {"id": "B", "title": "俄罗斯方块", "tags": ["碰撞检测", "网格模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addaddf74ace1cba9a20472"}}, {"id": "C", "title": "路径解析", "tags": ["栈", "路径解析", "字符串"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addae9574ace1cba9a2058d"}}, {"id": "D", "title": "游戏", "tags": ["BFS", "时间状态", "网格"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addaf1b74ace1cba9a20648"}}, {"id": "E", "title": "网络连接", "tags": ["状态压缩", "连通性DP", "Steiner树", "轮廓线DP"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb00e74ace1cba9a206db"}}]
---

# CSP 201604 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 折点计数

标签：`局部极值` · `数组扫描`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addad4c74ace1cba9a20424)（复刻评测）。

### 题意

相邻销售量保证不同，统计从增长变减少或从减少变增长的折点。首尾没有两侧邻居，不是折点。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604A)。

### 题解

扫描除首尾外每个位置：严格大于左右两邻为峰，严格小于两邻为谷，满足任一条件就计数。

这两种情况分别等价于上升转下降、下降转上升，覆盖全部折点且互斥。n<3时循环为空自然输出0。时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int count = 0;
    for (int i = 1; i + 1 < n; i++)
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
            ++count;
    cout << count << '\n';
}
```

<a id="problem-b"></a>

## B. 俄罗斯方块

标签：`碰撞检测` · `网格模拟`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addaddf74ace1cba9a20472)（复刻评测）。

### 题意

给15×10棋盘、4×4新板块图案及图案左边所在列，模拟板块竖直下落到首次碰撞前的位置。只放置板块，不消行；图案内可能有空白边。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604B)。

### 题解

先提取4×4中四个实心格子的相对坐标。假设图案顶端在top，检查每个实心格是否仍在棋盘内且与原棋盘无重叠。只要top+1可行就继续下落，否则将当前位置写入棋盘。

最初前四行全空，故起点合法；循环逐行模拟连续下落，停下时当前位置合法而下一位置碰撞，正是题目终态。不能把空白边删去后仍沿用输入列号。棋盘固定大小，时间和额外空间均为常数量。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int board[15][10];
    for (auto &r : board)
        for (int &x : r)
            cin >> x;
    vector<pair<int, int>> shape;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            if (x)
                shape.push_back({i, j});
        }
    int col;
    cin >> col;
    --col;
    auto fits = [&](int top) {
        for (auto [r, c] : shape)
            if (top + r >= 15 || board[top + r][col + c])
                return false;
        return true;
    };
    int top = 0;
    while (fits(top + 1))
        ++top;
    for (auto [r, c] : shape)
        board[top + r][col + c] = 1;
    for (auto &r : board) {
        for (int j = 0; j < 10; j++) {
            if (j)
                cout << ' ';
            cout << r[j];
        }
        cout << '\n';
    }
}
```

<a id="problem-c"></a>

## C. 路径解析

标签：`栈` · `路径解析` · `字符串`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addae9574ace1cba9a2058d)（复刻评测）。

### 题意

给定正规化的当前目录，把若干绝对／相对路径变为正规绝对路径。忽略重复斜杠和 .，.. 返回父目录但不能越过根；空路径表示当前目录，输出末尾不留斜杠，根目录例外。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604C)。

### 题解

把路径看成由斜杠分隔的目录名，使用向量模拟栈。绝对路径从空栈开始，相对路径先放入当前目录的各部分。空片段或 . 跳过，.. 在非空时弹栈，其他字符串入栈。最后为每个栈元素前加斜杠，空栈输出 /。

处理任一前缀后，栈始终是该前缀指定位置到根的目录链，各种操作正好对应保持位置、返回上层和进入下层，因此结果等价且满足正规形式。注意 ...、a.. 是普通名字，不能做字符串级的“删除所有点号”。时间和空间均为 $O(L)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
vector<string> parse(const string &s, vector<string> stack = {}) {
    istringstream in(s);
    string part;
    while (getline(in, part, '/')) {
        if (part.empty() || part == ".")
            continue;
        if (part == "..") {
            if (!stack.empty())
                stack.pop_back();
        } else
            stack.push_back(part);
    }
    return stack;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string cwd, line;
    cin >> cwd;
    getline(cin, line);
    auto base = parse(cwd);
    while (n--) {
        getline(cin, line);
        auto result = parse(line, !line.empty() && line[0] == '/' ? vector<string>{} : base);
        if (result.empty())
            cout << '/';
        else
            for (auto &s : result)
                cout << '/' << s;
        cout << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 游戏

标签：`BFS` · `时间状态` · `网格`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addaf1b74ace1cba9a20648)（复刻评测）。

### 题意

从 n×m 网格左上角走到右下角，每秒必须向上下左右之一移动一格，不能原地等待。部分格子在闭区间 [a,b] 时刻危险，进入时不能处于危险期。输入 n,m,t，随后每个危险格子的行、列、a、b。$n,m\le100$，危险结束时刻不超过 100，保证可达。求最早到达时刻。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604D)。

### 题解

同一个位置在不同时间有不同的可走方向，因此 BFS 状态应为“位置、时刻”，不能只给格子设一次访问标记。初始状态是左上角、时刻 0；从时刻 t 的状态只转移到时刻 t+1 的四个邻格，检查边界与该时刻是否危险。

为什么时间维有有限上界？设最晚危险结束于 B。保证存在成功路线；如果它在 B 前已经到达就更好，否则取其 B 时刻所在位置，此后所有格子都安全，至多再走 n+m-2 步即可到终点。因此保留到 B+n+m 即足够。

每条转移耗时 1，BFS 第一次取出终点状态就是最早时间。允许在两个安全格子之间往返来消耗时间，但代码没有“原地停留”转移。时间、空间均为 $O(nm(B+n+m))$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> begin(n * m, 1), end(n * m, 0);
    int last = 0;
    for (int i = 0; i < k; ++i) {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        int u = (r - 1) * m + c - 1;
        begin[u] = a;
        end[u] = b;
        last = max(last, b);
    }
    int limit = last + n + m;
    vector<vector<bool>> seen(limit + 1, vector<bool>(n * m));
    vector<pair<int, int>> queue{{0, 0}};
    seen[0][0] = true;
    const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    for (size_t head = 0; head < queue.size(); ++head) {
        auto [u, time] = queue[head];
        if (u == n * m - 1) {
            cout << time << '\n';
            return 0;
        }
        if (time == limit)
            continue;
        for (int d = 0; d < 4; ++d) {
            int x = u / m + dx[d], y = u % m + dy[d], t = time + 1;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            int v = x * m + y;
            if (!seen[t][v] && !(begin[v] <= t && t <= end[v])) {
                seen[t][v] = true;
                queue.push_back({v, t});
            }
        }
    }
}
```

<a id="problem-e"></a>

## E. 网络连接

标签：`状态压缩` · `连通性DP` · `Steiner树` · `轮廓线DP`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb00e74ace1cba9a206db)（复刻评测）。

### 题意

有 $n$ 台设备，其中一些是必须连通的用户设备，可以选择部分其他设备辅助连接。候选边 $(u,v)$ 满足 $|u-v|\le p$，有非负费用，求连接所有用户设备的最小费用。输入多组数据，每组为 `n m p`、终端标记 01 串、各候选边。$n\le500,p\le6$，终端至少两个。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604E)。

### 题解

终端数可能很多，按终端子集做 Steiner Tree DP 不合适；本题可用的是边的“编号跨度很小”。从小到大处理设备，在处理 $i$ 前，只需要记住窗口 $i,\ldots,i+p-1$。更早设备已不会连到更远的未来点。

**状态记录连通关系。** 每个窗口位置为 0 表示未选中，否则用相同标签表示在已选边中属于同一连通块。将标签按首次出现重新编号，避免同一种分区出现多个编码。窗口最多 6 个位置，共不超过 Bell(7)=877 个带空位分区。

处理设备 $i$ 时，枚举它到后面 $p$ 个位置的出边子集，加入费用并合并对应连通块，再忘掉最左端点、窗口右移。终端必须已经被选中或通过本次出边被选中；非终端可以完全跳过。不存在的边不能枚举。

**最容易漏的条件是“连通块消失”。** 若遗忘 $i$ 后，它所属连通块再也没有窗口代表，则它以后不可能连接其他点。只有当它是唯一连通块，且全部终端都已处理时，才能作为完整答案结束；否则丢弃该转移。即使某个消失块不含终端，也可以丢弃：边费用非负，最优方案总能去掉不连接终端的多余分量。

代码先枚举全部规范状态，并预计算每个状态和出边子集的连通性转移；实际每组数据只计算存在边子集的费用，再做最小值 DP。结束答案需要在合法连通块关闭时记录，不能简单把“最后为空状态”视为成功。

**正确性。** 窗口完整保存了过去与未来之间可能发生连接的全部接口；分区足以判断未来合并，消失规则保证不会遗留孤立终端。每条边只在较小端点处决策一次，故费用与所选网络一致。**复杂度：** 状态数记为 $S\le877$，主体 $O(nS2^p)$，转移预处理 $O(S2^p p^2)$，空间 $O(S2^p+np)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m, p;
        cin >> n >> m >> p;
        string terminal;
        cin >> terminal;
        int last = terminal.find_last_of('1');
        vector<array<int, 6>> cost(n);
        for (auto &a : cost)
            a.fill(-1);
        for (int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            cost[u - 1][v - u - 1] = w;
        }
        vector<int> codes{0};
        unordered_map<int, int> id{{0, 0}};
        vector<vector<int>> transition;
        for (size_t index = 0; index < codes.size(); ++index) {
            int code = codes[index];
            vector<int> row(1 << p, -1);
            for (int mask = 0; mask < (1 << p); ++mask) {
                array<int, 7> parent{}, selected{};
                iota(parent.begin(), parent.end(), 0);
                auto root = [&](int u) {
                    while (parent[u] != u)
                        u = parent[u];
                    return u;
                };
                auto unite = [&](int u, int v) { parent[root(u)] = root(v); };
                for (int i = 0; i < p; ++i) {
                    int label = (code >> (3 * i)) & 7;
                    selected[i] = label != 0;
                    if (label)
                        for (int j = 0; j < i; ++j)
                            if (((code >> (3 * j)) & 7) == label)
                                unite(i, j);
                }
                for (int j = 0; j < p; ++j)
                    if (mask >> j & 1) {
                        selected[0] = selected[j + 1] = 1;
                        unite(0, j + 1);
                    }
                if (selected[0]) {
                    bool stays = false, other = false;
                    for (int j = 1; j <= p; ++j)
                        if (selected[j]) {
                            if (root(j) == root(0))
                                stays = true;
                            else
                                other = true;
                        }
                    if (!stays) {
                        row[mask] = other ? -1 : -2;
                        continue;
                    }
                }
                array<int, 7> label{};
                int count = 0, next = 0;
                for (int j = 1; j <= p; ++j)
                    if (selected[j]) {
                        int r = root(j);
                        if (!label[r])
                            label[r] = ++count;
                        next |= label[r] << (3 * (j - 1));
                    }
                auto [it, inserted] = id.emplace(next, codes.size());
                if (inserted)
                    codes.push_back(next);
                row[mask] = it->second;
            }
            transition.push_back(std::move(row));
        }
        const ll INF = 1LL << 60;
        vector<ll> dp(codes.size(), INF);
        dp[0] = 0;
        ll answer = INF;
        for (int i = 0; i < n; ++i) {
            vector<ll> next(codes.size(), INF);
            int available = 0;
            for (int j = 0; j < p; ++j)
                if (cost[i][j] >= 0)
                    available |= 1 << j;
            vector<pair<int, ll>> options;
            for (int mask = available;; mask = (mask - 1) & available) {
                ll sum = 0;
                for (int j = 0; j < p; ++j)
                    if (mask >> j & 1)
                        sum += cost[i][j];
                options.push_back({mask, sum});
                if (!mask)
                    break;
            }
            for (int state = 0; state < int(codes.size()); ++state) {
                if (dp[state] == INF)
                    continue;
                for (auto [mask, w] : options) {
                    if (terminal[i] == '1' && !(codes[state] & 7) && !mask)
                        continue;
                    int to = transition[state][mask];
                    if (to == -2) {
                        if (i >= last)
                            answer = min(answer, dp[state] + w);
                    } else if (to >= 0)
                        next[to] = min(next[to], dp[state] + w);
                }
            }
            dp.swap(next);
        }
        cout << answer << '\n';
    }
}
```
