---
title: "CSP 202104 五题题解"
contest: "202104"
contest_month: "2021-04"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "计数数组", "直方图", "二维前缀和", "矩形查询", "状态机", "优先队列", "有序集合", "模拟", "动态规划", "因数", "计数", "最短路", "中国剩余定理", "扩展欧几里得", "周期"]
status: "published"
problems: [{"id": "A", "title": "灰度直方图", "tags": ["计数数组", "直方图"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce971a67df0b81749c1a2"}}, {"id": "B", "title": "邻域均值", "tags": ["二维前缀和", "矩形查询"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce972a67df0b81749c1b8"}}, {"id": "C", "title": "DHCP 服务器", "tags": ["状态机", "优先队列", "有序集合", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adceb1074ace1cba9a1bca0"}}, {"id": "D", "title": "校门外的树", "tags": ["动态规划", "因数", "计数"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adceb1274ace1cba9a1bca8"}}, {"id": "E", "title": "疫苗运输", "tags": ["最短路", "中国剩余定理", "扩展欧几里得", "周期"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；3 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 95 分 Time Exceeded（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104E/"}], "oj": {"status": "failed", "score": 95, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6adceb1474ace1cba9a1bccd"}}]
---

# CSP 202104 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 灰度直方图

标签：`计数数组` · `直方图`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给n×m灰度矩阵，每个像素值在0…L-1，按灰度顺序输出各值出现次数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104A/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104A)。

### 题解

初始化长度L的计数数组，读到值x就执行count[x]++。全部读完按0…L-1输出，包括未出现值的0。

每个像素恰好给其灰度桶贡献一次，计数和应为n*m，可用来手工核对。时间 $O(nm+L)$，空间 $O(L)$，无需保存整幅图像。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<int> count(L);
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        ++count[x];
    }
    for (int i = 0; i < L; i++) {
        if (i)
            cout << ' ';
        cout << count[i];
    }
    cout << '\n';
}
```

<a id="problem-b"></a>

## B. 邻域均值

标签：`二维前缀和` · `矩形查询`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

对n×n灰度图中的每个像素，取行列距离均不超过r且位于图内的邻域，统计平均灰度≤t的位置数，n≤600。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104B/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104B)。

### 题解

先做二维前缀和。每个邻域与图像边界取交，得到矩形[u,x]×[v,y]，用四项容斥O(1)取总灰度。判断总和≤t×实际格子数即可，避免浮点除法。

前缀和容斥恰好留下目标矩形的每个元素一次，边界裁剪保证平均值分母也是实际邻域大小；角落不能仍除以(2r+1)²。时间、空间均 $O(n^2)$，总和及乘积使用64位。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    vector<vector<long long>> s(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            long long x;
            cin >> x;
            s[i][j] = x + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int u = max(1, i - r), v = max(1, j - r), x = min(n, i + r), y = min(n, j + r);
            long long sum = s[x][y] - s[u - 1][y] - s[x][v - 1] + s[u - 1][v - 1];
            if (sum <= 1LL * t * (x - u + 1) * (y - v + 1))
                ++ans;
        }
    cout << ans << '\n';
}
```

<a id="problem-c"></a>

## C. DHCP 服务器

标签：`状态机` · `优先队列` · `有序集合` · `模拟`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

模拟具有 N 个地址的 DHCP 服务器。地址有未分配、待分配、占用、过期四种状态；处理 DIS/REQ 报文时按题目优先级选择地址、确认或拒绝，并限制租约长度。待分配到期清除所有者，占用到期保留所有者。N、报文数不超过 $10^4$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104C/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104C)。

### 题解

每个地址保存状态、所有者、到期时间、版本。最小堆保存租约事件；处理报文前弹出已到期事件，版本不匹配说明租约已被更新，丢弃。空闲与过期地址各放入有序集合，用户到其地址另建哈希索引。

先按接收方和消息类型过滤。DIS 优先复用该客户原有地址，其次最小空闲地址，再次最小过期地址，改成待分配并发送 OFR。REQ 发给其他服务器时释放该客户的待分配地址；发给本机时检查地址范围及所有者，不符发送 NAK，否则改为占用并发送 ACK。

新到期时间在请求为 0 时取当前时间加默认租期，否则将“请求到期时间减当前时间”限制在最短、最长租期之间。不要直接对绝对到期时间做限制。每次变更同时维护状态、索引和版本，按事件与报文时间顺序归纳即可覆盖题设规则。每个客户至多持有一个地址：首次只能分配一个，后续 DIS 必然复用它，REQ 也不能获得别人的地址。时间 $O((N+q)\log(N+q))$，空间 $O(N+q)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
struct IP {
    int state = 0;
    string owner;
    ll expiry = 0;
    int version = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    ll def, hi, lo;
    string host;
    cin >> n >> def >> hi >> lo >> host >> q;
    vector<IP> ip(n + 1);
    set<int> free, expired;
    for (int i = 1; i <= n; i++)
        free.insert(i);
    unordered_map<string, int> owned;
    using Event = tuple<ll, int, int>;
    priority_queue<Event, vector<Event>, greater<Event>> events;
    auto clear = [&](int x) {
        owned.erase(ip[x].owner);
        ip[x].owner.clear();
        ip[x].state = 0;
        ip[x].expiry = 0;
        ++ip[x].version;
        free.insert(x);
    };
    while (q--) {
        ll t, end;
        string sender, receiver, type;
        int addr;
        cin >> t >> sender >> receiver >> type >> addr >> end;
        while (!events.empty() && get<0>(events.top()) <= t) {
            auto [time, x, version] = events.top();
            events.pop();
            if (version != ip[x].version)
                continue;
            if (ip[x].state == 1)
                clear(x);
            else if (ip[x].state == 2) {
                ip[x].state = 3;
                ip[x].expiry = 0;
                expired.insert(x);
            }
        }
        if (receiver != host && receiver != "*" && type != "REQ")
            continue;
        if (type != "DIS" && type != "REQ")
            continue;
        if (receiver == "*" && type != "DIS")
            continue;
        if (receiver == host && type == "DIS")
            continue;
        if (type == "REQ" && receiver != host) {
            auto it = owned.find(sender);
            if (it != owned.end() && ip[it->second].state == 1)
                clear(it->second);
            continue;
        }
        if (type == "DIS") {
            auto it = owned.find(sender);
            if (it != owned.end())
                addr = it->second;
            else if (!free.empty())
                addr = *free.begin();
            else if (!expired.empty())
                addr = *expired.begin();
            else
                continue;
            if (!ip[addr].owner.empty())
                owned.erase(ip[addr].owner);
            ip[addr].owner = sender;
            owned[sender] = addr;
            ip[addr].state = 1;
        } else {
            if (addr < 1 || addr > n || ip[addr].owner != sender) {
                cout << host << ' ' << sender << " NAK " << addr << " 0\n";
                continue;
            }
            ip[addr].state = 2;
        }
        free.erase(addr);
        expired.erase(addr);
        ip[addr].expiry = end == 0 ? t + def : t + clamp(end - t, lo, hi);
        ++ip[addr].version;
        events.push({ip[addr].expiry, addr, ip[addr].version});
        cout << host << ' ' << sender << ' ' << (type == "DIS" ? "OFR" : "ACK") << ' ' << addr
             << ' ' << ip[addr].expiry << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 校门外的树

标签：`动态规划` · `因数` · `计数`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

数轴上障碍物坐标为递增的 $a_1,\ldots,a_n$。选择一些障碍物作为分段端点，每一段至少种一棵树，树和两端点构成整数公差的等差数列，任何树不能落在障碍物上。两种方案仅当种树坐标集合不同时才算不同。求方案数模 $10^9+7$。$n\le1000,a_i\le10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104D/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104D)。

### 题解

固定一段的两端 $a_l,a_r$，公差 d 必须是距离 $a_r-a_l$ 的真因子；若 d 还整除某个内部障碍物到左端的距离，就会把树种在障碍物上，不能使用。将剩下的合法公差数记作 $ways(l,r)$。

定义 $dp[r]$ 为左端到障碍物 r 的方案数，初始 $dp[1]=1$。把最后一段左端枚举为 l，则 $dp[r]+=dp[l]\,ways(l,r)$。固定 l 从左向右扫描 r，先数当前距离的未禁用真因子，再把当前距离的所有因子标为禁用，因为这个端点会成为下一轮的内部障碍。用 l 作为时间戳，避免反复清空标记数组。

**为什么不会因不同划分重复计数？** 给定最终种树集合，从最左障碍开始，第一棵树决定公差 d；该段右端只能是首个与左端距离被 d 整除的后续障碍，否则会在更早的障碍处种树。于是第一段唯一确定，递归处理后面，整套划分也唯一。因此按最后一段 DP 恰好统计本质不同的树集合。

用筛式枚举预处理所有距离的因子。设最大距离 A、其范围内最大因子数为 D，时间 $O(A\log A+n^2D)$，因子表空间 $O(A\log A)$，其余空间 $O(A+n)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
constexpr long long MOD = 1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int maximum = a.back() - a.front();
    vector<vector<int>> divisors(maximum + 1);
    for (int d = 1; d <= maximum; ++d)
        for (int multiple = d; multiple <= maximum; multiple += d)
            divisors[multiple].push_back(d);
    vector<int> blocked(maximum + 1, -1);
    vector<long long> dp(n);
    dp[0] = 1;
    for (int l = 0; l < n - 1; ++l)
        for (int r = l + 1; r < n; ++r) {
            int distance = a[r] - a[l], ways = 0;
            for (int d : divisors[distance])
                if (d < distance && blocked[d] != l)
                    ++ways;
            dp[r] = (dp[r] + dp[l] * ways) % MOD;
            for (int d : divisors[distance])
                blocked[d] = l;
        }
    cout << dp.back() << '\n';
}
```

<a id="problem-e"></a>

## E. 疫苗运输

标签：`最短路` · `中国剩余定理` · `扩展欧几里得` · `周期`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；3 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 95 分 Time Exceeded（复刻评测）。

### 题意

每条循环线路有一辆车，从时刻 0 起按固定方向不断运行。疫苗可以在站点 1 等待车辆，但运输途中只能在两车同一时刻到达同一站点时换乘，不能卸货留站等待。求从站点 1 把疫苗送到其他站点的最早时刻，无解输出 `inf`。输入 `n m`；每条线路给出站点数以及依次的“站点、到下一站耗时”。$n,m\le500$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104E/)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104E)。

### 题解

**最短路的点应当是线路。** 不能把站点建成普通最短路点：疫苗不能留站等待，而一旦登上一条循环线路，就可以一直留在车上等待合适的换乘机会。设线路 $u$ 的周期为 $P_u$，第一次到站 $s$ 的时刻为 $a_{u,s}$。之后到站时刻是 $a_{u,s}+kP_u$。

令 $dist[u]$ 为最早登上线路 $u$ 的时刻。起点初始化为每条经过站点 1 的线路第一次到达站点 1 的时间。已登车后，在某公共站 $s$ 换乘到 $v$ 需要解

$$t\equiv a_{u,s}\pmod{P_u},\qquad t\equiv a_{v,s}\pmod{P_v}.$$

令 $g=\gcd(P_u,P_v)$。两偏移之差不能被 $g$ 整除时，该站永远不能换乘；否则用扩展欧几里得求逆元得到一个解 $t_0$，所有解相差 $L=\operatorname{lcm}(P_u,P_v)$。把 $t_0$ 向上平移到第一个不早于 $dist[u]$ 的解，用它松弛 $v$。线路对的 gcd 和逆元可复用，公共站逐个枚举。

**为何可以 Dijkstra？** 更晚登上同一条车不可能获得更早的换乘时刻；这是一张满足 FIFO 性质的时间依赖图，因此最早未确定线路可以安全定型。每次定型线路 $u$，也用它更新全部途经站的最早到达时间。

**复杂度与数值范围。** 扫描式 Dijkstra 为 $O(m^2n+m^2\log P)$，空间 $O(mn)$。周期乘积和等待后的绝对时间可能大，使用 `__int128` 完成 CRT 与时间运算并自行输出十进制，不能在取模前先做可能溢出的 64 位乘法。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using I = __int128_t;
ll inverse(ll a, ll mod) {
    ll b = mod, x = 1, y = 0;
    while (b) {
        ll q = a / b;
        ll c = a - q * b;
        a = b;
        b = c;
        c = x - q * y;
        x = y;
        y = c;
    }
    return (x % mod + mod) % mod;
}
void print(I x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> period(m);
    vector<vector<ll>> offset(m, vector<ll>(n, -1));
    for (int i = 0; i < m; ++i) {
        int length;
        cin >> length;
        for (int j = 0; j < length; ++j) {
            int s;
            ll travel;
            cin >> s >> travel;
            offset[i][s - 1] = period[i];
            period[i] += travel;
        }
    }
    const I INF = I(1) << 120;
    vector<I> dist(m, INF), answer(n, INF);
    vector<bool> used(m);
    for (int i = 0; i < m; ++i)
        if (offset[i][0] >= 0)
            dist[i] = offset[i][0];
    for (int iteration = 0; iteration < m; ++iteration) {
        int u = -1;
        for (int i = 0; i < m; ++i)
            if (!used[i] && (u < 0 || dist[i] < dist[u]))
                u = i;
        if (u < 0 || dist[u] == INF)
            break;
        used[u] = true;
        for (int s = 0; s < n; ++s)
            if (offset[u][s] >= 0) {
                I t = offset[u][s];
                if (t < dist[u])
                    t += (dist[u] - t + period[u] - 1) / period[u] * period[u];
                answer[s] = min(answer[s], t);
            }
        for (int v = 0; v < m; ++v)
            if (!used[v]) {
                ll g = gcd(period[u], period[v]), mod = period[v] / g;
                ll inv = mod == 1 ? 0 : inverse(period[u] / g, mod);
                I cycle = I(period[u]) * mod;
                for (int s = 0; s < n; ++s)
                    if (offset[u][s] >= 0 && offset[v][s] >= 0) {
                        ll difference = offset[v][s] - offset[u][s];
                        if (difference % g)
                            continue;
                        I factor = mod == 1 ? 0 : (I(difference / g) * inv % mod + mod) % mod;
                        I time = (offset[u][s] + I(period[u]) * factor) % cycle;
                        if (time < dist[u])
                            time += (dist[u] - time + cycle - 1) / cycle * cycle;
                        dist[v] = min(dist[v], time);
                    }
            }
    }
    for (int s = 1; s < n; ++s) {
        if (answer[s] == INF)
            cout << "inf";
        else
            print(answer[s]);
        cout << '\n';
    }
}
```
