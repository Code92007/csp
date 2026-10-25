---
title: "CSP 202305 五题题解"
contest: "202305"
contest_month: "2023-05"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "字符串", "频率统计", "矩阵乘法", "结合律", "复杂度优化", "字节解析", "解压缩", "位运算", "图论", "树形DP", "变量消元", "枚举", "状态压缩", "最短路", "Dijkstra", "SOS DP"]
status: "published"
problems: [{"id": "A", "title": "重复局面", "tags": ["字符串", "频率统计"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16667"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d0a67df0b81749be5a"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305838806", "source_sha256": "ba3d4be762cf3243170222999ceb6d7dd7daaa79baca9ff90269d30011e138c8"}}, {"id": "B", "title": "矩阵运算", "tags": ["矩阵乘法", "结合律", "复杂度优化"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16668"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d2a67df0b81749be67"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305839266", "source_sha256": "6134c6c0bde54dc73bdf25dda099a587acc970cd484eb82c419496d6b379edd2"}}, {"id": "C", "title": "解压缩", "tags": ["字节解析", "解压缩", "位运算"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16669"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d4a67df0b81749be76"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305839556", "source_sha256": "6d341d5fcc167d14be201984db5b923b0919c1139cf6afe94beb0b87759d1b2f"}}, {"id": "D", "title": "电力网络", "tags": ["图论", "树形DP", "变量消元", "枚举"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；160 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16670"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d5a67df0b81749be85"}}, {"id": "E", "title": "闪耀巡航", "tags": ["状态压缩", "最短路", "Dijkstra", "SOS DP"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16671"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d7a67df0b81749be8f"}}]
---

# CSP 202305 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 重复局面

标签：`字符串` · `频率统计`

状态：**完整实现，已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce8d0a67df0b81749be5a)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305838806)（民间复刻评测）。

### 题意

按时间给出若干8×8棋盘局面，两个棋盘所有字符相同才算同一局面，输出每个局面是第几次出现。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16667)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305A)。

### 题解

把每局8行按固定顺序拼成64字符字符串，作为哈希表键，计数先加一再输出。

固定行宽使拼接可唯一还原棋盘，因此键相等当且仅当局面相等。哈希表会对完整字符串进行相等比较，不是只比较一个可能碰撞的摘要。期望时间 $O(64n)$，空间为不同局面的总长度，不涉及国际象棋规则。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_map<string, int> count;
    while (n--) {
        string board, row;
        for (int i = 0; i < 8; i++) {
            cin >> row;
            board += row;
        }
        cout << ++count[board] << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 矩阵运算

标签：`矩阵乘法` · `结合律` · `复杂度优化`

状态：**完整实现，已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce8d2a67df0b81749be67)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305839266)（民间复刻评测）。

### 题意

Q、K、V 为 n×d 矩阵，W 是给每行乘权重的向量，计算 $(W\cdot(QK^T))V$。n≤10000、d≤20，元素绝对值≤1000，输出整数矩阵。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16668)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305B)。

### 题解

不要显式构造 n×n 的 QKᵀ。W 对整行缩放，可以放到最后；利用矩阵乘法结合律，先算 d×d 的 T=KᵀV，再算 QT，最后把第 i 行乘 W[i]。

展开目标元素可得 `W[i]*Σ_a Q[i][a]*Σ_j K[j][a]*V[j][b]`，交换求和次序正是此算法，因此变形等价。两次乘法均只需 $O(nd^2)$，空间 $O(nd+d^2)$。最终绝对值上界 $n d\times1000^4\le2\times10^{17}$，需要64位，并确保中间乘法也在64位中进行。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<long long>>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    Matrix q(n, vector<long long>(d)), k = q, v = q;
    for (auto *a : {&q, &k, &v})
        for (auto &r : *a)
            for (auto &x : r)
                cin >> x;
    vector<long long> w(n);
    for (auto &x : w)
        cin >> x;
    Matrix small(d, vector<long long>(d));
    for (int i = 0; i < n; i++)
        for (int a = 0; a < d; a++)
            for (int b = 0; b < d; b++)
                small[a][b] += k[i][a] * v[i][b];
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < d; b++) {
            long long sum = 0;
            for (int a = 0; a < d; a++)
                sum += q[i][a] * small[a][b];
            if (b)
                cout << ' ';
            cout << sum * w[i];
        }
        cout << '\n';
    }
}
```

<a id="problem-c"></a>

## C. 解压缩

标签：`字节解析` · `解压缩` · `位运算`

状态：**完整实现，已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce8d4a67df0b81749be76)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305839556)（民间复刻评测）。

### 题意

输入 Snappy 风格压缩字节流的十六进制表示。开头以低 7 位、低位组在前的变长整数表示原始长度，随后是字面量片段或向前引用片段。按题目格式解压，输出小写十六进制，每行最多 8 字节。压缩与解压长度均不超过约 2 MiB，输入保证合法。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16669)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305C)。

### 题解

先把十六进制两个字符还原成一个字节，用指针依次读取。标记字节低两位决定类型。类型 0 的高六位小于 60 时，长度等于它加 1；否则接下来的“高六位减 59”个字节按小端拼成长度减 1，再复制对应字面量。

类型 1 的长度是 `((tag>>2)&7)+4`，偏移为标记最高三位拼接下一字节；类型 2 的长度为 `(tag>>2)+1`，偏移由后两字节按小端读取。题目不出现类型 3。

向前引用必须逐字节执行 `out.push_back(out[out.size()-offset])`。例如已有 a、偏移 1、复制 5 字节，应得到六个 a；新增字节可以继续被当前引用读取，所以不能只复制一次固定的旧区间。

每个片段的解码与编码规则互逆，按流顺序归纳即可还原全文。时间 $O(S+U)$，空间 $O(S+U)$，S 为压缩字节数、U 为解压字节数；输出的换行只作用于显示，不属于原数据。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s;
    cin >> s;
    vector<unsigned char> in;
    string h;
    while (cin >> h)
        for (size_t i = 0; i < h.size(); i += 2)
            in.push_back(stoul(h.substr(i, 2), nullptr, 16));
    size_t p = 0;
    unsigned length = 0, shift = 0;
    while (true) {
        unsigned b = in[p++];
        length |= (b & 127) << shift;
        if (!(b & 128))
            break;
        shift += 7;
    }
    vector<unsigned char> out;
    out.reserve(length);
    while (p < in.size()) {
        unsigned tag = in[p++], type = tag & 3, len, offset;
        if (type == 0) {
            len = tag >> 2;
            if (len < 60)
                ++len;
            else {
                unsigned bytes = len - 59;
                len = 0;
                for (unsigned j = 0; j < bytes; j++)
                    len |= unsigned(in[p++]) << (8 * j);
                ++len;
            }
            for (unsigned j = 0; j < len; j++)
                out.push_back(in[p++]);
        } else {
            if (type == 1) {
                len = ((tag >> 2) & 7) + 4;
                offset = ((tag >> 5) << 8) | in[p++];
            } else {
                len = (tag >> 2) + 1;
                offset = in[p++];
                offset |= unsigned(in[p++]) << 8;
            }
            for (unsigned j = 0; j < len; j++)
                out.push_back(out[out.size() - offset]);
        }
    }
    const char *hex = "0123456789abcdef";
    for (size_t i = 0; i < out.size(); i++) {
        cout << hex[out[i] >> 4] << hex[out[i] & 15];
        if (i % 8 == 7 || i + 1 == out.size())
            cout << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 电力网络

标签：`图论` · `树形DP` · `变量消元` · `枚举`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；160 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

有 $N$ 个城镇，每个城镇从 $K$ 个地址中选一个建设变电站；每个地址有建设成本。还需建设给定的 $M$ 条无向边，每条边给出 $K\times K$ 成本矩阵，费用取决于两端选址。求点成本与边成本总和的最小值。城镇编号从 0 开始。题目分别保证小图、树、单环图、删去某一点后为树的特定图，或者度数大于 2 的点不超过 6 个；$N\le10^4,K\le10$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16670)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305D)。

### 题解

这是带点费用的标签分配问题，一般图不能直接用树形 DP。实现按题目提供的结构统一处理两类情况。

**第一类：存在一个点，删掉后剩下森林。** 固定该点的选址为 $s$，把它与各邻居的边费用加到邻居的点费用中，剩下每棵树做

$$dp_u[x]=cost_u[x]+\sum_{v\text{ 为子节点}}\min_y\bigl(dp_v[y]+edge_{uv}[x][y]\bigr).$$

枚举被固定点的 $K$ 个地址，取最小值。树、单环图和题目的“删点成树”子任务都属于这一类。

不必逐点删图来试。连通无向图删去点 $u$ 后，剩余图有 $c_u$ 个连通分量，其独立环数为 $M-N+1-\deg(u)+c_u$。用一次 low-link DFS 求各点删除后的分量数，找到该表达式为 0 的点即可。DFS 迭代执行，避免深树爆栈。

**第二类：压缩度数不超过 2 的点。** 若找不到上述点，把低度点逐个消去，始终保留等价的点费用和边费用。孤立点取最便宜选址加入常数；叶子 $u$ 对每种邻居选址独立取最小值，并加到邻居点费用；度为 2 的 $u$，邻居为 $v,w$，生成新边费用

$$new[x][y]=\min_z\bigl(edge_{vu}[x][z]+cost_u[z]+edge_{uw}[z][y]\bigr).$$

若 $v,w$ 原本已有边，两份费用相加。每次消元都是在固定剩余变量时，对被消去变量精确求最小值，所以不改变最优答案。消元不会增加邻居的度数。最后一类数据至多留下原先那 6 个高度点；小图也至多剩 6 点。直接枚举核心所有选址，累加点边费用即可。

第一类时间 $O(KM+NK^3)$ 的保守界（每个固定选址做一次树形 DP），空间 $O(MK^2+NK)$；第二类消元 $O(NK^3)$，核心枚举 $O(K^h h^2)$、$h\le6$。代码保存边的两个方向时转置矩阵，不能把非对称费用矩阵当成对称矩阵。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>
using namespace std;
using i64 = long long;
using Matrix = vector<vector<i64>>;
const i64 INF = 4000000000000000000LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<i64>> cost(n, vector<i64>(k));
    for (auto &row : cost)
        for (auto &x : row)
            cin >> x;
    vector<map<int, Matrix>> edges(n);
    auto connect = [&](int u, int v, const Matrix &a) {
        Matrix transpose(k, vector<i64>(k));
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                transpose[j][i] = a[i][j];
        edges[u][v] = a;
        edges[v][u] = transpose;
    };
    for (int e = 0; e < m; ++e) {
        int u, v;
        cin >> u >> v;
        Matrix a(k, vector<i64>(k));
        for (auto &row : a)
            for (auto &x : row)
                cin >> x;
        connect(u, v, a);
    }
    // Count components after deleting each vertex using an iterative low-link DFS.
    vector<int> tin(n), low(n), parent(n, -1), children(n), separated(n), order;
    int timer = 0;
    vector<map<int, Matrix>::iterator> cursor(n);
    vector<int> stack{0};
    tin[0] = low[0] = ++timer;
    cursor[0] = edges[0].begin();
    while (!stack.empty()) {
        int u = stack.back();
        if (cursor[u] == edges[u].end()) {
            stack.pop_back();
            order.push_back(u);
            if (parent[u] != -1) {
                int p = parent[u];
                low[p] = min(low[p], low[u]);
                if (low[u] >= tin[p])
                    ++separated[p];
            }
            continue;
        }
        int v = (cursor[u]++)->first;
        if (v == parent[u])
            continue;
        if (tin[v])
            low[u] = min(low[u], tin[v]);
        else {
            parent[v] = u;
            ++children[u];
            tin[v] = low[v] = ++timer;
            cursor[v] = edges[v].begin();
            stack.push_back(v);
        }
    }
    int fixed = -1;
    for (int u = 0; u < n; ++u) {
        int components = parent[u] == -1 ? children[u] : separated[u] + 1;
        if (m - n + 1 - int(edges[u].size()) + components == 0) {
            fixed = u;
            break;
        }
    }
    if (fixed != -1) {
        // After fixing this vertex, all remaining components are trees.
        vector<int> par(n, -2), traversal;
        par[fixed] = -1;
        for (int start = 0; start < n; ++start)
            if (par[start] == -2) {
                par[start] = -1;
                traversal.push_back(start);
                for (size_t head = traversal.size() - 1; head < traversal.size(); ++head) {
                    int u = traversal[head];
                    for (const auto &[v, a] : edges[u])
                        if (par[v] == -2) {
                            par[v] = u;
                            traversal.push_back(v);
                        }
                }
            }
        i64 answer = INF;
        for (int label = 0; label < k; ++label) {
            auto dp = cost;
            for (const auto &[u, a] : edges[fixed])
                for (int b = 0; b < k; ++b)
                    dp[u][b] += a[label][b];
            i64 total = cost[fixed][label];
            for (auto it = traversal.rbegin(); it != traversal.rend(); ++it) {
                int u = *it, p = par[u];
                if (p == -1) {
                    total += *min_element(dp[u].begin(), dp[u].end());
                    continue;
                }
                const auto &a = edges[p].at(u);
                for (int x = 0; x < k; ++x) {
                    i64 best = INF;
                    for (int y = 0; y < k; ++y)
                        best = min(best, a[x][y] + dp[u][y]);
                    dp[p][x] += best;
                }
            }
            answer = min(answer, total);
        }
        cout << answer << '\n';
        return 0;
    }
    // Eliminate vertices of degree <= 2, keeping exact unary/pairwise costs.
    queue<int> ready;
    vector<bool> removed(n);
    for (int u = 0; u < n; ++u)
        if (edges[u].size() <= 2)
            ready.push(u);
    i64 constant = 0;
    while (!ready.empty()) {
        int u = ready.front();
        ready.pop();
        if (removed[u] || edges[u].size() > 2)
            continue;
        removed[u] = true;
        if (edges[u].empty()) {
            constant += *min_element(cost[u].begin(), cost[u].end());
            continue;
        }
        int v = edges[u].begin()->first;
        if (edges[u].size() == 1) {
            const auto &a = edges[v].at(u);
            for (int x = 0; x < k; ++x) {
                i64 best = INF;
                for (int y = 0; y < k; ++y)
                    best = min(best, a[x][y] + cost[u][y]);
                cost[v][x] += best;
            }
            edges[v].erase(u);
            ready.push(v);
        } else {
            int w = next(edges[u].begin())->first;
            const auto &a = edges[v].at(u);
            const auto &b = edges[u].at(w);
            Matrix merged(k, vector<i64>(k, INF));
            for (int x = 0; x < k; ++x)
                for (int y = 0; y < k; ++y) {
                    for (int z = 0; z < k; ++z)
                        merged[x][y] = min(merged[x][y], a[x][z] + cost[u][z] + b[z][y]);
                    if (edges[v].count(w))
                        merged[x][y] += edges[v].at(w)[x][y];
                }
            edges[v].erase(u);
            edges[w].erase(u);
            connect(v, w, merged);
            ready.push(v);
            ready.push(w);
        }
        edges[u].clear();
    }
    vector<int> core;
    for (int u = 0; u < n; ++u)
        if (!removed[u])
            core.push_back(u);
    vector<int> label(n);
    i64 answer = INF;
    function<void(int, i64)> enumerate = [&](int index, i64 value) {
        if (value >= answer)
            return;
        if (index == int(core.size())) {
            answer = value;
            return;
        }
        int u = core[index];
        for (int x = 0; x < k; ++x) {
            i64 next_value = value + cost[u][x];
            for (int j = 0; j < index; ++j)
                if (edges[u].count(core[j]))
                    next_value += edges[u].at(core[j])[x][label[core[j]]];
            label[u] = x;
            enumerate(index + 1, next_value);
        }
    };
    enumerate(0, constant);
    cout << answer << '\n';
}
```

<a id="problem-e"></a>

## E. 闪耀巡航

标签：`状态压缩` · `最短路` · `Dijkstra` · `SOS DP`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定若干小写字母串，每个串表示一条固定巡航线路：从首字符对应城市出发，在末字符城市结束，中间经过其余城市，长度为字符串长度减一。另给至多 10 个不同目标字母。对每条线路，要求先完整乘坐它，再接若干条线路，最后回到该线路起点，并经过全部目标城市，求最短总长度，无解输出 -1。输入线路数、目标字母串，以及每条线路的字符串。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16671)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305E)。

### 题解

**把一条线路压成一条带集合的有向边。** 记录首字母 $u$、末字母 $v$、途中目标城市集合 $mask$、长度 $w$。城市只有 26 个，目标集合用至多 10 位二进制表示。即使首尾相同，线路也可能收集新目标，不能删除自环。

状态 $(u,S)$ 表示当前在城市 $u$，已收集目标集合 $S$。经过线路 $(u,v,M,w)$，转移到 $(v,S\cup M)$，代价增加 $w$。边权非负，运行 Dijkstra。分别以 26 个城市为起点预处理，得到 `dist[start][end][mask]`。

对于必须先乘坐的线路 $(u,v,M,w)$，后半程从 $v$ 出发回到 $u$，只需补齐 $\overline M$。对每个起终点做一次超集最小值 SOS DP，使 `need[S]` 表示至少包含 $S$ 的最短距离。答案即 $w+need[v][u][\overline M]$。后半程可以为空；完整第一段已经满足条件的闭合线路自然会得到其自身长度。

**压缩重复边。** 相同首尾和集合只保留最短长度。如果存在相同首尾、集合更大、长度不增的线路，则原边被支配，可以删去。利用超集最小值快速检查支配关系。删边不会降低任何后续可行性，也不会增加代价。

**正确性。** 任意合法巡航唯一对应状态图中的一条游走；反之，每个状态转移都代表完整乘坐一条允许线路。固定第一段后，余下要求恰好是终点和缺失集合，因此最短路与超集查询给出最优值。

**复杂度。** 设压缩后边数为 $E$、目标数为 $k$。每次最短路有 $26\cdot2^k$ 个状态，最坏扫描 $E2^k$ 条状态边；总时间约为 $O(26E2^k\log(26\cdot2^k)+26^2k2^k)$，空间 $O(26^2 2^k+E)$。支配删边能减少实际扫描量，但不应把它当作改变最坏复杂度的保证；极限密集数据仍需关注时限。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
struct Route {
    int from, to, mask, length;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string target;
    cin >> n >> target;
    int bits = target.size(), S = 1 << bits, INF = 1000000000;
    array<int, 26> id;
    id.fill(-1);
    for (int i = 0; i < bits; ++i)
        id[target[i] - 'a'] = i;
    vector<Route> routes(n);
    vector<int> best(26 * 26 * S, INF);
    for (auto &r : routes) {
        string s;
        cin >> s;
        r = {s.front() - 'a', s.back() - 'a', 0, int(s.size()) - 1};
        for (char c : s)
            if (id[c - 'a'] >= 0)
                r.mask |= 1 << id[c - 'a'];
        int &w = best[(r.from * 26 + r.to) * S + r.mask];
        w = min(w, r.length);
    }
    vector<vector<Route>> g(26);
    for (int u = 0; u < 26; ++u)
        for (int v = 0; v < 26; ++v) {
            vector<int> sup(S);
            for (int s = 0; s < S; ++s)
                sup[s] = best[(u * 26 + v) * S + s];
            for (int b = 0; b < bits; ++b)
                for (int s = 0; s < S; ++s)
                    if (!(s >> b & 1))
                        sup[s] = min(sup[s], sup[s | (1 << b)]);
            for (int s = 0; s < S; ++s) {
                int w = best[(u * 26 + v) * S + s];
                if (w == INF)
                    continue;
                bool dominated = false;
                for (int b = 0; b < bits; ++b)
                    if (!(s >> b & 1) && sup[s | (1 << b)] <= w)
                        dominated = true;
                if (!dominated)
                    g[u].push_back({u, v, s, w});
            }
        }
    vector<vector<int>> need(26, vector<int>(26 * S, INF));
    for (int start = 0; start < 26; ++start) {
        auto &dist = need[start];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        dist[start * S] = 0;
        heap.push({0, start * S});
        while (!heap.empty()) {
            auto [d, state] = heap.top();
            heap.pop();
            if (d != dist[state])
                continue;
            int u = state / S, mask = state % S;
            for (auto edge : g[u]) {
                int v = edge.to * S + (mask | edge.mask);
                if (d + edge.length < dist[v]) {
                    dist[v] = d + edge.length;
                    heap.push({dist[v], v});
                }
            }
        }
        // Convert exact masks to "at least these stamps".
        for (int v = 0; v < 26; ++v)
            for (int b = 0; b < bits; ++b)
                for (int s = 0; s < S; ++s)
                    if (!(s >> b & 1))
                        dist[v * S + s] = min(dist[v * S + s], dist[v * S + (s | (1 << b))]);
    }
    for (auto r : routes) {
        int d = need[r.to][r.from * S + ((S - 1) ^ r.mask)];
        cout << (d == INF ? -1 : d + r.length) << '\n';
    }
}
```
