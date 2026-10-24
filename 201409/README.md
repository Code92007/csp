---
title: "CSP 201409 五题题解"
contest: "201409"
contest_month: "2014-09"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "集合", "计数", "网格覆盖", "面积并", "字符串匹配", "大小写转换", "多源BFS", "最短路", "网格", "轮廓线DP", "状态压缩", "矩阵快速幂"]
status: "published"
problems: [{"id": "A", "title": "相邻数对", "tags": ["集合", "计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409A/"}]}, {"id": "B", "title": "画图", "tags": ["网格覆盖", "面积并"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409B/"}]}, {"id": "C", "title": "字符串匹配", "tags": ["字符串匹配", "大小写转换"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409C/"}]}, {"id": "D", "title": "最优配餐", "tags": ["多源BFS", "最短路", "网格"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409D/"}]}, {"id": "E", "title": "拼图", "tags": ["轮廓线DP", "状态压缩", "矩阵快速幂"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409E/"}]}]
---

# CSP 201409 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 相邻数对

标签：`集合` · `计数`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

给n个互不相同的非负整数，求值恰好相差1的无序数对数量。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409A/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409A)。

### 题解

把所有数放入集合，枚举x，只检查x+1是否存在，存在就加一。不再检查x-1，避免同一对被计算两次。

每个合法数对唯一由较小的那个数代表，因此不重不漏。set实现时间 $O(n\log n)$，空间 $O(n)$；这里“相邻”指值相邻，不是输入位置相邻。

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
        answer += a.count(x + 1);
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 画图

标签：`网格覆盖` · `面积并`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

在整数坐标纸上涂若干轴对齐矩形，重叠部分只计一次，求总涂色面积。坐标范围0…100，矩形数≤100。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409B/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409B)。

### 题解

用布尔数组表示单位小方格：paint[x][y]代表[x,x+1]×[y,y+1]。矩形(x1,y1,x2,y2)覆盖的格子下标为x1≤x<x2、y1≤y<y2，逐格置true，最后数true个数。

整数边界矩形恰好由这些单位格组成，布尔值使重叠格只计一次，因此数量就是并集面积。右上界必须用严格小于，不能把顶点数当成面积。时间 $O(nV^2)$，空间 $O(V^2)$，V=100。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool paint[100][100] = {};
    while (n--) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        for (int i = x; i < xx; i++)
            for (int j = y; j < yy; j++)
                paint[i][j] = true;
    }
    int answer = 0;
    for (auto &r : paint)
        for (bool v : r)
            answer += v;
    cout << answer << '\n';
}
```

<a id="problem-c"></a>

## C. 字符串匹配

标签：`字符串匹配` · `大小写转换`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

给定模式串、大小写敏感开关和 n 个字符串，按原顺序输出含有模式串的字符串。开关为 0 时忽略大小写，为 1 时严格区分。每串长度至多 100。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409C/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409C)。

### 题解

敏感模式直接查找子串；不敏感模式把模式和待匹配字符串的副本统一转小写，再用 find 查找。始终输出原字符串，不能输出转换后的副本。

大小写折叠后同一字母的两种形式映射到相同字符，因此子串匹配等价于题目定义。最坏时间 $O(nLM)$，L 为文本长、M 为模式长；额外空间 $O(L+M)$，本题范围无需额外实现 KMP。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
string lower(string s) {
    for (char &c : s)
        c = tolower(static_cast<unsigned char>(c));
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string pattern, line;
    int sensitive, n;
    cin >> pattern >> sensitive >> n;
    if (!sensitive)
        pattern = lower(pattern);
    while (n--) {
        cin >> line;
        string key = sensitive ? line : lower(line);
        if (key.find(pattern) != string::npos)
            cout << line << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 最优配餐

标签：`多源BFS` · `最短路` · `网格`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。

### 题意

n×n 网格中有若干餐厅、若干客户与不可经过的位置。每家餐厅供餐量无限，配送一份餐每走一格花费 1。客户可位于同一坐标，保证可送达。输入 n,m,k,d，依次是餐厅位置、客户位置和订餐量、障碍位置。求最低总费用，$n\le1000$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409D/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409D)。

### 题解

每个客户都独立选择最近餐厅即可，因为餐厅没有容量限制，不存在客户之间争用资源的问题。答案为每个位置的订餐量乘它到最近餐厅的距离之和。

把所有餐厅同时放进 BFS 队列，初始距离都为 0；其余位置未访问，障碍另作标记。这样 BFS 每一层同时扩展所有餐厅的波前，一个位置首次被访问时，距离就是所有源点到它的最短距离。相比逐餐厅搜索，只需遍历整个网格一次。

同一位置的多份订单必须累加，不能覆盖。网格四方向边权均为 1，BFS 的分层性质保证距离正确，独立选择最近餐厅则保证费用最小。时间 $O(n^2+m+k+d)$，空间 $O(n^2)$；总费用用 64 位。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<int> distance(n * n, -1), queue;
    vector<long long> demand(n * n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int u = (x - 1) * n + y - 1;
        if (distance[u] < 0) {
            distance[u] = 0;
            queue.push_back(u);
        }
    }
    for (int i = 0; i < k; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        demand[(x - 1) * n + y - 1] += c;
    }
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        distance[(x - 1) * n + y - 1] = -2;
    }
    const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    long long answer = 0;
    for (size_t head = 0; head < queue.size(); ++head) {
        int u = queue[head];
        answer += demand[u] * distance[u];
        for (int dir = 0; dir < 4; ++dir) {
            int x = u / n + dx[dir], y = u % n + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
            int v = x * n + y;
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                queue.push_back(v);
            }
        }
    }
    cout << answer << '\n';
}
```

<a id="problem-e"></a>

## E. 拼图

标签：`轮廓线DP` · `状态压缩` · `矩阵快速幂`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

用由 3 个单位格组成的 L 形拼图铺满 $n\times m$ 的矩形。拼图可以旋转，不能重叠或越界，求方案数模 $10^9+7$。输入 `n m`，$n\le10^{15},m\le7$。每个 L 形是一个 $2\times2$ 方块去掉一个角。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409E/)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409E)。

### 题解

**按行看边界。** 一块 L 形最多跨相邻两行。用 $m$ 位二进制表示当前行中哪些格已经被上一行放下的拼图占据。固定输入掩码 `in`，递归填当前行剩余格，并记录被占用的下一行掩码 `out`，得到转移次数 $M[in][out]$。

递归每次找当前行最左侧空格，枚举所有覆盖它的合法 L 形。它所在的 $2\times2$ 方块左列可能是该列，也可能是前一列；再枚举缺失的四个角，检查当前行和下一行均无冲突。漏掉“方块左列在前一列”的情况，会漏算当前行只有一个右侧格、下一行占两个格的形状。

当前行全满时，把对应 `out` 的转移次数加一。总共只有 $2^m\le128$ 个边界状态；把行数 $n$ 作为矩阵幂次，初始向量仅空掩码为 1，最终答案是处理完 $n$ 行后空掩码的计数。非空掩码表示拼图伸出了最后一行，不能接受。

**正确性。** 最左空格的覆盖拼图在任意完整铺法中唯一确定，递归不会重复或遗漏；边界掩码保留跨行影响的全部信息，矩阵乘法对中间边界求和正好拼接行段。**复杂度：** 预处理宽度对应的有限转移后，时间 $O(2^{3m}\log n)$，空间 $O(2^{2m})$。面积不是 3 的倍数时可直接输出 0。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
using Matrix = vector<vector<int>>;
Matrix multiply(const Matrix &a, const Matrix &b) {
    int s = a.size();
    Matrix c(s, vector<int>(s));
    for (int i = 0; i < s; ++i)
        for (int k = 0; k < s; ++k)
            if (a[i][k])
                for (int j = 0; j < s; ++j)
                    if (b[k][j])
                        c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
    return c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    int m;
    cin >> n >> m;
    if ((n % 3) * (m % 3) % 3) {
        cout << 0 << '\n';
        return 0;
    }
    int s = 1 << m, full = s - 1;
    Matrix a(s, vector<int>(s));
    for (int initial = 0; initial < s; ++initial) {
        function<void(int, int)> dfs = [&](int occupied, int next) {
            if (occupied == full) {
                ++a[initial][next];
                return;
            }
            int c = 0;
            while (occupied >> c & 1)
                ++c;
            for (int left = c - 1; left <= c; ++left)
                if (left >= 0 && left + 1 < m)
                    for (int missing = 0; missing < 4; ++missing) {
                        int upper = 0, lower = 0;
                        for (int cell = 0; cell < 4; ++cell)
                            if (cell != missing) {
                                if (cell < 2)
                                    upper |= 1 << (left + cell);
                                else
                                    lower |= 1 << (left + cell - 2);
                            }
                        if (!(upper >> c & 1) || (upper & occupied) || (lower & next))
                            continue;
                        dfs(occupied | upper, next | lower);
                    }
        };
        dfs(initial, 0);
    }
    vector<int> dp(s);
    dp[0] = 1;
    while (n) {
        if (n & 1) {
            vector<int> next(s);
            for (int i = 0; i < s; ++i)
                if (dp[i])
                    for (int j = 0; j < s; ++j)
                        next[j] = (next[j] + 1LL * dp[i] * a[i][j]) % MOD;
            dp.swap(next);
        }
        n >>= 1;
        if (n)
            a = multiply(a, a);
    }
    cout << dp[0] << '\n';
}
```
