---
title: "CSP 202309 五题题解"
contest: "202309"
contest_month: "2023-09"
date: "2026-10-23"
updated: "2026-10-25"
tags: ["CSP", "累加", "平移变换", "前缀积", "前缀和", "旋转变换", "自动微分", "表达式", "栈", "有序集合", "几何", "模拟", "动态树", "树的直径", "动态规划"]
status: "published"
problems: [{"id": "A", "title": "坐标变换（其一）", "tags": ["累加", "平移变换"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16054"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c8a67df0b81749bdf6"}}, {"id": "B", "title": "坐标变换（其二）", "tags": ["前缀积", "前缀和", "旋转变换"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17/C++20 编译通过；2 个保存样例、500 组独立逐次操作对拍与 70 位精度边界复核通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16055"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb80574ace1cba9a20d52"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490746", "code_git_blob": "20776d0627c78f6c02502fc311a5648a5f01a3cb", "note": "上一版代码记录；本版新增高低角度前缀精度修复，以曙梦复验为准"}}, {"id": "C", "title": "梯度求解", "tags": ["自动微分", "表达式", "栈"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16056"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8cca67df0b81749be25"}}, {"id": "D", "title": "阴阳龙", "tags": ["有序集合", "几何", "模拟"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例、700 组独立随机对拍、255 种八方向占位掩码与 6 组 p=q=100000 上界测试通过；曙梦 OJ 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16057"}], "previous_oj": {"status": "failed", "score": 15, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6addca8774ace1cba9a21e22", "source_sha256": "cf65f5b624668a7c99fc6d7e9412abbd41af73b15b9ba405bf15aad1eb59f553", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490899", "source_sha256": "cf65f5b624668a7c99fc6d7e9412abbd41af73b15b9ba405bf15aad1eb59f553", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addfd5374ace1cba9a2324b", "source_sha256": "746784b9f38218ef1ad4b9f61f94c36aa4d8fa809310df1fee29028a4b61e83a"}}, {"id": "E", "title": "阻击", "tags": ["动态树", "树的直径", "动态规划"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16058"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8cfa67df0b81749be4d"}}]
---

# CSP 202309 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 坐标变换（其一）

标签：`累加` · `平移变换`

状态：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定n次平移(dx,dy)，求m个起点各自按相同操作序列平移后的坐标。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16054)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309A)。

### 题解

平移对两坐标分别加法，先累计全部dx和dy，再给每个点加上这两个总位移。

加法结合律保证合并后的平移等于逐次执行，所有点可共用预处理结果。时间 $O(n+m)$，额外空间 $O(1)$，累加使用64位。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    long long dx = 0, dy = 0;
    while (n--) {
        long long x, y;
        cin >> x >> y;
        dx += x;
        dy += y;
    }
    while (m--) {
        long long x, y;
        cin >> x >> y;
        cout << x + dx << ' ' << y + dy << '\n';
    }
}
```

<a id="problem-b"></a>

## B. 坐标变换（其二）

标签：`前缀积` · `前缀和` · `旋转变换`

状态：**完整实现，曙梦 OJ 已验证满分**。C++17/C++20 编译通过；2 个保存样例、500 组独立逐次操作对拍与 70 位精度边界复核通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb80574ace1cba9a20d52)（复刻评测）。上一版代码曾获 [洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490746)；本版新增高低角度前缀修复，以本次曙梦复验为准。

### 题意

操作为围绕原点等比例缩放或逆时针旋转。每次查询一个连续操作区间作用于点后的坐标。操作和查询各至多$10^5$，缩放系数为正且任意区间乘积有界。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16055)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309B)。

### 题解

**先把一串操作合并成一次缩放、一次旋转。** 每次缩放都对两个坐标乘同一个正数，每次旋转都围绕原点，因此缩放与旋转的先后次序可以交换。若区间内缩放系数的乘积为 $k$、旋转角度之和为 $\theta$，结果就是

$$
\begin{aligned}
x'&=k(x\cos\theta-y\sin\theta),\\
y'&=k(x\sin\theta+y\cos\theta).
\end{aligned}
$$

于是可以预处理缩放前缀积 $P_i$ 和角度前缀和 $S_i$。对于查询 $[l,r]$，有 $k=P_r/P_{l-1}$、$\theta=S_r-S_{l-1}$，每次查询只需常数次计算。题目保证任意区间的缩放乘积在 $[0.001,1000]$ 内，不会出现除以零。

**角度必须保留输入的实数精度。** 题面没有规定角度只有三位小数，不能把角度乘 1000 后取整。比如将点 $(10^6,0)$ 旋转 $0.0001$ 弧度，纵坐标约为 100；把角度舍入成 0 会直接算错。

**还要避免两个大前缀相减时丢掉低位。** 当 $n$ 达到 $10^5$，角度前缀可能达到几十万。即使使用补偿求和，若每个前缀最终仍只存一个浮点数，保存时的舍入误差也会留下来。两份大前缀相减后，误差再被 $10^6$ 的坐标和 1000 倍缩放放大，可能超过题目允许的绝对误差 0.1。某些平台的 `long double` 与 `double` 都只有 53 位有效二进制位，不能只依赖类型名字判断精度。

本实现把每个角度前缀拆为两部分：`high` 保存常规求和结果，`low` 累积每次加法被舍入掉的误差，即 $S_i\approx H_i+L_i$。加入新角度 $v$ 时，先算 `next = high + v`；再根据两个加数的大小，用 Neumaier 补偿公式恢复这次加法的低位误差并累加到 `low`。

查询时也保留减法误差。先算 `difference = H_r - H_{l-1}`，再用补偿减法恢复该次相减丢掉的低位，并加上 $L_r-L_{l-1}$，得到 `residual`。所以区间角度表示为

$$\theta\approx\text{difference}+\text{residual}.$$

此时不要立刻把两部分相加，否则较小的 `residual` 可能再次被舍去。分别求出两部分的正弦、余弦，再用角度和公式合成：

$$
\begin{aligned}
\cos(a+b)&=\cos a\cos b-\sin a\sin b,\\
\sin(a+b)&=\sin a\cos b+\cos a\sin b.
\end{aligned}
$$

也不手工用近似的 $2\pi$ 常量对大角度取模，避免取模时将周期常量的误差放大；直接把高、低两部分交给标准库三角函数。最后代入最初的坐标变换公式即可。

**正确性。** 缩放可交换且系数相乘，旋转可合并且角度相加；前缀积相除与前缀和相减恰好提取查询区间。补偿表示只改变浮点计算方式，不改变区间角度的数学含义，角度和公式仍给出同一次旋转。因此得到的就是按原顺序执行全部区间操作后的坐标。浮点误差另用独立高精度回归检查，不能用数学推导替代数值验证。

**复杂度。** 预处理 $O(n)$，每次查询 $O(1)$，总时间 $O(n+m)$，空间 $O(n)$。

精度回归采用 70 位 Decimal 与独立 Taylor 三角函数。在 Apple Silicon 的 53 位 `long double` 环境，合法最大长度重复角度构造的误差由旧版约 0.175913 降至本版约 0.049876（要求不超过 0.1）；固定种子 5003 个长前缀查询的最大误差约为 0.000219。复核入口：[精度回归脚本](../tests/precision_regressions.py)、[精度报告](../tests/precision-report.json)。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct AngleSum {
    long double high = 0, low = 0;
    void add(long double value) {
        long double next = high + value;
        // Retain the rounding error instead of rounding the compensated total
        // back to a single floating-point value at every prefix.
        low += fabsl(high) >= fabsl(value) ? (high - next) + value : (value - next) + high;
        high = next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long double> scale(n + 1, 1);
    vector<AngleSum> angle(n + 1);
    for (int i = 1; i <= n; ++i) {
        int type;
        long double value;
        cin >> type >> value;
        scale[i] = scale[i - 1];
        angle[i] = angle[i - 1];
        if (type == 1)
            scale[i] *= value;
        else
            angle[i].add(value);
    }
    cout << fixed << setprecision(10);
    while (m--) {
        int i, j;
        long double x, y;
        cin >> i >> j >> x >> y;
        long double a = angle[j].high, b = angle[i - 1].high;
        long double difference = a - b;
        long double virtualB = a - difference;
        long double residual = (a - (difference + virtualB)) + (virtualB - b);
        residual += angle[j].low - angle[i - 1].low;
        // Evaluate the high/low parts separately. Do not reduce a large angle
        // with a rounded 2*pi constant, or add the small residual back too early.
        long double c = cosl(difference), s = sinl(difference);
        long double dc = cosl(residual), ds = sinl(residual);
        long double cosine = c * dc - s * ds, sine = s * dc + c * ds;
        long double factor = scale[j] / scale[i - 1];
        cout << factor * (x * cosine - y * sine) << ' '
             << factor * (x * sine + y * cosine) << '\n';
    }
}
```

<a id="problem-c"></a>

## C. 梯度求解

标签：`自动微分` · `表达式` · `栈`

状态：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定由整数、变量 x1…xn 和加减乘构成的后缀表达式。每次给出所有变量的值及一个变量编号，求表达式对该变量的偏导数模 $10^9+7$。表达式至多 120 个操作数／运算符，n、查询数均不超过 100。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16056)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309C)。

### 题解

求导和求值可以一起做。栈中每项保存 `(当前值,当前导数)`：常数导数为 0，当前求导变量的导数为 1，其余变量导数为 0。遇到运算符弹出右、左操作数，分别按加法、减法和乘积求导公式合并。乘法产生 `(uv,u'v+uv')`，不能只把两个导数相乘。

后缀表达式的每个运算符前，其两个完整子表达式已经入栈。对表达式树归纳，二元组的两部分分别等于子表达式值和偏导数，因此最终栈顶就是答案。每一步取模；负常数、减法结果都规范到非负余数。每次查询时间 $O(L+n)$、空间 $O(L+n)$，L 为表达式长度。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll norm(ll x) {
    return (x % MOD + MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string line, t;
    getline(cin, line);
    getline(cin, line);
    istringstream in(line);
    vector<string> tokens;
    while (in >> t)
        tokens.push_back(t);
    while (m--) {
        int var;
        cin >> var;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = norm(a[i]);
        }
        vector<pair<ll, ll>> st;
        for (auto &s : tokens) {
            if (s == "+" || s == "-" || s == "*") {
                auto [v, d] = st.back();
                st.pop_back();
                auto [u, c] = st.back();
                st.pop_back();
                if (s == "+")
                    st.push_back({(u + v) % MOD, (c + d) % MOD});
                else if (s == "-")
                    st.push_back({norm(u - v), norm(c - d)});
                else
                    st.push_back({u * v % MOD, (c * v + u * d) % MOD});
            } else if (s[0] == 'x') {
                int id = stoi(s.substr(1));
                st.push_back({a[id], id == var});
            } else
                st.push_back({norm(stoll(s)), 0});
        }
        cout << st.back().second << '\n';
    }
}
```

<a id="problem-d"></a>

## D. 阴阳龙

标签：`有序集合` · `几何` · `模拟`

状态：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例、700 组独立随机对拍、255 种八方向占位掩码与 6 组 p=q=100000 上界测试通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addfd5374ace1cba9a2324b)（民间复刻评测）。

### 题意

在 $n\times m$ 网格中有 $p$ 名位置互异的员工。事件 $(u,v,t)$ 从中心向右、右上、上、左上、左、左下、下、右下观察，找到这八条射线上最近员工的距离 $k$，不考虑中心员工；但 $k$ 还必须满足八个方向走 $k$ 步均未越界，否则本次不动。把恰在这八个距离为 $k$ 的位置上的员工同时逆时针轮转 $t$ 个方向。处理 $q$ 次事件后输出 $\bigoplus_{i=1}^p(i x_i+y_i)$。$n,m\le10^9,p,q\le10^5$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16057)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309D)。

### 题解

#### 1. 八个方向对应四种直线

一个点的八条射线可以分为四条直线：

| 直线 | 直线编号 | 线上排序坐标 | 坐标增大的方向 |
| --- | --- | --- | --- |
| 水平 | `y` | `x` | 右 |
| 竖直 | `x` | `y` | 上 |
| 斜率为 1 | `x-y` | `x` | 右上 |
| 斜率为 -1 | `x+y` | `x` | 右下 |

分别建立四个有序集合，按“直线编号、线上坐标”排序。查询中心时，取同一直线上的严格前驱和严格后继，就得到八个方向各自最近的员工。要跳过恰好位于中心的员工；前驱或后继若属于另一条直线，也不能采用。

八个方向都不越界的最大距离为

$$b=\min(u-1,n-u,v-1,m-v).$$

若八个候选距离的最小值超过 `b`，本次事件不产生移动。否则这个最小值就是 `k`，所有距离恰好为 `k` 的候选员工都参加轮转。由于已经获得候选所在的槽位，不必再用坐标哈希表查一次人。

#### 2. 把“哪个位置有人”与“这个人是谁”分开

容易想到的实现是：把参加轮转的最多 8 名员工全部从四个集合删除，移动后再全部插入。但是，轮转后仍有人占据的位置，其几何索引其实没有变化。

因此我们为每个当前占用的位置建立一个**槽位**，槽位记录：

- 当前坐标；
- 当前在该位置的员工编号；
- 该位置在四个有序集合中的迭代器。

槽位编号不等于员工编号。旋转只改变员工编号的分布；只有占用位置发生变化时才需要改动有序集合。

设轮转前八个位置中有人占用的集合为 `A`，将其方向整体平移 `t` 后得到新的占用集合 `B`。先保存每个目标方向应该收到哪个员工，再统一更新：

1. `A` 与 `B` 的公共位置：坐标保持原样，只更换槽位中的员工编号。
2. `A` 中有、`B` 中没有的位置：槽位被腾空。
3. `B` 中有、`A` 中没有的位置：把腾出的槽位搬到这些新位置，并填入对应员工编号。

因为 `|A|=|B|`，腾出和新建的位置数相等。更进一步，它们都不超过 4：若总共有 `s` 个员工参与，腾出数量至多是 `min(s,8-s)`。当八个位置全有人时，几何索引完全不用修改，只交换员工编号即可。

这一步同时避免了覆盖问题：必须先保存所有目标员工编号，再更改任何槽位，不能一边读取旧编号一边写入新编号。

#### 3. 复用树节点，避免反复分配

每个需要迁移的槽位在四个集合中各有一个节点。代码用 C++17 的 `set::extract` 根据已保存的迭代器取出节点，改写排序键，再通过 `insert` 放回。

节点先脱离集合后才能改键，否则会破坏有序集合的顺序。所有待迁移槽位先统一取出，再统一放入新坐标；不需要申请和释放新的树节点。未迁移槽位的迭代器仍然有效。

排序键用一个 64 位无符号整数编码。因为线上坐标小于 `2^30`，可以用

```text
key = (直线编号 << 30) | 线上坐标
```

斜率为 1 的直线编号 `x-y` 可能为负，统一加上 `10^9` 后再编码。其他编号以及平移后的编号均小于 `2^31`，总共只需 61 位。这样保留与二元组相同的字典序，又减少每次树比较的工作。

#### 4. 正确性与复杂度

同一直线严格前驱、后继分别是该方向的最近员工，因此四棵树能准确求出八方向的候选和本次最小合法距离。占用集合 `A` 经过方向偏移得到 `B`，每个目标位置的员工由原题轮转规则唯一确定；公共位置只改编号，其他位置通过槽位迁移补齐，所以几何状态和员工身份都与同时移动一致。

初始化需要 `O(p log p)`，每次事件进行四次前驱/后继搜索，并至多迁移 4 个槽位，最坏 `O(log p)`，总复杂度为 `O((p+q) log p)`，空间为 `O(p)`。最终遍历所有槽位，用槽位保存的**员工编号**计算异或和；乘法使用 `long long`。

本版本地验证：1 个保存样例、700 组独立随机对拍、255 种八方向占位掩码与 6 组 p=q=100000 上界测试通过。完整测试配置和同机基准见 [回归报告](../tests/yin_yang_dragon-report.json)。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <set>
#include <utility>
#include <vector>
using namespace std;

class FastInput {
    static constexpr int SIZE = 1 << 16;
    char buffer[SIZE];
    int pos = 0, length = 0;
    int get() {
        if (pos == length) {
            length = int(fread(buffer, 1, SIZE, stdin));
            pos = 0;
            if (!length) return EOF;
        }
        return buffer[pos++];
    }
public:
    int read() {
        int c = get(), value = 0;
        while (c <= ' ' && c != EOF) c = get();
        while (c >= '0' && c <= '9') {
            value = value * 10 + c - '0';
            c = get();
        }
        return value;
    }
};

constexpr uint64_t MASK = (uint64_t(1) << 30) - 1;
struct Entry {
    uint64_t key;
    int slot;
    bool operator<(const Entry &other) const { return key < other.key; }
};
using Tree = set<Entry>;
struct Slot {
    int x, y, employee;
    array<Tree::iterator, 4> at;
};
array<uint64_t, 4> keys(int x, int y) {
    return {(uint64_t(y) << 30) | uint32_t(x),
            (uint64_t(x) << 30) | uint32_t(y),
            (uint64_t(x - y + 1000000000) << 30) | uint32_t(x),
            (uint64_t(x + y) << 30) | uint32_t(x)};
}

int main() {
    FastInput in;
    int n = in.read(), m = in.read(), p = in.read(), q = in.read();
    vector<Slot> slots(p + 1);
    array<Tree, 4> lines;
    for (int i = 1; i <= p; ++i) {
        Slot &slot = slots[i];
        slot.x = in.read(); slot.y = in.read(); slot.employee = i;
        auto key = keys(slot.x, slot.y);
        for (int j = 0; j < 4; ++j)
            slot.at[j] = lines[j].insert({key[j], i}).first;
    }
    const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int positiveDirection[4] = {0, 2, 1, 7};
    while (q--) {
        int u = in.read(), v = in.read(), t = in.read();
        int boundary = min({u - 1, n - u, v - 1, m - v});
        if (!boundary) continue;
        int distance = boundary + 1;
        int nearest[8] = {}, distances[8] = {};
        auto key = keys(u, v);
        for (int j = 0; j < 4; ++j) {
            auto after = lines[j].upper_bound({key[j], 0});
            auto accept = [&](Tree::iterator it, int direction) {
                if ((it->key >> 30) != (key[j] >> 30)) return;
                int delta = int(it->key & MASK) - int(key[j] & MASK);
                if (delta < 0) delta = -delta;
                nearest[direction] = it->slot;
                distances[direction] = delta;
                distance = min(distance, delta);
            };
            if (after != lines[j].end()) accept(after, positiveDirection[j]);
            if (after != lines[j].begin()) {
                auto before = prev(after);
                if (before->key == key[j]) {
                    if (before == lines[j].begin()) continue;
                    --before;
                }
                accept(before, (positiveDirection[j] + 4) & 7);
            }
        }
        if (distance > boundary) continue;

        int occupied[8] = {}, destinationEmployee[8] = {};
        for (int d = 0; d < 8; ++d) {
            if (nearest[d] && distances[d] == distance) {
                occupied[d] = nearest[d];
                destinationEmployee[(d + t) & 7] = slots[nearest[d]].employee;
            }
        }
        int vacated[4], targets[4], count = 0, targetCount = 0;
        for (int d = 0; d < 8; ++d) {
            if (occupied[d] && destinationEmployee[d]) {
                // The position stays occupied: only its employee label changes.
                slots[occupied[d]].employee = destinationEmployee[d];
            } else if (occupied[d]) {
                vacated[count++] = occupied[d];
            } else if (destinationEmployee[d]) {
                targets[targetCount++] = d;
            }
        }
        // Two subsets of an 8-element set with equal cardinality differ in
        // at most 4 positions on each side. Reuse the vacated position slots.
        array<array<Tree::node_type, 4>, 4> detached;
        for (int i = 0; i < count; ++i)
            for (int j = 0; j < 4; ++j)
                detached[i][j] = lines[j].extract(slots[vacated[i]].at[j]);
        for (int i = 0; i < count; ++i) {
            int id = vacated[i], d = targets[i];
            Slot &slot = slots[id];
            slot.x = u + distance * dx[d];
            slot.y = v + distance * dy[d];
            slot.employee = destinationEmployee[d];
            auto newKey = keys(slot.x, slot.y);
            for (int j = 0; j < 4; ++j) {
                detached[i][j].value().key = newKey[j];
                slot.at[j] = lines[j].insert(std::move(detached[i][j])).position;
            }
        }
    }
    long long answer = 0;
    for (int i = 1; i <= p; ++i)
        answer ^= 1LL * slots[i].employee * slots[i].x + slots[i].y;
    printf("%lld\n", answer);
}
```

<a id="problem-e"></a>

## E. 阻击

标签：`动态树` · `树的直径` · `动态规划`

状态：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

一棵树的每条边有宝物收益 $w_e$ 和阻击损失 $b_e$。选择两个城市，允许相同，敌军沿它们之间的简单路径行动，总损失为 $\sum(b_e-w_e)$。先输出初始最大总损失，再处理 $m$ 次把指定边的 $w_e$ 改成新值的操作，每次输出新的最优值。输入 `n m`，随后 $n-1$ 行 `u v w b`、$m$ 行 `边编号 新w`。$n,m\le10^5$，单项权值不超过 $10^9$。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16058)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309E)。

### 题解

**先认出真正维护的量。** 令边权 $c_e=b_e-w_e$，题目变成允许负边的动态树直径。负边破坏了“两次找最远点”的常用结论，不能直接套正权直径算法。

把每条边拆成一个权值为 $c_e$ 的新点，原城市的点权为 0，边修改变成点修改。拆边点的度为 2；一条路径即使在拆边点结束，也能延伸到相邻的零权城市而不降低值，所以最大点权路径与原问题等价。

**维护一条实链和挂在它上面的虚子树。** 使用 Link-Cut Tree。每个链段记录四个量：`sum` 为实链点权和；`first` 为从左端出发、可进入一棵虚子树的最大路径；`last` 对称；`best` 为整个链段及其虚子树内的最大路径。合并相邻段 $A,B$：

$$sum=sum_A+sum_B,$$
$$first=\max(first_A,sum_A+first_B),\quad last=\max(last_B,sum_B+last_A),$$
$$best=\max(best_A,best_B,last_A+first_B).$$

对于单个实链点 $u$，用两个多重集合保存各虚孩子的 `first` 与 `best`。设最大的两个非负虚分支贡献为 $a,b$，则局部状态是 $(w_u,w_u+a,w_u+a,\max(\text{虚子树best},w_u+a+b))$。注意 `sum` 只包含链上点权，不能把旁支算进去。

`access` 改变实虚边时，把旧实右子树加入集合，把新实右子树从集合删除；集合必须按一次出现删除，不能把同值贡献全部删掉。修改前先 `access`，才能确保祖先保存的虚信息仍与旧值一致。最后把城市 1 作为根，查询整树 `best`，再与 0 取最大值，涵盖起终点相同的选择。

**正确性。** 最优路径要么完全位于一个孩子结构内，要么经过当前连接点，至多使用两个分支；上述分类正好被局部状态和链合并式覆盖。**复杂度：** 多重集合让一次修改摊还 $O(\log^2 n)$，空间 $O(n)$。这份实现比只支持正权的直径模板通用，但需要先理解 Splay、实虚边与路径 DP。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
const ll NEG = -(1LL << 60);
struct Summary {
    ll sum = 0, first = NEG, last = NEG, best = NEG;
};
Summary join(Summary a, Summary b) {
    return {a.sum + b.sum, max(a.first, a.sum + b.first), max(b.last, b.sum + a.last),
            max({a.best, b.best, a.last + b.first})};
}
struct DynamicTree {
    struct Node {
        int child[2]{}, parent = 0;
        bool reverse = false;
        ll weight = 0;
        multiset<ll> sideFirst, sideBest;
        Summary data;
    };
    vector<Node> t;
    vector<int> path;
    explicit DynamicTree(int n) : t(n + 1) {
        path.reserve(n);
    }
    bool auxiliaryRoot(int u) {
        int p = t[u].parent;
        return t[p].child[0] != u && t[p].child[1] != u;
    }
    Summary local(int u) {
        ll first = 0, second = 0;
        auto it = t[u].sideFirst.rbegin();
        if (it != t[u].sideFirst.rend()) {
            first = max(0LL, *it);
            ++it;
        }
        if (it != t[u].sideFirst.rend())
            second = max(0LL, *it);
        ll w = t[u].weight, b = t[u].sideBest.empty() ? NEG : *t[u].sideBest.rbegin();
        return {w, w + first, w + first, max(b, w + first + second)};
    }
    void pull(int u) {
        t[u].data = join(join(t[t[u].child[0]].data, local(u)), t[t[u].child[1]].data);
    }
    void flip(int u) {
        if (!u)
            return;
        swap(t[u].child[0], t[u].child[1]);
        swap(t[u].data.first, t[u].data.last);
        t[u].reverse ^= 1;
    }
    void push(int u) {
        if (t[u].reverse) {
            flip(t[u].child[0]);
            flip(t[u].child[1]);
            t[u].reverse = false;
        }
    }
    void rotate(int u) {
        int p = t[u].parent, g = t[p].parent, d = t[p].child[1] == u, v = t[u].child[d ^ 1];
        if (!auxiliaryRoot(p))
            t[g].child[t[g].child[1] == p] = u;
        t[u].parent = g;
        t[u].child[d ^ 1] = p;
        t[p].parent = u;
        t[p].child[d] = v;
        if (v)
            t[v].parent = p;
        pull(p);
        pull(u);
    }
    void splay(int u) {
        path.clear();
        int v = u;
        path.push_back(v);
        while (!auxiliaryRoot(v)) {
            v = t[v].parent;
            path.push_back(v);
        }
        for (auto it = path.rbegin(); it != path.rend(); ++it)
            push(*it);
        while (!auxiliaryRoot(u)) {
            int p = t[u].parent, g = t[p].parent;
            if (!auxiliaryRoot(p))
                rotate((t[p].child[1] == u) == (t[g].child[1] == p) ? p : u);
            rotate(u);
        }
    }
    void virtualAdd(int u, int v) {
        if (!v)
            return;
        t[u].sideFirst.insert(t[v].data.first);
        t[u].sideBest.insert(t[v].data.best);
    }
    void virtualRemove(int u, int v) {
        if (!v)
            return;
        t[u].sideFirst.erase(t[u].sideFirst.find(t[v].data.first));
        auto it = t[u].sideBest.find(t[v].data.best);
        t[u].sideBest.erase(it);
    }
    void access(int u) {
        for (int v = 0, x = u; x; v = x, x = t[x].parent) {
            splay(x);
            virtualAdd(x, t[x].child[1]);
            virtualRemove(x, v);
            t[x].child[1] = v;
            pull(x);
        }
        splay(u);
    }
    void makeRoot(int u) {
        access(u);
        flip(u);
    }
    void link(int u, int v) {
        makeRoot(u);
        access(v);
        t[u].parent = v;
        virtualAdd(v, u);
        pull(v);
    }
    void cut(int u, int v) {
        makeRoot(u);
        access(v);
        t[v].child[0] = 0;
        t[u].parent = 0;
        pull(v);
    }
    void setWeight(int u, ll w) {
        access(u);
        t[u].weight = w;
        pull(u);
    }
    ll rootedValue(int root) {
        makeRoot(root);
        access(root);
        return local(root).first;
    }
    ll subtreeBest(int root, int u) {
        makeRoot(root);
        access(u);
        return local(u).best;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DynamicTree dt(2 * n);
    vector<long long> loss(n);
    for (int i = 1; i <= n; ++i)
        dt.pull(i);
    for (int i = 1; i < n; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w >> loss[i];
        int node = n + i;
        dt.t[node].weight = loss[i] - w;
        dt.pull(node);
        dt.link(u, node);
        dt.link(node, v);
    }
    cout << max(0LL, dt.subtreeBest(1, 1)) << '\n';
    while (m--) {
        int edge;
        long long value;
        cin >> edge >> value;
        dt.setWeight(n + edge, loss[edge] - value);
        cout << max(0LL, dt.subtreeBest(1, 1)) << '\n';
    }
}
```
