---
title: "CSP 202503 五题题解"
contest: "202503"
contest_month: "2025-03"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "枚举", "求和", "动态规划", "完全背包", "表达式解析", "记忆化搜索", "依赖图", "数论", "gcd", "状态压缩", "动态树", "Link-Cut Tree", "树形动态规划"]
status: "published"
problems: [{"id": "A", "title": "数值积分", "tags": ["枚举", "求和"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "当前重构版：C++17 编译通过，2 个保存用例、60 组独立对拍及 4 组边界/压力通过；UBSan 共 66 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b9a67df0b81749b958"}}, {"id": "B", "title": "机器人饲养指南", "tags": ["动态规划", "完全背包"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "当前重构版：C++17 编译通过，2 个保存用例、100 组独立对拍及 2 组边界/压力通过；UBSan 共 104 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7bba67df0b81749b972"}}, {"id": "C", "title": "模板展开", "tags": ["表达式解析", "记忆化搜索", "依赖图"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "当前重构版：C++17 编译通过，2 个保存用例、100 组独立对拍及 1 组边界/压力通过；UBSan 共 103 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7bda67df0b81749b97b"}}, {"id": "D", "title": "集体锻炼", "tags": ["数论", "gcd", "状态压缩"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "当前重构版：C++17 编译通过，2 个保存用例、130 组独立对拍及 1 组边界/压力通过；UBSan 共 133 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7bea67df0b81749b983"}}, {"id": "E", "title": "收费标准评估", "tags": ["动态树", "Link-Cut Tree", "树形动态规划"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "当前重构版：LinkCutTree 模板整理后，C++17 O2 与 UBSan 各324组通过（320独立对拍、1保存、1边界、2压力），无编译警告；尚未重新提交在线评测，oj字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202503E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202503E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c0a67df0b81749b987"}}]
---

# CSP 202503 五题题解

[原页面](https://code92007.github.io/csp/#/contest/202503) · [验证记录](../tests/202503/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 数值积分

标签：`枚举` · `求和`

本地：66 组优化版、66 组 UBSan 验证通过，详见 [验证记录](../tests/202503/VALIDATION.md)。

### 题意

给定二次函数 $f(x)=x^2+bx+c$，将闭区间 $[l,r]$ 内所有偶数处的函数值相加，再乘以 2。

输入一行 `b c l r`。保证 $0\le l<l+2\le r\le1000$、$-20\le b,c\le20$。

输出按上述规则计算的整数结果。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503A)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503A/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7b9a67df0b81749b958)（accepted，100 分；复刻评测）。

### 题解

**枚举偶数坐标**

若 $l$ 为奇数，先将它加一。之后每次加 2，累加 $2(x^2+bx+c)$，直到超过 $r$。右端点若为偶数也应计入。

**正确性**

枚举恰好覆盖闭区间内的全部偶数，且每个坐标只出现一次，逐项累加正好得到题目要求的和。

**复杂度**

时间复杂度 $O(r-l+1)$，额外空间复杂度 $O(1)$。代码使用 `ll` 保存结果。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b,c,l,r,ans;
int main(){
    scanf("%lld%lld%lld%lld",&b,&c,&l,&r);
    if(l%2)++l;
    for(ll x=l;x<=r;x+=2){
        ans+=2*(x*x+b*x+c);
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 机器人饲养指南

标签：`动态规划` · `完全背包`

本地：104 组优化版、104 组 UBSan 验证通过，详见 [验证记录](../tests/202503/VALIDATION.md)。

### 题意

有 $n$ 个苹果，每天可以投喂 1 到 $m$ 个，投喂 $i$ 个获得快乐值 $A_i$。天数不限，求喂完全部苹果的最大总快乐值。

输入 `n m` 和 $A_1,\ldots,A_m$。保证 $1\le n\le10^4$、$1\le m\le100$、$0\le A_i\le10^5$，收益不保证单调。

输出最大总快乐值。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503B)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503B/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7bba67df0b81749b972)（accepted，100 分；复刻评测）。

### 题解

**枚举最后一天**

设 $dp[x]$ 为恰好喂掉 $x$ 个苹果的最大快乐值，初态为 $dp[0]=0$。若最后一天喂 $i$ 个，则

$$dp[x]=\max_{1\le i\le\min(m,x)}\{dp[x-i]+A_i\}.$$

按 $x$ 从小到大计算，答案就是 $dp[n]$。不能只按 $A_i/i$ 贪心，剩余苹果可能使最高比例的组合不合适。

**正确性**

任意方案删去最后一天后，都得到一个规模更小的合法方案；该前缀若不是最优，可以替换成最优前缀。转移枚举了最后一天的所有投喂量，因此覆盖全部方案并保持最优。

**复杂度**

时间复杂度 $O(nm)$，空间复杂度 $O(n+m)$。收益使用 `ll`。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10010,M=110;
int n,m;
ll a[M],dp[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m && j<=i;++j){
            dp[i]=max(dp[i],dp[i-j]+a[j]);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
```

<a id="problem-c"></a>

## C. 模板展开

标签：`表达式解析` · `记忆化搜索` · `依赖图`

本地：103 组优化版、103 组 UBSan 验证通过，详见 [验证记录](../tests/202503/VALIDATION.md)。

### 题意

变量初始都是空串，表达式由字面量和 `$变量名` 拼接而成。直接赋值保存当时的结果，间接赋值保存表达式，后续使用时随当前变量值重新计算。

输入语句数 $n$，随后每行一条语句。保证 $n\le2000$、变量至多 1000 个，每个表达式至多 100 项，变量名和字面量长度不超过 50，动态依赖始终无环。

- `1 var expr`：立即计算 `expr`，将结果赋给 `var`。
- `2 var expr`：将 `var` 与动态表达式 `expr` 关联。
- `3 var`：查询 `var` 当前值的长度。

对每条查询输出长度模 $10^9+7$ 的结果。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503C)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503C/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7bda67df0b81749b97b)（accepted，100 分；复刻评测）。

### 题解

**把字符串拼接改成长度相加**

题目只询问长度，不必构造可能指数增长的字符串。字面量记录长度，变量引用记录编号；每个变量保存固定长度，或一组动态操作数。

直接赋值时先计算完整右侧，再覆盖左侧。例如 `1 a $a $a` 应使用 `a` 的旧值，不能提前清空它。

**按语句编号记忆化**

动态变量递归计算依赖，再将各项长度相加取模。同一条语句执行期间，依赖变量不会变化，可以缓存结果。

用 `now` 表示当前语句编号，`ed[u]` 记录变量 $u$ 的缓存所属语句。执行下一条语句后，旧缓存自动失效，动态变量便能反映新的赋值。

**正确性**

依赖无环，递归一定终止。按依赖顺序计算时，长度之和与真实字符串拼接长度一致；取模与加法兼容。

直接赋值冻结当时的结果，间接赋值保留引用，分别符合两种赋值语义。同语句缓存只复用未变化的值，不影响结果。

**复杂度**

设变量数为 $V$，当前全部表达式的项数为 $E$。单次求值至多处理每个变量及其表达式一次，总时间 $O(n(V+E))$，空间 $O(V+E)$，另计输入文本的读取长度。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1005,mod=1e9+7;
int n,tot,now,ed[N];
ll dp[N];
struct node{
    bool op;
    ll val;
    vector<P>g;
}a[N];
unordered_map<string,int>mp;
string read(){
    string s;
    int c;
    while((c=getchar())!='\n' && c!=EOF){
        s+=(char)c;
    }
    return s;
}
int id(const string &s){
    auto it=mp.find(s);
    if(it!=mp.end())return it->second;
    return mp[s]=++tot;
}
ll eval(int u){
    if(ed[u]==now)return dp[u];
    ll val=a[u].val;
    if(a[u].op){
        val=0;
        for(P &x:a[u].g){
            ll v=x.first?eval(x.second):x.second;
            val=(val+v)%mod;
        }
    }
    ed[u]=now;
    return dp[u]=val;
}
int main(){
    scanf("%d",&n);
    read();
    while(n--){
        ++now;
        istringstream in(read());
        int op;
        string s;
        in>>op>>s;
        int u=id(s);
        if(op==3){
            printf("%lld\n",eval(u));
            continue;
        }
        vector<P>g;
        while(in>>s){
            if(s[0]=='$')g.push_back(P(1,id(s.substr(1))));
            else g.push_back(P(0,s.size()));
        }
        if(op==1){
            ll val=0;
            for(P &x:g){
                ll v=x.first?eval(x.second):x.second;
                val=(val+v)%mod;
            }
            a[u].op=0;
            a[u].val=val;
            a[u].g.clear();
        }
        else{
            a[u].op=1;
            a[u].g.swap(g);
        }
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 集体锻炼

标签：`数论` · `gcd` · `状态压缩`

本地：133 组优化版、133 组 UBSan 验证通过，详见 [验证记录](../tests/202503/VALIDATION.md)。

### 题意

给定正整数数组，求所有非空连续区间的 $l\times r\times\gcd(a_l,\ldots,a_r)$ 之和。

输入 $n$ 和 $n$ 个数组元素，下标从 1 开始。保证 $1\le n,a_i\le10^6$。

输出答案模 $998244353$ 的结果。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503D)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503D/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7bea67df0b81749b983)（accepted，100 分；复刻评测）。

### 题解

**固定右端点，合并相同 gcd**

处理右端点 $r$ 时，用状态 $(g,s)$ 表示若干以 $r$ 结尾、gcd 均为 $g$ 的区间，其中 $s$ 为这些区间左端点下标之和。

加入 $a_r$ 后，先产生单点状态 $(a_r,r)$。旧状态 $(g,s)$ 延伸后变成 $(\gcd(g,a_r),s)$；相邻状态的 gcd 相同，就将下标之和相加。每组对答案的贡献为 $rgs$。

**为什么状态数很少**

从短区间向长区间看，gcd 只能变为原数的约数；每次严格减小至少减半，所以不同 gcd 至多有 $O(\log A)$ 个，其中 $A=\max a_i$。

相邻分组延伸后仍保持整除顺序，相同 gcd 会连续出现，只合并相邻项就足够。

**正确性**

以 $r$ 结尾的区间，要么是单点区间，要么唯一地由以 $r-1$ 结尾的区间延伸得到。转移无重无漏，合并只把相同 gcd 的贡献相加，不改变总和。再按右端点累加，即得到全部区间的答案。

**复杂度**

状态转移次数为 $O(n\log A)$，空间复杂度 $O(\log A)$。若计入欧几里得算法的复杂度，保守时间上界为 $O(n\log^2 A)$。下标之和及乘积用 `ll`，连续乘法之间取模。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int mod=998244353;
int n;
ll ans;
vector<P>g,h;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        h.clear();
        h.push_back(P(x,i));
        for(auto &[v,sum]:g){
            int d=gcd(v,x);
            P &w=h.back();
            if(w.first==d){
                w.second=(w.second+sum)%mod;
            }
            else h.push_back(P(d,sum));
        }
        g.swap(h);
        for(auto &[v,sum]:g){
            ans=(ans+sum*i%mod*v)%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-e"></a>

## E. 收费标准评估

标签：`动态树` · `Link-Cut Tree` · `树形动态规划`

本地：324 组优化版、324 组 UBSan 验证通过，详见 [验证记录](../tests/202503/VALIDATION.md)。

### 题意

有一棵带正负点权的树，初始根为 1。基本费用是包含当前根的非空连通子图最大权和；还需要查询指定子树内任意非空连通子图的最大权和。

输入 `n m`、各点权值、$n-1$ 条边和 $m$ 次操作。保证 $n,m\le10^5$，点权绝对值不超过 $10^9$。

- `1 u`：查询当前根意义下，$u$ 子树内的最大权和。
- `2 u x`：将 $u$ 的点权改为 $x$。
- `3 u`：将当前根改为 $u$。
- `4 a b c d`：删去边 $a-b$，加入边 $c-d$，保证操作后仍为树。

先输出初始基本费用。此后每次操作输出一行：操作 1 输出子树查询结果，其他操作输出更新后的基本费用。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202503E)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202503E/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7c0a67df0b81749b987)（accepted，100 分；复刻评测）。

### 题解

**先写出静态树形 DP**

令 $F_u$ 表示子树内必须包含 $u$ 的最大权和，$G_u$ 表示子树内任意非空连通子图的最大权和，则

$$F_u=a_u+\sum_v\max(0,F_v),\qquad G_u=\max(F_u,\max_vG_v).$$

负贡献的孩子可以不接入，但子图必须非空，不能将所有答案初始化为零。

**用四项信息合并实链**

Link-Cut Tree 将孩子分为实孩子和虚孩子。虚孩子的 $\max(0,F_v)$ 用总和维护，$G_v$ 用可删除的 `multiset` 维护。

设虚孩子的正贡献和为 $s$、最大 $G$ 为 $b$。当前点的有效权值为 $a_u+s$，局部最优还可能完全落在某个虚子树中，因此要同时考虑 $b$。

每段实链维护 `sum,l,r,ans`：整段有效权和、必须接触左端的最优值、必须接触右端的最优值，以及内部任意最优值。相邻链段 $A,B$ 合并为

$$\begin{aligned}
C.sum&=A.sum+B.sum,\\
C.l&=\max(A.l,A.sum+B.l),\\
C.r&=\max(B.r,B.sum+A.r),\\
C.ans&=\max(A.ans,B.ans,A.r+B.l).
\end{aligned}$$

最后一项对应连通子图跨过两段交界。链翻转时交换左右最优值即可。

**维护实虚切换与查询**

`access` 将旧实孩子改为虚孩子时，加入它的正贡献和最优值；将新实孩子从虚集合中移除时，做相反操作。修改点权前先 `access`，保证祖先记录的旧贡献已正确调整。

先换根到当前根，再 `access(u)`，此时 $u$ 左侧的实链是祖先，$u$ 自身及虚子树正好对应所需子树。于是子树答案为 `local(u).ans`，基本费用为 `local(root).l`。断边、连边沿用标准动态树操作，并同步虚贡献。

**正确性**

静态 DP 正确描述了选取连通子图的两种情况。链段合并枚举最优子图位于左段、右段或跨越交界的所有可能，实虚切换保持每个孩子的贡献恰好记录一次。

因此所有节点信息始终对应当前树。查询时剥离祖先实链，只读取本点及虚子树信息，得到题目要求的结果。

**复杂度**

建立动态树耗时 $O(n\log^2 n)$，每次操作均摊 $O(\log^2 n)$，空间复杂度 $O(n)$。权和使用 `ll`。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=2;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m,root=1;
struct info{
    ll sum=0,l=-INF,r=-INF,ans=-INF;
};
info merge(info a,info b){
    info c;
    c.sum=a.sum+b.sum;
    c.l=max(a.l,a.sum+b.l);
    c.r=max(b.r,b.sum+a.r);
    c.ans=max({a.ans,b.ans,a.r+b.l});
    return c;
}
struct LinkCutTree{
    bool rev[N];
    int fa[N],ch[N][M],st[N];
    ll val[N],sum[N];
    info mx[N];
    multiset<ll>g[N];
    #define ls(x) (ch[x][0])
    #define rs(x) (ch[x][1])
    #define dir(x) (rs(fa[x])==(x))
    #define isRoot(x) (ls(fa[x])!=(x) && rs(fa[x])!=(x))
    info local(int x){
        ll w=val[x]+sum[x];
        ll best=g[x].empty()?-INF:*g[x].rbegin();
        return {w,w,w,max(w,best)};
    }
    void pushup(int x){
        mx[x]=merge(merge(mx[ls(x)],local(x)),mx[rs(x)]);
    }
    void flip(int x){
        if(!x)return;
        swap(ls(x),rs(x));
        swap(mx[x].l,mx[x].r);
        rev[x]^=1;
    }
    void pushdown(int x){
        if(!rev[x])return;
        flip(ls(x));flip(rs(x));
        rev[x]=0;
    }
    void update(int x){
        int cnt=0,y=x;
        st[++cnt]=y;
        while(!isRoot(y)){
            y=fa[y];
            st[++cnt]=y;
        }
        while(cnt){
            pushdown(st[cnt--]);
        }
    }
    void rotate(int x){
        int y=fa[x],z=fa[y],d=dir(x);
        int w=ch[x][d^1];
        if(!isRoot(y))ch[z][dir(y)]=x;
        fa[x]=z;
        ch[x][d^1]=y;fa[y]=x;
        ch[y][d]=w;
        if(w)fa[w]=y;
        pushup(y);pushup(x);
    }
    void splay(int x){
        update(x);
        while(!isRoot(x)){
            int y=fa[x];
            if(!isRoot(y))rotate(dir(x)==dir(y)?y:x);
            rotate(x);
        }
    }
    void add(int x,int y){
        if(!y)return;
        sum[x]+=max(0ll,mx[y].l);
        g[x].insert(mx[y].ans);
    }
    void del(int x,int y){
        if(!y)return;
        sum[x]-=max(0ll,mx[y].l);
        auto it=g[x].find(mx[y].ans);
        g[x].erase(it);
    }
    void access(int x){
        int y=0,u=x;
        while(u){
            splay(u);
            add(u,rs(u));
            del(u,y);
            rs(u)=y;
            pushup(u);
            y=u;u=fa[u];
        }
        splay(x);
    }
    void makeroot(int x){
        access(x);
        flip(x);
    }
    int findroot(int x){
        access(x);
        pushdown(x);
        while(ls(x)){
            x=ls(x);
            pushdown(x);
        }
        splay(x);
        return x;
    }
    void split(int x,int y){
        makeroot(x);
        access(y);
    }
    void link(int x,int y){
        makeroot(x);
        if(findroot(y)==x)return;
        access(y);
        fa[x]=y;
        add(y,x);
        pushup(y);
    }
    void cut(int x,int y){
        split(x,y);
        if(ls(y)==x && !rs(x)){
            ls(y)=0;fa[x]=0;
            pushup(y);
        }
    }
    void setval(int x,ll w){
        access(x);
        val[x]=w;
        pushup(x);
    }
    ll best(int x){
        makeroot(x);
        access(x);
        return local(x).l;
    }
    ll query(int x){
        makeroot(root);
        access(x);
        return local(x).ans;
    }
}tr;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&tr.val[i]);
        tr.pushup(i);
    }
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        tr.link(u,v);
    }
    printf("%lld\n",tr.best(root));
    while(m--){
        int op,u;
        scanf("%d%d",&op,&u);
        if(op==1){
            printf("%lld\n",tr.query(u));
            continue;
        }
        if(op==2){
            ll x;
            scanf("%lld",&x);
            tr.setval(u,x);
        }
        if(op==3)root=u;
        if(op==4){
            int v,c,d;
            scanf("%d%d%d",&v,&c,&d);
            tr.cut(u,v);
            tr.link(c,d);
        }
        printf("%lld\n",tr.best(root));
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202503/VALIDATION.md)
- [cases.json](../tests/202503/cases.json)
- [compile.json](../tests/202503/compile.json)
- [constants-followup.json](../tests/202503/constants-followup.json)
- [current-sources.json](../tests/202503/current-sources.json)
- [extra.py](../tests/202503/extra.py)
- [lct-cases.json](../tests/202503/lct-cases.json)
- [lct-followup.json](../tests/202503/lct-followup.json)
- [lct-followup.py](../tests/202503/lct-followup.py)
- [naming-followup.json](../tests/202503/naming-followup.json)
- [style-followup.json](../tests/202503/style-followup.json)
- [style-followup.py](../tests/202503/style-followup.py)
- [summary.json](../tests/202503/summary.json)

<!-- local-validation-attachments:end -->
