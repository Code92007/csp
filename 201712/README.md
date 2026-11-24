---
title: "CSP 201712 五题题解"
contest: "201712"
contest_month: "2017-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "排序", "相邻元素", "队列", "循环模拟", "日期计算", "字符串解析", "枚举", "最短路", "Floyd", "分层图", "Dijkstra", "树形DP", "李超线段树", "启发式合并", "斜率优化"]
status: "published"
problems: [{"id": "A", "title": "最小差值", "tags": ["排序", "相邻元素"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "公开题面存档", "url": "https://www.cnblogs.com/wydxry/p/10730131.html"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b058f03e5d1fced2e457dd4", "source_sha256": "6fc42e40bb1d9761bd65bb5da357b51978d7e76ca806bb63365c92b6121446a6", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:22:11.800697+00:00"}, "oj_before_refactor": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "B", "title": "游戏", "tags": ["队列", "循环模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201712B"}, {"label": "公开题面存档", "url": "https://blog.51cto.com/u_15346485/3677111"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b058f85e5d1fced2e457e64", "source_sha256": "b489c509ec3ae7efd90cb1b410ead15985a5359796ca5324c6710e735898b43d", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:23:25.904264+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda75c74ace1cba9a1fccc"}}, {"id": "C", "title": "Crontab", "tags": ["日期计算", "字符串解析", "枚举", "排序"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "公开题面存档", "url": "https://www.cnblogs.com/imane/p/15095778.html"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b058fcfe5d1fced2e457f62", "source_sha256": "5fc6ca3c588cafe593063d09f8f9eb76dfc14510241b400f94f441ffee588c66", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:24:53.885797+00:00"}, "oj_before_refactor": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "D", "title": "行车路线", "tags": ["最短路", "Floyd", "分层图", "Dijkstra"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "公开题面存档", "url": "https://www.dreamwings.cn/ccf201712-4/5213.html"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b059027e5d1fced2e458041", "source_sha256": "9ca9b5a00588b6aa332bb68faf6a9e6cc0ba4a7dac011a4026a0e0616b719a0d", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:26:15.943564+00:00"}, "oj_before_refactor": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}, {"id": "E", "title": "商路", "tags": ["树形DP", "李超线段树", "启发式合并", "斜率优化"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "题面转录与转移式核对", "url": "https://bigrandall.io/u/randall/blog/20-chun-xiao-xue-qi-cheng-xu-she-ji-shi-yan-bao-gao#2-ccf-201712-5-商路"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b059079e5d1fced2e4581c6", "source_sha256": "ba6f4bb1d05f855acbc23500ed70be702497d6203fe6da7f1e65f31838000a10", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:27:28.899712+00:00"}, "oj_before_refactor": {"status": "unavailable", "reason": "隐藏题，当前账号无权查看"}}]
---

# CSP 201712 五题题解

[返回总目录](../README.md) · [本地验证](../tests/201712/VALIDATION.md)

<a id="problem-a"></a>

## A. 最小差值

标签：`排序` · `相邻元素`

原版未提供在线 Accepted 记录。重构版本地验证见 [VALIDATION.md](../tests/201712/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058f03e5d1fced2e457dd4)。

<!-- refactor-online:A:end -->

### 题意

给定 $n$ 个正整数，求任意两个元素的差的绝对值的最小值，允许存在重复元素。

输入 $n$ 和各元素，$n\le1000$。

输出最小差值。

来源：[公开题面存档](https://www.cnblogs.com/wydxry/p/10730131.html)。

### 题解

先排序，再扫描相邻元素差取最小。若两数排序后不相邻，它们之间至少有一个数；整段差是相邻差之和，必不小于其中某个相邻差，所以最小差一定可在相邻位置找到。

重复数排序后相邻并产生 0，直接参与最小值即可，不能先去重。时间 $O(n\log n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n;
ll ans=INF;
vector<ll> a;
int main(){
    scanf("%d",&n);
    a.resize(n);
    for(ll &x:a){
        scanf("%lld",&x);
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;++i){
        ans=min(ans,a[i]-a[i-1]);
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 游戏

标签：`队列` · `循环模拟`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adda75c74ace1cba9a1fccc)。重构版本地验证见 [VALIDATION.md](../tests/201712/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058f85e5d1fced2e457e64)。

<!-- refactor-online:B:end -->

### 题意

$n$ 个小朋友围成一圈，从 1 号开始连续报数 $1,2,3,\ldots$。报出的数为 $k$ 的倍数，或个位数字为 $k$ 时，该小朋友退出，直到只剩一人。

输入 $n,k$，$n\le1000$、$1\le k\le9$。

输出最后剩下的小朋友编号。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201712B) · [公开题面存档](https://blog.51cto.com/u_15346485/3677111)。

### 题解

队列按当前报数顺序保存存活者。每次弹出队首，用全局报数检查淘汰规则；未淘汰则放回队尾，淘汰则不再入队。报数每次加一，不因淘汰或转一圈而重置。

队列始终恰好是从下一个报数者开始的存活顺序，因而模拟与环形游戏等价。至少每 k 次报数淘汰一人，总报数次数不超过 k(n-1)，时间 $O(nk)$，空间 $O(n)$；n=1 时直接输出 1。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=1;
queue<int> q;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        q.push(i);
    }
    while(q.size()>1){
        int x=q.front();
        q.pop();
        if(cnt%k && cnt%10!=k)q.push(x);
        ++cnt;
    }
    printf("%d\n",q.front());
    return 0;
}
```

<a id="problem-c"></a>

## C. Crontab

标签：`日期计算` · `字符串解析` · `枚举` · `排序`

原版未提供在线 Accepted 记录。重构版本地验证见 [VALIDATION.md](../tests/201712/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058fcfe5d1fced2e457f62)。

<!-- refactor-online:C:end -->

### 题意

给定若干 Crontab 任务规则，找出指定时间区间内的全部执行时刻。五个字段分别约束分钟、小时、月内日期、月份和星期，五项条件必须同时满足。

输入规则数 $n$、起止时刻 $s,t$，再输入每条规则的五个字段与命令。$n\le20$，日期范围为 1970—2099 年，保证输出不超过一万行。字段支持 `*`、逗号并集、闭区间以及不区分大小写的英文月份和星期缩写。

输出 $[s,t)$ 内的执行时刻与命令，按时间升序排列；同一时刻按规则的输入顺序输出。

来源：[公开题面存档](https://www.cnblogs.com/imane/p/15095778.html)。

### 题解

先把每个字段解析成允许值的布尔表：逗号分片、连字符展开区间，英文缩写先转小写再映射。重叠区间只置同一个布尔位，不能重复执行。

从已知的 1970-01-01 星期四开始按天推进，正确处理闰年。 每一天先判断日期区间，再对每条规则检查月份、月内日期、星期三个条件；全部通过后只枚举该规则允许的小时、分钟。 过滤 [s,t) 边界后，把当天事件按 `(时间,规则编号)` 排序输出。

每天只生成满足五项条件的事件，枚举又覆盖每种可能时间；排序保证同刻顺序。 设扫描天数 D、生成事件数 K，时间 $O(Dn+K\log K)$（首尾边界日额外至多 $2880n$ 次候选），空间为规则与单日事件。 无需调用系统时间 API，不受时区和夏令时影响。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=60,M=5,K=13;
typedef array<bool,N> F;
const int lo[M]={0,0,1,1,0},hi[M]={59,23,31,12,6};
const int days[K]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct rule{
    array<F,M> f;
    vector<int> min,hour;
    string cmd;
};
int n;
ll s,t;
vector<rule> a;
string read(){
    string s;
    int c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(c!=EOF && !isspace(c)){
        s+=char(c);
        c=getchar();
    }
    return s;
}
int value(string s,int kind){
    for(char &c:s){
        c=tolower(c);
    }
    if(isdigit(s[0]))return stoi(s);
    string names=kind==3?"janfebmaraprmayjunjulaugsepoctnovdec":
                         "sunmontuewedthufrisat";
    return names.find(s)/3+(kind==3);
}
F parse(string s,int kind){
    F a;
    a.fill(false);
    if(s=="*"){
        for(int i=lo[kind];i<=hi[kind];++i){
            a[i]=true;
        }
        return a;
    }
    int p=0,len=s.size();
    while(p<len){
        int end=s.find(',',p);
        if(end==-1)end=len;
        string t=s.substr(p,end-p);
        int pos=t.find('-');
        int l=value(t.substr(0,pos),kind);
        int r=pos==-1?l:value(t.substr(pos+1),kind);
        for(int i=l;i<=r;++i){
            a[i]=true;
        }
        p=end+1;
    }
    return a;
}
bool leap(int y){
    return y%400==0 || (y%4==0 && y%100!=0);
}
int main(){
    scanf("%d%lld%lld",&n,&s,&t);
    a.resize(n);
    for(auto &r:a){
        for(int j=0;j<M;++j){
            r.f[j]=parse(read(),j);
        }
        r.cmd=read();
        for(int i=0;i<60;++i){
            if(r.f[0][i])r.min.push_back(i);
        }
        for(int i=0;i<24;++i){
            if(r.f[1][i])r.hour.push_back(i);
        }
    }
    int week=4;
    for(int y=1970;y<=t/100000000;++y){
        for(int mo=1;mo<=12;++mo){
            int last=days[mo]+(mo==2 && leap(y));
            for(int d=1;d<=last;++d,week=(week+1)%7){
                ll date=(y*10000+mo*100+d)*10000ll;
                if(date+2359<s || date>=t)continue;
                vector<pair<ll,int>> q;
                for(int i=0;i<n;++i){
                    auto &r=a[i];
                    if(!r.f[2][d] || !r.f[3][mo] || !r.f[4][week]){
                        continue;
                    }
                    for(int &h:r.hour){
                        for(int &m:r.min){
                            ll time=date+h*100+m;
                            if(s<=time && time<t)q.push_back({time,i});
                        }
                    }
                }
                sort(q.begin(),q.end());
                for(auto &[time,i]:q){
                    printf("%lld %s\n",time,a[i].cmd.c_str());
                }
            }
        }
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 行车路线

标签：`最短路` · `Floyd` · `分层图` · `Dijkstra`

原版未提供在线 Accepted 记录。重构版本地验证见 [VALIDATION.md](../tests/201712/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059027e5d1fced2e458041)。

<!-- refactor-online:D:end -->

### 题意

道路分为大道和小道。每走一公里大道增加 1 点疲劳；连续走一整段小道，总长为 $s$ 时，这段疲劳为 $s^2$。经过大道后，下一段小道重新累计长度，求从城市 1 到城市 $n$ 的最小疲劳。

输入 $n,m$，再输入每条双向道路的 `类型 端点1 端点2 长度`。类型 0 为大道，类型 1 为小道，$n\le500$。

输出最小疲劳值，平方和总费用使用 64 位整数。

来源：[公开题面存档](https://www.dreamwings.cn/ccf201712-4/5213.html)。

### 题解

不能仅记录“到路口 u 的最小疲劳”和该最优路线的小道长度，因为稍贵但连续小道长度更短的到达方式，后续可能反而更优。

**先把一整段连续小道合成一条边**

只用小道运行 Floyd，得到任意两点间最短小道长度 s；若存在这段路，其费用为 $s^2$。固定这一段的端点时，平方函数在非负数上单调，所以只需保留最短长度。

建立两类状态：0 表示刚走过大道或还没出发，1 表示刚走完一整段小道。 从两种状态都可走一条大道，转入 0；只有状态 0 能走合成小道边，转入 1。 禁止 1 直接接另一条合成小道，否则会把本应 $(a+b)^2$ 的连续费用错误拆成 $a^2+b^2$。

在这张非负权分层图上运行 Dijkstra，终点两种状态取较小值。

任意真实路线按最大连续小道段分割，可转成不更贵的分层路径；每条合成边也有真实小道路线可展开，且两段之间必须经过大道。 因此两者最优值相等。Floyd 时间 $O(n^3)$，随后朴素 Dijkstra $O(n^2)$，空间 $O(n^2)$。 平方与总费用用 64 位整数。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m;
vector<vector<ll>> a,b;
int main(){
    scanf("%d%d",&n,&m);
    a.assign(n,vector<ll>(n,INF));
    b=a;
    for(int i=0;i<n;++i){
        a[i][i]=0;
    }
    for(int i=0;i<m;++i){
        int op,u,v;
        ll w;
        scanf("%d%d%d%lld",&op,&u,&v,&w);
        --u;
        --v;
        auto &g=op?a:b;
        g[u][v]=g[v][u]=min(g[u][v],w);
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            if(a[i][k]==INF)continue;
            for(int j=0;j<n;++j){
                if(a[k][j]<INF){
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
    }
    vector<ll> dis(n*2,INF);
    vector<bool> vis(n*2);
    dis[0]=0;
    for(int i=0;i<n*2;++i){
        int x=-1;
        for(int j=0;j<n*2;++j){
            if(!vis[j] && (x==-1 || dis[j]<dis[x]))x=j;
        }
        if(x==-1 || dis[x]==INF)break;
        vis[x]=true;
        int u=x/2,op=x%2;
        for(int v=0;v<n;++v){
            if(b[u][v]<INF){
                dis[v*2]=min(dis[v*2],dis[x]+b[u][v]);
            }
            if(!op && v!=u && a[u][v]<INF){
                ll w=a[u][v];
                dis[v*2+1]=min(dis[v*2+1],dis[x]+w*w);
            }
        }
    }
    printf("%lld\n",min(dis[n*2-2],dis[n*2-1]));
    return 0;
}
```

<a id="problem-e"></a>

## E. 商路

标签：`树形DP` · `李超线段树` · `启发式合并` · `斜率优化`

原版未提供在线 Accepted 记录。重构版本地验证见 [VALIDATION.md](../tests/201712/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059079e5d1fced2e4581c6)。

<!-- refactor-online:E:end -->

### 题意

每座城市除根外都有一个编号更小的父亲，连边长度为 $s_i$。商路从城市 $u$ 出发，每一步可以跳到任意真后代 $v$，该段收益为 $v_u-(f_u-\operatorname{dist}(u,v))^2$，再从 $v$ 继续；也可以立即停止，收益为 0。

输入测试组数，每组输入城市数 $n$，再按编号输入各城市的 `父亲 s v f`。规模为 $n\le10^5$，$0\le v_i\le10^{13}$、$0\le f_i\le10^9$，非根边长满足 $1\le s_i\le10^4$。根的父亲和连边长度均为 0，父亲编号严格小于孩子编号。

每组输出所有城市最优收益之和，对 $10^{18}$ 取模。本题题名为《商路》。

来源：[题面转录与转移式核对](https://bigrandall.io/u/randall/blog/20-chun-xiao-xue-qi-cheng-xu-she-ji-shi-yan-bao-gao#2-ccf-201712-5-商路)。

### 题解

令 $dp[u]$ 为从 $u$ 出发的最优收益，$D_u$ 为根到 $u$ 的距离。直接转移为

$$dp[u]=\max\left(0,\max_{v\text{是真后代}}\{dp[v]+v_u-(f_u-D_v+D_u)^2\}\right).$$

设查询横坐标 $x=D_u+f_u$，展开平方得

$$dp[u]=\max(0,v_u-x^2+\max_v\{2D_vx+dp[v]-D_v^2\}).$$

每个后代 $v$ 提供直线 $y=2D_vx+dp[v]-D_v^2$。问题变成合并所有孩子的直线集合，再在 $x=D_u+f_u$ 处查询最大值。查询完成后才插入 $u$ 的直线，避免把自身错误地当作真后代。

**李超树加启发式合并**

所有查询横坐标预先离散化；李超线段树在每个区间保存中点处更优的直线，剩下一条只可能在一侧胜出，递归插入那一侧。每个子树同时用数组链表保存直线编号；合并时把小集合中的线逐条插入大集合对应的李超树，再拼接两条链表。每条线所在集合的大小每次至少翻倍，所以最多被搬动 $O(\log n)$ 次。

父亲编号小于孩子，可以按编号从大到小处理，省去递归遍历。

城市信息、离散坐标、编号链表和李超树节点池均使用全局数组，每组重置根、链表、DP 和节点计数。一次插线至多新建一个节点；结合启发式合并的搬动次数，节点池按 $O(n\log n)$ 预留容量。平方和比较使用 128 位整数，最终累加再按 $10^{18}$ 取模。

**正确性**

DP 枚举了停止或选择下一个后代的全部方案，展开没有改变数值； 子树合并恰好维护所有真后代的直线，李超树查询保持其逐点最大值。

**复杂度**

$O(n\log^2 n)$ 时间，代码保留历次合并产生的李超节点，空间上界 $O(n\log n)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
const int N=1e5+10,M=N*18;
const ll mod=1e18;
const i128 INF=(i128)1<<120;
int t,n,k,fa[N],rt[N],head[N],tail[N],nxt[N],sz[N];
ll dep[N],val[N],f[N],xs[N];
i128 dp[N];
i128 calc(int i,ll x){
    return (i128)2*dep[i]*x+dp[i]-(i128)dep[i]*dep[i];
}
struct segtree{
    int tot;
    struct node{
        int l,r,id,ls,rs;
    }e[M];
    #define l(p) e[p].l
    #define r(p) e[p].r
    int make(int x,int y,int id){
        e[++tot]={x,y,id,0,0};
        return tot;
    }
    int update(int p,int id){
        int mid=(l(p)+r(p))/2;
        if(calc(id,xs[mid])>calc(e[p].id,xs[mid])){
            swap(id,e[p].id);
        }
        if(l(p)==r(p))return p;
        if(calc(id,xs[l(p)])>calc(e[p].id,xs[l(p)])){
            int u=e[p].ls;
            if(!u)u=make(l(p),mid,id);
            else u=update(u,id);
            e[p].ls=u;
        }
        else if(calc(id,xs[r(p)])>calc(e[p].id,xs[r(p)])){
            int u=e[p].rs;
            if(!u)u=make(mid+1,r(p),id);
            else u=update(u,id);
            e[p].rs=u;
        }
        return p;
    }
    int insert(int p,int id){
        return p?update(p,id):make(0,k-1,id);
    }
    i128 query(int p,ll x){
        i128 ans=-INF;
        while(p){
            ans=max(ans,calc(e[p].id,x));
            int mid=(l(p)+r(p))/2;
            p=x<=xs[mid]?e[p].ls:e[p].rs;
        }
        return ans;
    }
}tr;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(rt,0,sizeof rt);
        memset(head,0,sizeof head);
        memset(tail,0,sizeof tail);
        memset(nxt,0,sizeof nxt);
        memset(sz,0,sizeof sz);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;++i){
            ll len;
            scanf("%d%lld%lld%lld",&fa[i],&len,&val[i],&f[i]);
            dep[i]=dep[fa[i]]+len;
            xs[i-1]=dep[i]+f[i];
        }
        sort(xs,xs+n);
        k=unique(xs,xs+n)-xs;
        tr.tot=0;
        ll ans=0;
        for(int u=n;u>=1;--u){
            ll x=dep[u]+f[u];
            if(rt[u]){
                dp[u]=max((i128)0,tr.query(rt[u],x)-(i128)x*x+val[u]);
            }
            ans=(ans+(ll)(dp[u]%mod))%mod;
            rt[u]=tr.insert(rt[u],u);
            if(head[u])nxt[tail[u]]=u;
            else head[u]=u;
            tail[u]=u;
            ++sz[u];
            int p=fa[u];
            if(!p)continue;
            if(sz[p]<sz[u]){
                swap(head[p],head[u]);
                swap(tail[p],tail[u]);
                swap(sz[p],sz[u]);
                swap(rt[p],rt[u]);
            }
            for(int id=head[u];id;id=nxt[id]){
                rt[p]=tr.insert(rt[p],id);
            }
            if(head[u]){
                nxt[tail[p]]=head[u];
                tail[p]=tail[u];
            }
            sz[p]+=sz[u];
            head[u]=tail[u]=sz[u]=rt[u]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201712/VALIDATION.md)
- [de-array-followup-report.json](../tests/201712/de-array-followup-report.json)
- [details.txt](../tests/201712/details.txt)
- [nightly-review-followup.json](../tests/201712/nightly-review-followup.json)
- [online-update-report.json](../tests/201712/online-update-report.json)
- [online-verdicts.json](../tests/201712/online-verdicts.json)
- [prose-final-review.json](../tests/201712/prose-final-review.json)
- [report.json](../tests/201712/report.json)
- [retained_oracles.py](../tests/201712/retained_oracles.py)
- [verify-de-followup.py](../tests/201712/verify-de-followup.py)
- [verify.py](../tests/201712/verify.py)

<!-- local-validation-attachments:end -->
