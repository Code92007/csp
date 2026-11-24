---
title: "CSP 202109 五题题解"
contest: "202109"
contest_month: "2021-09"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "贪心", "前缀最大值", "差分", "阈值枚举", "模拟", "循环数组", "浮点数", "事件延迟", "概率DP", "状态压缩", "期望", "动态树", "LCT", "倍增", "历史版本"]
status: "published"
problems: [{"id": "A", "title": "数组推导", "tags": ["贪心", "前缀最大值"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版未提交：Normal submit page confirms PermissionError for View hidden problems; see 202109A-access.json。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16026"}], "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490510"}, "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。"}, {"id": "B", "title": "非零段划分", "tags": ["差分", "阈值枚举"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版未提交：Normal submit page confirms PermissionError for View hidden problems; see 202109B-access.json。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16027"}], "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490539"}, "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}, "original_validation": "C++17 编译通过；4 个保存样例/回归用例通过；150 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。"}, {"id": "C", "title": "脉冲神经网络", "tags": ["模拟", "循环数组", "浮点数", "事件延迟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16028"}], "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490605"}, "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b058795e5d1fced2e456787", "source_sha256": "3a600da8f273ec2ba089c53b2c334a2e4d89cbd6554e49fbfa2501601bf5bc81", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:50:02.338320+00:00"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。", "oj_before_refactor": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "D", "title": "收集卡牌", "tags": ["概率DP", "状态压缩", "期望"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202109D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16029"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0587fbe5d1fced2e4568c7", "source_sha256": "3a8c7d9f84fb8b9d91f1567ed36a0f36d35070f9261811c33a7765604f522b6e", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:51:19.692764+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305945496", "source_sha256": "d0054cc4dee11a8f6a87b53aa508d7c4dff26aeb6418407984f5a70260c5dbdc"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce96fa67df0b81749c194"}}, {"id": "E", "title": "箱根山岳险天下", "tags": ["动态树", "LCT", "倍增", "历史版本"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版未提交：Normal submit page confirms PermissionError for View hidden problems; see 202109E-access.json。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16030"}], "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490619"}, "oj": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；洛谷民间数据 100 分 Accepted。"}]
---

# CSP 202109 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202109/VALIDATION.md)


<a id="problem-a"></a>

## A. 数组推导

标签：`贪心` · `前缀最大值`

本地验证：45 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202109/VALIDATION.md)。。

原版验证：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490510)。

<!-- refactor-online:A:start -->

重构版未提交：Normal submit page confirms PermissionError for View hidden problems; see 202109A-access.json；未产生新提交或判题结论。

<!-- refactor-online:A:end -->

### 题意

给出非负数组 A 的前缀最大值 B，求所有可能的 A 中，元素和的最大值与最小值。

输入数组长度 n 和 B 的各项，保证 B 单调不降。

先输出最大元素和，再输出最小元素和。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16026)。

### 题解

每个A[i]都不能超过B[i]，全部取B[i]即可满足前缀最大值，因此最大和是ΣB[i]。若B[i]>B[i-1]，新最大值必须由A[i]=B[i]产生；若相等，最小可取0。令B[0]=0即可统一第一项。

这些下界同时可达，选择不会影响未来必须出现的新最大值，所以最小和就是所有严格上升位置的B之和。时间 $O(n)$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll pre,mn,mx,x;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&x);
        mx+=x;
        if(x>pre)mn+=x;
        pre=x;
    }
    printf("%lld\n%lld\n",mx,mn);
    return 0;
}
```

<a id="problem-b"></a>

## B. 非零段划分

标签：`差分` · `阈值枚举`

本地验证：155 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202109/VALIDATION.md)。。

原版验证：**已实现**。C++17 编译通过；4 个保存样例/回归用例通过；150 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490539)。

<!-- refactor-online:B:start -->

重构版未提交：Normal submit page confirms PermissionError for View hidden problems; see 202109B-access.json；未产生新提交或判题结论。

<!-- refactor-online:B:end -->

### 题意

选择正整数阈值 p，将数组中小于 p 的值归零，使剩余的非零连续段尽可能多。

输入数组长度 n 和各项，范围为 n≤$5\times10^5$，值在 0…10000。

输出能得到的最多非零段数。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16027)。

### 题解

每个非零段有且只有一个起点。位置 i 在阈值 p 下成为起点，当且仅当 A[i]≥p 且前一个值 A[i-1]<p（令 A[0]=0）。因此它贡献1的阈值恰为整数区间 `[A[i-1]+1,A[i]]`，仅当右端不小于左端时有效。

对每个有效区间做差分加1，最后扫描所有阈值，前缀和就是该阈值下的段数，取最大值。这个计数直接按段起点建立一一对应，避免删除连续等高元素时的顺序问题。时间 $O(n+V)$，空间 $O(V)$，V=10000。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,x,pre,cur,ans,d[N];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x>pre){
            ++d[pre+1];
            --d[x+1];
        }
        pre=x;
    }
    for(int i=1;i<=10000;++i){
        cur+=d[i];
        ans=max(ans,cur);
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. 脉冲神经网络

标签：`模拟` · `循环数组` · `浮点数` · `事件延迟`

本地验证：83 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202109/VALIDATION.md)。。

原版验证：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490605)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058795e5d1fced2e456787)。

<!-- refactor-online:C:end -->

### 题意

按指定离散方程更新脉冲神经网络。每步先按编号为各脉冲源调用固定随机函数，神经元再用上一时刻的 v、u 和当前输入更新；v≥30 时发放脉冲并重置。

输入神经元数 N、突触数 S、脉冲源数 P、模拟时长 T 和步长 dt，随后是分组神经元参数、各源阈值及突触的起终点、权重、延迟。传播延迟严格为正，随机函数的调用次序不可改变。

输出 T 时刻神经元 v 的最小值、最大值，保留三位小数；再输出整个过程发放次数的最小值、最大值。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16028)。

### 题解

邻接表保存出边。若某结点在 t 发放，就把每条出边权重加到接收者的 t+D 时刻输入。最大延迟为 Dmax，只需长度 Dmax+1 的循环数组保存未来输入；消费当前槽后清零。正延迟保证当前时刻的发放不会影响本时刻其他神经元的更新。

更新前保存旧 v、u，两个新变量都必须使用旧值；输入 I 直接加在 v 上，不再乘 dt。达到阈值时先计数，再执行 v=c、u+=d。随机数使用无符号 64 位整数溢出，并且每个时刻每个源都调用一次，不能只为有出边的源调用。

循环数组中的每个槽始终等于对应未来时刻所有已发放脉冲的权重和，逐时刻归纳得到正确模拟。时间 $O(T(N+P+S))$，空间 $O(N(Dmax+1)+S+P)$。使用 double，最后按三位小数输出。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct neuron{
    double v,u,a,b,c,d;
    int cnt=0;
};
struct edge{
    int v,d;
    double w;
};
int n,s,p,t,delay,ring;
double dt;
ull seed=1;
vector<neuron> a;
vector<int> r;
vector<vector<edge>> g;
vector<vector<double>> in;
void emit(int u,int now){
    for(edge &e:g[u]){
        if(now+e.d<=t)in[(now+e.d)%ring][e.v]+=e.w;
    }
}
int main(){
    scanf("%d%d%d%d%lf",&n,&s,&p,&t,&dt);
    while((int)a.size()<n){
        int cnt;
        neuron x;
        scanf("%d%lf%lf%lf%lf%lf%lf",&cnt,&x.v,&x.u,&x.a,&x.b,&x.c,&x.d);
        while(cnt--){
            a.push_back(x);
        }
    }
    r.resize(p);
    for(int &x:r){
        scanf("%d",&x);
    }
    g.resize(n+p);
    while(s--){
        int u,v,d;
        double w;
        scanf("%d%d%lf%d",&u,&v,&w,&d);
        g[u].push_back({v,d,w});
        delay=max(delay,d);
    }
    ring=delay+1;
    in.assign(ring,vector<double>(n));
    for(int now=1;now<=t;++now){
        for(int i=0;i<p;++i){
            seed=seed*1103515245+12345;
            int val=(seed/65536)%32768;
            if(r[i]>val)emit(n+i,now);
        }
        for(int i=0;i<n;++i){
            neuron &x=a[i];
            double v=x.v,u=x.u;
            x.v=v+dt*(0.04*v*v+5*v+140-u)+in[now%ring][i];
            x.u=u+dt*x.a*(x.b*v-u);
            in[now%ring][i]=0;
            if(x.v>=30){
                x.v=x.c;
                x.u+=x.d;
                ++x.cnt;
                emit(i,now);
            }
        }
    }
    double mn=a[0].v,mx=mn;
    int lo=a[0].cnt,hi=lo;
    for(neuron &x:a){
        mn=min(mn,x.v);
        mx=max(mx,x.v);
        lo=min(lo,x.cnt);
        hi=max(hi,x.cnt);
    }
    printf("%.3f %.3f\n%d %d\n",mn,mx,lo,hi);
    return 0;
}
```

<a id="problem-d"></a>

## D. 收集卡牌

标签：`概率DP` · `状态压缩` · `期望`

本地验证：77 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202109/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce96fa67df0b81749c194)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce96fa67df0b81749c194)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305945496)（民间复刻评测）。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0587fbe5d1fced2e4568c7)。

<!-- refactor-online:D:end -->

### 题意

有 $n$ 种卡牌，每次独立抽中第 i 种的概率为 $p_i$。重复卡变成一枚硬币，k 枚硬币可以换一张未拥有的卡，求集齐全部卡牌的最小期望抽卡次数。

输入 n、k 和各概率，范围为 $n\le16,k\le5$。可以等硬币足够补齐全部缺卡时一次性兑换。

输出最小期望，允许绝对误差 $10^{-4}$。

来源：[公开题面存档](https://www.luogu.com.cn/problem/P16029)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202109D)。

### 题解

**为什么可以推迟兑换？**

提前兑换某张卡后若再抽到它，只获得一枚硬币；如果此前不兑换，就直接得到这张卡，同时保留原来准备兑换所用的 k 枚硬币。因为 $k\ge1$，推迟兑换不会更差。因此只在硬币足够补齐缺卡时停止抽卡即可。

用位掩码 $S$ 表示已经抽到的卡种，c 表示硬币数。设 $E[S][c]$ 为从此状态出发还需抽卡的期望。若 $c\ge k(n-|S|)$，直接兑换，期望为 0。否则先花一次抽卡，然后按抽中卡种分解：

$$E[S][c]=1+\left(\sum_{i\in S}p_i\right)E[S][c+1]+\sum_{i\notin S}p_iE[S\cup\{i\}][c].$$

重复卡使 c 增加，新卡使集合严格增大，所以没有自环，也无需在等式两侧解未知数。按掩码从大到小、硬币数从大到小计算即可；所有严格超集的二进制数都更大。初始答案为 $E[0][0]$。

全概率公式覆盖一次抽卡的全部互斥结果，终止状态与兑换条件一致，故反向 DP 正确。最多 nk 枚硬币就足够，时间 $O(2^n n^2k)$，空间 $O(2^n nk)$。保留足够小数位输出。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1<<16,M=85,K=20;
int n,k,cnt[N];
double p[K],dp[N][M];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%lf",&p[i]);
    }
    int len=1<<n;
    for(int s=1;s<len;++s){
        cnt[s]=cnt[s>>1]+(s&1);
    }
    for(int s=len-2;s>=0;--s){
        int need=(n-cnt[s])*k;
        double sum=0;
        for(int i=0;i<n;++i){
            if(s>>i&1)sum+=p[i];
        }
        for(int c=need-1;c>=0;--c){
            double val=1+sum*dp[s][c+1];
            for(int i=0;i<n;++i){
                if(!(s>>i&1))val+=p[i]*dp[s|(1<<i)][c];
            }
            dp[s][c]=val;
        }
    }
    printf("%.12lf\n",dp[0][0]);
    return 0;
}
```

<a id="problem-e"></a>

## E. 箱根山岳险天下

标签：`动态树` · `LCT` · `倍增` · `历史版本`

本地验证：83 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202109/VALIDATION.md)。。

原版验证：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305490619)。

<!-- refactor-online:E:start -->

重构版未提交：Normal submit page confirms PermissionError for View hidden problems; see 202109E-access.json；未产生新提交或判题结论。

<!-- refactor-online:E:end -->

### 题意

维护一份可以在末尾加入成员或删除末尾成员的名单。操作可以选择某个历史名单中的连续成员，对他们的当前权值乘以 y，或查询当前权值之和。名单是历史版本，权值不是历史快照；退出名单的人仍可能出现在旧名单查询中。

输入 `m p T` 及 m 天的操作，$m\le3\times10^5$，$p<2^{30}$。指定参数按原题异或最近答案解码：

- 操作 1：加入成员或删除末尾成员。
- 操作 2：选择第 $s$ 天结束时名单的第 $l$ 至 $r$ 位成员，将当前权值乘以 $y$。
- 操作 3：查询同样选定成员的当前权值之和。

每次求和输出结果对 p 取模后的值，并作为最近答案。

来源：[公开题面与样例](https://www.luogu.com.cn/problem/P16030)

### 题解

**把所有名单版本组成一棵历史树**

每次加入新成员，新建一个点，其父亲是加入前的名单末尾。删除末尾只把当前指针移到父亲。每一天记录末尾节点 `tail[day]`。于是任何一天的名单，都恰好是虚拟根到该末尾的一条祖先链；成员顺序对应树深度。

预处理新点的倍增祖先。给定历史末尾 $u$ 和名单位置 $l,r$，分别跳到深度为 $l,r$ 的两个祖先，就得到要操作的路径端点。特别注意 $s$ 等于当前操作日时，要使用当前末尾，而不是尚未写入的 `tail[s]`。

**历史树固定身份，动态树维护当前数值**

用 Link-Cut Tree 对这棵只增点的树支持路径乘、路径和。暴露端点路径后，其辅助树聚合值就是答案；乘法懒标记同时作用于节点权值、子树和及已有标记。反转路径时交换左右孩子并翻转反转标记，数值乘法与反转可独立下传。

新成员只需创建一个独立辅助树节点，将其路径父亲设为当时末尾；退队不删除树节点、不撤销乘法，也不切断历史边。否则查询旧名单就会丢失成员。输入解码只针对题面指定的 $x,y$，不能擅自解码历史日期和位置。

**正确性**

父亲关系逐步记录了每次入队前的完整名单，倍增定位因此准确。历史名单区间是祖先链上的连续路径，LCT 对该路径的更新作用于同一批成员的当前值，恰好符合题意。

**复杂度**

每次操作摊还 $O(\log m)$，祖先表空间 $O(m\log m)$；模乘使用 64 位，覆盖 $p<2^{30}$ 的乘积。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10,M=20,K=2;
struct LCT{
    struct node{
        int ch[K],fa;
        ll v,sum,mul=1;
        bool rev;
    }e[N];
    int top,st[N];
    ll mod;
    void init(int p){
        mod=p;
    }
    bool root(int x){
        int p=e[x].fa;
        return e[p].ch[0]!=x && e[p].ch[1]!=x;
    }
    void pushup(int x){
        e[x].sum=(e[x].v+e[e[x].ch[0]].sum+e[e[x].ch[1]].sum)%mod;
    }
    void multiply(int x,ll v){
        if(!x)return;
        e[x].v=e[x].v*v%mod;
        e[x].sum=e[x].sum*v%mod;
        e[x].mul=e[x].mul*v%mod;
    }
    void flip(int x){
        if(!x)return;
        swap(e[x].ch[0],e[x].ch[1]);
        e[x].rev^=1;
    }
    void pushdown(int x){
        if(e[x].rev){
            flip(e[x].ch[0]);
            flip(e[x].ch[1]);
            e[x].rev=false;
        }
        if(e[x].mul!=1){
            multiply(e[x].ch[0],e[x].mul);
            multiply(e[x].ch[1],e[x].mul);
            e[x].mul=1;
        }
    }
    void rotate(int x){
        int p=e[x].fa,g=e[p].fa;
        int d=(e[p].ch[1]==x),v=e[x].ch[d^1];
        if(!root(p))e[g].ch[e[g].ch[1]==p]=x;
        e[x].fa=g;
        e[x].ch[d^1]=p;
        e[p].fa=x;
        e[p].ch[d]=v;
        if(v)e[v].fa=p;
        pushup(p);
        pushup(x);
    }
    void splay(int x){
        top=0;
        int y=x;
        st[++top]=y;
        while(!root(y)){
            y=e[y].fa;
            st[++top]=y;
        }
        for(int i=top;i;--i){
            pushdown(st[i]);
        }
        while(!root(x)){
            int p=e[x].fa,g=e[p].fa;
            if(!root(p)){
                bool same=(e[p].ch[1]==x)==(e[g].ch[1]==p);
                rotate(same?p:x);
            }
            rotate(x);
        }
    }
    void access(int x){
        for(int y=0,u=x;u;y=u,u=e[u].fa){
            splay(u);
            e[u].ch[1]=y;
            pushup(u);
        }
        splay(x);
    }
    void path(int u,int v){
        access(u);
        flip(u);
        access(v);
    }
}tr;
int m,p,t,now,tot,last,up[N][M],dep[N],tail[N];
int at(int u,int d){
    int k=dep[u]-d;
    for(int i=0;i<M;++i){
        if(k>>i&1)u=up[u][i];
    }
    return u;
}
int main(){
    scanf("%d%d%d",&m,&p,&t);
    tr.init(p);
    for(int day=1;day<=m;++day){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            x^=t*last;
            if(!x)now=up[now][0];
            else{
                int u=++tot;
                up[u][0]=now;
                dep[u]=dep[now]+1;
                for(int i=1;i<M;++i){
                    up[u][i]=up[up[u][i-1]][i-1];
                }
                tr.e[u].v=tr.e[u].sum=x%p;
                tr.e[u].fa=now;
                now=u;
            }
        }
        else{
            int s,l,r;
            scanf("%d%d%d",&s,&l,&r);
            int end=s==day?now:tail[s];
            int u=at(end,l),v=at(end,r);
            tr.path(u,v);
            if(op==2){
                int y;
                scanf("%d",&y);
                y^=t*last;
                tr.multiply(v,y%p);
            }
            else{
                last=tr.e[v].sum;
                printf("%d\n",last);
            }
        }
        tail[day]=now;
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202109/VALIDATION.md)
- [b-capacity-followup-report.json](../tests/202109/b-capacity-followup-report.json)
- [boundaries.py](../tests/202109/boundaries.py)
- [d-printf-followup-report.json](../tests/202109/d-printf-followup-report.json)
- [online-update-report.json](../tests/202109/online-update-report.json)
- [online-verdicts.json](../tests/202109/online-verdicts.json)
- [refactor-report.json](../tests/202109/refactor-report.json)
- [statements.json](../tests/202109/statements.json)

<!-- local-validation-attachments:end -->
