---
title: "CSP 202603 五题题解"
contest: "202603"
contest_month: "2026-03"
date: "2026-10-23"
updated: "2026-10-24"
tags: ["CSP", "位运算", "计数", "0/1背包", "分数背包", "贪心", "模拟", "内存分配", "有序集合", "数位", "线段树", "懒标记", "树链剖分", "树状数组", "随机化", "在线查询"]
status: "published"
problems: [{"id": "A", "title": "平衡数", "tags": ["位运算", "计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603A/"}]}, {"id": "B", "title": "机器人项目管理", "tags": ["0/1背包", "分数背包", "贪心"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；3 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603B/"}]}, {"id": "C", "title": "进程通信", "tags": ["模拟", "内存分配", "有序集合"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603C/"}]}, {"id": "D", "title": "异或", "tags": ["数位", "线段树", "懒标记"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603D/"}]}, {"id": "E", "title": "旅游计划 - Easy Ver.", "tags": ["树链剖分", "树状数组", "随机化", "在线查询"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603E/"}]}]
---

# CSP 202603 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 平衡数

标签：`位运算` · `计数`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

统计给定正整数中，二进制有效位里0和1数量相同的数。最高位之前的补零不计，数值≤$10^9$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603A/)。

### 题解

每次用x&1取得最低位、右移一位，直到x变为0；同时统计处理位数bits和其中1的个数ones。当2*ones==bits时，0的个数bits-ones与1相等。

循环恰好处理从最低位到最高位1之间的全部有效位，所以不会计入前导零。时间 $O(n\log A)$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n, answer = 0;
    cin >> n;
    while (n--) {
        int x, ones = 0, bits = 0;
        cin >> x;
        while (x) {
            ones += x & 1;
            ++bits;
            x >>= 1;
        }
        answer += 2 * ones == bits;
    }
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 机器人项目管理

标签：`0/1背包` · `分数背包` · `贪心`

状态：**已实现**。C++17 编译通过；3 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

n 个任务的初始总耗时为各自 t 之和。普通任务消耗 a 杯咖啡才可缩短 b，不能部分购买；灵活任务可购买任意实数杯，按比例缩短，至多购买 a 杯。预算 m≤1000，n≤200，求最短总时间。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603B/)。

### 题解

先最大化节省时间。普通任务用 0/1 背包，dp[j] 表示预算至多 j 时的最大收益，容量必须倒序更新，避免同一任务重复购买。

灵活任务按 b/a 从高到低购买。若低效率任务已买而高效率任务尚未买满，把一点预算换给后者不会变差，因此该贪心最优。预处理每个整数预算的灵活收益 gain：容量 a 为整数，按效率顺序每次追加一杯的收益 b/a，就能得到所有整数预算结果。

普通部分实际费用一定为整数，所以枚举普通预算 j，取 `dp[j]+gain[m-j]` 最大值，覆盖所有最优分配。结果为初始总耗时减去最大节省。时间 $O(nm+n\log n)$，空间 $O(m+n)$；最终使用浮点数并保留足够小数。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    long long total = 0;
    vector<long long> dp(m + 1);
    vector<pair<int, int>> flex;
    while (n--) {
        int o, t, a, b;
        cin >> o >> t >> a >> b;
        total += t;
        if (!o)
            flex.push_back({a, b});
        else
            for (int j = m; j >= a; j--)
                dp[j] = max(dp[j], dp[j - a] + b);
    }
    sort(flex.begin(), flex.end(),
         [](auto x, auto y) { return 1LL * x.second * y.first > 1LL * y.second * x.first; });
    vector<long double> gain(m + 1);
    int used = 0;
    for (auto [a, b] : flex)
        for (int j = 0; j < a && used < m; j++) {
            gain[used + 1] = gain[used] + (long double)b / a;
            ++used;
        }
    while (used < m) {
        gain[used + 1] = gain[used];
        ++used;
    }
    long double best = 0;
    for (int j = 0; j <= m; j++)
        best = max(best, dp[j] + gain[m - j]);
    cout << fixed << setprecision(8) << total - best << '\n';
}
```

<a id="problem-c"></a>

## C. 进程通信

标签：`模拟` · `内存分配` · `有序集合`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

有 n 个进程与从地址 0 开始的无限空闲内存。`new p L` 建立长度 L 的队列：选择能容纳它的最短连续空闲段，同长取最左段，并从左端分配，输出起点。`send p` 向该进程所有队列各写一个对象，首次写起点，此后循环写下一个地址，输出本次写入地址之和。`delete p i` 删除第 i 个队列，释放内存并让后面的接口编号减一。$n\le100,q\le8000,L\le5\times10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603C/)。

### 题解

不需要存储内存中的每个字节：题目只询问分配地址和循环写指针。每个队列保存起点、长度、下一次写入的相对位置；发送后把指针加一对长度取模。

有限空洞用两份索引保存：map 按起点排序，set 按 `(长度,起点)` 排序。分配时在 set 中 lower_bound 找到最优空洞，删除它并加入分配后的剩余段；找不到时从无限尾段起点 tail 分配。释放时在 map 中找左右相邻空洞，若端点相接则合并；若合并后连接 tail，直接把 tail 向左移，不再保存有限空洞。

两份索引始终一一对应并只保存极大空闲段，所以 set 中第一个满足长度的元素恰是题意选择。队列向量的顺序就是接口编号，删除元素自然使后续编号减一。总时间保守为 $O(q^2+q\log q)$，空间 $O(n+q)$；地址和地址和必须用 64 位。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using i64 = long long;
struct Queue {
    i64 start, length, next = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<Queue>> processes(n + 1);
    map<i64, i64> free_by_start;
    set<pair<i64, i64>> free_by_size;
    i64 tail = 0;
    auto erase = [&](map<i64, i64>::iterator it) {
        free_by_size.erase({it->second, it->first});
        free_by_start.erase(it);
    };
    auto insert = [&](i64 l, i64 length) {
        if (length) {
            free_by_start[l] = length;
            free_by_size.insert({length, l});
        }
    };
    while (q--) {
        string op;
        int p;
        cin >> op >> p;
        if (op == "new") {
            i64 length, start;
            cin >> length;
            auto it = free_by_size.lower_bound({length, -1});
            if (it == free_by_size.end()) {
                start = tail;
                tail += length;
            } else {
                auto [available, l] = *it;
                start = l;
                erase(free_by_start.find(l));
                insert(l + length, available - length);
            }
            processes[p].push_back({start, length, 0});
            cout << start << '\n';
        } else if (op == "send") {
            i64 sum = 0;
            for (auto &queue : processes[p]) {
                sum += queue.start + queue.next;
                queue.next = (queue.next + 1) % queue.length;
            }
            cout << sum << '\n';
        } else {
            int index;
            cin >> index;
            --index;
            auto queue = processes[p][index];
            processes[p].erase(processes[p].begin() + index);
            i64 l = queue.start, r = l + queue.length;
            auto after = free_by_start.lower_bound(l);
            if (after != free_by_start.begin()) {
                auto before = prev(after);
                if (before->first + before->second == l) {
                    l = before->first;
                    erase(before);
                }
            }
            after = free_by_start.lower_bound(r);
            if (after != free_by_start.end() && after->first == r) {
                r += after->second;
                erase(after);
            }
            if (r == tail)
                tail = l;
            else
                insert(l, r - l);
        }
    }
}
```

<a id="problem-d"></a>

## D. 异或

标签：`数位` · `线段树` · `懒标记`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

把两个数写成奇数 $k$ 进制，每一位相加后对 $k$ 取模，得到运算 $\oplus_k$。定义 $f(0)=0$、$f(x)=x\oplus_k f(x-1)$。

输入 $n,m,k$、长度为 $n$ 的数组，随后执行 $m$ 次操作：`1 l r v` 将区间内所有元素与 $v$ 做 $\oplus_k$；`2 l r` 输出区间内所有 $f(a_i)$ 的 $\oplus_k$。$n\le5\times10^5,m\le10^4$，$11\le k\le10^9$ 且为奇数，数值不超过 $10^{12}$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603D/)。

### 题解

**先消去函数递推。** 设 $x$ 的数位为 $d_0,d_1,\ldots$。$f(x)$ 的每一位，就是 $0$ 到 $x$ 在这一位的数字之和对 $k$ 取模。最低位每完整循环的和为 $k(k-1)/2$；由于 $k$ 是奇数，这个和是 $k$ 的倍数。因此最低位只剩 $d_0(d_0+1)/2$。

对第 $j>0$ 位，每个完整数字块出现 $k^j$ 次，贡献也被 $k$ 整除。最后未完成的数字块贡献为 $d_j((x\bmod k^j)+1)$，模 $k$ 后就是 $d_j(d_0+1)$。

**把需要的统计量放进线段树。** 每段维护 $S_j=\sum d_j$ 和 $P_j=\sum d_0d_j$；其中 $P_0$ 是平方和。查询的最低位为 $(P_0+S_0)/2$，其余位为 $P_j+S_j$，全都对 $k$ 取模。这里除以 2 必须乘模逆元 $(k+1)/2$，不能在取模之后用整数除法。

更新的各位增量记作 $c_j$，段长记作 $L$。展开乘法得到

$$P'_j=P_j+c_0S_j+c_jS_0+Lc_0c_j,\qquad S'_j=S_j+Lc_j\pmod k.$$

代码先更新全部乘积和，再更新数位和，确保公式中的 $S$ 都来自旧状态。懒标记按数位相加即可合并。建立时逐叶计算统计量，合并时相加；更新公式与逐元素操作完全一致，由归纳可知节点始终保存正确统计量，查询拼接后便得到答案。

设数位数为 $D\le12$，建树 $O(nD)$，每次操作 $O(D\log n)$，空间 $O(nD)$。中间乘积使用 64 位，并在连续乘法之间取模。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;
constexpr int DIGITS = 12;
struct Node {
    array<i64, DIGITS> sum{}, product{}, lazy{};
};
int n, q, digits, base;
i64 mod;
vector<Node> tree;
array<i64, DIGITS> split(i64 x) {
    array<i64, DIGITS> a{};
    for (int j = 0; j < digits; ++j) {
        a[j] = x % mod;
        x /= mod;
    }
    return a;
}
void pull(int u) {
    for (int j = 0; j < digits; ++j) {
        tree[u].sum[j] = (tree[u * 2].sum[j] + tree[u * 2 + 1].sum[j]) % mod;
        tree[u].product[j] = (tree[u * 2].product[j] + tree[u * 2 + 1].product[j]) % mod;
    }
}
void apply(int u, int len, const array<i64, DIGITS> &shift) {
    Node &t = tree[u];
    // product[0] is the sum of squares. Preserve all old sums until products are updated.
    for (int j = 0; j < digits; ++j) {
        t.product[j] = (t.product[j] + shift[0] * t.sum[j] + shift[j] * t.sum[0] +
                        (shift[0] * shift[j] % mod) * len) %
                       mod;
    }
    for (int j = 0; j < digits; ++j) {
        t.sum[j] = (t.sum[j] + shift[j] * len) % mod;
        t.lazy[j] = (t.lazy[j] + shift[j]) % mod;
    }
}
void push(int u, int len) {
    bool any = false;
    for (int j = 0; j < digits; ++j)
        any |= tree[u].lazy[j] != 0;
    if (!any)
        return;
    apply(u * 2, len / 2, tree[u].lazy);
    apply(u * 2 + 1, len / 2, tree[u].lazy);
    tree[u].lazy.fill(0);
}
void update(int u, int l, int r, int a, int b, const array<i64, DIGITS> &shift) {
    if (a <= l && r <= b) {
        apply(u, r - l + 1, shift);
        return;
    }
    push(u, r - l + 1);
    int mid = (l + r) / 2;
    if (a <= mid)
        update(u * 2, l, mid, a, b, shift);
    if (b > mid)
        update(u * 2 + 1, mid + 1, r, a, b, shift);
    pull(u);
}
void query(int u, int l, int r, int a, int b, array<i64, DIGITS> &result) {
    if (a <= l && r <= b) {
        for (int j = 0; j < digits; ++j)
            result[j] = (result[j] + tree[u].sum[j] + tree[u].product[j]) % mod;
        return;
    }
    push(u, r - l + 1);
    int mid = (l + r) / 2;
    if (a <= mid)
        query(u * 2, l, mid, a, b, result);
    if (b > mid)
        query(u * 2 + 1, mid + 1, r, a, b, result);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> mod;
    for (i64 x = 1000000000000LL; x; x /= mod)
        ++digits;
    base = 1;
    while (base < n)
        base *= 2;
    tree.resize(base * 2);
    for (int i = 0; i < n; ++i) {
        i64 x;
        cin >> x;
        auto a = split(x);
        tree[base + i].sum = a;
        for (int j = 0; j < digits; ++j)
            tree[base + i].product[j] = a[0] * a[j] % mod;
    }
    for (int u = base - 1; u; --u)
        pull(u);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            i64 v;
            cin >> v;
            update(1, 1, base, l, r, split(v));
        } else {
            array<i64, DIGITS> ans{};
            query(1, 1, base, l, r, ans);
            ans[0] = ans[0] * ((mod + 1) / 2) % mod;
            i64 value = 0;
            for (int j = digits - 1; j >= 0; --j)
                value = value * mod + ans[j];
            cout << value << '\n';
        }
    }
}
```

<a id="problem-e"></a>

## E. 旅游计划 - Easy Ver.

标签：`树链剖分` · `树状数组` · `随机化` · `在线查询`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

树上的每条边最初都未翻修。一辆车在两个维修站之间最多经过一条未修边；起点出发时轮胎完好，到站后才能修复。给定固定的 $m$ 条旅游计划，支持把一条边修好，以及查询可行计划数。输入依次是 `n X`、树边、维修站数和编号、计划数和端点、事件数和事件。`1 u v` 的端点要异或 `X*lastans` 解码，`2` 输出答案。$n,m\le10^5$，站点数 $k\le20$，事件数 $q\le2\times10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603E/)

### 题解

**先拆条件。** 将一条计划按途经的维修站切开，每段允许的未修边数不超过 1。使用 LCA 距离等式判断站点是否在路径上，再按距起点的距离排序。长度不超过 1 的段天生可行；相同端点的段只维护一次，并记录依赖它的计划。站点之间的段最多 $\binom{k}{2}$ 种，其余段每条计划至多两个，因此不同段数 $S\le2m+\binom{k}{2}$。

**用两个见证边监控一个不合格段。** 若某段至少有两条未修边，均匀随机挑出两条，登记在这两条边的事件列表中。其他边被修好时，这两条见证还在，段必定仍不合格；只有见证边被修好才重新检查。重新检查后若剩余未修边不超过 1，就永久标记可行，并把所有依赖计划的未达标段数减一。计划计数降到零时，总答案加一。版本号让旧监听记录自动失效。

树链剖分把路径变成 $O(\log n)$ 个连续区间。树状数组保存边是否未修，边权放在较深端点；区间计数和第 $r$ 条未修边查询用于抽样。不能直接随机抽树上编号，否则不均匀。代码先在全部剩余边的秩中抽两个不同整数，再定位到具体区间。

**正确性与随机性。** 任意两条未修见证就足以证明该段不可行，因此随机选择不会影响答案。所有可行性变化都在某个见证失效时被检测到，也不会漏计；随机性只影响耗时。对一条有 $d$ 条未修边的段，下一次删除命中见证的概率为 $2/d$。由于输出与抽样无关，对固定合法输入，重新检查次数的期望为 $O(\log n)$。这是 Las Vegas 算法，不是蒙特卡洛近似。

**复杂度。** 分段 $O(mk\log n)$；在线维护期望 $O(S\log^3 n+q\log n)$。监听记录期望 $O(S\log n)$，计划与段的依赖关系 $O(mk)$。该版本采用随机化，不能声称确定性最坏界。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <random>
#include <utility>
#include <vector>
using namespace std;
struct Fenwick {
    int n;
    vector<int> t;
    explicit Fenwick(int n) : n(n), t(n + 1) {}
    void add(int x, int v) {
        for (; x <= n; x += x & -x)
            t[x] += v;
    }
    int sum(int x) {
        int s = 0;
        for (; x; x -= x & -x)
            s += t[x];
        return s;
    }
    int kth(int k) {
        int x = 0;
        for (int p = 1 << 17; p; p >>= 1)
            if (x + p <= n && t[x + p] < k) {
                k -= t[x + p];
                x += p;
            }
        return x + 1;
    }
};
struct Segment {
    int u, v, version = 0;
    bool done = false;
    vector<int> users;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, X;
    cin >> n >> X;
    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n + 1), depth(n + 1), size(n + 1, 1), heavy(n + 1), top(n + 1), tin(n + 1),
        at(n + 1), order{1};
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        for (int v : g[u])
            if (v != par[u]) {
                par[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
    }
    for (int i = n - 1; i > 0; --i) {
        int u = order[i], p = par[u];
        size[p] += size[u];
        if (size[u] > size[heavy[p]] || !heavy[p])
            heavy[p] = u;
    }
    int timer = 0;
    vector<pair<int, int>> stack{{1, 1}};
    while (!stack.empty()) {
        auto [u, h] = stack.back();
        stack.pop_back();
        for (; u; u = heavy[u]) {
            top[u] = h;
            tin[u] = ++timer;
            at[timer] = u;
            for (int v : g[u])
                if (par[v] == u && v != heavy[u])
                    stack.push_back({v, v});
        }
    }
    auto lca = [&](int u, int v) {
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            u = par[top[u]];
        }
        return depth[u] < depth[v] ? u : v;
    };
    auto distance = [&](int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; };
    int k;
    cin >> k;
    vector<int> stations(k);
    for (int &u : stations)
        cin >> u;
    int m;
    cin >> m;
    vector<int> missing(m);
    vector<Segment> segments;
    map<pair<int, int>, int> ids;
    for (int plan = 0; plan < m; ++plan) {
        int s, t;
        cin >> s >> t;
        int length = distance(s, t);
        vector<pair<int, int>> points{{0, s}, {length, t}};
        for (int u : stations) {
            int d = distance(s, u);
            if (d + distance(u, t) == length)
                points.push_back({d, u});
        }
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i].first - points[i - 1].first <= 1)
                continue;
            int u = points[i - 1].second, v = points[i].second;
            if (u > v)
                swap(u, v);
            auto [it, newKey] = ids.emplace(make_pair(u, v), int(segments.size()));
            if (newKey)
                segments.push_back({u, v, 0, false, {}});
            segments[it->second].users.push_back(plan);
            ++missing[plan];
        }
    }
    int answer = count(missing.begin(), missing.end(), 0);
    Fenwick bit(n);
    for (int u = 2; u <= n; ++u)
        bit.add(tin[u], 1);
    vector<vector<pair<int, int>>> watch(n + 1);
    mt19937 rng(random_device{}()); // random choices change running time only, never answers
    auto refresh = [&](int id) {
        auto &s = segments[id];
        ++s.version;
        vector<pair<int, int>> pieces;
        int u = s.u, v = s.v, total = 0;
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            pieces.push_back({tin[top[u]], tin[u]});
            u = par[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        if (u != v)
            pieces.push_back({tin[u] + 1, tin[v]});
        vector<int> counts;
        for (auto [l, r] : pieces) {
            int c = bit.sum(r) - bit.sum(l - 1);
            counts.push_back(c);
            total += c;
        }
        if (total <= 1) {
            s.done = true;
            for (int plan : s.users)
                if (--missing[plan] == 0)
                    ++answer;
            return;
        }
        int first = uniform_int_distribution<int>(1, total)(rng);
        int second = uniform_int_distribution<int>(1, total - 1)(rng);
        if (second >= first)
            ++second;
        for (int rank : {first, second}) {
            for (size_t i = 0; i < pieces.size(); ++i) {
                if (rank > counts[i])
                    rank -= counts[i];
                else {
                    int pos = bit.kth(bit.sum(pieces[i].first - 1) + rank);
                    watch[at[pos]].push_back({id, s.version});
                    break;
                }
            }
        }
    };
    for (int i = 0; i < int(segments.size()); ++i)
        refresh(i);
    int q, last = 0;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 2) {
            cout << answer << '\n';
            last = answer;
        } else {
            int u, v;
            cin >> u >> v;
            u ^= X * last;
            v ^= X * last;
            if (depth[u] < depth[v])
                swap(u, v);
            bit.add(tin[u], -1);
            auto events = std::move(watch[u]);
            for (auto [id, version] : events)
                if (!segments[id].done && segments[id].version == version)
                    refresh(id);
        }
    }
}
```
