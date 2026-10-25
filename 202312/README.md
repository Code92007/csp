---
title: "CSP 202312 五题题解"
contest: "202312"
contest_month: "2023-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "暴力枚举", "多维比较", "质因数分解", "试除法", "树", "DFS序", "决策树", "前缀和", "线段树", "栈", "括号序列", "矩阵乘法", "状态压缩", "折半搜索", "位集", "图论"]
status: "published"
problems: [{"id": "A", "title": "仓库规划", "tags": ["暴力枚举", "多维比较"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c0a67df0b81749bd8f"}}, {"id": "B", "title": "因子化简", "tags": ["质因数分解", "试除法"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c2a67df0b81749bd93"}}, {"id": "C", "title": "树上搜索", "tags": ["树", "DFS序", "决策树", "前缀和"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c3a67df0b81749bdb0"}}, {"id": "D", "title": "宝藏", "tags": ["线段树", "栈", "括号序列", "矩阵乘法"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例、700 组独立朴素对拍与 6 组 10 万规模压力测试通过；曙梦 OJ 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2", "source_sha256": "ae452c40a94a10bde5c2b7762bc72497775a8991ed96e7f92f9e7e6bad5bc4a3"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490650", "source_sha256": "b9dac51f4128d412d8797ca5102466c3a040e8c3431df66c0cef4bca8c940ae7", "note": "上一版根号分块代码记录；本版已改为线段树，须重新复验"}}, {"id": "E", "title": "彩色路径", "tags": ["状态压缩", "折半搜索", "位集", "图论"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c7a67df0b81749bdda"}}]
---

# CSP 202312 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 仓库规划

标签：`暴力枚举` · `多维比较`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

仓库j若每一维坐标都严格大于仓库i，便可作为i的上级。多个候选取最小编号，没有则输出0。n≤1000、维度≤10。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312A)。

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

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

分解正整数 n 的质因子，指数小于阈值 k 的整个质数幂删去，其他保留；无项剩余输出1。n≤$10^{10}$，查询数≤10。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312B)。

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

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

类别形成根为 1 的带正权树。每次在剩余类别中选一个点，使其子树内剩余权重与子树外权重之差绝对值最小，同分选编号小者；根据目标是否在该子树，保留对应一侧，直到只剩一个类别。给定 m 个目标，输出各自提问序列。$n\le2000,m\le100$，父节点编号不一定小于子节点。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312C)。

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

标签：`线段树` · `栈` · `括号序列` · `矩阵乘法`

状态：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例、700 组独立朴素对拍与 6 组 10 万规模压力测试通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2)（民间复刻评测）。

### 题意

维护 $n$ 条矩阵双端队列指令：1 表示头插一个 $2\times2$ 矩阵，2 表示尾插，3 表示删除最近插入的矩阵（空队列忽略）。支持修改某一条指令，以及从空队列执行区间 $[l,r]$ 的指令后，输出队列内矩阵从头到尾的乘积，元素模 $998244353$。空队列乘积为单位矩阵。$n,m\le10^5$。修改格式为 `1 i 新指令`，查询为 `2 l r`。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312D)。

### 题解

**1. 先决定谁能留下，再决定乘法顺序**

虽然容器是双端队列，但删除的对象取决于插入时间。因此，我们可以先用一个普通栈记录插入指令：指令 1、2 都压栈，指令 3 弹栈。最后留在栈中的插入指令，就是没有被撤销的矩阵。

对于这些存活指令，设 `front` 为所有头插矩阵按时间倒序相乘的结果，`back` 为所有尾插矩阵按时间正序相乘的结果，答案就是 `front * back`。例如依次“头插 A、尾插 B、头插 C”，队列为 `C,A,B`，答案是 `(C*A)*B`。

矩阵乘法不能交换顺序，也不能假设输入矩阵可逆。以下做法只用乘法，不需要求逆。

**2. 一段指令可以压缩成“删除若干个，再插入若干个”**

在空栈上执行一段指令，记录：

- `removed`：栈空时遇到多少次删除；
- `size`：最后还剩多少次插入；
- `all`：这些存活插入对应的 `front`、`back` 两个矩阵积。

这段指令接在任意已有栈后面，等价于先删除最多 `removed` 个旧元素，再压入本段存活的插入。块内已经互相抵消的插入和删除，不会影响外部结果。

现在考虑相邻两段 `L`、`R`。右段开头的删除会消去左段存活序列的末尾，因此左段留下的数量为

$$k=\max(0,L.size-R.removed).$$

合并后，存活序列是“左段的前 `k` 个存活插入，接上右段的全部存活插入”。于是

$$size=k+R.size,$$

$$removed=L.removed+\max(0,R.removed-L.size).$$

例如左段留下 `A,B,C`，右段先删除 2 次、再留下 `D`，合并后留下 `A,D`。

**3. 在线段树里快速取得存活序列的前缀**

难点是得到“左段前 `k` 个存活插入”的矩阵积。我们用线段树维护上述摘要，每个节点再缓存两个量：

- `leftSize`：合并左右儿子后，左儿子还留下多少个插入；
- `leftPart`：这部分插入对应的两种矩阵积。

若要获取某个节点存活序列的前 `count` 项：

1. 若取空前缀，返回两个单位矩阵；若取全部，直接返回 `all`。
2. 若 `count <= leftSize`，只需在左儿子中取前 `count` 项。
3. 否则，先取已缓存的 `leftPart`，再接上右儿子存活序列的前 `count-leftSize` 项。

每次递归只进入一个儿子，所以取一个存活前缀只需要 `O(log n)`。合并节点时，调用这个前缀操作得到左侧留下的部分，再与右儿子的摘要合并。

合并两段乘积时也必须保留方向。若 `X` 在时间上先于 `Y`，则

$$front=Y.front\times X.front,\qquad back=X.back\times Y.back.$$

后发生的头插排在前面，后发生的尾插排在后面，这就是两个方向不同的原因。

**4. 修改与查询**

单点修改后，从对应叶子向上重新合并节点，共 `O(log n)` 层，每次合并最多花 `O(log n)`，故修改最坏为 `O(log^2 n)`。

查询先把 `[l,r]` 分成线段树上的 `O(log n)` 个完整节点，然后**从右往左**处理。维护右侧还需要向左删除多少个插入，记作 `removed`：

- 若当前节点的 `size <= removed`，它留下的插入被全部删掉，把剩余删除需求及当前节点自己的未配对删除继续传向左边。
- 否则只保留当前节点存活序列的前 `size-removed` 项，取出对应乘积，接到已处理部分的前面；下一步向左传递的删除需求变成当前节点自己的 `removed`。

全部处理完后，任何多余删除都作用于空队列，可以忽略。输出累计的 `front * back`。

节点摘要准确描述一段指令对任意旧栈的作用；左右合并只删除左段存活序列的后缀；查询又严格按时间顺序组合最后的存活指令，所以计算结果与逐条执行相同。

空间复杂度为 `O(n)`。查询与修改最坏均为 `O(log^2 n)`。自底向上建树为 `O(n)`：高度为 `h` 的节点只有 `O(n/2^h)` 个，每个合并花 `O(h)`，而 `sum(h/2^h)` 有界。实现额外使用缓冲输入输出和固定长度的查询节点数组，避免每次查询反复分配容器。

旧版根号分块在曙梦 OJ 重交仍为 [85 分超时](https://oj.shumeng.tech/record/6addc9ec74ace1cba9a21d5a)，本版已获 [100 分 Accepted](https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2)。同机 6 组上界构造较旧版快约 8–36 倍；本地耗时不等同评测机耗时。[独立对拍脚本](../tests/treasure_regressions.py)、[验证报告](../tests/treasure-report.json)。上一版洛谷满分记录保留在元数据中，本版仍需单独复验。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <vector>
using namespace std;

constexpr uint32_t MOD = 998244353;
struct Matrix {
    uint32_t a = 1, b = 0, c = 0, d = 1;
};
inline Matrix multiply(const Matrix &x, const Matrix &y) {
    return {
        uint32_t((uint64_t(x.a) * y.a + uint64_t(x.b) * y.c) % MOD),
        uint32_t((uint64_t(x.a) * y.b + uint64_t(x.b) * y.d) % MOD),
        uint32_t((uint64_t(x.c) * y.a + uint64_t(x.d) * y.c) % MOD),
        uint32_t((uint64_t(x.c) * y.b + uint64_t(x.d) * y.d) % MOD)
    };
}
struct Product {
    Matrix front, back;
};
// Execute x before y: later front insertions precede all earlier ones.
inline Product join(const Product &x, const Product &y) {
    return {multiply(y.front, x.front), multiply(x.back, y.back)};
}

class FastIO {
    static constexpr int SIZE = 1 << 16;
    char input[SIZE], output[SIZE];
    int pos = 0, length = 0, used = 0;
    int get() {
        if (pos == length) {
            length = int(fread(input, 1, SIZE, stdin));
            pos = 0;
            if (!length) return EOF;
        }
        return input[pos++];
    }
public:
    ~FastIO() { flush(); }
    int read() {
        int ch = get(), value = 0;
        while (ch <= ' ' && ch != EOF) ch = get();
        while (ch >= '0' && ch <= '9') {
            value = value * 10 + ch - '0';
            ch = get();
        }
        return value;
    }
    void flush() {
        fwrite(output, 1, used, stdout);
        used = 0;
    }
    void write(uint32_t value, char end) {
        if (used + 12 >= SIZE) flush();
        char digits[10];
        int count = 0;
        do {
            digits[count++] = char('0' + value % 10);
            value /= 10;
        } while (value);
        while (count) output[used++] = digits[--count];
        output[used++] = end;
    }
};

struct Node {
    int removed = 0, size = 0, leftSize = 0;
    Product all, leftPart;
};

class SegmentTree {
    int base = 1;
    vector<Node> nodes;

    // First count insertions of this node's reduced chronological sequence.
    Product prefix(int u, int count) const {
        const Node &node = nodes[u];
        if (count == node.size) return node.all;
        if (!count) return {};
        if (count <= node.leftSize) return prefix(u * 2, count);
        return join(node.leftPart, prefix(u * 2 + 1, count - node.leftSize));
    }

    void pull(int u) {
        Node &node = nodes[u];
        const Node &left = nodes[u * 2], &right = nodes[u * 2 + 1];
        node.leftSize = max(0, left.size - right.removed);
        node.size = node.leftSize + right.size;
        node.removed = left.removed + max(0, right.removed - left.size);
        node.leftPart = prefix(u * 2, node.leftSize);
        if (!node.leftSize) node.all = right.all;
        else if (!right.size) node.all = node.leftPart;
        else node.all = join(node.leftPart, right.all);
    }

    void setLeaf(int u, int type, const Matrix &value) {
        Node &node = nodes[u];
        node.removed = type == 3;
        node.size = type != 3;
        node.all = {};
        if (type == 1) node.all.front = value;
        if (type == 2) node.all.back = value;
    }

public:
    explicit SegmentTree(int n) {
        while (base < n) base *= 2;
        nodes.resize(base * 2);
    }
    void initialize(int i, int type, const Matrix &value) {
        setLeaf(base + i, type, value);
    }
    void build() {
        for (int u = base - 1; u; --u) pull(u);
    }
    void update(int i, int type, const Matrix &value) {
        int u = base + i;
        setLeaf(u, type, value);
        while ((u /= 2)) pull(u);
    }
    Matrix query(int l, int r) const {
        // Collect the disjoint covering nodes in chronological order.
        int leftNodes[32], rightNodes[32], nl = 0, nr = 0;
        for (l += base, r += base + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) leftNodes[nl++] = l++;
            if (r & 1) rightNodes[nr++] = --r;
        }
        int removed = 0;
        Product answer;
        bool nonempty = false;
        auto consume = [&](int u) {
            const Node &node = nodes[u];
            if (node.size <= removed) {
                removed += node.removed - node.size;
            } else {
                Product part = prefix(u, node.size - removed);
                answer = nonempty ? join(part, answer) : part;
                nonempty = true;
                removed = node.removed;
            }
        };
        // Scan backwards: later deletions remove a suffix of earlier survivors.
        for (int i = 0; i < nr; ++i) consume(rightNodes[i]);
        for (int i = nl - 1; i >= 0; --i) consume(leftNodes[i]);
        return multiply(answer.front, answer.back);
    }
};

int main() {
    FastIO io;
    int n = io.read(), m = io.read();
    SegmentTree tree(n);
    auto readMatrix = [&](int type) {
        Matrix value;
        if (type != 3) {
            value.a = io.read(); value.b = io.read();
            value.c = io.read(); value.d = io.read();
        }
        return value;
    };
    for (int i = 0; i < n; ++i) {
        int type = io.read();
        tree.initialize(i, type, readMatrix(type));
    }
    tree.build();
    while (m--) {
        int op = io.read();
        if (op == 1) {
            int i = io.read() - 1, type = io.read();
            tree.update(i, type, readMatrix(type));
        } else {
            int l = io.read() - 1, r = io.read() - 1;
            Matrix answer = tree.query(l, r);
            io.write(answer.a, ' '); io.write(answer.b, ' ');
            io.write(answer.c, ' '); io.write(answer.d, '\n');
        }
    }
}
```

<a id="problem-e"></a>

## E. 彩色路径

标签：`状态压缩` · `折半搜索` · `位集` · `图论`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

有向图的点带颜色，求从 0 到 $n-1$ 的最长路径，要求路径各点颜色不同，点数不超过 $l$。$n\le100,m\le5000,l\le9,k\le30$，边权为正。输入第一行 `n m l k`，第二行颜色，随后三行分别给全部边的起点、终点、权值。保证存在合法路线，且起终点颜色不在其他点上出现。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312E)。

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
