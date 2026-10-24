---
title: "CSP 202412 五题题解"
contest: "202412"
contest_month: "2024-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "模拟", "边界判断", "前缀和", "前后缀最大值", "LRU", "链表", "哈希表", "BFS", "并查集", "区间遍历", "贪心", "单调栈"]
status: "published"
problems: [{"id": "A", "title": "移动", "tags": ["模拟", "边界判断"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c2a67df0b81749b98e"}}, {"id": "B", "title": "梦境巡查", "tags": ["前缀和", "前后缀最大值"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c3a67df0b81749b994"}}, {"id": "C", "title": "缓存模拟", "tags": ["LRU", "链表", "哈希表", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c5a67df0b81749b99a"}}, {"id": "D", "title": "跳房子", "tags": ["BFS", "并查集", "区间遍历"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；150 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c6a67df0b81749b99e"}}, {"id": "E", "title": "梦魔", "tags": ["贪心", "单调栈", "前缀和"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；160 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c9a67df0b81749b9c2"}}]
---

# CSP 202412 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 移动

标签：`模拟` · `边界判断`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

机器人在1…n的方格场地执行f/b/l/r指令：分别使y加1、y减1、x减1、x加1。目标出界时本次不移动。对各独立起点和指令串输出终点。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412A/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202412A)。

### 题解

逐字符先在临时坐标上尝试移动，只有两个坐标都在[1,n]内才提交给当前位置。下一条指令从实际位置继续。

每次更新正好对应题目的一步，逐步归纳得到最终位置。不能只统计四种方向的净位移，因为被边界挡住的步骤不会生效。总时间为指令总长度，额外空间除输入串外为 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        for (char c : s) {
            int xx = x, yy = y;
            if (c == 'f')
                ++yy;
            if (c == 'b')
                --yy;
            if (c == 'l')
                --xx;
            if (c == 'r')
                ++xx;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n) {
                x = xx;
                y = yy;
            }
        }
        cout << x << ' ' << y << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 梦境巡查

标签：`前缀和` · `前后缀最大值`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

依次经过 0…n 再返回起点，离开 i 消耗 a[i]，到达 i≥1 获得 b[i]。对每个 i，独立假设该地补给取消，求完成全程所需最小初始能量，n≤$10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412B/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202412B)。

### 题解

令 need[j] 为离开 j 前累计支出减去已经获得的补给。要能够通过该处，初始能量必须≥need[j]，所以原问题是全部 need 的最大值。

取消 b[i] 不影响 j<i 的 need，却使全部 j≥i 的 need 增加 b[i]。答案就是 `max(prefixMax[i-1],suffixMax[i]+b[i])`。前后缀最大值各做一次线性扫描，每个位置 O(1) 回答。

每一步能量非负的约束被完整枚举，取最大值同时满足全部约束且再小必定违反其中一个，故为最小可行值。时间、空间均 $O(n)$，累计量用 64 位。

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
    vector<long long> a(n + 1), b(n + 1), need(n + 1), pre(n + 1), suf(n + 2, -(1LL << 60));
    for (auto &x : a)
        cin >> x;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    long long cost = 0;
    for (int i = 0; i <= n; i++) {
        cost += a[i] - b[i];
        need[i] = cost;
        pre[i] = i ? max(pre[i - 1], need[i]) : need[i];
    }
    for (int i = n; i >= 0; i--)
        suf[i] = max(suf[i + 1], need[i]);
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            cout << ' ';
        cout << max(pre[i - 1], suf[i] + b[i]);
    }
    cout << '\n';
}
```

<a id="problem-c"></a>

## C. 缓存模拟

标签：`LRU` · `链表` · `哈希表` · `模拟`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

模拟 n 路、N 组缓存，块 a 只能进入组 $(a\div n)\bmod N$。读写命中均更新 LRU；未命中先载入，若满则淘汰最久未访问的块，脏块须先写回内存。输入处理器读写操作，输出实际内存读写操作，0 为读、1 为写。$nN\le65536,q\le10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412C/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202412C)。

### 题解

每组用双向链表，表头是最近使用，表尾是最久未使用；全局哈希表记录块地址对应的链表迭代器。

命中时用 splice 把节点移到表头，写操作将脏标记设为真；读操作不能清除已有脏标记。未命中且组满时，若表尾是脏块，先输出写回，再从链表和哈希表删除；接着无论原请求是读还是写，都输出读入新块，插入表头，脏标记取决于原请求。

每次处理后，链表顺序与最近访问顺序一致，脏标记也准确记录自载入后是否被写过，因此淘汰与输出顺序符合规则。结束时题目没有要求统一刷回脏块，不添加额外输出。期望时间 $O(q)$，空间 $O(nN+N)$。注意组编号不是常见的 `a % N`。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
struct Entry {
    int address;
    bool dirty;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ways, groups, q;
    cin >> ways >> groups >> q;
    vector<list<Entry>> cache(groups);
    unordered_map<int, list<Entry>::iterator> location;
    location.reserve(min(q, ways * groups) * 2 + 1);
    while (q--) {
        int op, address;
        cin >> op >> address;
        auto &group = cache[(address / ways) % groups];
        auto it = location.find(address);
        if (it != location.end()) {
            it->second->dirty |= op == 1;
            group.splice(group.begin(), group, it->second);
            continue;
        }
        if (int(group.size()) == ways) {
            Entry victim = group.back();
            if (victim.dirty)
                cout << "1 " << victim.address << '\n';
            location.erase(victim.address);
            group.pop_back();
        }
        cout << "0 " << address << '\n';
        group.push_front({address, op == 1});
        location[address] = group.begin();
    }
}
```

<a id="problem-d"></a>

## D. 跳房子

标签：`BFS` · `并查集` · `区间遍历`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；150 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

共有 $n$ 个格子，从 1 出发。在格子 $i$ 可以先跳到任意 $j\in[i+1,\min(n,i+k_i)]$，随后立即后退 $a_j$ 格，最终站在 $j-a_j$。求到达 $n$ 的最少跳数，不可达输出 -1。输入依次为 $n$、数组 $a$、数组 $k$；$n\le10^5$，$0\le a_i<i$，$a_n=0$，$k_i\le10^9$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412D/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202412D)。

### 题解

把实际站立位置当作图的节点，选择落点 $j$ 就是走一条边到 $j-a_j$。所有边权为 1，用 BFS 求最短路。直接枚举每个状态的全部可选落点，最坏会扫描 $O(n^2)$ 次。

**同一个落点只处理第一次。** BFS 出队顺序的距离不减。第一次被某个状态覆盖的落点 $j$，已经用尽可能小的跳数到达；它之后总是回退到同一个 $j-a_j$，再次使用它不会产生更短路径。注意删去的是“供选择的落点”，并非“人可以站立的状态”。例如删除落点 5 后，状态 5 仍可正常入队并向外跳。

用后继并查集维护 `find(x)`，返回不小于 $x$ 的第一个尚未处理的落点。处理 $j$ 后令它指向 `find(j+1)`；区间扫描从 `find(i+1)` 开始，超过右端点就停止。代码用迭代路径压缩，避免递归查找出现深调用栈。

BFS 的最短路性质保证删除安全，每个落点最多删除一次；所有可改善距离的边因此都被保留。采用路径压缩的后继结构，通常以近线性时间运行；保守可按 $O(n\log n)$ 估计，空间 $O(n)$。$n=1$ 时无需跳跃，答案为 0。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct Successor {
    vector<int> parent;
    explicit Successor(int n) : parent(n + 2) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        int root = x;
        while (parent[root] != root)
            root = parent[root];
        while (x != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1), k(n + 1), distance(n + 1, -1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> k[i];
    Successor next(n);
    vector<int> queue{1};
    distance[1] = 0;
    for (size_t head = 0; head < queue.size(); ++head) {
        int u = queue[head], right = int(min<long long>(n, 1LL * u + k[u]));
        for (int landing = next.find(u + 1); landing <= right; landing = next.find(landing)) {
            int v = landing - a[landing];
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                queue.push_back(v);
            }
            next.parent[landing] = next.find(landing + 1);
        }
    }
    cout << distance[n] << '\n';
}
```

<a id="problem-e"></a>

## E. 梦魔

标签：`贪心` · `单调栈` · `前缀和`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；160 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

一列梦魔有防御力 $a_i$ 和击杀收益 $b_i>0$。从相邻两只之间出发，每次只能攻击当前左右最近的一只；攻击力至少等于防御力才能击杀，之后增加对应收益。求每个起始间隙所需最小初始攻击力，并异或全部结果。每次询问给若干点的新 $a,b$，修改都基于原始数组，询问之间不累积。$n\le2\times10^6$，$q\le20$，修改总数不超过 $5\times10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412E/)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202412E)。

### 题解

**固定落点先理解贪心。** 两个可选端点中先杀防御力较小的不会更坏：把这次击杀提前，所需门槛没有增加，而且提前得到正收益，其余攻击仍然可行。对固定击杀顺序，所需初始攻击力是每步“当前防御减此前收益”的最大值。

**哪些步骤真正产生瓶颈？** 令 $L_j,R_j$ 为位置 $j$ 两侧最近的防御力不小于 $a_j$ 的位置，无则为 $0,n+1$。若落点 $p<j$ 且在 $[L_j,j-1]$，在 $j$ 形成门槛前，左边直到 $L_j$ 之间的小防御梦魔可以先清掉，所以产生下界 $a_j-(B_{j-1}-B_{L_j})$，其中 $B$ 是收益前缀和。对称地，当 $p\in[j,R_j-1]$，下界为 $a_j-(B_{R_j-1}-B_j)$。落点答案就是覆盖它的全部下界之最大值。

相等防御不弹出，左右边界都求“最近大于等于”。相等端点谁先杀并不影响可行性，但若错误地越过它，会多算可以预先取得的收益。

**无需给所有区间排序。** 单独看右向区间 $[j,R_j-1]$，这些区间只能嵌套或分离。按 $j$ 从小到大扫描，已经开始且未结束的区间形成一个栈；每项保存右端点和栈内最大下界。左向区间 $[L_j,j-1]$ 同理从右向左扫描。两遍结果逐点取最大值后异或。两类区间分开处理，也避免引入比较排序的 $\log n$。

**正确性。** 贪心交换论证给出最优击杀顺序；最近不小于边界恰好划分每个梦魔可能成为瓶颈的落点。两遍栈分别维护这些下界的最大值，合起来覆盖所有必要门槛。**复杂度：** 每次 $O(n+k)$、空间 $O(n)$。累计收益可能达 $2\times10^{15}$，差值和前缀和必须用 64 位有符号整数。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> originalA(n + 2), originalB(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> originalA[i];
    for (int i = 1; i <= n; ++i)
        cin >> originalB[i];
    int q;
    cin >> q;
    vector<int> left(n + 2), right(n + 2), stack;
    stack.reserve(n);
    vector<ll> prefix(n + 2), answer(n + 2), maximum;
    maximum.reserve(n);
    while (q--) {
        auto a = originalA, b = originalB;
        int k;
        cin >> k;
        while (k--) {
            int i;
            cin >> i;
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i - 1] + b[i];
        stack.clear();
        for (int i = 1; i <= n; ++i) {
            while (!stack.empty() && a[stack.back()] < a[i])
                stack.pop_back();
            left[i] = stack.empty() ? 0 : stack.back();
            stack.push_back(i);
        }
        stack.clear();
        for (int i = n; i >= 1; --i) {
            while (!stack.empty() && a[stack.back()] < a[i])
                stack.pop_back();
            right[i] = stack.empty() ? n + 1 : stack.back();
            stack.push_back(i);
        }
        stack.clear();
        maximum.clear();
        for (int p = 1; p < n; ++p) {
            while (!stack.empty() && stack.back() < p) {
                stack.pop_back();
                maximum.pop_back();
            }
            ll need = a[p] - (prefix[right[p] - 1] - prefix[p]);
            stack.push_back(right[p] - 1);
            maximum.push_back(max(need, maximum.empty() ? 0LL : maximum.back()));
            answer[p] = maximum.back();
        }
        stack.clear();
        maximum.clear();
        ll result = 0;
        for (int p = n - 1; p >= 1; --p) {
            while (!stack.empty() && stack.back() > p) {
                stack.pop_back();
                maximum.pop_back();
            }
            int j = p + 1;
            ll need = a[j] - (prefix[j - 1] - prefix[left[j]]);
            stack.push_back(left[j]);
            maximum.push_back(max(need, maximum.empty() ? 0LL : maximum.back()));
            result ^= max(answer[p], maximum.back());
        }
        cout << result << '\n';
    }
}
```
