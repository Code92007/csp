---
title: "CSP 201703 五题题解"
contest: "201703"
contest_month: "2017-03"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "顺序模拟", "分组", "数组", "模拟", "Markdown", "字符串解析", "递归", "并查集", "排序", "最小瓶颈路径", "最小割", "网格图", "动态规划"]
status: "published"
problems: [{"id": "A", "title": "分蛋糕", "tags": ["顺序模拟", "分组"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703A/"}]}, {"id": "B", "title": "学生排队", "tags": ["数组", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703B/"}]}, {"id": "C", "title": "Markdown", "tags": ["Markdown", "字符串解析", "递归"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703C/"}]}, {"id": "D", "title": "地铁修建", "tags": ["并查集", "排序", "最小瓶颈路径"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703D/"}]}, {"id": "E", "title": "引水入城", "tags": ["最小割", "网格图", "动态规划"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；4 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703E/"}]}]
---

# CSP 201703 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 分蛋糕

标签：`顺序模拟` · `分组`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

按编号依次分整块蛋糕给朋友，当前朋友累计重量达到k就换下一个；蛋糕全部分完时即便最后一人不足k，也算分到。求人数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703A/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703A)。

### 题解

累加当前朋友所得重量，达到k时人数加一并把当前重量清零。处理完若当前重量仍大于0，再把最后一人计入。

清零表示换人，超过k的部分仍属于上一人的整块蛋糕，不能把超出部分转给下一人。循环逐块执行题意，时间 $O(n)$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int current = 0, answer = 0;
    while (n--) {
        int x;
        cin >> x;
        current += x;
        if (current >= k) {
            ++answer;
            current = 0;
        }
    }
    if (current > 0)
        ++answer;
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 学生排队

标签：`数组` · `模拟`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

学生初始按学号1…n排队。每次指定学号p，向后移动q个位置（q<0为向前），输入保证合法。输出最终学号顺序，n、操作数≤1000。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703B/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703B)。

### 题解

用vector存队伍，每次先find找到学号p的当前下标i，删除该元素，再在下标i+q处插入p。前后移动都用同一公式，插入位置可以是新数组末尾。

删除后，其余学生相对顺序不变；在目标下标插入恰好跨过q名学生，符合调整规则。特别注意p是学号，不是当前队伍位置。每次查找和移动均 $O(n)$，总时间 $O(nm)$，空间 $O(n)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    while (m--) {
        int p, q;
        cin >> p >> q;
        int index = find(a.begin(), a.end(), p) - a.begin();
        a.erase(a.begin() + index);
        a.insert(a.begin() + index + q, p);
    }
    for (int i = 0; i < n; i++) {
        if (i)
            cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}
```

<a id="problem-c"></a>

## C. Markdown

标签：`Markdown` · `字符串解析` · `递归`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

把题目规定的简化 Markdown 转成 HTML：支持段落、1—6 级标题、单层无序列表，以及强调和超链接。两种行内格式可相互嵌套，各自不超过一层。输入块之间有空行，输出删除块间空行，保留段落内部换行。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703C/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703C)。

### 题解

先以空行分块，依据块第一行判断段落、标题或列表。段落只在整块首尾加 p 标签；标题数井号并跳过其后空格；列表前后加 ul，每行去掉星号及其后空格再包 li。

行内从左向右扫描：下划线交替输出 em 开闭标签；左方括号读取链接文字和地址，地址原样放入 href，链接文字递归做行内转换。外层强调状态在处理整个链接时保留，从而同时支持“强调包含链接”和“链接文字包含强调”。输入保证语法合法，普通文本不含需 HTML 转义的特殊符号。

分块转换符合三类区块定义，行内递归按语法层次替换且不重复处理生成的标签。总时间与输入和输出长度线性相关，空间为当前块及递归临时字符串；题目限制嵌套层数，递归深度为常数。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string inlineHTML(const string &s) {
    string out;
    bool em = false;
    for (size_t i = 0; i < s.size();) {
        if (s[i] == '_') {
            out += em ? "</em>" : "<em>";
            em = !em;
            ++i;
        } else if (s[i] == '[') {
            size_t end = s.find(']', i), close = s.find(')', end + 2);
            out += "<a href=\"" + s.substr(end + 2, close - end - 2) + "\">" +
                   inlineHTML(s.substr(i + 1, end - i - 1)) + "</a>";
            i = close + 1;
        } else
            out += s[i++];
    }
    return out;
}
string skipPrefix(const string &s, size_t p) {
    while (p < s.size() && s[p] == ' ')
        ++p;
    return s.substr(p);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> block;
    auto render = [&]() {
        if (block.empty())
            return;
        if (block[0][0] == '#') {
            size_t k = block[0].find_first_not_of('#');
            string tag = "h" + to_string(k);
            cout << '<' << tag << '>' << inlineHTML(skipPrefix(block[0], k)) << "</" << tag
                 << ">\n";
        } else if (block[0][0] == '*') {
            cout << "<ul>\n";
            for (auto &s : block)
                cout << "<li>" << inlineHTML(skipPrefix(s, 1)) << "</li>\n";
            cout << "</ul>\n";
        } else {
            cout << "<p>";
            for (size_t i = 0; i < block.size(); i++) {
                if (i)
                    cout << '\n';
                cout << inlineHTML(block[i]);
            }
            cout << "</p>\n";
        }
        block.clear();
    };
    string s;
    while (getline(cin, s)) {
        if (s.empty())
            render();
        else
            block.push_back(s);
    }
    render();
}
```

<a id="problem-d"></a>

## D. 地铁修建

标签：`并查集` · `排序` · `最小瓶颈路径`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

候选隧道连接 n 个交通枢纽，每条边施工天数已知，各隧道可同时施工。选出能从 1 到 n 的线路，求最短完工时间。输入 n,m 和 m 条 `u v 天数`；$n\le10^5,m\le2\times10^5$，保证连通。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703D/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703D)。

### 题解

一条线路的所有隧道同时开工，所以完工时间是边权的最大值，不是边权之和。给定天数 T，问题等价于只允许使用权值不超过 T 的边时，1 与 n 是否连通。

将边按时间升序排序，依次用并查集合并端点。第一次 1 与 n 同属一个集合时，当前边权就是答案：此时已找到全部边权不超过该值的线路；更小值对应的边此前已经全部处理，仍不连通，所以不可能更早完成。

时间 $O(m\log m+m\alpha(n))$，空间 $O(n+m)$。n=1 时起点就是终点，答案为 0。这个做法与 Kruskal 共用“排序加并查集”，但这里只需等两个指定点连通，不必把整棵生成树建完。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct Edge {
    int u, v, w;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    vector<int> parent(n + 1), size(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
    auto find = [&](int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    for (auto e : edges) {
        int u = find(e.u), v = find(e.v);
        if (u != v) {
            if (size[u] < size[v])
                swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
        if (find(1) == find(n)) {
            cout << e.w << '\n';
            break;
        }
    }
}
```

<a id="problem-e"></a>

## E. 引水入城

标签：`最小割` · `网格图` · `动态规划`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；4 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。

### 题意

$n\times m$ 的管网中，第一行是水源，最后一行是城市。竖直向下有容量限制，向上容量无限；中间各行的水平边双向都有给定容量。求最大引水量。输入 `n m A B Q X0`，按 $X_{i+1}=(AX_i+B)\bmod Q$ 生成竖边容量，再生成横边容量，均按题面行优先顺序。$n,m\le5000$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703E/)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703E)。

### 题解

**从最大流转成最小割。** 因为向上边容量无限，任何有限割的源侧在每一列都必须是从第一行开始的一段前缀。否则某个源侧点上方是汇侧，会切断一条无限容量边。设第 $j$ 列前缀高度为 $h_j\in[1,n-1]$，就把一个巨大网络的割压成了每列一个整数。

第 $j$ 列贡献竖边容量 $V_j[h_j]$。相邻列高度若为 $a,b$，在两高度之间的水平边恰好跨割，额外代价是这些水平容量之和。故

$$dp_j[b]=V_j[b]+\min_a\{dp_{j-1}[a]+\text{高度a到b之间的水平容量和}\}.$$

这个最小值不必 $O(n^2)$ 枚举。固定列间边，把上一列的 `dp` 从上往下松弛一次，再从下往上松弛一次，相当于求一条非负加权链上的多源最短路。得到全部高度的最优接入费用后，加上本列对应竖边容量。

**正确性。** 每个有限割唯一对应各列前缀高度，反之任何高度序列都给出有限割。DP 精确计算所有这类割的最小容量，由最大流最小割定理就是最大引水量。

**复杂度。** 生成与计算均为 $O(nm)$，保存容量需要 $O(nm)$ 空间，DP 本身只用 $O(n)$。代码按输入要求生成，再按列布局保存，方便连续扫描。第一项容量是 $X_1$，不是 $X_0$；生成器乘法和答案都需要 64 位。

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
    int n, m;
    ll a, b, q, x;
    cin >> n >> m >> a >> b >> q >> x;
    int h = n - 1;
    vector<int> vertical(h * m), horizontal((h - 1) * (m - 1));
    auto next = [&]() {
        x = (a * x + b) % q;
        return int(x);
    };
    for (int row = 0; row < h; ++row)
        for (int col = 0; col < m; ++col)
            vertical[col * h + row] = next();
    for (int row = 0; row < h - 1; ++row)
        for (int col = 0; col < m - 1; ++col)
            horizontal[col * (h - 1) + row] = next();
    vector<ll> dp(h);
    for (int row = 0; row < h; ++row)
        dp[row] = vertical[row];
    for (int col = 1; col < m; ++col) {
        int offset = (col - 1) * (h - 1);
        for (int row = 1; row < h; ++row)
            dp[row] = min(dp[row], dp[row - 1] + horizontal[offset + row - 1]);
        for (int row = h - 2; row >= 0; --row)
            dp[row] = min(dp[row], dp[row + 1] + horizontal[offset + row]);
        for (int row = 0; row < h; ++row)
            dp[row] += vertical[col * h + row];
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}
```
