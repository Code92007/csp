---
title: "CSP 202006 五题题解"
contest: "202006"
contest_month: "2020-06"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "直线两侧", "符号判断", "双指针", "稀疏向量", "状态机", "字符串", "模拟", "KMP", "矩阵快速幂", "递推", "最大权闭合子图", "最小割", "二次函数"]
status: "published"
problems: [{"id": "A", "title": "线性分类器", "tags": ["直线两侧", "符号判断"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adceb1574ace1cba9a1bce6"}}, {"id": "B", "title": "稀疏向量", "tags": ["双指针", "稀疏向量"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adceb1774ace1cba9a1bd0b"}}, {"id": "C", "title": "Markdown 渲染器", "tags": ["状态机", "字符串", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add98d374ace1cba9a1f2eb"}}, {"id": "D", "title": "1246", "tags": ["字符串", "KMP", "矩阵快速幂", "递推"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9c1c74ace1cba9a1f614"}}, {"id": "E", "title": "乔乔和牛牛逛超市", "tags": ["最大权闭合子图", "最小割", "二次函数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202006E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202006E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9cb974ace1cba9a1f6a9"}}]
---

# CSP 202006 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202006/VALIDATION.md)

<a id="problem-a"></a>

## A. 线性分类器

标签：`直线两侧` · `符号判断`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adceb1574ace1cba9a1bce6)。重构版本地验证见 [VALIDATION.md](../tests/202006/VALIDATION.md)，未重新提交在线评测。

### 题意

给定带有 `A/B` 标签的平面点。对每条直线 $\theta_0+\theta_1x+\theta_2y=0$，判断两类点是否分别完全位于直线的不同侧。

输入点数 $n$、直线数 $m$，再输入每个点的坐标与标签，以及每条直线的三个系数。两类点均存在，保证没有点恰好落在线上。

每条直线输出 `Yes` 或 `No`。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006A) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006A/)。

### 题解

代入直线方程，正负号决定所在半平面。将 B 类点的符号反转后，检查所有点的符号是否一致；一致意味着 A 在同侧、B 恰在另一侧。

这个变换同时检验类内一致与类间相反，无需求斜率，也自然支持竖直线。时间 $O(nm)$，空间 $O(n)$；乘法使用 64 位整数，避免溢出改变符号。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll x,y;
    char c;
};
int n,m;
vector<node> p;
int main(){
    scanf("%d%d",&n,&m);
    p.resize(n);
    for(auto &v:p){
        scanf("%lld%lld %c",&v.x,&v.y,&v.c);
    }
    while(m--){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        int last=0;
        bool ok=true;
        for(auto &v:p){
            ll val=a+b*v.x+c*v.y;
            int s=val>0?1:-1;
            if(v.c=='B')s=-s;
            if(!val || (last && last!=s))ok=false;
            last=s;
        }
        puts(ok?"Yes":"No");
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 稀疏向量

标签：`双指针` · `稀疏向量`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adceb1774ace1cba9a1bd0b)。重构版本地验证见 [VALIDATION.md](../tests/202006/VALIDATION.md)，未重新提交在线评测。

### 题意

两个 $n$ 维稀疏向量只给出非零项，各自按下标递增排列，求它们的内积。

输入维数 $n$、两个向量的非零项数 $a,b$，再分别输入各项的下标和值。$n$ 可达 $10^9$，每个向量的非零项至多 $5\times10^5$。

输出内积，使用 64 位整数保存乘积和。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006B) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006B/)。

### 题解

用两个指针合并扫描非零项。下标相等时把值相乘累加，两指针都前移；下标不等时只移动较小的一边，因为另一向量已不可能在这个较小下标出现非零值。

内积只有双方同下标均非零才有贡献，扫描恰好计算所有此类项一次。时间 $O(a+b)$，空间 $O(a+b)$，与巨大维数 n 无关；累计值可能超出 32 位，使用 `long long`。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int n,a,b;
vector<P> u,v;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    u.resize(a);
    v.resize(b);
    for(auto &[i,x]:u){
        scanf("%d%lld",&i,&x);
    }
    for(auto &[i,x]:v){
        scanf("%d%lld",&i,&x);
    }
    int i=0,j=0;
    ll ans=0;
    while(i<a && j<b){
        if(u[i].first<v[j].first)++i;
        else if(u[i].first>v[j].first)++j;
        else{
            ans+=u[i].second*v[j].second;
            ++i;++j;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. Markdown 渲染器

标签：`状态机` · `字符串` · `模拟`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add98d374ace1cba9a1f2eb)。重构版本地验证见 [VALIDATION.md](../tests/202006/VALIDATION.md)，未重新提交在线评测。

### 题意

在宽度为 $w$ 的终端渲染简化 Markdown，计算占用行数。空白行分隔块，块之间显示一个空行，文档首尾不额外留空行。

输入宽度 $w$，再按原始行读取 Markdown 内容，输入可达 20 MiB。普通段落各行去首尾空格后，用一个空格连接；行内原有连续空格保留。

- `* ` 开头启动列表项，后续以两个空格开头的非空行可以接续当前项。
- 列表正文宽度为 $w-3$，每项至少占一行。
- 换行后，丢弃剩余文本开头连续的空格，再开始下一行。

输出渲染后的总行数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006C) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006C/)。

### 题解

用三种状态表示当前没有块、普通段落、列表。遇到空白行结算当前内容并结束块；遇到新列表项，若原本在列表中仅结算上一项，否则先结算旧块并开启列表；列表中的缩进行接到当前项，其余非空行开启或延续普通段落。

每行内容先去首尾空格，非空内容之间只加一个连接空格；行内原有多个空格必须保留。

计算行数时，从当前文本位置消耗 w 个字符（列表为 w-3），若还有内容则跳过接下来连续空格，再开始下一行。 空列表项仍占一行。

状态转移恰好对应各类块及接续规则；计数循环与逐字符渲染的换行位置一致。只在新块开始且已有旧块时加一个分隔行，避免文档首尾或连续空行多计。总时间 $O(L)$，空间 $O(L)$，L 为输入字符数。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w,state;
ll ans;
bool had;
string text;
string trim(const string &s){
    int l=s.find_first_not_of(' ');
    if(l==-1)return "";
    return s.substr(l,s.find_last_not_of(' ')-l+1);
}
ll calc(const string &s,int w){
    if(s.empty())return 1;
    ll ans=0;
    int p=0,len=s.size();
    while(p<len){
        ++ans;
        p+=w;
        while(p<len && s[p]==' '){
            ++p;
        }
    }
    return ans;
}
void flush(){
    if(state)ans+=calc(text,state==2?w-3:w);
    text.clear();
}
void start(int kind){
    if(had)++ans;
    had=true;
    state=kind;
}
void append(const string &s){
    string t=trim(s);
    if(t.empty())return;
    if(!text.empty())text+=' ';
    text+=t;
}
bool read(string &s){
    s.clear();
    int c=getchar();
    while(c!=EOF && c!='\n'){
        s+=char(c);
        c=getchar();
    }
    return c!=EOF || !s.empty();
}
int main(){
    scanf("%d",&w);
    string s;
    read(s);
    while(read(s)){
        bool blank=trim(s).empty();
        bool bullet=(s.size()>=2 && s[0]=='*' && s[1]==' ');
        bool indent=(s.size()>=2 && s[0]==' ' && s[1]==' ');
        if(blank){
            flush();
            state=0;
            continue;
        }
        if(bullet){
            if(state==2)flush();
            else{
                flush();
                start(2);
            }
            append(s.substr(2));
        }
        else if(state==2 && indent)append(s.substr(2));
        else{
            if(state!=1){
                flush();
                start(1);
            }
            append(s);
        }
    }
    flush();
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-d"></a>

## D. 1246

标签：`字符串` · `KMP` · `矩阵快速幂` · `递推`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9c1c74ace1cba9a1f614)。重构版本地验证见 [VALIDATION.md](../tests/202006/VALIDATION.md)，未重新提交在线评测。

### 题意

从字符串 `1` 开始，每秒同时执行替换：`1→2`、`2→4`、`4→16`、`6→64`。求第 $n$ 秒得到的字符串中，模式串 $S$ 出现了多少次，允许重叠。

输入秒数 $n$ 和模式串 $S$，$n\le10^9$，$|S|\le10^5$，模式串只包含这四种数字。

输出出现次数对 $998244353$ 取模的结果。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006D) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006D/)。

### 题解

**分别考虑四个单字符的展开**

记录每个字符展开后包含 S 的次数，以及最多 $|S|-1$ 长的前缀和后缀。 例如 4 下一轮展开为“1 的旧展开 + 6 的旧展开”，匹配次数等于两个子块内部次数，再加跨界次数。

跨界匹配只可能用到左块后缀与右块前缀；这两段都比 S 短，所以在它们的拼接上运行 KMP，找到的每一次匹配都确实跨界，不会重复计算内部匹配。

四种字符的次数递推为线性关系加跨界常数。加入一个恒为 1 的维度，便可写成 5×5 矩阵。难点在于跨界常数随轮数变化，不能一开始就对同一个矩阵快速幂。

**先等待截断边界进入周期**

首字符的替换具有长度 3 的循环，尾字符具有长度 2 的循环。 固定只保留有限长度的边界后，展开足够长时，相隔 6 轮的这些前后缀会相同：对每个循环相位，继续展开只向截断范围之外延长。

程序不猜预热轮数，而是实际比较当前八个边界字符串与 6 轮前是否完全相等。 边界更新是确定性的，一旦相等，此后的跨界常数就严格以 6 为周期。

将这六轮的矩阵按执行顺序相乘，再快速幂跳过完整周期，最后处理不足六轮的余数。矩阵乘法顺序不能反过来。模式长度为 1 时截断长度为 0，不存在跨界匹配，同一流程仍成立；`n=0` 直接保留初始计数。

出现次数被互斥划分为内部与跨界两类，KMP 统计精确；相同边界状态保证后续转移重复，所以矩阵跳转不改变结果。设预热轮数为 H（$O(\log(|S|+1))$），时间 $O(H|S|+5^3\log n)$，空间 $O(|S|+H)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4,M=5,K=1e5+10;
const ll mod=998244353;
typedef array<ll,M> V;
typedef array<V,M> A;
ll n;
int len,keep,fa[K];
char t[K],c[M]="1246";
string s;
vector<int> g[N]={{1},{2},{0,3},{3,2}};
A unit(){
    A a;
    memset(a.data(),0,sizeof a);
    for(int i=0;i<M;++i){
        a[i][i]=1;
    }
    return a;
}
A mul(const A &a,const A &b){
    A c;
    memset(c.data(),0,sizeof c);
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            for(int k=0;k<M;++k){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return c;
}
V calc(const A &a,const V &b){
    V c;
    memset(c.data(),0,sizeof c);
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            c[i]=(c[i]+a[i][j]*b[j])%mod;
        }
    }
    return c;
}
struct node{
    array<string,N> pre,suf;
    bool operator==(const node &b)const{
        return pre==b.pre && suf==b.suf;
    }
};
ll match(const string &t){
    ll ans=0;
    int j=0;
    for(const char &c:t){
        while(j && c!=s[j]){
            j=fa[j-1];
        }
        if(c==s[j])++j;
        if(j==len){
            ++ans;
            j=fa[j-1];
        }
    }
    return ans;
}
int main(){
    scanf("%lld%s",&n,t);
    s=t;
    len=s.size();
    keep=len-1;
    for(int i=1,j=0;i<len;++i){
        while(j && s[i]!=s[j]){
            j=fa[j-1];
        }
        if(s[i]==s[j])++j;
        fa[i]=j;
    }
    node state;
    V cnt;
    memset(cnt.data(),0,sizeof cnt);
    cnt[N]=1;
    for(int i=0;i<N;++i){
        if(keep)state.pre[i]=state.suf[i]=string(1,c[i]);
        cnt[i]=(s==string(1,c[i]));
    }
    deque<node> q;
    q.push_back(state);
    vector<A> tr;
    ll time=0;
    while(time<n){
        node next;
        A a;
        memset(a.data(),0,sizeof a);
        a[N][N]=1;
        for(int i=0;i<N;++i){
            for(int &j:g[i]){
                ++a[i][j];
                next.pre[i]+=state.pre[j];
                next.suf[i]+=state.suf[j];
            }
            if((int)next.pre[i].size()>keep)next.pre[i].resize(keep);
            if((int)next.suf[i].size()>keep){
                next.suf[i].erase(0,next.suf[i].size()-keep);
            }
            if(g[i].size()==2){
                a[i][N]=match(state.suf[g[i][0]]+state.pre[g[i][1]]);
            }
        }
        cnt=calc(a,cnt);
        state=std::move(next);
        tr.push_back(a);
        ++time;
        if(q.size()==6 && state==q.front()){
            ll rem=n-time;
            int pos=tr.size()-6;
            A a=unit();
            for(int j=pos;j<pos+6;++j){
                a=mul(tr[j],a);
            }
            ll k=rem/6;
            while(k){
                if(k&1)cnt=calc(a,cnt);
                a=mul(a,a);
                k>>=1;
            }
            for(int j=0;j<rem%6;++j){
                cnt=calc(tr[pos+j],cnt);
            }
            break;
        }
        q.push_back(state);
        if(q.size()>6)q.pop_front();
    }
    printf("%lld\n",cnt[0]);
    return 0;
}
```

<a id="problem-e"></a>

## E. 乔乔和牛牛逛超市

标签：`最大权闭合子图` · `最小割` · `二次函数`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9cb974ace1cba9a1f6a9)。重构版本地验证见 [VALIDATION.md](../tests/202006/VALIDATION.md)，未重新提交在线评测。

### 题意

每种商品可以不买，也可以购买整数数量 $x_i\in[L_i,R_i]$，开心程度为 $a_ix_i^2+b_ix_i+c_i$。在满足商品依赖的前提下，求最大总开心程度。

输入 `n m`，再输入各商品的 `L R a b c` 和 $m$ 条限制 `z x y`。$n\le10^4$、$m\le10^5$，每件商品的内部数量区间非空。

- 限制 `1 x y`：买商品 $y$ 就必须买商品 $x$。
- 限制 `2 x y`：商品 $y$ 买到端点数量 $L_y$ 或 $R_y$ 时，必须买商品 $x$。

输出最大总开心程度，允许所有商品都不买。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202006E) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202006E/)。

### 题解

**先把每种商品缩成两个有用状态**

内部购买的最佳收益记为 $I_i=\max_{L_i<x<R_i} f_i(x)$，端点购买最佳收益为 $E_i=\max(f_i(L_i),f_i(R_i))$。二次函数在整数区间的最大值只可能来自区间端点，或开口向下时顶点附近的整数，因此常数次计算即可。

建两个点：基础点权为 $I_i$，升级点权为 $E_i-I_i$，并添加“升级点必选基础点”的依赖边。 都不选表示不购买；只选基础点表示内部购买；两者都选的总权恰为 $E_i$。 即使某个权值为负，也不能直接删去，它可能被其他商品的依赖强制选中。

第一类限制添加 $base_y\to base_x$，第二类添加 $upgrade_y\to base_x$。问题成为：选择一个点集，使选中的点的所有后继也被选中，并最大化点权和，即最大权闭合子图。

**转换为最小割**

正权点由源点连入，容量为该权值；负权点向汇点连边，容量为权值绝对值；依赖边容量设为大于全部有限收益总和的 `INF`。 令所有正权之和为 $P$，答案为 $P-\text{最大流}$。源侧点表示选择；割去正权边意味着放弃收益，割去负权边意味着支付代价，而有限最小割不会违反依赖。

**正确性**

商品三态与闭合点集一一对应且收益相同，闭合子图与有限割的代价关系又是精确的，因此最小割给出原问题最大值。

**复杂度**

代码使用 Dinic。图有 $O(n)$ 点、$O(n+m)$ 边，通用最坏时间界为 $O(V^2E)$，空间 $O(n+m)$；实际为典型最大闭合图规模，收益和容量均用 64 位。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct flow{
    struct edge{
        int v,rev;
        ll cap;
    };
    vector<vector<edge>> g;
    vector<int> dep,cur;
    void init(int n){
        g.resize(n);
        dep.resize(n);
        cur.resize(n);
    }
    void add(int u,int v,ll c){
        edge a={v,(int)g[v].size(),c};
        edge b={u,(int)g[u].size(),0};
        g[u].push_back(a);
        g[v].push_back(b);
    }
    ll dfs(int u,int t,ll f){
        if(u==t)return f;
        for(int &i=cur[u];i<(int)g[u].size();++i){
            auto &e=g[u][i];
            if(e.cap && dep[e.v]==dep[u]+1){
                ll val=dfs(e.v,t,min(f,e.cap));
                if(val){
                    e.cap-=val;
                    g[e.v][e.rev].cap+=val;
                    return val;
                }
            }
        }
        return 0;
    }
    ll run(int s,int t){
        ll ans=0;
        while(true){
            fill(dep.begin(),dep.end(),-1);
            queue<int> q;
            q.push(s);
            dep[s]=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto &e:g[u]){
                    if(e.cap && dep[e.v]<0){
                        dep[e.v]=dep[u]+1;
                        q.push(e.v);
                    }
                }
            }
            if(dep[t]<0)return ans;
            fill(cur.begin(),cur.end(),0);
            while(ll val=dfs(s,t,INF)){
                ans+=val;
            }
        }
    }
}f;
int n,m,s,t;
ll sum;
void weight(int u,ll x){
    if(x>0){
        f.add(s,u,x);
        sum+=x;
    }
    else if(x<0)f.add(u,t,-x);
}
int main(){
    scanf("%d%d",&n,&m);
    s=n*2;
    t=s+1;
    f.init(t+1);
    for(int i=0;i<n;++i){
        ll l,r,a,b,c;
        scanf("%lld%lld%lld%lld%lld",&l,&r,&a,&b,&c);
        auto calc=[&](ll x){
            return a*x*x+b*x+c;
        };
        ll in=max(calc(l+1),calc(r-1));
        if(a<0){
            ll mid=-b/(2*a);
            for(ll x=mid-2;x<=mid+2;++x){
                if(l<x && x<r)in=max(in,calc(x));
            }
        }
        ll out=max(calc(l),calc(r));
        weight(i,in);
        weight(i+n,out-in);
        f.add(i+n,i,INF);
    }
    while(m--){
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);
        f.add(y-1+(z==2?n:0),x-1,INF);
    }
    printf("%lld\n",sum-f.run(s,t));
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202006/VALIDATION.md)
- [b-increment-followup.json](../tests/202006/b-increment-followup.json)
- [details.txt](../tests/202006/details.txt)
- [nightly-review-followup.json](../tests/202006/nightly-review-followup.json)
- [prose-final-review.json](../tests/202006/prose-final-review.json)
- [report.json](../tests/202006/report.json)
- [retained_oracles.py](../tests/202006/retained_oracles.py)
- [verify.py](../tests/202006/verify.py)

<!-- local-validation-attachments:end -->
