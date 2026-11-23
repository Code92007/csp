---
title: "CSP 202603 五题题解"
contest: "202603"
contest_month: "2026-03"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "位运算", "计数", "0/1背包", "分数背包", "贪心", "模拟", "内存分配", "有序集合", "数位", "线段树", "懒标记", "树链剖分", "树状数组", "随机化", "在线查询"]
status: "published"
problems: [{"id": "A", "title": "平衡数", "tags": ["位运算", "计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版 C++17 编译通过；本地独立、边界及保存样例共 924 组验证；未重新提交。保留原版曙梦 OJ 100 分记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202603A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce724a67df0b81749b544"}}, {"id": "B", "title": "机器人项目管理", "tags": ["0/1背包", "分数背包", "贪心"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版 C++17 编译通过；本地独立、边界及保存样例共 473 组验证；未重新提交。保留原版曙梦 OJ 100 分记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202603B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce726a67df0b81749b54b"}}, {"id": "C", "title": "进程通信", "tags": ["模拟", "内存分配", "有序集合"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版 C++17 编译通过；本地独立、边界及保存样例共 328 组验证；未重新提交。保留原版曙梦 OJ 100 分记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202603C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce727a67df0b81749b550"}}, {"id": "D", "title": "异或", "tags": ["数位", "线段树", "懒标记"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版 C++17 编译通过；本地独立、边界及保存样例共 440 组验证（D 含同算法模板微调前记录，详见验证报告）；未重新提交。保留原版曙梦 OJ 100 分记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202603D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce729a67df0b81749b56b"}}, {"id": "E", "title": "旅游计划 - Easy Ver.", "tags": ["树链剖分", "树状数组", "随机化", "在线查询"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版 C++17 编译通过；本地独立、边界及保存样例共 364 组验证；未重新提交。保留原版曙梦 OJ 100 分记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202603E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202603E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce72ba67df0b81749b59e"}}]
---
# CSP 202603 五题题解

[原页面](https://code92007.github.io/csp/#/contest/202603) · [验证记录](../tests/202603/VALIDATION.md)

<a id="problem-a"></a>

## A. 平衡数

标签：`位运算` · `计数`

本地验证见 [VALIDATION.md](../tests/202603/VALIDATION.md)，重构版尚未在线重新提交。

### 题意

给定 $n$ 个正整数，统计其中二进制有效位里 0 和 1 数量相同的数。二进制表示从最高位的 1 开始，前导零不计入统计。

输入第一行为 $n$，第二行为 $n$ 个正整数 $a_i$。数据范围为 $1\le n\le100$、$1\le a_i\le10^9$。

输出一个整数，表示符合条件的数的个数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603A/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202603A)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce724a67df0b81749b544)。

### 题解

**逐位统计**

每次用 `x&1` 取得最低位，再将 `x` 右移一位，直到它变为 0。用 `len` 记录位数，`cnt` 记录其中 1 的个数，0 的个数就是 `len-cnt`，因此只需判断 `cnt*2==len`。

**正确性**

循环恰好处理从最低位到最高位 1 之间的全部有效位，不会计入前导零。判断条件等价于 0 和 1 数量相同，所以累计结果就是答案。

**复杂度**

设输入的最大值为 $A$。时间复杂度 $O(n\log A)$，额外空间复杂度 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,ans,x,cnt,len;
int main(){
    scanf("%d",&n);
    while(n--){
        cnt=len=0;
        scanf("%d",&x);
        while(x){
            cnt+=x&1;
            ++len;
            x>>=1;
        }
        ans+=(cnt*2==len);
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 机器人项目管理

标签：`0/1背包` · `分数背包` · `贪心`

本地验证见 [VALIDATION.md](../tests/202603/VALIDATION.md)，重构版尚未在线重新提交。

### 题意

有 $n$ 个任务，每个任务的初始耗时为 $t$。普通任务必须购买整组 $a$ 杯咖啡，才能缩短 $b$ 时间，不能部分购买；灵活任务可以购买任意实数杯，按比例缩短耗时，至多购买 $a$ 杯。总预算为 $m$ 杯，求完成所有任务的最短总时间。

输入先给出 `n m`，随后每个任务给出 `op t a b`，其中 `op=0` 表示灵活任务，`op=1` 表示普通任务。数据范围为 $1\le n\le200$、$1\le m\le1000$、$1\le a\le100$、$0<b<t\le10^4$。

输出一个实数，表示最短总时间，绝对误差需小于 $0.001$，推荐保留六位小数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603B/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202603B)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce726a67df0b81749b54b)。

### 题解

**普通任务做 0/1 背包**

先求最多能节省多少时间，再用初始总耗时减去它。`dp[j]` 表示普通任务花费不超过 $j$ 杯咖啡时，最多节省的时间。每个任务只能选一次，因此容量倒序更新：

$$dp[j]=\max(dp[j],dp[j-a]+b).$$

**灵活任务按效率贪心**

将灵活任务按 $b/a$ 从大到小排序，依次购买，买满一个再考虑下一个。比较效率时使用交叉乘法，避免排序中的浮点误差。

预处理 `g[c]`，表示灵活任务使用不超过整数预算 $c$ 时的最大收益。由于每个任务的上限 $a$ 是整数，按排序结果每次追加一杯的收益 $b/a$，即可得到所有整数预算的答案。买满所有灵活任务后，剩余预算的收益不再增加。

**枚举预算分配**

普通任务的实际花费一定是整数，剩给灵活任务的预算也为整数。枚举普通任务的预算 $j$，最大节省时间为

$$\max_{0\le j\le m}\{dp[j]+g[m-j]\}.$$

最后从初始总耗时 `sum` 中减去这个值。收益计算使用 `ld`，输出保留 8 位小数。

**正确性**

倒序背包枚举了普通任务的所有合法选择。对于灵活任务，如果低效率任务已购买，而高效率任务尚未买满，把一部分预算转给高效率任务不会使收益变差。不断交换后就得到按效率购买的贪心方案，所以 `g` 的值最优。

任意合法方案的普通部分都有一个整数花费，枚举预算时一定会覆盖该分配。两部分的最优收益相加，再取最大值，因此得到整体最优解。

**复杂度**

时间复杂度 $O(nm+n\log n)$，空间复杂度 $O(n+m)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const int M=1005;
int n,m;
ll sum,dp[M];
ld g[M];
bool cmp(P x,P y){
    return 1ll*x.second*y.first>1ll*y.second*x.first;
}
int main(){
    scanf("%d%d",&n,&m);
    vector<P>a;
    for(int i=1;i<=n;++i){
        int op,t,x,y;
        scanf("%d%d%d%d",&op,&t,&x,&y);
        sum+=t;
        if(!op){
            a.push_back(P(x,y));
        }
        else{
            for(int j=m;j>=x;--j){
                dp[j]=max(dp[j],dp[j-x]+y);
            }
        }
    }
    sort(a.begin(),a.end(),cmp);
    int used=0;
    for(P &x:a){
        for(int j=0;j<x.first && used<m;++j){
            g[used+1]=g[used]+(ld)x.second/x.first;
            ++used;
        }
    }
    while(used<m){
        g[used+1]=g[used];
        ++used;
    }
    ld ans=0;
    for(int j=0;j<=m;++j){
        ans=max(ans,dp[j]+g[m-j]);
    }
    printf("%.8Lf\n",sum-ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. 进程通信

标签：`模拟` · `内存分配` · `有序集合`

本地验证见 [VALIDATION.md](../tests/202603/VALIDATION.md)，重构版尚未在线重新提交。

### 题意

有 $n$ 个进程，以及从地址 0 开始的无限空闲内存，所有进程初始都没有队列。按给定命令模拟队列建立、对象发送与队列删除。

输入先给出 `n q`，随后给出 $q$ 条命令。数据范围为 $1\le n\le100$、$1\le q\le8000$、$1\le L\le5\times10^5$，进程编号从 1 到 $n$。保证所有命令合法，发送时进程至少有一个队列，删除的队列一定存在。支持以下三种命令：

- `new p L`：给进程 $p$ 建立长度为 $L$ 的队列，编号排在该进程现有队列之后。选择能容纳它的最短连续空闲段，同长时取最左的一段，从左端分配。
- `send p`：向进程 $p$ 的所有队列各写一个对象。第一次写入队列起点，此后循环写下一个地址。
- `delete p i`：删除进程 $p$ 的第 $i$ 个队列并释放内存，后续队列编号减一。

每次 `new` 输出新队列的起点，每次 `send` 输出本次写入地址之和，每个结果各占一行；`delete` 无需输出。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603C/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202603C)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce727a67df0b81749b550)。

### 题解

**只保存队列和空闲区间**

不需要存储内存中的每个对象。每个队列只保存起点 `l`、长度 `len` 和下一次写入的相对位置 `pos`。

发送时累加 `l+pos`，再将 `pos` 加一并对 `len` 取模。每个进程用一个向量按创建顺序保存队列，删除元素后，后续队列自然前移。

**用两份索引管理有限空洞**

`mp` 按起点保存有限空洞，便于寻找相邻区间。`st` 按 `(长度,起点)` 排序，便于选择最短、最左的合适空洞。`tail` 表示无限空闲尾段的起点。

分配时，在 `st` 中二分找到第一个长度不小于 $L$ 的空洞。从两份索引中删去它，再把分配后剩余的右半段加入索引。如果找不到，就直接从 `tail` 分配，并将 `tail` 向右移动。

**释放时合并相邻空洞**

在 `mp` 中寻找释放区间的左右邻居，端点相接就合并。如果合并后的右端点等于 `tail`，将 `tail` 左移到新区间起点。否则，将合并后的有限空洞同时加入两份索引。地址及地址之和使用 `ll`，避免多次分配后超出 `int` 范围。

**正确性**

两份索引始终保存同一组极大的有限空闲段，尾部空闲内存由 `tail` 表示。因此，`st` 中第一个满足长度要求的元素恰好符合最短、同长最左的分配规则。

分配只占用所选区间的左端，释放则合并所有相接空洞，都会保持上述性质。队列的循环指针和向量顺序也分别对应写入地址与队列编号，所以三种操作均与题意一致。

**复杂度**

每次分配或释放的空闲区间维护耗时 $O(\log q)$。发送和向量删除最坏耗时 $O(q)$。

总时间复杂度为 $O(q^2+q\log q)$，空间复杂度 $O(n+q)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=105,M=10;
int n,q,p;
char op[M];
struct node{
    ll l,len,pos;
};
vector<node>g[N];
map<ll,ll>mp;
set<P>st;
void erase(map<ll,ll>::iterator it){
    st.erase(P(it->second,it->first));
    mp.erase(it);
}
void add(ll l,ll len){
    if(!len)return;
    mp[l]=len;
    st.insert(P(len,l));
}
int main(){
    scanf("%d%d",&n,&q);
    ll tail=0;
    while(q--){
        scanf("%s%d",op,&p);
        if(op[0]=='n'){
            ll len,l;
            scanf("%lld",&len);
            auto it=st.lower_bound(P(len,-1));
            if(it==st.end()){
                l=tail;
                tail+=len;
            }
            else{
                ll rem=it->first;
                l=it->second;
                erase(mp.find(l));
                add(l+len,rem-len);
            }
            g[p].push_back({l,len,0});
            printf("%lld\n",l);
        }
        else if(op[0]=='s'){
            ll ans=0;
            for(auto &x:g[p]){
                ans+=x.l+x.pos;
                x.pos=(x.pos+1)%x.len;
            }
            printf("%lld\n",ans);
        }
        else{
            int id;
            scanf("%d",&id);
            --id;
            node x=g[p][id];
            g[p].erase(g[p].begin()+id);
            ll l=x.l,r=l+x.len;
            auto it=mp.lower_bound(l);
            if(it!=mp.begin()){
                auto pre=prev(it);
                if(pre->first+pre->second==l){
                    l=pre->first;
                    erase(pre);
                }
            }
            it=mp.lower_bound(r);
            if(it!=mp.end() && it->first==r){
                r+=it->second;
                erase(it);
            }
            if(r==tail)tail=l;
            else add(l,r-l);
        }
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 异或

标签：`数位` · `线段树` · `懒标记`

本地验证见 [VALIDATION.md](../tests/202603/VALIDATION.md)，重构版尚未在线重新提交。

### 题意

把两个非负整数写成奇数 $k$ 进制，每一位相加后对 $k$ 取模，不产生进位，定义运算 $\oplus_k$。定义 $f(0)=0$、$f(x)=x\oplus_k f(x-1)$。需要维护一个非负整数数组，支持区间修改与区间查询。

输入先给出 `n m k`，接着给出长度为 $n$ 的数组，随后给出 $m$ 次操作。数据范围为 $1\le n\le5\times10^5$、$1\le m\le10^4$、$11\le k\le10^9$，且 $k$ 为奇数；保证 $1\le l\le r\le n$，所有时刻的数组元素和输入的修改值均为非负整数，不超过 $10^{12}$。操作格式如下：

- `1 l r v`：将区间内每个元素替换为 $a_i\oplus_k v$。
- `2 l r`：查询区间内所有 $f(a_i)$ 的 $\oplus_k$。

对每个 `2 l r` 操作，输出一行一个非负整数，表示对应的区间查询结果。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603D/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202603D)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce729a67df0b81749b56b)。

### 题解

**先消去函数递推**

设 $x$ 的数位为 $d_0,d_1,\ldots$，最低位编号为 0。$f(x)$ 的每一位，就是 $0$ 到 $x$ 在这一位的数字和对 $k$ 取模。

最低位每个完整循环的和为 $k(k-1)/2$。因为 $k$ 为奇数，这个和是 $k$ 的倍数，因此只剩最后一段：

$$f(x)_0=\frac{d_0(d_0+1)}2\bmod k.$$

对于第 $j>0$ 位，每个完整数字块出现 $k^j$ 次，贡献同样被 $k$ 整除。最后未完成的数字块贡献为 $d_j((x\bmod k^j)+1)$，模 $k$ 后得到

$$f(x)_j=d_j(d_0+1)\bmod k.$$

**线段树维护数位和与乘积和**

每个节点维护

$$S_j=\sum d_j,\qquad P_j=\sum d_0d_j\pmod k.$$

其中，$P_0$ 就是最低位的平方和。查询时，最低位为 $(S_0+P_0)\cdot (k+1)/2\bmod k$，其余位为 $(S_j+P_j)\bmod k$。

这里除以 2 要乘模逆元，不能在取模后直接做整数除法。$k$ 可以是合数，只要它是奇数，2 的模逆元就是 $(k+1)/2$。

**推导区间修改公式**

设修改值的各位为 $c_j$，当前节点区间长度为 $L$。修改后，$d_0$ 和 $d_j$ 分别加上 $c_0$、$c_j$，展开乘积得到

$$P'_j=P_j+c_0S_j+c_jS_0+Lc_0c_j\pmod k,$$

$$S'_j=S_j+Lc_j\pmod k.$$

代码中的 `s`、`p`、`tag` 分别保存数位和、乘积和与数位增量。先更新全部 `p`，再更新 `s` 和 `tag`，保证乘积公式中的 $S$ 均为旧值。

懒标记按位相加并取模，下放时使用各子区间自身的长度。连续乘法之间要保留取模：先算 `v[0]*v[j]%k`，再乘区间长度，保证中间结果在 `ll` 范围内。

**数位数与建树**

修改不产生进位，数位数不会增加。由于 $11^{11}\le10^{12}<11^{12}$，最多只需维护 12 位。

线段树从 $[1,n]$ 递归建树，每个节点保存自己的左右端点和统计量。下传时，由子节点的左右端点计算各自长度，不要求两段等长。

**正确性**

逐位求和消去了 $f$ 的递推，所得查询式恰好表示区间内所有 $f(a_i)$ 的数位和。

叶子节点直接计算 $S_j,P_j$，父节点按位相加。修改公式与逐元素加数位后的统计量一致，懒标记合并也与连续修改等价。因此节点始终保存正确统计量，查询合并后按进制重建，就得到答案。

**复杂度**

设数位数为 $D\le12$。建树时间 $O(nD)$，每次操作时间 $O(D\log n)$，空间复杂度 $O(nD)$。

源码按最大规模预留 $2^{20}$ 个节点，每个节点保存两个端点和三组 12 位的 `ll` 数组，节点数组容量约为 296 MiB。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<19,M=12;
int n,m,d,op,l,r;
ll k,a[M],ans[M];
void split(ll x,ll *v){
    for(int j=0;j<d;++j){
        v[j]=x%k;
        x/=k;
    }
}
struct segtree{
    int n;
    struct node{
        int l,r;
        ll s[M],p[M],tag[M];
    }e[N<<1];
    #define l(p) e[p].l
    #define r(p) e[p].r
    void pushup(int p){
        for(int j=0;j<d;++j){
            e[p].s[j]=(e[p<<1].s[j]+e[p<<1|1].s[j])%k;
            e[p].p[j]=(e[p<<1].p[j]+e[p<<1|1].p[j])%k;
        }
    }
    void apply(int p,ll *v){
        node &t=e[p];
        int len=r(p)-l(p)+1;
        for(int j=0;j<d;++j){
            ll w=v[0]*v[j]%k;
            t.p[j]=(t.p[j]+v[0]*t.s[j]+v[j]*t.s[0]+w*len)%k;
        }
        for(int j=0;j<d;++j){
            t.s[j]=(t.s[j]+v[j]*len)%k;
            t.tag[j]=(t.tag[j]+v[j])%k;
        }
    }
    void pushdown(int p){
        bool ok=0;
        for(int j=0;j<d;++j){
            ok|=e[p].tag[j]!=0;
        }
        if(!ok)return;
        apply(p<<1,e[p].tag);
        apply(p<<1|1,e[p].tag);
        memset(e[p].tag,0,sizeof e[p].tag);
    }
    void build(int p,int x,int y){
        l(p)=x;r(p)=y;
        if(x==y){
            ll v;
            scanf("%lld",&v);
            split(v,e[p].s);
            for(int j=0;j<d;++j){
                e[p].p[j]=e[p].s[0]*e[p].s[j]%k;
            }
            return;
        }
        int mid=(x+y)>>1;
        build(p<<1,x,mid);
        build(p<<1|1,mid+1,y);
        pushup(p);
    }
    void init(int x){
        n=x;
        build(1,1,n);
    }
    void update(int p,int x,int y){
        if(x<=l(p) && r(p)<=y){
            apply(p,a);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(x<=mid)update(p<<1,x,y);
        if(y>mid)update(p<<1|1,x,y);
        pushup(p);
    }
    void query(int p,int x,int y){
        if(x<=l(p) && r(p)<=y){
            for(int j=0;j<d;++j){
                ans[j]=(ans[j]+e[p].s[j]+e[p].p[j])%k;
            }
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(x<=mid)query(p<<1,x,y);
        if(y>mid)query(p<<1|1,x,y);
    }
}tr;
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    for(ll x=1e12;x;x/=k){
        ++d;
    }
    tr.init(n);
    while(m--){
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            ll x;
            scanf("%lld",&x);
            split(x,a);
            tr.update(1,l,r);
        }
        else{
            memset(ans,0,sizeof ans);
            tr.query(1,l,r);
            ans[0]=ans[0]*((k+1)/2)%k;
            ll val=0;
            for(int j=d-1;j>=0;--j){
                val=val*k+ans[j];
            }
            printf("%lld\n",val);
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 旅游计划 - Easy Ver.

标签：`树链剖分` · `树状数组` · `随机化` · `在线查询`

本地验证见 [VALIDATION.md](../tests/202603/VALIDATION.md)，重构版尚未在线重新提交。

### 题意

树上每条边最初都未翻修。车辆出发时轮胎完好，到维修站后才能修复，因此在起点、终点及途经维修站划出的每段路上，最多经过一条未修边。给定固定的 $m$ 条旅游计划，支持修好一条边，以及查询当前可行的计划数。

输入依次为 `n X`、$n-1$ 条树边、维修站数 $k$ 及其编号、计划数 $m$ 及各计划的两个端点、事件数 $q$ 及各事件。事件格式如下：

- `1 u v`：两个端点均先异或 `X*last` 解码，再将对应的边修好。
- `2`：输出当前可行的计划数，并将 `last` 更新为本次答案。

数据范围为 $2\le n\le10^5$、$1\le m\le10^5$、$1\le k\le20$、$1\le q\le2\times10^5$、$X\in\{0,1\}$；城市编号从 1 到 $n$，维修站互不相同，每个计划的两个端点不同。保证每次翻修的边存在且此前未翻修。`last` 表示上一次查询的答案，初始 `last=0`。

对每个 `2` 事件，输出一行一个整数，表示当前可行的旅游计划数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202603E/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202603E)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce72ba67df0b81749b59e)。

### 题解

**先将计划按维修站分段**

对计划 $(s,t)$，使用距离等式

$$\operatorname{dist}(s,u)+\operatorname{dist}(u,t)=\operatorname{dist}(s,t)$$

判断维修站 $u$ 是否在路径上，再按到 $s$ 的距离排序。将起点、终点也加入，去重后，相邻两点之间就是一个待检查的路段。

长度不超过 1 的路段始终可行，可以忽略。其余路段按无序端点对去重，记录依赖它的所有计划。`need[i]` 表示第 $i$ 条计划尚未达标的路段数，降为 0 时，答案加一。

设不同路段数为 $S$。维修站之间的路段最多有 $\binom{k}{2}$ 种，其余路段每条计划至多产生两个，因此

$$S\le2m+\binom{k}{2}.$$

**用两条见证边监控不合格路段**

一个路段只要还剩至少两条未修边，就不可行。从中均匀随机选择两条作为见证，将该路段登记在这两条边的监听列表中。

如果修好的是其他边，两条见证都还在，路段一定仍不可行，无需处理。只有见证边被修好，才重新统计这个路段：

- 若仍有至少两条未修边，重新随机选择两条见证。
- 若未修边不超过一条，将路段永久标记为可行，并更新依赖计划的 `need`。

每次重新检查都增加版本号。监听记录保存路段编号与版本号，旧版本直接跳过，避免重复处理。

**树链剖分与均匀抽样**

树链剖分将路径拆成 $O(\log n)$ 个连续区间。把每条边放在较深端点的 `dfn` 位置，树状数组中未修边记为 1，修好后减一。

检查路段时，先求各区间中的未修边数，得到总数 `tot`。在 $1$ 到 `tot` 中随机选择两个不同的秩，再根据区间计数和树状数组的 `kth` 定位到具体边。这样每条剩余未修边被选中的机会相同，随机选树上点则不能保证。

**正确性**

任意两条未修见证都能证明该路段不可行，所以随机选择不会造成误判。如果一个路段从不可行变为可行，它的未修边数必然降到了 1。此前选择的两条见证不可能都留下，因此至少有一条被修好，程序一定会触发重新检查。

可行路段之后只会继续减少未修边，不会重新变差。每个路段只在首次可行时更新依赖计划，`need` 恰好记录未达标路段数，所以总答案准确。

**随机性与复杂度**

对一条当前还有 $d$ 条未修边的路段，下一条被修好的边命中见证的概率为 $2/d$。对固定合法输入，累加这些概率，每个路段重新检查次数的期望为 $O(\log n)$。

答案与抽样无关，随机性只影响耗时。这是 Las Vegas 算法，不是近似计数。

预处理树状数组与计划分段的时间为 $O(n\log n+m(k+1)\log n)$。每次检查路段需要 $O(\log^2 n)$，在线维护的期望总时间为 $O(S\log^3 n+q\log n)$。

依赖关系共 $O(m(k+1))$ 条，监听记录的期望数量为 $O(S\log n)$。总空间复杂度期望为 $O(n+m(k+1)+S\log n)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=1e5+10;
int n,X,k,m,ans,need[N];
vector<P>watch[N];
struct node{
    int u,v,ver;
    bool ok;
    vector<int>g;
};
vector<node>seg;
mt19937 rng(random_device{}());
struct BIT{
    int n,pw,tr[N];
    void init(int m){
        n=m;
        pw=1;
        while((pw<<1)<=n){
            pw<<=1;
        }
        memset(tr,0,(n+1)*sizeof(*tr));
    }
    void add(int x,int v){
        for(int i=x;i<=n;i+=i&-i){
            tr[i]+=v;
        }
    }
    int sum(int x){
        int ans=0;
        for(int i=x;i;i-=i&-i){
            ans+=tr[i];
        }
        return ans;
    }
    int kth(int k){
        int x=0;
        for(int i=pw;i;i>>=1){
            if(x+i<=n && k>tr[x+i]){
                x+=i;
                k-=tr[x];
            }
        }
        return x+1;
    }
}tr;
namespace HLD{
    int tim,fa[N],dep[N],sz[N],son[N],top[N],dfn[N],at[N],ord[N];
    vector<int>g[N];
    void build(){
        int cnt=1;
        ord[1]=1;
        for(int i=1;i<=cnt;++i){
            int u=ord[i];
            sz[u]=1;
            for(int &v:g[u]){
                if(v==fa[u])continue;
                fa[v]=u;
                dep[v]=dep[u]+1;
                ord[++cnt]=v;
            }
        }
        for(int i=n;i>1;--i){
            int u=ord[i],p=fa[u];
            sz[p]+=sz[u];
            if(sz[u]>sz[son[p]])son[p]=u;
        }
        vector<P>st;
        st.push_back(P(1,1));
        while(!st.empty()){
            P p=st.back();
            st.pop_back();
            for(int u=p.first;u;u=son[u]){
                top[u]=p.second;
                dfn[u]=++tim;
                at[tim]=u;
                for(int &v:g[u]){
                    if(fa[v]==u && v!=son[u]){
                        st.push_back(P(v,v));
                    }
                }
            }
        }
    }
    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]){
                swap(u,v);
            }
            u=fa[top[u]];
        }
        return dep[u]<dep[v]?u:v;
    }
    int dist(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
}
using namespace HLD;
void refresh(int id){
    node &s=seg[id];
    ++s.ver;
    vector<P>part;
    int u=s.u,v=s.v;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]){
            swap(u,v);
        }
        part.push_back(P(dfn[top[u]],dfn[u]));
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]){
        swap(u,v);
    }
    if(u!=v){
        part.push_back(P(dfn[u]+1,dfn[v]));
    }
    vector<int>cnt;
    int tot=0;
    for(auto &[l,r]:part){
        int c=tr.sum(r)-tr.sum(l-1);
        cnt.push_back(c);
        tot+=c;
    }
    if(tot<=1){
        s.ok=1;
        for(int &i:s.g){
            if(--need[i]==0)++ans;
        }
        return;
    }
    uniform_int_distribution<int> rx(1,tot),ry(1,tot-1);
    int x=rx(rng),y=ry(rng);
    if(y>=x)++y;
    for(int i=0;i<2;++i){
        int rank=i?y:x;
        for(int j=0;j<(int)part.size();++j){
            if(rank>cnt[j]){
                rank-=cnt[j];
            }
            else{
                int p=tr.kth(tr.sum(part[j].first-1)+rank);
                watch[at[p]].push_back(P(id,s.ver));
                break;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&X);
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build();
    scanf("%d",&k);
    vector<int>sta(k);
    for(int &u:sta){
        scanf("%d",&u);
    }
    scanf("%d",&m);
    seg.reserve(2*m+k*(k-1)/2);
    map<P,int>ids;
    for(int i=0;i<m;++i){
        int s,t;
        scanf("%d%d",&s,&t);
        int len=dist(s,t);
        vector<P>p;
        p.push_back(P(0,s));
        p.push_back(P(len,t));
        for(int &u:sta){
            int d=dist(s,u);
            if(d+dist(u,t)==len){
                p.push_back(P(d,u));
            }
        }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        for(int j=1;j<(int)p.size();++j){
            if(p[j].first-p[j-1].first<=1)continue;
            int u=p[j-1].second,v=p[j].second;
            if(u>v){
                swap(u,v);
            }
            auto [it,ok]=ids.emplace(P(u,v),(int)seg.size());
            if(ok){
                seg.push_back({u,v,0,0,{}});
            }
            seg[it->second].g.push_back(i);
            ++need[i];
        }
    }
    ids.clear();
    for(int i=0;i<m;++i){
        if(!need[i])++ans;
    }
    tr.init(n);
    for(int u=2;u<=n;++u){
        tr.add(dfn[u],1);
    }
    for(int i=0;i<(int)seg.size();++i){
        refresh(i);
    }
    int q,last=0;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==2){
            printf("%d\n",ans);
            last=ans;
        }
        else{
            int u,v;
            scanf("%d%d",&u,&v);
            u^=X*last;
            v^=X*last;
            if(dep[u]<dep[v]){
                swap(u,v);
            }
            tr.add(dfn[u],-1);
            auto cur=std::move(watch[u]);
            for(auto &[id,ver]:cur){
                if(!seg[id].ok && seg[id].ver==ver){
                    refresh(id);
                }
            }
        }
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202603/VALIDATION.md)
- [a-global-report.json](../tests/202603/a-global-report.json)
- [abc-boundary-report.json](../tests/202603/abc-boundary-report.json)
- [d-boundary-report.json](../tests/202603/d-boundary-report.json)
- [d-template-followup-report.json](../tests/202603/d-template-followup-report.json)
- [e-report.json](../tests/202603/e-report.json)
- [retained-cases.json](../tests/202603/retained-cases.json)
- [retained-report.json](../tests/202603/retained-report.json)
- [summary.json](../tests/202603/summary.json)
- [verify-a-global.py](../tests/202603/verify-a-global.py)
- [verify-abc.py](../tests/202603/verify-abc.py)
- [verify-d.py](../tests/202603/verify-d.py)
- [verify-e.py](../tests/202603/verify-e.py)
- [verify-retained.py](../tests/202603/verify-retained.py)

<!-- local-validation-attachments:end -->
