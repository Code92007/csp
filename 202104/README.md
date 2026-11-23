---
title: "CSP 202104 五题题解"
contest: "202104"
contest_month: "2021-04"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "计数数组", "直方图", "二维前缀和", "矩形查询", "状态机", "优先队列", "有序集合", "模拟", "动态规划", "因数", "计数", "最短路", "中国剩余定理", "扩展欧几里得", "周期"]
status: "published"
problems: [{"id": "A", "title": "灰度直方图", "tags": ["计数数组", "直方图"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "当前重构版：C++17 编译通过，2 个保存用例、60 组独立对拍及 1 组边界/压力通过；UBSan 共 63 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16036"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce971a67df0b81749c1a2"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305946069", "source_sha256": "cb04b1e64425e465d51f4d3e823af05735f5c3f8dd0928971918d527e62604c8"}}, {"id": "B", "title": "邻域均值", "tags": ["二维前缀和", "矩形查询"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "当前重构版：C++17 编译通过，2 个保存用例、100 组独立对拍及 1 组边界/压力通过；UBSan 共 103 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16037"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce972a67df0b81749c1b8"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305946624", "source_sha256": "d7e2bd6ce9f7665c2fc211365c95c7a3e09dcdac58a3a2944cdec0c56ef00672"}}, {"id": "C", "title": "DHCP 服务器", "tags": ["状态机", "优先队列", "有序集合", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "当前重构版：C++17 编译通过，2 个保存用例、100 组独立对拍及 1 组边界/压力通过；UBSan 共 103 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16038"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adceb1074ace1cba9a1bca0"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305947294", "source_sha256": "c7cdcf35a856adecb28fca6057aff11acc7d1aba5196d514c012d1c46d2b025f"}}, {"id": "D", "title": "校门外的树", "tags": ["动态规划", "因数", "计数"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "当前重构版：C++17 编译通过，2 个保存用例、95 组独立对拍及 4 组边界/压力通过；UBSan 共 101 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16039"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adceb1274ace1cba9a1bca8"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305948508", "source_sha256": "45455ae0cfa0766b11ba60e26ec3f73e3b374a4e5d2c2b9e8dab4d61fdca2c84"}}, {"id": "E", "title": "疫苗运输", "tags": ["最短路", "中国剩余定理", "扩展欧几里得", "周期"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "当前重构版：C++17 编译通过，3 个保存用例、60 组独立对拍及 2 组边界/压力通过；UBSan 共 65 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202104E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202104E/"}, {"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16040"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add984074ace1cba9a1f29d"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305949490", "source_sha256": "294e801f8822119af5dd27d341ae76ab81ee536e48d6d1ae979435541b27c072"}, "previous_luogu": {"status": "failed", "score": 95, "verdict": "Time Exceeded", "record": "https://www.luogu.com.cn/record/305496224", "note": "历史提交记录，未用于当前源码的验证；当前优化版已另行提交并逐字核对。"}}]
---

# CSP 202104 五题题解

[原页面](https://code92007.github.io/csp/#/contest/202104) · [验证记录](../tests/202104/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 灰度直方图

标签：`计数数组` · `直方图`

本地：63 组优化版、63 组 UBSan 验证通过，详见 [验证记录](../tests/202104/VALIDATION.md)。

### 题意

给定一幅灰度图，统计每种灰度值出现的像素数，得到灰度直方图。

输入先给出 $n,m,L$，再给出 $n\times m$ 矩阵，元素均在 $[0,L)$。满足 $1\le n,m\le500$、$4\le L\le256$。

按灰度值从 $0$ 到 $L-1$ 输出出现次数，共一行。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16036)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104A)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104A/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce971a67df0b81749c1a2)（accepted，100 分；复刻评测）。

### 题解

**直接计数**

读到灰度值 $x$ 时令 `cnt[x]` 加一，最后依次输出计数数组。

**正确性与复杂度**

每个像素恰好给其灰度值贡献一次，因此计数就是直方图。时间 $O(nm+L)$，空间 $O(L)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=260;
int n,m,l,x,cnt[N];
int main(){
    scanf("%d%d%d",&n,&m,&l);
    for(int i=0;i<n*m;++i){
        scanf("%d",&x);
        ++cnt[x];
    }
    for(int i=0;i<l;++i){
        printf("%d%c",cnt[i],i==l-1?'\n':' ');
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 邻域均值

标签：`二维前缀和` · `矩形查询`

本地：103 组优化版、103 组 UBSan 验证通过，详见 [验证记录](../tests/202104/VALIDATION.md)。

### 题意

对方阵中每个像素，取横、纵坐标差都不超过 $r$ 的邻域，并裁剪到图像边界内。若邻域平均灰度不超过 $t$，该像素属于较暗区域，统计这样的像素数。

输入先给出 $n,L,r,t$，再给出 $n\times n$ 灰度矩阵。满足 $1\le n\le600$、$1\le r\le100$、$2\le t<L\le256$，元素均在 $[0,L)$。

输出较暗区域的像素总数。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16037)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104B)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104B/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce972a67df0b81749c1b8)（accepted，100 分；复刻评测）。

### 题解

**二维前缀和**

预处理二维前缀和，便可用四个前缀值计算任意邻域矩形的灰度和。对每个像素，分别把邻域的四条边裁剪到矩阵范围。

设区域和为 $sum$、格子数为 $cnt$，直接判断 $sum\le t\cdot cnt$，无需浮点除法。

**正确性**

裁剪后的矩形恰好是定义中的邻域，前缀和容斥得到其准确总和。两边乘正数 $cnt$ 不改变比较方向，因此整数比较等价于平均值不超过阈值。

**复杂度**

时间 $O(n^2)$，空间 $O(n^2)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=610;
int n,l,r,t,ans;
ll s[N][N];
int main(){
    scanf("%d%d%d%d",&n,&l,&r,&t);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x;
            scanf("%d",&x);
            s[i][j]=x+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int a=max(1,i-r),b=max(1,j-r);
            int c=min(n,i+r),d=min(n,j+r);
            ll sum=s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
            ans+=(sum<=1ll*t*(c-a+1)*(d-b+1));
        }
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. DHCP 服务器

标签：`状态机` · `优先队列` · `有序集合` · `模拟`

本地：103 组优化版、103 组 UBSan 验证通过，详见 [验证记录](../tests/202104/VALIDATION.md)。

### 题意

模拟一个 DHCP 服务器的地址分配、确认、续租和过期处理。地址有未分配、待分配、占用、过期四种状态；待分配到期后清空占用者，占用到期后保留占用者。

输入先给出地址池大小 $N$、默认租期、最长租期、最短租期和本机名，再给出报文数量及按时刻递增的报文。满足 $N$、报文数不超过 $10^4$，主机名长度不超过 $20$，输入时间与租期参数不超过 $10^9$。

每条报文由时刻、发送主机、接收主机、类型、地址和请求到期时刻组成。只处理符合接收方与类型规则的 `DIS`、`REQ` 报文，租期需限制在最短和最长值之间。

按发送顺序输出服务器产生的 `OFR`、`ACK`、`NAK` 报文。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16038)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104C)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104C/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adceb1074ace1cba9a1bca0)（accepted，100 分；复刻评测）。

### 题解

**用状态机维护地址**

每个地址记录状态、占用者、到期时刻和版本号。两个有序集合分别保存未分配、过期地址，哈希表保存占用者到地址的索引。

最小堆记录租约到期事件。每次处理报文前，先弹出所有已到期事件；若版本号已经改变，说明它是旧租约，直接丢弃。有效事件按当前状态完成到期迁移。

**按规则处理报文**

先过滤不合法的接收方或类型。`DIS` 只能发给 `*`，发给其他服务器的 `REQ` 只释放该客户端的待分配地址，其余不响应。

收到有效 `DIS` 时，依次选择该客户端原有地址、最小未分配地址、最小过期地址；均不存在则忽略。选中地址改为待分配，并发送 `OFR`。

收到发给本机的 `REQ` 时，检查地址范围与占用者，不符则发送 `NAK`；符合则不论旧状态都改为占用，并发送 `ACK`。

请求到期时刻为零时使用默认租期；否则把“请求到期时刻减当前时刻”限制在租期上下界，再加回当前时刻。更新租约时递增版本号，并压入新事件。

**正确性**

每个客户端首次只能得到一个地址，后续请求会复用其已有地址，因此占用者索引准确。到期事件先于当前报文处理，旧版本事件被忽略；每次迁移同步修改状态、集合和索引，依时间顺序归纳即可保证模拟与规则一致。

**复杂度**

时间 $O((N+q)\log(N+q))$，空间 $O(N+q)$，其中 $q$ 为报文数。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> E;
const int N=10010,M=25;
int n,q;
ll def,hi,lo;
char host[M],from[M],to[M],type[M];
struct node{
    int st,ver;
    ll end;
    string name;
}a[N];
set<int>g,h;
unordered_map<string,int>id;
priority_queue<E,vector<E>,greater<E>>ev;
void clear(int x){
    id.erase(a[x].name);
    a[x].name.clear();
    a[x].st=0;
    a[x].end=0;
    ++a[x].ver;
    g.insert(x);
}
int main(){
    scanf("%d%lld%lld%lld%s%d",&n,&def,&hi,&lo,host,&q);
    for(int i=1;i<=n;++i){
        g.insert(i);
    }
    while(q--){
        ll t,end;
        int x;
        scanf("%lld%s%s%s%d%lld",&t,from,to,type,&x,&end);
        while(!ev.empty() && get<0>(ev.top())<=t){
            auto [time,x,ver]=ev.top();
            ev.pop();
            if(ver!=a[x].ver)continue;
            if(a[x].st==1)clear(x);
            else if(a[x].st==2){
                a[x].st=3;
                a[x].end=0;
                h.insert(x);
            }
        }
        string src=from,dst=to,op=type;
        if(dst!=host && dst!="*" && op!="REQ")continue;
        if(op!="DIS" && op!="REQ")continue;
        if(dst=="*" && op!="DIS")continue;
        if(dst==host && op=="DIS")continue;
        if(op=="REQ" && dst!=host){
            auto it=id.find(src);
            if(it!=id.end() && a[it->second].st==1)clear(it->second);
            continue;
        }
        if(op=="DIS"){
            auto it=id.find(src);
            if(it!=id.end())x=it->second;
            else if(!g.empty())x=*g.begin();
            else if(!h.empty())x=*h.begin();
            else continue;
            if(!a[x].name.empty())id.erase(a[x].name);
            a[x].name=src;
            id[src]=x;
            a[x].st=1;
        }
        else{
            if(x<1 || x>n || a[x].name!=src){
                printf("%s %s NAK %d 0\n",host,from,x);
                continue;
            }
            a[x].st=2;
        }
        g.erase(x);h.erase(x);
        if(!end)a[x].end=t+def;
        else a[x].end=t+clamp(end-t,lo,hi);
        ++a[x].ver;
        ev.push({a[x].end,x,a[x].ver});
        printf("%s %s %s %d %lld\n",host,from,op=="DIS"?"OFR":"ACK",x,a[x].end);
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 校门外的树

标签：`动态规划` · `因数` · `计数`

本地：101 组优化版、101 组 UBSan 验证通过，详见 [验证记录](../tests/202104/VALIDATION.md)。

### 题意

数轴上有递增排列的障碍物。可选择部分障碍物作为分段端点，每段至少种一棵树，树与两端点构成整数公差的等差数列，且树不能落在障碍物上。按最终种树坐标集合区分方案，求不同方案数。

输入先给出 $n$，再给出严格递增的坐标 $a_1,\ldots,a_n$。满足 $2\le n\le1000$、$0\le a_i\le10^5$，保证至少存在一种合法方案。

输出方案数对 $10^9+7$ 取模的结果。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16039)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104D)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104D/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adceb1274ace1cba9a1bca8)（accepted，100 分；复刻评测）。

### 题解

**枚举一段的合法公差**

固定端点 $a_l,a_r$，公差 $d$ 必须是 $a_r-a_l$ 的真因子，才能至少种一棵树。若 $d$ 整除某个内部障碍物到左端的距离，就会在障碍物上种树，需要排除。

固定 $l$，按 $r$ 递增枚举。当前距离的未禁用真因子数，就是这一段的选择数；统计完后，把当前距离的全部因子标为禁用，因为当前右端会成为下一轮的内部障碍。用 $l$ 作时间戳，无需反复清空标记。

**按最后一段转移**

令 $dp[r]$ 为从最左端到障碍物 $r$ 的方案数，初始 $dp[1]=1$。若当前段有 $cnt$ 种合法公差，则

$$dp[r]\mathrel{+}=dp[l]\cdot cnt.$$

**为什么不会重复统计同一树集合**

给定最终树集合，从最左障碍开始，第一棵树决定首段公差。右端只能是首个与左端距离被该公差整除的后续障碍，否则会在更早的障碍上种树。

所以首段唯一确定，递归处理其余部分，整个划分也唯一。动态规划枚举全部合法末段，因此不重不漏。

**复杂度**

用筛法预处理因子。设最大距离为 $A$，范围内最大因子数为 $D$，时间 $O(A\log A+n^2D)$，空间 $O(A\log A+n)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010,M=1e5+10,mod=1e9+7;
int n,a[N],ed[M];
ll dp[N];
vector<int>d[M];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int m=a[n]-a[1];
    for(int i=1;i<=m;++i){
        for(int j=i;j<=m;j+=i){
            d[j].push_back(i);
        }
    }
    memset(ed,-1,sizeof ed);
    dp[1]=1;
    for(int l=1;l<n;++l){
        for(int r=l+1;r<=n;++r){
            int x=a[r]-a[l],cnt=0;
            for(int &v:d[x]){
                cnt+=(v<x && ed[v]!=l);
            }
            dp[r]=(dp[r]+dp[l]*cnt)%mod;
            for(int &v:d[x]){
                ed[v]=l;
            }
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
```

<a id="problem-e"></a>

## E. 疫苗运输

标签：`最短路` · `中国剩余定理` · `扩展欧几里得` · `周期`

本地：65 组优化版、65 组 UBSan 验证通过，详见 [验证记录](../tests/202104/VALIDATION.md)。

### 题意

每条循环线路有一辆车，从时刻 $0$ 开始不断行驶。疫苗从站点 $1$ 出发，可以在起点等车，但途中只能在两车同时到达同一站点时换乘，不能留在中途站点等待，求送达其他站点的最早时刻。

输入先给出站点数 $n$、线路数 $m$，再给出各线路的站点数及按行驶顺序排列的“站点、到下一站耗时”。满足 $n,m\le500$，每条线路的站点互异，每段时间为不超过 $10^6$ 的正整数。

按站点 $2$ 到 $n$ 的顺序逐行输出最早到达时刻，无解输出 `inf`。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202104E)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202104E/)；[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16040)。

原版评测：[记录](https://oj.shumeng.tech/record/6add984074ace1cba9a1f29d)（accepted，100 分；复刻评测）。

### 题解

**把线路作为最短路节点**

不能把站点直接作为普通最短路节点，因为途中不允许卸货等待。但一旦登上一条循环线路，就可以一直留在车上，等待合适的换乘时刻。

设线路 $u$ 周期为 $P_u$，首次到站 $s$ 的时刻为 $a_{u,s}$，之后到站时刻为 $a_{u,s}+kP_u$。令 $d_u$ 为最早登上线路 $u$ 的时刻，起始值是各车首次到达站点 $1$ 的时刻。

**用 CRT 求换乘时刻**

从 $u$ 在公共站 $s$ 换乘到 $v$，需要满足

$$t\equiv a_{u,s}\pmod{P_u},\qquad t\equiv a_{v,s}\pmod{P_v}.$$

令 $g=\gcd(P_u,P_v)$。两偏移之差不能被 $g$ 整除时无解；否则通过模逆求一个最小非负解 $t_0$，其余解相隔 $\operatorname{lcm}(P_u,P_v)$。将 $t_0$ 向上平移到第一个不早于 $d_u$ 的解，即可松弛 $d_v$。

同一对线路的 gcd 和逆元可以复用，分别检查公共站即可。若 $d_v\le d_u$，这次换乘不可能改善 $v$，直接跳过。

**扫描式 Dijkstra**

更晚登上同一辆车不可能获得更早的换乘时刻，因此满足 FIFO 性质，可以每次确定最早的未处理线路。确定线路后，也用它下一次到达各站的时间更新站点答案。

**正确性**

CRT 恰好枚举两车在公共站同时出现的全部时刻，向上取整得到当前可用的最早换乘。FIFO 性质保证 Dijkstra 的定型顺序有效；所有可行运输都对应一串合法线路换乘，因此所得线路与站点最早时间准确。

**复杂度与数值范围**

时间 $O(m^2n+m^2\log P)$，空间 $O(mn)$。单条线路周期不超过 $5\times10^8$，两周期最小公倍数小于 $2.5\times10^{17}$，局部 CRT 可用 64 位整数；多次换乘后的绝对时间用 `__int128` 保存，并自行输出十进制。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 I;
const int N=510;
const I INF=I(1)<<120;
int n,m;
ll p[N],a[N][N];
I d[N],ans[N];
bool vis[N];
ll inv(ll a,ll b){
    ll mod=b,x=1,y=0;
    while(b){
        ll q=a/b,c=a-q*b;
        a=b;b=c;
        c=x-q*y;
        x=y;y=c;
    }
    return (x%mod+mod)%mod;
}
void print(I x){
    if(!x){
        putchar('0');
        return;
    }
    string s;
    while(x){
        s.push_back('0'+x%10);
        x/=10;
    }
    reverse(s.begin(),s.end());
    printf("%s",s.c_str());
}
int main(){
    scanf("%d%d",&n,&m);
    memset(a,-1,sizeof a);
    fill(d,d+m,INF);
    fill(ans,ans+n,INF);
    for(int i=0;i<m;++i){
        int k;
        scanf("%d",&k);
        while(k--){
            int s;
            ll t;
            scanf("%d%lld",&s,&t);
            a[i][s-1]=p[i];
            p[i]+=t;
        }
        if(a[i][0]>=0)d[i]=a[i][0];
    }
    for(int turn=0;turn<m;++turn){
        int u=-1;
        for(int i=0;i<m;++i){
            if(!vis[i] && (u<0 || d[i]<d[u]))u=i;
        }
        if(u<0 || d[u]==INF)break;
        vis[u]=1;
        for(int s=0;s<n;++s){
            if(a[u][s]<0)continue;
            I t=a[u][s];
            if(t<d[u])t+=(d[u]-t+p[u]-1)/p[u]*p[u];
            ans[s]=min(ans[s],t);
        }
        for(int v=0;v<m;++v){
            if(vis[v] || d[v]<=d[u])continue;
            ll g=gcd(p[u],p[v]),mod=p[v]/g;
            ll iv=mod==1?0:inv(p[u]/g,mod),cycle=p[u]*mod;
            for(int s=0;s<n;++s){
                if(a[u][s]<0 || a[v][s]<0)continue;
                ll w=a[v][s]-a[u][s];
                if(w%g)continue;
                ll k=0;
                if(mod>1)k=(w/g*iv%mod+mod)%mod;
                I t=a[u][s]+p[u]*k;
                if(t>=d[v])continue;
                if(t<d[u])t+=(d[u]-t+cycle-1)/cycle*cycle;
                d[v]=min(d[v],t);
            }
        }
    }
    for(int i=1;i<n;++i){
        if(ans[i]==INF)printf("inf");
        else print(ans[i]);
        puts("");
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202104/VALIDATION.md)
- [cases.json](../tests/202104/cases.json)
- [compile.json](../tests/202104/compile.json)
- [constants-followup.json](../tests/202104/constants-followup.json)
- [current-sources.json](../tests/202104/current-sources.json)
- [extra.py](../tests/202104/extra.py)
- [naming-followup.json](../tests/202104/naming-followup.json)
- [newline-followup.json](../tests/202104/newline-followup.json)
- [summary.json](../tests/202104/summary.json)

<!-- local-validation-attachments:end -->
