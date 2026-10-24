---
title: "CSP 201512 五题题解"
contest: "201512"
contest_month: "2015-12"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "数位分解", "网格扫描", "同时更新", "BFS", "连通块", "网格模拟", "欧拉路径", "Hierholzer", "字典序", "线性代数", "GF(2)", "线性基", "多项式", "bitset"]
status: "published"
problems: [{"id": "A", "title": "数位之和", "tags": ["数位分解"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512A/"}]}, {"id": "B", "title": "消除类游戏", "tags": ["网格扫描", "同时更新"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512B/"}]}, {"id": "C", "title": "画图", "tags": ["BFS", "连通块", "网格模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512C/"}]}, {"id": "D", "title": "送货", "tags": ["欧拉路径", "Hierholzer", "字典序"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512D/"}]}, {"id": "E", "title": "矩阵", "tags": ["线性代数", "GF(2)", "线性基", "多项式", "bitset"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512E/"}]}]
---

# CSP 201512 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 数位之和

标签：`数位分解`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；未提交正式评测。

### 题意

给0≤n≤$10^9$的十进制整数，求各位数字之和。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512A)。

### 题解

反复把n%10加入答案，再令n/=10删除最低位，直到n为0。每轮处理一个且仅一个数位，最终得到所有数位之和。

初值答案设为0，输入0时无需进入循环也能正确输出0。时间 $O(\log(n+1))$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    cout << sum << '\n';
}
```

<a id="problem-b"></a>

## B. 消除类游戏

标签：`网格扫描` · `同时更新`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

棋盘中任一行或列有连续至少三个同色棋子时，这些棋子同时消除为0。只执行一次消除，求结果，行列数≤30。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512B)。

### 题解

保留原棋盘，另开布尔标记。枚举每格作为水平或竖直三个相邻格的起点，三者同色就全部标记。最后统一把标记格输出为0。

长度至少三的同色段由若干重叠三元组覆盖，因此标记全部且只标记应消除的棋子。先改棋盘会破坏另一方向的判断，必须延后统一输出。时间、空间均为 $O(nm)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<bool>> erase(n, vector<bool>(m));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j + 2 < m && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2])
                for (int d = 0; d < 3; d++)
                    erase[i][j + d] = true;
            if (i + 2 < n && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j])
                for (int d = 0; d < 3; d++)
                    erase[i + d][j] = true;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j)
                cout << ' ';
            cout << (erase[i][j] ? 0 : a[i][j]);
        }
        cout << '\n';
    }
}
```

<a id="problem-c"></a>

## C. 画图

标签：`BFS` · `连通块` · `网格模拟`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

在初始全为点号的画布上依序画水平／竖直线段、填充连通区域。横线用 -，竖线用 |，交叉用 +；填充沿上下左右传播，只有线段和画布边界阻挡，原有其他字母不阻挡。坐标原点在左下，宽高至多 100。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512C)。

### 题解

画线时枚举闭区间上的格子：原本是 + 或另一方向线段则写 +，否则写本方向线符号。画线可以覆盖之前的填充字母。

填充时从起点 BFS，允许经过全部非线段格子，另开 visited 记录本轮访问。不能把“字符已等于填充颜色”当作访问过，因为先前操作可能已留下同色区域，它仍须允许本轮穿过。处理完成按 y 从大到小输出。

画线逐格维持正确交叉状态；BFS 恰好到达忽略旧填充颜色后的四连通块，所以写入范围符合定义。每次操作最坏 $O(mn)$，空间 $O(mn)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
bool wall(char c) {
    return c == '-' || c == '|' || c == '+';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, q;
    cin >> m >> n >> q;
    vector<string> a(n, string(m, '.'));
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 0) {
            int xx, yy;
            cin >> xx >> yy;
            bool horizontal = y == yy;
            if (x > xx)
                swap(x, xx);
            if (y > yy)
                swap(y, yy);
            for (int i = y; i <= yy; i++)
                for (int j = x; j <= xx; j++) {
                    char &c = a[i][j];
                    c = (c == '+' || (horizontal ? c == '|' : c == '-')) ? '+'
                        : horizontal                                     ? '-'
                                                                         : '|';
                }
        } else {
            char c;
            cin >> c;
            vector<vector<bool>> seen(n, vector<bool>(m));
            queue<pair<int, int>> todo;
            todo.push({x, y});
            seen[y][x] = true;
            int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
            while (!todo.empty()) {
                auto [u, v] = todo.front();
                todo.pop();
                a[v][u] = c;
                for (int k = 0; k < 4; k++) {
                    int xx = u + dx[k], yy = v + dy[k];
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n && !seen[yy][xx] &&
                        !wall(a[yy][xx])) {
                        seen[yy][xx] = true;
                        todo.push({xx, yy});
                    }
                }
            }
        }
    }
    for (int y = n - 1; y >= 0; y--)
        cout << a[y] << '\n';
}
```

<a id="problem-d"></a>

## D. 送货

标签：`欧拉路径` · `Hierholzer` · `字典序`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；未提交正式评测。

### 题意

给定无向街道图，从路口 1 出发，要求每条边恰好经过一次，输出字典序最小的路口序列；无解输出 -1。$n\le10^4,m\le10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512D)。

### 题解

先检查无向欧拉路径的度数条件：奇度点必须为 0 个，或恰好 2 个且起点 1 是其中之一。仅有度数条件还不够，最后还需确认全部边都被遍历。

将各点邻边按邻居编号升序排序，使用 Hierholzer：用栈沿未用边前进，走不动时把当前点加入答案并退栈，最后反转答案。每条无向边使用唯一编号，两侧邻接记录共用访问标记，不能仅标记点。

为什么不能直接把前进顺序当答案？最小邻居可能通向应最后走的死路。回溯逆序输出会把这类分支放到正确的末尾。按升序选边时，能够先完成的最小可行分支优先保留；不得不推迟的终止分支由回溯自动后置，因此得到最小字典序的欧拉路线。最终序列长度必须是 m+1，否则存在与起点不连通的边，输出 -1。

排序时间 $O(m\log m)$，排序后构造 $O(n+m)$，空间 $O(n+m)$。代码用显式栈，避免长度十万的递归调用。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }
    int odd = 0;
    for (int u = 1; u <= n; ++u) {
        sort(graph[u].begin(), graph[u].end());
        odd += graph[u].size() % 2;
    }
    if (odd != 0 && (odd != 2 || graph[1].size() % 2 == 0)) {
        cout << -1 << '\n';
        return 0;
    }
    vector<bool> used(m);
    vector<int> pointer(n + 1), stack{1}, path;
    while (!stack.empty()) {
        int u = stack.back();
        auto &i = pointer[u];
        while (i < int(graph[u].size()) && used[graph[u][i].second])
            ++i;
        if (i == int(graph[u].size())) {
            path.push_back(u);
            stack.pop_back();
        } else {
            auto [v, id] = graph[u][i++];
            used[id] = true;
            stack.push_back(v);
        }
    }
    if (path.size() != size_t(m + 1)) {
        cout << -1 << '\n';
        return 0;
    }
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); ++i)
        cout << path[i] << (i + 1 == path.size() ? '\n' : ' ');
}
```

<a id="problem-e"></a>

## E. 矩阵

标签：`线性代数` · `GF(2)` · `线性基` · `多项式` · `bitset`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；未提交正式评测。

### 题意

给定 $m\times m$ 的 01 矩阵 $A$ 和 01 列向量 $b$。加法为异或、乘法为与，即在 $GF(2)$ 上运算。对至多 100 个 $k\le10^9$，输出 $A^kb$；$m\le1000$。输入矩阵和向量均是没有空格的 01 串，$k=0$ 时输出原向量。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512E)。

### 题解

**只关心矩阵作用在这个向量上的轨道。** 依次生成 $v_0=b,v_1=Ab,v_2=A^2b,\ldots$，并向带表达式的线性基插入这些向量。至多 $m+1$ 个向量就线性相关。设第一次出现

$$v_d=\sum_{j<d}c_jv_j.$$

每个基向量同时保存它由哪些 $v_j$ 异或组成，消元时同步异或表达式，即可求出这组系数。得到多项式 $P(x)=x^d+\sum c_jx^j$，满足 $P(A)b=0$。

**大指数改为多项式取模。** 计算 $R(x)=x^k\bmod P(x)$，则 $A^kb=R(A)b$，直接异或 $R$ 中为 1 的系数对应的 $v_j$。预处理 $x^{2^t}\bmod P$，每个询问按二进制组合。

所有向量用 `bitset` 保存。矩阵乘向量的某一位，是该行与向量按位与后的 1 的个数的奇偶。多项式乘法是若干左移后异或，取余则从高位到低位消去最高项，完全不需要浮点数，也不需要常规三次方矩阵乘法。若 $b=0$，第一次关系的次数为 0，所有答案直接输出零向量。

**正确性。** 线性相关式右乘任意次 $A$ 后仍成立，故其多项式倍数作用于 $b$ 都是零，指数取余不会改变答案。这里求的是当前向量的湮灭多项式，不要求先算整个矩阵的特征多项式。

**复杂度。** 用机器字长 $w$ 表示并行位数，生成和消元约 $O(m^3/w)$；多项式幂约 $O((q+1)m^2\log k/w)$，空间 $O(m^2/w)$ 个机器字。实际性能取决于 `bitset::count` 和移位实现；编译开启优化。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <array>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using Bits = bitset<1001>;
using Poly = bitset<2048>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<Bits> a(m), basis(m), expression(m), states;
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j)
            a[i][j] = s[j] == '1';
    }
    cin >> s;
    Bits current;
    for (int j = 0; j < m; ++j)
        current[j] = s[j] == '1';
    Poly relation;
    int degree = 0;
    for (int d = 0; d <= m; ++d) {
        Bits v = current, e;
        e[d] = 1;
        bool independent = false;
        for (int p = m - 1; p >= 0; --p)
            if (v[p]) {
                if (basis[p].none()) {
                    basis[p] = v;
                    expression[p] = e;
                    independent = true;
                    break;
                }
                v ^= basis[p];
                e ^= expression[p];
            }
        if (!independent) {
            degree = d;
            for (int j = 0; j <= d; ++j)
                relation[j] = e[j];
            break;
        }
        states.push_back(current);
        Bits next;
        for (int i = 0; i < m; ++i)
            next[i] = (a[i] & current).count() % 2;
        current = next;
    }
    auto reduce = [&](Poly v) {
        for (int i = 2 * degree - 1; i >= degree; --i)
            if (v[i])
                v ^= relation << (i - degree);
        return v;
    };
    auto multiply = [&](const Poly &x, const Poly &y) {
        Poly z;
        for (int i = 0; i < degree; ++i)
            if (x[i])
                z ^= y << i;
        return reduce(z);
    };
    array<Poly, 31> power{};
    if (degree) {
        power[0][1] = 1;
        power[0] = reduce(power[0]);
        for (int j = 1; j < 31; ++j)
            power[j] = multiply(power[j - 1], power[j - 1]);
    }
    int q;
    cin >> q;
    while (q--) {
        unsigned k;
        cin >> k;
        Bits answer;
        if (degree) {
            Poly p;
            p[0] = 1;
            for (int j = 0; j < 31; ++j)
                if (k >> j & 1)
                    p = multiply(p, power[j]);
            for (int j = 0; j < degree; ++j)
                if (p[j])
                    answer ^= states[j];
        }
        for (int j = 0; j < m; ++j)
            cout << answer[j];
        cout << '\n';
    }
}
```
