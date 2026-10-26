---
title: "CSP 202303 五题题解"
contest: "202303"
contest_month: "2023-03"
date: "2026-10-23"
updated: "2026-10-26"
tags: ["CSP", "矩形相交", "几何", "二分答案", "单调性", "递归下降", "位集", "离线处理", "排序", "离散化", "线段树", "区间赋值", "分治", "树状数组", "区间计数"]
status: "published"
problems: [{"id": "A", "title": "田地丈量", "tags": ["矩形相交", "几何"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16694"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce918a67df0b81749c020"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305927066", "source_sha256": "34b442118b93a1609b689159910d0d67586cba362236d1513d8dfa5042ff4ef7"}}, {"id": "B", "title": "垦田计划", "tags": ["二分答案", "单调性"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16695"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91aa67df0b81749c02a"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305933793", "source_sha256": "cf5d32583c21adaa802cb829eaaddaba3128a3efc71b191734543ac88b6ab990"}}, {"id": "C", "title": "LDAP", "tags": ["递归下降", "位集", "离线处理", "排序"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "C++17 编译通过；1 个保存样例、600 组独立用户表达式对拍与 6 组上界测试通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16696"}], "previous_oj": {"status": "failed", "score": 70, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6addcb0574ace1cba9a21e46", "source_sha256": "05bb5a6be5154299b2db3bf8e7049de301197cc4aff1bf9bb7b4f3864f4e56e9", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490926", "source_sha256": "05bb5a6be5154299b2db3bf8e7049de301197cc4aff1bf9bb7b4f3864f4e56e9", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addfdea74ace1cba9a232ef", "source_sha256": "75f7d125f11603033f3a14745b88e080f636c946a66abd7100c836d2d7c933bb"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305934606", "source_sha256": "75f7d125f11603033f3a14745b88e080f636c946a66abd7100c836d2d7c933bb"}}, {"id": "D", "title": "星际网络 II", "tags": ["离散化", "线段树", "区间赋值"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16697"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91da67df0b81749c032"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305935489", "source_sha256": "91e3edd94753f6dc16b11f6eb2612a2bd740c13e14ebeb6e1cf4a93ae2a20363"}}, {"id": "E", "title": "施肥", "tags": ["分治", "线段树", "树状数组", "区间计数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16698"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91ea67df0b81749c036"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305936519", "source_sha256": "33d8956583e622b00cecc81c91baa224e566b1a7194a1fe3258ac41d90141fd2"}}]
---

# CSP 202303 五题题解

[返回总目录](../README.md)

本场已实现 **5/5** 题。每题依次给出题意、题解、代码。源码使用 C++17。

<a id="problem-a"></a>

## A. 田地丈量

标签：`矩形相交` · `几何`

状态：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce918a67df0b81749c020)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305927066)（民间复刻评测）。

### 题意

已有若干内部互不相交的轴对齐田地，求它们落在目标矩形[0,a]×[0,b]内的总面积。坐标可为负。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16694)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303A)。

### 题解

对每块田地求与目标矩形的交集：横向长度为max(0,min(x2,a)-max(x1,0))，纵向同理，两者相乘后累加。

两个矩形的公共横纵区间的笛卡尔积就是交集；相离或仅边界接触时长度为0。已有田地内部互不重叠，所以交集面积可直接相加，无需计算复杂矩形并。时间 $O(n)$，空间 $O(1)$，面积采用64位。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    long long a, b, answer = 0;
    cin >> n >> a >> b;
    while (n--) {
        long long x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        answer += max(0LL, min(a, xx) - max(0LL, x)) * max(0LL, min(b, yy) - max(0LL, y));
    }
    cout << answer << '\n';
}
```

<a id="problem-b"></a>

## B. 垦田计划

标签：`二分答案` · `单调性`

状态：**完整实现，已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce91aa67df0b81749c02a)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305933793)（民间复刻评测）。

### 题意

n 块田同时开垦，第 i 块原耗时 t[i]，每缩短一天花 c[i] 资源，最短均为 k 天。共有 m 资源，求总完成时间的最小值。n、t[i]、c[i]≤$10^5$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16695)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303B)。

### 题解

判断能否在 T 天完成：每块超过 T 的田至少要缩短 t[i]-T 天，因此最少花费为 `Σ max(0,t[i]-T)*c[i]`。总花费≤m 就可行。

T 越大，所需资源只会减少，所以在 [k,max(t)] 二分第一个可行时间。判定的花费既是必要下界，也可通过恰好缩短相应天数实现，故单调判定充分必要。时间 $O(n\log\max t)$，空间 $O(n)$，总成本可达$10^{15}$，用64位。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    long long m;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    int hi = k;
    for (auto &[t, c] : a) {
        cin >> t >> c;
        hi = max(hi, t);
    }
    int lo = k;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        long long need = 0;
        for (auto [t, c] : a)
            if (t > mid)
                need += 1LL * (t - mid) * c;
        if (need <= m)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << '\n';
}
```

<a id="problem-c"></a>

## C. LDAP

标签：`递归下降` · `位集` · `离线处理` · `排序`

状态：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例、600 组独立用户表达式对拍与 6 组上界测试通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addfdea74ace1cba9a232ef)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305934606)（民间复刻评测）。

### 题意

每个用户有唯一 DN 及若干整数属性。表达式 `a:b` 匹配具有属性 a 且值等于 b 的用户，`a~b` 匹配具有该属性且值不等于 b 的用户；`&(E1)(E2)`、`|(E1)(E2)` 表示交和并。每次输出匹配 DN 的升序列表，可以为空行。用户至多 2500，查询至多 500，表达式长度至多 2000。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16696)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303C)。

### 题解

#### 1. 用一个位集表示一批匹配用户

给用户按输入顺序编号 `0..n-1`。一个 `bitset<2500>` 就能表示一批用户：第 `i` 位为 1，表示用户 `i` 匹配。这样，逻辑与对应位集的 `&`，逻辑或对应 `|`。

关键是原子表达式。对于属性 `a`，记 `exists[a]` 为具有该属性的用户集合；对于属性与值的组合 `(a,b)`，记 `equals[a,b]` 为属性值等于 `b` 的用户集合。则

$$a:b\quad\longrightarrow\quad equals[a,b],$$

$$a\mathbin{\sim}b\quad\longrightarrow\quad exists[a]\ \&\ \sim equals[a,b].$$

反断言不能直接把相等集合取反：没有属性 `a` 的用户也不应匹配。必须再与 `exists[a]` 求交集。

#### 2. 只给查询实际用到的属性和值建位集

用户数据最多有 `2500 × 500 = 1250000` 条属性记录。若给每条不同的属性值组合都建一个完整位集，会浪费不少空间；反过来，若每次原子查询都重新扫描该属性的用户，又会在长表达式中重复工作。

本题没有在线修改，所有表达式都可以先读入。因此先扫描全部表达式，收集其中出现的 `(属性,值)`，排序并去重；再从中得到实际需要查询的属性列表。

对于收集到的组合分配 `equals` 位集，对于收集到的属性分配 `exists` 位集。用户数据中没有被表达式使用的属性不需要位集；某个被查询的组合没有出现在任何用户身上时，它的相等位集自然全为 0。

每条表达式最多约 250 个原子，500 条表达式最多约 125000 个原子。因此即使都不同，位集数量也受查询总长度约束，而不会随着全部用户属性记录数无限增长。

#### 3. 排序后一次构建索引

读入用户时，把每条属性保存为 `(属性,值,用户下标)` 的扁平记录。代码用

```text
key = (uint64_t(属性) << 32) | 值
```

编码属性和值；两者均不超过 `10^9`，编码不会冲突，整数顺序也等于先比较属性、再比较值的顺序。

把用户记录按 `key` 排序后，与已排序的查询组合列表、查询属性列表一起用双指针扫描：

- 若记录的属性是需要查询的属性，把该用户加入相应 `exists`。
- 若记录的完整 `key` 是需要查询的组合，把该用户加入相应 `equals`。

这样每条记录只在建索引时处理一次。无需为百万个不同属性建立各自的小容器，也不会让每次反断言扫描该属性下的全部用户。索引建好后，原始记录可以释放。

#### 4. 递归下降解析完整表达式

维护一个指向表达式当前字符的位置：

1. 遇到数字，读出属性、操作符和值，在排序后的组合列表中二分找到对应位集，按前面的公式返回结果。
2. 遇到 `&` 或 `|`，依次解析两个括号里的完整表达式，再对返回的位集求交或求并。

即使左子表达式的结果已经为空，也要正确读完右子表达式，保证解析位置没有错位。代码没有使用可能跳过解析分支的逻辑短路。

最后预先把用户按 DN 排序，逐个查看结果位集中的用户下标，再按顺序输出 DN。DN 和输入下标是两种不同编号，不能混用。

#### 5. 正确性与复杂度

`exists` 和 `equals` 由用户原始记录直接构建，所以两个原子表达式的位集准确符合题意。组合表达式又分别取两个子结果的交集或并集，对表达式树作结构归纳即可得到整个结果正确。

设属性记录总数为 `P`，不同查询组合数为 `K`，被查询的不同属性数为 `H`，所有表达式的总原子数为 `A`，总字符数为 `L`；位集占用 `W` 个机器字，当前上限为 `ceil(2500/64)=40`。

- 排序和构建索引需要 `O(P log P + K log K + (K+H)W)`，排序后的合并扫描为 `O(P+K+H)`。
- 解析与求值需要 `O(L + A(log K+W))`。
- 输出前扫描用户需要 `O(mn)`，另计实际输出字符量。
- 空间为 `O(P + (K+H)W + L)`，以及递归解析的临时位集。按题目上限，最保守的位集和属性记录总量也在 512 MiB 限制内。

实现使用缓冲输入输出，避免大量属性数字及结果 DN 的输入输出成为新的耗时来源。

本版本地验证：1 个保存样例、600 组独立用户表达式对拍与 6 组上界测试通过。完整测试配置和同机基准见 [回归报告](../tests/ldap-report.json)。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using Bits = bitset<2500>;

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
        int c = get(), value = 0;
        while (c <= ' ' && c != EOF) c = get();
        while (c >= '0' && c <= '9') {
            value = value * 10 + c - '0';
            c = get();
        }
        return value;
    }
    string word() {
        string result;
        int c = get();
        while (c <= ' ' && c != EOF) c = get();
        while (c > ' ') {
            result.push_back(char(c));
            c = get();
        }
        return result;
    }
    void flush() {
        fwrite(output, 1, used, stdout);
        used = 0;
    }
    void put(char c) {
        if (used == SIZE) flush();
        output[used++] = c;
    }
    void write(int value) {
        char digits[10];
        int count = 0;
        do {
            digits[count++] = char('0' + value % 10);
            value /= 10;
        } while (value);
        while (count) put(digits[--count]);
    }
};

uint64_t encode(int attribute, int value) {
    return (uint64_t(attribute) << 32) | uint32_t(value);
}
int number(const string &text, size_t &pos) {
    int value = 0;
    while (pos < text.size() && text[pos] >= '0' && text[pos] <= '9')
        value = value * 10 + text[pos++] - '0';
    return value;
}
struct Record {
    uint64_t key;
    int user;
};

class Evaluator {
    const vector<uint64_t> &keys;
    const vector<int> &attributeOf;
    const vector<Bits> &equals, &exists;
public:
    Evaluator(const vector<uint64_t> &k, const vector<int> &a,
              const vector<Bits> &e, const vector<Bits> &h)
        : keys(k), attributeOf(a), equals(e), exists(h) {}
    Bits parse(const string &text, size_t &pos) const {
        if (text[pos] == '&' || text[pos] == '|') {
            char op = text[pos++];
            ++pos; // '('
            Bits left = parse(text, pos);
            pos += 2; // ')('
            Bits right = parse(text, pos);
            ++pos; // ')'
            return op == '&' ? left & right : left | right;
        }
        int attribute = number(text, pos);
        char op = text[pos++];
        int value = number(text, pos);
        size_t index = lower_bound(keys.begin(), keys.end(), encode(attribute, value)) - keys.begin();
        if (op == ':') return equals[index];
        // A missing attribute never satisfies either assertion form.
        return exists[attributeOf[index]] & ~equals[index];
    }
};

int main() {
    FastIO io;
    int n = io.read();
    vector<pair<int, int>> dn;
    vector<Record> records;
    records.reserve(n * 500);
    for (int i = 0; i < n; ++i) {
        int id = io.read(), count = io.read();
        dn.push_back({id, i});
        while (count--) {
            int attribute = io.read(), value = io.read();
            records.push_back({encode(attribute, value), i});
        }
    }
    int m = io.read();
    vector<string> expressions(m);
    vector<uint64_t> keys;
    for (string &text : expressions) {
        text = io.word();
        for (size_t pos = 0; pos < text.size();) {
            if (text[pos] >= '0' && text[pos] <= '9') {
                int attribute = number(text, pos);
                ++pos; // ':' or '~'
                int value = number(text, pos);
                keys.push_back(encode(attribute, value));
            } else {
                ++pos;
            }
        }
    }
    sort(keys.begin(), keys.end());
    keys.erase(unique(keys.begin(), keys.end()), keys.end());
    vector<int> attributes, attributeOf;
    for (uint64_t key : keys) {
        int attribute = int(key >> 32);
        if (attributes.empty() || attributes.back() != attribute)
            attributes.push_back(attribute);
        attributeOf.push_back(int(attributes.size()) - 1);
    }
    vector<Bits> equals(keys.size()), exists(attributes.size());
    sort(records.begin(), records.end(), [](const Record &a, const Record &b) {
        return a.key < b.key;
    });
    size_t keyIndex = 0, attributeIndex = 0;
    for (const Record &record : records) {
        int attribute = int(record.key >> 32);
        while (attributeIndex < attributes.size() && attributes[attributeIndex] < attribute)
            ++attributeIndex;
        if (attributeIndex < attributes.size() && attributes[attributeIndex] == attribute)
            exists[attributeIndex].set(record.user);
        while (keyIndex < keys.size() && keys[keyIndex] < record.key)
            ++keyIndex;
        if (keyIndex < keys.size() && keys[keyIndex] == record.key)
            equals[keyIndex].set(record.user);
    }
    vector<Record>().swap(records);
    sort(dn.begin(), dn.end());
    Evaluator evaluator(keys, attributeOf, equals, exists);
    for (const string &text : expressions) {
        size_t pos = 0;
        Bits answer = evaluator.parse(text, pos);
        bool first = true;
        for (auto [id, user] : dn) {
            if (!answer[user]) continue;
            if (!first) io.put(' ');
            io.write(id);
            first = false;
        }
        io.put('\n');
    }
}
```

<a id="problem-d"></a>

## D. 星际网络 II

标签：`离散化` · `线段树` · `区间赋值`

状态：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce91da67df0b81749c032)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305935489)（民间复刻评测）。

### 题意

管理最多 512 位二进制的地址，输入采用固定长度十六进制、每四位以冒号分隔。`1 id l r` 申请闭区间：不能含其他用户的地址，且必须至少有一个尚未分配地址，成功则全部归 id 并输出 YES，否则 NO。`2 s` 查询地址主人，未分配为 0；`3 l r` 查询是否整段都属于同一用户，是则输出编号，否则 0。操作数 $q\le5\times10^4$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16697)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303D)。

### 题解

**大整数只用于排序，不需要转换成整数。** 删除冒号后，所有地址等长，字典序就是数值顺序。在前面补一位 0，便能安全计算最大地址的后继，避免全为 f 时溢出。

把每个闭区间变成半开区间 $[l,r+1)$；点查询同样视为 $[s,s+1)$。先读完所有操作，收集这些边界并排序去重。相邻边界之间的所有地址永远一起被操作，因此可以压成一个叶子。不能仅压缩 l 和 r 而忽略它们之间可能存在的空白地址。

线段树维护区间内的最小主人编号、最大主人编号、最小正主人编号，并支持整段赋值。申请合法等价于：最小编号为 0（确有空闲），并且最大编号为 0，或所有正编号都等于申请者。查询同一主人时，只需最小编号等于最大编号。

这些统计量可以从左右孩子合并，赋值时直接重置；懒标记保证区间操作效率。离散化保留每次操作的完整边界，因此压缩前后的覆盖关系一致，合法性判断又与规则逐项等价。

设地址十六进制长度为 $L$，时间 $O(qL\log q+q\log q)$，空间 $O(qL+q)$。特别注意：同一用户重复申请自己已经完全持有的区间，也必须输出 NO。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
constexpr int INF = 1000000000;
struct Info {
    int low = 0, high = 0, positive = INF;
};
Info merge(Info a, Info b) {
    return {min(a.low, b.low), max(a.high, b.high), min(a.positive, b.positive)};
}
struct Node {
    Info info;
    int lazy = -1;
};
struct Operation {
    int type, id = 0;
    string left, right;
};
string address() {
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), ':'), s.end());
    return '0' + s;
}
string successor(string s) {
    const string digits = "0123456789abcdef";
    for (int i = int(s.size()) - 1; i >= 0; --i) {
        if (s[i] == 'f')
            s[i] = '0';
        else {
            s[i] = digits[digits.find(s[i]) + 1];
            break;
        }
    }
    return s;
}
vector<Node> tree;
void assign(int u, int value) {
    tree[u].info = {value, value, value ? value : INF};
    tree[u].lazy = value;
}
void push(int u) {
    if (tree[u].lazy != -1) {
        assign(u * 2, tree[u].lazy);
        assign(u * 2 + 1, tree[u].lazy);
        tree[u].lazy = -1;
    }
}
Info query(int u, int l, int r, int a, int b) {
    if (a <= l && r <= b)
        return tree[u].info;
    push(u);
    int mid = (l + r) / 2;
    if (b <= mid)
        return query(u * 2, l, mid, a, b);
    if (a > mid)
        return query(u * 2 + 1, mid + 1, r, a, b);
    return merge(query(u * 2, l, mid, a, b), query(u * 2 + 1, mid + 1, r, a, b));
}
void update(int u, int l, int r, int a, int b, int value) {
    if (a <= l && r <= b) {
        assign(u, value);
        return;
    }
    push(u);
    int mid = (l + r) / 2;
    if (a <= mid)
        update(u * 2, l, mid, a, b, value);
    if (b > mid)
        update(u * 2 + 1, mid + 1, r, a, b, value);
    tree[u].info = merge(tree[u * 2].info, tree[u * 2 + 1].info);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int bits, q;
    cin >> bits >> q;
    vector<Operation> ops(q);
    vector<string> coordinates;
    for (auto &op : ops) {
        cin >> op.type;
        if (op.type == 1)
            cin >> op.id;
        op.left = address();
        op.right = successor(op.type == 2 ? op.left : address());
        coordinates.push_back(op.left);
        coordinates.push_back(op.right);
    }
    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
    int n = int(coordinates.size()) - 1;
    tree.resize(4 * n + 4);
    for (auto &op : ops) {
        int l = lower_bound(coordinates.begin(), coordinates.end(), op.left) - coordinates.begin();
        int r = int(lower_bound(coordinates.begin(), coordinates.end(), op.right) -
                    coordinates.begin()) -
                1;
        Info value = query(1, 0, n - 1, l, r);
        if (op.type == 1) {
            bool possible = value.low == 0 &&
                            (value.high == 0 || (value.high == op.id && value.positive == op.id));
            cout << (possible ? "YES" : "NO") << '\n';
            if (possible)
                update(1, 0, n - 1, l, r, op.id);
        } else
            cout << (value.low == value.high ? value.low : 0) << '\n';
    }
}
```

<a id="problem-e"></a>

## E. 施肥

标签：`分治` · `线段树` · `树状数组` · `区间计数`

状态：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce91ea67df0b81749c036)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305936519)（民间复刻评测）。

### 题意

$n$ 块田地排成一行，每辆车只能完整覆盖给定闭区间 $[l_i,r_i]$，不能截断。统计多少个 $L<R$，使得能选择若干辆车，恰好覆盖 $[L,R]$，允许重叠，但不能漏田或覆盖范围外的田。输入 `n m` 以及 $m$ 个区间，$n,m\le2\times10^5$。注意田地是离散的：$[1,2]$ 与 $[3,4]$ 可以直接拼成 $[1,4]$。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16698)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303E)。

### 题解

**按答案区间跨越的位置分治。** 在 $[lo,hi]$ 中取中点 $mid$。完全在左边、完全在右边的答案递归计算；本层只数 $L\le mid<R$。把车辆区间分成左侧、右侧、跨中点三类。

对每个左端点 $L$，定义 $a_L$ 为只用左侧车辆、从 $L$ 开始能连续覆盖的最远位置；没有以 $L$ 为起点的覆盖时设为 $L-1$。倒序扫描 $L$：先取所有起点恰为 $L$ 的区间的最大右端点 $r$，再查询已算好的 $a_t$，其中 $L<t\le\min(mid,r+1)$，取最大值。一次查询即可：达到最大值的那条链已经包含了从该 $t$ 能继续拼接的全部车辆。线段树维护这些最大值。

若要通过一辆跨中点的车继续覆盖，它的左端点必须位于 $[L,a_L+1]$。在这些车中取最小右端点，记为 $b_L$。如果 $a_L=mid$，还可以完全不使用跨中点车辆，此时把 $mid+1$ 也作为候选 $b_L$。没有方案则为正无穷。

从右向左做完全对称的计算，得到 $a_R$（右侧能连续覆盖到的最左位置），以及 $b_R$（能接上的跨中点车辆的最大左端点）；若右侧本身覆盖到 $mid+1$，也允许 $b_R=mid$。

**关键判定：** $[L,R]$ 可覆盖，当且仅当 $b_L\le R$ 且 $L\le b_R$。必要性由一组覆盖中接通左右边界的第一、最后跨中点车辆得到。充分性是：左右两端分别有合法覆盖接到跨中点车辆；两辆跨中点车必定重叠。若两侧都靠相邻拼接接通，则它们在 $mid,mid+1$ 相邻，仍连续。若只有一侧不需要跨车，另一侧的跨车也能与它接上。

把所有 $L$ 按 $b_L$ 排序，按 $R$ 递增扫描，将 $b_L\le R$ 的左端点加入树状数组，查询不超过 $b_R$ 的数量即可。本层 $O((n+m)\log n)$，递归后总时间 $O((n+m)\log^2 n)$；实现保留各层临时数组，空间上界 $O((n+m)\log n)$。重复车辆不影响答案，单点区间不计入。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;
struct Range {
    int base, identity;
    bool minimum;
    vector<int> t;
    Range(int n, bool mn)
        : base(n), identity(mn ? 1000000000 : -1000000000), minimum(mn), t(2 * n, identity) {}
    int combine(int a, int b) {
        return minimum ? min(a, b) : max(a, b);
    }
    void put(int x, int v) {
        x += base;
        t[x] = combine(t[x], v);
        for (x >>= 1; x; x >>= 1)
            t[x] = combine(t[2 * x], t[2 * x + 1]);
    }
    int get(int l, int r) {
        if (l > r)
            return identity;
        int ans = identity;
        for (l += base, r += base + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans = combine(ans, t[l++]);
            if (r & 1)
                ans = combine(ans, t[--r]);
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> intervals(m);
    for (auto &a : intervals)
        cin >> a.first >> a.second;
    function<long long(int, int, vector<pair<int, int>>)> solve =
        [&](int lo, int hi, vector<pair<int, int>> items) -> long long {
        if (lo == hi || items.empty())
            return 0;
        int mid = (lo + hi) / 2, len = hi - lo + 1;
        vector<pair<int, int>> left, right, cross;
        vector<int> furthest(len), nearest(len);
        for (int i = lo; i <= hi; ++i) {
            furthest[i - lo] = i - 1;
            nearest[i - lo] = i + 1;
        }
        for (auto [l, r] : items) {
            if (r <= mid) {
                left.push_back({l, r});
                furthest[l - lo] = max(furthest[l - lo], r);
            } else if (l > mid) {
                right.push_back({l, r});
                nearest[r - lo] = min(nearest[r - lo], l);
            } else
                cross.push_back({l, r});
        }
        vector<int> needRight(mid - lo + 1), needLeft(hi - mid);
        {
            Range reach(len, false), ends(len, true);
            for (auto [l, r] : cross)
                ends.put(l - lo, r);
            for (int L = mid; L >= lo; --L) {
                int a = furthest[L - lo];
                a = max(a, reach.get(L + 1 - lo, min(mid, a + 1) - lo));
                reach.put(L - lo, a);
                int b = ends.get(L - lo, min(mid, a + 1) - lo);
                if (a == mid)
                    b = min(b, mid + 1);
                needRight[L - lo] = b;
            }
        }
        {
            Range reach(len, true), starts(len, false);
            for (auto [l, r] : cross)
                starts.put(r - lo, l);
            for (int R = mid + 1; R <= hi; ++R) {
                int a = nearest[R - lo];
                a = min(a, reach.get(max(mid + 1, a - 1) - lo, R - 1 - lo));
                reach.put(R - lo, a);
                int b = starts.get(max(mid + 1, a - 1) - lo, R - lo);
                if (a == mid + 1)
                    b = max(b, mid);
                needLeft[R - mid - 1] = b;
            }
        }
        vector<pair<int, int>> events;
        for (int L = lo; L <= mid; ++L)
            events.push_back({needRight[L - lo], L});
        sort(events.begin(), events.end());
        vector<int> bit(mid - lo + 2);
        size_t p = 0;
        long long answer = 0;
        for (int R = mid + 1; R <= hi; ++R) {
            while (p < events.size() && events[p].first <= R) {
                int x = events[p++].second - lo + 1;
                for (; x < int(bit.size()); x += x & -x)
                    ++bit[x];
            }
            int bound = min(mid, needLeft[R - mid - 1]);
            for (int x = bound - lo + 1; x > 0; x -= x & -x)
                answer += bit[x];
        }
        // Release this level's bulky lists before recursing.
        return answer + solve(lo, mid, std::move(left)) + solve(mid + 1, hi, std::move(right));
    };
    cout << solve(1, n, std::move(intervals)) << '\n';
}
```
