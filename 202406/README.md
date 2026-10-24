---
title: "CSP 202406 五题题解"
contest: "202406"
contest_month: "2024-06"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "矩阵重塑", "线性下标", "数组", "矩阵变换", "模拟", "BPE", "链表", "优先队列", "字符串", "分组背包", "排序", "动态规划", "二维区间", "线段树", "扫描线", "静态查询"]
status: "published"
problems: [{"id": "A", "title": "矩阵重塑（其一）", "tags": ["矩阵重塑", "线性下标"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81ca67df0b81749bb2f"}}, {"id": "B", "title": "矩阵重塑（其二）", "tags": ["数组", "矩阵变换", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81da67df0b81749bb39"}}, {"id": "C", "title": "文本分词", "tags": ["BPE", "链表", "优先队列", "字符串"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；130 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81fa67df0b81749bb49"}}, {"id": "D", "title": "货物调度", "tags": ["分组背包", "排序", "动态规划"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce821a67df0b81749bb75"}}, {"id": "E", "title": "哥德尔机", "tags": ["二维区间", "线段树", "扫描线", "静态查询"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 70 分 Time Exceeded（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406E/"}], "oj": {"status": "failed", "score": 70, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6adce823a67df0b81749bb8a"}}]
---

# CSP 202406 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 矩阵重塑（其一）

标签：`矩阵重塑` · `线性下标`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

将n×m矩阵按行顺序重塑成p×q，元素总数相同，保持线性顺序。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406A)。

### 题解

输入按行读取时本身就是所需一维顺序。依次读出并输出元素，只需每q个换一行，行内相邻数字间输出一个空格，无需真正建立二维数组。

第k个输入在新矩阵中的位置为(k/q,k%q)，流式输出恰好执行此映射。时间 $O(nm)$，额外空间 $O(1)$。重塑保留元素顺序，不是转置。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int k = 0; k < n * m; k++) {
        int x;
        cin >> x;
        if (k % q)
            cout << ' ';
        cout << x;
        if (k % q == q - 1)
            cout << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 矩阵重塑（其二）

标签：`数组` · `矩阵变换` · `模拟`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

矩阵支持按行顺序重塑、转置和单点查询。元素总数≤10000，操作数≤$10^5$，其中转置至多100次。重塑前后元素总数相同。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406B)。

### 题解

始终用一维数组保存当前矩阵的按行序列。重塑不改变这条序列，只更新行列数；查询 (i,j) 直接取 a[i*m+j]。转置时才新建数组，令 `b[j*n+i]=a[i*m+j]`，完成后交换行列数。

这三种操作分别严格实现重塑的线性顺序、行列交换和坐标寻址定义，因此逐次维护得到正确矩阵。若元素数 S、转置次数 R，时间 $O(t+RS)$，空间 $O(S)$。不能把转置也只视为交换尺寸。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n * m);
    for (int &x : a)
        cin >> x;
    while (t--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            n = x;
            m = y;
        } else if (op == 2) {
            vector<int> b(a.size());
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    b[j * n + i] = a[i * m + j];
            a.swap(b);
            swap(n, m);
        } else
            cout << a[x * m + y] << '\n';
    }
}
```

<a id="problem-c"></a>

## C. 文本分词

标签：`BPE` · `链表` · `优先队列` · `字符串`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；130 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给出单词及频率，先把出现的单字母按字典序加入词表。每轮选择加权相邻词汇对出现次数最大者，依次以拼接长度短、前词长度短、拼接结果字典序小破同分；加入合并词，并在各单词中从左到右合并全部该词汇对。到词表目标长度或无法继续合并时停止。输入总词长不超过 $2.5\times10^5$、目标词表长度至多 5000。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406C)。

### 题解

直接每轮扫描所有单词会达到 $O(mL)$。把每个单词拆成双向链表节点，一个相邻对由其左节点唯一代表。按 `(左词编号,右词编号)` 保存所有出现位置的有序集合与频率之和；同一单词出现频率就是该位置的权重。

优先队列保存各词汇对的频率快照和版本号，按题目四级优先级排序。修改某对频率时增加版本号并压入新快照；取堆顶时丢弃过期版本。比较字典序时，前词长度已相同，可先比较前词再比较后词，不必为堆中的每个条目额外分配拼接字符串。

选定一对后，按左位置升序遍历其出现点。合并左节点 a 与右节点 b，只会改变“前驱→a、a→b、b→后继”三条旧相邻边，删除其计数后连接新节点，再加入两条新边。若重叠位置已被前一次合并删除，就跳过。例如 `a a a` 严格得到 `aa a`。

初始统计准确，局部更新覆盖全部改变的相邻关系，堆有效顶项即当前最佳词汇对，所以逐轮等价于题意。每次实际合并至少删除一个节点，全部合并次数 $O(L)$；忽略字符串比较及输出开销，时间 $O((L+m)\log(L+m))$，空间 $O(L+m)$。字符串内容另计词表总长度。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using i64 = long long;
struct TokenNode {
    int token, previous, next;
    i64 weight;
    bool alive = true;
};
struct PairInfo {
    int left, right, version = 0;
    i64 frequency = 0;
    set<int> positions;
};
struct Entry {
    i64 frequency;
    int pair, version;
};
vector<string> vocabulary;
vector<PairInfo> pairs;
struct Worse {
    bool operator()(const Entry &a, const Entry &b) const {
        if (a.frequency != b.frequency)
            return a.frequency < b.frequency;
        const auto &x = pairs[a.pair];
        const auto &y = pairs[b.pair];
        size_t ax = vocabulary[x.left].size(), ay = vocabulary[y.left].size(),
               bx = vocabulary[x.right].size(), by = vocabulary[y.right].size();
        if (ax + bx != ay + by)
            return ax + bx > ay + by;
        if (ax != ay)
            return ax > ay;
        int order = vocabulary[x.left].compare(vocabulary[y.left]);
        if (order)
            return order > 0;
        order = vocabulary[x.right].compare(vocabulary[y.right]);
        if (order)
            return order > 0;
        return a.pair > b.pair;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;
    vector<string> words(n);
    vector<i64> frequency(n);
    set<char> alphabet;
    for (int i = 0; i < n; ++i) {
        cin >> words[i] >> frequency[i];
        for (char c : words[i])
            alphabet.insert(c);
    }
    unordered_map<string, int> token_id;
    for (char c : alphabet) {
        string s(1, c);
        token_id[s] = vocabulary.size();
        vocabulary.push_back(s);
        cout << s << '\n';
    }
    vector<TokenNode> nodes;
    for (int i = 0; i < n; ++i) {
        int start = nodes.size();
        for (char c : words[i]) {
            int index = nodes.size();
            nodes.push_back({token_id[string(1, c)], index == start ? -1 : index - 1, index + 1,
                             frequency[i], true});
        }
        nodes.back().next = -1;
    }
    unordered_map<uint64_t, int> pair_id;
    priority_queue<Entry, vector<Entry>, Worse> heap;
    auto pair_index = [&](int left, int right) {
        uint64_t key = (uint64_t(left) << 32) | uint64_t(right);
        auto it = pair_id.find(key);
        if (it != pair_id.end())
            return it->second;
        int id = pairs.size();
        pairs.push_back({left, right, 0, 0, {}});
        pair_id[key] = id;
        return id;
    };
    auto change = [&](int position, int sign) {
        if (position < 0 || nodes[position].next < 0)
            return;
        int id = pair_index(nodes[position].token, nodes[nodes[position].next].token);
        auto &p = pairs[id];
        p.frequency += sign * nodes[position].weight;
        ++p.version;
        if (sign == 1)
            p.positions.insert(position);
        else
            p.positions.erase(position);
        if (p.frequency > 0)
            heap.push({p.frequency, id, p.version});
    };
    for (int i = 0; i < int(nodes.size()); ++i)
        change(i, 1);
    int printed = vocabulary.size();
    while (printed < target) {
        while (!heap.empty() && (heap.top().version != pairs[heap.top().pair].version ||
                                 pairs[heap.top().pair].frequency == 0))
            heap.pop();
        if (heap.empty())
            break;
        int chosen = heap.top().pair;
        heap.pop();
        int left_token = pairs[chosen].left, right_token = pairs[chosen].right;
        string joined = vocabulary[left_token] + vocabulary[right_token];
        cout << joined << '\n';
        ++printed;
        int new_token;
        auto it = token_id.find(joined);
        if (it == token_id.end()) {
            new_token = vocabulary.size();
            token_id[joined] = new_token;
            vocabulary.push_back(joined);
        } else
            new_token = it->second;
        vector<int> positions(pairs[chosen].positions.begin(), pairs[chosen].positions.end());
        for (int a : positions) {
            if (!nodes[a].alive || nodes[a].next < 0)
                continue;
            int b = nodes[a].next;
            if (nodes[a].token != left_token || nodes[b].token != right_token)
                continue;
            int before = nodes[a].previous, after = nodes[b].next;
            change(before, -1);
            change(a, -1);
            change(b, -1);
            nodes[a].token = new_token;
            nodes[a].next = after;
            nodes[b].alive = false;
            nodes[b].next = -1;
            if (after >= 0)
                nodes[after].previous = a;
            change(before, 1);
            change(a, 1);
        }
    }
}
```

<a id="problem-d"></a>

## D. 货物调度

标签：`分组背包` · `排序` · `动态规划`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

有 $n$ 个仓库、$m$ 件货物。启用仓库 $j$ 需付基本费 $b_j$，每卖一件还需付 $c_j$；货物 $i$ 的售价为 $a_i$，位于仓库 $t_i$。要求售价总和减费用总和至少为 $v$，求最小费用。输入 `n m v`，随后仓库的 `b c`，最后货物的 `a t`；仓库编号从 0 开始。$n,m\le1000,b_j,c_j\le20$，保证有解。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406D)。

### 题解

**先消除同仓库内部的组合选择。** 如果决定从某仓库卖 $k$ 件，其费用固定为 $b_j+kc_j$；选售价最高的 $k$ 件一定不会比其他选择差。将每个仓库的货物降序排列，前缀和给出每种件数的最优收入。

费用的上界很小：所有非空仓库基本费加上全部货物计件费不超过 $20n+20m\le40000$。定义 $dp[c]$ 为处理完若干仓库、恰好花费 $c$ 能取得的最大净收入。不可达状态设为负无穷，初始只有 $dp[0]=0$。

对一个仓库，先复制旧数组表示不启用。枚举选前 $k\ge1$ 件的方案，费用 $w=b_j+kc_j$，净收益 $s_k-w$，从旧数组更新

$$next[c+w]=\max(next[c+w],dp[c]+s_k-w).$$

一定从旧数组读状态，否则会重复选择同一个仓库的互斥方案。最后从小到大找到首个 $dp[c]\ge v$ 的费用。

每个合法方案可按仓库分组；同组固定件数时取最高售价不会增加成本。DP 穷尽每组的全部最优件数选项，所以得到指定费用下最大净收入，最后扫描就得到最小可行费用。时间 $O(C(n+m)+m\log m)$，空间 $O(C+n+m)$，$C\le40000$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, target;
    cin >> n >> m >> target;
    vector<int> basic(n), unit(n);
    vector<vector<int>> goods(n);
    for (int i = 0; i < n; ++i)
        cin >> basic[i] >> unit[i];
    for (int i = 0; i < m; ++i) {
        int value, warehouse;
        cin >> value >> warehouse;
        goods[warehouse].push_back(value);
    }
    int bound = 0;
    for (int i = 0; i < n; ++i)
        if (!goods[i].empty())
            bound += basic[i] + unit[i] * goods[i].size();
    const int NEG = -1000000000;
    vector<int> dp(bound + 1, NEG);
    dp[0] = 0;
    int previous_bound = 0;
    for (int i = 0; i < n; ++i) {
        if (goods[i].empty())
            continue;
        sort(goods[i].begin(), goods[i].end(), greater<int>());
        vector<int> next = dp;
        int value = 0;
        for (size_t k = 1; k <= goods[i].size(); ++k) {
            value += goods[i][k - 1];
            int cost = basic[i] + int(k) * unit[i];
            for (int old = 0; old <= previous_bound; ++old)
                if (dp[old] != NEG)
                    next[old + cost] = max(next[old + cost], dp[old] + value - cost);
        }
        previous_bound += basic[i] + unit[i] * goods[i].size();
        dp.swap(next);
    }
    for (int cost = 0; cost <= bound; ++cost)
        if (dp[cost] >= target) {
            cout << cost << '\n';
            return 0;
        }
}
```

<a id="problem-e"></a>

## E. 哥德尔机

标签：`二维区间` · `线段树` · `扫描线` · `静态查询`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 70 分 Time Exceeded（复刻评测）。

### 题意

先给 $n$ 个矩形学习操作，每个输入 `x1 x2 y1 y2 v`，把矩形内权值更新成原值与 $v$ 的最大值，初始为 0。全部学习结束后给 $m$ 个矩形查询，输出区域内最大权值。坐标和值均在 $1\ldots n$，$n,m\le5\times10^5$。这里所有修改先于所有查询，可利用静态预处理。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406E)。

### 题解

**先消去网格。** 查询答案等于所有与查询矩形有交集的学习矩形的最大权值。原因是任意格子的最终值来自覆盖它的某个矩形；反过来，两矩形只要有交点，对应修改值就能在查询区域中贡献。

**一维线段树分两种清单。** 在 $x$ 轴建线段树，插入修改的 $x$ 区间。递归访问的每个节点都把修改编号放入 `allIds`；被区间完全覆盖时另放入 `coverIds` 并停止下行。两张表每个矩形各占 $O(\log n)$ 记录。查询 $x$ 区间时：完全覆盖一个节点，查询其 `all`；部分覆盖时，查询其 `cover` 并继续递归。前者处理节点内所有修改，后者处理在祖先层已经停止下行的修改。任意相交的两个 $x$ 区间必在某层被这两种情况之一捕获。

**每张清单又是静态一维问题。** 忽略 $x$ 后，清单只剩带权 $y$ 区间，需要求与 $[c,d]$ 相交的区间最大权值。把各区间视为区间取最大修改，预先构造上包络。全局先按权值降序排列修改，所有清单自然继承此顺序；用有序区间集合记录已覆盖的位置，当前区间只给尚未覆盖的部分赋值，因为先覆盖的值一定更大。每个被删除的已覆盖段只会消失一次，新增分段总数与清单长度同阶。将所得分段排序，空隙补 0，建普通迭代线段树，查询先二分所在分段，再取区间最大值。短清单直接扫描，相同清单共用结果，外层使用紧凑节点编号；节点还保存权值上界，若不可能超过当前答案就停止搜索。这些优化仅减少常数，不改变最坏复杂度。

**正确性。** 外层清单分类恰好覆盖所有 $x$ 相交修改；内层上包络的区间最大值恰好筛选 $y$ 相交修改。两个方向同时相交等价于矩形相交，取最大得到答案。清单可能重复命中同一修改，但最大值操作不受重复影响。

**复杂度。** 总记录量 $O(n\log n)$，排序与包络预处理 $O(n\log^2 n)$；每个查询 $O(\log^2 n)$，空间 $O(n\log n)$。本题最大数据对常数和内存敏感，理论复杂度不能代替目标评测机上的时间验证。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
struct Rect {
    int xl, xr, yl, yr, value;
};
vector<Rect> rectangles;
// Static upper envelope of weighted closed intervals, with range maximum queries.
struct Envelope {
    vector<int> coordinates, maximum;
    int base = 0;
    void build(vector<int> ids) {
        if (ids.empty())
            return;
        if (ids.size() <= 8) {
            coordinates = std::move(ids);
            base = -1;
            return;
        }
        // IDs arrive in decreasing value order. Paint only uncovered positions.
        struct Piece {
            int l, r, value;
        };
        vector<Piece> pieces;
        map<int, int> covered;
        for (int id : ids) {
            auto rect = rectangles[id];
            int l = rect.yl, r = rect.yr;
            auto it = covered.upper_bound(l);
            if (it != covered.begin()) {
                auto previous = prev(it);
                if (previous->second >= l - 1) {
                    if (previous->second >= r)
                        continue;
                    it = previous;
                }
            }
            int begin = l, end = r, cursor = l;
            while (it != covered.end() && it->first <= r + 1) {
                if (cursor < it->first && cursor <= r)
                    pieces.push_back({cursor, min(r, it->first - 1), rect.value});
                cursor = max(cursor, it->second + 1);
                begin = min(begin, it->first);
                end = max(end, it->second);
                it = covered.erase(it);
            }
            if (cursor <= r)
                pieces.push_back({cursor, r, rect.value});
            covered.emplace(begin, end);
        }
        sort(pieces.begin(), pieces.end(), [](Piece a, Piece b) { return a.l < b.l; });
        vector<int> values;
        for (auto p : pieces) {
            if (!coordinates.empty() && coordinates.back() == p.l)
                values.back() = p.value;
            else {
                coordinates.push_back(p.l);
                values.push_back(p.value);
            }
            coordinates.push_back(p.r + 1);
            values.push_back(0);
        }
        base = coordinates.size();
        maximum.assign(2 * base, 0);
        copy(values.begin(), values.end(), maximum.begin() + base);
        for (int i = base - 1; i; --i)
            maximum[i] = max(maximum[2 * i], maximum[2 * i + 1]);
    }
    int query(int l, int r) const {
        if (base == -1) {
            int ans = 0;
            for (int id : coordinates) {
                auto a = rectangles[id];
                if (a.yl <= r && a.yr >= l)
                    ans = max(ans, a.value);
            }
            return ans;
        }
        if (!base || r < coordinates.front())
            return 0;
        int a = max(
            0,
            int(upper_bound(coordinates.begin(), coordinates.end(), l) - coordinates.begin()) - 1);
        int b = int(upper_bound(coordinates.begin(), coordinates.end(), r) - coordinates.begin());
        int ans = 0;
        for (a += base, b += base; a < b; a >>= 1, b >>= 1) {
            if (a & 1)
                ans = max(ans, maximum[a++]);
            if (b & 1)
                ans = max(ans, maximum[--b]);
        }
        return ans;
    }
};
struct Node {
    vector<int> allIds, coverIds;
    Envelope all, cover;
    int bound = 0;
    bool same = false;
};
vector<Node> tree;
void add(int u, int l, int r, int id) {
    const auto &a = rectangles[id];
    tree[u].allIds.push_back(id);
    if (a.xl <= l && r <= a.xr) {
        tree[u].coverIds.push_back(id);
        return;
    }
    int mid = (l + r) / 2;
    if (a.xl <= mid)
        add(u + 1, l, mid, id);
    if (a.xr > mid)
        add(u + 2 * (mid - l + 1), mid + 1, r, id);
}
int query(int u, int l, int r, int a, int b, int c, int d, int known = 0) {
    if (tree[u].bound <= known)
        return known;
    if (a <= l && r <= b)
        return max(known, (tree[u].same ? tree[u].cover : tree[u].all).query(c, d));
    int ans = tree[u].cover.query(c, d), mid = (l + r) / 2;
    ans = max(ans, known);
    if (a <= mid)
        ans = max(ans, query(u + 1, l, mid, a, b, c, d, ans));
    if (b > mid)
        ans = max(ans, query(u + 2 * (mid - l + 1), mid + 1, r, a, b, c, d, ans));
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    rectangles.resize(n);
    tree.resize(2 * n + 2);
    for (auto &r : rectangles)
        cin >> r.xl >> r.xr >> r.yl >> r.yr >> r.value;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [](int a, int b) { return rectangles[a].value > rectangles[b].value; });
    for (int i : order)
        add(1, 1, n, i);
    for (auto &node : tree) {
        node.bound = node.allIds.empty() ? 0 : rectangles[node.allIds[0]].value;
        node.same = node.allIds == node.coverIds;
        if (!node.same)
            node.all.build(std::move(node.allIds));
        else
            vector<int>().swap(node.allIds);
        node.cover.build(std::move(node.coverIds));
    }
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << query(1, 1, n, a, b, c, d) << '\n';
    }
}
```
