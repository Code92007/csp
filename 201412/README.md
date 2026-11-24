---
title: "CSP 201412 五题题解"
contest: "201412"
contest_month: "2014-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "在线计数", "矩阵遍历", "对角线", "前缀和", "排序", "整数精度", "模拟", "最小生成树", "Kruskal", "并查集", "费用流", "时间展开图", "周期调度"]
status: "published"
problems: [{"id": "A", "title": "门禁系统", "tags": ["在线计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201412A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a2b3e5d1fced2e45ab01", "source_sha256": "6c7e91b84554d18fc0c9ff20faeebe5621cdde0cfb39e72114d1624efd30f80e", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:44:55.262105+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addba3174ace1cba9a20ee1"}}, {"id": "B", "title": "Z 字形扫描", "tags": ["矩阵遍历", "对角线"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201412B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a2f0e5d1fced2e45aba2", "source_sha256": "f1ac108f70335eac6e2634659bcb92e877f0a5672614b4c9bf521d3b808858df", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:46:41.941464+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addbabd74ace1cba9a20f29"}}, {"id": "C", "title": "集合竞价", "tags": ["前缀和", "排序", "整数精度", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：90 分 Wrong Answer（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201412C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412C/"}], "oj": {"score": 90.0, "verdict": "Wrong Answer", "record": "https://oj.shumeng.tech/record/6b05a32ee5d1fced2e45ac6f", "source_sha256": "da9a660760de1b35e3ac5bd1bbdb3564bea4419d3d694e26f8d18b4fede45504", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "failed", "observed_at": "2026-11-24T14:46:43.474320+00:00"}, "oj_before_refactor": {"status": "failed", "score": 90, "verdict": "Wrong Answer", "record": "https://oj.shumeng.tech/record/6addbb4574ace1cba9a20fa8"}}, {"id": "D", "title": "最优灌溉", "tags": ["最小生成树", "Kruskal", "并查集"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201412D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a37ee5d1fced2e45adb3", "source_sha256": "25fd3e17b3e6c1964c0eff41c751c6656f70a3b7e062ce3eef3024e2fcb0b825", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:48:58.004783+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addbbd074ace1cba9a21026"}}, {"id": "E", "title": "货物调度", "tags": ["费用流", "时间展开图", "周期调度"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201412E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201412E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a3bce5d1fced2e45ae6f", "source_sha256": "2e79fb9fc9a3ad92ec794ce610a4396df0bcf0670ba5c48cbc5a7b47db55bf6f", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:48:58.749146+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addbcce74ace1cba9a21124"}}]
---

# CSP 201412 五题题解

[返回总目录](../README.md) · [本地验证](../tests/201412/VALIDATION.md)

<a id="problem-a"></a>

## A. 门禁系统

标签：`在线计数`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addba3174ace1cba9a20ee1)。重构版本地验证见 [VALIDATION.md](../tests/201412/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a2b3e5d1fced2e45ab01)。

<!-- refactor-online:A:end -->

### 题意

按时间给出读者来访编号，求每条记录中的读者截至这次来访已出现多少次。

输入记录数 `n` 和依次到访的 `n` 个编号，$1\le n\le1000$，编号在 $1\ldots n$ 内。

按输入顺序输出每条记录对应的出现次数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201412A) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412A/)。

### 题解

为每个编号维护已出现次数。读入 `x` 后先递增 `cnt[x]` 再输出，其他编号计数不变。

处理前 i 条后，计数数组恰好记录该前缀中每人的出现次数，因此输出就是所需序号。不要先统计全文频次再统一输出。时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1000+10;
int n,x,cnt[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        printf("%d%c",++cnt[x],i==n-1?'\n':' ');
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. Z 字形扫描

标签：`矩阵遍历` · `对角线`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addbabd74ace1cba9a20f29)。重构版本地验证见 [VALIDATION.md](../tests/201412/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a2f0e5d1fced2e45aba2)。

<!-- refactor-online:B:end -->

### 题意

对一个方阵从左上角开始按 Z 字形扫描，相邻反对角线的方向交替。

输入方阵边长 `n` 及 $n\times n$ 个元素，$1\le n\le500$。

按扫描顺序输出全部元素。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201412B) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412B/)。

### 题解

同一条反对角线满足 `i+j=s`，依次枚举 `s=0…2n-2`。合法行号范围为 `max(0,s-n+1)` 到 `min(n-1,s)`；`s` 为奇数时行号从小到大，偶数时从大到小，列号由 `j=s-i` 确定。

每个格子唯一属于一条反对角线，枚举范围恰好包含所有合法格子，交替方向符合 Z 字形。时间 $O(n^2)$，存矩阵空间 $O(n^2)$，无需复杂地模拟碰边转向。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,a[N][N],cnt;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int s=0;s<=2*n-2;++s){
        int l=max(0,s-n+1),r=min(n-1,s);
        for(int k=l;k<=r;++k){
            int i=s&1?k:l+r-k,j=s-i;
            printf("%d%c",a[i][j],++cnt==n*n?'\n':' ');
        }
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 集合竞价

标签：`前缀和` · `排序` · `整数精度` · `模拟`

原版评测：[曙梦 OJ 90 分 Wrong Answer](https://oj.shumeng.tech/record/6addbb4574ace1cba9a20fa8)。重构版本地验证见 [VALIDATION.md](../tests/201412/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：90 分 Wrong Answer（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a32ee5d1fced2e45ac6f)。

<!-- refactor-online:C:end -->

### 题意

记录买卖委托和撤单。对一个候选成交价，有效买量是报价不低于该价的买单总量，有效卖量是报价不高于该价的卖单总量，成交量为两者较小值。选择成交量最大的价格，同分时选择最高价。

输入若干条记录，直到文件结束。记录不超过 5000 条，单笔股数可达 $10^8$，价格保留两位小数。记录格式如下，撤单编号按全部输入行计数：

- `buy p s`：以价格 `p` 委托买入 `s` 股。
- `sell p s`：以价格 `p` 委托卖出 `s` 股。
- `cancel i`：撤销第 `i` 行的委托。

输出成交价格和最大成交量，价格保留两位小数。此题原版在线评测仍为 90 分，未解决的边界问题见下文说明。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201412C) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412C/)。

### 题解

先读完全部记录并标记撤销，行号包括 `cancel` 行，不能只给买卖单编号。价格固定两位小数，用 `scanf` 分别读取整数、小数部分并换算成整数“分”，避免浮点比较误差；按价格聚合买量和卖量。

价格从低到高扫描。初始 `buy` 是全部买量，`sell=0`；到价格 `p` 时先把该价卖量加入 `sell`，此时两者分别准确等于报价不低于 `p` 的买量、报价不高于 `p` 的卖量。计算较小值，若不小于当前最优便更新，以保留较高价格；最后再扣掉该价买量。

买卖量只在委托价处变化，常规集合竞价枚举这些候选价即可；存在正成交量时，最高最优价格必落在某个有效买单报价处。前后缀不变量保证每个候选价的成交量正确。时间 $O(n\log n)$，空间 $O(n)$，总股数用 64 位。

**保留的未满分状态**

原版曙梦 OJ 第 2、20 点失败，成绩为 **90 分 Wrong Answer**。历史审计的 2000 组独立对拍和 5 组上界检查尚未定位原因；2026-10-25 的单位股票子集 oracle 又检查了 192759 个正成交量样例，仍无差异。

零成交量案例仅核对当前候选价格约定，不能据此排除题面边界差异。本次只重构代码风格，保留原候选价格与零成交约定；本地通过不能视为已修复在线 WA 或取得满分。

历史审计：[本地审计结果](../tests/auction-report.json) · [独立验证器](../tests/auction_regressions.py) · [后续审计统计](../tests/auction-review-v2-report.json)。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int M=10;
struct order{
    int op,p;
    ll num;
    bool ok;
};
vector<order> a(1);
map<int,P> g;
char s[M];
ll buy,sell,ans=-1;
int price;
int main(){
    while(scanf("%s",s)==1){
        order e{0,0,0,true};
        if(s[0]=='c'){
            int x;
            scanf("%d",&x);
            a[x].ok=false;
            e.ok=false;
        }
        else{
            int x,y;
            scanf("%d.%d%lld",&x,&y,&e.num);
            e.op=s[0]=='b';
            e.p=x*100+y;
        }
        a.push_back(e);
    }
    for(auto &e:a){
        if(!e.ok || !e.num)continue;
        P &v=g[e.p];
        if(e.op){
            v.first+=e.num;
            buy+=e.num;
        }
        else v.second+=e.num;
    }
    for(auto &[p,v]:g){
        sell+=v.second;
        ll num=min(buy,sell);
        if(num>=ans){
            ans=num;
            price=p;
        }
        buy-=v.first;
    }
    ans=max(0ll,ans);
    printf("%d.%02d %lld\n",price/100,price%100,ans);
    return 0;
}
```

<a id="problem-d"></a>

## D. 最优灌溉

标签：`最小生成树` · `Kruskal` · `并查集`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addbbd074ace1cba9a21026)。重构版本地验证见 [VALIDATION.md](../tests/201412/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a37ee5d1fced2e45adb3)。

<!-- refactor-online:D:end -->

### 题意

有 `n` 块麦田，第 1 块有水井，可以在指定田地之间修建水渠。选择水渠，使所有田地都能从水井获得水，并使总费用最小。

输入 `n m`，随后给出 `m` 条可建水渠的两个端点和正费用，形成连通的无向带权图。$n\le1000,m\le10^5$。

输出连接全部麦田所需的最小总费用。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201412D) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412D/)。

### 题解

所有田地都能从水井获得水，当且仅当选择的边使整张图连通。由于费用为正，环上可以删去一条边而保持连通，所以最优方案可以是一棵生成树。

使用 Kruskal：边按费用升序，只有两端还在不同并查集时才选取并合并。 对于一次连接两个分量的最便宜边，任意最优生成树若没选它，加入后形成的环上必有另一条跨这两个分量的边；用当前边替换不会更贵。 这一交换论证保证每一步均可包含在某棵最优树中。

累加所有选中边费用即可。排序为 $O(m\log m)$，并查集操作近线性，空间 $O(n+m)$。这是“最小生成树总权重”，与只问 1 到 n 的瓶颈路径题不同。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000+10,M=1e5+10;
struct edge{
    int u,v,w;
    bool operator<(const edge &e)const{
        return w<e.w;
    }
}e[M];
int n,m,fa[N],sz[N];
ll ans;
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        fa[i]=i,sz[i]=1;
    }
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e,e+m);
    for(int i=0;i<m;++i){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v)continue;
        if(sz[u]<sz[v])swap(u,v);
        fa[v]=u;
        sz[u]+=sz[v];
        ans+=e[i].w;
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-e"></a>

## E. 货物调度

标签：`费用流` · `时间展开图` · `周期调度`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addbcce74ace1cba9a21124)。重构版本地验证见 [VALIDATION.md](../tests/201412/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a3bce5d1fced2e45ae6f)。

<!-- refactor-online:E:end -->

### 题意

每座城市在一周七天分别生产和消耗一定量货物。道路可在当天运输货物，每城仓库有容量限制和单位每夜保管费。要求每周按同一流程循环，求最低每周费用。

输入 `n m`，每城一行给出七日产量、七日需求、仓库容量和单位保管费，随后给出 `m` 条无向道路的端点和单位运费。$n\le100,m\le500$，产量、需求量和仓库容量不超过 100，单位运输费和保管费为 $1\sim100$。道路无重边、自环且不限运输量，每周总产量等于总需求，题面保证调度可行；星期日的库存可以结转到下一周星期一。

输出满足所有需求的最低每周费用。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201412E) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201412E/)。

### 题解

**把“城市”和“星期几”一起作为节点**

建 $7n$ 个节点 $(i,d)$。源点连到每个节点，容量为该日生产量、费用 0；各节点连汇点，容量为该日需求量、费用 0。

道路 $(u,v)$ 在每一天各建两个方向的边，容量足够大、费用为单位运费。 仓储则建 $(i,d)\to(i,(d+1)\bmod7)$，容量为仓库容量，费用为每夜保管费。尤其不能漏掉星期日到下星期一这条边：题目求稳定的周期调度，第一天可以使用上一周结转的库存。

求从源到汇、流量等于总需求的最小费用流。每一单位流表示一吨货物，它穿过道路边时支付运输费用，穿过跨日边时占用一晚仓库并支付存储费。 周末环边准确表达周期条件，而不是凭空增加免费货物：所有流仍受生产与需求平衡约束。

代码用 `struct MCMF` 封装链式前向星。每次在正残量边上用 SPFA 求最短费用路，沿前驱取路径瓶颈并一次增广，直到满足总需求。反向边费用取负，用于撤回不再最优的分配；正反弧成对保存，通过 `i^1` 访问。

**正确性**

可行循环调度与满足源汇总量的流互相转换，边容量对应库存上限，边费用对应实际支出。 最小费用最大流因此给出最优调度。

**复杂度**

设实际增广次数为 $T$，一次 SPFA 的最坏时间为 $O(VE)$，总时间 $O(TVE)$，空间 $O(V+E)$。这里 $V=7n+2$，正反弧共 $E=2(21n+14m)$；每次按整条路径的瓶颈增广，不是逐吨增广。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=710,M=18210,K=7;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct MCMF{
    struct edge{
        int v,nxt,w;
        ll cost;
    }e[M];
    int head[N],pre[N],q[N],cnt;
    ll dis[N],ans;
    bool vis[N];
    void init(){
        cnt=0;
        memset(head,-1,sizeof head);
    }
    void add(int x,int y,int z,int w){
        e[cnt]={y,head[x],z,w};
        head[x]=cnt++;
    }
    void add2(int x,int y,int z,int w){
        add(x,y,z,w);
        add(y,x,0,-w);
    }
    bool spfa(int s,int t){
        memset(dis,(int)INF,sizeof dis);
        memset(vis,0,sizeof vis);
        int l=0,r=1;
        q[0]=s;
        dis[s]=0;
        vis[s]=1;
        while(l!=r){
            int u=q[l];
            l=(l+1)%N;
            vis[u]=0;
            for(int i=head[u];i!=-1;i=e[i].nxt){
                int v=e[i].v;
                if(!e[i].w || dis[v]<=dis[u]+e[i].cost)continue;
                dis[v]=dis[u]+e[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    q[r]=v;
                    r=(r+1)%N;
                }
            }
        }
        return dis[t]!=INF;
    }
    int augment(int s,int t,int num){
        for(int v=t;v!=s;v=e[pre[v]^1].v){
            num=min(num,e[pre[v]].w);
        }
        for(int v=t;v!=s;v=e[pre[v]^1].v){
            int i=pre[v];
            e[i].w-=num;
            e[i^1].w+=num;
            ans+=(ll)num*e[i].cost;
        }
        return num;
    }
    ll mcmf(int s,int t,int need){
        ans=0;
        while(need && spfa(s,t)){
            need-=augment(s,t,need);
        }
        return need?-1:ans;
    }
}f;
int n,m,s,t,sum,a[K],b[K];
int main(){
    scanf("%d%d",&n,&m);
    s=K*n,t=s+1;
    f.init();
    for(int i=0;i<n;++i){
        for(int &x:a){
            scanf("%d",&x);
        }
        for(int &x:b){
            scanf("%d",&x);
        }
        int c,w;
        scanf("%d%d",&c,&w);
        for(int j=0;j<K;++j){
            f.add2(s,K*i+j,a[j],0);
            f.add2(K*i+j,t,b[j],0);
            f.add2(K*i+j,K*i+(j+1)%K,c,w);
            sum+=b[j];
        }
    }
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        --u,--v;
        for(int j=0;j<K;++j){
            f.add2(K*u+j,K*v+j,1e9,w);
            f.add2(K*v+j,K*u+j,1e9,w);
        }
    }
    printf("%lld\n",f.mcmf(s,t,sum));
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201412/VALIDATION.md)
- [c-output-followup-report.json](../tests/201412/c-output-followup-report.json)
- [details.txt](../tests/201412/details.txt)
- [e-mcmf-cases.json](../tests/201412/e-mcmf-cases.json)
- [e-mcmf-report.json](../tests/201412/e-mcmf-report.json)
- [nightly-review-followup.json](../tests/201412/nightly-review-followup.json)
- [online-update-report.json](../tests/201412/online-update-report.json)
- [online-verdicts.json](../tests/201412/online-verdicts.json)
- [prose-final-review.json](../tests/201412/prose-final-review.json)
- [report.json](../tests/201412/report.json)
- [retained_oracles.py](../tests/201412/retained_oracles.py)
- [verify-c-output-followup.py](../tests/201412/verify-c-output-followup.py)
- [verify-e-mcmf.py](../tests/201412/verify-e-mcmf.py)
- [verify.py](../tests/201412/verify.py)

<!-- local-validation-attachments:end -->
