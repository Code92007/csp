---
title: "CSP 201809 五题题解"
contest: "201809"
contest_month: "2018-09"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "数组", "同时更新", "双指针", "区间交集", "树", "祖先关系", "字符串", "贪心", "记忆化搜索", "动态规划", "字典序", "线性递推", "多项式", "NTT", "生成函数"]
status: "published"
problems: [{"id": "A", "title": "卖菜", "tags": ["数组", "同时更新"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda03c74ace1cba9a1f8b7"}}, {"id": "B", "title": "买菜", "tags": ["双指针", "区间交集"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda10674ace1cba9a1f946"}}, {"id": "C", "title": "元素选择器", "tags": ["树", "祖先关系", "字符串", "贪心"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda1a174ace1cba9a1f972"}}, {"id": "D", "title": "再卖菜", "tags": ["记忆化搜索", "动态规划", "字典序"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda24c74ace1cba9a1f9b0"}}, {"id": "E", "title": "线性递推式", "tags": ["线性递推", "多项式", "NTT", "生成函数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17/C++20 编译通过；3 个保存样例通过；500 组直接递推独立对拍、100 组大下标差分和 5 组压力测试通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda98c74ace1cba9a1fe91"}}]
---

# CSP 201809 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 卖菜

标签：`数组` · `同时更新`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adda03c74ace1cba9a1f8b7)（复刻评测）。

### 题意

第二天每家菜店价格为自己及相邻店第一天价格的平均值并向下取整；两端只有一个邻居。求全部新价格。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809A)。

### 题解

保存完整原数组，对位置i取[max(0,i-1),min(n-1,i+1)]中的价格求和，除以实际项数。全部计算始终读取原数组。

区间恰好包含本店与存在的邻居，正整数除法就是向下取整。不能边计算边覆盖原价格，否则下一家会误用第二天的数据。时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        int l = max(0, i - 1), r = min(n - 1, i + 1), sum = 0;
        for (int j = l; j <= r; j++)
            sum += a[j];
        if (i)
            cout << ' ';
        cout << sum / (r - l + 1);
    }
    cout << '\n';
}
```

<a id="problem-b"></a>

## B. 买菜

标签：`双指针` · `区间交集`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adda10674ace1cba9a1f946)（复刻评测）。

### 题意

两人各有n个有序且互不相交的装车时间区间，求同时装车的总时长。区间[s,t]的时长是t-s，端点接触时没有正长度交集。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809B)。

### 题解

双指针指向各自当前区间，交集长度为 `max(0,min(右端)-max(左端))`。累加后，右端较早的区间先结束，移动其指针；另一边保留以便继续与后续区间相交。

被丢弃区间不可能与另一侧更晚且不重叠的区间产生新交集，所以不会遗漏；同一人的区间不重叠又保证不会重复计时。时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (auto &[l, r] : a)
        cin >> l >> r;
    for (auto &[l, r] : b)
        cin >> l >> r;
    int i = 0, j = 0, answer = 0;
    while (i < n && j < n) {
        answer += max(0, min(a[i].second, b[j].second) - max(a[i].first, b[j].first));
        if (a[i].second < b[j].second)
            ++i;
        else
            ++j;
    }
    cout << answer << '\n';
}
```

<a id="problem-c"></a>

## C. 元素选择器

标签：`树` · `祖先关系` · `字符串` · `贪心`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adda1a174ace1cba9a1f972)（复刻评测）。

### 题意

用每层两个点号的缩进描述元素树，元素含大小写不敏感的标签及可选大小写敏感 id。查询是单个选择器或以空格相连的后代选择器链，输出最后一个选择器匹配且祖先链满足前面条件的行号。n≤100，查询数≤10。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809C)。

### 题解

读入树时维护各深度最近的结点栈，弹出同层及更深结点后，栈顶就是父亲。标签统一转小写，id 原样保存。

枚举查询可能选择的结点，先要求它匹配最后一级，再沿父亲向上，贪心匹配倒数第二级、倒数第三级等。这里是严格祖先，不能让同一个结点匹配两级；中间允许跳过任意不匹配祖先。

选择最近的可用祖先不会减少更上方可选祖先，因此若存在一条匹配链，贪心也能完成；反之完成的链本身就是证明。按输入行序枚举自然得到递增输出，每个结点至多输出一次。每条查询时间 $O(nh)$，h 为树高，空间 $O(n+|S|)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string lower(string s) {
    for (char &c : s)
        c = tolower(static_cast<unsigned char>(c));
    return s;
}
struct Node {
    string tag, id;
    int parent;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string line;
    getline(cin, line);
    vector<Node> a(n + 1);
    vector<int> stack;
    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        int d = 0;
        while (line[d] == '.')
            ++d;
        d /= 2;
        while (int(stack.size()) > d)
            stack.pop_back();
        a[i].parent = stack.empty() ? 0 : stack.back();
        istringstream in(line.substr(2 * d));
        in >> a[i].tag >> a[i].id;
        a[i].tag = lower(a[i].tag);
        stack.push_back(i);
    }
    while (m--) {
        getline(cin, line);
        istringstream in(line);
        vector<string> sel;
        string t;
        while (in >> t)
            sel.push_back(t[0] == '#' ? t : lower(t));
        auto match = [&](int u, int k) {
            return sel[k][0] == '#' ? a[u].id == sel[k] : a[u].tag == sel[k];
        };
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int k = int(sel.size()) - 1;
            if (!match(i, k))
                continue;
            --k;
            int u = a[i].parent;
            while (k >= 0 && u) {
                if (match(u, k))
                    --k;
                u = a[u].parent;
            }
            if (k < 0)
                ans.push_back(i);
        }
        cout << ans.size();
        for (int u : ans)
            cout << ' ' << u;
        cout << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 再卖菜

标签：`记忆化搜索` · `动态规划` · `字典序`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adda24c74ace1cba9a1f9b0)（复刻评测）。

### 题意

已知 n 家商店第二天的价格 b。两端价格是第一天自己与邻店的平均值向下取整，中间是自己及两侧三家的平均值向下取整。还原所有价格均为正整数、且字典序最小的第一天价格 a。$2\le n\le300,b_i\le100$，保证有解。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809D)。

### 题解

已知相邻原价 x、y 后，由中间商店平均值 b 可知下一项只能是 $3b-x-y$、$3b+1-x-y$、$3b+2-x-y$。因此状态只需记录当前位置与前两个原价，无需记录整个前缀。

设 `possible(i,x,y)` 判断固定 $a_{i-1}=x,a_i=y$ 后，是否存在合法后缀。到末尾检查 $(x+y)/2=b_i$；其他位置枚举上述三个正整数并递归。记忆化成功或失败结果，避免指数重复搜索。原价取 1 到 302 已足够：任何三项和最多 302，而另外两项至少为 1；端点二项和最多 201。

先升序枚举 a1，再升序枚举满足首端平均值的两个 a2 候选，选择首个后缀可行的组合。以后每一步也取最小的可行下一项。与任何其他解在第一个不同位置比较，我们的取值都不更大，所以得到全局字典序最小解。

状态总数 $O(nV^2)$，每个状态至多三个转移，时间与空间均为 $O(nV^2)$，$V=303$。缓存用单字节三态值降低内存。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
constexpr int V = 303;
int n;
vector<int> b;
vector<int8_t> memo;
bool possible(int i, int x, int y) {
    if (x < 1 || x >= V || y < 1 || y >= V)
        return false;
    int8_t &answer = memo[(i * V + x) * V + y];
    if (answer != -1)
        return answer;
    if (i == n - 1)
        return answer = (x + y) / 2 == b[i];
    for (int z = 3 * b[i] - x - y; z <= 3 * b[i] + 2 - x - y; ++z)
        if (possible(i + 1, y, z))
            return answer = 1;
    return answer = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    b.resize(n);
    for (auto &x : b)
        cin >> x;
    memo.assign(n * V * V, -1);
    vector<int> a;
    for (int x = 1; x <= 2 * b[0] && a.empty(); ++x)
        for (int y = max(1, 2 * b[0] - x); y <= 2 * b[0] + 1 - x; ++y)
            if (possible(1, x, y)) {
                a = {x, y};
                break;
            }
    for (int i = 1; i < n - 1; ++i)
        for (int z = 3 * b[i] - a[i - 1] - a[i]; z <= 3 * b[i] + 2 - a[i - 1] - a[i]; ++z)
            if (possible(i + 1, a[i], z)) {
                a.push_back(z);
                break;
            }
    for (int i = 0; i < n; ++i)
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
}
```

<a id="problem-e"></a>

## E. 线性递推式

标签：`线性递推` · `多项式` · `NTT` · `生成函数`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17/C++20 编译通过；3 个保存样例通过；500 组直接递推独立对拍、100 组大下标差分和 5 组压力测试通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adda98c74ace1cba9a1fe91)（复刻评测）。

### 题意

给定 $a_0=1$，对 $n>0$ 有 $a_n=\sum_{i=1}^{\min(n,m)}k_i a_{n-i}$，所有计算模 $998244353$。输入 `m l r` 和 $m$ 个系数，输出 $a_l$ 至 $a_r$。$m\le10^5,l\le10^{12},r-l\le3\times10^5$，不能逐项算到 $l$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809E)。

### 题解

**第一步：求递推序列的前缀。** 令 $C(x)=1-k_1x-\cdots-k_mx^m$，由递推式可得 $A(x)=\sum_{i\ge0}a_ix^i=1/C(x)$。使用多项式牛顿迭代 $B_{new}=B(2-CB)\bmod x^{2t}$，将逆多项式的已知长度逐次翻倍；卷积用模 $998244353$ 的 NTT 计算。

**第二步：把巨大下标压回 $m$ 维。** 定义特征多项式 $P(x)=x^m-k_1x^{m-1}-\cdots-k_m$，计算

$$R(x)=x^l\bmod P(x)=\sum_{j=0}^{m-1}r_jx^j.$$

从最高二进制位向最低位处理 $l$。若已处理前缀为 $s$，保持 $R=x^s\bmod P$；下一位为 $b$ 时，更新为 $R^2x^b\bmod P$。平方后用逆序多项式除法求余：逆序 $P$ 就是 $C$，所以可预先求出并复用 $1/C$ 的前缀。乘 $x$ 则只需移位，再以 $x^m=k_1x^{m-1}+\cdots+k_m$ 消去最高项，耗时 $O(m)$，无需再做通用卷积。最初次数较小时保留实际长度。

**第三步：一次卷积求出整个答案区间。** 递推关系保证对每个 $t\ge0$ 都有

$$a_{l+t}=\sum_{j=0}^{m-1}r_ja_{t+j}.$$

将 $R$ 逆序，与序列前缀卷积，下标 $m-1+t$ 的项就是所求值。代码若只保留了 $u$ 个系数，则相应只求出 $a_0$ 至 $a_{u+d-2}$，读取卷积下标 $u-1+t$，其中 $d=r-l+1$。$m=1$ 时直接计算等比数列；$l=0$ 与零系数也自然成立。

**降低 NTT 常数。** 平方只变换一个因子，固定的除式及逆多项式缓存其频域结果。牛顿迭代从 $t$ 扩展到 $2t$ 时复用旧逆的变换，只计算误差的高半段：长度 $2t$ 的循环卷积回卷只影响舍弃的低半段，因此每步用 5 次长度 $2t$ 的 NTT 即可。正变换采用 DIF、逆变换采用 DIT，共享倒位序的频率排列，并预处理各层单位根。

**正确性。** 二进制更新保持 $R=x^s\bmod P$，故最后得到 $x^l$ 的余式。多项式除法中被减去的 $P$ 的倍数对应若干递推等式的线性组合，在任意非负位移处均为零，所以余式给出的线性组合成立；最后的卷积恰好同时计算所有位移。

**复杂度。** 时间 $O(m\log m\log l+(m+d)\log(m+d))$，空间 $O(m+d)$。优化前曙梦 OJ 为 [77 分超时](https://oj.shumeng.tech/record/6adda38574ace1cba9a1fa97)。本地最大随机构造从 3.715 秒降至 0.514 秒，指数多置位构造从 5.240 秒降至 0.504 秒；同机性能对比不等同于目标评测机耗时。复核入口：[优化回归脚本](../tests/optimized_regressions.py)、[验证报告](../tests/optimization-report.json)。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr int MOD = 998244353;
using Polynomial = vector<int>;

int power(int a, long long n) {
    int r = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD)
        if (n & 1) r = 1LL * r * a % MOD;
    return r;
}
int transformSize(int need) {
    int n = 1;
    while (n < need) n <<= 1;
    return n;
}

// DIF forward and DIT inverse use the same bit-reversed frequency order.
// Roots are stored once for every butterfly stage, avoiding per-block powers.
void ntt(Polynomial &a, bool inverse) {
    static Polynomial roots{0, 1}, inverseRoots{0, 1};
    int n = int(a.size());
    while (int(roots.size()) < n) {
        int half = int(roots.size());
        roots.resize(2 * half);
        inverseRoots.resize(2 * half);
        int w = power(3, (MOD - 1) / (2 * half));
        int iw = power(w, MOD - 2);
        roots[half] = inverseRoots[half] = 1;
        for (int j = 1; j < half; ++j) {
            roots[half + j] = 1LL * roots[half + j - 1] * w % MOD;
            inverseRoots[half + j] = 1LL * inverseRoots[half + j - 1] * iw % MOD;
        }
    }
    if (!inverse) {
        for (int half = n / 2; half; half >>= 1)
            for (int start = 0; start < n; start += 2 * half)
                for (int j = 0; j < half; ++j) {
                    int u = a[start + j], v = a[start + j + half];
                    int sum = u + v, difference = u - v;
                    if (sum >= MOD) sum -= MOD;
                    if (difference < 0) difference += MOD;
                    a[start + j] = sum;
                    a[start + j + half] = 1LL * difference * roots[half + j] % MOD;
                }
    } else {
        for (int half = 1; half < n; half <<= 1)
            for (int start = 0; start < n; start += 2 * half)
                for (int j = 0; j < half; ++j) {
                    int u = a[start + j];
                    int v = 1LL * a[start + j + half] * inverseRoots[half + j] % MOD;
                    int sum = u + v, difference = u - v;
                    if (sum >= MOD) sum -= MOD;
                    if (difference < 0) difference += MOD;
                    a[start + j] = sum;
                    a[start + j + half] = difference;
                }
        int scale = power(n, MOD - 2);
        for (int &x : a) x = 1LL * x * scale % MOD;
    }
}
Polynomial multiply(Polynomial a, Polynomial b) {
    if (a.empty() || b.empty()) return {};
    int size = int(a.size() + b.size()) - 1;
    if (min(a.size(), b.size()) <= 32) {
        Polynomial c(size);
        for (int i = 0; i < int(a.size()); ++i)
            for (int j = 0; j < int(b.size()); ++j)
                c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % MOD;
        return c;
    }
    int n = transformSize(size);
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * b[i] % MOD;
    ntt(a, true);
    a.resize(size);
    return a;
}

Polynomial inverse(const Polynomial &a, int size) {
    Polynomial b{power(a[0], MOD - 2)};
    while (int(b.size()) < size) {
        int old = int(b.size()), n = 2 * old;
        Polynomial fb = b, error(n);
        fb.resize(n);
        copy_n(a.begin(), min(n, int(a.size())), error.begin());
        ntt(fb, false);
        ntt(error, false);
        for (int i = 0; i < n; ++i) error[i] = 1LL * error[i] * fb[i] % MOD;
        ntt(error, true);
        // Only the upper half is needed. Cyclic wraparound affects the lower half.
        fill(error.begin(), error.begin() + old, 0);
        ntt(error, false);
        for (int i = 0; i < n; ++i) error[i] = 1LL * error[i] * fb[i] % MOD;
        ntt(error, true);
        b.resize(n);
        for (int i = old; i < n; ++i) b[i] = error[i] ? MOD - error[i] : 0;
    }
    b.resize(size);
    return b;
}

class Remainder {
    int m, n;
    Polynomial characteristic, inversePrefix, transformedP, transformedInverse;
public:
    explicit Remainder(const Polynomial &c)
        : m(int(c.size()) - 1), n(transformSize(2 * m - 1)),
          characteristic(c.rbegin(), c.rend()), inversePrefix(inverse(c, m)) {}

    Polynomial square(const Polynomial &a) {
        int size = 2 * int(a.size()) - 1;
        Polynomial product;
        if (int(a.size()) <= 32) {
            product = multiply(a, a);
        } else {
            product = a;
            product.resize(transformSize(size));
            ntt(product, false);
            for (int &x : product) x = 1LL * x * x % MOD;
            ntt(product, true);
            product.resize(size);
        }
        if (size <= m) return product;
        int length = size - m;
        Polynomial quotient(product.rbegin(), product.rbegin() + length);
        if (length < m - 1 || m <= 32) {
            Polynomial cut(inversePrefix.begin(), inversePrefix.begin() + length);
            quotient = multiply(quotient, cut);
            quotient.resize(length);
            reverse(quotient.begin(), quotient.end());
            auto removed = multiply(quotient, characteristic);
            product.resize(m);
            for (int i = 0; i < m; ++i) {
                product[i] -= removed[i];
                if (product[i] < 0) product[i] += MOD;
            }
        } else {
            if (transformedP.empty()) {
                transformedP = characteristic;
                transformedP.resize(n);
                transformedInverse = inversePrefix;
                transformedInverse.resize(n);
                ntt(transformedP, false);
                ntt(transformedInverse, false);
            }
            quotient.resize(n);
            ntt(quotient, false);
            for (int i = 0; i < n; ++i)
                quotient[i] = 1LL * quotient[i] * transformedInverse[i] % MOD;
            ntt(quotient, true);
            quotient.resize(length);
            reverse(quotient.begin(), quotient.end());
            quotient.resize(n);
            ntt(quotient, false);
            for (int i = 0; i < n; ++i)
                quotient[i] = 1LL * quotient[i] * transformedP[i] % MOD;
            ntt(quotient, true);
            product.resize(m);
            for (int i = 0; i < m; ++i) {
                product[i] -= quotient[i];
                if (product[i] < 0) product[i] += MOD;
            }
        }
        return product;
    }

    void multiplyX(Polynomial &a) const {
        if (int(a.size()) < m) {
            a.insert(a.begin(), 0);
            return;
        }
        int top = a.back();
        for (int i = m - 1; i >= 0; --i) {
            int value = i ? a[i - 1] : 0;
            value = (value - 1LL * top * characteristic[i]) % MOD;
            if (value < 0) value += MOD;
            a[i] = value;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    long long l, r;
    if (!(cin >> m >> l >> r)) return 0;
    int count = int(r - l + 1);
    Polynomial c(m + 1);
    c[0] = 1;
    for (int i = 1, k; i <= m; ++i) {
        cin >> k;
        c[i] = k ? MOD - k : 0;
    }
    if (m == 1) {
        int k = c[1] ? MOD - c[1] : 0, a = power(k, l);
        for (int i = 0; i < count; ++i, a = 1LL * a * k % MOD) cout << a << '\n';
        return 0;
    }
    Polynomial result{1};
    if (l) {
        Remainder reduce(c);
        int highest = 0;
        while ((1LL << (highest + 1)) <= l) ++highest;
        for (int bit = highest; bit >= 0; --bit) {
            result = reduce.square(result);
            if ((l >> bit) & 1) reduce.multiplyX(result);
        }
    }
    int used = int(result.size());
    auto prefix = inverse(c, used + count - 1);
    reverse(result.begin(), result.end());
    auto answer = multiply(result, prefix);
    for (int i = 0; i < count; ++i) cout << answer[used - 1 + i] << '\n';
}
```
