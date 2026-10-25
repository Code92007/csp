---
title: "CSP 202406 五题题解"
contest: "202406"
contest_month: "2024-06"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "矩阵重塑", "线性下标", "数组", "矩阵变换", "模拟", "BPE", "链表", "优先队列", "字符串", "分组背包", "排序", "动态规划", "二维区间", "线段树", "扫描线", "静态查询"]
status: "published"
problems: [{"id": "A", "title": "矩阵重塑（其一）", "tags": ["矩阵重塑", "线性下标"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81ca67df0b81749bb2f"}}, {"id": "B", "title": "矩阵重塑（其二）", "tags": ["数组", "矩阵变换", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81da67df0b81749bb39"}}, {"id": "C", "title": "文本分词", "tags": ["BPE", "链表", "优先队列", "字符串"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；130 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81fa67df0b81749bb49"}}, {"id": "D", "title": "货物调度", "tags": ["分组背包", "排序", "动态规划"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce821a67df0b81749bb75"}}, {"id": "E", "title": "哥德尔机", "tags": ["二维区间", "线段树", "扫描线", "静态查询"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17/C++20 编译通过；2 个保存样例通过；600 组独立朴素对拍和 6 组 50 万规模压力测试通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addaa6774ace1cba9a1ff5b"}}]
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

状态：**完整实现，曙梦 OJ 已验证满分**。C++17/C++20 编译通过；2 个保存样例通过；600 组独立朴素对拍和 6 组 50 万规模压力测试通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addaa6774ace1cba9a1ff5b)（复刻评测）。

### 题意

先给 $n$ 个矩形学习操作，每个输入 `x1 x2 y1 y2 v`，把矩形内权值更新成原值与 $v$ 的最大值，初始为 0。全部学习结束后给 $m$ 个矩形查询，输出区域内最大权值。坐标和值均在 $1\ldots n$，$n,m\le5\times10^5$。这里所有修改先于所有查询，可利用静态预处理。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406E)。

### 题解

**先消去网格。** 查询答案等于所有与查询矩形有交集的学习矩形的最大权值。任意格子的最终值来自覆盖它的学习矩形；反过来，两矩形只要有交点，该学习值就能在查询区域中贡献。

**外层线段树只保存完全覆盖清单。** 在 $x$ 轴建线段树，将每个学习矩形的 $x$ 区间拆成 $O(\log n)$ 个互不相交的标准节点，把编号加入各节点的 `cover` 清单。先按权值降序处理矩形，各清单自然也是降序。先统计长度、求前缀和，再用连续数组存放所有清单，减少小块内存分配。

**把一张清单变成一维上包络。** 只看各矩形的 $y$ 区间，将左端点、右端点加一离散化，形成基本半开区间。按权值降序涂色，并查集的 `next` 指针跳过已涂色位置，每段只在首次遇到时赋值，因此得到逐点最大权值。合并相邻同值段，保存断点和每段值，并建立静态区间最大值树；查询时先二分定位，再做范围最大值查询。最后一个断点保存值 0，表示所有区间结束。

**自底向上合并 `all` 包络。** 节点的 `all` 表示停在本节点或后代的全部修改，等于本节点 `cover`、左子树 `all`、右子树 `all` 的逐点最大值。三张包络的断点均有序，三路归并即可线性合并，不必重新排序或进行有序集合插入。合并结果若与已有包络相同，直接共用；所有包络的断点与最大值树统一放入连续数组。

**如何查询。** 查询的 $x$ 区间完全包含当前节点时，在 `all` 上查询 $y$ 范围；部分相交时，先查本节点 `cover`，再访问相交的孩子。若包络的全局最高值已经不超过当前答案，可以跳过；两个孩子优先访问上界较大的一个。矩形相交关于 $x,y$ 对称，预先统计两个轴各自的标准节点记录数，以较少的轴作为外层，查询同步交换坐标即可。

**正确性。** 任一学习矩形在外层被分成若干标准节点。它与查询的 $x$ 区间相交时，查询必定到达其某个存储节点，或完全包含该节点的祖先：前者由 `cover` 捕获，后者由 `all` 捕获。内层包络在查询 $y$ 区间的最大值，正是与该区间相交的修改最大值。两个轴同时相交等价于矩形相交；重复命中不会改变最大值。

**复杂度。** 每个矩形的标准节点及其祖先共 $O(\log n)$ 个，所有清单与包络总规模 $O(n\log n)$。排序、离散化和包络构造共 $O(n\log^2 n)$，$m$ 次查询共 $O(m\log^2 n)$，空间 $O(n\log n)$。

原版曙梦 OJ 为 [70 分超时](https://oj.shumeng.tech/record/6adce823a67df0b81749bb8a)。本机 50 万修改、50 万查询的随机矩形由 4.530 秒降至 1.148 秒，横线条构造由 11.706 秒降至 0.420 秒；测得点矩形构造峰值内存约 262 MiB。此处仅用于同机对比。复核入口：[优化回归脚本](../tests/optimized_regressions.py)、[验证报告](../tests/optimization-report.json)。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class FastInput {
    static constexpr int SIZE = 1 << 16;
    char buffer[SIZE];
    int at = 0, length = 0;
    int next() {
        if (at == length) {
            length = int(fread(buffer, 1, SIZE, stdin));
            at = 0;
            if (!length) return EOF;
        }
        return buffer[at++];
    }
public:
    int read() {
        int c = next();
        while (c <= ' ' && c != EOF) c = next();
        int x = 0;
        while ('0' <= c && c <= '9') {
            x = x * 10 + c - '0';
            c = next();
        }
        return x;
    }
};
struct Rectangle { int xl, xr, yl, yr, value; };
vector<Rectangle> rectangles;

// Each envelope occupies [coordinates, iterative range-maximum tree] in one arena.
vector<int> arena;
struct Envelope {
    int offset = 0, size = 0;
    int coordinate(int i) const { return arena[offset + i]; }
    int value(int i) const { return arena[offset + 2 * size + i]; }
    int bound() const { return size ? arena[offset + size + 1] : 0; }
    int query(int l, int r) const {
        if (!size || r < coordinate(0) || l >= coordinate(size - 1)) return 0;
        auto begin = arena.begin() + offset;
        int a = max(0, int(upper_bound(begin, begin + size, l) - begin) - 1);
        int b = int(upper_bound(begin, begin + size, r) - begin);
        int answer = 0, tree = offset + size;
        for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
            if (a & 1) answer = max(answer, arena[tree + a++]);
            if (b & 1) answer = max(answer, arena[tree + --b]);
        }
        return answer;
    }
};
struct Node { Envelope cover, all; };
vector<Node> nodes;

Envelope saveEnvelope(const vector<int> &coordinates, const vector<int> &values) {
    int size = int(coordinates.size()), offset = int(arena.size());
    if (!size) return {};
    arena.resize(offset + 3 * size);
    copy(coordinates.begin(), coordinates.end(), arena.begin() + offset);
    copy(values.begin(), values.end(), arena.begin() + offset + 2 * size);
    int tree = offset + size;
    for (int i = size - 1; i; --i)
        arena[tree + i] = max(arena[tree + 2 * i], arena[tree + 2 * i + 1]);
    return {offset, size};
}
int findNext(vector<int> &next, int x) {
    while (next[x] != x) {
        next[x] = next[next[x]];
        x = next[x];
    }
    return x;
}
Envelope buildCover(const vector<int> &ids, int first, int last) {
    if (first == last) return {};
    if (last - first == 1) {
        const auto &a = rectangles[ids[first]];
        return saveEnvelope({a.yl, a.yr + 1}, {a.value, 0});
    }
    vector<int> coordinates;
    coordinates.reserve(2 * (last - first));
    for (int i = first; i < last; ++i) {
        const auto &a = rectangles[ids[i]];
        coordinates.push_back(a.yl);
        coordinates.push_back(a.yr + 1);
    }
    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
    int size = int(coordinates.size());
    vector<int> next(size + 1), values(size);
    iota(next.begin(), next.end(), 0);
    // IDs are in decreasing weight order: each elementary interval is painted once.
    for (int i = first; i < last; ++i) {
        const auto &a = rectangles[ids[i]];
        int l = int(lower_bound(coordinates.begin(), coordinates.end(), a.yl) - coordinates.begin());
        int r = int(lower_bound(coordinates.begin(), coordinates.end(), a.yr + 1) - coordinates.begin());
        for (int p = findNext(next, l); p < r; p = findNext(next, p)) {
            values[p] = a.value;
            next[p] = findNext(next, p + 1);
        }
    }
    int written = 0, previous = 0;
    for (int i = 0; i < size; ++i)
        if (values[i] != previous) {
            previous = values[i];
            coordinates[written] = coordinates[i];
            values[written++] = previous;
        }
    coordinates.resize(written);
    values.resize(written);
    return saveEnvelope(coordinates, values);
}

Envelope mergeEnvelopes(Envelope a, Envelope b, Envelope c) {
    Envelope inputs[3] = {a, b, c};
    int nonempty = 0, single = 0;
    for (int i = 0; i < 3; ++i) if (inputs[i].size) ++nonempty, single = i;
    if (!nonempty) return {};
    if (nonempty == 1) return inputs[single];
    int at[3] = {}, current[3] = {}, previous = 0;
    vector<int> coordinates, values;
    int total = a.size + b.size + c.size;
    coordinates.reserve(total);
    values.reserve(total);
    while (true) {
        int x = 1000000000;
        for (int i = 0; i < 3; ++i)
            if (at[i] < inputs[i].size) x = min(x, inputs[i].coordinate(at[i]));
        if (x == 1000000000) break;
        for (int i = 0; i < 3; ++i)
            if (at[i] < inputs[i].size && inputs[i].coordinate(at[i]) == x)
                current[i] = inputs[i].value(at[i]++);
        int value = max(current[0], max(current[1], current[2]));
        if (value != previous) {
            coordinates.push_back(x);
            values.push_back(value);
            previous = value;
        }
    }
    // A dominating child or cover can be shared without another stored copy.
    for (Envelope old : inputs) {
        if (old.size != int(coordinates.size())) continue;
        bool equal = true;
        for (int i = 0; i < old.size && equal; ++i)
            equal = old.coordinate(i) == coordinates[i] && old.value(i) == values[i];
        if (equal) return old;
    }
    return saveEnvelope(coordinates, values);
}

int query(int node, int left, int right, int a, int b, int c, int d, int known) {
    if (nodes[node].all.bound() <= known) return known;
    if (a <= left && right <= b) return max(known, nodes[node].all.query(c, d));
    if (nodes[node].cover.bound() > known) known = max(known, nodes[node].cover.query(c, d));
    int middle = (left + right) / 2;
    bool useLeft = a <= middle, useRight = b > middle;
    if (useLeft && useRight) {
        if (nodes[2 * node].all.bound() >= nodes[2 * node + 1].all.bound()) {
            known = query(2 * node, left, middle, a, b, c, d, known);
            known = query(2 * node + 1, middle + 1, right, a, b, c, d, known);
        } else {
            known = query(2 * node + 1, middle + 1, right, a, b, c, d, known);
            known = query(2 * node, left, middle, a, b, c, d, known);
        }
    } else if (useLeft) {
        known = query(2 * node, left, middle, a, b, c, d, known);
    } else {
        known = query(2 * node + 1, middle + 1, right, a, b, c, d, known);
    }
    return known;
}

int main() {
    FastInput input;
    int n = input.read(), m = input.read(), base = 1, height = 0;
    if (!n) return 0;
    while (base < n) base <<= 1, ++height;
    rectangles.resize(n);
    nodes.resize(2 * base);
    vector<int> order(n), starts(2 * base + 1);
    iota(order.begin(), order.end(), 0);
    long long xRecords = 0, yRecords = 0;
    auto records = [base](int a, int b) {
        int answer = 0;
        for (int l = a + base - 1, r = b + base; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ++answer, ++l;
            if (r & 1) ++answer, --r;
        }
        return answer;
    };
    for (auto &a : rectangles) {
        a.xl = input.read(); a.xr = input.read();
        a.yl = input.read(); a.yr = input.read(); a.value = input.read();
        xRecords += records(a.xl, a.xr);
        yRecords += records(a.yl, a.yr);
    }
    // Either axis is valid. Use the one with fewer canonical insertion records.
    bool swapped = yRecords < xRecords;
    for (auto &a : rectangles) {
        if (swapped) swap(a.xl, a.yl), swap(a.xr, a.yr);
        for (int l = a.xl + base - 1, r = a.xr + base; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ++starts[l++ + 1];
            if (r & 1) ++starts[--r + 1];
        }
    }
    for (int i = 1; i <= 2 * base; ++i) starts[i] += starts[i - 1];
    vector<int> ids(starts.back()), cursor = starts;
    sort(order.begin(), order.end(), [](int a, int b) {
        return rectangles[a].value > rectangles[b].value;
    });
    for (int id : order) {
        const auto &a = rectangles[id];
        for (int l = a.xl + base - 1, r = a.xr + base; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ids[cursor[l]++] = id, ++l;
            if (r & 1) --r, ids[cursor[r]++] = id;
        }
    }
    vector<int>().swap(cursor);
    vector<int>().swap(order);
    // Reserve once to avoid a large old/new-buffer peak during arena growth.
    arena.reserve(size_t(6) * n * (height + 1));
    for (int u = 2 * base - 1; u; --u) {
        nodes[u].cover = buildCover(ids, starts[u], starts[u + 1]);
        nodes[u].all = u >= base ? nodes[u].cover :
            mergeEnvelopes(nodes[u].cover, nodes[2 * u].all, nodes[2 * u + 1].all);
    }
    vector<int>().swap(ids);
    vector<int>().swap(starts);
    vector<Rectangle>().swap(rectangles);
    string output;
    output.reserve(m * 8);
    while (m--) {
        int a = input.read(), b = input.read(), c = input.read(), d = input.read();
        if (swapped) swap(a, c), swap(b, d);
        output += to_string(query(1, 1, base, a, b, c, d, 0));
        output.push_back('\n');
    }
    fwrite(output.data(), 1, output.size(), stdout);
}
```
