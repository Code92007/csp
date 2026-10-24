---
title: "CSP 202506 五题题解"
contest: "202506"
contest_month: "2025-06"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "整数运算", "坐标映射", "BFS", "网格最短路", "位运算", "进制转换", "哈希表", "模拟", "字符串", "自动机", "矩阵快速幂", "计数DP", "圆方树", "虚树", "LCA", "图论"]
status: "published"
problems: [{"id": "A", "title": "正态分布", "tags": ["整数运算", "坐标映射"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b2a67df0b81749b8ec"}}, {"id": "B", "title": "机器人复健指南", "tags": ["BFS", "网格最短路"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b3a67df0b81749b902"}}, {"id": "C", "title": "消息解码", "tags": ["位运算", "进制转换", "哈希表", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b5a67df0b81749b914"}}, {"id": "D", "title": "月票发行", "tags": ["字符串", "自动机", "矩阵快速幂", "计数DP"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；3 个保存样例/回归用例通过；71 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b6a67df0b81749b92b"}}, {"id": "E", "title": "博物馆", "tags": ["圆方树", "虚树", "LCA", "图论"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b8a67df0b81749b940"}}]
---

# CSP 202506 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 正态分布

标签：`整数运算` · `坐标映射`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

把正态分布查询标准化为z=(n-μ)/σ，输出其在标准表的行列号。行按0.0、0.1…排列，列按百分位0…9排列，均从1编号；σ是100的因子。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506A/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506A)。

### 题解

计算整数v=100*(n-μ)/σ，题设保证整除。v/10表示z的整数部分与十分位，v%10是百分位，答案为(v/10+1,v%10+1)。

相当于把两位小数拆成表格的行、列下标，全程整数可避免3.45在浮点中略小于3.45导致截断。每个查询 $O(1)$ 时间、$O(1)$ 空间。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    while (k--) {
        int mu, sigma, n;
        cin >> mu >> sigma >> n;
        int value = 100 * (n - mu) / sigma;
        cout << value / 10 + 1 << ' ' << value % 10 + 1 << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 机器人复健指南

标签：`BFS` · `网格最短路`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

机器人在 n×n 场地内按马步移动，即 (±1,±2) 或 (±2,±1)。从给定格子出发，求不超过 k 步可到达的不同格子数，包括起点。n、k≤100。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506B/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506B)。

### 题解

把格子视为图顶点，八种合法马步为等权边，从起点 BFS。首次入队时记录最短距离并标记，距离达到 k 的点计入答案但不再扩展。

BFS 按距离递增处理结点，因此第一次访问得到最少步数；一个格子能在 k 步内到达，当且仅当其最短距离≤k。注意“八方向”指题图中的马步，并非相邻八格。每格至多入队一次，时间和空间均为 $O(n^2)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    --x;
    --y;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    int ans = 0, dx[] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        ++ans;
        if (dist[u][v] == k)
            continue;
        for (int i = 0; i < 8; i++) {
            int a = u + dx[i], b = v + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < n && dist[a][b] == -1) {
                dist[a][b] = dist[u][v] + 1;
                q.push({a, b});
            }
        }
    }
    cout << ans << '\n';
}
```

<a id="problem-c"></a>

## C. 消息解码

标签：`位运算` · `进制转换` · `哈希表` · `模拟`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

将 72 位消息解码。简单消息依次含 1 位类型、28 位接收方、28 位发送方、15 位位置；代号值小于 $2^{25}$ 时是 25 位散列，否则减去 $2^{25}$ 得典型代号的混合进制短编码。复杂消息含类型、58 位完整代号、12 位另一方散列及一位方向。散列推断前加 #，找不到输出 ###，位置 0 不输出。只能使用此前消息直接给出的代号；冲突取最近消息，同条消息优先发送方。消息数至多 $10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506C/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506C)。

### 题解

把二进制字段按规定位置读成无符号整数。完整代号用 38 进制反解 11 个字符，再去掉末尾空格。典型代号依次使用基数 37、36、10、26、26、26，反解时从最后一位开始取余，首位空格则去掉。

维护 12 位和 25 位散列到最近直接代号的映射。每条消息必须先把两方都解码、输出，然后才更新映射；更新时先接收方后发送方，使同条消息冲突时发送方覆盖。通过散列猜出的代号不回写，防止错误地刷新历史优先级。

散列可用无符号 64 位乘法：`数字表示 * 47055833459` 的溢出按模 $2^{64}$ 定义，再右移 64-b 位，恰好得到题目要求的 b 位散列。因为更高的乘积位在最终对 $2^b$ 取模时本来就会被消去，这并非依赖未定义的有符号溢出。

进制反解与编码互逆，延后更新映射保证只查看历史消息，覆盖次序保证冲突规则。每条消息固定 72 位且代号至多 11 字符，期望总时间 $O(n)$，空间 $O(n+2^{12})$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using u64 = uint64_t;
int digit(char c) {
    if (c == ' ')
        return 0;
    if (c >= '0' && c <= '9')
        return c - '0' + 1;
    if (c == '_')
        return 37;
    return c - 'A' + 11;
}
char symbol(int x) {
    if (x == 0)
        return ' ';
    if (x <= 10)
        return char('0' + x - 1);
    if (x == 37)
        return '_';
    return char('A' + x - 11);
}
u64 numeric(string s) {
    s.resize(11, ' ');
    u64 value = 0;
    for (char c : s)
        value = value * 38 + digit(c);
    return value;
}
string full(u64 x) {
    string s(11, ' ');
    for (int i = 10; i >= 0; --i) {
        s[i] = symbol(x % 38);
        x /= 38;
    }
    while (!s.empty() && s.back() == ' ')
        s.pop_back();
    return s;
}
string typical(u64 x) {
    string s(6, ' ');
    for (int i = 5; i >= 3; --i) {
        s[i] = char('A' + x % 26);
        x /= 26;
    }
    s[2] = char('0' + x % 10);
    x /= 10;
    int second = x % 36;
    x /= 36;
    s[1] = second < 10 ? char('0' + second) : char('A' + second - 10);
    s[0] = symbol(x);
    if (s[0] == ' ')
        s.erase(s.begin());
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<u64, string> known25;
    vector<string> known12(4096);
    auto remember = [&](const string &name) {
        u64 hash = numeric(name) * u64(47055833459ULL);
        known25[hash >> 39] = name;
        known12[hash >> 52] = name;
    };
    while (n--) {
        string bits;
        cin >> bits;
        auto value = [&](int begin, int length) {
            u64 x = 0;
            for (int i = 0; i < length; ++i)
                x = x * 2 + (bits[begin + i] - '0');
            return x;
        };
        string receiver, sender;
        bool direct_receiver = false, direct_sender = false;
        int location = 0;
        if (bits[0] == '0') {
            auto decode = [&](u64 x, bool &direct) {
                direct = x >= (1ULL << 25);
                if (direct)
                    return typical(x - (1ULL << 25));
                auto it = known25.find(x);
                return it == known25.end() ? string("###") : "#" + it->second;
            };
            receiver = decode(value(1, 28), direct_receiver);
            sender = decode(value(29, 28), direct_sender);
            location = value(57, 15);
        } else {
            string literal = full(value(1, 58));
            const string &prior = known12[value(59, 12)];
            string inferred = prior.empty() ? "###" : "#" + prior;
            if (bits[71] == '0') {
                receiver = inferred;
                sender = literal;
                direct_sender = true;
            } else {
                receiver = literal;
                sender = inferred;
                direct_receiver = true;
            }
        }
        cout << receiver << ' ' << sender;
        if (location)
            cout << ' ' << location;
        cout << '\n';
        if (direct_receiver)
            remember(receiver);
        if (direct_sender)
            remember(sender);
    }
}
```

<a id="problem-d"></a>

## D. 月票发行

标签：`字符串` · `自动机` · `矩阵快速幂` · `计数DP`

状态：**已实现**。C++17 编译通过；3 个保存样例/回归用例通过；71 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

长度为 $n$ 的字符串有 $m$ 个固定位置是 `#`，其他位置可填任意小写字母。统计存在一处 `ccf`，且其右边存在一处 `cspark` 的字符串数量，模 $998244353$。输入 $n,m$ 和递增的井号位置；$n\le10^9,m\le10^6$。模式不能跨过井号，但前后两种模式可以位于不同的自由段。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506D/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506D)。

### 题解

**用状态表示已经完成了哪一步。** 找到第一个 `ccf` 之前，只记录当前后缀匹配了它的多少个字符，得到状态 0、1、2。找到后改为匹配 `cspark`，得到状态 3 到 8；两者都按顺序找到则进入永久接受状态 9。对每个状态和字母，取“拼上字母后的字符串”和目标模式的最长前缀匹配后缀，得到下一状态。两个模式无法相互重叠，所以识别到第一个模式时，可以从第二个模式的空前缀开始。

为什么只需记第一次 `ccf`？如果后面任意一个 `ccf` 能与某个 `cspark` 配对，那么最早的 `ccf` 也能与它配对。因此这个状态机恰好识别题目要求，既不遗漏也不重复。

**逐字 DP 改为整段转移。** 井号把模式匹配的后缀清空，但保留“没找到第一个／找到第一个／已经成功”这三个阶段。对于长为 $L$ 的自由段，设 $A$ 为从阶段 0 到阶段 0 的数量，$B$ 为从阶段 0 到阶段 1 的数量，$C$ 为从阶段 1 留在阶段 1 的数量，$T=26^L$。这些数量都由十状态转移矩阵的 $L$ 次幂得到。

三个全局计数 $(u,w,z)$ 依次表示上述阶段，经过该段后变成

$$u'=uA,\quad w'=uB+wC,\quad z'=zT+w(T-C)+u(T-A-B).$$

空段也适用：$A=C=T=1,B=0$。最终输出 $z$。

**兼顾很多短段和少量长段。** 预计算长度不超过 $H=10^5$ 的段转移，长段用矩阵快速幂，重复长度缓存。所有段长总和不超过 $n$，所以长段数量至多 $n/(H+1)$，不会给一百万个井号逐个做快速幂。设状态数 $S=10$，时间上界为 $O(HS^2+S^3\log n+m+\frac nH S^2\log n)$，空间 $O(m+H+S^2\log n+n/H)$。矩阵内积使用无符号 64 位累加，十项乘积之和仍在其范围内。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
constexpr int MOD = 998244353, S = 10, SMALL = 100000;
using Row = array<int, S>;
using Matrix = array<Row, S>;
Row multiply(const Row &a, const Matrix &b) {
    Row c{};
    for (int j = 0; j < S; ++j) {
        uint64_t sum = 0;
        for (int k = 0; k < S; ++k)
            sum += uint64_t(a[k]) * b[k][j];
        c[j] = sum % MOD;
    }
    return c;
}
int next_state(int s, char ch) {
    if (s == 9)
        return 9;
    string pattern = s < 3 ? "ccf" : "cspark";
    int offset = s < 3 ? 0 : 3;
    string text = pattern.substr(0, s - offset) + ch;
    for (int len = pattern.size(); len >= 0; --len)
        if (text.size() >= size_t(len) &&
            text.compare(text.size() - len, len, pattern, 0, len) == 0)
            return offset + len;
    return offset;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> lengths;
    int previous = 0;
    for (int i = 0; i < m; ++i) {
        int position;
        cin >> position;
        lengths.push_back(position - previous - 1);
        previous = position;
    }
    lengths.push_back(n - previous);
    Matrix transition{};
    for (int s = 0; s < S; ++s)
        for (char c = 'a'; c <= 'z'; ++c)
            ++transition[s][next_state(s, c)];
    array<Matrix, 30> power;
    power[0] = transition;
    for (int bit = 1; bit < 30; ++bit)
        for (int row = 0; row < S; ++row)
            power[bit][row] = multiply(power[bit - 1][row], power[bit - 1]);
    // For a segment: counts for 0->0, 0->1, 1->1, and all strings.
    auto extract = [](const Row &a, const Row &b) {
        array<int, 4> result{};
        for (int s = 0; s < S; ++s) {
            if (s < 3)
                result[0] = (result[0] + a[s]) % MOD;
            if (s >= 3 && s < 9)
                result[1] = (result[1] + a[s]) % MOD;
            if (s < 9)
                result[2] = (result[2] + b[s]) % MOD;
            result[3] = (result[3] + a[s]) % MOD;
        }
        return result;
    };
    vector<array<int, 4>> small(min(n, SMALL) + 1);
    Row a{}, b{};
    a[0] = b[3] = 1;
    for (size_t len = 0; len < small.size(); ++len) {
        small[len] = extract(a, b);
        a = multiply(a, transition);
        b = multiply(b, transition);
    }
    unordered_map<int, array<int, 4>> cache;
    long long unseen = 1, waiting = 0, accepted = 0;
    for (int len : lengths) {
        array<int, 4> ways;
        if (len < int(small.size()))
            ways = small[len];
        else if (cache.count(len))
            ways = cache[len];
        else {
            a.fill(0);
            b.fill(0);
            a[0] = b[3] = 1;
            for (int bit = 0; bit < 30; ++bit)
                if (len >> bit & 1) {
                    a = multiply(a, power[bit]);
                    b = multiply(b, power[bit]);
                }
            ways = cache[len] = extract(a, b);
        }
        auto [no_first, first_only, no_second, all] = ways;
        long long direct = (all - no_first - first_only + 2LL * MOD) % MOD;
        accepted = (accepted * all + waiting * (all - no_second + MOD) + unseen * direct) % MOD;
        waiting = (waiting * no_second + unseen * first_only) % MOD;
        unseen = unseen * no_first % MOD;
    }
    cout << accepted << '\n';
}
```

<a id="problem-e"></a>

## E. 博物馆

标签：`圆方树` · `虚树` · `LCA` · `图论`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

连通无向图有 $n$ 个路口，每份攻略指定一组不同的博物馆路口。对于每个被封闭路口 $x$，可以自由选择住宿路口，收益是删去 $x$ 后某个连通块中的最大博物馆数。每份攻略输出所有 $x$ 的收益之和。输入 `n m q`、全部边、每份攻略的点数和点表。$n,q\le10^5$，$m\le2\times10^5$，全部攻略点数之和不超过 $3\times10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506E/)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506E)。

### 题解

**图先变树。** Tarjan 求点双连通分量；每个原顶点建圆点，每个点双分量建方点，成员与分量之间连边。得到圆方树。删原图顶点后的连通块，对应圆方树删去该圆点后的各分支。于是只需计算每个圆点周围各分支包含多少标记。

**设一个便于修正的基准。** 一份攻略有 $C$ 个标记。假设删任意点都不分裂标记，那么普通点贡献 $C$，标记点贡献 $C-1$，合计 $(n-1)C$。只有标记点之间的树路径上的圆点可能需要修正。

将标记点按 DFS 序排序，加入相邻标记的 LCA，再加入根，构建虚树。逆序求每个虚树点的标记子树大小 $sub[u]$。对于虚树上的圆点 $u$，父亲方向有 $C-sub[u]$ 个标记，各虚树孩子方向各有 $sub[v]$ 个；这些分支属于不同的原树孩子方向，因为所有必要 LCA 已加入。最大值就是实际贡献，减去原基准完成修正。

**压缩边中间也要算。** 虚树边 $p\to u$ 的中间点均未被标记，也没有额外含标记分支。删去任何一个这样的圆点，标记分成 $sub[u]$ 和 $C-sub[u]$ 两部分，因此每个中间圆点都要从基准减去 $\min(sub[u],C-sub[u])$。预处理根路径上的圆点数量，即可常数时间求中间圆点个数；方点不参与最终答案。

**正确性。** 虚树点、中间链上的圆点、虚树外的圆点三类互不重叠且覆盖全部原点，分别使用精确分支计数、二分支公式、基准值，故总和正确。实现用显式栈做原图和树的 DFS，避免长链递归爆栈。

**复杂度。** 预处理 $O(n+m+n\log n)$；一份 $C$ 点攻略 $O(C\log C+C\log n)$。空间 $O(n\log n+m+C)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    vector<vector<int>> tree(2 * n + 1);
    vector<int> dfn(n + 1), low(n + 1), par(n + 1), pe(n + 1, -1), pos(n + 1), vertices, dfs;
    int clock = 0, N = n;
    dfn[1] = low[1] = ++clock;
    dfs.push_back(1);
    vertices.push_back(1);
    // Explicit DFS stack avoids recursion overflow on a long chain.
    while (!dfs.empty()) {
        int u = dfs.back();
        if (pos[u] < int(g[u].size())) {
            auto [v, id] = g[u][pos[u]++];
            if (id == pe[u])
                continue;
            if (!dfn[v]) {
                par[v] = u;
                pe[v] = id;
                dfn[v] = low[v] = ++clock;
                vertices.push_back(v);
                dfs.push_back(v);
            } else
                low[u] = min(low[u], dfn[v]);
        } else {
            dfs.pop_back();
            int p = par[u];
            if (!p)
                continue;
            low[p] = min(low[p], low[u]);
            if (low[u] >= dfn[p]) {
                ++N;
                tree[N].push_back(p);
                tree[p].push_back(N);
                int v;
                do {
                    v = vertices.back();
                    vertices.pop_back();
                    tree[N].push_back(v);
                    tree[v].push_back(N);
                } while (v != u);
            }
        }
    }
    int LOG = 1;
    while ((1 << LOG) <= N)
        ++LOG;
    vector<vector<int>> up(LOG, vector<int>(N + 1));
    vector<int> tin(N + 1), tout(N + 1), dep(N + 1), prefix(N + 1), order{1};
    vector<pair<int, bool>> st{{1, false}};
    clock = 0;
    while (!st.empty()) {
        auto [u, exit] = st.back();
        st.pop_back();
        if (exit) {
            tout[u] = clock;
            continue;
        }
        tin[u] = ++clock;
        prefix[u] = prefix[up[0][u]] + (u <= n);
        for (int j = 1; j < LOG; ++j)
            up[j][u] = up[j - 1][up[j - 1][u]];
        st.push_back({u, true});
        for (int v : tree[u])
            if (v != up[0][u]) {
                up[0][v] = u;
                dep[v] = dep[u] + 1;
                st.push_back({v, false});
            }
    }
    auto ancestor = [&](int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; };
    auto lca = [&](int u, int v) {
        if (ancestor(u, v))
            return u;
        if (ancestor(v, u))
            return v;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[j][u] && !ancestor(up[j][u], v))
                u = up[j][u];
        return up[0][u];
    };
    vector<int> marked(N + 1), sub(N + 1), maxBranch(N + 1), vp(N + 1);
    for (int qi = 1; qi <= q; ++qi) {
        int c;
        cin >> c;
        vector<int> v(c);
        for (int &x : v) {
            cin >> x;
            marked[x] = qi;
        }
        auto cmp = [&](int a, int b) { return tin[a] < tin[b]; };
        sort(v.begin(), v.end(), cmp);
        for (int i = 1; i < c; ++i)
            v.push_back(lca(v[i - 1], v[i]));
        v.push_back(1);
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(), v.end()), v.end());
        vector<int> stack;
        for (int u : v) {
            sub[u] = (marked[u] == qi);
            maxBranch[u] = 0;
            while (!stack.empty() && !ancestor(stack.back(), u))
                stack.pop_back();
            vp[u] = stack.empty() ? 0 : stack.back();
            stack.push_back(u);
        }
        long long ans = 1LL * (n - 1) * c; // baseline c - [marked]
        for (int i = int(v.size()) - 1; i >= 0; --i) {
            int u = v[i], p = vp[u];
            int best = max(maxBranch[u], c - sub[u]);
            if (u <= n)
                ans += best - (c - (marked[u] == qi));
            if (p) {
                int middle = prefix[u] - prefix[p] - (u <= n);
                ans -= 1LL * middle * min(sub[u], c - sub[u]);
                sub[p] += sub[u];
                maxBranch[p] = max(maxBranch[p], sub[u]);
            }
        }
        cout << ans << '\n';
    }
}
```
