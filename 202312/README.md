---
title: "CSP 202312 五题题解"
contest: "202312"
contest_month: "2023-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "暴力枚举", "多维比较", "质因数分解", "试除法", "树", "DFS序", "决策树", "前缀和", "根号分块", "栈", "矩阵乘法", "状态压缩", "折半搜索", "位集", "图论"]
status: "published"
problems: [{"id": "A", "title": "仓库规划", "tags": ["暴力枚举", "多维比较"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c0a67df0b81749bd8f"}}, {"id": "B", "title": "因子化简", "tags": ["质因数分解", "试除法"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c2a67df0b81749bd93"}}, {"id": "C", "title": "树上搜索", "tags": ["树", "DFS序", "决策树", "前缀和"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c3a67df0b81749bdb0"}}, {"id": "D", "title": "宝藏", "tags": ["根号分块", "栈", "矩阵乘法"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；110 组独立随机对拍通过；数梦 OJ 85 分 Time Exceeded（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312D/"}], "oj": {"status": "failed", "score": 85, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6adce8c5a67df0b81749bdca"}}, {"id": "E", "title": "彩色路径", "tags": ["状态压缩", "折半搜索", "位集", "图论"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "数梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c7a67df0b81749bdda"}}]
---

# CSP 202312 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 仓库规划

标签：`暴力枚举` · `多维比较`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

仓库j若每一维坐标都严格大于仓库i，便可作为i的上级。多个候选取最小编号，没有则输出0。n≤1000、维度≤10。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312A/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312A)。

### 题解

对每个i按编号从小到大枚举j，检查全部维度，任一维不严格大于就失败；第一个全部通过的j就是答案并停止。

逐维合取正好对应上级定义，编号升序保证首次成功者最小。不能仅比较向量和、字典序或允许某维相等。时间 $O(n^2m)$，空间 $O(nm)$，在给定范围内足够。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    for (int i = 0; i < n; i++) {
        int answer = 0;
        for (int j = 0; j < n; j++) {
            bool larger = true;
            for (int k = 0; k < m; k++)
                if (a[j][k] <= a[i][k]) {
                    larger = false;
                    break;
                }
            if (larger) {
                answer = j + 1;
                break;
            }
        }
        cout << answer << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 因子化简

标签：`质因数分解` · `试除法`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

分解正整数 n 的质因子，指数小于阈值 k 的整个质数幂删去，其他保留；无项剩余输出1。n≤$10^{10}$，查询数≤10。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312B/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312B)。

### 题解

从2起试除当前剩余数，循环条件为 p≤n/p，避免 p*p 溢出。每遇到因子 p 就连续除尽，统计指数和完整幂；指数达到 k 才乘进答案。

试除结束后若剩余数>1，它只能是一个指数为1的质数（否则还存在不超过平方根的因子）；原题 k>1，因此通常不保留，代码也兼容 k=1。已经取出的因子不会再次出现，最终恰好保留题目要求的各幂。每次时间 $O(\sqrt n)$，额外空间 $O(1)$，n 与答案用64位。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        long long n, answer = 1;
        int k;
        cin >> n >> k;
        for (long long p = 2; p <= n / p; p++) {
            int count = 0;
            long long power = 1;
            while (n % p == 0) {
                n /= p;
                power *= p;
                ++count;
            }
            if (count >= k)
                answer *= power;
        }
        if (n > 1 && k <= 1)
            answer *= n;
        cout << answer << '\n';
    }
}
```

<a id="problem-c"></a>

## C. 树上搜索

标签：`树` · `DFS序` · `决策树` · `前缀和`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

类别形成根为 1 的带正权树。每次在剩余类别中选一个点，使其子树内剩余权重与子树外权重之差绝对值最小，同分选编号小者；根据目标是否在该子树，保留对应一侧，直到只剩一个类别。给定 m 个目标，输出各自提问序列。$n\le2000,m\le100$，父节点编号不一定小于子节点。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312C/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312C)。

### 题解

一次提问由当前候选集合决定，与目标是谁无关。因此先构建所有目标共享的二叉决策树：状态保存候选集合，选出最佳问题后分成“是”和“否”两组，递归构建；单元素集合为叶子。

对原树预处理 DFS 进入和退出时间，任意子树对应连续区间。对某个决策状态，将候选点权放到 DFS 序上、其余填零，构造前缀和，就能 O(1) 得到每个候选点子树内的剩余权重。扫描候选点选择最小差值，编号破同分，然后按 DFS 区间分组。

权重为正且候选至少两个时，存在一个真子集的问题比保留全体更平衡，所以两个分支都非空，过程必定终止。决策节点至多 2n-1 个，每个状态 O(n) 构建前缀与筛选，总构建时间 $O(n^2)$。查询只沿决策树输出路径，时间等于输出长度；本实现递归保留候选数组，最坏空间 $O(n^2)$，在 n≤2000 下可用。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct Decision {
    int question = 0, yes = -1, no = -1;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> weight(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> weight[i];
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        children[p].push_back(i);
    }
    vector<int> tin(n + 1), tout(n + 1);
    int timer = 0;
    function<void(int)> dfs = [&](int u) {
        tin[u] = timer++;
        for (int v : children[u])
            dfs(v);
        tout[u] = timer;
    };
    dfs(1);
    vector<Decision> decisions;
    decisions.reserve(2 * n);
    function<int(const vector<int> &)> build = [&](const vector<int> &candidates) {
        int node = decisions.size();
        decisions.push_back({});
        if (candidates.size() == 1)
            return node;
        vector<long long> prefix(n + 1);
        for (int u : candidates)
            prefix[tin[u] + 1] = weight[u];
        for (int i = 1; i <= n; ++i)
            prefix[i] += prefix[i - 1];
        long long best = -1;
        int chosen = 0;
        for (int u : candidates) {
            long long difference = llabs(prefix[n] - 2 * (prefix[tout[u]] - prefix[tin[u]]));
            if (best == -1 || difference < best || (difference == best && u < chosen)) {
                best = difference;
                chosen = u;
            }
        }
        vector<int> yes, no;
        for (int u : candidates)
            (tin[chosen] <= tin[u] && tin[u] < tout[chosen] ? yes : no).push_back(u);
        decisions[node].question = chosen;
        int y = build(yes), z = build(no);
        decisions[node].yes = y;
        decisions[node].no = z;
        return node;
    };
    vector<int> all(n);
    iota(all.begin(), all.end(), 1);
    int root = build(all);
    while (m--) {
        int target;
        cin >> target;
        int u = root;
        bool first = true;
        while (decisions[u].question) {
            int question = decisions[u].question;
            if (!first)
                cout << ' ';
            first = false;
            cout << question;
            u = tin[question] <= tin[target] && tin[target] < tout[question] ? decisions[u].yes
                                                                             : decisions[u].no;
        }
        cout << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 宝藏

标签：`根号分块` · `栈` · `矩阵乘法`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；110 组独立随机对拍通过；数梦 OJ 85 分 Time Exceeded（复刻评测）。

### 题意

维护 $n$ 条矩阵双端队列指令：1 表示头插一个 $2\times2$ 矩阵，2 表示尾插，3 表示删除最近插入的矩阵（空队列忽略）。支持修改某一条指令，以及从空队列执行区间 $[l,r]$ 的指令后，输出队列内矩阵从头到尾的乘积，元素模 $998244353$。空队列乘积为单位矩阵。$n,m\le10^5$。修改格式为 `1 i 新指令`，查询为 `2 l r`。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312D/)。

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312D)。

### 题解

虽然最终容器是双端队列，但删除规则按插入时间执行，因此可以先用栈决定哪些插入存活，再处理乘法顺序。

**每块指令压缩成“先删、后插”。** 从空栈扫描一块，插入压栈，删除弹栈；栈空时的删除累计为 $d$。最终保留下来的插入序列记作 $S$。这块指令作用在任意旧栈上，等价于先删除最多 $d$ 个旧元素，再整体压入 $S$。因为块内已经配对的插入与删除不会影响旧栈，未配对的删除只会作用在块外。

对 $S$ 的每个前缀，分别预处理头插矩阵的反序乘积 `front`、尾插矩阵的顺序乘积 `back`。例如时间顺序为“头插 A、尾插 B、头插 C”，最终队列为 C、A、B，乘积为 $(CA)B$。不能交换矩阵相乘顺序，也不能假设矩阵可逆。

查询时，左右边界各扫描不足一块的指令，中间完整块直接使用摘要。临时栈保存“哪个块、保留多少个存活插入”；删除时整块弹出或截短最上面一块。所有删除结束后，按块的时间顺序合并：新头积在左边相乘，新尾积在右边相乘，最终输出 `front * back`。部分保留的块直接查它的前缀积。

摘要变换与原指令对任意输入栈等价，因此逐块复合后的存活序列正确；两种矩阵积又严格对应最终队列顺序。块长 $B\approx\sqrt n$，预处理 $O(n)$，单次修改 $O(B)$，查询 $O(B+n/B)$，空间 $O(n)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
constexpr long long MOD = 998244353;
struct Matrix {
    array<long long, 4> a{1, 0, 0, 1};
};
Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix z;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            z.a[i * 2 + j] = (x.a[i * 2] * y.a[j] + x.a[i * 2 + 1] * y.a[2 + j]) % MOD;
    return z;
}
struct Command {
    int type;
    Matrix value;
};
struct Block {
    int removed = 0;
    vector<Matrix> front, back;
};
vector<Command> commands;
Block summarize(int l, int r) {
    Block result;
    vector<int> live;
    for (int i = l; i <= r; ++i) {
        if (commands[i].type != 3)
            live.push_back(i);
        else if (live.empty())
            ++result.removed;
        else
            live.pop_back();
    }
    result.front.push_back({});
    result.back.push_back({});
    for (int i : live) {
        auto &c = commands[i];
        result.front.push_back(c.type == 1 ? c.value * result.front.back() : result.front.back());
        result.back.push_back(c.type == 2 ? result.back.back() * c.value : result.back.back());
    }
    return result;
}
void read(Command &c) {
    cin >> c.type;
    if (c.type != 3)
        for (auto &x : c.value.a)
            cin >> x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    commands.resize(n);
    for (auto &c : commands)
        read(c);
    int width = max(1, int(sqrt(n))), count = (n + width - 1) / width;
    vector<Block> blocks(count);
    auto rebuild = [&](int b) {
        blocks[b] = summarize(b * width, min(n - 1, (b + 1) * width - 1));
    };
    for (int b = 0; b < count; ++b)
        rebuild(b);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i;
            cin >> i;
            --i;
            read(commands[i]);
            rebuild(i / width);
            continue;
        }
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        vector<pair<const Block *, int>> stack;
        auto append = [&](const Block &b) {
            int remove = b.removed;
            while (remove && !stack.empty()) {
                int used = min(remove, stack.back().second);
                remove -= used;
                stack.back().second -= used;
                if (stack.back().second == 0)
                    stack.pop_back();
            }
            int size = int(b.front.size()) - 1;
            if (size)
                stack.push_back({&b, size});
        };
        Block left, right;
        if (l / width == r / width) {
            left = summarize(l, r);
            append(left);
        } else {
            left = summarize(l, (l / width + 1) * width - 1);
            right = summarize(r / width * width, r);
            append(left);
            for (int b = l / width + 1; b < r / width; ++b)
                append(blocks[b]);
            append(right);
        }
        Matrix front, back;
        for (auto [block, size] : stack) {
            front = block->front[size] * front;
            back = back * block->back[size];
        }
        Matrix answer = front * back;
        for (int i = 0; i < 4; ++i)
            cout << answer.a[i] << (i == 3 ? '\n' : ' ');
    }
}
```

<a id="problem-e"></a>

## E. 彩色路径

标签：`状态压缩` · `折半搜索` · `位集` · `图论`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；数梦 OJ 100 分 Accepted（复刻评测）。

### 题意

有向图的点带颜色，求从 0 到 $n-1$ 的最长路径，要求路径各点颜色不同，点数不超过 $l$。$n\le100,m\le5000,l\le9,k\le30$，边权为正。输入第一行 `n m l k`，第二行颜色，随后三行分别给全部边的起点、终点、权值。保证存在合法路线，且起终点颜色不在其他点上出现。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312E/)

原站练习：[数梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312E)。

### 题解

**最多八条边，分成两半。** 任意合法路径可以选择一个中间点，使两半各不超过四条边。在正图从 0 出发、反图从终点出发，各做四层 DP。状态 $(d,u,mask)$ 记录恰走 $d$ 条边到 $u$、颜色集合为 $mask$ 的最大权值；转移时拒绝已经出现的颜色。相同状态只保留最大值，因为未来可行性只由当前位置和颜色集合决定。

**合并要去掉重复的中间颜色。** 对一个前半状态，后半最多有 $\min(4,l-1-d)$ 条边。两半颜色交集只能是中间点颜色；从前半掩码中删掉该位后，就成为与后半掩码完全不相交的条件。颜色不同也保证没有重复顶点。

**位集寻找最大的可用后半段。** 对固定中间点和长度上限，把后半状态按权值降序排列。对每种颜色建立位集，表示哪些候选包含此颜色。将前半出现的颜色对应位集按或合并，得到全部禁用候选；取反后第一个置位就是权值最大的可用候选。用 64 位整数逐块扫描，不需要枚举两半的所有组合。

**正确性。** 每条合法路径至少被一种中间点拆法覆盖；DP 不丢失任何可能成为最优的半路径。颜色交集和总长度条件保证合并后合法。候选按值排序，第一条可用者就是该前半段的最优搭配。

**复杂度。** 以实际 DP 状态数 $S$、转移总数 $E_s$、每次合并候选数 $R$ 表示，时间为 $O(E_s+S\log S+S\cdot4\lceil R/64\rceil)$，空间为状态和颜色位集大小。每个半路径固定包含一个终端颜色，四边状态的自由颜色只有三种，数量受 $\binom{k-2}{3}$ 约束。注意位集扫描的是候选数 $R$，不能误写成 $k/64$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using Mask = uint32_t;
using Word = uint64_t;
using Layer = vector<unordered_map<Mask, int>>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, limit, k;
    cin >> n >> m >> limit >> k;
    vector<int> color(n), from(m), to(m), weight(m);
    for (int &x : color)
        cin >> x;
    for (int &x : from)
        cin >> x;
    for (int &x : to)
        cin >> x;
    for (int &x : weight)
        cin >> x;
    vector<vector<pair<int, int>>> g(n), rg(n);
    for (int i = 0; i < m; ++i) {
        g[from[i]].push_back({to[i], weight[i]});
        rg[to[i]].push_back({from[i], weight[i]});
    }
    auto compute = [&](int source, const vector<vector<pair<int, int>>> &edges) {
        vector<Layer> dp(5, Layer(n));
        dp[0][source][Mask(1) << color[source]] = 0;
        for (int d = 0; d < 4 && d + 1 < limit; ++d)
            for (int u = 0; u < n; ++u)
                for (auto [mask, value] : dp[d][u])
                    for (auto [v, w] : edges[u])
                        if (!(mask >> color[v] & 1)) {
                            auto &best = dp[d + 1][v][mask | (Mask(1) << color[v])];
                            best = max(best, value + w);
                        }
        return dp;
    };
    auto forward = compute(0, g), backward = compute(n - 1, rg);
    int answer = 0;
    for (int u = 0; u < n; ++u)
        for (int d = 0; d <= 4 && d < limit; ++d) {
            if (forward[d][u].empty())
                continue;
            int cap = min(4, limit - 1 - d);
            vector<pair<int, Mask>> candidates;
            for (int e = 0; e <= cap; ++e)
                for (auto [mask, value] : backward[e][u])
                    candidates.push_back({value, mask});
            sort(candidates.rbegin(), candidates.rend());
            int words = (int(candidates.size()) + 63) / 64;
            if (!words)
                continue;
            vector<vector<Word>> bad(k, vector<Word>(words));
            for (int i = 0; i < int(candidates.size()); ++i) {
                Mask mask = candidates[i].second;
                while (mask) {
                    int c = __builtin_ctz(mask);
                    mask &= mask - 1;
                    bad[c][i / 64] |= Word(1) << (i % 64);
                }
            }
            for (auto [key, value] : forward[d][u]) {
                Mask mask = key ^ (Mask(1) << color[u]);
                vector<int> colors;
                while (mask) {
                    colors.push_back(__builtin_ctz(mask));
                    mask &= mask - 1;
                }
                for (int j = 0; j < words; ++j) {
                    Word excluded = 0;
                    for (int c : colors)
                        excluded |= bad[c][j];
                    Word valid = ~excluded;
                    if (valid) {
                        int index = j * 64 + __builtin_ctzll(valid);
                        if (index < int(candidates.size()))
                            answer = max(answer, value + candidates[index].first);
                        break;
                    }
                }
            }
        }
    cout << answer << '\n';
}
```
