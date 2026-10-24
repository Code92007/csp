---
title: "CSP 202409 五题题解"
contest: "202409"
contest_month: "2024-09"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "字符分类", "频率统计", "倍增", "函数复合", "字符串", "字符串解析", "KMP", "模拟", "最短路", "Dijkstra", "几何判定", "Treap", "启发式分裂", "哈希表"]
status: "published"
problems: [{"id": "A", "title": "密码", "tags": ["字符分类", "频率统计"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce814a67df0b81749badf"}}, {"id": "B", "title": "字符串变换", "tags": ["倍增", "函数复合", "字符串"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce816a67df0b81749baf4"}}, {"id": "C", "title": "补丁应用", "tags": ["字符串解析", "KMP", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；4 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce817a67df0b81749bb06"}}, {"id": "D", "title": "通讯延迟", "tags": ["最短路", "Dijkstra", "几何判定"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce819a67df0b81749bb1b"}}, {"id": "E", "title": "木板切割", "tags": ["Treap", "启发式分裂", "哈希表"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81aa67df0b81749bb21"}}]
---

# CSP 202409 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 密码

标签：`字符分类` · `频率统计`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

密码保证长度≥6且只含大小写字母、数字、*、#。缺少字母、数字、特殊字符中的任一类为低级0；三类都有但某字符超过两次为中级1；否则高级2。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409A)。

### 题解

一次扫描设置三类是否出现的标志，同时按字符本身计数并记录是否有频次>2。先检查三类齐全，再检查重复条件，按规则输出。

分类条件和频次条件分别完整统计，按安全等级定义组合即可。大小写属于同一“字母类”，但A与a是两个不同字符，频次不能合并。时间 $O(|s|)$，使用固定128格计数数组，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        bool letter = false, digit = false, special = false, repeat = false;
        int count[128] = {};
        for (unsigned char c : s) {
            if (isalpha(c))
                letter = true;
            else if (isdigit(c))
                digit = true;
            else
                special = true;
            if (++count[c] > 2)
                repeat = true;
        }
        cout << (!(letter && digit && special) ? 0 : repeat ? 1 : 2) << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 字符串变换

标签：`倍增` · `函数复合` · `字符串`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定 63 种字符上的替换映射，未定义字符保持不变。查询初始字符串替换 k 次后的结果，k≤$10^9$，至多1000次查询。输入输出用 # 包住字符串，空格也是普通字符。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409B)。

### 题解

预处理 jump[b][c] 表示字符 c 替换 $2^b$ 次的结果，递推 `jump[b][c]=jump[b-1][jump[b-1][c]]`。对每个字符按 k 的二进制位依次应用对应跳跃，最后重新加上外侧井号。

递推是两个相同长度变换的复合，二进制分解又把 k 拆成这些次数之和，因此结果等于连续 k 次替换。每次查询都从原始串出发，不接着上一查询继续变换。用 getline 保留映射和字符串中的空格。时间 $O(128\log K+m|s|\log K)$，空间 $O(128\log K+|s|)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, line;
    getline(cin, s);
    s = s.substr(1, s.size() - 2);
    int jump[31][128];
    for (int c = 0; c < 128; c++)
        jump[0][c] = c;
    int n;
    cin >> n;
    getline(cin, line);
    while (n--) {
        getline(cin, line);
        jump[0][int(line[1])] = line[2];
    }
    for (int b = 1; b < 31; b++)
        for (int c = 0; c < 128; c++)
            jump[b][c] = jump[b - 1][jump[b - 1][c]];
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << '#';
        for (char ch : s) {
            int c = ch;
            for (int b = 0; b < 31; b++)
                if (k & (1 << b))
                    c = jump[b][c];
            cout << char(c);
        }
        cout << "#\n";
    }
}
```

<a id="problem-c"></a>

## C. 补丁应用

标签：`字符串解析` · `KMP` · `模拟`

状态：**已实现**。C++17 编译通过；4 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定原文件与补丁文本。补丁头严格形如 `@@ -NN,MM +nn,mm @@`，四个数为不带前导零的正整数；忽略 nn。块内空格／减号行组成原片段，空格／加号行组成新片段，数量须相符，原声明区间不得重叠。补丁中的 # 开头行忽略，首块前杂项忽略。每块在参考行号附近寻找原片段，偏移绝对值须小于 MM，优先绝对值小、再偏移小；找到后把偏移累加给后续块。失败输出 `Patch is damaged.`。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409C)。

### 题解

先读取原文件，再单独解析补丁。原文件里的 # 是正常内容，不能被当成补丁注释删除。收集并校验所有块后才生成结果，避免前面成功的输出在后面发现损坏后无法撤回。

**始终在原文件行号坐标中匹配。** 保存尚未消耗的原文起点 consumed 和累计行号偏移 offset。当前参考起点为 `NN-1+offset`；搜索 consumed 之后与原片段相同的连续行，比较允许范围内候选的 `(偏移绝对值,偏移)`。找到后输出尚未修改的原文和新片段，推进 consumed，并仅把本次偏移加入 offset。新旧片段行数之差不混入原文件坐标。

把每一行完整字符串映射为整数编号，原片段与原文件变为整数序列。KMP 在线性时间找出所有匹配起点，比较候选时无需反复比较长行。字典映射按完整字符串比较，不会因哈希碰撞把不同文本当成同一行。

consumed 保证块应用区域不重叠，最小候选排序严格对应题意；按原文顺序拼接未修改片段和替换片段，得到正确结果。设块数 B≤25、原文件行数 n≤2000，行编号之后匹配时间 $O(Bn+\text{补丁行数})$，另计读取、哈希和输出的字符总量。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Block {
    long long start, old_count, new_count;
    vector<int> before, after;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    vector<string> text;
    unordered_map<string, int> ids;
    auto id = [&](const string &s) {
        auto it = ids.find(s);
        if (it != ids.end())
            return it->second;
        int x = text.size();
        text.push_back(s);
        ids[s] = x;
        return x;
    };
    vector<int> original(n);
    for (auto &x : original) {
        getline(cin, line);
        x = id(line);
    }
    vector<Block> blocks;
    bool valid = true;
    regex header("^@@ -([1-9][0-9]*),([1-9][0-9]*) \\+([1-9][0-9]*),([1-9][0-9]*) @@$");
    auto number = [](const string &s) {
        long long x = 0;
        for (char c : s) {
            x = x * 10 + c - '0';
            if (x > 1000000000000LL)
                return 1000000000000LL;
        }
        return x;
    };
    while (getline(cin, line)) {
        if (!line.empty() && line[0] == '#')
            continue;
        if (!line.empty() && line[0] == '@') {
            smatch match;
            if (!regex_match(line, match, header)) {
                valid = false;
                break;
            }
            Block b{number(match[1]), number(match[2]), number(match[4]), {}, {}};
            if (!blocks.empty() && b.start < blocks.back().start + blocks.back().old_count) {
                valid = false;
                break;
            }
            blocks.push_back(std::move(b));
        } else if (!blocks.empty()) {
            if (line.empty() || (line[0] != ' ' && line[0] != '+' && line[0] != '-')) {
                valid = false;
                break;
            }
            int value = id(line.substr(1));
            if (line[0] != '+')
                blocks.back().before.push_back(value);
            if (line[0] != '-')
                blocks.back().after.push_back(value);
        }
    }
    if (blocks.empty())
        valid = false;
    for (const auto &b : blocks)
        if (b.old_count != static_cast<long long>(b.before.size()) ||
            b.new_count != static_cast<long long>(b.after.size()))
            valid = false;
    vector<int> result;
    int consumed = 0;
    long long offset = 0;
    if (valid)
        for (const auto &b : blocks) {
            int length = b.before.size();
            vector<int> failure(length);
            for (int i = 1, j = 0; i < length; ++i) {
                while (j && b.before[i] != b.before[j])
                    j = failure[j - 1];
                if (b.before[i] == b.before[j])
                    ++j;
                failure[i] = j;
            }
            long long expected = b.start - 1 + offset,
                      best_delta = numeric_limits<long long>::max();
            int best = -1;
            for (int i = consumed, j = 0; i < n; ++i) {
                while (j && original[i] != b.before[j])
                    j = failure[j - 1];
                if (original[i] == b.before[j])
                    ++j;
                if (j == length) {
                    int start = i - length + 1;
                    long long delta = start - expected;
                    if (abs(delta) < length &&
                        (best == -1 || abs(delta) < abs(best_delta) ||
                         (abs(delta) == abs(best_delta) && delta < best_delta))) {
                        best = start;
                        best_delta = delta;
                    }
                    j = failure[j - 1];
                }
            }
            if (best == -1) {
                valid = false;
                break;
            }
            result.insert(result.end(), original.begin() + consumed, original.begin() + best);
            result.insert(result.end(), b.after.begin(), b.after.end());
            consumed = best + length;
            offset += best_delta;
        }
    if (!valid) {
        cout << "Patch is damaged.\n";
        return 0;
    }
    result.insert(result.end(), original.begin() + consumed, original.end());
    for (int x : result)
        cout << text[x] << '\n';
}
```

<a id="problem-d"></a>

## D. 通讯延迟

标签：`最短路` · `Dijkstra` · `几何判定`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

平面上有 $n$ 个节点和 $m$ 个基站。基站 $(x,y,r,t)$ 覆盖满足 $|X-x|\le r,|Y-y|\le r$ 的节点，包括边界；覆盖内任意两点可用延迟 $t$ 通讯。输入节点坐标和基站参数，求节点 1 到节点 $n$ 的最短延迟，无法到达时输出大小写准确的 `Nan`。$n,m\le5000$，坐标与半径不超过 $10^9$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409D)。

### 题解

一个覆盖 $s$ 个点的基站表示一个完全图，直接添加所有点对会浪费 $O(s^2)$ 条边。可以保留基站覆盖集合，在需要时一次展开。

**Dijkstra 确定一个点 $u$ 的最短距离后，检查尚未用过的基站。** 如果基站覆盖 $u$，就用 $d_u+t$ 松弛它覆盖的所有点，并永久标记该基站已处理。为什么只展开一次？$u$ 是该基站覆盖的点中第一个被确定的点；其余覆盖点的最终距离不会更小，因此以后从它们进入同一基站，代价至少也是 $d_u+t$。第一次展开已提供该基站能够带来的所有最优松弛。

这里直接扫描所有点选取最小未确定距离，使用朴素 Dijkstra。节点和基站都只有 5000，避免大规模堆更新很合适。一个点确定时扫描 $m$ 个基站，一个基站至多扫描 $n$ 个点一次；总时间 $O(n^2+nm)$，只用 $O(n+m)$ 空间，不保存覆盖边。

边权为正，Dijkstra 每次选出的距离正确；结合基站展开的安全性，目标点被确定时即可结束。几何减法和距离用 64 位整数。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
using i64 = long long;
struct Station {
    i64 x, y, r, cost;
    bool used = false;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<i64> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    vector<Station> stations(m);
    for (auto &s : stations)
        cin >> s.x >> s.y >> s.r >> s.cost;
    const i64 INF = numeric_limits<i64>::max() / 4;
    vector<i64> distance(n, INF);
    vector<bool> done(n);
    distance[0] = 0;
    for (int step = 0; step < n; ++step) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!done[i] && (u == -1 || distance[i] < distance[u]))
                u = i;
        if (u == -1 || distance[u] == INF)
            break;
        done[u] = true;
        if (u == n - 1)
            break;
        for (auto &s : stations) {
            if (s.used || abs(x[u] - s.x) > s.r || abs(y[u] - s.y) > s.r)
                continue;
            s.used = true;
            i64 candidate = distance[u] + s.cost;
            for (int v = 0; v < n; ++v)
                if (!done[v] && candidate < distance[v] && abs(x[v] - s.x) <= s.r &&
                    abs(y[v] - s.y) <= s.r)
                    distance[v] = candidate;
        }
    }
    if (distance[n - 1] == INF)
        cout << "Nan\n";
    else
        cout << distance[n - 1] << '\n';
}
```

<a id="problem-e"></a>

## E. 木板切割

标签：`Treap` · `启发式分裂` · `哈希表`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

初始木板含编号 $1\ldots n$ 的段，每段有颜色。第 $i$ 次操作 `x l r` 从木板 $x$ 中切出原始编号在 $[l,r]$ 的全部段，按原顺序形成第 $i+1$ 块木板；剩余段重新连在一起。输出新木板的不同颜色数和连续颜色段数，空木板两者均为 0。段的原始编号始终不变。输入 `n m k`、$n$ 个颜色、$k$ 次操作，三者均不超过 $10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409E)。

### 题解

**维护原始编号，不维护当前排名。** 每块木板用按原编号为键的 Treap 表示。两次 split 将原树分成编号小于 $l$、处于 $[l,r]$、大于 $r$ 三部分；中间成为新板，首尾 merge 回原板。

**连续颜色段可以局部合并。** 每个节点保存子树大小、第一种颜色、最后一种颜色、颜色段数。左右子序列拼接时，若交界两色相同，段数减一。Treap 每次修改后 `pull` 即可，答案从新根直接读取。

**不同颜色数不能简单相加。** 每块板再维护一张颜色频次表。分裂后只遍历较小板上的段，建立小板的新表，同时从原有大表中减去这些频次，计数归零就删除。若切出的板较大，应把原频次表交换给新板，而不是坚持把表留在旧编号下。

**摊还证明。** 每当一个段被遍历，它进入的板大小不超过原板的一半。一个段最多被遍历 $O(\log n)$ 次。哈希表条目用频次保存，重复颜色不会导致漏减。Treap 的随机优先级只影响树高，不影响切割结果。

**复杂度。** 期望时间 $O((n+k)\log n)$；有效颜色记录总数不超过段数。哈希桶可能保留已减少元素的容量，当前实现的空间上界写作 $O(n\log n+k)$，而非保证为严格 $O(n)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;
struct Node {
    int l = 0, r = 0, size = 1, color = 0, first = 0, last = 0, runs = 1;
    unsigned priority = 0;
};
vector<Node> t(1);
int sizeOf(int u) {
    return u ? t[u].size : 0;
}
void pull(int u) {
    auto &x = t[u];
    x.size = 1 + sizeOf(x.l) + sizeOf(x.r);
    x.first = x.l ? t[x.l].first : x.color;
    x.last = x.r ? t[x.r].last : x.color;
    x.runs = 1 + (x.l ? t[x.l].runs - (t[x.l].last == x.color) : 0) +
             (x.r ? t[x.r].runs - (t[x.r].first == x.color) : 0);
}
void split(int u, int key, int &a, int &b) {
    if (!u) {
        a = b = 0;
        return;
    }
    if (u <= key) {
        a = u;
        split(t[u].r, key, t[u].r, b);
        pull(u);
    } else {
        b = u;
        split(t[u].l, key, a, t[u].l);
        pull(u);
    }
}
int join(int a, int b) {
    if (!a || !b)
        return a | b;
    if (t[a].priority < t[b].priority) {
        t[a].r = join(t[a].r, b);
        pull(a);
        return a;
    }
    t[b].l = join(a, t[b].l);
    pull(b);
    return b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    t.resize(n + 1);
    vector<int> roots(k + 2);
    vector<unordered_map<int, int>> freq(k + 2);
    mt19937 rng(94127);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i].color;
        t[i].first = t[i].last = t[i].color;
        t[i].priority = rng();
        roots[1] = join(roots[1], i);
        ++freq[1][t[i].color];
    }
    for (int id = 2; id <= k + 1; ++id) {
        int x, l, r, a, b, c;
        cin >> x >> l >> r;
        split(roots[x], r, b, c);
        split(b, l - 1, a, b);
        roots[x] = join(a, c);
        roots[id] = b;
        int small = id, large = x;
        if (sizeOf(roots[x]) < sizeOf(roots[id])) {
            freq[x].swap(freq[id]);
            small = x;
            large = id;
        }
        vector<int> stack;
        if (roots[small])
            stack.push_back(roots[small]);
        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            int color = t[u].color;
            ++freq[small][color];
            auto it = freq[large].find(color);
            if (--it->second == 0)
                freq[large].erase(it);
            if (t[u].l)
                stack.push_back(t[u].l);
            if (t[u].r)
                stack.push_back(t[u].r);
        }
        cout << freq[id].size() << ' ' << (roots[id] ? t[roots[id]].runs : 0) << '\n';
    }
}
```
