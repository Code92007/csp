---
title: "CSP 201509 五题题解"
contest: "201509"
contest_month: "2015-09"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "连续段", "线性扫描", "日期计算", "模拟", "字符串扫描", "模板替换", "哈希表", "图论", "强连通分量", "Kosaraju", "AC自动机", "矩阵快速幂", "最大加代数"]
status: "published"
problems: [{"id": "A", "title": "数列分段", "tags": ["连续段", "线性扫描"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb44174ace1cba9a20918"}}, {"id": "B", "title": "日期计算", "tags": ["日期计算", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb4db74ace1cba9a209b5"}}, {"id": "C", "title": "模板生成系统", "tags": ["字符串扫描", "模板替换", "哈希表"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb56174ace1cba9a20adf"}}, {"id": "D", "title": "高速公路", "tags": ["图论", "强连通分量", "Kosaraju"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb5e874ace1cba9a20bc7"}}, {"id": "E", "title": "最佳文章", "tags": ["AC自动机", "矩阵快速幂", "最大加代数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb67074ace1cba9a20c6f"}}]
---

# CSP 201509 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 数列分段

标签：`连续段` · `线性扫描`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb44174ace1cba9a20918)（复刻评测）。

### 题意

把数列划成若干连续相同值的极大段，求段数。同一个数在不同位置被其他值隔开时属于不同段。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509A)。

### 题解

第一个元素开启第一段；之后每个元素若不同于前一个，就开启新段。只需保存前值和计数，不必存全数组。

每段唯一对应它的第一个元素，而段首恰好满足“首元素或与前值不同”，所以计数一一对应。时间 $O(n)$，空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n, previous = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0 || x != previous)
            ++count;
        previous = x;
    }
    cout << count << '\n';
}
```

<a id="problem-b"></a>

## B. 日期计算

标签：`日期计算` · `模拟`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb4db74ace1cba9a209b5)（复刻评测）。

### 题意

给年份y及该年的第d天，输出月份和月内日期。需正确处理闰年二月。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509B)。

### 题解

按闰年规则设置二月为28或29天，从一月开始：若d大于当前月天数，则减去该月天数并进入下月，否则当前月和剩余d就是答案。

每次减法只去掉完整经过的月份，剩余d始终是从当前月一日数起的日序，因此循环结束给出正确日期。月末边界使用严格大于，不能用大于等于。时间 $O(12)$，空间 $O(1)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int y, d;
    cin >> y >> d;
    int length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        length[2] = 29;
    int month = 1;
    while (d > length[month]) {
        d -= length[month];
        ++month;
    }
    cout << month << '\n' << d << '\n';
}
```

<a id="problem-c"></a>

## C. 模板生成系统

标签：`字符串扫描` · `模板替换` · `哈希表`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb56174ace1cba9a20adf)（复刻评测）。

### 题意

把模板中的合法标记 `{{ VAR }}` 替换成变量值。变量名区分大小写，未定义变量变为空串；变量值可能包含同样的标记，但不再递归替换。保留其余字符及每一行的格式。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509C)。

### 题解

先保存所有模板行，再读取变量定义，用第一个空格取名字、最外层双引号取完整值。扫描原模板时，找到下一个左标记，输出前面的普通文本；找到对应右标记，查询变量并输出值，然后把扫描位置移到原模板标记之后。

扫描指针始终只在原模板中推进，替换值直接输出，因此不会意外递归。每个原字符要么作为普通文本原样输出，要么属于恰好一个被替换标记，故输出符合规则。哈希表下期望时间 $O(L+U)$，空间为模板和变量值总长度；U 是实际输出长度。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    string line;
    getline(cin, line);
    vector<string> lines(m);
    for (auto &s : lines)
        getline(cin, s);
    unordered_map<string, string> values;
    while (n--) {
        getline(cin, line);
        size_t space = line.find(' '), quote = line.find('"', space);
        values[line.substr(0, space)] = line.substr(quote + 1, line.size() - quote - 2);
    }
    for (auto &s : lines) {
        for (size_t p = 0; p < s.size();) {
            size_t l = s.find("{{ ", p);
            if (l == string::npos) {
                cout << s.substr(p);
                break;
            }
            cout << s.substr(p, l - p);
            size_t r = s.find(" }}", l + 3);
            auto it = values.find(s.substr(l + 3, r - l - 3));
            if (it != values.end())
                cout << it->second;
            p = r + 3;
        }
        cout << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 高速公路

标签：`图论` · `强连通分量` · `Kosaraju`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb5e874ace1cba9a20bc7)（复刻评测）。

### 题意

给定 n 个城市、m 条单向公路，若两城市能互相到达，则组成一对便利城市。无序点对只计一次，求总数。$n\le10^4,m\le10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509D)。

### 题解

互相可达恰好是“属于同一个强连通分量”。大小为 s 的分量内部任意两点都成立，贡献 $s(s-1)/2$；不同分量之间不可能互相可达。

用 Kosaraju 求分量：先在原图做 DFS，记录每个点退出 DFS 的顺序；再反向遍历这个顺序，在所有边反向后的图中搜索，每次搜到的点恰是一整个强连通分量。原图缩点后是 DAG，退出时间顺序保证第二遍不会越过当前应处理分量的边界。

实现两遍都用显式栈。第一遍必须在所有子节点处理完以后才加入退出序列，不能把普通 BFS 的顺序拿来替代。总时间 $O(n+m)$，空间 $O(n+m)$，答案使用 64 位整数。

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n), reverse(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        reverse[v].push_back(u);
    }
    vector<bool> seen(n);
    vector<int> order;
    for (int start = 0; start < n; ++start)
        if (!seen[start]) {
            vector<pair<int, size_t>> stack{{start, 0}};
            seen[start] = true;
            while (!stack.empty()) {
                int u = stack.back().first;
                auto &index = stack.back().second;
                if (index == graph[u].size()) {
                    order.push_back(u);
                    stack.pop_back();
                } else {
                    int v = graph[u][index++];
                    if (!seen[v]) {
                        seen[v] = true;
                        stack.push_back({v, 0});
                    }
                }
            }
        }
    fill(seen.begin(), seen.end(), false);
    long long answer = 0;
    for (auto it = order.rbegin(); it != order.rend(); ++it)
        if (!seen[*it]) {
            vector<int> todo{*it};
            seen[*it] = true;
            for (size_t i = 0; i < todo.size(); ++i)
                for (int v : reverse[todo[i]])
                    if (!seen[v]) {
                        seen[v] = true;
                        todo.push_back(v);
                    }
            long long size = todo.size();
            answer += size * (size - 1) / 2;
        }
    cout << answer << '\n';
}
```

<a id="problem-e"></a>

## E. 最佳文章

标签：`AC自动机` · `矩阵快速幂` · `最大加代数`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb67074ace1cba9a20c6f)（复刻评测）。

### 题意

选定 $n$ 个不同的小写单词。一篇长度为 $m$ 的文章的重要度为这些单词出现次数之和，允许重叠和包含。求所有长度为 $m$ 的字符串中的最大重要度。输入 `n m` 和各单词，单词总长度不超过 100，$m\le10^{15}$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509E)。

### 题解

**AC 自动机负责“最后一个字符新产生多少匹配”。** 建 Trie 并计算 fail 指针，将 fail 节点的终止计数累加到当前节点。到达状态 $v$ 时，`reward[v]` 就是以当前字符结尾的全部重要单词数。重叠不需要特殊处理，后缀匹配由 fail 链自动涵盖。

若只能写较短文章，可以逐字符 DP：`dp[state]` 为当前长度、当前自动机状态的最高分。枚举下一个字母 $c$，转移到 `go[state][c]` 并加上目标状态的奖励。

**把这个转移做快速幂。** 构造矩阵 $M[u][v]$：存在字母能从 $u$ 到 $v$ 时取 `reward[v]`，否则取负无穷。矩阵乘法改成

$$C[i][j]=\max_k(A[i][k]+B[k][j]).$$

这叫最大加代数；它表示两段字符串拼接后的最优得分。初始向量只有根状态为 0，其余为负无穷。按 $m$ 的二进制展开，把相应矩阵幂乘到向量上，最后取所有结束状态的最大值。

**正确性。** 自动机状态包含后续匹配所需的全部后缀信息，奖励精确计算每次新出现的单词。一次矩阵合并枚举中间状态，因此遍历所有字符串拼接方式且取最优；快速幂仅改变合并顺序。

**复杂度。** 状态数 $S\le101$，时间 $O(S^3\log m)$，空间 $O(S^2)$。答案可能达到 $nm$，必须用 64 位；加法前检查负无穷，避免不可达状态参加运算。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const ll NEG = -(1LL << 60);
using Matrix = vector<vector<ll>>;
Matrix multiply(const Matrix &a, const Matrix &b) {
    int n = a.size();
    Matrix c(n, vector<ll>(n, NEG));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            if (a[i][k] != NEG)
                for (int j = 0; j < n; ++j)
                    if (b[k][j] != NEG)
                        c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
    return c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll length;
    cin >> n >> length;
    struct Node {
        array<int, 26> next{};
        int fail = 0, reward = 0;
    };
    vector<Node> trie(1);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int u = 0;
        for (char c : s) {
            int k = c - 'a';
            if (!trie[u].next[k]) {
                trie[u].next[k] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].next[k];
        }
        ++trie[u].reward;
    }
    queue<int> q;
    for (int v : trie[0].next)
        if (v)
            q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        trie[u].reward += trie[trie[u].fail].reward;
        for (int c = 0; c < 26; ++c) {
            int v = trie[u].next[c];
            if (v) {
                trie[v].fail = trie[trie[u].fail].next[c];
                q.push(v);
            } else
                trie[u].next[c] = trie[trie[u].fail].next[c];
        }
    }
    int s = trie.size();
    Matrix a(s, vector<ll>(s, NEG));
    for (int u = 0; u < s; ++u)
        for (int v : trie[u].next)
            a[u][v] = trie[v].reward;
    vector<ll> dp(s, NEG);
    dp[0] = 0;
    while (length) {
        if (length & 1) {
            vector<ll> next(s, NEG);
            for (int u = 0; u < s; ++u)
                if (dp[u] != NEG)
                    for (int v = 0; v < s; ++v)
                        if (a[u][v] != NEG)
                            next[v] = max(next[v], dp[u] + a[u][v]);
            dp.swap(next);
        }
        length >>= 1;
        if (length)
            a = multiply(a, a);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
```
