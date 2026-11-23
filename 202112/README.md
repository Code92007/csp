---
title: "CSP 202112 五题题解"
contest: "202112"
contest_month: "2021-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "贡献法", "区间计数", "双指针", "分段函数", "区间统计", "编码", "多项式", "模运算", "模拟", "线段树", "离散化", "懒标记", "点分治", "树状数组", "离线统计", "树上路径", "位运算"]
status: "published"
problems: [{"id": "A", "title": "序列查询", "tags": ["贡献法", "区间计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16059"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce928a67df0b81749c05d"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305940917", "source_sha256": "74c492ab0f041b54d3dec002984de837659422a21c103bd228cfdd4c1202737f"}}, {"id": "B", "title": "序列查询新解", "tags": ["双指针", "分段函数", "区间统计"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16060"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adce92aa67df0b81749c061"}, "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490959"}}, {"id": "C", "title": "登机牌条码", "tags": ["编码", "多项式", "模运算", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16061"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adce92ba67df0b81749c065"}, "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490983"}}, {"id": "D", "title": "磁盘文件操作", "tags": ["线段树", "离散化", "懒标记"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16062"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce92da67df0b81749c06b"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305941488", "source_sha256": "3d1c08db14005411be92eb49ebc4c741a1d335fad30d8b220b8e836136c2e1dd"}}, {"id": "E", "title": "极差路径", "tags": ["点分治", "树状数组", "离线统计", "树上路径", "位运算"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202112E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16063"}], "previous_oj": {"status": "failed", "score": 56, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6addccac74ace1cba9a21f0f", "source_sha256": "fe2c351c465816e460e5a40eacc8102efc31798009081865a5b98656cff8aa70", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305494838", "source_sha256": "fe2c351c465816e460e5a40eacc8102efc31798009081865a5b98656cff8aa70", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6ade046d74ace1cba9a237ab", "source_sha256": "e7b86d3a8fe5877854bb5175dd65572766e7c8592c6c03896d4ab6741d0af312"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305944901", "source_sha256": "e7b86d3a8fe5877854bb5175dd65572766e7c8592c6c03896d4ab6741d0af312"}}]
---

# CSP 202112 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202112/VALIDATION.md)

<a id="problem-a"></a>

## A. 序列查询

标签：`贡献法` · `区间计数`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce928a67df0b81749c05d)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305940917)。重构版本地验证见 [VALIDATION.md](../tests/202112/VALIDATION.md)，未重新提交在线评测。

### 题意

给定严格递增序列 $0=A_0<A_1<\cdots<A_n<N$，定义 $f(x)$ 为满足 $A_i\le x$ 的最大下标 $i$。求所有整数 $0\le x<N$ 的 $f(x)$ 之和。

输入 $n,N$ 和 $A_1\ldots A_n$，$N$ 可达 $10^7$。

输出函数值的总和。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112A) · [公开题面存档](https://www.luogu.com.cn/problem/P16059)。

### 题解

因为序列严格递增，`f(x)` 也等于 `A[1]…A[n]` 中不超过 `x` 的元素个数。换一个统计方向：每个 `A[i]` 恰好给 `x=A[i]…N-1` 这 `N-A[i]` 个查询贡献 1，因此答案为 `Σ(N-A[i])`。

这只是交换“遍历查询再数元素”和“遍历元素再数查询”的加法顺序，每对符合 `A[i]≤x` 的组合恰好计一次。时间 $O(n)$，额外空间 $O(1)$，无需二分或遍历 N 个值。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,x,ans;
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&x);
        ans+=m-x;
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 序列查询新解

标签：`双指针` · `分段函数` · `区间统计`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce92aa67df0b81749c061)；[洛谷民间数据 100 分 accepted](https://www.luogu.com.cn/record/305490959)。重构版本地验证见 [VALIDATION.md](../tests/202112/VALIDATION.md)，未重新提交在线评测。

### 题意

给定严格递增序列 $A_0=0<A_1<\cdots<A_n<N$，令 $f(x)$ 为不超过 $x$ 的序列元素的最大下标。再令 $r=\lfloor N/(n+1)\rfloor$、$g(x)=\lfloor x/r\rfloor$，求所有整数 $0\le x<N$ 的 $|f(x)-g(x)|$ 之和。

输入 $n,N$ 和 $A_1\ldots A_n$，$N\le10^9$。由严格递增条件可知 $N\ge n+1$，所以 $r\ge1$。

输出总误差。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112B) · [公开题面存档](https://www.luogu.com.cn/problem/P16060)。

### 题解

f 在相邻 A 之间不变，g 在相邻 r 的倍数之间不变。 当前坐标为 x、f(x)=i、g(x)=j 时，下一个变化点为 `y=min(a[i+1],(j+1)*r)`，这一整段贡献 `(y-x)*abs(i-j)`。 累加后直接跳到 y。

每段内两函数恒定，所有段又恰好覆盖 [0,N)，所以分段求和等于逐点求和。每次跳跃至少跨过一类断点，总段数 $O(n+N/r)=O(n)$，因为 r 的定义使 N/r<2(n+1)。时间、空间均 $O(n)$，乘积和总误差用 64 位整数。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,r,x,ans;
vector<ll> a;
int main(){
    scanf("%d%lld",&n,&m);
    a.resize(n+2);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    a[n+1]=m;
    r=m/(n+1);
    int i=0;
    while(x<m){
        while(i<n && a[i+1]<=x){
            ++i;
        }
        ll j=x/r,y=min(a[i+1],(j+1)*r);
        ans+=(y-x)*llabs(j-i);
        x=y;
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. 登机牌条码

标签：`编码` · `多项式` · `模运算` · `模拟`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce92ba67df0b81749c065)；[洛谷民间数据 100 分 accepted](https://www.luogu.com.cn/record/305490983)。重构版本地验证见 [VALIDATION.md](../tests/202112/VALIDATION.md)，未重新提交在线评测。

### 题意

将大小写字母、数字组成的字符串编码为简化 PDF417 码字。字符使用三种模式，通过 27、28 切换；每两个字符数值合成 $30H+L$，奇数项补 29。数据前加入长度码字，末尾补 900，使数据与校验总数成为行宽的倍数。

输入行宽 $w$、校验级别 $s$ 和待编码字符串。级别 $s$ 对应 $k=2^{s+1}$ 个校验字，$s=-1$ 时无校验；数据码字数小于 929。

依次输出数据与校验码字，每个整数占一行。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112C) · [公开题面存档](https://www.luogu.com.cn/problem/P16061)。

### 题解

先维护当前字符模式，按最短路径切换：进入小写用 27，进入数字用 28；数字到大写用 28，小写到大写必须连续两个 28。 收集字符数值后两两配对。

注意补 29 与补 900 属于不同阶段，长度码字包括自身及 900 填充，但不包括校验字。

所有多项式计算在模 929 下进行。逐次乘以 $(x-3^i)$ 构造首一多项式 g，数组按降幂存放。给数据多项式末尾补 k 个零，得到 $x^k d(x)$；从最高位开始，用当前系数乘 g 并相减，逐项消掉高次项。

题目定义是 $x^k d=qg-r$，而普通除法得到 $x^k d=qg+\mathrm{rem}$，所以校验字必须取余式系数的相反数，按高次到低次输出。这样数据和校验拼出的多项式被 g 整除，满足全部校验规则。时间 $O(k^2+nk+|S|)$，空间 $O(n+k+|S|)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=2010,mod=929;
int w,s;
char t[N];
vector<int> a,b,g;
int main(){
    scanf("%d%d%s",&w,&s,t);
    int mode=0;
    for(int i=0;t[i];++i){
        char c=t[i];
        int next=isupper(c)?0:islower(c)?1:2;
        if(mode!=next){
            if(next==1)a.push_back(27);
            else if(next==2)a.push_back(28);
            else{
                a.push_back(28);
                if(mode==1)a.push_back(28);
            }
            mode=next;
        }
        a.push_back(c-(mode==0?'A':mode==1?'a':'0'));
    }
    if(a.size()%2)a.push_back(29);
    b.push_back(0);
    for(int i=0;i<(int)a.size();i+=2){
        b.push_back(a[i]*30+a[i+1]);
    }
    int k=s<0?0:1<<(s+1);
    while((b.size()+k)%w){
        b.push_back(900);
    }
    b[0]=b.size();
    for(int &x:b){
        printf("%d\n",x);
    }
    if(!k)return 0;
    g.push_back(1);
    int power=1;
    for(int i=1;i<=k;++i){
        power=power*3%mod;
        vector<int> h(g.size()+1);
        for(int j=0;j<(int)g.size();++j){
            h[j]=(h[j]+g[j])%mod;
            h[j+1]=(h[j+1]-g[j]*power%mod+mod)%mod;
        }
        g.swap(h);
    }
    vector<int> rem=b;
    rem.resize(b.size()+k);
    for(int i=0;i<(int)b.size();++i){
        int v=rem[i];
        for(int j=0;j<=k;++j){
            rem[i+j]=(rem[i+j]-v*g[j]%mod+mod)%mod;
        }
    }
    for(int i=b.size();i<(int)rem.size();++i){
        printf("%d\n",(mod-rem[i])%mod);
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 磁盘文件操作

标签：`线段树` · `离散化` · `懒标记`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce92da67df0b81749c06b)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305941488)。重构版本地验证见 [VALIDATION.md](../tests/202112/VALIDATION.md)，未重新提交在线评测。

### 题意

磁盘位置为 $1\ldots m$，初始空闲、数据值均为 0。程序可以写入、删除和恢复文件，删除只释放占用，不清除历史数据。

输入程序数 $n$、磁盘大小 $m$、操作数 $k$ 和各条操作。$m\le10^9$，操作数不超过 $2\times10^5$。

- `0 id l r x`：从左向右写入值 $x$，遇到首个被其他程序占用的位置停止。输出成功写入的最右位置，完全不能写入时输出 $-1$。
- `1 id l r`：仅当整段当前都属于 `id` 时删除，输出 `OK` 或 `FAIL`。
- `2 id l r`：仅当整段均空闲、上次主人又都是 `id` 时恢复，输出 `OK` 或 `FAIL`。
- `3 p`：输出当前位置的主人和数据值；空闲时输出 `0 0`。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112D) · [公开题面存档](https://www.luogu.com.cn/problem/P16062)。

### 题解

**用带符号主人编号表示历史**

正数 id 表示被占用，负数 -id 表示已删除、上次属于 id，0 表示从未占用。 另行保存数据值，删除与恢复只改变主人编号。这样恢复的条件就是整段状态均为 -id，无需建立额外历史链。

收集所有操作的 l、r+1 边界（点读取也收集 p、p+1），离散化成原磁盘上的连续小段。线段树维护主人状态最小值、最大值，以及正主人编号的最小值和最大值。

删除时检查最小值和最大值均为 id，再整段赋 -id；恢复反之。

写入时，正主人集合为空，或全部为当前 id 的节点，都可以整体跳过检查。 否则向左右孩子查找第一个不允许写入的叶子，并对它左侧的目标区间执行“主人赋 id、数据赋 x”。 原坐标中的最右端点由下一条离散化边界减 1 得到。

主人赋值和数据赋值采用两套独立懒标记：只删除主人时，旧的数据赋值标记仍要保留，之后下传给孩子才能恢复原数据。读到正主人时输出保存的值，否则输出 0 0。

每种状态更新都与题目规则一致；找首个冲突时始终先找左子树，且只跳过全部可写的节点，因此不会越过第一个冲突位置。总时间 $O(k\log k)$，空间 $O(k)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
struct info{
    int mn,mx,lo,hi;
};
info merge(info a,info b){
    return {min(a.mn,b.mn),max(a.mx,b.mx),
            min(a.lo,b.lo),max(a.hi,b.hi)};
}
struct query{
    int op,id,l,r,x;
};
int n,m,k;
vector<query> q;
vector<int> v;
struct segtree{
    struct node{
        int l,r,tag,val;
        info s;
        bool own,mark;
    };
    vector<node> e;
    #define l(p) e[p].l
    #define r(p) e[p].r
    void build(int p,int x,int y){
        l(p)=x;r(p)=y;
        e[p].s={0,0,INF,0};
        if(x==y)return;
        int mid=(x+y)/2;
        build(p*2,x,mid);
        build(p*2+1,mid+1,y);
    }
    void owner(int p,int id){
        e[p].s={id,id,id>0?id:INF,id>0?id:0};
        e[p].tag=id;
        e[p].own=true;
    }
    void op(int p,int x){
        e[p].val=x;
        e[p].mark=true;
    }
    void pushup(int p){
        e[p].s=merge(e[p*2].s,e[p*2+1].s);
    }
    void pushdown(int p){
        if(e[p].own){
            owner(p*2,e[p].tag);
            owner(p*2+1,e[p].tag);
            e[p].own=false;
        }
        if(e[p].mark){
            op(p*2,e[p].val);
            op(p*2+1,e[p].val);
            e[p].mark=false;
        }
    }
    info query(int p,int x,int y){
        if(x<=l(p) && r(p)<=y)return e[p].s;
        pushdown(p);
        int mid=(l(p)+r(p))/2;
        if(y<=mid)return query(p*2,x,y);
        if(x>mid)return query(p*2+1,x,y);
        return merge(query(p*2,x,y),query(p*2+1,x,y));
    }
    int find(int p,int x,int y,int id){
        auto &s=e[p].s;
        if(r(p)<x || l(p)>y || !s.hi)return -1;
        if(s.lo==id && s.hi==id)return -1;
        if(l(p)==r(p))return l(p);
        pushdown(p);
        int u=find(p*2,x,y,id);
        return u!=-1?u:find(p*2+1,x,y,id);
    }
    void update(int p,int x,int y,int id,bool write,int val){
        if(x<=l(p) && r(p)<=y){
            owner(p,id);
            if(write)op(p,val);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))/2;
        if(x<=mid)update(p*2,x,y,id,write,val);
        if(y>mid)update(p*2+1,x,y,id,write,val);
        pushup(p);
    }
    P read(int p,int x){
        if(l(p)==r(p)){
            int id=e[p].s.mn;
            return id>0?P(id,e[p].val):P(0,0);
        }
        pushdown(p);
        int mid=(l(p)+r(p))/2;
        return x<=mid?read(p*2,x):read(p*2+1,x);
    }
}tr;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    q.resize(k);
    v.push_back(1);
    v.push_back(m+1);
    for(auto &e:q){
        scanf("%d",&e.op);
        if(e.op==3){
            scanf("%d",&e.l);
            e.r=e.l;
        }
        else{
            scanf("%d%d%d",&e.id,&e.l,&e.r);
            if(!e.op)scanf("%d",&e.x);
        }
        v.push_back(e.l);
        v.push_back(e.r+1);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int len=v.size()-1;
    tr.e.resize(len*4+4);
    tr.build(1,0,len-1);
    for(auto &e:q){
        int l=lower_bound(v.begin(),v.end(),e.l)-v.begin();
        int r=lower_bound(v.begin(),v.end(),e.r+1)-v.begin()-1;
        if(e.op==3){
            auto [id,val]=tr.read(1,l);
            printf("%d %d\n",id,val);
        }
        else if(!e.op){
            int pos=tr.find(1,l,r,e.id);
            int end=pos==-1?r:pos-1;
            if(end<l)puts("-1");
            else{
                tr.update(1,l,end,e.id,true,e.x);
                printf("%d\n",v[end+1]-1);
            }
        }
        else{
            info s=tr.query(1,l,r);
            int id=e.op==1?e.id:-e.id;
            bool ok=(s.mn==id && s.mx==id);
            puts(ok?"OK":"FAIL");
            if(ok)tr.update(1,l,r,-id,false,0);
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 极差路径

标签：`点分治` · `树状数组` · `离线统计` · `树上路径` · `位运算`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6ade046d74ace1cba9a237ab)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305944901)。重构版本地验证见 [VALIDATION.md](../tests/202112/VALIDATION.md)，未重新提交在线评测。

### 题意

树的顶点编号为 $1\ldots n$，编号也是该景点的不满意程度。统计无向简单路径 $(x,y)$，使路径上的所有编号均位于 $[\min(x,y)-k_1,\max(x,y)+k_2]$ 内。单点路径合法，正反方向只计一次。

输入 `n k1 k2` 和 $n-1$ 条边，$n\le5\times10^5$。

输出合法路径总数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202112E) · [公开题面与样例](https://www.luogu.com.cn/problem/P16063)。

### 题解

#### 1. 用点分治确定路径经过的中心

取当前连通块的重心 `c`。先统计经过 `c` 的合法路径，再删除 `c`，分别处理剩余分支。每次删去重心后，每个分支至多有原来一半的点，因此只有 `O(log n)` 层。

对每个点 `v`，记录从 `c` 到 `v` 的路径上的最小编号 `low[v]` 和最大编号 `high[v]`。 若两个端点属于不同分支，它们的路径经过 `c`，路径最小值就是两个 `low` 的最小值，最大值就是两个 `high` 的最大值。

单点路径统一先计入 `n`。其余路径只统计编号较小的端点 `x` 和较大的端点 `y`，即 `x<y`。

#### 2. 将合法性拆成可以扫描的条件

对于 `x<y`，需要同时满足

$$low_x\ge x-k_1,\quad low_y\ge x-k_1,$$

$$high_x\le y+k_2,\quad high_y\le y+k_2.$$

其中第一项只与 `x` 有关，最后一项只与 `y` 有关。因此先筛出两个候选集合：

- 左端点集合 `A`：满足 `low[x] >= x-k1` 的点；
- 右端点集合 `B`：满足 `high[y] <= y+k2` 的点。

剩余条件可以写成

$$high_x\le y+k_2,\qquad x\le\min(y-1,low_y+k_1).$$

把 `A` 按 `high[x]` 排序，把 `B` 按编号 `y` 排序。 扫描 `y` 时，逐步加入所有 `high[x] <= y+k2` 的左端点，然后查询编号不超过 `min(y-1,low[y]+k1)` 的已加入点数。 这是一个插入加前缀计数问题，可以用树状数组处理。

#### 3. 保证两个端点来自不同分支

最直接的办法是“统计当前连通块的全部点对，再减去各个分支内部的点对”。同分支点对在加减两次统计中使用相同的 `low/high` 条件，因此会抵消；它们的真实路径交给后面的分治层处理。

树的链形和平衡形结构中，很多重心只有两三个分支。此时可以直接统计互不相交的分支组，减少重复工作：

- 只有两个分支时，只统计这两个分支之间的点对。
- 有三个分支时，设最大的分支为 `L`，其余为 `S,T`，先统计 `L` 与 `S∪T`，再统计 `S` 与 `T`。
- 分支更多时，继续使用全部点对减各分支内部点对。

统计两组之间的点对时，分别做“第一组提供较小端点”和“第二组提供较小端点”两次扫描。因为仍要求 `x<y`，不会重复计数。低度重心自己作为端点的路径直接扫描一次 `low/high` 判定即可。

#### 4. 让前缀计数适应 50 万点规模

**用 64 位整数记录块内成员**

编号互不相同，每个点在一次统计中最多插入一次。 因此可以把每 64 个编号放在一个 `uint64_t` 中，用某一位是否为一表示该编号是否已加入。 树状数组只维护每个完整块的点数。

查询前 `r` 个编号时，先查询前 `r/64` 个完整块的总数量，再对下一个块中前 `r%64` 位使用 `popcount`。 树状数组的长度由 `n` 缩小到 `ceil(n/64)`，既减少更新步数，也使计数数组更容易留在缓存中。

**提前回答所有左端点都满足阈值的查询**

设 `H=max(high[x])`，其中 `x∈A`。 当一个右端点满足 `y+k2>=H` 时，它对 `high[x]` 的要求已经对所有 `A` 成立，只剩编号上界。 可以为整个 `A` 建立静态位图和块前缀和，直接回答这类查询，无须排序和动态插入。

代码仅在这类查询足够多时建立完整块前缀和，将建表开销摊到这些查询上。回答后，把它们从动态扫描中移除；对剩下的查询，不可能达到其最大 `high` 阈值的左候选也可以删除。

**保留简单的局部优化**

候选集合为空时直接返回；较小的一侧不超过 24 个点时直接枚举。 大数组的排序键都在 `1..500000`，可以用两趟 10 位基数排序；小数组使用普通排序。

相邻查询若插入数量和查询上界都未改变，复用上一次计数。统计完成后，整批清零用到的位图块和树状数组单元。

#### 5. 连通块可以整体确定合法时提前结束

设当前连通块内最小、最大编号为 `L,R`。对任何两个不同端点 `x<y`，都有

$$x\le R-1,\qquad y\ge L+1.$$

如果 `k1,k2` 都至少为 `R-L-1`，那么

$$x-k_1\le L,\qquad y+k_2\ge R.$$

整个连通块的编号都在允许区间内，任意路径都合法。若块大小为 `s`，直接加入 `s(s-1)/2` 条非单点路径即可，无须继续分治。单点贡献已经包含在最开始的 `n` 中。

这是由编号范围推出的充分条件；不满足它时，仍运行一般算法。

#### 6. 存储顺序与复杂度

随机编号的树会让多次遍历产生大量分散的内存访问。代码先按 DFS 顺序重新安排内部存储下标，再以连续数组存放每个点的邻居。 `lab[u]` 始终保存题目给定的原编号，所有 `low/high`、端点大小关系和答案计算都使用原编号；内部下标只服务于遍历。

重心查找与路径信息收集使用显式数组，避免长链造成递归栈溢出，并复用计数与排序缓冲区。

一般情况下，每层点分治的离线计数为 `O(n log n)`，总时间为 `O(n log² n)`，空间为 `O(n)`。 静态前缀统计、低度重心的直接跨组计数和整块判定都不会增加这个复杂度。

每条路径只在首次经过所选重心的一层被统计一次，计数公式逐项对应合法性条件，因此算法正确。

原版的大规模回归配置见 [原回归报告](../tests/range_path-report.json)。本次重构验证单独记录于 [VALIDATION.md](../tests/202112/VALIDATION.md)，不将原评测记录当作新提交结果。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uint64_t ull;
const int B=1024;
struct node{
    int id,low,high;
};
struct counter{
    int n,k1,k2;
    int m;
    vector<int>bit;
    vector<ull>vis,full;
    vector<int>pre;
    vector<node>a,b,tmp;
    void radix(vector<node> &v,bool high){
        if(v.size()<2048){
            if(high){
                sort(v.begin(),v.end(),[](const node &x,const node &y){
                    return x.high<y.high;
                });
            }
            else{
                sort(v.begin(),v.end(),[](const node &x,const node &y){
                    return x.id<y.id;
                });
            }
            return;
        }
        tmp.resize(v.size());
        for(int b:{0,10}){
            array<int,B>cnt;
            cnt.fill(0);
            for(const node &x:v){
                ++cnt[((high?x.high:x.id)>>b)&1023];
            }
            int sum=0;
            for(int &val:cnt){
                int sz=val;
                val=sum;
                sum+=sz;
            }
            for(const node &x:v){
                tmp[cnt[((high?x.high:x.id)>>b)&1023]++]=x;
            }
            v.swap(tmp);
        }
    }
    ll sweep(){
        if(a.empty() || b.empty())return 0;
        ll ans=0;
        if(min(a.size(),b.size())<=24){
            for(const node &x:a){
                for(const node &y:b){
                    if(x.id<y.id && x.high<=y.id+k2 && x.id<=y.low+k1)++ans;
                }
            }
            return ans;
        }
        int mx=0,mn=n+1;
        for(const node &x:a){
            mx=max(mx,x.high);
            mn=min(mn,x.high);
        }
        int cnt=0;
        for(const node &y:b){
            cnt+=(y.id+k2>=mx);
        }
        if(cnt>=max(32,m/8)){
            for(const node &x:a){
                full[(x.id-1)>>6]|=ull(1)<<((x.id-1)&63);
            }
            pre[0]=0;
            for(int i=0;i<m;++i){
                pre[i+1]=pre[i]+__builtin_popcountll(full[i]);
            }
            size_t len=0;
            int lim=0;
            for(const node &y:b){
                if(y.id+k2>=mx){
                    int lim=min(y.id-1,y.low+k1);
                    int idx=lim>>6;
                    ull S=(ull(1)<<(lim&63))-1;
                    ans+=pre[idx]+__builtin_popcountll(full[idx]&S);
                }
                else{
                    b[len++]=y;
                    lim=max(lim,y.id+k2);
                }
            }
            b.resize(len);
            for(const node &x:a){
                full[(x.id-1)>>6]=0;
            }
            if(b.empty())return ans;
            len=0;
            mn=n+1;
            mx=0;
            for(const node &x:a){
                if(x.high<=lim){
                    a[len++]=x;
                    mn=min(mn,x.high);
                    mx=max(mx,x.high);
                }
            }
            a.resize(len);
            if(a.empty())return ans;
            if(min(a.size(),b.size())<=24){
                for(const node &x:a){
                    for(const node &y:b){
                        if(x.id<y.id && x.high<=y.id+k2 && x.id<=y.low+k1)++ans;
                    }
                }
                return ans;
            }
        }
        if(mn!=mx)radix(a,true);
        radix(b,false);
        size_t num=0;
        int last=-1,done=-1,res=0;
        for(const node &y:b){
            int lim=min(y.id-1,y.low+k1);
            int full=lim>>6,rem=lim&63;
            while(num<a.size() && a[num].high<=y.id+k2){
                int lab=a[num++].id-1;
                int idx=lab>>6;
                vis[idx]|=ull(1)<<(lab&63);
                for(int x=idx+1;x<=m;x+=x&-x){
                    ++bit[x];
                }
            }
            if(last!=lim || done!=int(num)){
                res=__builtin_popcountll(vis[full]&((ull(1)<<rem)-1));
                for(int x=full;x>0;x-=x&-x){
                    res+=bit[x];
                }
                last=lim;
                done=int(num);
            }
            ans+=res;
        }
        for(size_t i=0;i<num;++i){
            int idx=(a[i].id-1)>>6;
            if(!vis[idx])continue;
            vis[idx]=0;
            for(int x=idx+1;x<=m && bit[x];x+=x&-x){
                bit[x]=0;
            }
        }
        return ans;
    }
    counter(int x,int y,int z):n(x),k1(y),k2(z),
        m((n+63)/64),bit(m+1),vis(m+1),
        full(m+1),pre(m+1){
        a.reserve(n);
        b.reserve(n);
        tmp.reserve(n);
    }
    ll calc(const node*v,int sz){
        if(sz<2)return 0;
        a.clear();
        b.clear();
        for(int i=0;i<sz;++i){
            node x=v[i];
            if(x.low>=x.id-k1)a.push_back(x);
            if(x.high<=x.id+k2)b.push_back(x);
        }
        return sweep();
    }
    ll cross(const node*left,int nl,const node*right,int nr){
        a.clear();
        b.clear();
        for(int i=0;i<nl;++i){
            if(left[i].low>=left[i].id-k1)a.push_back(left[i]);
        }
        for(int i=0;i<nr;++i){
            if(right[i].high<=right[i].id+k2)b.push_back(right[i]);
        }
        return sweep();
    }
    ll both(const node*left,int nl,const node*right,int nr){
        return cross(left,nl,right,nr)+cross(right,nr,left,nl);
    }
};
int n,k1,k2;
vector<int>head,g,lab;
void build(){
    head.resize(n+2);
    g.resize(2*(n-1));
    vector<pair<int,int>>edges(n-1);
    for(auto &e:edges){
        scanf("%d%d",&e.first,&e.second);
        ++head[e.first];
        ++head[e.second];
    }
    int tot=0;
    for(int i=1;i<=n+1;++i){
        int degree=head[i];
        head[i]=tot;
        tot+=degree;
    }
    vector<int>cur=head;
    for(const auto &e:edges){
        g[cur[e.first]++]=e.second;
        g[cur[e.second]++]=e.first;
    }
}
void relabel(){
    lab.resize(n+1);
    vector<int>id(n+1),st{1};
    id[1]=-1;
    int tot=0;
    while(!st.empty()){
        int u=st.back();
        st.pop_back();
        id[u]=++tot;
        lab[tot]=u;
        for(int e=head[u];e<head[u+1];++e){
            int v=g[e];
            if(!id[v]){
                id[v]=-1;
                st.push_back(v);
            }
        }
    }
    vector<int>nh(n+2),ng(g.size());
    int cnt=0;
    for(int u=1;u<=n;++u){
        nh[u]=cnt;
        for(int e=head[lab[u]];e<head[lab[u]+1];++e){
            ng[cnt++]=id[g[e]];
        }
    }
    nh[n+1]=cnt;
    head.swap(nh);
    g.swap(ng);
}
int main(){
    scanf("%d%d%d",&n,&k1,&k2);
    build();
    if(k1>=n-1 && k2>=n-1){
        printf("%lld\n",1LL*n*(n+1)/2);
        return 0;
    }
    relabel();
    counter c(n,k1,k2);
    vector<int>fa(n+1),sz(n+1),big(n+1),ord,q{1};
    vector<unsigned char>del(n+1);
    vector<node>all;
    vector<pair<int,int>>br;
    ord.reserve(n);
    all.reserve(n);
    q.reserve(n);
    ll ans=n;
    while(!q.empty()){
        int start=q.back();
        q.pop_back();
        ord.clear();
        ord.push_back(start);
        fa[start]=0;
        int lo=n+1,hi=0;
        for(size_t i=0;i<ord.size();++i){
            int u=ord[i];
            lo=min(lo,lab[u]);
            hi=max(hi,lab[u]);
            sz[u]=1;
            big[u]=0;
            for(int e=head[u];e<head[u+1];++e){
                int v=g[e];
                if(!del[v] && v!=fa[u]){
                    fa[v]=u;
                    ord.push_back(v);
                }
            }
        }
        int sum=int(ord.size()),rt=start;
        if(min(k1,k2)>=hi-lo-1){
            ans+=1LL*sum*(sum-1)/2;
            continue;
        }
        for(int i=sum-1;i>=0;--i){
            int u=ord[i],p=fa[u];
            if(max(big[u],sum-sz[u])<=sum/2)rt=u;
            if(p){
                sz[p]+=sz[u];
                big[p]=max(big[p],sz[u]);
            }
        }
        br.clear();
        for(int e=head[rt];e<head[rt+1];++e){
            int v=g[e];
            if(!del[v])br.push_back({fa[v]==rt?sz[v]:sum-sz[rt],v});
        }
        if(br.size()<=3){
            sort(br.begin(),br.end(),[](const pair<int,int> &x,const pair<int,int> &y){
                return x.first>y.first;
            });
        }
        int val=lab[rt];
        all.clear();
        all.push_back({val,val,val});
        ord.clear();
        ord.push_back(rt);
        for(const auto &x:br){
            int v=x.second;
            int start=int(all.size());
            fa[v]=rt;
            ord.push_back(v);
            all.push_back({lab[v],min(lab[v],val),max(lab[v],val)});
            for(size_t i=start;i<all.size();++i){
                node x=all[i];
                int u=ord[i];
                for(int f=head[u];f<head[u+1];++f){
                    int v=g[f];
                    if(!del[v] && v!=fa[u]){
                        fa[v]=u;
                        ord.push_back(v);
                        all.push_back({lab[v],min(x.low,lab[v]),max(x.high,lab[v])});
                    }
                }
            }
            if(br.size()>3)ans-=c.calc(all.data()+start,int(all.size())-start);
        }
        if(br.size()<=3){
            for(size_t i=1;i<all.size();++i){
                const node &v=all[i];
                if(v.low>=min(val,v.id)-k1 && v.high<=max(val,v.id)+k2)++ans;
            }
            if(br.size()>=2){
                int first=br[0].first;
                ans+=c.both(all.data()+1,first,all.data()+first+1,sum-first-1);
            }
            if(br.size()==3){
                int first=br[0].first,second=br[1].first;
                ans+=c.both(all.data()+first+1,second,
                            all.data()+first+second+1,br[2].first);
            }
        }
        else{
            ans+=c.calc(all.data(),int(all.size()));
        }
        del[rt]=1;
        for(int e=head[rt];e<head[rt+1];++e){
            if(!del[g[e]])q.push_back(g[e]);
        }
    }
    printf("%lld\n",ans);
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202112/VALIDATION.md)
- [details.txt](../tests/202112/details.txt)
- [name-followup-before.json](../tests/202112/name-followup-before.json)
- [name-followup-report.json](../tests/202112/name-followup-report.json)
- [nightly-review-followup.json](../tests/202112/nightly-review-followup.json)
- [prose-final-review.json](../tests/202112/prose-final-review.json)
- [report.json](../tests/202112/report.json)
- [retained_oracles.py](../tests/202112/retained_oracles.py)
- [verify-name-followup.py](../tests/202112/verify-name-followup.py)
- [verify.py](../tests/202112/verify.py)

<!-- local-validation-attachments:end -->
