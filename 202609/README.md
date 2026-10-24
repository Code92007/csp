---
title: "CSP 202609 五题题解"
contest: "202609"
contest_month: "2026-09"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "数学", "精度", "查表", "模拟", "动态规划", "01背包", "队列", "调度", "状态机", "图论", "二分图", "带权并查集", "区间", "构造", "树", "点分治", "动态查询", "位运算", "哈希表"]
status: "published"
problems: [{"id": "A", "title": "流程规划（其一）", "tags": ["数学", "精度", "查表", "模拟"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "已通过 C++17 编译、101 组本地对拍及复刻样例；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609A"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6c2a67df0b81749b341"}}, {"id": "B", "title": "流程规划（其二）", "tags": ["动态规划", "01背包", "精度"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "已通过 C++17 编译、120 组本地对拍及复刻样例；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609B"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6e0a67df0b81749b3d9"}}, {"id": "C", "title": "轮转调度", "tags": ["模拟", "队列", "调度", "状态机"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "已通过 C++17 编译、100 组本地对拍及复刻样例；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609C"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6e2a67df0b81749b3e7"}}, {"id": "D", "title": "数字分组", "tags": ["图论", "二分图", "带权并查集", "区间", "构造"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "已通过 C++17 编译、240 组本地对拍（输出由独立检查器验证）；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609D"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6e4a67df0b81749b40a"}}, {"id": "E", "title": "奇", "tags": ["树", "点分治", "动态查询", "位运算", "哈希表"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "已通过 C++17 编译、140 组本地对拍及复刻样例；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609E"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce90ea67df0b81749bfe2"}}]
---

# CSP 202609 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 流程规划（其一）

标签：`数学` · `精度` · `查表` · `模拟`

状态：**已实现**。已通过 C++17 编译、101 组本地对拍及复刻样例；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

有 $n$ 个相互独立的制造环节。题目给出各环节的平均耗时 $\mu_i$ 和标准差 $\sigma_i$，总平均耗时为 $\mu=\sum\mu_i$，总标准差为 $\sigma=\sqrt{\sum\sigma_i^2}$。

给定时间上限 $m$，计算 $z=(m-\mu)/\sigma$，再从一张递增表中选择与 $z$ 横坐标距离最近的表项。若恰好等距，选择横坐标较小的表项。输出这一项在输入中的函数值，保留原来的三位小数格式。所有输入实数都是三位小数，且保证 $z$ 在表内。输入依次为 `n m k`、$n$ 个均值、$n$ 个标准差、$k$ 个横坐标及 $k$ 个函数值；$n,m\le100$，$k\le20$。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609A)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

**第一步：只实现题目给出的公式。** 不需要自己计算正态分布函数；输入已经给出了所需的函数值表。总方差是各标准差平方之和，不能直接把标准差相加。

**第二步：用相邻表项的中点确定最近项。** 对相邻横坐标 $x_i,x_{i+1}$，若 $z\le(x_i+x_{i+1})/2$，就应选左边；从左到右遇到第一个满足条件的中点即可停止。等号选左边，恰好符合题意。

**第三步：避免浮点数把“等距”判断成“不等距”。** 将均值、标准差、表横坐标都按输入小数位放大 1000 倍，分别记为整数 $M_i,S_i,X_i$。令 $D=1000m-\sum M_i$、$V=\sum S_i^2$，则 $z=D/\sqrt V$。因为题目保证 $z\ge0$，以下比较两边非负，可以平方：

$$z\le\frac{X_i+X_{i+1}}{2000}
\iff (2000D)^2\le(X_i+X_{i+1})^2V.$$

比较在 `__int128` 中完成。函数值直接用字符串保存，输出时不会丢失末尾的零。

**正确性。** 递增表的各相邻中点，把数轴分成每个表项的最近区域。从左到右找到的第一个中点，就是当前 $z$ 所在区域的右边界；等距归左。整数缩放和平方保持比较结果，因此返回的表项满足最近与并列规则。

**复杂度。** 时间 $O(n+k)$，额外空间 $O(k)$。`__int128` 为 GCC/Clang 扩展，可在常见 C++17 编译器使用。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using i128 = __int128_t;

long long scaled(const string& s, int places) {
    size_t dot = s.find('.');
    string whole = dot == string::npos ? s : s.substr(0, dot);
    string fraction = dot == string::npos ? "" : s.substr(dot + 1);
    fraction.resize(places, '0');
    long long factor = 1;
    for (int i = 0; i < places; ++i) factor *= 10;
    return stoll(whole) * factor + stoll(fraction.empty() ? "0" : fraction);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    long long totalMean = 0, variance = 0;
    string token;
    for (int i = 0; i < n; ++i) {
        cin >> token;
        totalMean += scaled(token, 3);
    }
    for (int i = 0; i < n; ++i) {
        cin >> token;
        long long x = scaled(token, 3);
        variance += x * x;
    }
    vector<long long> x(k);
    vector<string> value(k);
    for (auto& v : x) { cin >> token; v = scaled(token, 3); }
    for (auto& v : value) cin >> v;
    long long numerator = 1000LL * m - totalMean;
    int chosen = k - 1;
    for (int i = 0; i + 1 < k; ++i) {
        i128 left = i128(2000) * numerator;
        i128 middle = x[i] + x[i + 1];
        // All quantities are nonnegative: compare to the exact midpoint.
        if (left * left <= middle * middle * variance) {
            chosen = i;
            break;
        }
    }
    cout << value[chosen] << '\n';
}
```

<a id="problem-b"></a>

## B. 流程规划（其二）

标签：`动态规划` · `01背包` · `精度`

状态：**已实现**。已通过 C++17 编译、120 组本地对拍及复刻样例；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

从 $n$ 个可选环节中各选或不选一次。选中集合 $S$ 的收益是 $\sum\mu_i$，总标准差是 $\sqrt{\sum\sigma_i^2}$。非空集合需满足 $m/\sqrt{\sum\sigma_i^2}\ge q$；也允许选择空集合，收益为 0。求最大收益。这里 $n\le100$，每个整数收益 $\mu_i\le100$，标准差保留一位小数，$q$ 保留三位小数。输入依次为 `n m q`、$n$ 个收益、$n$ 个标准差；输出一个最大收益整数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609B)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

**把条件改写成“总风险受限”。** 对非空集合平方移项可得 $q^2\sum\sigma_i^2\le m^2$。每个环节贡献固定收益和固定的方差，且最多选择一次，因此是 01 背包。

**为什么按收益定义状态？** 方差含小数，但总收益最多只有 10000。定义 `dp[v]` 为恰好取得收益 $v$ 所需的最小风险，无法达到时为无穷大。将标准差放大 10 倍后的整数记为 $s_i$，风险取 $s_i^2$，于是它等于真实方差的 100 倍。

初始 `dp[0]=0`。处理第 $i$ 个环节时，收益从大到小更新：

$$dp[v]=\min(dp[v],dp[v-\mu_i]+s_i^2).$$

倒序是为了让每个环节最多使用一次。若正序更新，就会错误地变成完全背包。

令 $Q=1000q$，最终可行条件完全使用整数判断：

$$dp[v]\cdot Q^2\le100\,m^2\cdot10^6.$$

从大到小扫描收益，输出第一个可行值。

**正确性。** 对每个环节，所有方案分为“不选它”和“选它”两类，转移分别覆盖两类方案并取较小风险。归纳得到 `dp[v]` 为收益恰为 $v$ 的最小风险。只有这一最小风险都超限时，该收益才不可行；因此最后的倒序扫描得到最大可行收益。

**复杂度。** 设 $U=\sum\mu_i\le10000$，时间 $O(nU)$，空间 $O(U)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int fixedPoint(const string& s, int digits) {
    size_t pos = s.find('.');
    string a = s.substr(0, pos);
    string b = pos == string::npos ? "" : s.substr(pos + 1);
    b.resize(digits, '0');
    int base = 1;
    while (digits--) base *= 10;
    return stoi(a) * base + stoi(b.empty() ? "0" : b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string qText;
    if (!(cin >> n >> m >> qText)) return 0;
    int q = fixedPoint(qText, 3);
    vector<int> benefit(n), risk(n);
    for (int& x : benefit) cin >> x;
    for (int& x : risk) {
        string s; cin >> s;
        x = fixedPoint(s, 1);
        x *= x;
    }
    int maximum = accumulate(benefit.begin(), benefit.end(), 0);
    const int INF = 1000000000;
    vector<int> dp(maximum + 1, INF);
    dp[0] = 0;
    int prefix = 0;
    for (int i = 0; i < n; ++i) {
        prefix += benefit[i];
        for (int v = prefix; v >= benefit[i]; --v) {
            if (dp[v - benefit[i]] != INF)
                dp[v] = min(dp[v], dp[v - benefit[i]] + risk[i]);
        }
    }
    long long limit = 100LL * m * m * 1000000;
    for (int v = maximum; v >= 0; --v) {
        if (dp[v] != INF && 1LL * dp[v] * q * q <= limit) {
            cout << v << '\n';
            break;
        }
    }
}
```

<a id="problem-c"></a>

## C. 轮转调度

标签：`模拟` · `队列` · `调度` · `状态机`

状态：**已实现**。已通过 C++17 编译、100 组本地对拍及复刻样例；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

有 $n$ 个任务、$m$ 个 CPU 和 $m$ 条任务队列。任务按编号轮流进入各队列，每个 CPU 有自己的时间片长度。CPU 从当前对应的队列取出任务，普通速度每毫秒完成 1 单位工作，若该 CPU 是这个任务偏好的 CPU，速度变成 2；最后不足 2 单位也需要 1 毫秒。

每隔 $T$ 毫秒，CPU 对应的队列整体循环移动一位。运行中的任务不中断，也不算在队列中。若一个时间片结束但任务尚未完成，要放回当时 CPU 对应队列的末尾。同一时刻先结束时间片并放回旧队列，再改变对应关系，最后由空闲 CPU 取任务。输出每个任务从第一次开始执行到最终完成的经过时间。

题目规模为 $n,m\le100$，任务工作量和 CPU 时间片均不超过 100。输入先给 `n m T`，接着给 $m$ 个 CPU 的时间片长度；每个任务一行 `工作量 偏好CPU数 偏好CPU编号列表`。CPU 和任务编号均从 1 开始，按任务顺序输出 $n$ 个答案。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609C)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

**状态。** 每条队列保存等待的任务编号；每个 CPU 保存正在执行的任务及时间片结束时刻；每个任务保存剩余工作量、首次开始时刻和最后答案。

**为什么逐毫秒模拟可行？** 总工作量 $W\le10000$，只要尚有任务未完成，就至少有一个 CPU 在执行或者能立即从非空队列取任务；执行速度至少为 1，因此经过时间不超过 $W$。虽然 $T$ 可很大，也无需模拟到 $T$。

每个整数时刻依次做三件事：

1. 处理所有此时结束的时间片。任务完成则记录答案；未完成则放回旋转前对应的队列。
2. 用 `now / T` 得到已经发生的旋转次数。CPU `cpu` 此时对应 `(cpu + now / T) % m` 号队列。
3. 空闲 CPU 从新对应队列取任务。速度为 `speed` 时，本次持续时间为 `min(时间片, ceil(剩余工作量/speed))`。

代码在开始时间片时扣去这一次预计完成的工作量，但直到时间片结束才处理完成或重新入队，任务在执行期间始终只存在于 CPU 状态中。

**边界。** 时间片恰好在旋转时刻结束，放回队列要使用 `(now-1)/T` 对应的旧关系。偏好速度依据 CPU 实际编号判断，不随队列旋转。答案是“完成时间减首次执行时间”，不是完成时刻本身。

**正确性。** 初始队列与题意相同。每个时刻按照题目规定的优先顺序更新，取队首、工作量扣减、队尾回插均保持一致，故由时间归纳可知所有任务状态与真实过程相同，最终时间差即所求。

**复杂度。** 时间 $O(mW+nm)$，空间 $O(nm+n+m)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll period;
    if (!(cin >> n >> m >> period)) return 0;
    vector<int> quantum(m), work(n);
    for (int& x : quantum) cin >> x;
    vector<vector<bool>> preferred(n, vector<bool>(m));
    vector<queue<int>> waiting(m);
    for (int i = 0; i < n; ++i) {
        int count; cin >> work[i] >> count;
        while (count--) { int cpu; cin >> cpu; preferred[i][cpu - 1] = true; }
        waiting[i % m].push(i);
    }
    vector<int> running(m, -1);
    vector<ll> ends(m), first(n, -1), answer(n);
    int completed = 0;
    for (ll now = 0; completed < n; ++now) {
        // Complete slices before applying a rotation at this timestamp.
        for (int cpu = 0; cpu < m; ++cpu) {
            int job = running[cpu];
            if (job == -1 || ends[cpu] != now) continue;
            if (work[job] == 0) {
                answer[job] = now - first[job];
                ++completed;
            } else {
                int oldQueue = (cpu + (now - 1) / period % m) % m;
                waiting[oldQueue].push(job);
            }
            running[cpu] = -1;
        }
        if (completed == n) break;
        int shift = now / period % m;
        for (int cpu = 0; cpu < m; ++cpu) {
            int queueId = (cpu + shift) % m;
            if (running[cpu] != -1 || waiting[queueId].empty()) continue;
            int job = waiting[queueId].front();
            waiting[queueId].pop();
            int speed = preferred[job][cpu] ? 2 : 1;
            int duration = min(quantum[cpu], (work[job] + speed - 1) / speed);
            if (first[job] == -1) first[job] = now;
            work[job] = max(0, work[job] - duration * speed);
            running[cpu] = job;
            ends[cpu] = now + duration;
        }
    }
    for (int i = 0; i < n; ++i) cout << answer[i] << (i + 1 == n ? '\n' : ' ');
}
```

<a id="problem-d"></a>

## D. 数字分组

标签：`图论` · `二分图` · `带权并查集` · `区间` · `构造`

状态：**已实现**。已通过 C++17 编译、240 组本地对拍（输出由独立检查器验证）；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

把 $n$ 个互不相同的正整数划分为尽量少的组，每个数恰好出现一次。$op=0$ 时，同组不能出现满足 $x=ky$ 的两个数；$op=1$ 时，同组不能出现满足 $\lfloor x/y\rfloor=k$ 的两个数。给定 $k\ge2$，输出最少组数和任意合法分组。规模 $n\le5\times10^5$、数值不超过 $10^{18}$。

输入给出 `n k op`，随后是 $n$ 个互不相同的正整数。输出最少组数，再对每组输出其大小与成员，允许任意最优合法划分。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609D)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

把每个数当成图的一个顶点，互相冲突的两数之间连边。分组就是给图染色，使每条边两端颜色不同，并最小化颜色数。

**先证明最多三色。** 设 $L(x)=\lfloor\log_k x\rfloor$。冲突边取较大端 $x$、较小端 $y$，则 $k\le x/y<k+1\le k^2$，从而 $L(x)-L(y)$ 只可能为 1 或 2。因此按 `L(x)%3` 分组一定合法。实际计算用反复整数除以 $k$，不使用浮点对数。

所以答案只有三种：无边时 1；有边且为二分图时 2；不是二分图时 3。

**`op=0` 的边很少。** 对每个 $x$，只需判断 $x/k$ 是否为输入中的整数。每个顶点至多有一个更小的相邻点，图不会出现环，天然为二分图。排序、二分查找并加入异色约束即可。

**`op=1` 不能枚举所有边。** 对固定的较大端 $x$，全部较小邻居满足：

$$\frac{x}{k+1}<y\le\frac{x}{k}.$$

排序后，这是连续下标区间 $[l,r]$。若希望二染色，则这一整段邻居都必须同色，且与 $x$ 异色。于是用带奇偶关系的并查集维护两类约束：`join(a,b,0)` 同色，`join(a,b,1)` 异色。

将邻居区间内相邻位置依次加入同色约束，再让 $x$ 与区间第一个点异色。为了避免重复合并长区间，再用一个“后继并查集”：位置 $j$ 与 $j+1$ 的同色约束已经加入后，就永久跳过 $j$。每个相邻位置最多处理一次，总约束数为线性级别。

若所有约束不矛盾，输出奇偶并查集给出的两色；若发现矛盾，二色不可能，再用前述三色构造。无冲突边则所有点放在同一组。

**正确性。** 一个点的邻居全同色且与它异色，恰好等价于该点连接的全部边都满足二染色要求。区间相邻合并传递地约束整段；跳过的约束此前已经成立，不会遗漏。并查集能判定所有约束是否相容，因此能准确区分一色、二色与至少三色；三色构造又给出上界，故组数最优。

**复杂度。** 排序及二分 $O(n\log n)$，并查集合并均摊 $O(n\alpha(n))$，空间 $O(n)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

struct ParityDSU {
    vector<int> parent, size, parity;
    explicit ParityDSU(int n) : parent(n), size(n, 1), parity(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        int old = parent[x];
        parent[x] = find(old);
        parity[x] ^= parity[old];
        return parent[x];
    }
    bool join(int a, int b, int difference) {
        int ra = find(a), rb = find(b);
        int relation = parity[a] ^ parity[b] ^ difference;
        if (ra == rb) return relation == 0;
        if (size[ra] < size[rb]) swap(ra, rb);
        parent[rb] = ra;
        parity[rb] = relation;
        size[ra] += size[rb];
        return true;
    }
};

struct Successor {
    vector<int> parent;
    explicit Successor(int n) : parent(n + 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) {
        int root = x;
        while (parent[root] != root) root = parent[root];
        while (parent[x] != x) { int next = parent[x]; parent[x] = root; x = next; }
        return root;
    }
    void erase(int x) { parent[x] = find(x + 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, op;
    ll k;
    if (!(cin >> n >> k >> op)) return 0;
    vector<ll> values(n);
    for (ll& x : values) cin >> x;
    sort(values.begin(), values.end());
    ParityDSU dsu(n);
    Successor unused(n);
    bool hasEdge = false, bipartite = true;
    for (int i = 0; i < n && bipartite; ++i) {
        if (op == 0) {
            if (values[i] % k != 0) continue;
            auto it = lower_bound(values.begin(), values.end(), values[i] / k);
            if (it != values.end() && *it == values[i] / k) {
                hasEdge = true;
                bipartite = dsu.join(i, int(it - values.begin()), 1);
            }
        } else {
            int left = upper_bound(values.begin(), values.end(), values[i] / (k + 1)) - values.begin();
            int right = int(upper_bound(values.begin(), values.end(), values[i] / k) - values.begin()) - 1;
            if (left > right) continue;
            hasEdge = true;
            // All smaller neighbours of i must have the same colour.
            for (int j = unused.find(left); j < right; j = unused.find(j)) {
                if (!dsu.join(j, j + 1, 0)) { bipartite = false; break; }
                unused.erase(j);
            }
            if (bipartite) bipartite = dsu.join(i, left, 1);
        }
    }
    int groupCount = !hasEdge ? 1 : (bipartite ? 2 : 3);
    vector<vector<ll>> groups(groupCount);
    for (int i = 0; i < n; ++i) {
        int colour = 0;
        if (groupCount == 2) {
            dsu.find(i);
            colour = dsu.parity[i];
        } else if (groupCount == 3) {
            ll x = values[i];
            int level = 0;
            while (x >= k) { x /= k; ++level; }
            colour = level % 3;
        }
        groups[colour].push_back(values[i]);
    }
    cout << groupCount << '\n';
    for (const auto& group : groups) {
        cout << group.size();
        for (ll x : group) cout << ' ' << x;
        cout << '\n';
    }
}
```

<a id="problem-e"></a>

## E. 奇

标签：`树` · `点分治` · `动态查询` · `位运算` · `哈希表`

状态：**已实现**。已通过 C++17 编译、140 组本地对拍及复刻样例；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

树的每个点有固定颜色和可开关的灯，边有正整数权重。一个无序点对 $\{u,v\}$（允许 $u=v$）合格，需要两端灯都亮、路径边权和为 $k$ 的倍数，并且路径节点中恰有一种颜色出现奇数次。路径中间的点是否亮灯不影响颜色统计。

先输出初始答案，每次翻转一个点的灯后再次输出。规模为 $n,q\le10^5$、颜色数 $m\le40$、$k\le4$。输入依次为 `n m k q`、长度为 $n$ 的灯状态 01 字符串、$n$ 个颜色、$n-1$ 条带权边和 $q$ 个待翻转点编号；点与颜色编号从 1 开始。边权不超过 $10^6$。输出初始及每次开关后的答案，共 $q+1$ 行。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609E)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

**先把“奇数次颜色”变为异或。** 颜色 $c$ 对应第 $c-1$ 位的 1。沿路径异或所有点的颜色位，得到的掩码每一位恰好表示该颜色出现次数的奇偶性。“恰有一种奇数次颜色”等价于掩码是一个单独的 1。

直接对每次开关重新统计点对过慢。使用点分治：不断找到连通块重心，删除重心，再递归处理各子块。每个点只会经历 $O(\log n)$ 个重心。

**重心处存什么？** 对重心 $c$ 和点 $u$，记录：

- `mask(u,c)`：包含两端的路径颜色异或；
- `distance(u,c)%k`；
- $u$ 属于删除 $c$ 后的哪一个分支。

每个重心维护一个“所有亮点”的计数哈希表，并为每个分支另维护计数表。键为“颜色掩码、距离余数”。

**如何查询与 $u$ 合格的亮点数？** 若路径经过 $c$，两端掩码异或会把重心颜色抵消两次，所以实际路径掩码为：

$$mask(u,c)\oplus mask(v,c)\oplus bit(c).$$

枚举那一种出现奇数次的颜色 $b$，则需要查找的另一个端点掩码为 `mask(u,c)^bit(c)^bit(b)`，距离余数为 `(k-distance(u,c))%k`。查询重心总表，再减去 $u$ 所在分支的表，排除未经过该重心的路径。沿着 $u$ 的全部重心祖先累加，即可得到它的全部合格伙伴数。

**开关怎么更新答案？**

- 原来灭灯：先查询已有亮点中的伙伴数，答案加上它，再额外加 1 计入 $\{u,u\}$，最后把 $u$ 加入全部相关计数表。
- 原来亮灯：先查询，此时结果已经包含自身，答案减去查询值，再从各表删除 $u$。

初始状态从全灭开始，依次加入初始亮灯节点。答案使用 `long long`。代码预先登记所有可能出现的哈希键，使用连续数组开放寻址保存计数；开关时仅修改计数，避免反复分配节点。

**为什么不重不漏？** 对两个不同端点，点分治过程中第一次把它们分开的重心，恰好是唯一将这个点对计入“总表减同分支表”的层。更高层被同分支减掉，更低层不会同时包含两端；自身点对仅在以自身为重心的层保留。因此查询恰好计数一次。距离与掩码条件又分别准确表达两项限制。

**复杂度。** 预处理约 $O(n\log n)$，每次开关期望 $O(m\log n)$；含初始化，总时间期望 $O((n+q)m\log n)$。计数表和祖先记录空间 $O(n\log n)$。查询数量仍随颜色数线性增长，应关注极限数据的运行时间。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using Mask = uint64_t;
using ll = long long;

struct Hash {
    size_t operator()(Mask x) const {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
};
class Counter {
    static constexpr Mask empty = ~Mask(0);
    vector<Mask> keys;
    vector<int> values;
    size_t capacityMask = 0;

    size_t slot(Mask key) const {
        size_t i = Hash{}(key) & capacityMask;
        while (keys[i] != empty && keys[i] != key) i = (i + 1) & capacityMask;
        return i;
    }
public:
    void reserve(size_t expected) {
        size_t capacity = 2;
        while (capacity < expected * 2) capacity <<= 1;
        keys.assign(capacity, empty);
        values.assign(capacity, 0);
        capacityMask = capacity - 1;
    }
    void emplace(Mask key, int value) {
        size_t i = slot(key);
        if (keys[i] == empty) { keys[i] = key; values[i] = value; }
    }
    int get(Mask key) const {
        size_t i = slot(key);
        return keys[i] == key ? values[i] : 0;
    }
    void add(Mask key, int delta) { values[slot(key)] += delta; }
};
struct Edge { int to, weight; };
struct Record { Mask mask; int centre, branch, distance; };
struct Visit { int node, parent, distance; Mask mask; };

class Solver {
    int n, modulus;
    vector<vector<Edge>> tree;
    vector<Mask> bit, colours;
    vector<bool> removed;
    vector<int> parent, subtree;
    vector<vector<Record>> ancestors;
    vector<Counter> all, branch;

    int centroid(int start, vector<int>& nodes) {
        nodes.push_back(start);
        parent[start] = -1;
        for (size_t i = 0; i < nodes.size(); ++i) {
            int v = nodes[i];
            for (const auto& e : tree[v]) {
                if (removed[e.to] || e.to == parent[v]) continue;
                parent[e.to] = v;
                nodes.push_back(e.to);
            }
        }
        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it) {
            int v = *it;
            subtree[v] = 1;
            for (const auto& e : tree[v])
                if (!removed[e.to] && parent[e.to] == v) subtree[v] += subtree[e.to];
        }
        int best = start, bestPart = int(nodes.size());
        for (int v : nodes) {
            int largest = int(nodes.size()) - subtree[v];
            for (const auto& e : tree[v])
                if (!removed[e.to] && parent[e.to] == v) largest = max(largest, subtree[e.to]);
            if (largest < bestPart) { bestPart = largest; best = v; }
        }
        return best;
    }

    void decompose(int start) {
        vector<int> nodes;
        int centre = centroid(start, nodes);
        removed[centre] = true;
        all[centre].reserve(nodes.size());
        ancestors[centre].push_back({bit[centre], centre, -1, 0});
        all[centre].emplace(bit[centre] << 2, 0);
        for (const auto& edge : tree[centre]) {
            if (removed[edge.to]) continue;
            int id = int(branch.size());
            branch.emplace_back();
            vector<Visit> visits{{edge.to, centre, edge.weight % modulus, bit[centre] ^ bit[edge.to]}};
            for (size_t i = 0; i < visits.size(); ++i) {
                Visit cur = visits[i];
                for (const auto& next : tree[cur.node]) {
                    if (removed[next.to] || next.to == cur.parent) continue;
                    visits.push_back({next.to, cur.node, (cur.distance + next.weight) % modulus, cur.mask ^ bit[next.to]});
                }
            }
            branch[id].reserve(visits.size());
            for (const auto& cur : visits) {
                ancestors[cur.node].push_back({cur.mask, centre, id, cur.distance});
                Mask key = (cur.mask << 2) | Mask(cur.distance);
                all[centre].emplace(key, 0);
                branch[id].emplace(key, 0);
            }
        }
        for (const auto& edge : tree[centre])
            if (!removed[edge.to]) decompose(edge.to);
    }

public:
    Solver(int count, int k) : n(count), modulus(k), tree(n), bit(n), removed(n), parent(n), subtree(n), ancestors(n), all(n) {
        branch.reserve(n);
    }
    void read() {
        for (Mask& x : bit) { int colour; cin >> colour; x = Mask(1) << (colour - 1); }
        colours = bit;
        sort(colours.begin(), colours.end());
        colours.erase(unique(colours.begin(), colours.end()), colours.end());
        for (int i = 1; i < n; ++i) {
            int a, b, w; cin >> a >> b >> w; --a; --b;
            tree[a].push_back({b, w}); tree[b].push_back({a, w});
        }
        decompose(0);
    }
    ll partners(int node) const {
        ll result = 0;
        for (const auto& r : ancestors[node]) {
            Mask base = r.mask ^ bit[r.centre];
            int required = (modulus - r.distance) % modulus;
            for (Mask oddColour : colours) {
                Mask key = ((base ^ oddColour) << 2) | Mask(required);
                result += all[r.centre].get(key);
                if (r.branch != -1) result -= branch[r.branch].get(key);
            }
        }
        return result;
    }
    void change(int node, int delta) {
        for (const auto& r : ancestors[node]) {
            Mask key = (r.mask << 2) | Mask(r.distance);
            all[r.centre].add(key, delta);
            if (r.branch != -1) branch[r.branch].add(key, delta);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, q;
    if (!(cin >> n >> m >> k >> q)) return 0;
    string lamps; cin >> lamps;
    Solver solver(n, k);
    solver.read();
    ll answer = 0;
    for (int v = 0; v < n; ++v) {
        if (lamps[v] == '1') {
            answer += solver.partners(v) + 1;
            solver.change(v, 1);
        }
    }
    cout << answer << '\n';
    while (q--) {
        int v; cin >> v; --v;
        if (lamps[v] == '1') {
            answer -= solver.partners(v);
            solver.change(v, -1);
            lamps[v] = '0';
        } else {
            answer += solver.partners(v) + 1;
            solver.change(v, 1);
            lamps[v] = '1';
        }
        cout << answer << '\n';
    }
}
```
