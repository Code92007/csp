---
title: "CSP 202605 五题题解"
contest: "202605"
contest_month: "2026-05"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "数学", "精度", "模拟", "二分答案", "状态机", "调度", "异或", "前缀和", "贪心", "倍增", "树", "字典序", "候选根淘汰", "并查集", "启发式合并"]
status: "published"
problems: [{"id": "A", "title": "银行家舍入", "tags": ["数学", "精度", "模拟"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "已通过 C++17 编译、复刻样例和覆盖全部小数位和奇偶组合的本地校验；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202605A"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json"}, {"label": "公开存档（目录已发现，内容待核对）", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202605A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6e8a67df0b81749b446"}}, {"id": "B", "title": "机器人宿管指南", "tags": ["二分答案", "模拟", "数学"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "已通过 C++17 编译、复刻样例和100 组枚举对拍；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202605B"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json"}, {"label": "公开存档（目录已发现，内容待核对）", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202605B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6e9a67df0b81749b44f"}}, {"id": "C", "title": "死锁优化", "tags": ["模拟", "状态机", "调度"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "已通过 C++17 编译、复刻样例和90 组独立时间轴模拟对拍；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202605C"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json"}, {"label": "公开存档（目录已发现，内容待核对）", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202605C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6eba67df0b81749b463"}}, {"id": "D", "title": "石子游戏", "tags": ["异或", "前缀和", "贪心", "倍增"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "已通过 C++17 编译、复刻样例和110 组区间划分暴力对拍；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202605D"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json"}, {"label": "公开存档（目录已发现，内容待核对）", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202605D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6eda67df0b81749b46e"}}, {"id": "E", "title": "绝世好串", "tags": ["树", "字典序", "贪心", "候选根淘汰", "并查集", "启发式合并", "倍增"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；保存样例通过；2042 组独立 DP 对拍通过；7 组十万点构造运行通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202605E"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json"}, {"label": "公开题目存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202605E/"}, {"label": "zlxFTH：原题非官方完整算法", "url": "https://www.zhihu.com/question/2043989350854156307/answer/2044499207764105133"}, {"label": "CYMario：Bonus Ver. 探索报告", "url": "https://zhuanlan.zhihu.com/p/2083646963501815540"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6efa67df0b81749b475"}}]
---

# CSP 202605 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。E 根据补充参考资料给出完整规模算法，并保留小规模 DP 用于对拍。

<a id="problem-a"></a>

## A. 银行家舍入

标签：`数学` · `精度` · `模拟`

状态：**已实现**。已通过 C++17 编译、复刻样例和覆盖全部小数位和奇偶组合的本地校验；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

输入 $n$ 个形如 `a.b` 的非负数，每个数恰好有一位小数。第一行输出普通四舍五入结果，第二行输出向偶数舍入结果。向偶数舍入只在小数位恰为 5 时不同：在相邻两个整数中选偶数。例如 `2.5` 得 2，`3.5` 得 4。$n\le100$，整数部分不超过 $10^5$。

来源：[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202605A)；[公开存档（目录已发现，内容待核对）](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605A/)

### 题解

**先拆字符串，避免引入浮点误差。** 以小数点分开整数部分 $a$ 和小数位 $b$，两者都是整数。

普通四舍五入：$b\ge5$ 时结果为 $a+1$，否则为 $a$。向偶数舍入分三种情况：$b<5$ 向下，$b>5$ 向上，$b=5$ 时只有 $a$ 为奇数才加 1。

因此第二种结果可以写成 `a + (b > 5 || (b == 5 && a % 2 == 1))`。不要把向偶数舍入理解为“所有情况都找一个最近偶数”；只有恰好居中时才比较奇偶。

**正确性。** 两个判断式分别覆盖题目定义的全部小数位。恰为 5 时，$a$ 为偶数就保留，否则 $a+1$ 为偶数，因此符合规则。

**复杂度。** 设输入字符总数为 $L$，时间 $O(L+n)$，空间 $O(n)$，用于按两行输出。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> ordinary(n), even(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        size_t point = s.find('.');
        int a = stoi(s.substr(0, point)), b = s[point + 1] - '0';
        ordinary[i] = a + (b >= 5);
        even[i] = a + (b > 5 || (b == 5 && a % 2 == 1));
    }
    for (int i = 0; i < n; ++i) cout << ordinary[i] << (i + 1 == n ? '\n' : ' ');
    for (int i = 0; i < n; ++i) cout << even[i] << (i + 1 == n ? '\n' : ' ');
}
```

<a id="problem-b"></a>

## B. 机器人宿管指南

标签：`二分答案` · `模拟` · `数学`

状态：**已实现**。已通过 C++17 编译、复刻样例和100 组枚举对拍；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

第 0 天有 $n$ 个苹果。每天先按剩余量 $t$ 丢弃 $\lceil tk/100\rceil$ 个苹果，再让每个机器人吃一个。机器人数量每天相同，连续吃满 $m$ 天，过程中苹果不能不够。求最多机器人数量。输入一行 `n k m`，其中 $n\le10^{18}$、$1\le k\le5$、$m\le2000$，保证答案在 $[1,10^9]$ 中。

来源：[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202605B)；[公开存档（目录已发现，内容待核对）](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605B/)

### 题解

**先写“给定机器人数量，能否撑满”的检查函数。** 从初始苹果数开始，逐天损耗、检查是否够吃、扣除机器人数量。某天不够时立即返回不可行。

**单调性是二分的依据。** 机器人更多时，每天吃掉的苹果更多。每天损耗后的剩余量为 $t-\lceil tk/100\rceil=\lfloor(100-k)t/100\rfloor$，它随 $t$ 单调不减。因此如果 $x$ 个机器人可行，更少的机器人也可行；如果不可行，更多的也不可行。可行答案构成一段前缀。

在 `[0, 10^9]` 二分最后一个可行值。取上中位数 `(lo+hi+1)/2`，可行时令 `lo=mid`，否则 `hi=mid-1`，避免只差 1 时停不下来。

**整数上取整与范围。** 将 $t=100a+b$，$0\le b<100$，则损耗为 $ak+\lceil bk/100\rceil$，代码使用 `t/100*k + ((t%100)*k+99)/100`。全程整数运算，也避免直接做大数乘法。

**正确性。** 检查函数逐日执行原规则，所以准确判断一个数量是否可行。单调性保证每次二分都保留包含最优答案的区间，收敛后得到最大可行值。

**复杂度。** 时间 $O(m\log10^9)$，额外空间 $O(1)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; int k, days;
    if (!(cin >> n >> k >> days)) return 0;
    auto feasible = [&](ll robots) {
        ll left = n;
        for (int day = 0; day < days; ++day) {
            // ceil(left*k/100), without multiplying a value up to 1e18 by k.
            ll wasted = left / 100 * k + ((left % 100) * k + 99) / 100;
            left -= wasted;
            if (left < robots) return false;
            left -= robots;
        }
        return true;
    };
    ll lo = 0, hi = 1000000000;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (feasible(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
}
```

<a id="problem-c"></a>

## C. 死锁优化

标签：`模拟` · `状态机` · `调度`

状态：**已实现**。已通过 C++17 编译、复刻样例和90 组独立时间轴模拟对拍；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

有 $n\le10$ 个进程、$m\le40$ 种资源。每个进程从指定段开始，依次申请不同资源；申请成功后运行指定的若干段，包含成功这一段。运行时每段收益为它实际持有的资源数，等待时没有收益。已取得的资源一直保留到整个进程结束、主动放弃或被抢走。

每段先申请，再计算收益，最后释放。普通申请中，空闲资源由编号最小的申请者取得，已有持有者的资源拒绝普通申请。X 类无限等待；A 类连续失败 $w$ 次后在段末释放所持资源，继续等待当前资源；B 类第 $w$ 次失败时放弃这次申请并运行当前任务；C 类前 $w$ 次失败后，在下一段强制申请。对同一资源的强制申请者都开始运行，只有编号最大的实际持有资源，其他普通申请失败。被抢走资源的进程不重新执行已完成的任务。

X 类输入 `X st k a1 t1 ... ak tk`；其他类输入 `类型 st w k a1 t1 ... ak tk`。输出每个进程的总收益和从开始到结束的持续段数；永久等待则持续段数为 `-1`。所有开始时间、忍耐限度和任务时长都不超过 20，每进程任务数不超过 40。

来源：[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202605C)；[公开存档（目录已发现，内容待核对）](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605C/)

### 题解

第三题的难点是**同一段内各步骤的顺序**。不要一边遍历进程一边修改资源并立即计算收益，否则结果会错误地依赖遍历顺序。

**状态。** 资源数组 `owner[r]` 记录唯一的实际持有者。进程记录“未开始、等待、运行、结束”四种状态、当前任务、已失败次数、剩余运行段数、累计收益及是否已因本次等待释放过资源。实际持有数量每段从 `owner` 重新统计，资源被 C 类抢走时无需修改多个副本。

每段按四步执行：

1. 激活此段开始的进程，收集所有等待进程的普通申请和强制申请。
2. 按资源统一裁决。有强制申请则全部强制申请者进入运行、最大编号获得资源；否则，资源空闲时最小编号普通申请者成功。随后处理失败次数：B 类达到限度则也进入运行；A 类仅登记“段末释放”。
3. 申请全部完成后，按**此时的实际持有资源**给所有运行进程计算收益，并扣减剩余运行段数。新开始的任务也参与本段收益与扣减。
4. 本任务结束则下一段申请下一资源；全部任务结束则记录持续段数。统一释放结束进程及 A 类标记进程实际仍持有的资源。

**C 类的边界。** 失败次数在本次普通申请失败后增加。只有段首已经失败至少 $w$ 次，才进入强制申请列表，因此强制发生在第一次申请段之后第 $w$ 段，不会提前一段。

**怎样判断永久等待？** 不能真的模拟到题目中的 $10^{100}$。每次进程开始、任务开始/结束或 A 类首次触发释放，都记为一次事件。设 $H$ 为所有开始时间、任务时长、忍耐限度加 1 的最大值。若连续超过 $H$ 段没有事件，则既没有将要开始的进程，也没有仍在运行的任务或未到期的 B/C 类等待、A 类释放；其余请求只能永久等下去。反过来，只要还有上述有限计时状态，就必在 $H$ 段内产生事件。资源不再变化且无人可申请成功，故可以结束模拟。

**正确性。** 资源裁决分别准确实现强制申请优先、强制申请最大编号持有和普通申请最小编号成功的规则；收益统一在裁决后计算，释放统一在收益后执行。逐段归纳，所有进程状态、实际持有者与收益都与原过程相同。无事件判定排除了全部未来能改变状态的原因，因此只会把永久等待的进程标为 `-1`。

**复杂度。** 令总任务数为 $K$，事件数为 $O(n+K)$，有意义的时间轴长度为 $O(H(n+K))$。每段 $O(n+m)$，总时间 $O(H(n+K)(n+m))$，空间 $O(K+n+m)$。本题 $H\le21$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Process {
    char kind;
    int start, patience = 0, task = 0, failures = 0, remaining = 0;
    int state = 0; // 0: not started, 1: waiting, 2: running, 3: finished
    bool released = false;
    vector<int> resource, length;
    long long income = 0;
    int duration = -1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<Process> p(n);
    int horizon = 1;
    for (auto& x : p) {
        int tasks;
        cin >> x.kind >> x.start;
        if (x.kind != 'X') cin >> x.patience;
        cin >> tasks;
        horizon = max({horizon, x.start, x.patience + 1});
        for (int j = 0; j < tasks; ++j) {
            int r, t; cin >> r >> t;
            x.resource.push_back(r - 1); x.length.push_back(t);
            horizon = max(horizon, t);
        }
    }
    vector<int> owner(m, -1);
    int quiet = 0, completed = 0;
    for (int time = 1; completed < n; ++time) {
        bool event = false;
        for (auto& x : p) if (x.state == 0 && x.start == time) {
            x.state = 1; event = true;
        }
        vector<vector<int>> normal(m), forced(m);
        for (int i = 0; i < n; ++i) if (p[i].state == 1) {
            auto& x = p[i];
            int resource = x.resource[x.task];
            if (x.kind == 'C' && x.failures >= x.patience) forced[resource].push_back(i);
            else normal[resource].push_back(i);
        }
        vector<bool> succeeded(n), releaseAtEnd(n);
        for (int r = 0; r < m; ++r) {
            if (!forced[r].empty()) {
                // All forced applicants run, but only the largest id owns r.
                owner[r] = *max_element(forced[r].begin(), forced[r].end());
                for (int i : forced[r]) succeeded[i] = true;
            } else if (owner[r] == -1 && !normal[r].empty()) {
                int i = *min_element(normal[r].begin(), normal[r].end());
                owner[r] = i; succeeded[i] = true;
            }
        }
        for (int i = 0; i < n; ++i) if (p[i].state == 1) {
            auto& x = p[i];
            bool run = succeeded[i];
            if (!run) {
                ++x.failures;
                if (x.kind == 'A' && !x.released && x.failures == x.patience) {
                    releaseAtEnd[i] = true; x.released = true; event = true;
                }
                if (x.kind == 'B' && x.failures == x.patience) run = true;
            }
            if (run) {
                x.state = 2; x.remaining = x.length[x.task]; event = true;
            }
        }
        // Ownership has settled for this segment. A stolen resource no longer
        // contributes to its old holder's income, even if that holder is running.
        vector<int> held(n);
        for (int id : owner) if (id != -1) ++held[id];
        for (int i = 0; i < n; ++i) if (p[i].state == 2) {
            auto& x = p[i];
            x.income += held[i];
            if (--x.remaining == 0) {
                event = true;
                if (++x.task == int(x.resource.size())) {
                    x.state = 3; x.duration = time - x.start + 1;
                    releaseAtEnd[i] = true; ++completed;
                } else {
                    x.state = 1; x.failures = 0; x.released = false;
                }
            }
        }
        for (int& id : owner) if (id != -1 && releaseAtEnd[id]) id = -1;
        quiet = event ? 0 : quiet + 1;
        // Every future start / running task / patience timer must trigger within
        // horizon segments. A longer silent interval means permanent waiting.
        if (quiet > horizon) break;
    }
    for (const auto& x : p) cout << x.income << ' ' << x.duration << '\n';
}
```

<a id="problem-d"></a>

## D. 石子游戏

标签：`异或` · `前缀和` · `贪心` · `倍增`

状态：**已实现**。已通过 C++17 编译、复刻样例和110 组区间划分暴力对拍；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定序列 $b_1,\ldots,b_n$。一个区间 $[l,r]$ 是“后手必胜区间”，当且仅当 $b_l\oplus b_{l+2}\oplus\cdots=0$，取到不超过 $r$ 的最后位置。每次查询 $[L,R]$，要将它完整切分成连续、无重叠、无空隙的非空区间，使其中后手必胜区间数量最多。

输入 `n q`、$n$ 个数，再输入 $q$ 组 `L R`；每问输出最大数量。$n,q\le10^6$，$0\le b_i<2^{31}$。这里直接使用该博弈的判定结论；“必胜”指后手必胜，避免与先手概念混用。

来源：[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202605/statements.json)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202605D)；[公开存档（目录已发现，内容待核对）](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605D/)

### 题解

**先把完整切分转成选区间。** 任意切分中的必胜区间都是互不相交的；反过来，任取若干互不相交的必胜区间，空隙都可以另切成区间。所以最大数量等于“最多选择多少个互不相交的必胜区间”。

**只考虑奇数长度的候选区间。** 如果一个偶数长度区间必胜，最后一个数并未参与异或，删去最后一位后依然必胜且更早结束。因此寻找最早结束区间时，只需考虑右端点与左端点同奇偶的情况。

定义隔位异或前缀 $P_i=b_i\oplus P_{i-2}$，并规定 $P_{-1}=P_0=0$。对同奇偶的 $l,r$：

$$b_l\oplus b_{l+2}\oplus\cdots\oplus b_r=P_r\oplus P_{l-2}.$$

因此要找的是最早满足 $r\ge l$、$r\equiv l\pmod2$ 且 $P_r=P_{l-2}$ 的位置。倒序遍历 $l$，分别为两种奇偶维护“某个前缀值最近出现的位置”，即可用哈希表期望 $O(1)$ 查询。先插入 $P_l$ 再查询，才能包含长度为 1、值为 0 的区间。

**贪心：每次选结束位置最早的候选。** 令 `end[l]` 表示左端点不小于 $l$ 的所有必胜区间里，最小的右端点。它等于“恰从 $l$ 开始的最早右端点”和 `end[l+1]` 的较小值。选择它后，下一次从 `end[l]+1` 开始。

交换论证：任意最优方案的第一个区间，都可以替换成最早结束区间；替换后不会挤占后续区间，也不会减少数量。递归应用即可得到贪心最优。

**多次查询用倍增跳贪心。** `jump[0][l]=end[l]+1`，表示选一次后下一次开始的位置；`jump[t][l]` 表示选 $2^t$ 次后的位置。若 `jump[t][l]<=R+1`，这 $2^t$ 个区间都完整位于查询范围内，可以一次取走。按 $t$ 从大到小跳，累计数量。

**正确性。** 隔位前缀和奇偶限制准确找出所有必要的最早候选；后缀最小值允许跳过前面的非必胜部分。交换论证保证贪心达到最优，倍增只是重复同一贪心转移，因此查询答案正确。

**复杂度。** 哈希预处理期望 $O(n)$，倍增预处理 $O(n\log n)$，每问 $O(\log n)$；空间 $O(n\log n)$。哈希表在建立倍增表前释放，以减少峰值内存。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Hash {
    size_t operator()(uint64_t x) const {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<uint32_t> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        uint32_t x; cin >> x;
        prefix[i] = x ^ (i >= 2 ? prefix[i - 2] : 0);
    }
    vector<int> end(n + 3, n + 1);
    {
        unordered_map<uint32_t, int, Hash> nearest[2];
        nearest[0].reserve(n / 2 + 1); nearest[1].reserve(n / 2 + 1);
        for (int i = n; i >= 1; --i) {
            auto& table = nearest[i & 1];
            table[prefix[i]] = i;
            uint32_t target = i >= 2 ? prefix[i - 2] : 0;
            auto it = table.find(target);
            if (it != table.end()) end[i] = it->second;
            end[i] = min(end[i], end[i + 1]);
        }
    }
    int levels = 1;
    while ((1 << levels) <= n) ++levels;
    vector<vector<int>> jump(levels, vector<int>(n + 3, n + 2));
    for (int i = 1; i <= n; ++i) jump[0][i] = end[i] + 1;
    for (int b = 1; b < levels; ++b)
        for (int i = 1; i <= n; ++i) jump[b][i] = jump[b - 1][jump[b - 1][i]];
    while (q--) {
        int l, r, answer = 0; cin >> l >> r;
        for (int b = levels - 1; b >= 0; --b)
            if (jump[b][l] <= r + 1) { answer += 1 << b; l = jump[b][l]; }
        cout << answer << '\n';
    }
}
```

<a id="problem-e"></a>

## E. 绝世好串

标签：`树` · `字典序` · `贪心` · `候选根淘汰` · `并查集` · `启发式合并` · `倍增`

状态：**已实现（原题完整规模）**。C++17 编译通过；保存样例通过；2042 组独立 DP 对拍通过；7 组十万点构造运行通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

树的点 $i$ 初始保存序列 `[i]`。一次聚拢选择中心 $u$，把 $u$ 和所有邻点上的非空序列作为完整块，任选块的顺序拼接，放在 $u$，其余参与点清空。块内部不能重排。第一次聚拢任意，之后每次必须接触至少一个长度不小于 2 的块。最终把全部整数聚成一个序列，求字典序最小的结果。输入 $n$ 和 $n-1$ 条边，完整规模 $n\le10^5$。

题面：[公开存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202605E/)。完整算法参考 **zlxFTH** 的[原题非官方题解](https://www.zhihu.com/question/2043989350854156307/answer/2044499207764105133)。下文按学习顺序重述其算法，并用迭代遍历、倍增、延迟删除堆和并查集重新实现。Bonus 部分参考 **CYMario** 的[探索报告](https://zhuanlan.zhihu.com/p/2083646963501815540)，它研究的是取消后续聚拢限制的另一个版本。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202605E)。

### 题解

**先理解唯一长块。** 第一次操作后只有一个长块；后续操作必须碰到它，所以别处不能独立产生第二个长块。其余非空点仍是单字符。长块的位置可以沿树移动，收集新字符；没有新字符的移动也合法。

设长块是 $W$，首元素为 $h$。新吸收的单字符中，小于 $h$ 的升序放在前面，大于 $h$ 的升序放在后面。因为各块首元素不同，这正是这些块的最小字典序排列。一次最优合并因此具有 $W\to LWR$ 的形式。

这里的局部贪心只决定**已经选定中心之后怎样拼接**，还没有解决应该先访问哪一条分支。后访问的分支可能把更小字符插到最前面，直接选择当前边界最小点会出错。

**小规模精确解仍保留。** 原来的 `dp[mask][u]` 保存“已收集集合为 mask、长块位于 u 时的最小序列”。同一状态下，更大的内部排列在后续整块拼接中不会反超，故可以删去。转移枚举 u 及其邻点作为新中心，并处理集合不变的移动闭包。这份算法适用 $n\le10$，现在放在 [tests/oracles/202605E.cpp](../tests/oracles/202605E.cpp)，作为下方完整算法的独立对拍基准。

**从固定根到共同前缀。** 固定第一次中心 $r$ 后，可以把字符第一次被收集的方向看成朝向 $r$ 的方向。之后各次加入的左段、右段使答案呈现

$$L_k\cdots L_1 B_r R_1\cdots R_k,$$

其中 $B_r$ 是第一次中心闭邻域的升序排列。枚举每个根分别求解会重复大量工作；完整算法逐个确定答案前缀，并同步缩小仍可能最优的根集合。

实现中未定向点组成连通候选区域 $A$；`toward[u] == 0` 表示 u 还在 A 中，否则指向从 u 走向 A 的下一点。把某分支定向到其余区域，就淘汰该分支中的根。每个点只会被定向一次。选择根的过程中仍可暂时保留冗余的叶子候选，它们会在分支处理时一起淘汰。

**封口计数表达前缀约束。** 一个中心贡献的左段已经进入答案、剩余右段需要留到后面时，称它已封口。定义

$$cnt[u]=\min\bigl(2,\ u\text{ 到 }A\text{ 的闭路径上的封口点数}\bigr),\qquad cnt[0]=0.$$

路径包括 u 和第一个进入 A 的点。只需区分 0、1、至少 2：跨过过多已封口中心会破坏已经确定的前缀。`seal` 增加这项约束，`add_seals` 沿已定向的反向枝条传播；达到 2 后无需继续重复增加。全程用显式栈，十万点长链也不依赖递归栈。

设刚输出的字符为 x，向上扫描候选 y。令 u 为 x 到 y 的第一步，v 为第二步（相邻时 v=0），令 $far=[d(x,y)\ge3]$。原题解给出的前缀可行性判据是：

1. $cnt[toward[y]]+far\le1$；
2. 如果 x 仍在 A 且距离至少 2，将要定向的边必须仍在候选区域内：距离 2 时要求 u 在 A，距离至少 3 时要求 v 在 A。

第一个条件检查新字符与已封口段是否冲突；第二个条件保证还能留下一个与当前前缀兼容的根。代码中的 `step` 用倍增求路径上的第一步，不需要实际走完整条路径。

找到最小可行 y 后，若 x 在 A：距离 1 时，把 x 除 y 方向外的候选分支全部指向 x；距离 2 时定向 $x\to u$；距离至少 3 时定向 $u\to v$。若 x 已在 A 外，只有距离至少 3 时需要后一种定向。整侧定向时把已有封口约束同时传下去。

**不能漏掉“现在就以某点为根”的选择。** 继续延长左侧前缀之前，当前前缀可能已经恰好走到某个初始中心块 $B_r$ 的末尾。此时需要比较：固定这个停止根后，下一个字符 z 是否比扫描得到的 y 更小。只有 $z<y$ 时立即选停止根；相等时继续延长，仍不劣。实现中的 `stopping_root` 记录这一额外候选；候选区域仅剩两个点时还需检查当前点。遗漏这个分支是直接按可行 y 贪心的常见错误。

**怎样得到固定根的下一字符。** `next_for_root` 共享已输出字符和历史事件，比较以下三种来源，无需为每个候选根重新建立完整模拟。

| 来源 | 保存的信息 | 下一步 |
|---|---|---|
| 当前中心 | 自身与邻点中未输出字符的小根堆 | 有字符时取最小者 |
| 黑色连通块边界 | 闭邻域已经输出完的中心缩成并查集；边界 a–b 的键为 b 除 a 外的最小邻点 | 在当前块的最小邻域编号之上取最小边界键 |
| 延迟的右段 | 封口时，进入字符恰为中心最小邻点才记录一个事件 | 查询当前阈值以下最近的事件，并检查它仍属于该块的有效边界 |

黑块的阈值是 $\min(C\cup N(C))$。边界候选表示下一段能取得的最小字符；红事件恢复先前暂缓的右段。比较二者后进入相应中心继续。右段中心若已经空了，必须先将它并入黑块、再找出口；不能把“暂时空”直接当成“这条来源不存在”。这是实现中的 `delayed_value = 0` 所表达的优先收缩动作，并不是输出字符 0。

各点闭邻域堆使用全局 `emitted` 标记延迟删除，总共只有 $3n-2$ 个初始堆元素。黑块按大小合并边界集合；黑块最小编号独立保存，避免在同一集合里混用负数标记和真实编号。所有树上遍历、定向传播和并查集查找都使用迭代实现。

**正确性说明。** 单长块不变量覆盖原题全部合法操作，按块首元素排序保证每次合并的局部最优。固定根模拟中的当前闭邻域、可进入边界和延迟右段，覆盖该根尚未输出部分的三种来源；黑块收缩只跳过已经输出的部分，保留全部有效出口。筛根阶段用上述可行性判据保留能产生当前前缀的连通候选区域，并额外比较可能停在中央块末尾的根；只有在首个不同字符更大时才淘汰根。因此保留前缀始终与某个全局最优解兼容。选定根后继续同一个固定根模拟，便得到完整最优序列。这一结构性算法来自引用的非官方题解；本工程还以穷举和独立 DP 检验了其实现。

**复杂度。** 每个点至多定向一次，截断计数至多增加两次。堆元素总数线性，倍增预处理和路径首步查询共 $O(n\log n)$；边界集合的小并大给出保守 $O(n\log^2 n)$ 总时间。倍增表占 $O(n\log n)$，其他结构占 $O(n)$。适用于原题 $n\le10^5$。

**原题与 Bonus 的区别。** Bonus 允许在长块之外独立聚拢，因此可能同时存在多个长块，前面的状态压缩与根筛选不再适用。例如这棵树：

```text
6
1 2
1 5
1 6
2 4
3 6
```

原题的最优结果为 `1 2 4 5 6 3`，已由小规模 DP 和完整算法共同核对。Bonus 可以依次选择中心 `2, 4, 1, 6, 1, 2` 得到 `1 2 4 3 5 6`：先把 `[1,2,4]` 暂存在 4，再单独形成 `[3,5,6]`，最后连接。第三步没有接触长块，所以这条操作序列在原题中不合法。

CYMario 的文章针对 Bonus 分析了多块的位置、内部顺序和联合搬运状态，并报告了判定版本属于 NP 的论证；文中没有给出一般树上的多项式算法，也未完成 NP-hard 归约。这是该报告的研究范围，不能据此断言原题没有解，或者 Bonus 已被证明 NP 完全。备考时可把 Bonus 作为拓展阅读，原题使用本节算法。

**验证范围。** 本版本通过保存样例、n≤6 的全部 1,442 棵有标号树以及 n=7…10 的 600 棵随机树，与保留的小规模 DP 共对拍 2,042 组；另运行 7 组十万点构造。完整排列检查与压力运行不等于大规模最优性证明；详细结果和复现入口见 [gather-report.json](../tests/gather-report.json)、[gather-stress-report.json](../tests/gather-stress-report.json)。尚未提交正式评测。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
// Candidate-root algorithm described by zlxFTH:
// https://www.zhihu.com/question/2043989350854156307/answer/2044499207764105133
// Reimplemented with iterative traversals, binary lifting and lazy local heaps.
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

class GatherSolver {
    using MinHeap = priority_queue<int, vector<int>, greater<int>>;
    const int inf;
    int n, levels, candidates, fixed_root = 0, cursor = 0;
    vector<vector<int>> graph, up;
    vector<int> depth, toward, sealed_count;
    vector<bool> emitted, black;
    vector<MinHeap> local;
    vector<int> leader, component_size, component_min;
    vector<set<int>> boundary;
    set<int> red_events;
    vector<int> answer;

    int step(int from, int destination) const {
        // First vertex on the path from 'from' to 'destination'.
        if (depth[destination] > depth[from]) {
            int v = destination;
            int jump = depth[destination] - depth[from] - 1;
            for (int bit = 0; jump; ++bit, jump >>= 1)
                if (jump & 1)
                    v = up[bit][v];
            if (up[0][v] == from)
                return v;
        }
        return up[0][from];
    }

    int minimum_other_neighbor(int vertex, int excluded) const {
        for (int i = 0; i < min(2, int(graph[vertex].size())); ++i)
            if (graph[vertex][i] != excluded)
                return graph[vertex][i];
        return inf;
    }

    int remaining_min(int vertex) {
        auto &heap = local[vertex];
        while (!heap.empty() && emitted[heap.top()])
            heap.pop();
        return heap.empty() ? inf : heap.top();
    }

    void output(int vertex) {
        assert(vertex >= 1 && vertex <= n && !emitted[vertex]);
        emitted[vertex] = true;
        answer.push_back(vertex);
    }

    int find_component(int vertex) {
        int root = vertex;
        while (leader[root] != root)
            root = leader[root];
        while (vertex != root) {
            int next = leader[vertex];
            leader[vertex] = root;
            vertex = next;
        }
        return root;
    }

    int join_components(int a, int b) {
        a = find_component(a);
        b = find_component(b);
        if (a == b)
            return a;
        if (component_size[a] < component_size[b])
            swap(a, b);
        leader[b] = a;
        component_size[a] += component_size[b];
        component_min[a] = min(component_min[a], component_min[b]);
        boundary[a].merge(boundary[b]);
        boundary[b].clear();
        return a;
    }

    int activate_black(int vertex) {
        if (black[vertex])
            return find_component(vertex);
        black[vertex] = true;
        component_min[vertex] = min(vertex, graph[vertex].front());
        boundary[vertex].insert(inf);
        int root = vertex;
        for (int adjacent : graph[vertex]) {
            if (!black[adjacent]) {
                boundary[find_component(root)].insert(minimum_other_neighbor(adjacent, vertex));
            } else {
                int other = find_component(adjacent);
                boundary[other].erase(minimum_other_neighbor(vertex, adjacent));
                boundary[other].insert(inf);
                root = join_components(root, other);
            }
        }
        return find_component(root);
    }

    void add_seals(int start, int increment) {
        if (increment == 0)
            return;
        vector<int> stack{start};
        while (!stack.empty()) {
            int vertex = stack.back();
            stack.pop_back();
            if (sealed_count[vertex] >= 2)
                continue;
            sealed_count[vertex] = min(2, sealed_count[vertex] + increment);
            for (int child : graph[vertex])
                if (toward[child] == vertex)
                    stack.push_back(child);
        }
    }

    void seal(int vertex, int entry) {
        if (sealed_count[vertex] > sealed_count[toward[vertex]])
            return;
        add_seals(vertex, 1);
        if (entry == graph[vertex].front())
            red_events.insert(entry);
    }

    void orient_branch(int first, int parent) {
        vector<pair<int, int>> stack{{first, parent}};
        while (!stack.empty()) {
            auto [vertex, next] = stack.back();
            stack.pop_back();
            assert(toward[vertex] == 0);
            toward[vertex] = next;
            --candidates;
            int inherited = sealed_count[next];
            sealed_count[vertex] = min(2, sealed_count[vertex] + inherited);
            for (int adjacent : graph[vertex]) {
                if (toward[adjacent] == vertex)
                    add_seals(adjacent, inherited);
                else if (adjacent != next && toward[adjacent] == 0)
                    stack.emplace_back(adjacent, vertex);
            }
        }
    }

    int next_for_root(int root = 0) {
        if (root != 0)
            fixed_root = cursor = root;
        while (true) {
            int direct = remaining_min(cursor);
            if (direct != inf)
                return direct;
            int group = activate_black(cursor);
            int head = component_min[group];
            int border = *boundary[group].upper_bound(head);
            auto event_it = red_events.lower_bound(head);
            int delayed_vertex = 0, delayed_value = inf;
            if (event_it != red_events.begin()) {
                int event = *prev(event_it);
                if (boundary[group].count(event)) {
                    delayed_vertex = toward[event];
                    delayed_value = remaining_min(delayed_vertex);
                    // Empty delayed region must be contracted before comparing exits.
                    if (delayed_value == inf)
                        delayed_value = 0;
                }
            }
            if (border < delayed_value)
                cursor = step(border, fixed_root);
            else {
                assert(delayed_vertex != 0 && delayed_value != inf);
                cursor = delayed_vertex;
            }
        }
    }

    int select_root() {
        int current = 1, stopping_root = 0;
        while (candidates > 1) {
            int parent = toward[current];
            output(current);
            if (parent)
                seal(parent, current);
            int next = current + 1, first = 0, second = 0;
            bool distant = false;
            for (; next <= n; ++next) {
                first = step(current, next);
                second = first == next ? 0 : step(first, next);
                distant = second != 0 && second != next;
                if (sealed_count[toward[next]] + int(distant) > 1)
                    continue;
                if (!parent && second && toward[distant ? second : first])
                    continue;
                break;
            }
            if (next > n)
                return parent ? parent : current;
            if (parent) {
                if (distant)
                    orient_branch(first, second);
                current = next;
                continue;
            }
            // The common prefix can also end at one initial central block.
            int stop = 0;
            if (candidates == 2 && second)
                stop = current;
            else if (stopping_root && !toward[stopping_root])
                stop = stopping_root;
            if (stop && next_for_root(stop) < next)
                return stop;
            if (stopping_root && first != stopping_root)
                seal(current, stopping_root);
            if (!second) {
                for (int neighbor : graph[current])
                    if (neighbor != next && !toward[neighbor])
                        orient_branch(neighbor, current);
                stopping_root = current;
            } else {
                if (distant && first != stopping_root)
                    stopping_root = 0;
                orient_branch(distant ? first : current, distant ? second : first);
                seal(first, current);
            }
            current = next;
        }
        return toward[current] ? toward[current] : current;
    }

  public:
    explicit GatherSolver(vector<vector<int>> adjacency)
        : inf(int(adjacency.size()) + 1), n(int(adjacency.size()) - 1), candidates(n),
          graph(std::move(adjacency)), depth(n + 1), toward(n + 1), sealed_count(n + 1),
          emitted(n + 1), black(n + 1), local(n + 1), leader(n + 1), component_size(n + 1, 1),
          component_min(n + 1), boundary(n + 1) {
        levels = 1;
        while ((1LL << levels) <= n)
            ++levels;
        up.assign(levels, vector<int>(n + 1));
        iota(leader.begin(), leader.end(), 0);
        for (int vertex = 1; vertex <= n; ++vertex) {
            sort(graph[vertex].begin(), graph[vertex].end());
            local[vertex].push(vertex);
            for (int neighbor : graph[vertex])
                local[vertex].push(neighbor);
        }
        vector<int> order{1};
        for (size_t i = 0; i < order.size(); ++i) {
            int vertex = order[i];
            for (int neighbor : graph[vertex]) {
                if (neighbor == up[0][vertex])
                    continue;
                up[0][neighbor] = vertex;
                depth[neighbor] = depth[vertex] + 1;
                order.push_back(neighbor);
            }
        }
        for (int bit = 1; bit < levels; ++bit)
            for (int vertex = 1; vertex <= n; ++vertex)
                up[bit][vertex] = up[bit - 1][up[bit - 1][vertex]];
    }

    vector<int> solve() {
        if (n == 1)
            return {1};
        int root = select_root();
        while (int(answer.size()) < n) {
            output(next_for_root(root));
            root = 0;
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    auto answer = GatherSolver(std::move(graph)).solve();
    for (int i = 0; i < n; ++i)
        cout << answer[i] << (i + 1 == n ? '\n' : ' ');
}
```
