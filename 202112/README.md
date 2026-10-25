---
title: "CSP 202112 五题题解"
contest: "202112"
contest_month: "2021-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "贡献法", "区间计数", "双指针", "分段函数", "区间统计", "编码", "多项式", "模运算", "模拟", "线段树", "离散化", "懒标记", "点分治", "树状数组", "离线统计", "树上路径", "位运算"]
status: "published"
problems: [{"id": "A", "title": "序列查询", "tags": ["贡献法", "区间计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16059"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce928a67df0b81749c05d"}}, {"id": "B", "title": "序列查询新解", "tags": ["双指针", "分段函数", "区间统计"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；3 个保存样例/回归用例通过；150 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16060"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adce92aa67df0b81749c061"}, "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490959"}}, {"id": "C", "title": "登机牌条码", "tags": ["编码", "多项式", "模运算", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16061"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adce92ba67df0b81749c065"}, "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490983"}}, {"id": "D", "title": "磁盘文件操作", "tags": ["线段树", "离散化", "懒标记"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16062"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce92da67df0b81749c06b"}}, {"id": "E", "title": "极差路径", "tags": ["点分治", "树状数组", "离线统计", "树上路径", "位运算"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例、650 组独立全点对路径枚举、3 组解析用例与 13 组 n=500000 上界测试通过；曙梦 OJ 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16063"}], "previous_oj": {"status": "failed", "score": 56, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6addccac74ace1cba9a21f0f", "source_sha256": "fe2c351c465816e460e5a40eacc8102efc31798009081865a5b98656cff8aa70", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305494838", "source_sha256": "fe2c351c465816e460e5a40eacc8102efc31798009081865a5b98656cff8aa70", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6ade046d74ace1cba9a237ab", "source_sha256": "e7b86d3a8fe5877854bb5175dd65572766e7c8592c6c03896d4ab6741d0af312"}}]
---

# CSP 202112 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 序列查询

标签：`贡献法` · `区间计数`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

0=A[0]<A[1]<…<A[n]<N，f(x)是≤x的A元素最大下标。求0≤x<N的f(x)总和，N可达$10^7$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16059)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112A)。

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

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；3 个保存样例/回归用例通过；150 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce92aa67df0b81749c061)（复刻评测）。另有 [洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490959)。

### 题意

A[0]=0<A[1]<…<A[n]<N，f(x) 是不超过 x 的 A 元素的最大下标，g(x)=⌊x/r⌋，r=⌊N/(n+1)⌋。求0≤x<N的 |f(x)-g(x)| 之和，N≤$10^9$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16060)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112B)。

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

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce92ba67df0b81749c065)（复刻评测）。另有 [洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490983)。

### 题意

把大小写字母、数字组成的字符串编码成简化 PDF417 码字。三种模式通过 27、28 切换，每两项组成 30H+L，奇数项补 29；码字前加数据长度，末尾补 900 使数据和校验总数为行宽倍数。校验级别 s 对应 $k=2^{s+1}$ 个校验字，s=-1 时无校验。数据码字数小于 929。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16061)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112C)。

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

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

磁盘位置为 1 到 $m$，初始空闲且值为 0。`0 id l r x` 从左向右写值 x，遇到首个被其他程序占用的位置停止，输出成功写入的最右位置或 -1。`1 id l r` 仅当整段当前都归 id 时删除；`2 id l r` 仅当整段空闲且上次主人均为 id 时恢复；这两种操作输出 OK/FAIL。`3 p` 输出主人和值，空闲输出 `0 0`。删除不清除历史值。$m\le10^9$，操作数不超过 $2\times10^5$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16062)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112D)。

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

标签：`点分治` · `树状数组` · `离线统计` · `树上路径` · `位运算`

状态：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例、650 组独立全点对路径枚举、3 组解析用例与 13 组 n=500000 上界测试通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6ade046d74ace1cba9a237ab)（民间复刻评测）。

### 题意

树的顶点编号为 1 至 $n$，编号也是该景点的不满意程度。统计无向简单路径 $(x,y)$，使路径所有编号都位于 $[\min(x,y)-k_1,\max(x,y)+k_2]$。单点路径合法，$(x,y)$ 与 $(y,x)$ 只计一次。输入 `n k1 k2` 及 $n-1$ 条边；$n\le5\times10^5$。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16063)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112E)。

### 题解

#### 1. 用点分治确定路径经过的中心

取当前连通块的重心 `c`。先统计经过 `c` 的合法路径，再删除 `c`，分别处理剩余分支。每次删去重心后，每个分支至多有原来一半的点，因此只有 `O(log n)` 层。

对每个点 `v`，记录从 `c` 到 `v` 的路径上的最小编号 `low[v]` 和最大编号 `high[v]`。若两个端点属于不同分支，它们的路径经过 `c`，路径最小值就是两个 `low` 的最小值，最大值就是两个 `high` 的最大值。

单点路径统一先计入 `n`。其余路径只统计编号较小的端点 `x` 和较大的端点 `y`，即 `x<y`。

#### 2. 将合法性拆成可以扫描的条件

对于 `x<y`，需要同时满足

$$low_x\ge x-k_1,\quad low_y\ge x-k_1,$$

$$high_x\le y+k_2,\quad high_y\le y+k_2.$$

其中第一项只与 `x` 有关，最后一项只与 `y` 有关。因此先筛出两个候选集合：

- 左端点集合 `A`：满足 `low[x] >= x-k1` 的点；
- 右端点集合 `B`：满足 `high[y] <= y+k2` 的点。

剩余条件可以写成

$$high_x\le y+k_2,\qquad x\le\min(y-1,low_y+k_1).$$

把 `A` 按 `high[x]` 排序，把 `B` 按编号 `y` 排序。扫描 `y` 时，逐步加入所有 `high[x] <= y+k2` 的左端点，然后查询编号不超过 `min(y-1,low[y]+k1)` 的已加入点数。这是一个插入加前缀计数问题，可以用树状数组处理。

#### 3. 保证两个端点来自不同分支

最直接的办法是“统计当前连通块的全部点对，再减去各个分支内部的点对”。同分支点对在加减两次统计中使用相同的 `low/high` 条件，因此会抵消；它们的真实路径交给后面的分治层处理。

树的链形和平衡形结构中，很多重心只有两三个分支。此时可以直接统计互不相交的分支组，减少重复工作：

- 只有两个分支时，只统计这两个分支之间的点对。
- 有三个分支时，设最大的分支为 `L`，其余为 `S,T`，先统计 `L` 与 `S∪T`，再统计 `S` 与 `T`。
- 分支更多时，继续使用全部点对减各分支内部点对。

统计两组之间的点对时，分别做“第一组提供较小端点”和“第二组提供较小端点”两次扫描。因为仍要求 `x<y`，不会重复计数。低度重心自己作为端点的路径直接扫描一次 `low/high` 判定即可。

#### 4. 让前缀计数适应 50 万点规模

**用 64 位整数记录块内成员。** 编号互不相同，每个点在一次统计中最多插入一次。因此可以把每 64 个编号放在一个 `uint64_t` 中，用某一位是否为一表示该编号是否已加入。树状数组只维护每个完整块的点数。

查询前 `r` 个编号时，先查询前 `r/64` 个完整块的总数量，再对下一个块中前 `r%64` 位使用 `popcount`。树状数组的长度由 `n` 缩小到 `ceil(n/64)`，既减少更新步数，也使计数数组更容易留在缓存中。

**提前回答所有左端点都满足阈值的查询。** 设 `H=max(high[x])`，其中 `x∈A`。当一个右端点满足 `y+k2>=H` 时，它对 `high[x]` 的要求已经对所有 `A` 成立，只剩编号上界。可以为整个 `A` 建立静态位图和块前缀和，直接回答这类查询，无须排序和动态插入。

代码仅在这类查询足够多时建立完整块前缀和，将建表开销摊到这些查询上。回答后，把它们从动态扫描中移除；对剩下的查询，不可能达到其最大 `high` 阈值的左候选也可以删除。

**保留简单的局部优化。** 候选集合为空时直接返回；较小的一侧不超过 24 个点时直接枚举。大数组的排序键都在 `1..500000`，可以用两趟 10 位基数排序；小数组使用普通排序。相邻查询若插入数量和查询上界都未改变，复用上一次计数。统计完成后，整批清零用到的位图块和树状数组单元。

#### 5. 连通块可以整体确定合法时提前结束

设当前连通块内最小、最大编号为 `L,R`。对任何两个不同端点 `x<y`，都有

$$x\le R-1,\qquad y\ge L+1.$$

如果 `k1,k2` 都至少为 `R-L-1`，那么

$$x-k_1\le L,\qquad y+k_2\ge R.$$

整个连通块的编号都在允许区间内，任意路径都合法。若块大小为 `s`，直接加入 `s(s-1)/2` 条非单点路径即可，无须继续分治。单点贡献已经包含在最开始的 `n` 中。

这是由编号范围推出的充分条件；不满足它时，仍运行一般算法。

#### 6. 存储顺序与复杂度

随机编号的树会让多次遍历产生大量分散的内存访问。代码先按 DFS 顺序重新安排内部存储下标，再以连续数组存放每个点的邻居。`label[u]` 始终保存题目给定的原编号，所有 `low/high`、端点大小关系和答案计算都使用原编号；内部下标只服务于遍历。

重心查找与路径信息收集使用显式数组，避免长链造成递归栈溢出，并复用计数与排序缓冲区。

一般情况下，每层点分治的离线计数为 `O(n log n)`，总时间为 `O(n log² n)`，空间为 `O(n)`。静态前缀统计、低度重心的直接跨组计数和整块判定都不会增加这个复杂度。每条路径只在首次经过所选重心的一层被统计一次，计数公式逐项对应合法性条件，因此算法正确。

本版本地验证：1 个保存样例、650 组独立全点对路径枚举、3 组解析用例与 13 组 n=500000 上界测试通过。完整测试配置和同机基准见 [回归报告](../tests/range_path-report.json)。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdint>
#include <utility>
#include <vector>
using namespace std;

class FastInput {
    static constexpr int SIZE = 1 << 16;
    char buffer[SIZE];
    int pos = 0, length = 0;
    int get() {
        if (pos == length) {
            length = int(fread(buffer, 1, SIZE, stdin));
            pos = 0;
            if (!length) return EOF;
        }
        return buffer[pos++];
    }
public:
    int read() {
        int c = get(), value = 0;
        while (c <= ' ' && c != EOF) c = get();
        while (c >= '0' && c <= '9') {
            value = value * 10 + c - '0';
            c = get();
        }
        return value;
    }
};
struct Item {
    int id, low, high;
};

class Counter {
    int n, k1, k2;
    int blocks;
    vector<int> bit;
    vector<uint64_t> occupied, complete;
    vector<int> prefix;
    vector<Item> a, b, temporary;

    void sortBy(vector<Item> &items, bool high) {
        if (items.size() < 2048) {
            if (high)
                sort(items.begin(), items.end(), [](const Item &x, const Item &y) { return x.high < y.high; });
            else
                sort(items.begin(), items.end(), [](const Item &x, const Item &y) { return x.id < y.id; });
            return;
        }
        // Both keys are vertex labels <= 500000, hence fit in 19 bits.
        temporary.resize(items.size());
        for (int shift : {0, 10}) {
            array<int, 1024> count{};
            for (const Item &item : items)
                ++count[((high ? item.high : item.id) >> shift) & 1023];
            int total = 0;
            for (int &value : count) {
                int size = value;
                value = total;
                total += size;
            }
            for (const Item &item : items)
                temporary[count[((high ? item.high : item.id) >> shift) & 1023]++] = item;
            items.swap(temporary);
        }
    }
    long long sweep() {
        if (a.empty() || b.empty()) return 0;
        long long answer = 0;
        if (min(a.size(), b.size()) <= 24) {
            for (const Item &x : a)
                for (const Item &y : b)
                    if (x.id < y.id && x.high <= y.id + k2 && x.id <= y.low + k1)
                        ++answer;
            return answer;
        }
        int maxHigh = 0, minHigh = n + 1;
        for (const Item &x : a) { maxHigh = max(maxHigh, x.high); minHigh = min(minHigh, x.high); }
        int fullyActive = 0;
        for (const Item &y : b) fullyActive += y.id + k2 >= maxHigh;
        // These queries accept every A by the high-bound condition. Answer
        // them from a static bitmap before sorting or updating the Fenwick.
        // The threshold charges the O(blocks) prefix build to enough queries.
        if (fullyActive >= max(32, blocks / 8)) {
            for (const Item &x : a) complete[(x.id - 1) >> 6] |= uint64_t(1) << ((x.id - 1) & 63);
            prefix[0] = 0;
            for (int i = 0; i < blocks; ++i) prefix[i + 1] = prefix[i] + __builtin_popcountll(complete[i]);
            size_t kept = 0;
            int largestThreshold = 0;
            for (const Item &y : b) {
                if (y.id + k2 >= maxHigh) {
                    int limit = min(y.id - 1, y.low + k1);
                    answer += prefix[limit >> 6] + __builtin_popcountll(complete[limit >> 6] & ((uint64_t(1) << (limit & 63)) - 1));
                } else {
                    b[kept++] = y;
                    largestThreshold = max(largestThreshold, y.id + k2);
                }
            }
            b.resize(kept);
            for (const Item &x : a) complete[(x.id - 1) >> 6] = 0;
            if (b.empty()) return answer;
            kept = 0; minHigh = n + 1; maxHigh = 0;
            for (const Item &x : a) if (x.high <= largestThreshold) {
                a[kept++] = x;
                minHigh = min(minHigh, x.high); maxHigh = max(maxHigh, x.high);
            }
            a.resize(kept);
            if (a.empty()) return answer;
            if (min(a.size(), b.size()) <= 24) {
                for (const Item &x : a)
                    for (const Item &y : b)
                        if (x.id < y.id && x.high <= y.id + k2 && x.id <= y.low + k1) ++answer;
                return answer;
            }
        }
        if (minHigh != maxHigh) sortBy(a, true);
        sortBy(b, false);
        size_t inserted = 0;
        int lastLimit = -1, lastInserted = -1, lastAnswer = 0;
        for (const Item &y : b) {
            int limit = min(y.id - 1, y.low + k1);
            int full = limit >> 6, remainder = limit & 63;
            while (inserted < a.size() && a[inserted].high <= y.id + k2) {
                int label = a[inserted++].id - 1;
                int block = label >> 6;
                // Labels are unique. A word records membership within 64
                // labels; the much smaller Fenwick stores whole-word counts.
                occupied[block] |= uint64_t(1) << (label & 63);
                for (int x = block + 1; x <= blocks; x += x & -x)
                    ++bit[x];
            }
            if (lastLimit != limit || lastInserted != int(inserted)) {
                lastAnswer = __builtin_popcountll(occupied[full] & ((uint64_t(1) << remainder) - 1));
                for (int x = full; x > 0; x -= x & -x) lastAnswer += bit[x];
                lastLimit = limit; lastInserted = int(inserted);
            }
            answer += lastAnswer;
        }
        // Every updated Fenwick entry is nonnegative. If a reset chain hits
        // zero, that node and all its ancestors were already reset together.
        for (size_t i = 0; i < inserted; ++i) {
            int block = (a[i].id - 1) >> 6;
            if (!occupied[block]) continue;
            occupied[block] = 0;
            for (int x = block + 1; x <= blocks && bit[x]; x += x & -x)
                bit[x] = 0;
        }
        return answer;
    }

public:
    Counter(int n_, int k1_, int k2_) : n(n_), k1(k1_), k2(k2_),
        blocks((n + 63) / 64), bit(blocks + 1), occupied(blocks + 1),
        complete(blocks + 1), prefix(blocks + 1) {
        a.reserve(n); b.reserve(n); temporary.reserve(n);
    }
    long long count(const Item *items, int size) {
        if (size < 2) return 0;
        a.clear(); b.clear();
        for (int i = 0; i < size; ++i) {
            Item x = items[i];
            if (x.low >= x.id - k1) a.push_back(x);
            if (x.high <= x.id + k2) b.push_back(x);
        }
        return sweep();
    }
    long long cross(const Item *left, int nl, const Item *right, int nr) {
        a.clear(); b.clear();
        for (int i = 0; i < nl; ++i)
            if (left[i].low >= left[i].id - k1) a.push_back(left[i]);
        for (int i = 0; i < nr; ++i)
            if (right[i].high <= right[i].id + k2) b.push_back(right[i]);
        return sweep();
    }
    long long crossBoth(const Item *left, int nl, const Item *right, int nr) {
        return cross(left, nl, right, nr) + cross(right, nr, left, nl);
    }
};

int main() {
    FastInput in;
    int n = in.read(), k1 = in.read(), k2 = in.read();
    vector<int> head(n + 2), adjacent(2 * (n - 1));
    {
        vector<pair<int, int>> inputEdges(n - 1);
        for (auto &edge : inputEdges) {
            edge.first = in.read(); edge.second = in.read();
            ++head[edge.first]; ++head[edge.second];
        }
        int totalEdges = 0;
        for (int i = 1; i <= n + 1; ++i) {
            int degree = head[i]; head[i] = totalEdges; totalEdges += degree;
        }
        vector<int> cursor = head;
        for (const auto &edge : inputEdges) {
            adjacent[cursor[edge.first]++] = edge.second;
            adjacent[cursor[edge.second]++] = edge.first;
        }
    }
    if (k1 >= n - 1 && k2 >= n - 1) {
        printf("%lld\n", 1LL * n * (n + 1) / 2);
        return 0;
    }
    vector<int> label(n + 1);
    {
        // Graph storage uses DFS-order indices for locality. label[u] always
        // retains the original problem label; no path condition uses u itself.
        vector<int> mapping(n + 1), stack{1};
        mapping[1] = -1;
        int nextId = 0;
        while (!stack.empty()) {
            int u = stack.back(); stack.pop_back();
            mapping[u] = ++nextId; label[nextId] = u;
            for (int e = head[u]; e < head[u + 1]; ++e) {
                int v = adjacent[e];
                if (!mapping[v]) { mapping[v] = -1; stack.push_back(v); }
            }
        }
        vector<int> newHead(n + 2), newAdjacent(adjacent.size());
        int nextEdge = 0;
        for (int u = 1; u <= n; ++u) {
            newHead[u] = nextEdge;
            for (int e = head[label[u]]; e < head[label[u] + 1]; ++e)
                newAdjacent[nextEdge++] = mapping[adjacent[e]];
        }
        newHead[n + 1] = nextEdge;
        head.swap(newHead); adjacent.swap(newAdjacent);
    }
    Counter counter(n, k1, k2);
    vector<int> parent(n + 1), size(n + 1), largest(n + 1), order, components{1};
    vector<unsigned char> removed(n + 1);
    vector<Item> all;
    vector<pair<int, int>> branches;
    order.reserve(n); all.reserve(n); components.reserve(n);
    long long answer = n;
    while (!components.empty()) {
        int start = components.back(); components.pop_back();
        order.clear(); order.push_back(start); parent[start] = 0;
        int minLabel = n + 1, maxLabel = 0;
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i];
            minLabel = min(minLabel, label[u]); maxLabel = max(maxLabel, label[u]);
            size[u] = 1; largest[u] = 0;
            for (int e = head[u]; e < head[u + 1]; ++e) {
                int v = adjacent[e];
                if (!removed[v] && v != parent[u]) {
                    parent[v] = u;
                    order.push_back(v);
                }
            }
        }
        int total = int(order.size()), centroid = start;
        // For x < y, x <= maxLabel-1 and y >= minLabel+1. This bound makes
        // every path in this component valid, so its descendants need no work.
        if (min(k1, k2) >= maxLabel - minLabel - 1) {
            answer += 1LL * total * (total - 1) / 2;
            continue;
        }
        for (int i = total - 1; i >= 0; --i) {
            int u = order[i], p = parent[u];
            if (max(largest[u], total - size[u]) <= total / 2) centroid = u;
            if (p) {
                size[p] += size[u];
                largest[p] = max(largest[p], size[u]);
            }
        }
        branches.clear();
        for (int e = head[centroid]; e < head[centroid + 1]; ++e) {
            int v = adjacent[e];
            if (!removed[v]) branches.push_back({parent[v] == centroid ? size[v] : total - size[centroid], v});
        }
        if (branches.size() <= 3)
            sort(branches.begin(), branches.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
                return x.first > y.first;
            });
        int centreLabel = label[centroid];
        all.clear(); all.push_back({centreLabel, centreLabel, centreLabel});
        order.clear(); order.push_back(centroid);
        for (const auto &branch : branches) {
            int neighbor = branch.second;
            int begin = int(all.size());
            parent[neighbor] = centroid;
            order.push_back(neighbor);
            all.push_back({label[neighbor], min(label[neighbor], centreLabel), max(label[neighbor], centreLabel)});
            for (size_t i = begin; i < all.size(); ++i) {
                Item item = all[i];
                int u = order[i];
                for (int f = head[u]; f < head[u + 1]; ++f) {
                    int v = adjacent[f];
                    if (!removed[v] && v != parent[u]) {
                        parent[v] = u;
                        order.push_back(v);
                        all.push_back({label[v], min(item.low, label[v]), max(item.high, label[v])});
                    }
                }
            }
            if (branches.size() > 3)
                answer -= counter.count(all.data() + begin, int(all.size()) - begin);
        }
        if (branches.size() <= 3) {
            // Count centroid endpoints directly. For two/three branches,
            // disjoint cross-group counts avoid the repeated all-minus-own
            // work; with three branches, combine the largest against the rest.
            for (size_t i = 1; i < all.size(); ++i) {
                const Item &v = all[i];
                if (v.low >= min(centreLabel, v.id) - k1 && v.high <= max(centreLabel, v.id) + k2)
                    ++answer;
            }
            if (branches.size() >= 2) {
                int first = branches[0].first;
                answer += counter.crossBoth(all.data() + 1, first, all.data() + first + 1, total - first - 1);
            }
            if (branches.size() == 3) {
                int first = branches[0].first, second = branches[1].first;
                answer += counter.crossBoth(all.data() + first + 1, second,
                                            all.data() + first + second + 1, branches[2].first);
            }
        } else {
            answer += counter.count(all.data(), int(all.size()));
        }
        removed[centroid] = 1;
        for (int e = head[centroid]; e < head[centroid + 1]; ++e)
            if (!removed[adjacent[e]]) components.push_back(adjacent[e]);
    }
    printf("%lld\n", answer);
}
```
