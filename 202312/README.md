---
title: "CSP 202312 五题题解"
contest: "202312"
contest_month: "2023-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "暴力枚举", "多维比较", "质因数分解", "试除法", "树", "DFS序", "决策树", "前缀和", "线段树", "栈", "括号序列", "矩阵乘法", "状态压缩", "折半搜索", "位集", "图论"]
status: "published"
problems: [{"id": "A", "title": "仓库规划", "tags": ["暴力枚举", "多维比较"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16064"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055e8ee5d1fced2e450e72", "source_sha256": "710a79b37c5eb67b6cfa08008c8c827b32aa67d576a3c39863e25d78cf67b0cf", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:54:56.797171+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305806451", "source_sha256": "4c83d3db506e7f5e4767ced8ac4cef5fc097e00da47c3952011d644b6309957d"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c0a67df0b81749bd8f"}}, {"id": "B", "title": "因子化简", "tags": ["质因数分解", "试除法"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16065"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055f06e5d1fced2e451057", "source_sha256": "e5c90cc994df3c3c5864791d0c7023407fdeba9a494dace9901649c1bfe1646c", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:55:36.512863+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305807711", "source_sha256": "563b394c1a56a2ae26effa1a69a22016e0d9ba0e053c3ed2cd89bdff50935b00"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c2a67df0b81749bd93"}}, {"id": "C", "title": "树上搜索", "tags": ["树", "DFS序", "决策树", "前缀和"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16066"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312C/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055f64e5d1fced2e451151", "source_sha256": "26c33898ee789f478bd67652b4cc6d910c22182d1ccf129e9a0280a55892ee67", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:57:12.223727+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305808966", "source_sha256": "9dd41b045ba10af0744e306a984044d3e75c5b1fab25e9b0f98378321c4ddf64"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c3a67df0b81749bdb0"}}, {"id": "D", "title": "宝藏", "tags": ["线段树", "栈", "括号序列", "矩阵乘法"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16067"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055fc8e5d1fced2e451250", "source_sha256": "a0f4375d0c7528854e6cfa934b3783bdef1b8f14fc5681a24dd85ac8fd72261c", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:58:58.243401+00:00"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490650", "source_sha256": "b9dac51f4128d412d8797ca5102466c3a040e8c3431df66c0cef4bca8c940ae7", "note": "上一版根号分块代码记录；本版已改为线段树，须重新复验"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305810434", "source_sha256": "ae452c40a94a10bde5c2b7762bc72497775a8991ed96e7f92f9e7e6bad5bc4a3"}, "original_validation": "C++17 编译通过；1 个保存样例、700 组独立朴素对拍与 6 组 10 万规模压力测试通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2", "source_sha256": "ae452c40a94a10bde5c2b7762bc72497775a8991ed96e7f92f9e7e6bad5bc4a3"}}, {"id": "E", "title": "彩色路径", "tags": ["状态压缩", "折半搜索", "位集", "图论"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16068"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202312E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202312E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b056032e5d1fced2e4512f0", "source_sha256": "7035b3ceb3c58de35a5ded1bb1ee44a370671d4d101f21e63011cbfdb6731f9b", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:01:13.107907+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305811545", "source_sha256": "50bb86e45543e321967d09cb269c8526e3649064b4c2c134197072f109b67e71"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c7a67df0b81749bdda"}}]
---

# CSP 202312 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202312/VALIDATION.md)


<a id="problem-a"></a>

## A. 仓库规划

标签：`暴力枚举` · `多维比较`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202312/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce8c0a67df0b81749bd8f)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce8c0a67df0b81749bd8f)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305806451)（民间复刻评测）。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055e8ee5d1fced2e450e72)。

<!-- refactor-online:A:end -->

### 题意

仓库 j 的每一维坐标都严格大于仓库 i 时，可以作为 i 的上级。对每个仓库，求编号最小的上级。

输入仓库数 n、维度 m，以及各仓库的 m 维坐标。范围为 n≤1000、m≤10。

依次输出每个仓库的上级编号；没有候选时输出 0。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312A)。

### 题解

对每个i按编号从小到大枚举j，检查全部维度，任一维不严格大于就失败；第一个全部通过的j就是答案并停止。

逐维合取正好对应上级定义，编号升序保证首次成功者最小。不能仅比较向量和、字典序或允许某维相等。时间 $O(n^2m)$，空间 $O(nm)$，在给定范围内足够。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=15;
int n,m,a[N][M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        int ans=0;
        for(int j=1;j<=n;++j){
            bool ok=true;
            for(int k=0;k<m;++k){
                if(a[j][k]<=a[i][k]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                ans=j;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 因子化简

标签：`质因数分解` · `试除法`

本地验证：102 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202312/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce8c2a67df0b81749bd93)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce8c2a67df0b81749bd93)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305807711)（民间复刻评测）。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055f06e5d1fced2e451057)。

<!-- refactor-online:B:end -->

### 题意

分解正整数 n 的质因子，删去指数小于阈值 k 的整个质数幂，保留其余项。

输入查询数，随后每组输入 n、k。范围为 n≤$10^{10}$、查询数≤10，原题 k>1。

每组输出保留项的乘积；没有保留项时输出 1。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312B)。

### 题解

从2起试除当前剩余数，循环条件为 p≤n/p，避免 p*p 溢出。每遇到因子 p 就连续除尽，统计指数和完整幂；指数达到 k 才乘进答案。

试除结束后若剩余数>1，它只能是一个指数为1的质数（否则还存在不超过平方根的因子）；原题 k>1，因此通常不保留，代码也兼容 k=1。已经取出的因子不会再次出现，最终恰好保留题目要求的各幂。每次时间 $O(\sqrt n)$，额外空间 $O(1)$，n 与答案用64位。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,k;
ll n;
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%lld%d",&n,&k);
        ll ans=1;
        for(ll p=2;p<=n/p;++p){
            int cnt=0;
            ll v=1;
            while(n%p==0){
                n/=p;
                v*=p;
                ++cnt;
            }
            if(cnt>=k)ans*=v;
        }
        if(n>1 && k<=1)ans*=n;
        printf("%lld\n",ans);
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 树上搜索

标签：`树` · `DFS序` · `决策树` · `前缀和`

本地验证：102 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202312/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce8c3a67df0b81749bdb0)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce8c3a67df0b81749bdb0)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305808966)（民间复刻评测）。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055f64e5d1fced2e451151)。

<!-- refactor-online:C:end -->

### 题意

类别构成根为 1 的带正权树。每轮从剩余类别中选一个点，使其子树内外的剩余权重之差绝对值最小，同分取编号较小者；根据目标是否在该子树中保留对应一侧，直到只剩一个类别。

输入 n、m、各点权重、节点 2 到 n 的父节点，以及 m 个目标。范围为 $n\le2000,m\le100$，父节点编号不一定小于子节点。

对每个目标输出依次提问的节点编号。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312C)。

### 题解

一次提问由当前候选集合决定，与目标是谁无关。因此先构建所有目标共享的二叉决策树：状态保存候选集合，选出最佳问题后分成“是”和“否”两组，递归构建；单元素集合为叶子。

对原树预处理 DFS 进入和退出时间，任意子树对应连续区间。对某个决策状态，将候选点权放到 DFS 序上、其余填零，构造前缀和，就能 O(1) 得到每个候选点子树内的剩余权重。扫描候选点选择最小差值，编号破同分，然后按 DFS 区间分组。

权重为正且候选至少两个时，存在一个真子集的问题比保留全体更平衡，所以两个分支都非空，过程必定终止。决策节点至多 2n-1 个，每个状态 O(n) 构建前缀与筛选，总构建时间 $O(n^2)$。查询只沿决策树输出路径，时间等于输出长度；本实现递归保留候选数组，最坏空间 $O(n^2)$，在 n≤2000 下可用。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2010;
struct node{
    int x,l,r;
}e[N<<1];
int n,m,tot,tim,in[N],out[N];
ll w[N];
vector<int> g[N];
void dfs(int u){
    in[u]=tim++;
    for(int &v:g[u]){
        dfs(v);
    }
    out[u]=tim;
}
bool anc(int t,int x){
    return in[x]<=in[t] && in[t]<out[x];
}
int build(const vector<int> &v){
    int p=++tot;
    if(v.size()==1)return p;
    vector<ll> sum(n+1);
    for(const int &u:v){
        sum[in[u]+1]=w[u];
    }
    for(int i=1;i<=n;++i){
        sum[i]+=sum[i-1];
    }
    ll best=-1;
    int x=0;
    for(const int &u:v){
        ll d=abs(sum[n]-2*(sum[out[u]]-sum[in[u]]));
        if(best==-1 || d<best || (d==best && u<x)){
            best=d;
            x=u;
        }
    }
    vector<int> a,b;
    for(const int &u:v){
        if(anc(u,x))a.push_back(u);
        else b.push_back(u);
    }
    e[p].x=x;
    e[p].l=build(a);
    e[p].r=build(b);
    return p;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&w[i]);
    }
    for(int i=2;i<=n;++i){
        int p;
        scanf("%d",&p);
        g[p].push_back(i);
    }
    dfs(1);
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    int root=build(v);
    while(m--){
        int t,u=root;
        scanf("%d",&t);
        bool first=true;
        while(e[u].x){
            int x=e[u].x;
            if(!first)putchar(' ');
            first=false;
            printf("%d",x);
            bool yes=anc(t,x);
            u=yes?e[u].l:e[u].r;
        }
        putchar('\n');
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 宝藏

标签：`线段树` · `栈` · `括号序列` · `矩阵乘法`

本地验证：813 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202312/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例、700 组独立朴素对拍与 6 组 10 万规模压力测试通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305810434)（民间复刻评测）。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055fc8e5d1fced2e451250)。

<!-- refactor-online:D:end -->

### 题意

维护 $n$ 条矩阵双端队列指令：1 表示头插一个 $2\times2$ 矩阵，2 表示尾插，3 表示删除最近插入的矩阵，空队列上的删除忽略。支持修改一条指令，并查询从空队列执行指定区间后的矩阵乘积。

输入 n、m 及初始指令，随后输入 m 次操作，$n,m\le10^5$。操作格式如下：

- `1 i 新指令`：修改第 i 条指令。
- `2 l r`：从空队列执行区间 $[l,r]$ 的指令，查询队列内矩阵从头到尾的乘积。

每次查询输出乘积的四个元素，均模 $998244353$；空队列的乘积为单位矩阵。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312D)。

### 题解

**1. 先决定谁能留下，再决定乘法顺序**

虽然容器是双端队列，但删除的对象取决于插入时间。因此，我们可以先用一个普通栈记录插入指令：指令 1、2 都压栈，指令 3 弹栈。最后留在栈中的插入指令，就是没有被撤销的矩阵。

对于这些存活指令，设 `a` 为所有头插矩阵按时间倒序相乘的结果，`b` 为所有尾插矩阵按时间正序相乘的结果，答案就是 `a * b`。例如依次“头插 A、尾插 B、头插 C”，队列为 `C,A,B`，答案是 `(C*A)*B`。

矩阵乘法不能交换顺序，也不能假设输入矩阵可逆。以下做法只用乘法，不需要求逆。

**2. 一段指令可以压缩成“删除若干个，再插入若干个”**

在空栈上执行一段指令，记录：

- `del`：栈空时遇到多少次删除；
- `sz`：最后还剩多少次插入；
- `all`：这些存活插入对应的 `a`、`b` 两个矩阵积。

这段指令接在任意已有栈后面，等价于先删除最多 `del` 个旧元素，再压入本段存活的插入。块内已经互相抵消的插入和删除，不会影响外部结果。

现在考虑相邻两段 `L`、`R`。右段开头的删除会消去左段存活序列的末尾，因此左段留下的数量为

$$k=\max(0,L.sz-R.del).$$

合并后，存活序列是“左段的前 `k` 个存活插入，接上右段的全部存活插入”。于是

$$sz=k+R.sz,$$

$$del=L.del+\max(0,R.del-L.sz).$$

例如左段留下 `A,B,C`，右段先删除 2 次、再留下 `D`，合并后留下 `A,D`。

**3. 在线段树里快速取得存活序列的前缀**

难点是得到“左段前 `k` 个存活插入”的矩阵积。我们用线段树维护上述摘要，每个节点再缓存两个量：

- `cnt`：合并左右儿子后，左儿子还留下多少个插入；
- `pre`：这部分插入对应的两种矩阵积。

若要获取某个节点存活序列的前 `k` 项：

1. 若取空前缀，返回两个单位矩阵；若取全部，直接返回 `all`。
2. 若 `k <= cnt`，只需在左儿子中取前 `k` 项。
3. 否则，先取已缓存的 `pre`，再接上右儿子存活序列的前 `k-cnt` 项。

每次递归只进入一个儿子，所以取一个存活前缀只需要 `O(log n)`。合并节点时，调用这个前缀操作得到左侧留下的部分，再与右儿子的摘要合并。

合并两段乘积时也必须保留方向。若 `X` 在时间上先于 `Y`，则

$$a=Y.a\times X.a,\qquad b=X.b\times Y.b.$$

后发生的头插排在前面，后发生的尾插排在后面，这就是两个方向不同的原因。

**4. 修改与查询**

单点修改后，从对应叶子向上重新合并节点，共 `O(log n)` 层，每次合并最多花 `O(log n)`，故修改最坏为 `O(log^2 n)`。

查询先把 `[l,r]` 分成线段树上的 `O(log n)` 个完整节点，然后**从右往左**处理。维护右侧还需要向左删除多少个插入，记作 `del`：

- 若当前节点的 `sz <= del`，它留下的插入被全部删掉，把剩余删除需求及当前节点自己的未配对删除继续传向左边。
- 否则只保留当前节点存活序列的前 `sz-del` 项，取出对应乘积，接到已处理部分的前面；下一步向左传递的删除需求变成当前节点自己的 `del`。

全部处理完后，任何多余删除都作用于空队列，可以忽略。输出累计的 `a * b`。

节点摘要准确描述一段指令对任意旧栈的作用；左右合并只删除左段存活序列的后缀；查询又严格按时间顺序组合最后的存活指令，所以计算结果与逐条执行相同。

空间复杂度为 `O(n)`。查询与修改最坏均为 `O(log^2 n)`。自底向上建树为 `O(n)`：高度为 `h` 的节点只有 `O(n/2^h)` 个，每个合并花 `O(h)`，而 `sum(h/2^h)` 有界。实现使用固定长度的查询节点数组，避免每次查询反复分配容器。

旧版根号分块在曙梦 OJ 重交仍为 [85 分超时](https://oj.shumeng.tech/record/6addc9ec74ace1cba9a21d5a)，原版已获 [100 分 Accepted](https://oj.shumeng.tech/record/6addcc1874ace1cba9a21ea2)。同机 6 组上界构造较旧版快约 8–36 倍；本地耗时不等同评测机耗时。

[独立对拍脚本](../tests/treasure_regressions.py)、[验证报告](../tests/treasure-report.json)。上一版洛谷满分记录保留在元数据中，当前重构版的本地复验另见本地验证记录。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1<<17,M=32;
const int mod=998244353;
struct mat{
    int a=1,b=0,c=0,d=1;
};
mat mul(const mat &x,const mat &y){
    mat z;
    z.a=(1ll*x.a*y.a+1ll*x.b*y.c)%mod;
    z.b=(1ll*x.a*y.b+1ll*x.b*y.d)%mod;
    z.c=(1ll*x.c*y.a+1ll*x.d*y.c)%mod;
    z.d=(1ll*x.c*y.b+1ll*x.d*y.d)%mod;
    return z;
}
struct prod{
    mat a,b;
};
prod merge(const prod &x,const prod &y){
    return {mul(y.a,x.a),mul(x.b,y.b)};
}
struct segtree{
    int n;
    struct node{
        int l,r,del,sz,cnt;
        prod all,pre;
    }e[N<<1];
    #define l(p) e[p].l
    #define r(p) e[p].r
    prod prefix(int p,int k){
        node &v=e[p];
        if(k==v.sz)return v.all;
        if(!k)return prod();
        if(k<=v.cnt)return prefix(p<<1,k);
        return merge(v.pre,prefix(p<<1|1,k-v.cnt));
    }
    void pushup(int p){
        node &v=e[p],&a=e[p<<1],&b=e[p<<1|1];
        v.cnt=max(0,a.sz-b.del);
        v.sz=v.cnt+b.sz;
        v.del=a.del+max(0,b.del-a.sz);
        v.pre=prefix(p<<1,v.cnt);
        if(!v.cnt)v.all=b.all;
        else if(!b.sz)v.all=v.pre;
        else v.all=merge(v.pre,b.all);
    }
    void set(int p,int type,const mat &v){
        e[p].del=(type==3);
        e[p].sz=(type!=3);
        e[p].all=prod();
        if(type==1)e[p].all.a=v;
        if(type==2)e[p].all.b=v;
    }
    void build(int p,int x,int y){
        l(p)=x;r(p)=y;
        if(x==y)return;
        int mid=(x+y)>>1;
        build(p<<1,x,mid);
        build(p<<1|1,mid+1,y);
    }
    void init(int k){
        n=1;
        while(n<k){
            n<<=1;
        }
        build(1,0,n-1);
    }
    void update(int x,int type,const mat &v){
        int p=n+x;
        set(p,type,v);
        while(p>>=1){
            pushup(p);
        }
    }
    mat query(int x,int y){
        int a[M],b[M],na=0,nb=0;
        for(x+=n,y+=n+1;x<y;x>>=1,y>>=1){
            if(x&1)a[na++]=x++;
            if(y&1)b[nb++]=--y;
        }
        int del=0;
        prod ans;
        bool ok=false;
        auto take=[&](int p){
            node &v=e[p];
            if(v.sz<=del)del+=v.del-v.sz;
            else{
                prod cur=prefix(p,v.sz-del);
                ans=ok?merge(cur,ans):cur;
                ok=true;
                del=v.del;
            }
        };
        for(int i=0;i<nb;++i){
            take(b[i]);
        }
        for(int i=na-1;i>=0;--i){
            take(a[i]);
        }
        return mul(ans.a,ans.b);
    }
}tr;
int n,m,op,x,y,type;
mat read(int t){
    mat v;
    if(t!=3)scanf("%d%d%d%d",&v.a,&v.b,&v.c,&v.d);
    return v;
}
int main(){
    scanf("%d%d",&n,&m);
    tr.init(n);
    for(int i=0;i<n;++i){
        scanf("%d",&type);
        tr.set(tr.n+i,type,read(type));
    }
    for(int p=tr.n-1;p;--p){
        tr.pushup(p);
    }
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&type);
            tr.update(x-1,type,read(type));
        }
        else{
            scanf("%d%d",&x,&y);
            mat ans=tr.query(x-1,y-1);
            printf("%d %d %d %d\n",ans.a,ans.b,ans.c,ans.d);
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 彩色路径

标签：`状态压缩` · `折半搜索` · `位集` · `图论`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202312/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce8c7a67df0b81749bdda)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce8c7a67df0b81749bdda)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305811545)（民间复刻评测）。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b056032e5d1fced2e4512f0)。

<!-- refactor-online:E:end -->

### 题意

有向图的点带颜色，求从 0 到 $n-1$ 的最长路径，要求路径各点颜色互不相同，点数不超过 $l$。

输入首行为 `n m l k`，第二行是点颜色，随后三行分别给全部边的起点、终点、权值。范围为 $n\le100,m\le5000,l\le9,k\le30$，边权为正；保证存在合法路线，且起终点颜色不在其他点上出现。

输出合法路径的最大权值。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202312E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202312E)。

### 题解

**最多八条边，分成两半**

任意合法路径可以选择一个中间点，使两半各不超过四条边。在正图从 0 出发、反图从终点出发，各做四层 DP。状态 $(d,u,S)$ 记录恰走 $d$ 条边到 $u$、颜色集合为 $S$ 的最大权值；转移时拒绝已经出现的颜色。相同状态只保留最大值，因为未来可行性只由当前位置和颜色集合决定。

**合并要去掉重复的中间颜色**

对一个前半状态，后半最多有 $\min(4,l-1-d)$ 条边。两半颜色交集只能是中间点颜色；从前半掩码中删掉该位后，就成为与后半掩码完全不相交的条件。颜色不同也保证没有重复顶点。

**位集寻找最大的可用后半段**

对固定中间点和长度上限，把后半状态按权值降序排列。对每种颜色建立位集，表示哪些候选包含此颜色。将前半出现的颜色对应位集按或合并，得到全部禁用候选；取反后第一个置位就是权值最大的可用候选。用 64 位整数逐块扫描，不需要枚举两半的所有组合。

**正确性**

每条合法路径至少被一种中间点拆法覆盖；DP 不丢失任何可能成为最优的半路径。颜色交集和总长度条件保证合并后合法。候选按值排序，第一条可用者就是该前半段的最优搭配。

**复杂度**

以实际 DP 状态数 $S$、转移总数 $E_s$、每次合并候选数 $R$ 表示，时间为 $O(E_s+S\log S+S\cdot4\lceil R/64\rceil)$，空间为状态和颜色位集大小。每个半路径固定包含一个终端颜色，四边状态的自由颜色只有三种，数量受 $\binom{k-2}{3}$ 约束。注意位集扫描的是候选数 $R$，不能误写成 $k/64$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<unordered_map<ui,int>> layer;
const int N=105,M=5;
int n,m,l,k,col[N];
vector<P> g[N],rg[N];
vector<layer> calc(int s,vector<P> edges[N]){
    vector<layer> dp(M,layer(n));
    dp[0][s][1u<<col[s]]=0;
    for(int d=0;d<M-1 && d+1<l;++d){
        for(int u=0;u<n;++u){
            for(auto &[S,val]:dp[d][u]){
                for(auto &[v,w]:edges[u]){
                    int c=col[v];
                    if(S>>c&1)continue;
                    int &best=dp[d+1][v][S|(1u<<c)];
                    best=max(best,val+w);
                }
            }
        }
    }
    return dp;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&l,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&col[i]);
    }
    vector<int> a(m),b(m),w(m);
    for(int &x:a){
        scanf("%d",&x);
    }
    for(int &x:b){
        scanf("%d",&x);
    }
    for(int &x:w){
        scanf("%d",&x);
    }
    for(int i=0;i<m;++i){
        g[a[i]].push_back({b[i],w[i]});
        rg[b[i]].push_back({a[i],w[i]});
    }
    auto f=calc(0,g),h=calc(n-1,rg);
    int ans=0;
    for(int u=0;u<n;++u){
        for(int d=0;d<M && d<l;++d){
            if(f[d][u].empty())continue;
            int cap=min(M-1,l-1-d);
            vector<pair<int,ui>> v;
            for(int i=0;i<=cap;++i){
                for(auto &[S,val]:h[i][u]){
                    v.push_back({val,S});
                }
            }
            sort(v.rbegin(),v.rend());
            int len=(v.size()+63)/64;
            if(!len)continue;
            vector<vector<ull>> bad(k,vector<ull>(len));
            for(int i=0;i<(int)v.size();++i){
                ui S=v[i].second;
                while(S){
                    int c=__builtin_ctz(S);
                    S&=S-1;
                    bad[c][i/64]|=1ull<<(i%64);
                }
            }
            for(auto &[key,val]:f[d][u]){
                ui S=key^(1u<<col[u]);
                vector<int> colors;
                while(S){
                    colors.push_back(__builtin_ctz(S));
                    S&=S-1;
                }
                for(int i=0;i<len;++i){
                    ull ex=0;
                    for(int &c:colors){
                        ex|=bad[c][i];
                    }
                    ull ok=~ex;
                    if(!ok)continue;
                    int pos=i*64+__builtin_ctzll(ok);
                    if(pos<(int)v.size())ans=max(ans,val+v[pos].first);
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202312/VALIDATION.md)
- [boundaries.py](../tests/202312/boundaries.py)
- [c-style-followup-report.json](../tests/202312/c-style-followup-report.json)
- [d-alias-followup-report.json](../tests/202312/d-alias-followup-report.json)
- [d-style-followup-report.json](../tests/202312/d-style-followup-report.json)
- [e-mask-followup-report.json](../tests/202312/e-mask-followup-report.json)
- [online-update-report.json](../tests/202312/online-update-report.json)
- [online-verdicts.json](../tests/202312/online-verdicts.json)
- [refactor-report.json](../tests/202312/refactor-report.json)
- [statements.json](../tests/202312/statements.json)

<!-- local-validation-attachments:end -->
