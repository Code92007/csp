---
title: "CSP 202112 五题题解"
contest: "202112"
contest_month: "2021-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "贡献法", "区间计数", "双指针", "分段函数", "区间统计", "编码", "多项式", "模运算", "模拟", "线段树", "离散化", "懒标记", "点分治", "树状数组", "离线统计", "树上路径"]
status: "published"
problems: [{"id": "A", "title": "序列查询", "tags": ["贡献法", "区间计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16059"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce928a67df0b81749c05d"}}, {"id": "B", "title": "序列查询新解", "tags": ["双指针", "分段函数", "区间统计"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；3 个保存样例/回归用例通过；150 组独立随机对拍通过；数梦 OJ 已提交，结果待核验。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16060"}], "oj": {"status": "submitted", "score": null, "record": "https://oj.shumeng.tech/record/6adce92aa67df0b81749c061"}}, {"id": "C", "title": "登机牌条码", "tags": ["编码", "多项式", "模运算", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 已提交，结果待核验。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16061"}], "oj": {"status": "submitted", "score": null, "record": "https://oj.shumeng.tech/record/6adce92ba67df0b81749c065"}}, {"id": "D", "title": "磁盘文件操作", "tags": ["线段树", "离散化", "懒标记"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16062"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce92da67df0b81749c06b"}}, {"id": "E", "title": "极差路径", "tags": ["点分治", "树状数组", "离线统计", "树上路径"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；数梦 OJ 56 分 Time Exceeded（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16063"}], "oj": {"status": "failed", "score": 56, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6adce96da67df0b81749c18a"}}]
---

# CSP 202112 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 序列查询

标签：`贡献法` · `区间计数`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

0=A[0]<A[1]<…<A[n]<N，f(x)是≤x的A元素最大下标。求0≤x<N的f(x)总和，N可达$10^7$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16059)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112A)。

### 题解

因为序列严格递增，f(x)也等于A[1]…A[n]中≤x的元素个数。换一个统计方向：每个A[i]恰好给x=A[i]…N-1这N-A[i]个查询贡献1，因此答案为Σ(N-A[i])。

这只是交换“遍历查询再数元素”和“遍历元素再数查询”的加法顺序，每对符合A[i]≤x的组合恰好计一次。时间 $O(n)$，额外空间 $O(1)$，无需二分或遍历N个值。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n;
    long long N, answer = 0;
    cin >> n >> N;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        answer += N - a;
    }
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 序列查询新解

标签：`双指针` · `分段函数` · `区间统计`

状态：**已实现**。C++17 编译通过；3 个保存样例/回归用例通过；150 组独立随机对拍通过；数梦 OJ 已提交，结果待核验。

### 题意

A[0]=0<A[1]<…<A[n]<N，f(x) 是不超过 x 的 A 元素的最大下标，g(x)=⌊x/r⌋，r=⌊N/(n+1)⌋。求0≤x<N的 |f(x)-g(x)| 之和，N≤$10^9$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16060)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112B)。

### 题解

f 在相邻 A 之间不变，g 在相邻 r 的倍数之间不变。当前坐标为 x、f(x)=i、g(x)=j 时，下一个变化点为 `next=min(A[i+1],(j+1)*r)`，这一整段贡献 `(next-x)*abs(i-j)`。累加后直接跳到 next。

每段内两函数恒定，所有段又恰好覆盖 [0,N)，所以分段求和等于逐点求和。每次跳跃至少跨过一类断点，总段数 $O(n+N/r)=O(n)$，因为 r 的定义使 N/r<2(n+1)。时间、空间均 $O(n)$，乘积和总误差用64位。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long N;
    cin >> n >> N;
    vector<long long> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = N;
    long long r = N / (n + 1), x = 0, ans = 0;
    int f = 0;
    while (x < N) {
        while (f < n && a[f + 1] <= x)
            ++f;
        long long g = x / r, next = min(a[f + 1], (g + 1) * r);
        ans += (next - x) * llabs(g - f);
        x = next;
    }
    cout << ans << '\n';
}
```

<a id="problem-c"></a>

## C. 登机牌条码

标签：`编码` · `多项式` · `模运算` · `模拟`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 已提交，结果待核验。

### 题意

把大小写字母、数字组成的字符串编码成简化 PDF417 码字。三种模式通过 27、28 切换，每两项组成 30H+L，奇数项补 29；码字前加数据长度，末尾补 900 使数据和校验总数为行宽倍数。校验级别 s 对应 $k=2^{s+1}$ 个校验字，s=-1 时无校验。数据码字数小于 929。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16061)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112C)。

### 题解

先维护当前字符模式，按最短路径切换：进入小写用 27，进入数字用 28；数字到大写用 28，小写到大写必须连续两个 28。收集字符数值后两两配对。注意补 29 与补 900 属于不同阶段，长度码字包括自身及 900 填充，但不包括校验字。

所有多项式计算在模 929 下进行。逐次乘以 $(x-3^i)$ 构造首一多项式 g，数组按降幂存放。给数据多项式末尾补 k 个零，得到 $x^k d(x)$；从最高位开始，用当前系数乘 g 并相减，逐项消掉高次项。

题目定义是 $x^k d=qg-r$，而普通除法得到 $x^k d=qg+\mathrm{rem}$，所以校验字必须取余式系数的相反数，按高次到低次输出。这样数据和校验拼出的多项式被 g 整除，满足全部校验规则。时间 $O(k^2+nk+|S|)$，空间 $O(n+k+|S|)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, s;
    string text;
    cin >> w >> s >> text;
    vector<int> chars;
    int mode = 0;
    for (char c : text) {
        int next = (c >= 'A' && c <= 'Z') ? 0 : (c >= 'a' && c <= 'z') ? 1 : 2;
        if (mode != next) {
            if (next == 1)
                chars.push_back(27);
            else if (next == 2)
                chars.push_back(28);
            else {
                chars.push_back(28);
                if (mode == 1)
                    chars.push_back(28);
            }
            mode = next;
        }
        chars.push_back(c - (mode == 0 ? 'A' : mode == 1 ? 'a' : '0'));
    }
    if (chars.size() % 2)
        chars.push_back(29);
    vector<int> data(1, 0);
    for (size_t i = 0; i < chars.size(); i += 2)
        data.push_back(chars[i] * 30 + chars[i + 1]);
    int k = s < 0 ? 0 : 1 << (s + 1);
    while ((data.size() + k) % w)
        data.push_back(900);
    data[0] = int(data.size());
    for (int x : data)
        cout << x << '\n';
    if (!k)
        return 0;
    // 按降幂顺序存储多项式，每次乘 (x - 3^i)。
    vector<int> g(1, 1);
    int power = 1;
    for (int i = 1; i <= k; i++) {
        power = power * 3 % 929;
        vector<int> next(g.size() + 1);
        for (size_t j = 0; j < g.size(); j++) {
            next[j] = (next[j] + g[j]) % 929;
            next[j + 1] = (next[j + 1] - g[j] * power % 929 + 929) % 929;
        }
        g.swap(next);
    }
    vector<int> rem = data;
    rem.resize(data.size() + k);
    for (size_t i = 0; i < data.size(); i++) {
        int factor = rem[i];
        for (int j = 0; j <= k; j++)
            rem[i + j] = (rem[i + j] - factor * g[j] % 929 + 929) % 929;
    }
    for (size_t i = data.size(); i < rem.size(); i++)
        cout << (929 - rem[i]) % 929 << '\n';
}
```

<a id="problem-d"></a>

## D. 磁盘文件操作

标签：`线段树` · `离散化` · `懒标记`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

磁盘位置为 1 到 $m$，初始空闲且值为 0。`0 id l r x` 从左向右写值 x，遇到首个被其他程序占用的位置停止，输出成功写入的最右位置或 -1。`1 id l r` 仅当整段当前都归 id 时删除；`2 id l r` 仅当整段空闲且上次主人均为 id 时恢复；这两种操作输出 OK/FAIL。`3 p` 输出主人和值，空闲输出 `0 0`。删除不清除历史值。$m\le10^9$，操作数不超过 $2\times10^5$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16062)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112D)。

### 题解

**用带符号主人编号表示历史。** 正数 id 表示被占用，负数 -id 表示已删除、上次属于 id，0 表示从未占用。另行保存数据值，删除与恢复只改变主人编号。这样恢复的条件就是整段状态均为 -id，无需建立额外历史链。

收集所有操作的 l、r+1 边界（点读取也收集 p、p+1），离散化成原磁盘上的连续小段。线段树维护主人状态最小值、最大值，以及正主人编号的最小值和最大值。

删除时检查最小值和最大值均为 id，再整段赋 -id；恢复反之。写入时，正主人集合为空，或全部为当前 id 的节点，都可以整体跳过检查。否则向左右孩子查找第一个不允许写入的叶子，并对它左侧的目标区间执行“主人赋 id、数据赋 x”。原坐标中的最右端点由下一条离散化边界减 1 得到。

主人赋值和数据赋值采用两套独立懒标记：只删除主人时，旧的数据赋值标记仍要保留，之后下传给孩子才能恢复原数据。读到正主人时输出保存的值，否则输出 0 0。

每种状态更新都与题目规则一致；找首个冲突时始终先找左子树，且只跳过全部可写的节点，因此不会越过第一个冲突位置。总时间 $O(k\log k)$，空间 $O(k)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
constexpr int NONE = numeric_limits<int>::max();
struct Info {
    int low = 0, high = 0, min_positive = NONE, max_positive = 0;
};
Info combine(Info a, Info b) {
    return {min(a.low, b.low), max(a.high, b.high), min(a.min_positive, b.min_positive),
            max(a.max_positive, b.max_positive)};
}
struct Node {
    Info info;
    int owner_tag = NONE, value = 0;
    bool value_tag = false;
};
struct Operation {
    int type, id = 0, l, r, value = 0;
};
vector<Node> tree;
void set_owner(int u, int id) {
    tree[u].info = {id, id, id > 0 ? id : NONE, id > 0 ? id : 0};
    tree[u].owner_tag = id;
}
void set_value(int u, int value) {
    tree[u].value = value;
    tree[u].value_tag = true;
}
void push(int u) {
    if (tree[u].owner_tag != NONE) {
        set_owner(u * 2, tree[u].owner_tag);
        set_owner(u * 2 + 1, tree[u].owner_tag);
        tree[u].owner_tag = NONE;
    }
    if (tree[u].value_tag) {
        set_value(u * 2, tree[u].value);
        set_value(u * 2 + 1, tree[u].value);
        tree[u].value_tag = false;
    }
}
Info query(int u, int l, int r, int a, int b) {
    if (a <= l && r <= b)
        return tree[u].info;
    push(u);
    int mid = (l + r) / 2;
    if (b <= mid)
        return query(u * 2, l, mid, a, b);
    if (a > mid)
        return query(u * 2 + 1, mid + 1, r, a, b);
    return combine(query(u * 2, l, mid, a, b), query(u * 2 + 1, mid + 1, r, a, b));
}
int first_foreign(int u, int l, int r, int a, int b, int id) {
    const auto &s = tree[u].info;
    if (r < a || l > b || s.max_positive == 0 || (s.min_positive == id && s.max_positive == id))
        return -1;
    if (l == r)
        return l;
    push(u);
    int mid = (l + r) / 2;
    int left = first_foreign(u * 2, l, mid, a, b, id);
    return left != -1 ? left : first_foreign(u * 2 + 1, mid + 1, r, a, b, id);
}
void update(int u, int l, int r, int a, int b, int id, bool write, int value) {
    if (a <= l && r <= b) {
        set_owner(u, id);
        if (write)
            set_value(u, value);
        return;
    }
    push(u);
    int mid = (l + r) / 2;
    if (a <= mid)
        update(u * 2, l, mid, a, b, id, write, value);
    if (b > mid)
        update(u * 2 + 1, mid + 1, r, a, b, id, write, value);
    tree[u].info = combine(tree[u * 2].info, tree[u * 2 + 1].info);
}
pair<int, int> read(int u, int l, int r, int position) {
    if (l == r) {
        int id = tree[u].info.low;
        return id > 0 ? pair<int, int>{id, tree[u].value} : pair<int, int>{0, 0};
    }
    push(u);
    int mid = (l + r) / 2;
    return position <= mid ? read(u * 2, l, mid, position) : read(u * 2 + 1, mid + 1, r, position);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int programs, disk, k;
    cin >> programs >> disk >> k;
    vector<Operation> ops(k);
    vector<int> coordinates{1, disk + 1};
    for (auto &op : ops) {
        cin >> op.type;
        if (op.type == 3) {
            cin >> op.l;
            op.r = op.l;
        } else {
            cin >> op.id >> op.l >> op.r;
            if (op.type == 0)
                cin >> op.value;
        }
        coordinates.push_back(op.l);
        coordinates.push_back(op.r + 1);
    }
    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
    int n = int(coordinates.size()) - 1;
    tree.resize(4 * n + 4);
    for (auto op : ops) {
        int l = lower_bound(coordinates.begin(), coordinates.end(), op.l) - coordinates.begin();
        int r = int(lower_bound(coordinates.begin(), coordinates.end(), op.r + 1) -
                    coordinates.begin()) -
                1;
        if (op.type == 3) {
            auto [owner, value] = read(1, 0, n - 1, l);
            cout << owner << ' ' << value << '\n';
            continue;
        }
        if (op.type == 0) {
            int blocked = first_foreign(1, 0, n - 1, l, r, op.id),
                end = blocked == -1 ? r : blocked - 1;
            if (end < l)
                cout << -1 << '\n';
            else {
                update(1, 0, n - 1, l, end, op.id, true, op.value);
                cout << coordinates[end + 1] - 1 << '\n';
            }
        } else {
            Info s = query(1, 0, n - 1, l, r);
            int required = op.type == 1 ? op.id : -op.id;
            bool ok = s.low == required && s.high == required;
            cout << (ok ? "OK" : "FAIL") << '\n';
            if (ok)
                update(1, 0, n - 1, l, r, -required, false, 0);
        }
    }
}
```

<a id="problem-e"></a>

## E. 极差路径

标签：`点分治` · `树状数组` · `离线统计` · `树上路径`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；数梦 OJ 56 分 Time Exceeded（复刻评测）。

### 题意

树的顶点编号为 1 至 $n$，编号也是该景点的不满意程度。统计无向简单路径 $(x,y)$，使路径所有编号都位于 $[\min(x,y)-k_1,\max(x,y)+k_2]$。单点路径合法，$(x,y)$ 与 $(y,x)$ 只计一次。输入 `n k1 k2` 及 $n-1$ 条边；$n\le5\times10^5$。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16063)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112E)。

### 题解

**用点分治固定路径经过的中心。** 对当前重心 $c$，每个点 $v$ 记录从 $c$ 到 $v$ 路径上的最小、最大编号 $low_v,high_v$。先统计所有点对，再减去重心同一分支内的点对，剩下的恰好是经过重心的路径；各分支递归处理。

约定两个端点 $x<y$。合法条件拆成四项：

$$low_x\ge x-k_1,\quad low_y\ge x-k_1,$$
$$high_x\le y+k_2,\quad high_y\le y+k_2.$$

其中第一项只约束左端点，第四项只约束右端点。先筛出满足自身约束的候选 $x$、候选 $y$。把候选 $x$ 按 $high_x$ 排序，把候选 $y$ 按编号排序。扫描 $y$ 时，将 $high_x\le y+k_2$ 的 $x$ 插入按编号维护的树状数组，再查询

$$x\le\min(y-1,low_y+k_1)$$

的数量。这同时保证端点顺序和剩下的最小值条件。每次统计完成后撤销插入，避免不同分支之间污染。

**为何减去同分支也成立？** 本层对同分支点对使用的仍是“两个端点到重心路径并集”的条件，正负两次完全相同，必定抵消；真正的较短路径会在后续分治层重新计数。单点路径不进入 $x<y$ 的统计，统一把答案初始化为 $n$。

**复杂度。** 每层的排序和树状数组操作 $O(n\log n)$，重心层数 $O(\log n)$，总时间 $O(n\log^2 n)$，辅助空间 $O(n)$。答案最多 $n(n+1)/2$，必须用 64 位。遍历分量和收集路径信息均用显式栈，能处理长链。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
struct Item {
    int id, low, high;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> bit(n + 1), parent(n + 1), size(n + 1);
    vector<bool> removed(n + 1);
    auto add = [&](int x, int d) {
        for (; x <= n; x += x & -x)
            bit[x] += d;
    };
    auto countPairs = [&](const vector<Item> &items) {
        vector<Item> a, b;
        for (auto x : items) {
            if (x.low >= x.id - k1)
                a.push_back(x);
            if (x.high <= x.id + k2)
                b.push_back(x);
        }
        sort(a.begin(), a.end(), [](Item x, Item y) { return x.high < y.high; });
        sort(b.begin(), b.end(), [](Item x, Item y) { return x.id < y.id; });
        long long answer = 0;
        size_t p = 0;
        for (auto y : b) {
            while (p < a.size() && a[p].high <= y.id + k2) {
                add(a[p].id, 1);
                ++p;
            }
            int bound = min(y.id - 1, y.low + k1);
            for (int x = bound; x > 0; x -= x & -x)
                answer += bit[x];
        }
        for (size_t i = 0; i < p; ++i)
            add(a[i].id, -1);
        return answer;
    };
    long long answer = n;
    vector<int> components{1};
    while (!components.empty()) {
        int start = components.back();
        components.pop_back();
        vector<int> order{start};
        parent[start] = 0;
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i];
            for (int v : g[u])
                if (!removed[v] && v != parent[u]) {
                    parent[v] = u;
                    order.push_back(v);
                }
        }
        int total = order.size(), centroid = start;
        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            int u = *it;
            size[u] = 1;
            int largest = 0;
            for (int v : g[u])
                if (!removed[v] && parent[v] == u) {
                    size[u] += size[v];
                    largest = max(largest, size[v]);
                }
            largest = max(largest, total - size[u]);
            if (largest <= total / 2)
                centroid = u;
        }
        vector<Item> all{{centroid, centroid, centroid}};
        for (int neighbor : g[centroid])
            if (!removed[neighbor]) {
                vector<Item> part;
                vector<tuple<int, int, int, int>> stack{
                    {neighbor, centroid, min(neighbor, centroid), max(neighbor, centroid)}};
                while (!stack.empty()) {
                    auto [u, p, lo, hi] = stack.back();
                    stack.pop_back();
                    part.push_back({u, lo, hi});
                    for (int v : g[u])
                        if (v != p && !removed[v])
                            stack.push_back({v, u, min(lo, v), max(hi, v)});
                }
                answer -= countPairs(part);
                all.insert(all.end(), part.begin(), part.end());
            }
        answer += countPairs(all);
        removed[centroid] = true;
        for (int v : g[centroid])
            if (!removed[v])
                components.push_back(v);
    }
    cout << answer << '\n';
}
```
