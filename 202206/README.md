---
title: "CSP 202206 五题题解"
contest: "202206"
contest_month: "2022-06"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "均值", "方差", "浮点数", "稀疏坐标", "枚举", "矩阵匹配", "权限系统", "位集", "哈希表", "模拟", "有序集合", "几何", "线段树", "矩阵", "仿射变换", "计算几何"]
status: "published"
problems: [{"id": "A", "title": "归一化处理", "tags": ["均值", "方差", "浮点数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P13910"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05830ae5d1fced2e455719", "source_sha256": "be41560514213ca80e4beff5b50d2ec8585db76e2cca82355d10348b83f89892", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:29:47.247493+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305937570", "source_sha256": "c1e2dcc4f047a86704b4cc0da88bbebfd5ed840f08d9f5cdb47d36a9b3137cc1"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce920a67df0b81749c03a"}}, {"id": "B", "title": "寻宝！大冒险！", "tags": ["稀疏坐标", "枚举", "矩阵匹配"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P13911"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0583a4e5d1fced2e4558bf", "source_sha256": "736f5e3862eac6c8747b5803578afbee351c494986490822e0c6cdc9a21ec5f7", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:32:28.688569+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305938226", "source_sha256": "c4bd808350d4951436fba8b59a592650e534fa773d7e8875ad4b87137feac365"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce921a67df0b81749c040"}}, {"id": "C", "title": "角色授权", "tags": ["权限系统", "位集", "哈希表", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P13912"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206C/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b058437e5d1fced2e455a13", "source_sha256": "b18f838e56e8901b5d12ee81e51d038440278b987d334e9c23d66bf2f779ba35", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:34:51.068517+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305939423", "source_sha256": "6a7f11b6730219655a2f7086866eed2ac34cf2a420f0d7f574b601fd945d5e55"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce923a67df0b81749c046"}}, {"id": "D", "title": "光线追踪", "tags": ["模拟", "有序集合", "几何"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P13913"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0584d0e5d1fced2e455c99", "source_sha256": "c4a6adfccafac181025c18c3263f54963f6fed2e7d261f772babfca324a7637d", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:37:29.758373+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305940404", "source_sha256": "c66dd2a4555c087b797cd0757325577bf1b1e7a5d162d75d1d9a646283df5ce2"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce925a67df0b81749c04d"}}, {"id": "E", "title": "PS 无限版", "tags": ["线段树", "矩阵", "仿射变换", "计算几何"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202206E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202206E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05850ee5d1fced2e455d90", "source_sha256": "0aa0f4041561176d9d95fb2ae5323dbaed900444308329b95684c7029b04d39b", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T12:38:42.302480+00:00"}, "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490960"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addcb9374ace1cba9a21e80", "source_sha256": "cf492760608f922b71d0100c83502a913c3365af4f0d2e666c6024dee9fee905"}}]
---

# CSP 202206 五题题解

[原页面](https://code92007.github.io/csp/#/contest/202206) · [验证记录](../tests/202206/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 归一化处理

标签：`均值` · `方差` · `浮点数`

本地：62 组优化版、62 组 UBSan 验证通过，详见 [验证记录](../tests/202206/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05830ae5d1fced2e455719)。

<!-- refactor-online:A:end -->

### 题意

给定 $n$ 个整数，按均值 $\mu$ 和总体方差 $D$ 将每个数归一化为 $(a_i-\mu)/\sqrt D$。

输入先给出 $n$，再给出全部整数。满足 $n,|a_i|\le1000$，保证 $D\ge1$。

按输入顺序逐行输出归一化结果，绝对误差不超过 $10^{-4}$。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P13910)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206A)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206A/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce920a67df0b81749c03a)（accepted，100 分；复刻评测）。

### 题解

**按定义计算**

第一遍求均值，第二遍累加与均值之差的平方，再除以 $n$ 并开方，得到标准差。最后逐个输出归一化结果。

总体方差的分母是 $n$，均值需要浮点除法。先计算平方差也能避免直接用平方和减均值平方造成的大数相消。

**正确性与复杂度**

三步计算分别对应均值、方差和归一化定义，因此输出正确。时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1010;
int n;
ld a[N],mu,var;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%Lf",&a[i]);
        mu+=a[i];
    }
    mu/=n;
    for(int i=1;i<=n;++i){
        ld x=a[i]-mu;
        var+=x*x;
    }
    var=sqrtl(var/n);
    for(int i=1;i<=n;++i){
        printf("%.10Lf\n",(a[i]-mu)/var);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 寻宝！大冒险！

标签：`稀疏坐标` · `枚举` · `矩阵匹配`

本地：103 组优化版、103 组 UBSan 验证通过，详见 [验证记录](../tests/202206/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0583a4e5d1fced2e4558bf)。

<!-- refactor-online:B:end -->

### 题意

绿化图中有 $n$ 棵树，藏宝图是一块 $(S+1)\times(S+1)$ 的 01 矩阵，左下角一定有树。求绿化图中有多少个不越界的方形区域与藏宝图完全相同。

输入先给出 $n,L,S$，再给出树的互异坐标，最后给出藏宝图。满足 $n\le1000$、$L\le10^9$、$S\le50$，坐标均在 $[0,L]$；藏宝图第一行对应第一坐标 $S$，最后一行对应第一坐标 $0$。

输出可以作为藏宝图左下角的位置数。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P13911)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206B)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206B/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce921a67df0b81749c040)（accepted，100 分；复刻评测）。

### 题解

**只枚举已有树作为左下角**

藏宝图左下角是 $1$，因此候选位置只有已有的 $n$ 棵树。跳过右上角越界的候选，再扫描全部树，检查落入方形内的树是否都对应藏宝图中的 $1$，并统计数量。

若没有树落在 $0$ 上，且树数等于藏宝图中 $1$ 的总数，这个候选就匹配成功。

**正确性**

候选枚举不会漏掉合法左下角。树的坐标互异，因此每棵树对应不同的格子；所有树都位于 $1$ 上且数量相等，就保证全部 $1$ 都被覆盖，而全部 $0$ 都没有树。

**复杂度**

时间 $O(n^2+S^2)$，空间 $O(n+S^2)$，无需存储整张大地图。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=1010,M=55;
int n,l,s,b[M][M],tot,ans;
P a[N];
int main(){
    scanf("%d%d%d",&n,&l,&s);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    for(int i=s;i>=0;--i){
        for(int j=0;j<=s;++j){
            scanf("%d",&b[i][j]);
            tot+=b[i][j];
        }
    }
    for(int i=0;i<n;++i){
        auto [x,y]=a[i];
        if(x+s>l || y+s>l)continue;
        int cnt=0;
        bool ok=1;
        for(int j=0;j<n;++j){
            auto [u,v]=a[j];
            int dx=u-x,dy=v-y;
            if(dx<0 || dx>s || dy<0 || dy>s)continue;
            ++cnt;
            if(!b[dx][dy]){
                ok=0;
                break;
            }
        }
        ans+=(ok && cnt==tot);
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. 角色授权

标签：`权限系统` · `位集` · `哈希表` · `模拟`

本地：102 组优化版、102 组 UBSan 验证通过，详见 [验证记录](../tests/202206/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b058437e5d1fced2e455a13)。

<!-- refactor-online:C:end -->

### 题意

角色规定允许的操作、资源种类和资源名称，并可关联到用户或用户组。对每次请求，判断是否存在一个关联角色同时允许该操作、资源种类和资源名称。

输入先给出角色数 $n$、关联数 $m$ 和查询数 $q$，依次描述角色清单、用户或组的角色关联、待授权请求。满足 $n,m\le500$、$q\le5000$，各清单和单次用户组数不超过 $400$，字符串长度不超过 $10$。

操作与资源种类清单中的 `*` 表示任意，资源名称清单为空时表示任意。查询所属组只以本次输入为准，不能沿用之前同名用户的所属组。

每次请求输出 `1` 表示允许，否则输出 `0`。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P13912)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206C)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206C/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce923a67df0b81749c046)（accepted，100 分；复刻评测）。

### 题解

**位集收集关联角色**

分别保存角色的三个权限集合。为每个用户、用户组维护角色位集，读取关联时将对应位设为 $1$。

查询时，把用户名和本次全部所属组的角色位集按位或，得到所有可用角色。随后逐角色检查三个条件，任意一个角色全部通过就允许操作。

**正确性**

位集的并集准确表示用户直接或通过组关联的角色。角色内部三个条件取合取、角色之间取析取，与授权规则一致。

不能把不同角色的三个权限字段分别合并，否则可能将甲角色的操作权限与乙角色的资源权限拼成不存在的授权。

**复杂度**

设角色数为 $R$，单次查询所属组数为 $G$。忽略字符串长度，哈希查询期望常数时间，单次期望时间 $O(G\lceil R/64\rceil+R)$；空间为全部权限字符串和关联位集的大小。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=510,M=15;
int n,m,q;
char s[M];
struct role{
    unordered_set<string>op,type,name;
}a[N];
unordered_map<string,int>id;
unordered_map<string,bitset<N>>user,group;
string read(){
    scanf("%s",s);
    return s;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;++i){
        id[read()]=i;
        for(auto *st:{&a[i].op,&a[i].type,&a[i].name}){
            int k;
            scanf("%d",&k);
            while(k--){
                st->insert(read());
            }
        }
    }
    while(m--){
        string r=read();
        int k;
        scanf("%d",&k);
        while(k--){
            string t=read(),s=read();
            (t=="u"?user:group)[s].set(id[r]);
        }
    }
    while(q--){
        string s=read();
        int k;
        scanf("%d",&k);
        bitset<N>can;
        auto it=user.find(s);
        if(it!=user.end())can=it->second;
        while(k--){
            string g=read();
            auto it=group.find(g);
            if(it!=group.end())can|=it->second;
        }
        string op=read(),type=read(),name=read();
        bool ok=0;
        for(int i=0;i<n;++i){
            if(!can[i])continue;
            role &r=a[i];
            bool x=r.op.count("*") || r.op.count(op);
            bool y=r.type.count("*") || r.type.count(type);
            bool z=r.name.empty() || r.name.count(name);
            if(x && y && z){
                ok=1;
                break;
            }
        }
        printf("%d\n",ok);
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 光线追踪

标签：`模拟` · `有序集合` · `几何`

本地：103 组优化版、103 组 UBSan 验证通过，详见 [验证记录](../tests/202206/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0584d0e5d1fced2e455c99)。

<!-- refactor-online:D:end -->

### 题意

动态维护与坐标轴成 $45^\circ$ 的镜面线段。激光沿坐标轴运动，遇镜面改变方向并乘折损系数，求指定时间后的位置和向下取整的强度；镜面端点不反射。

输入先给出操作数 $m\le10^5$。所有插入镜面的横向长度之和不超过 $3\times10^5$，输入整数绝对值不超过 $10^9$，初始强度不超过 $10^9$，折损系数在 $[0.2,0.8]$，实数最多六位小数。镜面内部互不相交，光源不位于镜面内部。

- `1 x1 y1 x2 y2 a`：插入镜面。
- `2 k`：删除第 $k$ 个操作插入的镜面。
- `3 x y d I t`：发射激光，方向 $0,1,2,3$ 分别为右、上、左、下。

每次查询输出最终坐标与强度。到达镜面恰好用完时间也要折损；强度低于 $1$ 时输出 `0 0 0`。题目保证直接使用 64 位浮点计算及取整即可。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P13913)；[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206D)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206D/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce925a67df0b81749c04d)（accepted，100 分；复刻评测）。

### 题解

**展开镜面的内部整点**

激光从整数点出发，沿坐标轴与 $45^\circ$ 镜面的交点仍是整数点，反射后也沿坐标轴运动。因此只需记录镜面的内部整点，排除端点即可；总横向长度保证展开规模可控。

建立两张有序映射，分别以 $(y,x)$ 和 $(x,y)$ 排序。横向运动使用前者，纵向使用后者；向正方向找严格后继，负方向找严格前驱，并检查是否仍处于同一直线上。

**直接跳到下一次碰撞**

若最近镜面距离大于剩余时间，就沿当前方向走完。否则移动到交点、扣除时间、乘折损系数，再改变方向。查找严格前驱或后继可以排除刚刚反射的位置。

斜率 $1$ 的镜面交换右与上、左与下；斜率 $-1$ 的镜面交换右与下、上与左。

**正确性**

每次索引查询得到当前射线上最近的真实镜面交点，所以跳跃不会遗漏中途碰撞。每次更新精确执行移动、反射和折损，循环结束便得到时间用尽或强度耗散时的状态。

**复杂度**

每次反射强度至多保留 $0.8$ 倍，初始不超过 $10^9$，至多约 $93$ 次反射就耗散。设总内部点数为 $S$、查询数为 $Q$，时间 $O((S+93Q)\log(S+1))$，空间 $O(S+m)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=1e5+10,M=4;
const int dx[M]={1,0,-1,0},dy[M]={0,1,0,-1};
int m;
struct mirror{
    ll x1,y1,x2,y2;
    double a;
    int k;
}s[N];
map<P,int>h,v;
void update(int id,bool add){
    mirror &p=s[id];
    for(ll x=p.x1+1;x<p.x2;++x){
        ll y=p.y1+p.k*(x-p.x1);
        if(add){
            h[P(y,x)]=id;
            v[P(x,y)]=id;
        }
        else{
            h.erase(P(y,x));
            v.erase(P(x,y));
        }
    }
}
int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        int op;
        scanf("%d",&op);
        if(op==1){
            mirror &p=s[i];
            scanf("%lld%lld%lld%lld%lf",&p.x1,&p.y1,&p.x2,&p.y2,&p.a);
            if(p.x1>p.x2){
                swap(p.x1,p.x2);
                swap(p.y1,p.y2);
            }
            p.k=p.y2>p.y1?1:-1;
            update(i,1);
        }
        else if(op==2){
            int id;
            scanf("%d",&id);
            update(id,0);
        }
        else{
            ll x,y,t;
            int d;
            double w;
            scanf("%lld%lld%d%lf%lld",&x,&y,&d,&w,&t);
            while(t>0 && w>=1){
                bool hor=d%2==0,pos=d<2;
                auto &g=hor?h:v;
                ll line=hor?y:x,cur=hor?x:y;
                auto it=g.end();
                if(pos)it=g.upper_bound(P(line,cur));
                else{
                    auto p=g.lower_bound(P(line,cur));
                    if(p!=g.begin())it=prev(p);
                }
                bool ok=(it!=g.end() && it->first.first==line);
                ll dis=ok?abs(it->first.second-cur):t+1;
                if(dis>t){
                    x+=dx[d]*t;
                    y+=dy[d]*t;
                    break;
                }
                x+=dx[d]*dis;
                y+=dy[d]*dis;
                t-=dis;
                mirror &p=s[it->second];
                w*=p.a;
                d^=p.k==1?1:3;
            }
            if(w<1)puts("0 0 0");
            else printf("%lld %lld %lld\n",x,y,(ll)floor(w));
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. PS 无限版

标签：`线段树` · `矩阵` · `仿射变换` · `计算几何`

本地：263 组优化版、263 组 UBSan 验证通过，详见 [验证记录](../tests/202206/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05850ee5d1fced2e455d90)。

<!-- refactor-online:E:end -->

### 题意

维护按编号排列的平面点，支持区间平移、旋转、缩放、轴对称和投影，并查询区间重心或到给定点的距离平方和。

输入先给出 $n,q$ 和各点坐标，再给出操作。满足 $n\le5\times10^5$、$q\le2\times10^4$，保证任意时刻点坐标绝对值不超过 $10^6$；角度均以弧度给出。

- `1 l r a b`：平移向量 $(a,b)$。
- `2 l r a b θ`：绕 $(a,b)$ 逆时针旋转 $\theta$。
- `3 l r a b λ`：以 $(a,b)$ 为中心缩放，$\lambda$ 可为负或零。
- `4 l r θ y0`：关于 $y=(\tan\theta)x+y_0$ 对称。
- `5 l r θ y0`：投影到上述直线。
- `6 l r`：查询重心。
- `7 l r a b`：查询到 $(a,b)$ 的距离平方和。

对操作 $6$、$7$ 分别输出两个、一个实数，绝对或相对误差不超过 $10^{-3}$。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202206E)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202206E/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addcb9374ace1cba9a21e80)（accepted，100 分；复刻评测）。

### 题解

**统一为仿射变换**

用齐次列向量 $(x,y,1)^T$ 表示点，五种修改都能写成 $p'=Tp$，其中 $T$ 是 $3\times3$ 矩阵。若线性部分是 $A$、变换中心为 $c$，平移列统一写成 $c-Ac$。

平移的线性部分为单位矩阵，旋转使用正余弦矩阵，缩放为 $\lambda I$。直线方向为 $d=(\cos\theta,\sin\theta)^T$ 时，投影的线性部分为 $dd^T$，对称为 $2dd^T-I$，取 $c=(0,y_0)^T$ 即可，避免直接计算正切。

**维护重心和中心二阶矩**

每段记录点数 $N$、重心 $\mu$，以及中心矩阵

$$C=\sum(p-\mu)(p-\mu)^T.$$

只需保存其 $xx,xy,yy$ 三项。仿射变换的线性部分为 $A$、平移为 $b$ 时，

$$\mu'=A\mu+b,\qquad C'=ACA^T.$$

合并两段时，令 $\delta=\mu_2-\mu_1$，则

$$\mu=\mu_1+\frac{N_2}{N_1+N_2}\delta,$$
$$C=C_1+C_2+\frac{N_1N_2}{N_1+N_2}\delta\delta^T.$$

这样能减少坐标很大、点间距离却很小时的大数相消。查询重心直接返回 $\mu$，到点 $z$ 的距离平方和为

$$\operatorname{tr}(C)+N\lVert\mu-z\rVert^2.$$

**线段树维护区间**

懒标记保存完整仿射矩阵，新变换放在旧变换左侧，即 `tag=T*tag`。叶子的中心矩阵为零，空查询段点数为零，合并时直接忽略。按节点区间递归建树。

**正确性**

仿射矩阵分别准确表示五种操作。重心与中心矩阵的变换、合并公式均由逐点展开得到，线段树因此始终记录实际点集的统计量；查询公式随之给出正确结果。

**复杂度**

建树 $O(n)$，每次操作 $O(3^3\log n)$，空间 $O(n)$。使用 `long double` 并对最终距离平方和作非负截断，结果按题面浮点容差比较。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1<<19,M=3;
int n,q,op,l,r;
ld x[N],y[N];
struct mat{
    ld a[M][M];
    mat(){
        memset(a,0,sizeof a);
    }
};
mat unit(){
    mat a;
    for(int i=0;i<M;++i){
        a.a[i][i]=1;
    }
    return a;
}
mat operator*(const mat &a,const mat &b){
    mat c;
    for(int i=0;i<M;++i){
        for(int k=0;k<M;++k){
            for(int j=0;j<M;++j){
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
            }
        }
    }
    return c;
}
struct info{
    ld cnt=0,x=0,y=0,xx=0,xy=0,yy=0;
};
info operator+(info a,info b){
    if(!a.cnt)return b;
    if(!b.cnt)return a;
    ld cnt=a.cnt+b.cnt,dx=b.x-a.x,dy=b.y-a.y;
    ld w=a.cnt*b.cnt/cnt;
    info c;
    c.cnt=cnt;
    c.x=a.x+dx*b.cnt/cnt;
    c.y=a.y+dy*b.cnt/cnt;
    c.xx=a.xx+b.xx+w*dx*dx;
    c.xy=a.xy+b.xy+w*dx*dy;
    c.yy=a.yy+b.yy+w*dy*dy;
    return c;
}
info trans(const info &s,const mat &t){
    ld a=t.a[0][0],b=t.a[0][1];
    ld c=t.a[1][0],d=t.a[1][1];
    info v;
    v.cnt=s.cnt;
    v.x=a*s.x+b*s.y+t.a[0][2];
    v.y=c*s.x+d*s.y+t.a[1][2];
    v.xx=a*a*s.xx+2*a*b*s.xy+b*b*s.yy;
    v.xy=a*c*s.xx+(a*d+b*c)*s.xy+b*d*s.yy;
    v.yy=c*c*s.xx+2*c*d*s.xy+d*d*s.yy;
    return v;
}
struct segtree{
    struct node{
        int l,r;
        info s;
        mat tag;
        bool ok;
    }e[N<<1];
    #define l(p) e[p].l
    #define r(p) e[p].r
    void pushup(int p){
        e[p].s=e[p<<1].s+e[p<<1|1].s;
    }
    void build(int p,int a,int b){
        l(p)=a;r(p)=b;
        e[p].tag=unit();
        if(a==b){
            e[p].s={1,x[a],y[a],0,0,0};
            return;
        }
        int mid=(a+b)>>1;
        build(p<<1,a,mid);
        build(p<<1|1,mid+1,b);
        pushup(p);
    }
    void change(int p,const mat &t){
        e[p].s=trans(e[p].s,t);
        e[p].tag=t*e[p].tag;
        e[p].ok=1;
    }
    void pushdown(int p){
        if(!e[p].ok)return;
        change(p<<1,e[p].tag);
        change(p<<1|1,e[p].tag);
        e[p].tag=unit();
        e[p].ok=0;
    }
    void update(int p,int a,int b,const mat &t){
        if(a<=l(p) && r(p)<=b){
            change(p,t);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(a<=mid)update(p<<1,a,b,t);
        if(b>mid)update(p<<1|1,a,b,t);
        pushup(p);
    }
    info query(int p,int a,int b){
        if(a<=l(p) && r(p)<=b)return e[p].s;
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        info ans;
        if(a<=mid)ans=ans+query(p<<1,a,b);
        if(b>mid)ans=ans+query(p<<1|1,a,b);
        return ans;
    }
}tr;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%Lf%Lf",&x[i],&y[i]);
    }
    tr.build(1,1,n);
    while(q--){
        scanf("%d%d%d",&op,&l,&r);
        if(op>=6){
            info s=tr.query(1,l,r);
            if(op==6)printf("%.12Lf %.12Lf\n",s.x,s.y);
            else{
                ld a,b;
                scanf("%Lf%Lf",&a,&b);
                ld dx=s.x-a,dy=s.y-b;
                ld ans=s.xx+s.yy+s.cnt*(dx*dx+dy*dy);
                printf("%.12Lf\n",max(0.L,ans));
            }
            continue;
        }
        mat t=unit();
        ld a,b;
        if(op==1){
            scanf("%Lf%Lf",&a,&b);
            t.a[0][2]=a;
            t.a[1][2]=b;
        }
        else if(op==2 || op==3){
            ld x;
            scanf("%Lf%Lf%Lf",&a,&b,&x);
            if(op==2){
                ld c=cosl(x),s=sinl(x);
                t.a[0][0]=t.a[1][1]=c;
                t.a[0][1]=-s;
                t.a[1][0]=s;
            }
            else t.a[0][0]=t.a[1][1]=x;
            t.a[0][2]=a-t.a[0][0]*a-t.a[0][1]*b;
            t.a[1][2]=b-t.a[1][0]*a-t.a[1][1]*b;
        }
        else{
            ld angle,y,c,s;
            scanf("%Lf%Lf",&angle,&y);
            c=cosl(angle);s=sinl(angle);
            ld k=op==4?2:1,d=op==4?1:0;
            t.a[0][0]=k*c*c-d;
            t.a[0][1]=t.a[1][0]=k*c*s;
            t.a[1][1]=k*s*s-d;
            t.a[0][2]=-t.a[0][1]*y;
            t.a[1][2]=y-t.a[1][1]*y;
        }
        tr.update(1,l,r,t);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202206/VALIDATION.md)
- [cases.json](../tests/202206/cases.json)
- [compile.json](../tests/202206/compile.json)
- [current-sources.json](../tests/202206/current-sources.json)
- [extra.py](../tests/202206/extra.py)
- [online-update-report.json](../tests/202206/online-update-report.json)
- [online-verdicts.json](../tests/202206/online-verdicts.json)
- [summary.json](../tests/202206/summary.json)

<!-- local-validation-attachments:end -->
