---
title: "CSP 201503 五题题解"
contest: "201503"
contest_month: "2015-03"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "矩阵旋转", "坐标映射", "频率统计", "自定义排序", "日期计算", "枚举", "树的直径", "BFS", "点分治", "倍增", "贪心", "树上查询"]
status: "published"
problems: [{"id": "A", "title": "图像旋转", "tags": ["矩阵旋转", "坐标映射"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "当前重构版：C++17 编译通过，1 个保存用例、60 组独立对拍及 1 组边界/压力通过；UBSan 共 62 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb6f774ace1cba9a20ceb"}}, {"id": "B", "title": "数字排序", "tags": ["频率统计", "自定义排序"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "当前重构版：C++17 编译通过，1 个保存用例、100 组独立对拍及 1 组边界/压力通过；UBSan 共 102 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb77c74ace1cba9a20d2d"}}, {"id": "C", "title": "节日", "tags": ["日期计算", "枚举"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "当前重构版：C++17 编译通过，1 个保存用例、100 组独立对拍及 7 组边界/压力通过；UBSan 共 108 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb88c74ace1cba9a20dc5"}}, {"id": "D", "title": "网络延时", "tags": ["树的直径", "BFS"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "当前重构版：C++17 编译通过，2 个保存用例、79 组独立对拍及 1 组边界/压力通过；UBSan 共 82 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb91774ace1cba9a20e42"}}, {"id": "E", "title": "最小花费", "tags": ["点分治", "倍增", "贪心", "树上查询"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "当前重构版：C++17 编译通过，1 个保存用例、257 组独立对拍及 4 组边界/压力通过；UBSan 共 262 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201503E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201503E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb9a174ace1cba9a20ea0"}}]
---

# CSP 201503 五题题解

[原页面](https://code92007.github.io/csp/#/contest/201503) · [验证记录](../tests/201503/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 图像旋转

标签：`矩阵旋转` · `坐标映射`

本地：62 组优化版、62 组 UBSan 验证通过，详见 [验证记录](../tests/201503/VALIDATION.md)。

### 题意

将一个 $n\times m$ 矩阵逆时针旋转 $90^\circ$，求旋转后的图像。

输入 $n,m$，再按行输入矩阵。$1\le n,m\le1000$，元素为不超过 $1000$ 的非负整数。

输出 $m$ 行、每行 $n$ 个整数，表示旋转后的矩阵。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503A)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503A/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addb6f774ace1cba9a20ceb)（accepted，100 分；复刻评测）。

### 题解

原矩阵第 $j$ 列从上到下，变成结果第 $m-1-j$ 行从左到右。因此按原列从右到左、列内原行从上到下输出即可。

**正确性**

以零为起点的坐标映射为 $(i,j)\to(m-1-j,i)$，它对全部格子一一对应，并且恰好表示逆时针旋转。

**复杂度**

时间、空间均为 $O(nm)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,a[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int j=m-1;j>=0;--j){
        for(int i=0;i<n;++i){
            printf("%d%c",a[i][j],i==n-1?'\n':' ');
        }
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 数字排序

标签：`频率统计` · `自定义排序`

本地：102 组优化版、102 组 UBSan 验证通过，详见 [验证记录](../tests/201503/VALIDATION.md)。

### 题意

统计给定整数的出现次数，按次数递减输出；次数相同时按数值递增，每种数只输出一次。

输入整数个数 $n$，再输入 $n$ 个整数。$1\le n\le1000$，所有数均在 $[0,1000]$ 内。

每行输出一种数及其出现次数，顺序满足上述要求。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503B)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503B/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addb77c74ace1cba9a20d2d)（accepted，100 分；复刻评测）。

### 题解

数值范围很小，直接用计数数组统计频率。对每个出现过的数构造二元组 `(-次数,数值)`，按默认字典序排序后输出。

**正确性**

计数数组将相同整数归为一项。第一关键字取负后，次数越多越靠前；第二关键字保证同频率时，小的数先输出，恰好对应题目顺序。

**复杂度**

记数值容量为 $V$、不同数个数为 $u$，时间 $O(n+V+u\log u)$，空间 $O(V)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=1010;
int n,cnt[N],tot;
P a[N];
int main(){
    scanf("%d",&n);
    for(int i=0,x;i<n;++i){
        scanf("%d",&x);
        ++cnt[x];
    }
    for(int i=0;i<N;++i){
        if(cnt[i])a[tot++]=P(-cnt[i],i);
    }
    sort(a,a+tot);
    for(int i=0;i<tot;++i){
        printf("%d %d\n",a[i].second,-a[i].first);
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 节日

标签：`日期计算` · `枚举`

本地：108 组优化版、108 组 UBSan 验证通过，详见 [验证记录](../tests/201503/VALIDATION.md)。

### 题意

某节日定义为每年 $a$ 月第 $b$ 个星期 $c$。求指定年份区间内每年的节日日期，若该月不存在第 $b$ 个星期 $c$，则输出 `none`。

输入 `a b c y1 y2`。$1\le a\le12$，$1\le b\le5$，星期一到星期日用 $1$ 到 $7$ 表示；$1850\le y1\le y2\le2050$。已知 1850 年 1 月 1 日是星期二。

每年输出一行，日期格式为 `yyyy/mm/dd`，月、日补足两位；不存在时输出 `none`。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503C)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503C/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addb88c74ace1cba9a20dc5)（accepted，100 分；复刻评测）。

### 题解

从 1850 年起维护元旦的星期，每过一年加上该年的天数。进入目标年份后，再加上目标月之前的各月天数，得到该月 1 日的星期 $f$；统一把星期日表示为 $0$。

第一个目标星期的日号为 $1+(c\bmod7-f+7)\bmod7$，第 $b$ 个再加 $7(b-1)$。若超过本月天数，就不存在。

**正确性**

同一星期每隔七天重复，因此公式按顺序列出该月的目标星期。月长及年长使用公历闰年规则：能被 $400$ 整除，或能被 $4$ 整除但不能被 $100$ 整除。1900 年与 2000 年分别按平年、闰年处理。

**复杂度**

扫描 $Y$ 年的时间为 $O(12Y)$，额外空间 $O(1)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=13;
int a,b,c,l,r,first=2;
int mon[N]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int y){
    return y%400==0 || (y%4==0 && y%100!=0);
}
int main(){
    scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
    for(int y=1850;y<=r;++y){
        if(y>=l){
            int w=first;
            for(int m=1;m<a;++m){
                w=(w+mon[m]+(m==2 && leap(y)))%7;
            }
            int d=1+(c%7-w+7)%7+7*(b-1);
            if(d>mon[a]+(a==2 && leap(y)))puts("none");
            else printf("%d/%02d/%02d\n",y,a,d);
        }
        first=(first+365+leap(y))%7;
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 网络延时

标签：`树的直径` · `BFS`

本地：82 组优化版、82 组 UBSan 验证通过，详见 [验证记录](../tests/201503/VALIDATION.md)。

### 题意

网络由 $n$ 台交换机和 $m$ 台终端电脑组成，连接关系是一棵树。求任意两台设备之间最多需要经过多少条连接。

输入 $n,m$，再输入交换机 $2$ 到 $n$ 各自连接的父交换机编号，随后输入每台电脑连接的交换机编号。$n,m\le10^4$，每台交换机的父编号比自身小。

输出网络中两点间的最大距离。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503D)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503D/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addb91774ace1cba9a20e42)（accepted，100 分；复刻评测）。

### 题解

将电脑也作为普通树节点，统一编号后建双向边，问题转化为求树的直径。

先从任意节点 BFS，找到最远点 $u$；再从 $u$ BFS，第二次遍历中的最大距离就是直径长度。

**正确性**

树上任意两点间的路径唯一。从任意节点出发，最远点可作为某条直径的端点；这是树的两次遍历求直径性质。因此第二次从该端点取最远距离，即得到最长路径。此性质不能直接用于一般无向图。

**复杂度**

两次 BFS 的时间均为 $O(n+m)$，空间同阶。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=20010;
int n,m,head[N],to[N<<1],nxt[N<<1],cnt,d[N],q[N];
void add(int u,int v){
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int bfs(int s){
    memset(d,-1,sizeof d);
    int l=0,r=0,u=s;
    q[r++]=s;d[s]=0;
    while(l<r){
        int x=q[l++];
        if(d[x]>d[u])u=x;
        for(int i=head[x];i;i=nxt[i]){
            int v=to[i];
            if(d[v]>=0)continue;
            d[v]=d[x]+1;
            q[r++]=v;
        }
    }
    return u;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int u=1,p;u<n+m;++u){
        scanf("%d",&p);
        --p;
        add(u,p);add(p,u);
    }
    int u=bfs(0),v=bfs(u);
    printf("%d\n",d[v]);
    return 0;
}
```

<a id="problem-e"></a>

## E. 最小花费

标签：`点分治` · `倍增` · `贪心` · `树上查询`

本地：262 组优化版、262 组 UBSan 验证通过，详见 [验证记录](../tests/201503/VALIDATION.md)。

### 题意

树上的城市有不同食物价格，每走一单位路程消耗一单位食物。可以在经过的城市提前购买任意数量，但只能沿起终点间的唯一简单路径旅行。对每个有向起终点对，求最低花费；反向旅行的费用可能不同。

输入 `n m`、$n$ 个价格、$n-1$ 条带长度的无向边，以及 $m$ 个查询 `s t`。$1\le n,m\le10^5$，价格在 $[1,10^6]$，边长在 $[1,10^4]$。

每个查询输出一行最低费用。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201503E)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201503E/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addb9a174ace1cba9a20ea0)（accepted，100 分；复刻评测）。

### 题解

**单条路径的贪心**

每段路消耗的食物，都应在此前经过的最低价城市购买。遇到更低价格之前，可以提前囤粮；更高价城市无需购买。因此答案就是各段边长乘此前最低价的总和。

**点分治拆开查询**

对当前重心 $c$，把所在分量临时以 $c$ 为根。记录重心距离 $D_u$、根路径最低价 $\operatorname{low}_u$，以及从 $c$ 出发的费用 $\operatorname{dc}_u$。若 $v$ 是 $u$ 的孩子，有

$$\operatorname{dc}_v=\operatorname{dc}_u+w(u,v)\operatorname{low}_u.$$

再计算从各点走向重心的费用 $\operatorname{uc}_u$。设 $v$ 为最近的、价格严格低于 $a_u$ 的祖先，则

$$\operatorname{uc}_u=a_u(D_u-D_v)+\operatorname{uc}_v.$$

用倍增祖先和祖先段最低价跳过所有不更便宜的城市；若没有更低价祖先，就以当前价走到重心。按父亲先于孩子的顺序计算，右侧所需状态已经确定。

**回答经过重心的查询**

对于 $(s,t)$，前半段费用为 $\operatorname{uc}_s$，到重心后能继续使用的最低购买价为 $p=\operatorname{low}_s$。

若重心到 $t$ 的路径上没有更低价，后半段费用为 $pD_t$。否则用倍增找到从重心出发第一个使根路径最低价小于 $p$ 的点 $v$，费用为

$$pD_v+\operatorname{dc}_t-\operatorname{dc}_v.$$

到达 $v$ 的最后一条边仍使用旧价格，因此公式使用 $D_v$，不能提前在父亲处切换。起终点位于同一分支的查询移交该分支，其余查询在本层回答。

**正确性**

贪心独立最小化每段路的购买价。分治把真实路径拆成走向重心和离开重心两段，并将前半段取得的最低价格带入后半段，因此拼接没有损失。每个查询在第一次跨分支的层次恰好被回答一次。

**复杂度**

时间 $O((n+m)\log^2n)$，空间 $O(n\log n+m)$。树遍历及分治任务使用迭代方式，避免长链递归深度；距离和费用用 64 位整数。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1e5+10,K=18;
int n,m,a[N],fa[N],sz[N],bel[N],low[N],ord[N],root[N];
int up[N][K],mn[N][K],head[N],to[N<<1],nxt[N<<1],w[N<<1],cnt;
ll ans[N],dis[N],uc[N],dc[N];
bool del[N];
P qs[N];
struct task{
    int rt;
    vector<int> ids;
};
vector<task> tasks;
void add(int u,int v,int c){
    to[++cnt]=v;
    w[cnt]=c;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int main(){
    scanf("%d%d",&n,&m);
    a[0]=2e9;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1,u,v,c;i<n;++i){
        scanf("%d%d%d",&u,&v,&c);
        add(u,v,c);add(v,u,c);
    }
    for(int i=0;i<m;++i){
        scanf("%d%d",&qs[i].first,&qs[i].second);
    }
    fill(mn[0],mn[0]+K,a[0]);
    tasks.resize(1);
    tasks[0].rt=1;
    tasks[0].ids.resize(m);
    iota(tasks[0].ids.begin(),tasks[0].ids.end(),0);
    while(!tasks.empty()){
        task cur=std::move(tasks.back());
        tasks.pop_back();
        if(cur.ids.empty())continue;
        int len=1;
        ord[0]=cur.rt;fa[cur.rt]=0;
        for(int i=0;i<len;++i){
            int u=ord[i];
            for(int j=head[u];j;j=nxt[j]){
                int v=to[j];
                if(del[v] || v==fa[u])continue;
                fa[v]=u;
                ord[len++]=v;
            }
        }
        int c=cur.rt;
        for(int i=len-1;i>=0;--i){
            int u=ord[i],mx=0;
            sz[u]=1;
            for(int j=head[u];j;j=nxt[j]){
                int v=to[j];
                if(del[v] || fa[v]!=u)continue;
                sz[u]+=sz[v];
                mx=max(mx,sz[v]);
            }
            if(max(mx,len-sz[u])<=len/2)c=u;
        }
        len=1;
        ord[0]=c;fa[c]=0;bel[c]=-1;
        dis[c]=uc[c]=dc[c]=0;low[c]=a[c];
        int tot=0;
        for(int j=head[c];j;j=nxt[j]){
            if(!del[to[j]])root[tot++]=to[j];
        }
        for(int i=0;i<len;++i){
            int u=ord[i],p=fa[u];
            up[u][0]=p;mn[u][0]=a[p];
            for(int j=1;j<K;++j){
                int v=up[u][j-1];
                up[u][j]=up[v][j-1];
                mn[u][j]=min(mn[u][j-1],mn[v][j-1]);
            }
            if(p){
                int v=u;
                for(int j=K-1;j>=0;--j){
                    if(up[v][j] && mn[v][j]>=a[u])v=up[v][j];
                }
                int q=fa[v];
                uc[u]=(ll)a[u]*(dis[u]-dis[q])+uc[q];
            }
            int num=0;
            for(int j=head[u];j;j=nxt[j]){
                int v=to[j];
                if(del[v] || v==p)continue;
                fa[v]=u;dis[v]=dis[u]+w[j];
                low[v]=min(low[u],a[v]);
                dc[v]=dc[u]+(ll)w[j]*low[u];
                bel[v]=u==c?num++:bel[u];
                ord[len++]=v;
            }
        }
        vector<vector<int>> pending(tot);
        for(int &id:cur.ids){
            auto [s,t]=qs[id];
            if(s!=c && t!=c && bel[s]==bel[t]){
                pending[bel[s]].push_back(id);
                continue;
            }
            ll res=uc[s];
            int p=low[s];
            if(low[t]>=p)res+=(ll)p*dis[t];
            else{
                int v=t;
                for(int j=K-1;j>=0;--j){
                    if(up[v][j] && low[up[v][j]]<p)v=up[v][j];
                }
                res+=(ll)p*dis[v]+dc[t]-dc[v];
            }
            ans[id]=res;
        }
        del[c]=1;
        for(int i=0;i<tot;++i){
            if(!pending[i].empty()){
                tasks.push_back({root[i],std::move(pending[i])});
            }
        }
    }
    for(int i=0;i<m;++i){
        printf("%lld\n",ans[i]);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201503/VALIDATION.md)
- [add-followup.json](../tests/201503/add-followup.json)
- [cases.json](../tests/201503/cases.json)
- [compile.json](../tests/201503/compile.json)
- [current-sources.json](../tests/201503/current-sources.json)
- [extra.py](../tests/201503/extra.py)
- [summary.json](../tests/201503/summary.json)

<!-- local-validation-attachments:end -->
