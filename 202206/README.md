---
title: "CSP 202206 五题题解"
contest: "202206"
contest_month: "2022-06"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "均值", "方差", "浮点数", "稀疏坐标", "枚举", "矩阵匹配", "权限系统", "位集", "哈希表", "模拟", "有序集合", "几何", "线段树", "矩阵", "仿射变换", "计算几何"]
status: "published"
problems: [{"id": "A", "title": "归一化处理", "tags": ["均值", "方差", "浮点数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce920a67df0b81749c03a"}}, {"id": "B", "title": "寻宝！大冒险！", "tags": ["稀疏坐标", "枚举", "矩阵匹配"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce921a67df0b81749c040"}}, {"id": "C", "title": "角色授权", "tags": ["权限系统", "位集", "哈希表", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce923a67df0b81749c046"}}, {"id": "D", "title": "光线追踪", "tags": ["模拟", "有序集合", "几何"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce925a67df0b81749c04d"}}, {"id": "E", "title": "PS 无限版", "tags": ["线段树", "矩阵", "仿射变换", "计算几何"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 30 分 Time Exceeded（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206E/"}], "oj": {"status": "failed", "score": 30, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6adce927a67df0b81749c056"}}]
---

# CSP 202206 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 归一化处理

标签：`均值` · `方差` · `浮点数`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给n个整数，计算均值μ、总体方差D，再依次输出(a[i]-μ)/√D。题目保证D≥1。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206A)。

### 题解

第一遍求平均值，第二遍累加每个数与均值之差的平方并除以n，开方后逐个归一化输出。

严格使用题目的总体方差分母n，不是统计学中另一种样本方差分母n-1；用浮点除法防止均值被整数截断。两遍公式与定义完全相同，平方差计算也比先算平方和再相减更稳健。时间 $O(n)$，存储数据空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long double> a(n);
    long double mean = 0;
    for (auto &x : a) {
        cin >> x;
        mean += x;
    }
    mean /= n;
    long double variance = 0;
    for (auto x : a)
        variance += (x - mean) * (x - mean);
    variance /= n;
    long double sd = sqrtl(variance);
    cout << fixed << setprecision(10);
    for (auto x : a)
        cout << (x - mean) / sd << '\n';
}
```

<a id="problem-b"></a>

## B. 寻宝！大冒险！

标签：`稀疏坐标` · `枚举` · `矩阵匹配`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

巨大地图中只有 n≤1000 棵树，藏宝图为(S+1)²的01图，S≤50，左下角一定有树。求可与藏宝图完全一致且不越界的位置数；读入藏宝图时第一行对应第一坐标 S，最后一行对应0。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206B)。

### 题解

候选左下角一定是已有树，故只枚举 n 个位置。若右上角超过 L 则跳过；否则扫描全部树，检查落入候选方形内的树是否都对应藏宝图的1，并统计这些树的数量。

若存在对应0的树则失败；若没有且数量恰好等于藏宝图1的总数，就成功。因为不同树坐标不同，“全部落在1上且数量相等”保证每个1都被覆盖，也保证所有0处无树。时间 $O(n^2+S^2)$，空间 $O(n+S^2)$，无需分配大小由 L 决定的数组。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L, S;
    cin >> n >> L >> S;
    vector<pair<int, int>> trees(n);
    for (auto &[x, y] : trees)
        cin >> x >> y;
    vector<vector<int>> b(S + 1, vector<int>(S + 1));
    int ones = 0;
    for (int x = S; x >= 0; x--)
        for (int y = 0; y <= S; y++) {
            cin >> b[x][y];
            ones += b[x][y];
        }
    int answer = 0;
    for (auto [x, y] : trees) {
        if (x + S > L || y + S > L)
            continue;
        int count = 0;
        bool ok = true;
        for (auto [u, v] : trees) {
            int dx = u - x, dy = v - y;
            if (dx >= 0 && dx <= S && dy >= 0 && dy <= S) {
                ++count;
                if (!b[dx][dy]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && count == ones)
            ++answer;
    }
    cout << answer << '\n';
}
```

<a id="problem-c"></a>

## C. 角色授权

标签：`权限系统` · `位集` · `哈希表` · `模拟`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

角色规定允许的操作、资源种类、资源名称；操作与种类中的 * 表示全部，名称列表为空表示全部。角色可授予用户或用户组。查询给出用户、所属组和待访问资源，判断是否存在一个与用户关联且同时允许全部三项的角色。角色、关联规则至多 500，查询至多 5000。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206C)。

### 题解

角色的三个权限集合分别存储。为每个用户、用户组建立角色位集，读取关联时将角色位设为 1；查询时把该用户和全部所属组的角色位集做或运算。

随后只检查关联角色，每个角色必须同时通过操作、资源类型、资源名称三项检查，任意一个角色通过即可授权。不能把不同角色的三个权限字段分别合并，否则可能把“角色甲能操作 A”与“角色乙能访问 B”拼成不存在的授权。

位集恰好表示关联角色的并集，逐角色的合取和角色间的析取与题意一致。若角色数 R、查询组数 G，单次期望时间 $O(GR/64+R)$；哈希集合查询期望常数时间，空间为权限字符串及关联位集总量。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct Role {
    unordered_set<string> verbs, types, names;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<Role> roles(n);
    unordered_map<string, int> rid;
    for (int i = 0; i < n; i++) {
        string name, s;
        cin >> name;
        rid[name] = i;
        for (auto *set : {&roles[i].verbs, &roles[i].types, &roles[i].names}) {
            int k;
            cin >> k;
            while (k--) {
                cin >> s;
                set->insert(s);
            }
        }
    }
    unordered_map<string, bitset<500>> users, groups;
    while (m--) {
        string r, t, name;
        int k;
        cin >> r >> k;
        while (k--) {
            cin >> t >> name;
            (t == "u" ? users : groups)[name].set(rid[r]);
        }
    }
    while (q--) {
        string user, g, verb, type, name;
        int k;
        cin >> user >> k;
        bitset<500> allowed;
        auto u = users.find(user);
        if (u != users.end())
            allowed = u->second;
        while (k--) {
            cin >> g;
            auto it = groups.find(g);
            if (it != groups.end())
                allowed |= it->second;
        }
        cin >> verb >> type >> name;
        bool ok = false;
        for (int i = 0; i < n; i++)
            if (allowed[i]) {
                auto &r = roles[i];
                if ((r.verbs.count("*") || r.verbs.count(verb)) &&
                    (r.types.count("*") || r.types.count(type)) &&
                    (r.names.empty() || r.names.count(name))) {
                    ok = true;
                    break;
                }
            }
        cout << ok << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 光线追踪

标签：`模拟` · `有序集合` · `几何`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

动态插入、删除与坐标轴成 45° 的反射线段；线段端点不反射，折损系数为 $a\in[0.2,0.8]$。查询从整数点沿右、上、左、下（编号 0、1、2、3）发射强度 $I$ 的光线，单位时间走单位距离，经过 $t$ 后的位置与向下取整的强度。到达镜面恰好用完时间时仍需折损；强度小于 1 输出 `0 0 0`。删除编号是插入发生的操作序号。$m\le10^5$，全部插入线段的横向长度之和不超过 $3\times10^5$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206D)。

### 题解

光线起点是整数点，水平或竖直光线与 45° 镜面的交点也是整数点，反射后仍沿坐标轴行进。因此只需存储每条线段的内部整点，完全排除端点。总横向长度受限，所以这种展开最多产生 $3\times10^5$ 个点。

分别用有序映射保存 `(y,x)->镜面编号` 与 `(x,y)->镜面编号`。横向运动在第一张表查邻点，纵向运动在第二张表查邻点，并检查是否仍在同一条直线上。向正方向用严格后继，负方向用严格前驱，避免刚反射完又撞上原位置。

若最近交点距离大于剩余时间，就沿当前方向走完；否则移动到交点、扣掉距离并乘折损系数。斜率 +1 将方向交换为右↔上、左↔下；斜率 -1 为右↔下、上↔左。距离等于剩余时间时也执行反射与折损。

每步总是选择射线上最近的真实镜面交点，因此不会跳过碰撞。每次强度最多保留 0.8 倍，初始至多 $10^9$，至多约 93 次反射就会低于 1；不必逐单位时间推进。设总内部点数为 $S$、查询数为 $Q$，时间 $O((S+93Q)\log(S+1))$，空间 $O(S+m)$。题目明确保证直接使用 64 位浮点数与取整即可。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <cmath>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
using i64 = long long;
struct Mirror {
    i64 x1, y1, x2, y2;
    double ratio;
    int slope;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<Mirror> mirrors(m + 1);
    map<pair<i64, i64>, int> horizontal, vertical;
    auto modify = [&](int id, bool insert) {
        const auto &s = mirrors[id];
        for (i64 x = s.x1 + 1; x < s.x2; ++x) {
            i64 y = s.y1 + s.slope * (x - s.x1);
            if (insert) {
                horizontal[{y, x}] = id;
                vertical[{x, y}] = id;
            } else {
                horizontal.erase({y, x});
                vertical.erase({x, y});
            }
        }
    };
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    for (int op_index = 1; op_index <= m; ++op_index) {
        int op;
        cin >> op;
        if (op == 1) {
            auto &s = mirrors[op_index];
            cin >> s.x1 >> s.y1 >> s.x2 >> s.y2 >> s.ratio;
            if (s.x1 > s.x2) {
                swap(s.x1, s.x2);
                swap(s.y1, s.y2);
            }
            s.slope = s.y2 > s.y1 ? 1 : -1;
            modify(op_index, true);
        } else if (op == 2) {
            int id;
            cin >> id;
            modify(id, false);
        } else {
            i64 x, y, time;
            int direction;
            double intensity;
            cin >> x >> y >> direction >> intensity >> time;
            while (time > 0 && intensity >= 1) {
                bool is_horizontal = direction % 2 == 0, positive = direction < 2;
                auto &points = is_horizontal ? horizontal : vertical;
                i64 line = is_horizontal ? y : x, current = is_horizontal ? x : y;
                auto it = points.end();
                if (positive)
                    it = points.upper_bound({line, current});
                else {
                    auto next = points.lower_bound({line, current});
                    if (next != points.begin())
                        it = prev(next);
                }
                if (it == points.end() || it->first.first != line ||
                    abs(it->first.second - current) > time) {
                    x += dx[direction] * time;
                    y += dy[direction] * time;
                    time = 0;
                    break;
                }
                i64 distance = abs(it->first.second - current);
                x += dx[direction] * distance;
                y += dy[direction] * distance;
                time -= distance;
                const auto &s = mirrors[it->second];
                intensity *= s.ratio;
                direction ^= s.slope == 1 ? 1 : 3;
            }
            if (intensity < 1)
                cout << "0 0 0\n";
            else
                cout << x << ' ' << y << ' ' << i64(floor(intensity)) << '\n';
        }
    }
}
```

<a id="problem-e"></a>

## E. PS 无限版

标签：`线段树` · `矩阵` · `仿射变换` · `计算几何`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 30 分 Time Exceeded（复刻评测）。

### 题意

维护按编号排列的平面点，支持区间平移、绕给定点旋转、绕给定点缩放、关于直线对称、投影到直线，查询区间重心或到指定点的距离平方和。输入 `n q`、各点坐标，再输入操作；操作 1–7 的参数顺序见原题。角度均为弧度，直线表示为 $y=(\tan\theta)x+y_0$。$n\le5\times10^5,q\le2\times10^4$，答案允许绝对或相对误差 $10^{-3}$。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206E)。

### 题解

**把五种修改统一成仿射变换。** 用列向量 $p=(x,y,1)^T$ 表示一个点，修改写成 $p'=Tp$，其中 $T$ 为 $3\times3$ 矩阵。平移写入最后一列；旋转的左上角为 $\begin{pmatrix}\cos\theta&-\sin\theta\\\sin\theta&\cos\theta\end{pmatrix}$；缩放为 $\lambda I$。若以 $c=(a,b)^T$ 为中心，平移列统一写成 $c-Ac$。

对于经过 $(0,y_0)$、方向为 $d=(\cos\theta,\sin\theta)^T$ 的直线，投影的线性部分为 $dd^T$，对称为 $2dd^T-I$，同样使用 $c-Ac$ 得到平移列。这样无需计算接近无穷大的 $\tan\theta$。

**用中心二阶矩避免大数相减。** 每段维护点数 $N$、重心 $\mu$，以及中心矩阵 $C=\sum(p-\mu)(p-\mu)^T$，只需保存 $C_{xx},C_{xy},C_{yy}$。若仿射变换的线性部分为 $A$、平移为 $b$，则

$$\mu'=A\mu+b,\qquad C'=ACA^T.$$

平移只改变重心，旋转、缩放、投影改变中心矩阵。合并两段时，令 $\delta=\mu_2-\mu_1$，有

$$\mu=\mu_1+\frac{N_2}{N_1+N_2}\delta,$$
$$C=C_1+C_2+\frac{N_1N_2}{N_1+N_2}\delta\delta^T.$$

这些式子直接由中心偏移展开得到。查询重心时直接输出 $\mu$，到点 $q$ 的距离平方和为 $\operatorname{tr}(C)+N\lVert\mu-q\rVert^2$。相比维护 $\sum x^2$ 再减去多个巨大项，这个写法对坐标很大但点间距离很小的情况更稳定。

线段树懒标记仍保存完整的 $3\times3$ 仿射矩阵，顺序必须是 `lazy = T * lazy`，因为列向量先经历旧变换再经历新变换。叶子的中心矩阵为零，空查询段的点数为零，合并时直接忽略空段。

**正确性。** 仿射矩阵准确表达每种操作，中心矩阵的变换和合并公式是逐点展开的恒等式；线段树因此始终保存实际点集的重心与二阶矩。**复杂度：** 建树 $O(n)$，每次操作 $O(3^3\log n)$，空间 $O(n)$。使用 `long double` 和足够的小数位，并对最终距离平方和做非负截断；浮点计算仍应按题面容差比较。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using Real = long double;
struct Matrix {
    Real a[3][3]{};
    static Matrix identity() {
        Matrix m;
        for (int i = 0; i < 3; ++i)
            m.a[i][i] = 1;
        return m;
    }
};
Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 3; ++i)
        for (int k = 0; k < 3; ++k)
            for (int j = 0; j < 3; ++j)
                c.a[i][j] += a.a[i][k] * b.a[k][j];
    return c;
}
struct Moments {
    Real count = 0, x = 0, y = 0, xx = 0, xy = 0, yy = 0;
};
Moments operator+(Moments a, Moments b) {
    if (!a.count)
        return b;
    if (!b.count)
        return a;
    Real count = a.count + b.count, dx = b.x - a.x, dy = b.y - a.y,
         factor = a.count * b.count / count;
    return {count,
            a.x + dx * b.count / count,
            a.y + dy * b.count / count,
            a.xx + b.xx + factor * dx * dx,
            a.xy + b.xy + factor * dx * dy,
            a.yy + b.yy + factor * dy * dy};
}
Moments transform(const Moments &s, const Matrix &t) {
    Real a = t.a[0][0], b = t.a[0][1], c = t.a[1][0], d = t.a[1][1];
    return {s.count,
            a * s.x + b * s.y + t.a[0][2],
            c * s.x + d * s.y + t.a[1][2],
            a * a * s.xx + 2 * a * b * s.xy + b * b * s.yy,
            a * c * s.xx + (a * d + b * c) * s.xy + b * d * s.yy,
            c * c * s.xx + 2 * c * d * s.xy + d * d * s.yy};
}
struct Tree {
    vector<Moments> moment;
    vector<Matrix> lazy;
    vector<bool> pending;
    vector<array<Real, 2>> point;
    explicit Tree(int n) : moment(4 * n + 4), lazy(4 * n + 4), pending(4 * n + 4), point(n + 1) {}
    void build(int u, int l, int r) {
        lazy[u] = Matrix::identity();
        if (l == r) {
            moment[u] = {1, point[l][0], point[l][1], 0, 0, 0};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * u, l, mid);
        build(2 * u + 1, mid + 1, r);
        moment[u] = moment[2 * u] + moment[2 * u + 1];
    }
    void apply(int u, const Matrix &t) {
        moment[u] = transform(moment[u], t);
        lazy[u] = t * lazy[u];
        pending[u] = true;
    }
    void push(int u) {
        if (pending[u]) {
            apply(2 * u, lazy[u]);
            apply(2 * u + 1, lazy[u]);
            lazy[u] = Matrix::identity();
            pending[u] = false;
        }
    }
    void update(int u, int l, int r, int a, int b, const Matrix &t) {
        if (a <= l && r <= b) {
            apply(u, t);
            return;
        }
        push(u);
        int mid = (l + r) / 2;
        if (a <= mid)
            update(2 * u, l, mid, a, b, t);
        if (b > mid)
            update(2 * u + 1, mid + 1, r, a, b, t);
        moment[u] = moment[2 * u] + moment[2 * u + 1];
    }
    Moments query(int u, int l, int r, int a, int b) {
        if (a <= l && r <= b)
            return moment[u];
        push(u);
        int mid = (l + r) / 2;
        Moments result;
        if (a <= mid)
            result = result + query(2 * u, l, mid, a, b);
        if (b > mid)
            result = result + query(2 * u + 1, mid + 1, r, a, b);
        return result;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    int n, q;
    cin >> n >> q;
    Tree tree(n);
    for (int i = 1; i <= n; ++i)
        cin >> tree.point[i][0] >> tree.point[i][1];
    tree.build(1, 1, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op >= 6) {
            auto s = tree.query(1, 1, n, l, r);
            if (op == 6)
                cout << s.x << ' ' << s.y << '\n';
            else {
                Real a, b;
                cin >> a >> b;
                Real dx = s.x - a, dy = s.y - b;
                Real answer = s.xx + s.yy + s.count * (dx * dx + dy * dy);
                cout << max(Real(0), answer) << '\n';
            }
            continue;
        }
        Matrix t = Matrix::identity();
        Real a, b;
        if (op == 1) {
            cin >> a >> b;
            t.a[0][2] = a;
            t.a[1][2] = b;
        } else if (op == 2 || op == 3) {
            Real x;
            cin >> a >> b >> x;
            if (op == 2) {
                Real c = cosl(x), s = sinl(x);
                t.a[0][0] = t.a[1][1] = c;
                t.a[0][1] = -s;
                t.a[1][0] = s;
            } else
                t.a[0][0] = t.a[1][1] = x;
            t.a[0][2] = a - t.a[0][0] * a - t.a[0][1] * b;
            t.a[1][2] = b - t.a[1][0] * a - t.a[1][1] * b;
        } else {
            Real angle, y0;
            cin >> angle >> y0;
            Real c = cosl(angle), s = sinl(angle), factor = op == 4 ? 2 : 1,
                 subtract = op == 4 ? 1 : 0;
            t.a[0][0] = factor * c * c - subtract;
            t.a[0][1] = t.a[1][0] = factor * c * s;
            t.a[1][1] = factor * s * s - subtract;
            t.a[0][2] = -t.a[0][1] * y0;
            t.a[1][2] = y0 - t.a[1][1] * y0;
        }
        tree.update(1, 1, n, l, r, t);
    }
}
```
