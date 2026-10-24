---
title: "CSP 202303 五题题解"
contest: "202303"
contest_month: "2023-03"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "矩形相交", "几何", "二分答案", "单调性", "递归下降", "位集", "倒排索引", "离散化", "线段树", "区间赋值", "分治", "树状数组", "区间计数"]
status: "published"
problems: [{"id": "A", "title": "田地丈量", "tags": ["矩形相交", "几何"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16694"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce918a67df0b81749c020"}}, {"id": "B", "title": "垦田计划", "tags": ["二分答案", "单调性"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16695"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91aa67df0b81749c02a"}}, {"id": "C", "title": "LDAP", "tags": ["递归下降", "位集", "倒排索引"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 70 分 Time Exceeded（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16696"}], "oj": {"status": "failed", "score": 70, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6adce91ba67df0b81749c02e"}}, {"id": "D", "title": "星际网络 II", "tags": ["离散化", "线段树", "区间赋值"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16697"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91da67df0b81749c032"}}, {"id": "E", "title": "施肥", "tags": ["分治", "线段树", "树状数组", "区间计数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16698"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91ea67df0b81749c036"}}]
---

# CSP 202303 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 田地丈量

标签：`矩形相交` · `几何`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

已有若干内部互不相交的轴对齐田地，求它们落在目标矩形[0,a]×[0,b]内的总面积。坐标可为负。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16694)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303A)。

### 题解

对每块田地求与目标矩形的交集：横向长度为max(0,min(x2,a)-max(x1,0))，纵向同理，两者相乘后累加。

两个矩形的公共横纵区间的笛卡尔积就是交集；相离或仅边界接触时长度为0。已有田地内部互不重叠，所以交集面积可直接相加，无需计算复杂矩形并。时间 $O(n)$，空间 $O(1)$，面积采用64位。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    long long a, b, answer = 0;
    cin >> n >> a >> b;
    while (n--) {
        long long x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        answer += max(0LL, min(a, xx) - max(0LL, x)) * max(0LL, min(b, yy) - max(0LL, y));
    }
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 垦田计划

标签：`二分答案` · `单调性`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

n 块田同时开垦，第 i 块原耗时 t[i]，每缩短一天花 c[i] 资源，最短均为 k 天。共有 m 资源，求总完成时间的最小值。n、t[i]、c[i]≤$10^5$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16695)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303B)。

### 题解

判断能否在 T 天完成：每块超过 T 的田至少要缩短 t[i]-T 天，因此最少花费为 `Σ max(0,t[i]-T)*c[i]`。总花费≤m 就可行。

T 越大，所需资源只会减少，所以在 [k,max(t)] 二分第一个可行时间。判定的花费既是必要下界，也可通过恰好缩短相应天数实现，故单调判定充分必要。时间 $O(n\log\max t)$，空间 $O(n)$，总成本可达$10^{15}$，用64位。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    long long m;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    int hi = k;
    for (auto &[t, c] : a) {
        cin >> t >> c;
        hi = max(hi, t);
    }
    int lo = k;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        long long need = 0;
        for (auto [t, c] : a)
            if (t > mid)
                need += 1LL * (t - mid) * c;
        if (need <= m)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << '\n';
}
```

<a id="problem-c"></a>

## C. LDAP

标签：`递归下降` · `位集` · `倒排索引`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 70 分 Time Exceeded（复刻评测）。

### 题意

每个用户有唯一 DN 及若干整数属性。表达式 `a:b` 匹配具有属性 a 且值等于 b 的用户，`a~b` 匹配具有该属性且值不等于 b 的用户；`&(E1)(E2)`、`|(E1)(E2)` 表示交和并。每次输出匹配 DN 的升序列表，可以为空行。用户至多 2500，查询至多 500，表达式长度至多 2000。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16696)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303C)。

### 题解

按属性建立倒排索引，记录 `(属性值,用户下标)` 并排序。断言用二分定位相等值区间，反断言遍历该属性的记录选取不等值；属性不存在的用户两者都不匹配。这与把“等于”的结果直接取反不同。

递归下降解析表达式。原子表达式返回用户 bitset；逻辑表达式先递归读完两个括号中的表达式，再对位集做按位与／或。解析指针总是停在当前表达式之后，不使用短路逻辑跳过解析分支。最后扫描预先按 DN 排序的用户，输出被置位的下标。

原子结果直接符合定义，逻辑结点的位集交并也符合组合语义，结构归纳得到正确性。设一条表达式含 A 个原子、L 个字符，用户数 n，则单次保守时间 $O(L+An)$，位集逻辑运算每次 $O(n/64)$；索引空间与总属性数线性相关，递归位集另占 $O(Ln/64)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <bitset>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using Bits = bitset<2500>;
unordered_map<int, vector<pair<int, int>>> attrs;
string expr;
size_t posi;
int number() {
    int x = 0;
    while (posi < expr.size() && isdigit(expr[posi]))
        x = x * 10 + expr[posi++] - '0';
    return x;
}
Bits parse() {
    if (expr[posi] == '&' || expr[posi] == '|') {
        char op = expr[posi++];
        ++posi;
        Bits a = parse();
        posi += 2;
        Bits b = parse();
        ++posi;
        return op == '&' ? (a & b) : (a | b);
    }
    int key = number();
    char op = expr[posi++];
    int value = number();
    Bits ans;
    auto it = attrs.find(key);
    if (it == attrs.end())
        return ans;
    const auto &v = it->second;
    if (op == ':') {
        auto l = lower_bound(v.begin(), v.end(), pair<int, int>{value, -1});
        for (; l != v.end() && l->first == value; ++l)
            ans.set(l->second);
    } else
        for (auto [val, id] : v)
            if (val != value)
                ans.set(id);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> dn;
    for (int i = 0; i < n; i++) {
        int d, k;
        cin >> d >> k;
        dn.push_back({d, i});
        while (k--) {
            int a, v;
            cin >> a >> v;
            attrs[a].push_back({v, i});
        }
    }
    for (auto &[key, v] : attrs)
        sort(v.begin(), v.end());
    sort(dn.begin(), dn.end());
    int m;
    cin >> m;
    while (m--) {
        cin >> expr;
        posi = 0;
        Bits ans = parse();
        bool first = true;
        for (auto [d, i] : dn)
            if (ans[i]) {
                if (!first)
                    cout << ' ';
                cout << d;
                first = false;
            }
        cout << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 星际网络 II

标签：`离散化` · `线段树` · `区间赋值`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

管理最多 512 位二进制的地址，输入采用固定长度十六进制、每四位以冒号分隔。`1 id l r` 申请闭区间：不能含其他用户的地址，且必须至少有一个尚未分配地址，成功则全部归 id 并输出 YES，否则 NO。`2 s` 查询地址主人，未分配为 0；`3 l r` 查询是否整段都属于同一用户，是则输出编号，否则 0。操作数 $q\le5\times10^4$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16697)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303D)。

### 题解

**大整数只用于排序，不需要转换成整数。** 删除冒号后，所有地址等长，字典序就是数值顺序。在前面补一位 0，便能安全计算最大地址的后继，避免全为 f 时溢出。

把每个闭区间变成半开区间 $[l,r+1)$；点查询同样视为 $[s,s+1)$。先读完所有操作，收集这些边界并排序去重。相邻边界之间的所有地址永远一起被操作，因此可以压成一个叶子。不能仅压缩 l 和 r 而忽略它们之间可能存在的空白地址。

线段树维护区间内的最小主人编号、最大主人编号、最小正主人编号，并支持整段赋值。申请合法等价于：最小编号为 0（确有空闲），并且最大编号为 0，或所有正编号都等于申请者。查询同一主人时，只需最小编号等于最大编号。

这些统计量可以从左右孩子合并，赋值时直接重置；懒标记保证区间操作效率。离散化保留每次操作的完整边界，因此压缩前后的覆盖关系一致，合法性判断又与规则逐项等价。

设地址十六进制长度为 $L$，时间 $O(qL\log q+q\log q)$，空间 $O(qL+q)$。特别注意：同一用户重复申请自己已经完全持有的区间，也必须输出 NO。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
constexpr int INF = 1000000000;
struct Info {
    int low = 0, high = 0, positive = INF;
};
Info merge(Info a, Info b) {
    return {min(a.low, b.low), max(a.high, b.high), min(a.positive, b.positive)};
}
struct Node {
    Info info;
    int lazy = -1;
};
struct Operation {
    int type, id = 0;
    string left, right;
};
string address() {
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), ':'), s.end());
    return '0' + s;
}
string successor(string s) {
    const string digits = "0123456789abcdef";
    for (int i = int(s.size()) - 1; i >= 0; --i) {
        if (s[i] == 'f')
            s[i] = '0';
        else {
            s[i] = digits[digits.find(s[i]) + 1];
            break;
        }
    }
    return s;
}
vector<Node> tree;
void assign(int u, int value) {
    tree[u].info = {value, value, value ? value : INF};
    tree[u].lazy = value;
}
void push(int u) {
    if (tree[u].lazy != -1) {
        assign(u * 2, tree[u].lazy);
        assign(u * 2 + 1, tree[u].lazy);
        tree[u].lazy = -1;
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
    return merge(query(u * 2, l, mid, a, b), query(u * 2 + 1, mid + 1, r, a, b));
}
void update(int u, int l, int r, int a, int b, int value) {
    if (a <= l && r <= b) {
        assign(u, value);
        return;
    }
    push(u);
    int mid = (l + r) / 2;
    if (a <= mid)
        update(u * 2, l, mid, a, b, value);
    if (b > mid)
        update(u * 2 + 1, mid + 1, r, a, b, value);
    tree[u].info = merge(tree[u * 2].info, tree[u * 2 + 1].info);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int bits, q;
    cin >> bits >> q;
    vector<Operation> ops(q);
    vector<string> coordinates;
    for (auto &op : ops) {
        cin >> op.type;
        if (op.type == 1)
            cin >> op.id;
        op.left = address();
        op.right = successor(op.type == 2 ? op.left : address());
        coordinates.push_back(op.left);
        coordinates.push_back(op.right);
    }
    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
    int n = int(coordinates.size()) - 1;
    tree.resize(4 * n + 4);
    for (auto &op : ops) {
        int l = lower_bound(coordinates.begin(), coordinates.end(), op.left) - coordinates.begin();
        int r = int(lower_bound(coordinates.begin(), coordinates.end(), op.right) -
                    coordinates.begin()) -
                1;
        Info value = query(1, 0, n - 1, l, r);
        if (op.type == 1) {
            bool possible = value.low == 0 &&
                            (value.high == 0 || (value.high == op.id && value.positive == op.id));
            cout << (possible ? "YES" : "NO") << '\n';
            if (possible)
                update(1, 0, n - 1, l, r, op.id);
        } else
            cout << (value.low == value.high ? value.low : 0) << '\n';
    }
}
```

<a id="problem-e"></a>

## E. 施肥

标签：`分治` · `线段树` · `树状数组` · `区间计数`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

$n$ 块田地排成一行，每辆车只能完整覆盖给定闭区间 $[l_i,r_i]$，不能截断。统计多少个 $L<R$，使得能选择若干辆车，恰好覆盖 $[L,R]$，允许重叠，但不能漏田或覆盖范围外的田。输入 `n m` 以及 $m$ 个区间，$n,m\le2\times10^5$。注意田地是离散的：$[1,2]$ 与 $[3,4]$ 可以直接拼成 $[1,4]$。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16698)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303E)。

### 题解

**按答案区间跨越的位置分治。** 在 $[lo,hi]$ 中取中点 $mid$。完全在左边、完全在右边的答案递归计算；本层只数 $L\le mid<R$。把车辆区间分成左侧、右侧、跨中点三类。

对每个左端点 $L$，定义 $a_L$ 为只用左侧车辆、从 $L$ 开始能连续覆盖的最远位置；没有以 $L$ 为起点的覆盖时设为 $L-1$。倒序扫描 $L$：先取所有起点恰为 $L$ 的区间的最大右端点 $r$，再查询已算好的 $a_t$，其中 $L<t\le\min(mid,r+1)$，取最大值。一次查询即可：达到最大值的那条链已经包含了从该 $t$ 能继续拼接的全部车辆。线段树维护这些最大值。

若要通过一辆跨中点的车继续覆盖，它的左端点必须位于 $[L,a_L+1]$。在这些车中取最小右端点，记为 $b_L$。如果 $a_L=mid$，还可以完全不使用跨中点车辆，此时把 $mid+1$ 也作为候选 $b_L$。没有方案则为正无穷。

从右向左做完全对称的计算，得到 $a_R$（右侧能连续覆盖到的最左位置），以及 $b_R$（能接上的跨中点车辆的最大左端点）；若右侧本身覆盖到 $mid+1$，也允许 $b_R=mid$。

**关键判定：** $[L,R]$ 可覆盖，当且仅当 $b_L\le R$ 且 $L\le b_R$。必要性由一组覆盖中接通左右边界的第一、最后跨中点车辆得到。充分性是：左右两端分别有合法覆盖接到跨中点车辆；两辆跨中点车必定重叠。若两侧都靠相邻拼接接通，则它们在 $mid,mid+1$ 相邻，仍连续。若只有一侧不需要跨车，另一侧的跨车也能与它接上。

把所有 $L$ 按 $b_L$ 排序，按 $R$ 递增扫描，将 $b_L\le R$ 的左端点加入树状数组，查询不超过 $b_R$ 的数量即可。本层 $O((n+m)\log n)$，递归后总时间 $O((n+m)\log^2 n)$；实现保留各层临时数组，空间上界 $O((n+m)\log n)$。重复车辆不影响答案，单点区间不计入。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;
struct Range {
    int base, identity;
    bool minimum;
    vector<int> t;
    Range(int n, bool mn)
        : base(n), identity(mn ? 1000000000 : -1000000000), minimum(mn), t(2 * n, identity) {}
    int combine(int a, int b) {
        return minimum ? min(a, b) : max(a, b);
    }
    void put(int x, int v) {
        x += base;
        t[x] = combine(t[x], v);
        for (x >>= 1; x; x >>= 1)
            t[x] = combine(t[2 * x], t[2 * x + 1]);
    }
    int get(int l, int r) {
        if (l > r)
            return identity;
        int ans = identity;
        for (l += base, r += base + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans = combine(ans, t[l++]);
            if (r & 1)
                ans = combine(ans, t[--r]);
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> intervals(m);
    for (auto &a : intervals)
        cin >> a.first >> a.second;
    function<long long(int, int, vector<pair<int, int>>)> solve =
        [&](int lo, int hi, vector<pair<int, int>> items) -> long long {
        if (lo == hi || items.empty())
            return 0;
        int mid = (lo + hi) / 2, len = hi - lo + 1;
        vector<pair<int, int>> left, right, cross;
        vector<int> furthest(len), nearest(len);
        for (int i = lo; i <= hi; ++i) {
            furthest[i - lo] = i - 1;
            nearest[i - lo] = i + 1;
        }
        for (auto [l, r] : items) {
            if (r <= mid) {
                left.push_back({l, r});
                furthest[l - lo] = max(furthest[l - lo], r);
            } else if (l > mid) {
                right.push_back({l, r});
                nearest[r - lo] = min(nearest[r - lo], l);
            } else
                cross.push_back({l, r});
        }
        vector<int> needRight(mid - lo + 1), needLeft(hi - mid);
        {
            Range reach(len, false), ends(len, true);
            for (auto [l, r] : cross)
                ends.put(l - lo, r);
            for (int L = mid; L >= lo; --L) {
                int a = furthest[L - lo];
                a = max(a, reach.get(L + 1 - lo, min(mid, a + 1) - lo));
                reach.put(L - lo, a);
                int b = ends.get(L - lo, min(mid, a + 1) - lo);
                if (a == mid)
                    b = min(b, mid + 1);
                needRight[L - lo] = b;
            }
        }
        {
            Range reach(len, true), starts(len, false);
            for (auto [l, r] : cross)
                starts.put(r - lo, l);
            for (int R = mid + 1; R <= hi; ++R) {
                int a = nearest[R - lo];
                a = min(a, reach.get(max(mid + 1, a - 1) - lo, R - 1 - lo));
                reach.put(R - lo, a);
                int b = starts.get(max(mid + 1, a - 1) - lo, R - lo);
                if (a == mid + 1)
                    b = max(b, mid);
                needLeft[R - mid - 1] = b;
            }
        }
        vector<pair<int, int>> events;
        for (int L = lo; L <= mid; ++L)
            events.push_back({needRight[L - lo], L});
        sort(events.begin(), events.end());
        vector<int> bit(mid - lo + 2);
        size_t p = 0;
        long long answer = 0;
        for (int R = mid + 1; R <= hi; ++R) {
            while (p < events.size() && events[p].first <= R) {
                int x = events[p++].second - lo + 1;
                for (; x < int(bit.size()); x += x & -x)
                    ++bit[x];
            }
            int bound = min(mid, needLeft[R - mid - 1]);
            for (int x = bound - lo + 1; x > 0; x -= x & -x)
                answer += bit[x];
        }
        // Release this level's bulky lists before recursing.
        return answer + solve(lo, mid, std::move(left)) + solve(mid + 1, hi, std::move(right));
    };
    cout << solve(1, n, std::move(intervals)) << '\n';
}
```
