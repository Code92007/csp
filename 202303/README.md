---
title: "CSP 202303 五题题解"
contest: "202303"
contest_month: "2023-03"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "矩形相交", "几何", "二分答案", "单调性", "递归下降", "位集", "离线处理", "排序", "离散化", "线段树", "区间赋值", "分治", "树状数组", "区间计数"]
status: "published"
problems: [{"id": "A", "title": "田地丈量", "tags": ["矩形相交", "几何"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16694"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0564bde5d1fced2e451c23", "source_sha256": "38c9ef51ee2f3a55cf4f572ac78b6b61eeaef2be618b4d6ad4e8b4c028d60b9a", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:19:59.698790+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305927066", "source_sha256": "34b442118b93a1609b689159910d0d67586cba362236d1513d8dfa5042ff4ef7"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce918a67df0b81749c020"}}, {"id": "B", "title": "垦田计划", "tags": ["二分答案", "单调性"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16695"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b056519e5d1fced2e451c8b", "source_sha256": "74d9999e08c6ce5a64765fd7a25a0b3e8ef0d1ca9e00762c27b5ea4f59a62b01", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:21:32.701451+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305933793", "source_sha256": "cf5d32583c21adaa802cb829eaaddaba3128a3efc71b191734543ac88b6ab990"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91aa67df0b81749c02a"}}, {"id": "C", "title": "LDAP", "tags": ["递归下降", "位集", "离线处理", "排序"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16696"}], "previous_oj": {"status": "failed", "score": 70, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6addcb0574ace1cba9a21e46", "source_sha256": "05bb5a6be5154299b2db3bf8e7049de301197cc4aff1bf9bb7b4f3864f4e56e9", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490926", "source_sha256": "05bb5a6be5154299b2db3bf8e7049de301197cc4aff1bf9bb7b4f3864f4e56e9", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05812fe5d1fced2e454ffc", "source_sha256": "b7ab663741efaf5e3ca6d2f7a89891453be7399151021c214a9ab3262baae0ab", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:22:46.953040+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305934606", "source_sha256": "75f7d125f11603033f3a14745b88e080f636c946a66abd7100c836d2d7c933bb"}, "original_validation": "C++17 编译通过；1 个保存样例、600 组独立用户表达式对拍与 6 组上界测试通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addfdea74ace1cba9a232ef", "source_sha256": "75f7d125f11603033f3a14745b88e080f636c946a66abd7100c836d2d7c933bb"}}, {"id": "D", "title": "星际网络 II", "tags": ["离散化", "线段树", "区间赋值"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16697"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0581bbe5d1fced2e455238", "source_sha256": "d8c261b1711c863971ed5ddef82c35fc090c4c9747cfa34eac9a95d5ee6130d2", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:24:11.917218+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305935489", "source_sha256": "91e3edd94753f6dc16b11f6eb2612a2bd740c13e14ebeb6e1cf4a93ae2a20363"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91da67df0b81749c032"}}, {"id": "E", "title": "施肥", "tags": ["分治", "线段树", "树状数组", "区间计数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202303E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16698"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b058247e5d1fced2e455484", "source_sha256": "a24464b151f4e0eaee241f63faebff0c5e9ac2e90763ac3454e39cbb8abbe32b", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:26:38.922928+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305936519", "source_sha256": "33d8956583e622b00cecc81c91baa224e566b1a7194a1fe3258ac41d90141fd2"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce91ea67df0b81749c036"}}]
---

# CSP 202303 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202303/VALIDATION.md)


<a id="problem-a"></a>

## A. 田地丈量

标签：`矩形相交` · `几何`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202303/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce918a67df0b81749c020)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce918a67df0b81749c020)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305927066)（民间复刻评测）。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0564bde5d1fced2e451c23)。

<!-- refactor-online:A:end -->

### 题意

若干轴对齐田地的内部互不相交，求它们落在目标矩形 [0,a]×[0,b] 内的总面积。

输入田地数 n、目标边长 a、b，随后每块田地输入左下角与右上角坐标。坐标可以为负，原田地之间允许接触边界。

输出落在目标矩形内的面积之和。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16694)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303A)。

### 题解

对每块田地求与目标矩形的交集：横向长度为max(0,min(x2,a)-max(x1,0))，纵向同理，两者相乘后累加。

两个矩形的公共横纵区间的笛卡尔积就是交集；相离或仅边界接触时长度为0。已有田地内部互不重叠，所以交集面积可直接相加，无需计算复杂矩形并。时间 $O(n)$，空间 $O(1)$，面积采用64位。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a,b,ans,x,y,u,v;
int main(){
    scanf("%d%lld%lld",&n,&a,&b);
    while(n--){
        scanf("%lld%lld%lld%lld",&x,&y,&u,&v);
        ll w=max(0ll,min(a,u)-max(0ll,x));
        ll h=max(0ll,min(b,v)-max(0ll,y));
        ans+=w*h;
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 垦田计划

标签：`二分答案` · `单调性`

本地验证：103 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202303/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce91aa67df0b81749c02a)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce91aa67df0b81749c02a)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305933793)（民间复刻评测）。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b056519e5d1fced2e451c8b)。

<!-- refactor-online:B:end -->

### 题意

n 块田同时开垦，第 i 块原耗时 t[i]，每缩短一天花 c[i] 资源，最短均为 k 天。可用资源总量为 m，求全部田地完成的最短时间。

输入 n、m、k，随后每块田地输入 t[i]、c[i]。范围为 n、t[i]、c[i]≤$10^5$。

输出总完成时间的最小值。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16695)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303B)。

### 题解

判断能否在 T 天完成：每块超过 T 的田至少要缩短 t[i]-T 天，因此最少花费为 `Σ max(0,t[i]-T)*c[i]`。总花费≤m 就可行。

T 越大，所需资源只会减少，所以在 [k,max(t)] 二分第一个可行时间。判定的花费既是必要下界，也可通过恰好缩短相应天数实现，故单调判定充分必要。时间 $O(n\log\max t)$，空间 $O(n)$，总成本可达$10^{15}$，用64位。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,l,r;
ll m;
vector<P> a;
int main(){
    scanf("%d%lld%d",&n,&m,&k);
    a.resize(n);
    l=r=k;
    for(auto &[t,c]:a){
        scanf("%d%d",&t,&c);
        r=max(r,t);
    }
    while(l<r){
        int mid=l+(r-l)/2;
        ll sum=0;
        for(auto &[t,c]:a){
            if(t>mid)sum+=1ll*(t-mid)*c;
        }
        if(sum<=m)r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
```

<a id="problem-c"></a>

## C. LDAP

标签：`递归下降` · `位集` · `离线处理` · `排序`

本地验证：703 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202303/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6addfdea74ace1cba9a232ef)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例、600 组独立用户表达式对拍与 6 组上界测试通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addfdea74ace1cba9a232ef)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305934606)（民间复刻评测）。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05812fe5d1fced2e454ffc)。

原版评测记录：[历史记录 1](https://oj.shumeng.tech/record/6addcb0574ace1cba9a21e46)。

<!-- refactor-online:C:end -->

### 题意

每个用户有唯一 DN 及若干整数属性，通过给定表达式筛选用户。原子表达式 `a:b` 表示具有属性 a 且值等于 b，`a~b` 表示具有该属性且值不等于 b；`&(E1)(E2)`、`|(E1)(E2)` 分别表示交和并。

输入用户数、各用户的 DN 和属性表，再输入查询数及各条表达式。用户至多 2500，每人至多 500 条属性，查询至多 500，表达式长度至多 2000；属性和值均不超过 `10^9`。没有属性 a 的用户不满足 `a~b`。

每次输出匹配 DN 的升序列表，没有匹配时输出空行。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16696)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303C)。

### 题解

#### 1. 用一个位集表示一批匹配用户

给用户按输入顺序编号 `0..n-1`。一个 `bitset<2500>` 就能表示一批用户：第 `i` 位为 1，表示用户 `i` 匹配。这样，逻辑与对应位集的 `&`，逻辑或对应 `|`。

关键是原子表达式。下文用属性及属性值组合标识集合；代码会先离散化，再用下标访问 `has`、`eq`。对于属性 `a`，记 `has[a]` 为具有该属性的用户集合；对于属性与值的组合 `(a,b)`，记 `eq[a,b]` 为属性值等于 `b` 的用户集合。则

$$a:b\quad\longrightarrow\quad eq[a,b],$$

$$a\mathbin{\sim}b\quad\longrightarrow\quad has[a]\ \&\ \sim eq[a,b].$$

反断言不能直接把相等集合取反：没有属性 `a` 的用户也不应匹配。必须再与 `has[a]` 求交集。

#### 2. 只给查询实际用到的属性和值建位集

用户数据最多有 `2500 × 500 = 1250000` 条属性记录。若给每条不同的属性值组合都建一个完整位集，会浪费不少空间；反过来，若每次原子查询都重新扫描该属性的用户，又会在长表达式中重复工作。

本题没有在线修改，所有表达式都可以先读入。因此先扫描全部表达式，收集其中出现的 `(属性,值)`，排序并去重；再从中得到实际需要查询的属性列表。

对于收集到的组合分配 `eq` 位集，对于收集到的属性分配 `has` 位集。用户数据中没有被表达式使用的属性不需要位集；某个被查询的组合没有出现在任何用户身上时，它的相等位集自然全为 0。

每条表达式最多约 250 个原子，500 条表达式最多约 125000 个原子。因此即使都不同，位集数量也受查询总长度约束，而不会随着全部用户属性记录数无限增长。

#### 3. 排序后一次构建索引

读入用户时，把每条属性保存为 `(属性,值,用户下标)` 的扁平记录。代码用

```text
key = (ull(属性) << 32) | unsigned(值)
```

编码属性和值；两者均不超过 `10^9`，编码不会冲突，整数顺序也等于先比较属性、再比较值的顺序。

把用户记录按 `key` 排序后，与已排序的查询组合列表、查询属性列表一起用双指针扫描：

- 若记录的属性是需要查询的属性，把该用户加入相应 `has`。
- 若记录的完整 `key` 是需要查询的组合，把该用户加入相应 `eq`。

这样每条记录只在建索引时处理一次。无需为百万个不同属性建立各自的小容器，也不会让每次反断言扫描该属性下的全部用户。索引建好后，原始记录可以释放。

#### 4. 递归下降解析完整表达式

维护一个指向表达式当前字符的位置：

1. 遇到数字，读出属性、操作符和值，在排序后的组合列表中二分找到对应位集，按前面的公式返回结果。
2. 遇到 `&` 或 `|`，依次解析两个括号里的完整表达式，再对返回的位集求交或求并。

即使左子表达式的结果已经为空，也要正确读完右子表达式，保证解析位置没有错位。代码没有使用可能跳过解析分支的逻辑短路。

最后预先把用户按 DN 排序，逐个查看结果位集中的用户下标，再按顺序输出 DN。DN 和输入下标是两种不同编号，不能混用。

#### 5. 正确性与复杂度

`has` 和 `eq` 由用户原始记录直接构建，所以两个原子表达式的位集准确符合题意。组合表达式又分别取两个子结果的交集或并集，对表达式树作结构归纳即可得到整个结果正确。

设属性记录总数为 `P`，不同查询组合数为 `K`，被查询的不同属性数为 `H`，所有表达式的总原子数为 `A`，总字符数为 `L`；位集占用 `W` 个机器字，当前上限为 `ceil(2500/64)=40`。

- 排序和构建索引需要 `O(P log P + K log K + (K+H)W)`，排序后的合并扫描为 `O(P+K+H)`。
- 解析与求值需要 `O(L + A(log K+W))`。
- 输出前扫描用户需要 `O(mn)`，另计实际输出字符量。
- 空间为 `O(P + (K+H)W + L)`，以及递归解析的临时位集。按题目上限，最保守的位集和属性记录总量也在 512 MiB 限制内。

原版本地验证：1 个保存样例、600 组独立用户表达式对拍与 6 组上界测试通过。完整测试配置和同机基准见 [回归报告](../tests/ldap-report.json)。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=2500,M=2010;
typedef bitset<N> bits;
struct record{
    ull key;
    int u;
};
int n,m;
char s[M];
vector<P> dn;
vector<record> rec;
vector<string> expr;
vector<ull> keys;
vector<int> attr,id;
vector<bits> eq,has;
ull code(int a,int b){
    return (ull(a)<<32)|unsigned(b);
}
int num(const string &str,size_t &p){
    int x=0;
    while(p<str.size() && str[p]>='0' && str[p]<='9'){
        x=x*10+str[p++]-'0';
    }
    return x;
}
bits parse(const string &str,size_t &p){
    if(str[p]=='&' || str[p]=='|'){
        char op=str[p++];
        ++p;
        bits a=parse(str,p);
        p+=2;
        bits b=parse(str,p);
        ++p;
        return op=='&'?a&b:a|b;
    }
    int a=num(str,p);
    char op=str[p++];
    int b=num(str,p);
    int x=lower_bound(keys.begin(),keys.end(),code(a,b))-keys.begin();
    if(op==':')return eq[x];
    return has[id[x]]&~eq[x];
}
int main(){
    scanf("%d",&n);
    rec.reserve(n*500);
    for(int i=0;i<n;++i){
        int u,k;
        scanf("%d%d",&u,&k);
        dn.push_back({u,i});
        while(k--){
            int a,b;
            scanf("%d%d",&a,&b);
            rec.push_back({code(a,b),i});
        }
    }
    scanf("%d",&m);
    expr.resize(m);
    for(string &str:expr){
        scanf("%2000s",s);
        str=s;
        for(size_t p=0;p<str.size();){
            if(str[p]>='0' && str[p]<='9'){
                int a=num(str,p);
                ++p;
                int b=num(str,p);
                keys.push_back(code(a,b));
            }
            else ++p;
        }
    }
    sort(keys.begin(),keys.end());
    keys.erase(unique(keys.begin(),keys.end()),keys.end());
    for(ull &key:keys){
        int a=key>>32;
        if(attr.empty() || attr.back()!=a)attr.push_back(a);
        id.push_back(attr.size()-1);
    }
    eq.resize(keys.size());
    has.resize(attr.size());
    sort(rec.begin(),rec.end(),[](const record &a,const record &b){
        return a.key<b.key;
    });
    size_t x=0,y=0;
    for(record &v:rec){
        int a=v.key>>32;
        while(y<attr.size() && attr[y]<a){
            ++y;
        }
        if(y<attr.size() && attr[y]==a)has[y].set(v.u);
        while(x<keys.size() && keys[x]<v.key){
            ++x;
        }
        if(x<keys.size() && keys[x]==v.key)eq[x].set(v.u);
    }
    vector<record>().swap(rec);
    sort(dn.begin(),dn.end());
    for(string &str:expr){
        size_t p=0;
        bits ans=parse(str,p);
        bool first=true;
        for(auto &[u,i]:dn){
            if(!ans[i])continue;
            if(!first)putchar(' ');
            printf("%d",u);
            first=false;
        }
        putchar('\n');
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 星际网络 II

标签：`离散化` · `线段树` · `区间赋值`

本地验证：102 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202303/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce91da67df0b81749c032)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce91da67df0b81749c032)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305935489)（民间复刻评测）。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0581bbe5d1fced2e455238)。

<!-- refactor-online:D:end -->

### 题意

管理最多 512 位二进制的地址，支持申请地址段、查询单个地址主人及查询整段是否同属一个用户。

输入地址位数及操作数 q，再依次输入操作，$q\le5\times10^4$。地址用固定长度十六进制表示，每四位以冒号分隔：

- `1 id l r`：申请闭区间。不能含其他用户的地址，且必须至少有一个尚未分配的地址；成功后全部归 id。
- `2 s`：查询地址 s 的主人，未分配为 0。
- `3 l r`：查询整段是否属于同一用户。

申请成功输出 YES，否则输出 NO。点查询输出主人编号；区间查询全部同主时输出该编号，否则输出 0。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16697)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303D)。

### 题解

**大整数只用于排序，不需要转换成整数**

删除冒号后，所有地址等长，字典序就是数值顺序。在前面补一位 0，便能安全计算最大地址的后继，避免全为 f 时溢出。

把每个闭区间变成半开区间 $[l,r+1)$；点查询同样视为 $[s,s+1)$。先读完所有操作，收集这些边界并排序去重。相邻边界之间的所有地址永远一起被操作，因此可以压成一个叶子。不能仅压缩 l 和 r 而忽略它们之间可能存在的空白地址。

线段树维护区间内的最小主人编号、最大主人编号、最小正主人编号，并支持整段赋值。申请合法等价于：最小编号为 0（确有空闲），并且最大编号为 0，或所有正编号都等于申请者。查询同一主人时，只需最小编号等于最大编号。

这些统计量可以从左右孩子合并，赋值时直接重置；懒标记保证区间操作效率。离散化保留每次操作的完整边界，因此压缩前后的覆盖关系一致，合法性判断又与规则逐项等价。

设地址十六进制长度为 $L$，时间 $O(qL\log q+q\log q)$，空间 $O(qL+q)$。特别注意：同一用户重复申请自己已经完全持有的区间，也必须输出 NO。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=200,INF=0x3f3f3f3f;
struct info{
    int mn=0,mx=0,pos=INF;
};
info merge(info a,info b){
    return {min(a.mn,b.mn),max(a.mx,b.mx),min(a.pos,b.pos)};
}
struct segtree{
    int n;
    struct node{
        int l,r,tag=-1;
        info v;
    };
    vector<node> e;
    #define l(p) e[p].l
    #define r(p) e[p].r
    void build(int p,int x,int y){
        l(p)=x;r(p)=y;
        if(x==y)return;
        int mid=(x+y)>>1;
        build(p<<1,x,mid);
        build(p<<1|1,mid+1,y);
    }
    void init(int k){
        n=k;
        e.resize(n*4+4);
        build(1,0,n-1);
    }
    void set(int p,int v){
        e[p].v={v,v,v?v:INF};
        e[p].tag=v;
    }
    void pushup(int p){
        e[p].v=merge(e[p<<1].v,e[p<<1|1].v);
    }
    void pushdown(int p){
        if(e[p].tag==-1)return;
        set(p<<1,e[p].tag);
        set(p<<1|1,e[p].tag);
        e[p].tag=-1;
    }
    info query(int p,int x,int y){
        if(x<=l(p) && r(p)<=y)return e[p].v;
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(y<=mid)return query(p<<1,x,y);
        if(x>mid)return query(p<<1|1,x,y);
        return merge(query(p<<1,x,y),query(p<<1|1,x,y));
    }
    void update(int p,int x,int y,int v){
        if(x<=l(p) && r(p)<=y){
            set(p,v);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(x<=mid)update(p<<1,x,y,v);
        if(y>mid)update(p<<1|1,x,y,v);
        pushup(p);
    }
}tr;
struct operation{
    int type,id;
    string l,r;
};
int bits,q;
char s[N];
vector<operation> ops;
vector<string> a;
string read(){
    scanf("%s",s);
    string str=s;
    str.erase(remove(str.begin(),str.end(),':'),str.end());
    return '0'+str;
}
string next(string str){
    const string digit="0123456789abcdef";
    for(int i=str.size()-1;i>=0;--i){
        if(str[i]=='f')str[i]='0';
        else{
            str[i]=digit[digit.find(str[i])+1];
            break;
        }
    }
    return str;
}
int main(){
    scanf("%d%d",&bits,&q);
    ops.resize(q);
    for(operation &op:ops){
        scanf("%d",&op.type);
        if(op.type==1)scanf("%d",&op.id);
        op.l=read();
        op.r=next(op.type==2?op.l:read());
        a.push_back(op.l);
        a.push_back(op.r);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    tr.init(a.size()-1);
    for(operation &op:ops){
        int x=lower_bound(a.begin(),a.end(),op.l)-a.begin();
        int y=lower_bound(a.begin(),a.end(),op.r)-a.begin()-1;
        info v=tr.query(1,x,y);
        if(op.type==1){
            bool ok=v.mn==0 && (v.mx==0 || (v.mx==op.id && v.pos==op.id));
            puts(ok?"YES":"NO");
            if(ok)tr.update(1,x,y,op.id);
        }
        else printf("%d\n",v.mn==v.mx?v.mn:0);
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 施肥

标签：`分治` · `线段树` · `树状数组` · `区间计数`

本地验证：83 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202303/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce91ea67df0b81749c036)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce91ea67df0b81749c036)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305936519)（民间复刻评测）。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058247e5d1fced2e455484)。

<!-- refactor-online:E:end -->

### 题意

$n$ 块田地排成一行，每辆车只能完整覆盖给定闭区间 $[l_i,r_i]$，不能截断。统计有多少个 $L<R$，可以选择若干辆车恰好覆盖 $[L,R]$；允许重叠，但不能漏田或覆盖范围外的田。

输入 `n m` 以及 $m$ 个区间，范围为 $n,m\le2\times10^5$。田地是离散的，$[1,2]$ 与 $[3,4]$ 可以直接拼成 $[1,4]$。

输出符合要求的区间数量。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16698)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202303E)。

### 题解

**按答案区间跨越的位置分治**

在 $[l,r]$ 中取中点 $mid$。完全在左边、完全在右边的答案递归计算；本层只数 $L\le mid<R$。把车辆区间分成左侧、右侧、跨中点三类。

对每个左端点 $L$，定义 $a_L$ 为只用左侧车辆、从 $L$ 开始能连续覆盖的最远位置；没有以 $L$ 为起点的覆盖时设为 $L-1$。倒序扫描 $L$：先取所有起点恰为 $L$ 的区间的最大右端点 $r$，再查询已算好的 $a_t$，其中 $L<t\le\min(mid,r+1)$，取最大值。一次查询即可：达到最大值的那条链已经包含了从该 $t$ 能继续拼接的全部车辆。线段树维护这些最大值。

若要通过一辆跨中点的车继续覆盖，它的左端点必须位于 $[L,a_L+1]$。在这些车中取最小右端点，记为 $b_L$。如果 $a_L=mid$，还可以完全不使用跨中点车辆，此时把 $mid+1$ 也作为候选 $b_L$。没有方案则为正无穷。

从右向左做完全对称的计算，得到 $a_R$（右侧能连续覆盖到的最左位置），以及 $b_R$（能接上的跨中点车辆的最大左端点）；若右侧本身覆盖到 $mid+1$，也允许 $b_R=mid$。

**关键判定**

$[L,R]$ 可覆盖，当且仅当 $b_L\le R$ 且 $L\le b_R$。必要性由一组覆盖中接通左右边界的第一、最后跨中点车辆得到。充分性是：左右两端分别有合法覆盖接到跨中点车辆；两辆跨中点车必定重叠。若两侧都靠相邻拼接接通，则它们在 $mid,mid+1$ 相邻，仍连续。若只有一侧不需要跨车，另一侧的跨车也能与它接上。

把所有 $L$ 按 $b_L$ 排序，按 $R$ 递增扫描，将 $b_L\le R$ 的左端点加入树状数组，查询不超过 $b_R$ 的数量即可。

本层 $O((n+m)\log n)$，递归后总时间 $O((n+m)\log^2 n)$；实现保留各层临时数组，空间上界 $O((n+m)\log n)$。重复车辆不影响答案，单点区间不计入。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
struct range{
    int n,val;
    bool mn;
    vector<int> tr;
    void init(int k,bool flag){
        n=k;
        mn=flag;
        val=mn?INF:-INF;
        tr.assign(n*2,val);
    }
    int merge(int a,int b){
        return mn?min(a,b):max(a,b);
    }
    void add(int x,int v){
        x+=n;
        tr[x]=merge(tr[x],v);
        for(x>>=1;x;x>>=1){
            tr[x]=merge(tr[x<<1],tr[x<<1|1]);
        }
    }
    int query(int l,int r){
        if(l>r)return val;
        int ans=val;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1)ans=merge(ans,tr[l++]);
            if(r&1)ans=merge(ans,tr[--r]);
        }
        return ans;
    }
};
struct BIT{
    int n;
    vector<int> tr;
    void init(int k){
        n=k;
        tr.assign(n+1,0);
    }
    void add(int x){
        for(;x<=n;x+=x&-x){
            ++tr[x];
        }
    }
    int sum(int x){
        int ans=0;
        for(;x>0;x-=x&-x){
            ans+=tr[x];
        }
        return ans;
    }
};
int n,m;
ll solve(int l,int r,vector<P> v){
    if(l==r || v.empty())return 0;
    int mid=(l+r)>>1,len=r-l+1;
    vector<P> a,b,c;
    vector<int> far(len),near(len);
    for(int i=l;i<=r;++i){
        far[i-l]=i-1;
        near[i-l]=i+1;
    }
    for(auto &[x,y]:v){
        if(y<=mid){
            a.push_back({x,y});
            far[x-l]=max(far[x-l],y);
        }
        else if(x>mid){
            b.push_back({x,y});
            near[y-l]=min(near[y-l],x);
        }
        else c.push_back({x,y});
    }
    vector<int> right(mid-l+1),left(r-mid);
    range reach,ends;
    reach.init(len,false);
    ends.init(len,true);
    for(auto &[x,y]:c){
        ends.add(x-l,y);
    }
    for(int i=mid;i>=l;--i){
        int x=far[i-l];
        x=max(x,reach.query(i+1-l,min(mid,x+1)-l));
        reach.add(i-l,x);
        int y=ends.query(i-l,min(mid,x+1)-l);
        if(x==mid)y=min(y,mid+1);
        right[i-l]=y;
    }
    reach.init(len,true);
    ends.init(len,false);
    for(auto &[x,y]:c){
        ends.add(y-l,x);
    }
    for(int i=mid+1;i<=r;++i){
        int x=near[i-l];
        x=min(x,reach.query(max(mid+1,x-1)-l,i-1-l));
        reach.add(i-l,x);
        int y=ends.query(max(mid+1,x-1)-l,i-l);
        if(x==mid+1)y=max(y,mid);
        left[i-mid-1]=y;
    }
    vector<P> events;
    for(int i=l;i<=mid;++i){
        events.push_back({right[i-l],i});
    }
    sort(events.begin(),events.end());
    BIT bit;
    bit.init(mid-l+1);
    size_t p=0;
    ll ans=0;
    for(int i=mid+1;i<=r;++i){
        while(p<events.size() && events[p].first<=i){
            bit.add(events[p++].second-l+1);
        }
        int x=min(mid,left[i-mid-1]);
        ans+=bit.sum(x-l+1);
    }
    ans+=solve(l,mid,std::move(a));
    ans+=solve(mid+1,r,std::move(b));
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    vector<P> v(m);
    for(auto &[l,r]:v){
        scanf("%d%d",&l,&r);
    }
    printf("%lld\n",solve(1,n,std::move(v)));
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202303/VALIDATION.md)
- [boundaries.py](../tests/202303/boundaries.py)
- [e-style-followup-report.json](../tests/202303/e-style-followup-report.json)
- [online-update-report.json](../tests/202303/online-update-report.json)
- [online-verdicts.json](../tests/202303/online-verdicts.json)
- [refactor-report.json](../tests/202303/refactor-report.json)
- [statements.json](../tests/202303/statements.json)

<!-- local-validation-attachments:end -->
