---
title: "CSP 202006 五题题解"
contest: "202006"
contest_month: "2020-06"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "直线两侧", "符号判断", "双指针", "稀疏向量", "状态机", "字符串", "模拟", "KMP", "矩阵快速幂", "递推", "最大权闭合子图", "最小割", "二次函数"]
status: "published"
problems: [{"id": "A", "title": "线性分类器", "tags": ["直线两侧", "符号判断"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adceb1574ace1cba9a1bce6"}}, {"id": "B", "title": "稀疏向量", "tags": ["双指针", "稀疏向量"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adceb1774ace1cba9a1bd0b"}}, {"id": "C", "title": "Markdown 渲染器", "tags": ["状态机", "字符串", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add98d374ace1cba9a1f2eb"}}, {"id": "D", "title": "1246", "tags": ["字符串", "KMP", "矩阵快速幂", "递推"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；110 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9c1c74ace1cba9a1f614"}}, {"id": "E", "title": "乔乔和牛牛逛超市", "tags": ["最大权闭合子图", "最小割", "二次函数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9cb974ace1cba9a1f6a9"}}]
---

# CSP 202006 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 线性分类器

标签：`直线两侧` · `符号判断`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给带A/B标签的平面点，对每条θ0+θ1x+θ2y=0直线判断两类是否各自完全位于不同侧。两类均存在，输入保证没有点在线上。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006A)。

### 题解

代入直线方程，正负号决定所在半平面。将B类点的符号反转后，检查所有点的符号是否一致；一致意味着A在同侧、B恰在另一侧。

这个变换同时检验类内一致与类间相反，无需求斜率，也自然支持竖直线。时间 $O(nm)$，空间 $O(n)$；乘法使用64位防止改变符号。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
struct Point {
    long long x, y;
    char type;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<Point> points(n);
    for (auto &p : points)
        cin >> p.x >> p.y >> p.type;
    while (m--) {
        long long a, b, c;
        cin >> a >> b >> c;
        int reference = 0;
        bool ok = true;
        for (auto p : points) {
            long long value = a + b * p.x + c * p.y;
            int side = value > 0 ? 1 : -1;
            if (p.type == 'B')
                side = -side;
            if (value == 0 || (reference && reference != side))
                ok = false;
            reference = side;
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 稀疏向量

标签：`双指针` · `稀疏向量`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

两个 n 维向量只给出非零项，且各自按下标递增排列。n 可达$10^9$，每个向量非零项至多$5\times10^5$。求内积。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006B)。

### 题解

用两个指针合并扫描非零项。下标相等时把值相乘累加，两指针都前移；下标不等时只移动较小的一边，因为另一向量已不可能在这个较小下标出现非零值。

内积只有双方同下标均非零才有贡献，扫描恰好计算所有此类项一次。时间 $O(a+b)$，空间 $O(a+b)$，与巨大维数n无关；累计值可能超出32位，使用long long。

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
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, long long>> u(a), v(b);
    for (auto &[i, x] : u)
        cin >> i >> x;
    for (auto &[i, x] : v)
        cin >> i >> x;
    int i = 0, j = 0;
    long long ans = 0;
    while (i < a && j < b) {
        if (u[i].first < v[j].first)
            ++i;
        else if (u[i].first > v[j].first)
            ++j;
        else {
            ans += u[i].second * v[j].second;
            ++i;
            ++j;
        }
    }
    cout << ans << '\n';
}
```

<a id="problem-c"></a>

## C. Markdown 渲染器

标签：`状态机` · `字符串` · `模拟`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；120 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add98d374ace1cba9a1f2eb)（复刻评测）。

### 题意

在宽 w 的终端渲染简化 Markdown，输出占用行数。空白行分隔块；普通段落各行去首尾空格后用一个空格连接；`* ` 开头启动列表项，后续以两个空格开头的非空白行可接续该项。列表正文宽度为 w-3，每项至少占一行。换行后丢弃剩余文本开头连续空格，块之间留一空行。输入可达 20 MiB。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006C)。

### 题解

用三种状态表示当前没有块、普通段落、列表。遇到空白行结算当前内容并结束块；遇到新列表项，若原本在列表中仅结算上一项，否则先结算旧块并开启列表；列表中的缩进行接到当前项，其余非空行开启或延续普通段落。

每行内容先去首尾空格，非空内容之间只加一个连接空格；行内原有多个空格必须保留。计算行数时，从当前文本位置消耗 w 个字符（列表为 w-3），若还有内容则跳过接下来连续空格，再开始下一行。空列表项仍占一行。

状态转移恰好对应各类块及接续规则；计数循环与逐字符渲染的换行位置一致。只在新块开始且已有旧块时加一个分隔行，避免文档首尾或连续空行多计。总时间 $O(L)$，空间 $O(L)$，L 为输入字符数。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <string>
using namespace std;
string trim(const string &s) {
    size_t l = s.find_first_not_of(' ');
    if (l == string::npos)
        return "";
    return s.substr(l, s.find_last_not_of(' ') - l + 1);
}
long long lines(const string &s, int width) {
    if (s.empty())
        return 1;
    long long ans = 0;
    size_t p = 0;
    while (p < s.size()) {
        ++ans;
        p += width;
        while (p < s.size() && s[p] == ' ')
            ++p;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w;
    cin >> w;
    string s, text;
    getline(cin, s);
    int state = 0;
    long long answer = 0;
    bool hadBlock = false;
    auto flush = [&]() {
        if (state)
            answer += lines(text, state == 2 ? w - 3 : w);
        text.clear();
    };
    auto begin = [&](int kind) {
        if (hadBlock)
            ++answer;
        hadBlock = true;
        state = kind;
    };
    auto append = [&](const string &part) {
        string t = trim(part);
        if (t.empty())
            return;
        if (!text.empty())
            text += ' ';
        text += t;
    };
    while (getline(cin, s)) {
        bool blank = trim(s).empty();
        bool bullet = s.size() >= 2 && s[0] == '*' && s[1] == ' ';
        bool indent = s.size() >= 2 && s[0] == ' ' && s[1] == ' ';
        if (blank) {
            flush();
            state = 0;
            continue;
        }
        if (bullet) {
            if (state == 2)
                flush();
            else {
                flush();
                begin(2);
            }
            append(s.substr(2));
        } else if (state == 2 && indent) {
            append(s.substr(2));
        } else {
            if (state != 1) {
                flush();
                begin(1);
            }
            append(s);
        }
    }
    flush();
    cout << answer << '\n';
}
```

<a id="problem-d"></a>

## D. 1246

标签：`字符串` · `KMP` · `矩阵快速幂` · `递推`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；110 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9c1c74ace1cba9a1f614)（复刻评测）。

### 题意

从字符串 `1` 开始，每秒同时把 1 换成 2、2 换成 4、4 换成 16、6 换成 64。给定秒数 $n\le10^9$ 和仅含这四种数字的模式串 S（长度至多 $10^5$），求第 n 秒字符串中 S 的出现次数，允许重叠，答案模 $998244353$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006D)。

### 题解

**分别考虑四个单字符的展开。** 记录每个字符展开后包含 S 的次数，以及最多 $|S|-1$ 长的前缀和后缀。例如 4 下一轮展开为“1 的旧展开 + 6 的旧展开”，匹配次数等于两个子块内部次数，再加跨界次数。跨界匹配只可能用到左块后缀与右块前缀；这两段都比 S 短，所以在它们的拼接上运行 KMP，找到的每一次匹配都确实跨界，不会重复计算内部匹配。

四种字符的次数递推为线性关系加跨界常数。加入一个恒为 1 的维度，便可写成 5×5 矩阵。难点在于跨界常数随轮数变化，不能一开始就对同一个矩阵快速幂。

**先等待截断边界进入周期。** 首字符的替换具有长度 3 的循环，尾字符具有长度 2 的循环。固定只保留有限长度的边界后，展开足够长时，相隔 6 轮的这些前后缀会相同：对每个循环相位，继续展开只向截断范围之外延长。程序不猜预热轮数，而是实际比较当前八个边界字符串与 6 轮前是否完全相等。边界更新是确定性的，一旦相等，此后的跨界常数就严格以 6 为周期。

将这六轮的矩阵按执行顺序相乘，再快速幂跳过完整周期，最后处理不足六轮的余数。矩阵乘法顺序不能反过来。模式长度为 1 时截断长度为 0，不存在跨界匹配，同一流程仍成立；n=0 直接保留初始计数。

出现次数被互斥划分为内部与跨界两类，KMP 统计精确；相同边界状态保证后续转移重复，所以矩阵跳转不改变结果。设预热轮数为 H（$O(\log(|S|+1))$），时间 $O(H|S|+5^3\log n)$，空间 $O(|S|+H)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using i64 = long long;
constexpr i64 MOD = 998244353;
using Matrix = array<array<i64, 5>, 5>;
using Vector = array<i64, 5>;
Matrix identity_matrix() {
    Matrix a{};
    for (int i = 0; i < 5; ++i)
        a[i][i] = 1;
    return a;
}
Matrix multiply(const Matrix &a, const Matrix &b) {
    Matrix c{};
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    return c;
}
Vector apply_matrix(const Matrix &a, const Vector &b) {
    Vector c{};
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            c[i] = (c[i] + a[i][j] * b[j]) % MOD;
    return c;
}
struct Ends {
    array<string, 4> prefix, suffix;
    bool operator==(const Ends &b) const {
        return prefix == b.prefix && suffix == b.suffix;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n;
    string pattern;
    cin >> n >> pattern;
    int length = pattern.size(), keep = length - 1;
    vector<int> failure(length);
    for (int i = 1, j = 0; i < length; ++i) {
        while (j && pattern[i] != pattern[j])
            j = failure[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        failure[i] = j;
    }
    auto matches = [&](const string &text) {
        i64 count = 0;
        int j = 0;
        for (char c : text) {
            while (j && c != pattern[j])
                j = failure[j - 1];
            if (c == pattern[j])
                ++j;
            if (j == length) {
                ++count;
                j = failure[j - 1];
            }
        }
        return count;
    };
    const string symbols = "1246";
    const vector<vector<int>> children{{1}, {2}, {0, 3}, {3, 2}};
    Ends state;
    Vector count{};
    count[4] = 1;
    for (int a = 0; a < 4; ++a) {
        if (keep)
            state.prefix[a] = state.suffix[a] = string(1, symbols[a]);
        count[a] = pattern == string(1, symbols[a]);
    }
    deque<Ends> history{state};
    vector<Matrix> transitions;
    for (i64 time = 0; time < n;) {
        Ends next;
        Matrix transform{};
        transform[4][4] = 1;
        for (int a = 0; a < 4; ++a) {
            for (int child : children[a]) {
                ++transform[a][child];
                next.prefix[a] += state.prefix[child];
                next.suffix[a] += state.suffix[child];
            }
            if (int(next.prefix[a].size()) > keep)
                next.prefix[a].resize(keep);
            if (int(next.suffix[a].size()) > keep)
                next.suffix[a].erase(0, next.suffix[a].size() - keep);
            if (children[a].size() == 2)
                transform[a][4] =
                    matches(state.suffix[children[a][0]] + state.prefix[children[a][1]]);
        }
        count = apply_matrix(transform, count);
        state = std::move(next);
        transitions.push_back(transform);
        ++time;
        // Equal endpoints imply exactly equal future boundary contributions.
        if (history.size() == 6 && state == history.front()) {
            i64 remaining = n - time;
            int begin = int(transitions.size()) - 6;
            Matrix cycle = identity_matrix();
            for (int j = begin; j < begin + 6; ++j)
                cycle = multiply(transitions[j], cycle);
            i64 rounds = remaining / 6;
            while (rounds) {
                if (rounds & 1)
                    count = apply_matrix(cycle, count);
                cycle = multiply(cycle, cycle);
                rounds /= 2;
            }
            for (int j = 0; j < remaining % 6; ++j)
                count = apply_matrix(transitions[begin + j], count);
            break;
        }
        history.push_back(state);
        if (history.size() > 6)
            history.pop_front();
    }
    cout << count[0] << '\n';
}
```

<a id="problem-e"></a>

## E. 乔乔和牛牛逛超市

标签：`最大权闭合子图` · `最小割` · `二次函数`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9cb974ace1cba9a1f6a9)（复刻评测）。

### 题意

每种商品可以不买，或购买整数数量 $x_i\in[L_i,R_i]$，开心程度为二次函数 $a_ix_i^2+b_ix_i+c_i$。限制 1：买商品 $y$ 就必须买商品 $x$；限制 2：商品 $y$ 买到其端点数量 $L_y$ 或 $R_y$ 时，必须买商品 $x$。求最大总开心程度。输入 `n m`、各商品 `L R a b c`、限制 `z x y`；$n\le10^4,m\le10^5$，且内部区间非空。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006E)。

### 题解

**先把每种商品缩成两个有用状态。** 内部购买的最佳收益记为 $I_i=\max_{L_i<x<R_i} f_i(x)$，端点购买最佳收益为 $E_i=\max(f_i(L_i),f_i(R_i))$。二次函数在整数区间的最大值只可能来自区间端点，或开口向下时顶点附近的整数，因此常数次计算即可。

建两个点：基础点权为 $I_i$，升级点权为 $E_i-I_i$，并添加“升级点必选基础点”的依赖边。都不选表示不购买；只选基础点表示内部购买；两者都选的总权恰为 $E_i$。即使某个权值为负，也不能直接删去，它可能被其他商品的依赖强制选中。

第一类限制添加 $base_y\to base_x$，第二类添加 $upgrade_y\to base_x$。问题成为：选择一个点集，使选中的点的所有后继也被选中，并最大化点权和，即最大权闭合子图。

**转换为最小割。** 正权点由源点连入，容量为该权值；负权点向汇点连边，容量为权值绝对值；依赖边容量设为大于全部有限收益总和的 `INF`。令所有正权之和为 $P$，答案为 $P-\text{最大流}$。源侧点表示选择；割去正权边意味着放弃收益，割去负权边意味着支付代价，而有限最小割不会违反依赖。

**正确性。** 商品三态与闭合点集一一对应且收益相同，闭合子图与有限割的代价关系又是精确的，因此最小割给出原问题最大值。代码使用 Dinic。图有 $O(n)$ 点、$O(n+m)$ 边，通用最坏时间界为 $O(V^2E)$，空间 $O(n+m)$；实际为典型最大闭合图规模，收益和容量均用 64 位。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
struct Flow {
    struct Edge {
        int to, reverse;
        ll capacity;
    };
    vector<vector<Edge>> g;
    vector<int> level, current;
    explicit Flow(int n) : g(n), level(n), current(n) {}
    void add(int u, int v, ll c) {
        Edge a{v, int(g[v].size()), c}, b{u, int(g[u].size()), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    }
    ll dfs(int u, int sink, ll f) {
        if (u == sink)
            return f;
        for (int &i = current[u]; i < int(g[u].size()); ++i) {
            auto &e = g[u][i];
            if (e.capacity && level[e.to] == level[u] + 1) {
                ll sent = dfs(e.to, sink, min(f, e.capacity));
                if (sent) {
                    e.capacity -= sent;
                    g[e.to][e.reverse].capacity += sent;
                    return sent;
                }
            }
        }
        return 0;
    }
    ll run(int source, int sink) {
        ll ans = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            queue<int> q;
            q.push(source);
            level[source] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto e : g[u])
                    if (e.capacity && level[e.to] < 0) {
                        level[e.to] = level[u] + 1;
                        q.push(e.to);
                    }
            }
            if (level[sink] < 0)
                return ans;
            fill(current.begin(), current.end(), 0);
            while (ll sent = dfs(source, sink, 1LL << 60))
                ans += sent;
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int source = 2 * n, sink = source + 1;
    Flow flow(sink + 1);
    ll positives = 0;
    const ll INF = 1LL << 60;
    auto weight = [&](int u, ll x) {
        if (x > 0) {
            flow.add(source, u, x);
            positives += x;
        } else if (x < 0)
            flow.add(u, sink, -x);
    };
    for (int i = 0; i < n; ++i) {
        ll l, r, a, b, c;
        cin >> l >> r >> a >> b >> c;
        auto f = [&](ll x) { return a * x * x + b * x + c; };
        ll inside = max(f(l + 1), f(r - 1));
        if (a < 0) {
            ll center = -b / (2 * a);
            for (ll x = center - 2; x <= center + 2; ++x)
                if (l < x && x < r)
                    inside = max(inside, f(x));
        }
        ll endpoint = max(f(l), f(r));
        weight(i, inside);
        weight(i + n, endpoint - inside);
        flow.add(i + n, i, INF);
    }
    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        --x;
        --y;
        flow.add(y + (z == 2 ? n : 0), x, INF);
    }
    cout << positives - flow.run(source, sink) << '\n';
}
```
