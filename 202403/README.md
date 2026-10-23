---
title: "CSP 202403 五题题解"
contest: "202403"
contest_month: "2024-03"
date: "2026-10-23"
updated: "2026-10-24"
tags: ["CSP", "计数", "时间戳", "集合", "哈希", "大小写转换", "字符串解析", "线性代数", "高斯消元", "模运算", "模拟", "双向链表", "优先队列", "树", "链表", "DFS序", "树状数组"]
status: "published"
problems: [{"id": "A", "title": "词频统计", "tags": ["计数", "时间戳"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403A/"}]}, {"id": "B", "title": "相似度计算", "tags": ["集合", "哈希", "大小写转换"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；4 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403B/"}]}, {"id": "C", "title": "化学方程式配平", "tags": ["字符串解析", "线性代数", "高斯消元", "模运算"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；110 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403C/"}]}, {"id": "D", "title": "十滴水", "tags": ["模拟", "双向链表", "优先队列"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；120 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403D/"}]}, {"id": "E", "title": "文件夹合并", "tags": ["树", "链表", "DFS序", "树状数组"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403E/"}]}]
---

# CSP 202403 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 词频统计

标签：`计数` · `时间戳`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

n篇文章由1…m的单词编号表示。对每个词输出出现的文章数和总出现次数，同篇多次出现只贡献一个文章数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403A/)。

### 题解

为每个词保存total、articles和last三项。每读到一次词就增加total；只有last不是当前文章编号时才增加articles，并更新last。

last标记该词在当前文章是否已经计过，避免为每篇文章清空整个去重数组。两个计数分别统计全部出现和每篇首次出现，准确符合定义。时间 $O(总词数+m)$，空间 $O(m)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> articles(m + 1), total(m + 1), last(m + 1);
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        while (l--) {
            int word;
            cin >> word;
            ++total[word];
            if (last[word] != i) {
                ++articles[word];
                last[word] = i;
            }
        }
    }
    for (int i = 1; i <= m; i++)
        cout << articles[i] << ' ' << total[i] << '\n';
}
```

<a id="problem-b"></a>

## B. 相似度计算

标签：`集合` · `哈希` · `大小写转换`

状态：**已实现**。C++17 编译通过；4 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

两篇文章各由一列英文单词组成。忽略大小写、各自去重后，输出两个单词集合的交集大小和并集大小。存档加强范围每篇可达 $5\times10^5$ 个单词。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403B/)。

### 题解

把所有单词统一转小写，分别插入两个 unordered_set。枚举第一集合，统计也在第二集合中的单词数 I；并集大小由容斥为 |A|+|B|-I。

集合插入自动去掉同篇重复词，统一大小写保证比较规则一致；交集统计每个不同词一次，容斥只消除重复计算部分。期望时间为输入总字符数的线性量，空间为不同单词的总长度。只输出两个整数，不计算相似度小数。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
string lower(string s) {
    for (char &c : s)
        c = tolower(static_cast<unsigned char>(c));
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    unordered_set<string> a, b;
    string s;
    while (n--) {
        cin >> s;
        a.insert(lower(s));
    }
    while (m--) {
        cin >> s;
        b.insert(lower(s));
    }
    size_t common = 0;
    for (auto &s : a)
        common += b.count(s);
    cout << common << '\n' << a.size() + b.size() - common << '\n';
}
```

<a id="problem-c"></a>

## C. 化学方程式配平

标签：`字符串解析` · `线性代数` · `高斯消元` · `模运算`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；110 组独立随机对拍通过；未提交正式评测。

### 题意

输入若干组物质化学式，每种物质由小写元素名及其原子数组成，不含括号，数字 1 不省略。判断把物质系数当作未知数得到的齐次线性方程组是否存在非零解，输出 Y/N。允许某些系数为零，不要求全部为正。每组物质和元素均不超过 40 种，原子数不超过 50。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403C/)。

### 题解

每个元素一行、每种物质一列，矩阵项就是原子数。设物质数为 m，齐次方程存在非零解当且仅当矩阵秩小于 m；如果元素数少于 m，直接成立。

本实现使用模素数高斯消元，且用明确的整数界保证判定，而非只取一个模数猜测。对 12 个不同且大于 $10^9$ 的素数求秩；任何一个模数下满列秩，都证明某个整数子式不为零，输出 N。

如果 12 个模数下全都不满秩，则每个 m 阶子式都被这 12 个素数整除。另一方面，Hadamard 不等式给出子式绝对值至多 $(50\sqrt m)^m\le(50\sqrt{40})^{40}<10^{101}$；12 个素数的乘积超过 $10^{108}$。一个绝对值比乘积小、又被乘积整除的整数只能为零。因此所有子式均为零，输出 Y 是确定正确的。

每轮消元找非零主元，乘模逆元归一化，再消去下方元素。时间 $O(12em\min(e,m))$，空间 $O(em)$，另加一次小规模素数预处理。这个判定只回答题目定义的线性相关性，不能把它解释成每种物质都参与的实际化学反应。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using i64 = long long;
i64 power(i64 x, i64 e, i64 mod) {
    i64 result = 1;
    while (e) {
        if (e & 1)
            result = result * x % mod;
        x = x * x % mod;
        e /= 2;
    }
    return result;
}
int rank_mod(vector<vector<i64>> a, i64 mod) {
    int rows = a.size(), columns = a[0].size(), rank = 0;
    for (int c = 0; c < columns && rank < rows; ++c) {
        int pivot = rank;
        while (pivot < rows && a[pivot][c] == 0)
            ++pivot;
        if (pivot == rows)
            continue;
        swap(a[pivot], a[rank]);
        i64 inverse = power(a[rank][c], mod - 2, mod);
        for (int j = c; j < columns; ++j)
            a[rank][j] = a[rank][j] * inverse % mod;
        for (int i = rank + 1; i < rows; ++i)
            if (a[i][c]) {
                i64 factor = a[i][c];
                for (int j = c; j < columns; ++j)
                    a[i][j] = (a[i][j] - factor * a[rank][j] % mod + mod) % mod;
            }
        ++rank;
    }
    return rank;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<i64> primes;
    for (i64 value = 1000000007; primes.size() < 12; value += 2) {
        bool prime = true;
        for (i64 d = 3; d * d <= value; d += 2)
            if (value % d == 0) {
                prime = false;
                break;
            }
        if (prime)
            primes.push_back(value);
    }
    int tests;
    cin >> tests;
    while (tests--) {
        int m;
        cin >> m;
        map<string, int> row;
        vector<vector<i64>> matrix;
        for (int c = 0; c < m; ++c) {
            string s;
            cin >> s;
            size_t i = 0;
            while (i < s.size()) {
                size_t begin = i;
                while (i < s.size() && islower(static_cast<unsigned char>(s[i])))
                    ++i;
                string element = s.substr(begin, i - begin);
                int number = 0;
                while (i < s.size() && isdigit(static_cast<unsigned char>(s[i])))
                    number = number * 10 + s[i++] - '0';
                auto it = row.find(element);
                int r;
                if (it == row.end()) {
                    r = row.size();
                    row[element] = r;
                    matrix.push_back(vector<i64>(m));
                } else
                    r = it->second;
                matrix[r][c] = number;
            }
        }
        bool dependent = true;
        if (matrix.size() >= size_t(m))
            for (i64 p : primes)
                if (rank_mod(matrix, p) == m) {
                    dependent = false;
                    break;
                }
        cout << (dependent ? 'Y' : 'N') << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 十滴水

标签：`模拟` · `双向链表` · `优先队列`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；120 组独立随机对拍通过；未提交正式评测。

### 题意

一维格子中最初有 $m$ 个位置含 1 到 4 滴水。每次向一个当前有水的位置加一滴；水量达到 5 的格子会爆开、清空，并让左右最近的有水格子各加一滴。多个位置待爆时，始终先爆最左边的，包括连锁反应中新产生的位置。每次操作后输出剩余有水格子数。输入 `c m n`、$m$ 个 `位置 水量`、$n$ 个操作位置；$c\le10^9,m\le3\times10^5,n\le4m$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403D/)。

### 题解

**空格子以后不会重新有水。** 加水操作只指定已有水的格子，爆炸也只给最近的有水格子加水。因此位置集合只会删除，可以先按坐标排序，再用两个数组保存存活格子的左邻居、右邻居，构成双向链表。爆炸时摘掉当前节点，将两个邻居接起来即可。

待爆位置存入小根堆，堆顶始终是当前最左的待爆格子。加水时只在水量从 4 变成 5 的一刻入堆；继续变成 6、7 不再入堆，保证每个格子只排队一次。取出后先记住左右邻居，再删除当前格子，最后同时向这两个邻居加水。新到达 5 的格子加入同一个堆，下次重新取最左者，不能用普通 FIFO 队列代替。

输入操作位置通过排序数组二分定位；数组中的坐标始终保留，只修改水量和链表指针。题目保证操作位置当时有水。

链表始终表示当前存活位置的顺序，堆始终包含所有待爆位置，故每一步与规定的游戏过程完全一致。每个格子最多爆一次，总时间 $O((m+n)\log m)$，空间 $O(m)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int width, m, n;
    cin >> width >> m >> n;
    vector<pair<int, int>> cells(m);
    for (auto &[x, water] : cells)
        cin >> x >> water;
    sort(cells.begin(), cells.end());
    vector<int> left(m), right(m);
    for (int i = 0; i < m; ++i) {
        left[i] = i - 1;
        right[i] = i + 1;
    }
    priority_queue<int, vector<int>, greater<int>> ready;
    auto add = [&](int u) {
        if (u >= 0 && u < m && ++cells[u].second == 5)
            ready.push(u);
    };
    int alive = m;
    while (n--) {
        int position;
        cin >> position;
        int u =
            lower_bound(cells.begin(), cells.end(), pair<int, int>{position, -1}) - cells.begin();
        add(u);
        while (!ready.empty()) {
            int x = ready.top();
            ready.pop();
            int l = left[x], r = right[x];
            if (l >= 0)
                right[l] = r;
            if (r < m)
                left[r] = l;
            cells[x].second = 0;
            --alive;
            add(l);
            add(r);
        }
        cout << alive << '\n';
    }
}
```

<a id="problem-e"></a>

## E. 文件夹合并

标签：`树` · `链表` · `DFS序` · `树状数组`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

根为 1 的文件夹树，每个文件夹有自己的数据量。合并 `1 x` 删除 $x$ 当前的所有直接子文件夹，将它们的数据加给 $x$，其子文件夹提升为 $x$ 的直接子文件夹；输出新子文件夹数和 $x$ 的数据量。访问 `2 z` 输出从根到 $z$ 的存活文件夹数。操作目标保证仍存活。输入 `n m`、2 到 $n$ 的父亲、各点数据量、操作；$n\le5\times10^5$，$m\le3n$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403E/)

### 题解

**子文件夹用链表整段拼接。** 每个点保存当前孩子链表的头尾和孩子数。合并 $x$ 时先取走旧孩子链表，再逐个删除旧孩子 $y$，把 $y$ 的整条孩子链表接入新表。拼接只修改头尾指针，不逐个重设孙子的父亲。注意不能把刚提升的孙子也在同一次操作中删除，所以代码会保存旧表的 `following` 再拼接。每个点至多被删除一次，总遍历量为 $O(n)$。

**访问路径沿用原树。** 节点被删除后只是从祖先路径中跳过，存活点的原始祖先关系没有改变。预处理原树 DFS 序，$y$ 的所有后代构成连续区间 $[tin_y,tout_y]$。删除 $y$，就在这个区间上减一；访问 $z$ 的答案是原深度（根深度为 1）加上 $tin_z$ 处的累计改变量。

树状数组实现“区间加、单点查”：区间左端加 $-1$，右端后一位加 $1$。单点查取前缀和。被删点本身也在区间内没有问题，因为题目不会再询问它。

**正确性。** 链表精确完成一层合并，每个被删除祖先恰好对其后代扣掉一次访问次数，故两种输出分别符合定义。**复杂度：** $O((n+m)\log n)$ 时间、$O(n)$ 空间。数据量之和可能超过 32 位，使用 `long long`；DFS 使用显式栈。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> original(n + 1);
    vector<int> head(n + 1), tail(n + 1), next(n + 1), count(n + 1), depth(n + 1), tin(n + 1),
        tout(n + 1), bit(n + 2);
    auto append = [&](int u, int a, int b) {
        if (!a)
            return;
        if (tail[u])
            next[tail[u]] = a;
        else
            head[u] = a;
        tail[u] = b;
    };
    for (int i = 2, p; i <= n; ++i) {
        cin >> p;
        original[p].push_back(i);
        append(p, i, i);
        ++count[p];
    }
    vector<long long> data(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> data[i];
    int timer = 0;
    depth[1] = 1;
    vector<pair<int, bool>> stack{{1, false}};
    while (!stack.empty()) {
        auto [u, exit] = stack.back();
        stack.pop_back();
        if (exit) {
            tout[u] = timer;
            continue;
        }
        tin[u] = ++timer;
        stack.push_back({u, true});
        for (int v : original[u]) {
            depth[v] = depth[u] + 1;
            stack.push_back({v, false});
        }
    }
    auto add = [&](int x, int d) {
        for (; x <= n; x += x & -x)
            bit[x] += d;
    };
    while (m--) {
        int op, u;
        cin >> op >> u;
        if (op == 2) {
            int d = depth[u];
            for (int x = tin[u]; x; x -= x & -x)
                d += bit[x];
            cout << d << '\n';
        } else {
            // Save the old list before appending grandchildren: delete only one level.
            int v = head[u];
            head[u] = tail[u] = count[u] = 0;
            while (v) {
                int following = next[v];
                next[v] = 0;
                data[u] += data[v];
                append(u, head[v], tail[v]);
                count[u] += count[v];
                add(tin[v], -1);
                add(tout[v] + 1, 1);
                v = following;
            }
            cout << count[u] << ' ' << data[u] << '\n';
        }
    }
}
```
