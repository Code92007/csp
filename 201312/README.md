---
title: "CSP 201312 五题题解"
contest: "201312"
contest_month: "2013-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "频率统计", "同分规则", "字符串", "校验码", "单调栈", "直方图", "最大矩形", "状态压缩", "计数DP", "图论", "BFS", "反向图", "网格"]
status: "published"
problems: [{"id": "A", "title": "出现次数最多的数", "tags": ["频率统计", "同分规则"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312A/"}]}, {"id": "B", "title": "ISBN 号码", "tags": ["字符串", "校验码"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；4 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312B/"}]}, {"id": "C", "title": "最大的矩形", "tags": ["单调栈", "直方图", "最大矩形"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；160 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U281824"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312C/"}], "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305657951"}}, {"id": "D", "title": "有趣的数", "tags": ["状态压缩", "计数DP"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；9 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312D/"}]}, {"id": "E", "title": "I’m stuck!", "tags": ["图论", "BFS", "反向图", "网格"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312E/"}]}]
---

# CSP 201312 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

本题组为第 0 次（练习题组），不计入正式认证场次。

<a id="problem-a"></a>

## A. 出现次数最多的数

标签：`频率统计` · `同分规则`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

找出出现次数最多的整数；若并列，输出其中最小的数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312A)。

### 题解

用map统计频次，它会按数值升序遍历。维护当前最高频次，只有遇到严格更高频次时才更新答案；同频不更新，使较小值被保留。

计数准确，扫描后最高频次为全局最大，升序加严格更新保证并列取最小。设不同值个数u，时间 $O(n\log u+u)$，空间 $O(u)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <map>
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
    int answer = 0, most = 0;
    for (auto [x, c] : count)
        if (c > most) {
            most = c;
            answer = x;
        }
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. ISBN 号码

标签：`字符串` · `校验码`

状态：**已实现**。C++17 编译通过；4 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

ISBN格式为x-xxx-xxxxx-x。前9位数字按位置权重1…9相乘求和模11，余数10写成X。判断最后一位校验码，正确输出Right，否则输出修正后的ISBN。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312B)。

### 题解

扫描末位之前的字符，遇到数字才乘当前权重并递增，连字符直接跳过。求余后转换为0…9或X，与末位比较；不符时仅替换末位，原有分隔符保留。

数字权重由遇到的数字数量决定，恰好对应定义中的1到9，不受三个连字符位置影响。固定长度输入，时间和空间均为 $O(1)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int weight = 1, sum = 0;
    for (size_t i = 0; i + 1 < s.size(); i++)
        if (s[i] != '-')
            sum += (s[i] - '0') * weight++;
    int r = sum % 11;
    char correct = r == 10 ? 'X' : char('0' + r);
    if (s.back() == correct)
        cout << "Right\n";
    else {
        s.back() = correct;
        cout << s << '\n';
    }
}
```

<a id="problem-c"></a>

## C. 最大的矩形

标签：`单调栈` · `直方图` · `最大矩形`

状态：**完整实现，洛谷已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；160 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305657951)。

### 题意

给定 n 个宽 1、高为 h 的相邻柱子，求直方图中轴对齐矩形的最大面积。采用可覆盖存档加强范围 $n\le10^5,h\le10^9$ 的做法。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312C)。

洛谷练习：[同题民间复刻](https://www.luogu.com.cn/problem/U281824)。

### 题解

维护高度严格递增的下标栈，左端放高度 0 的哨兵，最右端也补 0。扫描到 i 时，若栈顶高度不小于当前高度，就弹出 j：弹出后新栈顶是左侧更低边界，当前 i 是可用于结算的右边界，候选面积为 `h[j]*(i-stack.back()-1)`。随后压入 i。

对相等高度提前弹出不会漏解，后面的同高柱会继承更左边界，最终覆盖整段。任意最优矩形可选一根最低柱作为高度，其最大可扩展宽度会在某次弹栈时被计算，所以取全部候选最大值正确。

每个下标只入栈、出栈一次，时间 $O(n)$，空间 $O(n)$。面积可能达到 $10^{14}$，必须使用 64 位整数。

### 代码

独立源码：[C.cpp](C.cpp)

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
    vector<long long> h(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    vector<int> stack{0};
    long long answer = 0;
    for (int i = 1; i <= n + 1; i++) {
        while (stack.size() > 1 && h[stack.back()] >= h[i]) {
            int top = stack.back();
            stack.pop_back();
            answer = max(answer, h[top] * (i - stack.back() - 1));
        }
        stack.push_back(i);
    }
    cout << answer << '\n';
}
```

<a id="problem-d"></a>

## D. 有趣的数

标签：`状态压缩` · `计数DP`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；9 组独立随机对拍通过；未提交正式评测。

### 题意

统计恰有 n 位的十进制数：只使用 0、1、2、3，四种数字均至少出现一次；所有 0 在所有 1 前面，所有 2 在所有 3 前面，首位不为 0。答案模 $10^9+7$，$n\le1000$。原 CSP 输入一个 n；公开存档将输入改为 T 组，下面代码同时支持这两种输入形式。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312D)。

### 题解

用四位掩码记录哪些数字已经出现，$dp[mask]$ 为当前长度下的合法前缀数。每次尝试添加一个数字，检查：首位不能为 0；已经出现 1 后不能再放 0；出现 3 后不能再放 2。还可以提前要求放 1 前必须出现过 0、放 3 前必须出现过 2，因为否则以后无法补齐前置数字。

合法添加后，把对应位设为 1，方案数累加。空串初始 $dp[0]=1$；达到目标长度后只取 mask=15 的状态，保证四种数字都出现。按这些条件，首位实际上只能是 2，但无需在代码外另加特殊递推。

每个合法数按末位删除后，唯一对应一个合法前缀及添加动作；每个被接受的添加也不会破坏顺序，所以计数无重无漏。每一位仅 16×4 次转移，时间 $O(n)$、滚动 DP 空间 $O(1)$；为了回答多组输入，额外保存各长度答案，占 $O(n)$ 空间。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
constexpr int MOD = 1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> input;
    int x;
    while (cin >> x)
        input.push_back(x);
    if (input.empty())
        return 0;
    // Original CSP input is one n; the archived OJ also provides a T-case variant.
    vector<int> queries = input.size() == 1 ? input : vector<int>(input.begin() + 1, input.end());
    int maximum = *max_element(queries.begin(), queries.end());
    vector<int> answer(maximum + 1);
    array<int, 16> dp{};
    dp[0] = 1;
    for (int len = 0; len < maximum; ++len) {
        array<int, 16> next{};
        for (int mask = 0; mask < 16; ++mask)
            for (int digit = 0; digit < 4; ++digit) {
                if (len == 0 && digit == 0)
                    continue;
                if (digit == 0 && (mask & 2))
                    continue;
                if (digit == 1 && !(mask & 1))
                    continue;
                if (digit == 2 && (mask & 8))
                    continue;
                if (digit == 3 && !(mask & 4))
                    continue;
                int to = mask | (1 << digit);
                next[to] = (next[to] + dp[mask]) % MOD;
            }
        dp = next;
        answer[len + 1] = dp[15];
    }
    for (int n : queries)
        cout << answer[n] << '\n';
}
```

<a id="problem-e"></a>

## E. I’m stuck!

标签：`图论` · `BFS` · `反向图` · `网格`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；2 个保存样例/回归用例通过；未提交正式评测。

### 题意

字符网格中，`#` 不可通行；`+`、`S`、`T` 可以向四个方向离开；`-` 只能向左右离开，`|` 只能向上下离开，`.` 只能向下离开。先判断能否从 S 到达 T；若不能，输出 `I’m stuck!`（代码中为 ASCII 单引号）。否则统计从 S 能到达、但从该格无法到达 T 的格子数。输入行列数和网格。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312E)。

### 题解

**出边取决于当前格，不能看目标格决定方向。** 对每个非墙格，按其字符类型枚举允许的离开方向。目标在边界内且不是墙，就建一条有向边，同时在反向图中建反向边。相邻格之间不一定双向可达。

从 S 在原图 BFS，得到 `reachable`。如果 T 不在其中，立即输出指定提示。再从 T 在反向图 BFS，得到 `returnable`：它表示原图中所有能够到达 T 的格子。最终统计 `reachable[u] && !returnable[u]`。

**为什么反向搜索等价？** 原图中从 $u$ 到 T 的每条路径，翻转所有边后就是反向图中从 T 到 $u$ 的路径，反之也成立。因此两次搜索的集合差恰好是题目要求的“能走进去但到不了终点”的位置。无需从每个格子单独搜索一次，也不是简单判断它是否有出边。

**复杂度。** 每格至多四条出边，两次 BFS 总时间、空间均为 $O(RC)$。网格越界、单向死路和先判断 S 能否到 T 是主要易错点。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (auto &s : grid)
        cin >> s;
    int start = -1, target = -1;
    vector<vector<int>> g(r * c), back(r * c);
    array<int, 4> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
    for (int x = 0; x < r; ++x)
        for (int y = 0; y < c; ++y) {
            char ch = grid[x][y];
            int u = x * c + y;
            if (ch == 'S')
                start = u;
            if (ch == 'T')
                target = u;
            if (ch == '#')
                continue;
            for (int d = 0; d < 4; ++d) {
                bool allowed = ch == '+' || ch == 'S' || ch == 'T' || (ch == '-' && d >= 2) ||
                               (ch == '|' && d < 2) || (ch == '.' && d == 1);
                int a = x + dx[d], b = y + dy[d];
                if (allowed && a >= 0 && a < r && b >= 0 && b < c && grid[a][b] != '#') {
                    int v = a * c + b;
                    g[u].push_back(v);
                    back[v].push_back(u);
                }
            }
        }
    auto bfs = [&](int root, const vector<vector<int>> &edges) {
        vector<bool> seen(r * c);
        queue<int> q;
        q.push(root);
        seen[root] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u])
                if (!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
        }
        return seen;
    };
    auto reachable = bfs(start, g);
    if (!reachable[target]) {
        cout << "I'm stuck!\n";
        return 0;
    }
    auto returnable = bfs(target, back);
    int answer = 0;
    for (int u = 0; u < r * c; ++u)
        answer += reachable[u] && !returnable[u];
    cout << answer << '\n';
}
```
