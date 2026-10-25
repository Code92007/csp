---
title: "CSP 201912 五题题解"
contest: "201912"
contest_month: "2019-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "数位判断", "循环模拟", "集合", "坐标枚举", "递归下降", "哈希计数", "化学式", "图论", "BFS", "事件模拟", "有序映射", "线段树", "有限群", "状态压缩", "数论"]
status: "published"
problems: [{"id": "A", "title": "报数", "tags": ["数位判断", "循环模拟"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9d4674ace1cba9a1f711"}}, {"id": "B", "title": "回收站选址", "tags": ["集合", "坐标枚举"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；3 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9dd274ace1cba9a1f78d"}}, {"id": "C", "title": "化学方程式", "tags": ["递归下降", "哈希计数", "化学式"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9e5474ace1cba9a1f7d3"}}, {"id": "D", "title": "区块链", "tags": ["图论", "BFS", "事件模拟", "有序映射"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9ee174ace1cba9a1f812"}}, {"id": "E", "title": "魔数", "tags": ["线段树", "有限群", "状态压缩", "数论"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9fb574ace1cba9a1f846"}}]
---

# CSP 201912 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 报数

标签：`数位判断` · `循环模拟`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9d4674ace1cba9a1f711)（复刻评测）。

### 题意

四人从1起轮流报数，7的倍数或十进制含7的数跳过；累计实际报出n个数后停止，输出每个人跳过次数。跳过仍消耗该人的轮次。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912A)。

### 题解

分别维护当前整数x和已成功报出的数量spoken。若x%7==0或逐位检查含7，给(x-1)%4号人的跳过次数加一；否则spoken加一。每轮x都增加，直到spoken达到n。

轮次由尝试报的整数确定，终止条件由成功次数确定，两者分开才能正确模拟。设最后尝试到X，时间 $O(X\log X)$，额外空间 $O(1)$；题目n≤666。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
bool skip(int x) {
    if (x % 7 == 0)
        return true;
    while (x) {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    int count[4] = {}, spoken = 0;
    for (int x = 1; spoken < n; x++) {
        if (skip(x))
            ++count[(x - 1) % 4];
        else
            ++spoken;
    }
    for (int x : count)
        cout << x << '\n';
}
```

<a id="problem-b"></a>

## B. 回收站选址

标签：`集合` · `坐标枚举`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；3 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9dd274ace1cba9a1f78d)（复刻评测）。

### 题意

n个互异垃圾点中，只有本点及上下左右四邻都存在垃圾才可建回收站，得分为四个对角邻居中有垃圾的数量。输出得分0到4的选址数，n≤1000、坐标可为负。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912B)。

### 题解

把全部坐标放入 set<pair<int,int>>，枚举每个垃圾点。先查四个正邻居，缺一个就跳过；否则查询四个对角点并把相应分数计数加一。

每个候选都必须位于输入垃圾点，枚举不会漏；两组查找分别直接对应资格和得分定义。时间 $O(n\log n)$，空间 $O(n)$。坐标范围很大，应按坐标存集合，不能开覆盖全地图的数组。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <set>
#include <utility>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<pair<int, int>> a;
    while (n--) {
        int x, y;
        cin >> x >> y;
        a.insert({x, y});
    }
    int count[5] = {};
    for (auto [x, y] : a) {
        if (!a.count({x - 1, y}) || !a.count({x + 1, y}) || !a.count({x, y - 1}) ||
            !a.count({x, y + 1}))
            continue;
        int score = 0;
        for (int dx : {-1, 1})
            for (int dy : {-1, 1})
                score += a.count({x + dx, y + dy});
        ++count[score];
    }
    for (int x : count)
        cout << x << '\n';
}
```

<a id="problem-c"></a>

## C. 化学方程式

标签：`递归下降` · `哈希计数` · `化学式`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9e5474ace1cba9a1f7d3)（复刻评测）。

### 题意

判断合法化学方程式左右两侧每种元素的原子总数是否相同。支持系数、元素下标、多层括号及加号；省略系数表示 1。表达式长度不超过 1000，每侧任一元素总数不超过 $10^9$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912C)。

### 题解

按照题目语法分层解析：表达式处理“系数×化学式”并以加号分隔；化学式反复读取“项×下标”；项要么是大写字母及可选小写字母组成的元素，要么是括号中的递归化学式。

每层返回“元素名→数量”的字典。元素产生数量 1，括号产生内部统计结果；读到后缀系数就整体相乘，再并入当前字典。左右表达式分别计算，比较字典即可。不要把 Co 拆成 C、o，也不要把括号后的系数只乘最后一个元素。

递归结构与化学式结构一致，逐层计数保持每个子式的元素总数正确。设元素种类 E、文本长度 L，map 实现保守时间 $O(LE\log E)$，空间 $O(LE)$；本题 E≤702，实际通常远小于此上界。用 64 位累加。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;
using Counts = map<string, long long>;
string s;
size_t p;
long long number() {
    if (p == s.size() || !isdigit(s[p]))
        return 1;
    long long n = 0;
    while (p < s.size() && isdigit(s[p]))
        n = n * 10 + s[p++] - '0';
    return n;
}
void add(Counts &a, const Counts &b, long long factor) {
    for (auto &[element, count] : b)
        a[element] += count * factor;
}
Counts formula() {
    Counts result;
    while (p < s.size() && s[p] != ')' && s[p] != '+' && s[p] != '=') {
        Counts term;
        if (s[p] == '(') {
            ++p;
            term = formula();
            ++p;
        } else {
            string element(1, s[p++]);
            if (p < s.size() && islower(s[p]))
                element += s[p++];
            term[element] = 1;
        }
        long long factor = number();
        add(result, term, factor);
    }
    return result;
}
Counts expression() {
    Counts result;
    while (p < s.size() && s[p] != '=') {
        long long factor = number();
        Counts term = formula();
        add(result, term, factor);
        if (p < s.size() && s[p] == '+')
            ++p;
        else
            break;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        p = 0;
        Counts a = expression();
        ++p;
        Counts b = expression();
        cout << (a == b ? 'Y' : 'N') << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 区块链

标签：`图论` · `BFS` · `事件模拟` · `有序映射`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9ee174ace1cba9a1f812)（复刻评测）。

### 题意

网络节点维护从创世块 0 开始的链。收到更长链就替换，等长时选末块编号更小的链；本地产生块则接在当前链尾。主链更新后发送给邻居，每条边传输耗时 t。同一时刻先接收再产生，查询排在该时刻全部产生操作之后。输入每行 `节点 时刻 新块编号` 表示产生，两个数表示查询；输出链长及从 0 起的编号序列。$n\le500,k\le3\times10^4$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912D)。

### 题解

**把每条新链的传播改写为最短路到达。** 图的每条边延迟相同，先从每个节点 BFS，求两点最少边数。一个新块生成时，其所在完整链可以认为会在“生成时刻 + 最少边数 × t”抵达每个可达节点。

这一改写需要证明：链可能在中途被更好的链压制，为何还能假想它继续传播？若链 A 在某节点输给 B，那么 B 更长，或等长但末块更小。B 从该处继续沿 A 的后续路线传播，抵达时间不晚于假想 A，且比较结果始终更好；若 B 又被压制，继续使用同样的替代论证。故假想传播的 A 永远不会造成一次不该发生的有效更新。反过来，真实的传播不可能早于最短路时间。两种模型在每个节点的最优主链完全一致。

**每个节点只保存未来的有效候选。** 用 map 按到达时间维护未来主链，越晚的候选必须严格更好。插入新候选时，若它不胜过前一个候选就丢弃；否则删去后方被它压制的候选。查询或生成新块之前，把已经到达的候选推进到当前状态。每个历史区块只存父区块、长度、编号；传播传递链尾下标，输出时沿父指针还原。

比较只依赖长度和唯一末块编号，是一致的全序；被提前到达且更好的链支配的候选永远不可能胜出，故删除安全。最坏时间 $O(n(n+m)+nk\log k+P)$，空间 $O(n^2+nk+k)$，其中 P 为实际输出总长度；候选删除可显著减少实际存储。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using i64 = long long;
struct Block {
    int parent, id, length;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    i64 delay;
    int k;
    cin >> delay >> k;
    vector<vector<int>> distance(n, vector<int>(n, -1));
    for (int start = 0; start < n; ++start) {
        vector<int> queue{start};
        distance[start][start] = 0;
        for (size_t head = 0; head < queue.size(); ++head)
            for (int v : graph[queue[head]])
                if (distance[start][v] < 0) {
                    distance[start][v] = distance[start][queue[head]] + 1;
                    queue.push_back(v);
                }
    }
    vector<Block> blocks{{-1, 0, 1}};
    vector<int> current(n);
    vector<map<i64, int>> future(n);
    auto better = [&](int a, int b) {
        return blocks[a].length != blocks[b].length ? blocks[a].length > blocks[b].length
                                                    : blocks[a].id < blocks[b].id;
    };
    auto advance = [&](int u, i64 time) {
        auto end = future[u].upper_bound(time);
        if (end != future[u].begin())
            current[u] = prev(end)->second;
        future[u].erase(future[u].begin(), end);
    };
    auto schedule = [&](int u, i64 time, int chain) {
        auto it = future[u].lower_bound(time);
        int previous = it == future[u].begin() ? current[u] : prev(it)->second;
        if (!better(chain, previous))
            return;
        if (it != future[u].end() && it->first == time && !better(chain, it->second))
            return;
        while (it != future[u].end() && !better(it->second, chain))
            it = future[u].erase(it);
        future[u][time] = chain;
    };
    string line;
    getline(cin, line);
    for (int i = 0; i < k; ++i) {
        getline(cin, line);
        istringstream input(line);
        int u, id;
        i64 time;
        input >> u >> time;
        --u;
        advance(u, time);
        if (input >> id) {
            int index = blocks.size();
            blocks.push_back({current[u], id, blocks[current[u]].length + 1});
            current[u] = index;
            auto &events = future[u];
            auto it = events.begin();
            while (it != events.end() && !better(it->second, index))
                it = events.erase(it);
            for (int v = 0; v < n; ++v)
                if (v != u && distance[u][v] >= 0)
                    schedule(v, time + delay * distance[u][v], index);
        } else {
            vector<int> answer;
            for (int b = current[u]; b != -1; b = blocks[b].parent)
                answer.push_back(blocks[b].id);
            reverse(answer.begin(), answer.end());
            cout << answer.size();
            for (int x : answer)
                cout << ' ' << x;
            cout << '\n';
        }
    }
}
```

<a id="problem-e"></a>

## E. 魔数

标签：`线段树` · `有限群` · `状态压缩` · `数论`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9fb574ace1cba9a1f846)（复刻评测）。

### 题意

初始序列为 $A_i=i$。每次给出区间 $[l,r]$，先输出 $\sum f(A_i)$，其中 $f(x)=(x\bmod P)\bmod2019$，$P=2009731336725594113$；再令区间内所有数乘上题面五个常数中的 $U_{sum\bmod5}$。$n\le10^6,q\le10^5$。只需维护模 $P$ 的值，但不能把两个取模交换。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912E)。

### 题解

**关键在五个常数生成的乘法集合。** 从 1 开始，不断乘任意一个 $U_i$ 并模 $P$，新得到的余数加入队列。对于题面固定的常数，这个闭包只有 32 个元素。代码直接计算闭包并检查大小，不依赖手写猜测的常数表。随后枚举任意两个状态的乘积，预处理 `product[a][b]`。

**一个区间预存 32 种未来答案。** 线段树节点保存

$$sum[s]=\sum_{i\text{在区间内}} ((A_i\cdot g_s\bmod P)\bmod2019).$$

其中 $g_0=1$，所以当前答案是 `sum[0]`。整段乘 $g_t$ 后，新的 `sum[s]` 就是旧的 `sum[product[s][t]]`，一次修改只需重排 32 个统计量。懒标记同样通过乘积表合成。

初始叶子 $i$ 需要计算 $i g_s\bmod P$。按 $i$ 递增时，每个状态的余数可由前一个余数加 $g_s$ 获得，只需一次减法取模，避免在百万个叶子上反复做 128 位除法。只有生成闭包和乘积表时使用 `__uint128_t` 安全乘法。

**正确性。** 任何实际乘数都由五个常数相乘得到，始终属于闭包；32 个统计量因此涵盖所有可能的未来统一修改。乘法结合律保证状态重排与逐点乘法完全相同，线段树求和和懒标记保持该不变量。

**复杂度。** 建树 $O(32n)$，每次询问及随后的修改 $O(32\log n)$，空间 $O(32n)$。本实现把叶子数扩成二的幂，$n=10^6$ 时统计数组约 256 MiB，适用于题面 1024 MiB 内存限制；不能随意搬到 128 MiB 环境。单个区间和最多 $2018n$，在本题范围内仍可用 32 位整数。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using U = uint64_t;
using Wide = __uint128_t;
const U MOD = 2009731336725594113ULL;
const U magic[5] = {314882150829468584ULL, 427197303358170108ULL, 1022292690726729920ULL,
                    1698479428772363217ULL, 2006101093849356424ULL};
int product[32][32];
struct Tree {
    int base;
    vector<array<int, 32>> sum;
    vector<unsigned char> lazy;
    explicit Tree(int n, const vector<U> &group) {
        base = 1;
        while (base < n)
            base *= 2;
        sum.resize(2 * base);
        lazy.resize(2 * base);
        array<U, 32> residue{};
        for (int i = 1; i <= n; ++i)
            for (int s = 0; s < 32; ++s) {
                residue[s] += group[s];
                if (residue[s] >= MOD)
                    residue[s] -= MOD;
                sum[base + i - 1][s] = residue[s] % 2019;
            }
        for (int u = base - 1; u; --u)
            pull(u);
    }
    void pull(int u) {
        for (int s = 0; s < 32; ++s)
            sum[u][s] = sum[2 * u][s] + sum[2 * u + 1][s];
    }
    void apply(int u, int state) {
        array<int, 32> next;
        for (int s = 0; s < 32; ++s)
            next[s] = sum[u][product[s][state]];
        sum[u] = next;
        lazy[u] = product[lazy[u]][state];
    }
    void push(int u) {
        if (lazy[u]) {
            apply(2 * u, lazy[u]);
            apply(2 * u + 1, lazy[u]);
            lazy[u] = 0;
        }
    }
    int query(int u, int l, int r, int a, int b) {
        if (a <= l && r <= b)
            return sum[u][0];
        push(u);
        int mid = (l + r) / 2, ans = 0;
        if (a <= mid)
            ans += query(2 * u, l, mid, a, b);
        if (b > mid)
            ans += query(2 * u + 1, mid + 1, r, a, b);
        return ans;
    }
    void update(int u, int l, int r, int a, int b, int state) {
        if (a <= l && r <= b) {
            apply(u, state);
            return;
        }
        push(u);
        int mid = (l + r) / 2;
        if (a <= mid)
            update(2 * u, l, mid, a, b, state);
        if (b > mid)
            update(2 * u + 1, mid + 1, r, a, b, state);
        pull(u);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<U> group{1};
    map<U, int> id{{1, 0}};
    for (size_t i = 0; i < group.size(); ++i)
        for (U x : magic) {
            U y = Wide(group[i]) * x % MOD;
            if (!id.count(y)) {
                id[y] = group.size();
                group.push_back(y);
            }
        }
    if (group.size() != 32)
        return 1;
    for (int i = 0; i < 32; ++i)
        for (int j = 0; j < 32; ++j)
            product[i][j] = id.at(Wide(group[i]) * group[j] % MOD);
    Tree tree(n, group);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int answer = tree.query(1, 1, tree.base, l, r);
        cout << answer << '\n';
        tree.update(1, 1, tree.base, l, r, id.at(magic[answer % 5]));
    }
}
```
