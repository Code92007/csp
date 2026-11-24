---
title: "CSP 201403 五题题解"
contest: "201403"
contest_month: "2014-03"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "集合", "相反数", "层次顺序", "模拟", "字符串解析", "状态机", "有序映射", "分层BFS", "最短路", "几何判定", "动态规划", "资源调度", "状态压缩"]
status: "published"
problems: [{"id": "A", "title": "相反数", "tags": ["集合", "相反数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U281236"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403A/"}], "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305650472"}, "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a533e5d1fced2e45b1a8", "source_sha256": "54d1cb07286ac63df531463a356f83997e19851dda626c9adca41c78e0186586", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:55:31.298165+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addcd3974ace1cba9a21f70", "source_sha256": "269740413c10bf630470510697040ed0b65d7b69454f456b2806f8942455b030"}}, {"id": "B", "title": "窗口", "tags": ["层次顺序", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a571e5d1fced2e45b25d", "source_sha256": "0681f45fd8d972c9a42b87d8f64bdbc4c18b88568301990c6ec3f41f938b9470", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:57:34.766573+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc14d74ace1cba9a2189b"}}, {"id": "C", "title": "命令行选项", "tags": ["字符串解析", "状态机", "有序映射"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U281238"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403C/"}], "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305653686"}, "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a5aee5d1fced2e45b390", "source_sha256": "0867e0bab71f1a6634739d9386dcfc735358afc700fb873120d0efafc4a2243a", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:57:36.400688+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addf69574ace1cba9a22df8", "source_sha256": "441729975e87fcc5b4706c6cb63d0c5a202463d9b7f382dfe7e30f7290ea793b"}}, {"id": "D", "title": "无线网络", "tags": ["分层BFS", "最短路", "几何判定"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U281240"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403D/"}], "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305643544"}, "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a5ece5d1fced2e45b433", "source_sha256": "eadefb37c29f5073a705550d0b81140ea299cf0caf31d3f2cf59157e413864d8", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:59:19.348552+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addf9b174ace1cba9a22fa2", "source_sha256": "aba51d8d53cc594a3a946db1144c35d9a239d50198a9b9186efb87c8c058b8ac"}}, {"id": "E", "title": "任务调度", "tags": ["动态规划", "资源调度", "状态压缩"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201403E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201403E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a62ae5d1fced2e45b4a9", "source_sha256": "9dd76afe748889fd99ded737f5c968ff3a9d6a7777a0e7fc7b5f9b9ddd00e3d6", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:59:21.234315+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc1d874ace1cba9a218be"}}]
---

# CSP 201403 五题题解

[原页面](https://code92007.github.io/csp/#/contest/201403) · [验证记录](../tests/201403/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 相反数

标签：`集合` · `相反数`

本地：63 组优化版、63 组 UBSan 验证通过，详见 [验证记录](../tests/201403/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a533e5d1fced2e45b1a8)。

<!-- refactor-online:A:end -->

### 题意

给定若干非零且互不相同的整数，统计其中互为相反数的无序数对个数。

输入整数个数 $1\le n\le500$，再输入这 $n$ 个数。每个数都非零，绝对值不超过 $1000$，且任意两个数不同。

输出相反数对的数量。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/U281236)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403A)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403A/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addcd3974ace1cba9a21f70)（accepted，100 分；复刻评测）。

原版洛谷民间评测：[记录](https://www.luogu.com.cn/record/305650472)（accepted，100 分）。

### 题解

将所有数放入集合，只枚举正数 $x$，检查集合中是否存在 $-x$，存在就计数。

每对非零相反数恰好有一个正数，因此每个合法数对恰好统计一次。题目保证非零且互异，不能把此计数直接用作含重复值时的组合数答案。

**复杂度**

时间 $O(n\log n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,ans;
set<int> a;
int main(){
    scanf("%d",&n);
    for(int i=0,x;i<n;++i){
        scanf("%d",&x);
        a.insert(x);
    }
    for(const int &x:a){
        if(x>0 && a.count(-x))++ans;
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 窗口

标签：`层次顺序` · `模拟`

本地：102 组优化版、102 组 UBSan 验证通过，详见 [验证记录](../tests/201403/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a571e5d1fced2e45b25d)。

<!-- refactor-online:B:end -->

### 题意

窗口按从底到顶的顺序给出。每次点击选中包含该点的最顶层窗口，并将它移到顶层，其他窗口的相对顺序不变。窗口边界也算内部，没有命中时忽略此次点击。

输入窗口数 $n$ 和点击数 $m$，接着输入每个矩形的左下、右上坐标，再输入各次点击坐标。$1\le n,m\le10$，横、纵坐标分别在 $[0,2559]$、$[0,1439]$ 内，窗口按输入顺序从 $1$ 编号。

每次点击输出选中的原始窗口编号；未命中则输出 `IGNORED`。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403B)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403B/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addc14d74ace1cba9a2189b)（accepted，100 分；复刻评测）。

### 题解

用数组按从底到顶保存窗口，窗口始终携带原始编号。每次从后向前查找第一个包含点击点的矩形：找到后输出编号，将其后的窗口依次前移，再把选中窗口放到末尾；没找到则不改变数组。

**正确性**

逆序查找保证选择最顶层的命中窗口。删除该项并放到末尾，既实现置顶，也保持其他窗口的相对顺序，因此数组顺序始终与实际层次一致。

**复杂度**

每次查询与移动均为 $O(n)$，总时间 $O(nm)$，空间 $O(n)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=15;
struct node{
    int l,b,r,t,id;
}a[N];
int n,m,x,y;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        node &v=a[i];
        scanf("%d%d%d%d",&v.l,&v.b,&v.r,&v.t);
        v.id=i+1;
    }
    while(m--){
        scanf("%d%d",&x,&y);
        int p=-1;
        for(int i=n-1;i>=0;--i){
            node &v=a[i];
            if(v.l<=x && x<=v.r && v.b<=y && y<=v.t){
                p=i;
                break;
            }
        }
        if(p<0)puts("IGNORED");
        else{
            node v=a[p];
            printf("%d\n",v.id);
            for(int i=p;i<n-1;++i){
                a[i]=a[i+1];
            }
            a[n-1]=v;
        }
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 命令行选项

标签：`字符串解析` · `状态机` · `有序映射`

本地：103 组优化版、103 组 UBSan 验证通过，详见 [验证记录](../tests/201403/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a5aee5d1fced2e45b390)。

<!-- refactor-online:C:end -->

### 题意

根据格式字符串解析命令行选项。字母后紧跟冒号，表示该选项必须消费下一个词作为参数，否则为无参选项。遇到非法选项或缺少必需参数时，停止解析，忽略剩余词。

输入格式字符串、命令行数量 $n$，再输入各行命令。格式串长度不超过 $52$，$1\le n\le20$，单行长度不超过 $256$。命令的第一个词为工具名；后续词由小写字母、数字、减号组成，以单个空格分隔。

第 $i$ 行以 `Case i:` 开头，按字母递增输出已识别选项及参数。重复无参选项只输出一次，带参选项保留最后一次完整出现的参数。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/U281238)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403C)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403C/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addf69574ace1cba9a22df8)（accepted，100 分；复刻评测）。

原版洛谷民间评测：[记录](https://www.luogu.com.cn/record/305653686)（accepted，100 分）。

### 题解

预处理每个字母的类型：不支持、无参数、有参数。逐行分词并跳过工具名；之后每次读取一个词，要求它恰好是减号加一个受支持的小写字母。

带参选项无条件消费紧随的下一个词，即使它以减号开头。若没有下一个词，就停止，且不覆盖之前已经记录的有效参数。通过全部检查后，再标记该选项并更新参数。

**正确性**

数组中始终保存已解析合法前缀的最终结果。非法词之后不再扫描，重复选项仅覆盖同一位置，缺少参数的末次出现不会覆盖旧值。按字母顺序扫描数组，输出顺序自然满足要求。

**复杂度**

设单行长度为 $L$，每行时间 $O(L+26)$，空间 $O(L+26)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=60,K=26;
int n,kind[K];
bool ok[K];
char fmt[M],s[N];
string val[K];
int main(){
    scanf("%s%d",fmt,&n);
    for(int i=0;fmt[i];++i){
        if(fmt[i]==':')continue;
        kind[fmt[i]-'a']=fmt[i+1]==':'?2:1;
    }
    fgets(s,N,stdin);
    for(int t=1;t<=n;++t){
        fgets(s,N,stdin);
        memset(ok,0,sizeof ok);
        istringstream in(s);
        string w;
        in>>w;
        while(in>>w){
            if(w.size()!=2 || w[0]!='-')break;
            if(w[1]<'a' || w[1]>'z')break;
            int c=w[1]-'a';
            if(!kind[c])break;
            string v;
            if(kind[c]==2 && !(in>>v))break;
            ok[c]=1;val[c]=v;
        }
        printf("Case %d:",t);
        for(int c=0;c<K;++c){
            if(!ok[c])continue;
            printf(" -%c",'a'+c);
            if(kind[c]==2)printf(" %s",val[c].c_str());
        }
        puts("");
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 无线网络

标签：`分层BFS` · `最短路` · `几何判定`

本地：113 组优化版、113 组 UBSan 验证通过，详见 [验证记录](../tests/201403/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a5ece5d1fced2e45b433)。

<!-- refactor-online:D:end -->

### 题意

已有 $n$ 个无线路由器，另有 $m$ 个候选安装位置，最多新增 $k$ 个。两点距离不超过 $r$ 即可通信，求路由器 $1$ 到 $2$ 最少经过多少个中转路由器。

输入 `n m k r`，先给出已有路由器坐标，再给出候选位置。$2\le n\le100$，$1\le k\le m\le100$，$1\le r\le10^8$，坐标绝对值不超过 $10^8$。位置互异，且原网络中 $1$ 到 $2$ 已经连通。

输出最少中转路由器数。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/U281240)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403D)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403D/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addf9b174ace1cba9a22fa2)（accepted，100 分；复刻评测）。

原版洛谷民间评测：[记录](https://www.luogu.com.cn/record/305643544)（accepted，100 分）。

### 题解

两两检查全部已有与候选位置，使用距离平方与 $r^2$ 比较建图，避免浮点误差；坐标差和平方使用 64 位整数。

只记录到达某点的最短路还不够，因为该路径可能消耗了更多新增名额。BFS 状态设为“位置 $u$、已使用新增数 $c$”：走到已有路由器不增加 $c$，走到候选点则加一，超过 $k$ 的状态不入队。

**正确性**

最优路线可以取简单路径。若某点重复出现，删去中间环路只会减少长度及新增需求，因此按路径经过候选点的次数计数即可，无需记录已经安装的完整集合。

所有合法简单路径都能在分层图中表达，各边步数均为一，故 BFS 首次取出路由器 $2$ 时得到最少边数。中转点数比边数少一。

**复杂度**

设 $V=n+m$，建图时间 $O(V^2)$，BFS 时间 $O(kV^2)$，空间 $O(V^2+kV)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=210,M=110;
int n,m,k,tot,d[N][M],head,tail;
ll r,x[N],y[N];
bool g[N][N];
P q[N*M];
int main(){
    scanf("%d%d%d%lld",&n,&m,&k,&r);
    tot=n+m;
    for(int i=0;i<tot;++i){
        scanf("%lld%lld",&x[i],&y[i]);
        for(int j=0;j<i;++j){
            ll dx=x[i]-x[j],dy=y[i]-y[j];
            if(dx*dx+dy*dy<=r*r)g[i][j]=g[j][i]=1;
        }
    }
    memset(d,-1,sizeof d);
    d[0][0]=0;q[tail++]=P(0,0);
    while(head<tail){
        auto [u,c]=q[head++];
        if(u==1){
            printf("%d\n",d[u][c]-1);
            return 0;
        }
        for(int v=0;v<tot;++v){
            if(!g[u][v])continue;
            int t=c+(v>=n);
            if(t>k || d[v][t]>=0)continue;
            d[v][t]=d[u][c]+1;
            q[tail++]=P(v,t);
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 任务调度

标签：`动态规划` · `资源调度` · `状态压缩`

本地：158 组优化版、158 组 UBSan 验证通过，详见 [验证记录](../tests/201403/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a62ae5d1fced2e45b4a9)。

<!-- refactor-online:E:end -->

### 题意

有两个 CPU 和一个 GPU，任务之间没有依赖。每个任务可选择单 CPU、双 CPU、单 CPU 加 GPU、双 CPU 加 GPU，期间独占所用设备且不能中断。求全部任务完成所需的最短时间。

输入任务数 $1\le n\le40$，再输入每个任务四种模式的耗时 $a_i,b_i,c_i,d_i$，均为 $1$ 到 $10$ 的整数。

输出最短总完成时间。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201403E)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201403E/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addc1d874ace1cba9a218be)（accepted，100 分；复刻评测）。

### 题解

**将调度转化为资源负载**

使用双 CPU 的任务无法与其他任务并行，可以统一挪到一个串行时段，耗时选择 $\min(b_i,d_i)$。其余任务分别分配到两个 CPU，其中部分还占用 GPU。

设两 CPU 的负载为 $x,y$，GPU 负载为 $z$，双 CPU 任务的串行时间为 $s$。完成时间至少为

$$s+\max(x,y,z).$$

该下界可以达到：记 $T=\max(x,y,z)$，将 CPU1 上占 GPU 的任务排在最前，将 CPU2 上占 GPU 的任务排在最后。两段 GPU 任务的总长度为 $z\le T$，因此不重叠；其他任务放在各 CPU 剩余位置中，能在 $T$ 内结束。最后再加入双 CPU 的串行时段。

**对三种负载做 DP**

定义 `dp[x][y][z]` 为处理若干任务、达到三个负载时的最小串行时间 $s$。每个任务有五种转移：单 CPU 分配给 CPU1 或 CPU2，CPU 加 GPU 分配给 CPU1 或 CPU2，以及双 CPU 串行执行。

交换两个 CPU 不改变答案，统一令 $x\le y$ 合并对称状态。DP 枚举全部模式分配，而上述构造说明每个负载状态都能实现，因此最小目标值就是最优调度时间。

**收紧状态范围**

先用普通子集背包求出仅使用单 CPU 时的最优最大负载，再与全部任务双 CPU 串行执行比较，得到可行上界 $U$。只保存 $s+\max(x,y,z)<U$ 的状态，答案初值保留 $U$。

各负载以后只增不减，被剪掉的状态不可能再改进上界。把最多四十个任务分为各不超过二十个的两组，每组总时长不超过 $200$，因此 $U\le200$。

若 $c_i\ge a_i$，CPU 加 GPU 被单 CPU 支配；若 $\min(b_i,d_i)\ge a_i$，双 CPU 方式也被单 CPU 支配，可跳过这些转移。

**实现与复杂度**

用两个扁平数组滚动，只枚举实际到达的状态，并在交换前清掉旧状态。串行耗时最多 $400$，以 16 位无符号数保存，使用对应的重复字节无穷大 $\mathtt{0x3f3f}$，仍保留初态 `dp[0]=0`。

最坏时间 $O(nU^3)$，空间 $O(U^3)$。负载下界可排程的构造是关键，不能只写资源总量下界而省略可行性证明。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned short us;
const int N=45,M=410,K=200,V=K*K*K;
const us INF=0x3f3f;
struct job{
    int a,b,c,d;
}a[N];
int n,sum,tot,lim,bs,vol,cnt;
bool ok[M];
us f[V],g[V],*dp=f,*ndp=g;
int x[V],y[V],*cur=x,*nxt=y;
void put(int x,int y,int z,int cost){
    if(cost+max({x,y,z})>=lim)return;
    if(x>y)swap(x,y);
    int id=(x*bs+y)*bs+z;
    if(ndp[id]==INF)nxt[cnt++]=id;
    ndp[id]=min<int>(ndp[id],cost);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        job &v=a[i];
        scanf("%d%d%d%d",&v.a,&v.b,&v.c,&v.d);
        sum+=v.a;tot+=min(v.b,v.d);
    }
    ok[0]=1;
    for(int i=0;i<n;++i){
        for(int s=sum;s>=a[i].a;--s){
            ok[s]=(ok[s] || ok[s-a[i].a]);
        }
    }
    lim=tot;
    for(int s=0;s<=sum;++s){
        if(ok[s])lim=min(lim,max(s,sum-s));
    }
    bs=lim;vol=bs*bs*bs;
    memset(dp,INF,vol*sizeof *dp);
    memset(ndp,INF,vol*sizeof *ndp);
    dp[0]=0;cur[0]=0;
    int len=1;
    for(int i=0;i<n;++i){
        job &v=a[i];
        int both=min(v.b,v.d);
        cnt=0;
        for(int j=0;j<len;++j){
            int id=cur[j],z=id%bs;
            int y=id/bs%bs,x=id/bs/bs,cost=dp[id];
            put(x+v.a,y,z,cost);put(x,y+v.a,z,cost);
            if(v.c<v.a){
                put(x+v.c,y,z+v.c,cost);
                put(x,y+v.c,z+v.c,cost);
            }
            if(both<v.a)put(x,y,z,cost+both);
        }
        for(int j=0;j<len;++j){
            dp[cur[j]]=INF;
        }
        swap(dp,ndp);swap(cur,nxt);
        len=cnt;
    }
    int ans=lim;
    for(int j=0;j<len;++j){
        int id=cur[j],z=id%bs;
        int y=id/bs%bs,x=id/bs/bs;
        ans=min(ans,dp[id]+max({x,y,z}));
    }
    printf("%d\n",ans);
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201403/VALIDATION.md)
- [cases.json](../tests/201403/cases.json)
- [compile.json](../tests/201403/compile.json)
- [current-sources.json](../tests/201403/current-sources.json)
- [extra.py](../tests/201403/extra.py)
- [names-followup.json](../tests/201403/names-followup.json)
- [online-update-report.json](../tests/201403/online-update-report.json)
- [online-verdicts.json](../tests/201403/online-verdicts.json)
- [summary.json](../tests/201403/summary.json)

<!-- local-validation-attachments:end -->
