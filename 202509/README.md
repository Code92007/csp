---
title: "CSP 202509 五题题解"
contest: "202509"
contest_month: "2025-09"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "几何判断", "定点数", "计数", "矩阵枚举", "差分", "区间并集", "字符串解析", "Huffman", "双端队列", "模拟", "树", "LCA", "可持久化线段树", "mex", "动态规划", "离散凸性", "优先队列", "拉格朗日优化"]
status: "published"
problems: [{"id": "A", "title": "蒙特卡洛", "tags": ["几何判断", "定点数", "计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；3 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce736a67df0b81749b65c"}}, {"id": "B", "title": "水印检查", "tags": ["矩阵枚举", "差分", "区间并集"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce738a67df0b81749b678"}}, {"id": "C", "title": "HTTP 头信息", "tags": ["字符串解析", "Huffman", "双端队列", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce739a67df0b81749b685"}}, {"id": "D", "title": "造题计划（上）", "tags": ["树", "LCA", "可持久化线段树", "mex"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；150 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce73ba67df0b81749b69a"}}, {"id": "E", "title": "造题计划（下）", "tags": ["动态规划", "离散凸性", "优先队列", "拉格朗日优化"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce73ca67df0b81749b6b1"}}]
---

# CSP 202509 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 蒙特卡洛

标签：`几何判断` · `定点数` · `计数`

状态：**已实现**。C++17 编译通过；3 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定正方形[-a,a]²内的n个点，统计位于半径a圆内（含边界）的点数m，输出估计值4m/n。坐标最多两位小数，n、a≤1000。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509A/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202509A)。

### 题解

先把坐标字符串精确转换成百分之一单位的整数，如-3.01变为-301，整数4变为400。圆半径也乘100，然后用64位比较x²+y²≤r²；避免平方根，也避免小数舍入导致圆周点被错误排除。

统一缩放不改变距离与半径的大小关系，因此计数准确。最后仅在4m/n时使用浮点除法。时间 $O(n)$，额外空间 $O(1)$，输出足够小数。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
long long hundredths(string s) {
    bool neg = s[0] == '-';
    if (neg || s[0] == '+')
        s = s.substr(1);
    size_t p = s.find('.');
    long long v = stoll(s.substr(0, p)) * 100;
    if (p != string::npos) {
        string frac = s.substr(p + 1);
        while (frac.size() < 2)
            frac += '0';
        v += stoll(frac);
    }
    return neg ? -v : v;
}
int main() {
    int n, a, inside = 0;
    cin >> n >> a;
    long long r = 100LL * a;
    for (int i = 0; i < n; i++) {
        string sx, sy;
        cin >> sx >> sy;
        long long x = hundredths(sx), y = hundredths(sy);
        inside += x * x + y * y <= r * r;
    }
    cout << fixed << setprecision(8) << 4.0 * inside / n << '\n';
}
```

<a id="problem-b"></a>

## B. 水印检查

标签：`矩阵枚举` · `差分` · `区间并集`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

对 n×n 灰度图选阈值 k，灰度≥k 为白，否则黑。求所有使某个 5×9 子矩阵恰好呈现题定 CSP 图案的 k，范围 0≤k<L，n≤200、L≤65536。图案固定、不旋转、不翻转。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509B/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202509B)。

### 题解

固定一个左上角后，所有白格要求 k≤该格灰度，所有黑格要求 k>该格灰度。因此允许阈值恰是区间 `[黑格最大值+1,白格最小值]`，再与 [0,L-1] 相交。区间为空则该位置无解。

枚举所有位置，每个检查 45 格，把得到的合法闭区间用差分标记。最终前缀和大于 0 的阈值，说明至少一个位置存在水印，依次输出。区间约束既必要又充分，差分求其并集不会遗漏或重复输出。时间 $O(45n^2+L)$，空间 $O(n^2+L)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L;
    cin >> n >> L;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    string pattern[] = {"111111111", "100100101", "100111110", "100001100", "111111100"};
    vector<int> diff(L + 1);
    for (int i = 0; i + 4 < n; i++)
        for (int j = 0; j + 8 < n; j++) {
            int low = 0, high = L - 1;
            for (int u = 0; u < 5; u++)
                for (int v = 0; v < 9; v++) {
                    if (pattern[u][v] == '1')
                        high = min(high, a[i + u][j + v]);
                    else
                        low = max(low, a[i + u][j + v] + 1);
                }
            if (low <= high) {
                ++diff[low];
                --diff[high + 1];
            }
        }
    int sum = 0;
    for (int k = 0; k < L; k++) {
        sum += diff[k];
        if (sum)
            cout << k << '\n';
    }
}
```

<a id="problem-c"></a>

## C. HTTP 头信息

标签：`字符串解析` · `Huffman` · `双端队列` · `模拟`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

模拟简化 HPACK。静态表有 S 项，动态表最多 D 项，新项插在动态表最前面，超限删除末项。指令 1 引用完整条目；2 指定字段名和字段值并加入动态表；3 只输出、不加入。字段名可直接给出或按表索引引用。普通字符串原样输出，HH 开头去掉一个 H；单个 H 开头表示十六进制 Huffman 数据，末字节是补零位数。输出 `key: value`。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509C/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202509C)。

### 题解

先按前序编码重建 Huffman 树：读到 1 后再读一个字符形成叶子；读到 0 则依次递归建立左右子树。解码十六进制串时，最后一字节只表示补零位数，不是内容；剩下的数据按每字节高位到低位沿树行走，到叶子输出字符并回根，最后的补零位不参与解码。

静态表用数组，动态表用 deque；索引 1 到 S 对应静态表，其余减去 S 后对应动态表。每条指令先完整取得当前字段名和字段值，输出后才按类型 2 插入动态表，避免插入造成索引偏移。表中的静态字符串已经是原文，不应再次执行 H 解码；只有指令中的字面量需要解码。

Huffman 树是前缀码，到叶子即确定唯一字符；表更新顺序又与指令一致，因此逐条归纳得到正确输出。时间与输入解码位数、输出字符总数线性相关，动态表操作均为常数次，空间为树与两张表的字符串总量。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <deque>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
struct Node {
    int left = -1, right = -1;
    char symbol = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s, capacity;
    cin >> s >> capacity;
    vector<pair<string, string>> fixed(s);
    for (auto &[key, value] : fixed)
        cin >> key >> value;
    string encoding;
    cin >> encoding;
    vector<Node> tree;
    int position = 0;
    function<int()> parse = [&]() {
        int u = tree.size();
        tree.push_back({});
        char type = encoding[position++];
        if (type == '1')
            tree[u].symbol = encoding[position++];
        else {
            int left = parse(), right = parse();
            tree[u].left = left;
            tree[u].right = right;
        }
        return u;
    };
    int root = parse();
    auto hex = [](char c) { return c <= '9' ? c - '0' : c - 'a' + 10; };
    auto decode = [&](const string &input) {
        if (input[0] != 'H')
            return input;
        if (input.size() > 1 && input[1] == 'H')
            return input.substr(1);
        int bytes = (input.size() - 1) / 2,
            padding = hex(input[input.size() - 2]) * 16 + hex(input.back());
        int bits = (bytes - 1) * 8 - padding;
        string result;
        int u = root;
        for (int i = 0; i < bits; ++i) {
            int bit = (hex(input[1 + i / 4]) >> (3 - i % 4)) & 1;
            u = bit ? tree[u].right : tree[u].left;
            if (tree[u].symbol) {
                result += tree[u].symbol;
                u = root;
            }
        }
        return result;
    };
    deque<pair<string, string>> dynamic;
    auto lookup = [&](int index) { return index <= s ? fixed[index - 1] : dynamic[index - s - 1]; };
    int n;
    cin >> n;
    while (n--) {
        int type, index;
        cin >> type >> index;
        pair<string, string> header;
        if (type == 1)
            header = lookup(index);
        else {
            string value;
            if (index == 0) {
                string key;
                cin >> key;
                header.first = decode(key);
            } else
                header.first = lookup(index).first;
            cin >> value;
            header.second = decode(value);
        }
        cout << header.first << ": " << header.second << '\n';
        if (type == 2) {
            dynamic.push_front(header);
            if (int(dynamic.size()) > capacity)
                dynamic.pop_back();
        }
    }
}
```

<a id="problem-d"></a>

## D. 造题计划（上）

标签：`树` · `LCA` · `可持久化线段树` · `mex`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；150 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定一棵 $n$ 个点的树，每个点有一个权值，所有权值恰为 $0,1,\ldots,n-1$ 的排列。每次询问两点之间简单路径上的权值集合的 mex，即最小未出现的非负整数。输入 $n,m$、点权、$n-1$ 条边和 $m$ 对查询端点；每个查询输出一个整数。$n,m\le2\times10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509D/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202509D)。

### 题解

**把树上路径拆成四条根路径。** 任取 1 为根，建立每个点 $u$ 对应的版本，记录从根到 $u$ 所有权值的出现次数。若 $w=\operatorname{LCA}(u,v)$，查询路径的计数就是版本 $u+v-w-\operatorname{parent}(w)$；空节点 0 的版本全为零。这样公共祖先恰好保留一次。

每个版本用可持久化线段树保存权值区间的计数。插入当前点权时，只复制根到叶的一条链，旧节点供其他版本共享。树的遍历用队列式数组完成，避免链状输入导致 DFS 栈溢出；LCA 用倍增。

**在线段树上找第一个空缺。** 值域取 $[0,n]$，因为 $n$ 一定没有出现。若当前左半区间包含的权值个数等于左半区间长度，则其每个数都在路径上，mex 必在右边；否则向左走。这个判定严格依赖“全局权值互不相同”：若允许重复，计数等于长度不再代表全部出现。

四版本相减恰好得到路径上的集合；每一步都保留含有最小缺失值的半区间，因此最后的叶子就是 mex。总时间 $O((n+m)\log n)$，空间 $O(n\log n)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <array>
#include <iostream>
#include <vector>
using namespace std;
constexpr int LOG = 20;
struct Node {
    int left = 0, right = 0, count = 0;
};
vector<Node> seg(1);
int insert(int old, int l, int r, int x) {
    int u = seg.size();
    seg.push_back(seg[old]);
    ++seg[u].count;
    if (l < r) {
        int mid = (l + r) / 2;
        if (x <= mid)
            seg[u].left = insert(seg[old].left, l, mid, x);
        else
            seg[u].right = insert(seg[old].right, mid + 1, r, x);
    }
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), root(n + 1), depth(n + 1);
    vector<array<int, LOG>> up(n + 1);
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    seg.reserve(size_t(n) * (LOG + 1));
    vector<int> order{1};
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        root[u] = insert(root[up[u][0]], 0, n, a[u]);
        for (int j = 1; j < LOG; ++j)
            up[u][j] = up[up[u][j - 1]][j - 1];
        for (int v : graph[u]) {
            if (v == up[u][0])
                continue;
            up[v][0] = u;
            depth[v] = depth[u] + 1;
            order.push_back(v);
        }
    }
    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        int difference = depth[u] - depth[v];
        for (int j = 0; j < LOG; ++j)
            if (difference >> j & 1)
                u = up[u][j];
        if (u == v)
            return u;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        return up[u][0];
    };
    while (m--) {
        int u, v;
        cin >> u >> v;
        int w = lca(u, v);
        array<int, 4> roots{root[u], root[v], root[w], root[up[w][0]]};
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int count = seg[seg[roots[0]].left].count + seg[seg[roots[1]].left].count -
                        seg[seg[roots[2]].left].count - seg[seg[roots[3]].left].count;
            bool full = count == mid - l + 1;
            for (int &rt : roots)
                rt = full ? seg[rt].right : seg[rt].left;
            if (full)
                l = mid + 1;
            else
                r = mid;
        }
        cout << l << '\n';
    }
}
```

<a id="problem-e"></a>

## E. 造题计划（下）

标签：`动态规划` · `离散凸性` · `优先队列` · `拉格朗日优化`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

共 $n$ 天，第 $i$ 天上午至多造一题、费用 $a_i$，下午至多验一题、费用 $b_i$。验题之前必须已经造好，同一天上午造的题可以下午验。给定预算 $m$，求最多完成的题数。输入 `n m`，然后两行费用。$n\le5\times10^5$，费用在 $[1,10^9]$，预算不超过 $10^{18}$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509E/)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202509E)。

### 题解

**从余额 DP 开始。** 余额 $h$ 表示已造未验的题数，始终不能为负。若固定完成题数，直接 DP 要同时记天数、余额和完成数，规模太大。给每完成一题奖励 $\lambda$，把验题费用改成 $b_i-\lambda$，只需最小化“真实费用减奖励”。

设当前 $F(h)$ 为余额 $h$ 的最小调整费用。它是离散凸函数，即相邻差 $D_h=F(h)-F(h-1)$ 不递减。用一个小根堆保存全部斜率，并另外保存 $F(0)$。上午可以不造或造一题，转移是与序列 $(0,a_i)$ 做最小卷积，等价于把斜率 $a_i$ 插入堆。下午令 $c=b_i-\lambda$：若最小斜率 $d$ 满足 $d+c<0$，则把 $F(0)$ 加上 $d+c$，弹出 $d$，插入 $-c$；否则保持。这来自 $F_{new}(h)=\min(F(h),F(h+1)+c)$：相邻候选在斜率首次超过 $-c$ 处切换，斜率多重集恰好替换一次。

**同时恢复题数。** 堆元素和 $F(0)$ 都用二元组 `(调整费用, -完成数)`，按字典序比较。费用相等时选择完成数最多的方案。加减二元组就是对整个目标函数做相同运算，最终从第二维恢复完成数，再加回奖励得到真实费用。

**预算对应哪个断点？** 固定完成数的最小费用 $C(k)$ 是整数离散凸函数；可将它看作单位容量费用流的最小费用，逐次增广的边际费用不减。二分最大的整数奖励 `lo`，使所选方案仍在预算内；下一个奖励 `hi=lo+1` 对应一段边际费用都等于 `hi` 的题目。若 `lo` 得到 $(cost,count)$，还可多做 $\lfloor(m-cost)/hi\rfloor$ 题。先判断全部题都能完成的情况，避免没有右边界。

**复杂度。** 每次参数求解 $O(n\log n)$，总计 $O(n\log n\log(2\times10^9))$，空间 $O(n)$。费用、预算和乘积使用 64 位整数。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<ll, int>; // adjusted cost, negative number of completed tasks
P operator+(P a, P b) {
    return {a.first + b.first, a.second + b.second};
}
P operator-(P a) {
    return {-a.first, -a.second};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll budget;
    cin >> n >> budget;
    vector<ll> a(n), b(n);
    ll full = 0;
    for (auto &x : a) {
        cin >> x;
        full += x;
    }
    for (auto &x : b) {
        cin >> x;
        full += x;
    }
    if (full <= budget) {
        cout << n << '\n';
        return 0;
    }
    auto evaluate = [&](ll reward) {
        priority_queue<P, vector<P>, greater<P>> slopes;
        P base{0, 0};
        for (int i = 0; i < n; ++i) {
            slopes.push({a[i], 0});
            P finish{b[i] - reward, -1};
            P change = slopes.top() + finish;
            if (change < P{0, 0}) {
                base = base + change;
                slopes.pop();
                slopes.push(-finish);
            }
        }
        ll count = -base.second;
        return pair<ll, ll>{base.first + reward * count, count};
    };
    ll lo = 0, hi = 2000000001LL;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (evaluate(mid).first <= budget)
            lo = mid;
        else
            hi = mid;
    }
    auto [cost, count] = evaluate(lo);
    // All additional tasks at the next breakpoint have marginal cost hi.
    cout << count + (budget - cost) / hi << '\n';
}
```
