---
title: "CSP 201912 五题题解"
contest: "201912"
contest_month: "2019-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "数位判断", "循环模拟", "集合", "坐标枚举", "递归下降", "哈希计数", "化学式", "图论", "BFS", "事件模拟", "有序映射", "线段树", "有限群", "状态压缩", "数论"]
status: "published"
problems: [{"id": "A", "title": "报数", "tags": ["数位判断", "循环模拟"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版 C++17 编译通过；62 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9d4674ace1cba9a1f711"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "B", "title": "回收站选址", "tags": ["集合", "坐标枚举"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版 C++17 编译通过；104 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9dd274ace1cba9a1f78d"}, "original_validation": "C++17 编译通过；3 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "C", "title": "化学方程式", "tags": ["递归下降", "哈希计数", "化学式"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版 C++17 编译通过；102 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U283455"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9e5474ace1cba9a1f7d3"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305950101", "source_sha256": "189420464de9f6d303fba4f90ce0c63be59f635e2cbab8ce639ef536bb5d0c26"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted；洛谷民间数据 100 分 Accepted（民间复刻评测）。"}, {"id": "D", "title": "区块链", "tags": ["图论", "BFS", "事件模拟", "有序映射"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版 C++17 编译通过；83 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9ee174ace1cba9a1f812"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "E", "title": "魔数", "tags": ["线段树", "有限群", "状态压缩", "数论"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版 C++17 编译通过；61 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201912E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201912E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6add9fb574ace1cba9a1f846"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}]
---

# CSP 201912 五题题解

[返回总目录](../README.md) · [本地验证](../tests/201912/VALIDATION.md)


<a id="problem-a"></a>

## A. 报数

标签：`数位判断` · `循环模拟`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201912/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6add9d4674ace1cba9a1f711)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9d4674ace1cba9a1f711)（复刻评测）。

### 题意

四个人从 1 起轮流报数，遇到 7 的倍数或十进制中含 7 的数时跳过。跳过仍占用该人的轮次，实际报出 n 个数后停止。

输入 n，范围为 n≤666。

按轮流顺序输出每个人跳过的次数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912A)。

### 题解

分别维护当前整数 `x` 和已成功报出的数量 `sum`。若 `x%7==0` 或逐位检查含 7，给 `(x-1)%4` 号人的跳过次数加一；否则 `sum` 加一。每轮 `x` 都增加，直到 `sum` 达到 `n`。

轮次由尝试报的整数确定，终止条件由成功次数确定，两者分开才能正确模拟。设最后尝试到X，时间 $O(X\log X)$，额外空间 $O(1)$；题目n≤666。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=4;
int n,cnt[N],sum;
bool skip(int x){
    if(x%7==0)return true;
    while(x){
        if(x%10==7)return true;
        x/=10;
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int x=1;sum<n;++x){
        if(skip(x))++cnt[(x-1)%4];
        else ++sum;
    }
    for(int &x:cnt){
        printf("%d\n",x);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 回收站选址

标签：`集合` · `坐标枚举`

本地验证：104 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201912/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6add9dd274ace1cba9a1f78d)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；3 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9dd274ace1cba9a1f78d)（复刻评测）。

### 题意

从垃圾点中选择回收站。候选点必须有上下左右四个垃圾点，得分是四个对角邻居中存在垃圾的数量。

输入垃圾点数 n 及各点坐标，n≤1000，所有点互异，坐标可以为负。

依次输出得分为 0、1、2、3、4 的选址数量。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912B)。

### 题解

把全部坐标放入 set<pair<int,int>>，枚举每个垃圾点。先查四个正邻居，缺一个就跳过；否则查询四个对角点并把相应分数计数加一。

每个候选都必须位于输入垃圾点，枚举不会漏；两组查找分别直接对应资格和得分定义。时间 $O(n\log n)$，空间 $O(n)$。坐标范围很大，应按坐标存集合，不能开覆盖全地图的数组。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=5;
int n,cnt[N];
set<P> a;
bool ok(int x,int y){
    vector<P> g={{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
    for(auto &v:g){
        if(!a.count(v))return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        a.insert({x,y});
    }
    for(const auto &[x,y]:a){
        if(!ok(x,y))continue;
        int sum=0;
        for(int dx:{-1,1}){
            for(int dy:{-1,1}){
                sum+=a.count({x+dx,y+dy});
            }
        }
        ++cnt[sum];
    }
    for(int &x:cnt){
        printf("%d\n",x);
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 化学方程式

标签：`递归下降` · `哈希计数` · `化学式`

本地验证：102 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201912/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6add9e5474ace1cba9a1f7d3)。

原版验证：**完整实现，已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9e5474ace1cba9a1f7d3)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305950101)（民间复刻评测）。

### 题意

判断化学方程式两侧每种元素的原子总数是否相同。支持系数、元素下标、多层括号及加号，省略的系数表示 1。

输入方程式数量，随后输入各条合法方程式。表达式长度不超过 1000，每侧任一元素的总数不超过 $10^9$。

配平时输出 Y，否则输出 N。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912C)。

### 题解

按照题目语法分层解析：表达式处理“系数×化学式”并以加号分隔；化学式反复读取“项×下标”；项要么是大写字母及可选小写字母组成的元素，要么是括号中的递归化学式。

每层返回“元素名→数量”的字典。元素产生数量 1，括号产生内部统计结果；读到后缀系数就整体相乘，再并入当前字典。左右表达式分别计算，比较字典即可。不要把 Co 拆成 C、o，也不要把括号后的系数只乘最后一个元素。

递归结构与化学式结构一致，逐层计数保持每个子式的元素总数正确。设元素种类 E、文本长度 L，map 实现保守时间 $O(LE\log E)$，空间 $O(LE)$；本题 E≤702，实际通常远小于此上界。用 64 位累加。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<string,ll> counts;
const int N=1010;
int n,p;
char s[N];
ll num(){
    if(!isdigit(s[p]))return 1;
    ll x=0;
    while(isdigit(s[p])){
        x=x*10+s[p++]-'0';
    }
    return x;
}
void add(counts &a,const counts &b,ll k){
    for(const auto &[x,v]:b){
        a[x]+=v*k;
    }
}
counts formula(){
    counts ans;
    while(s[p] && s[p]!=')' && s[p]!='+' && s[p]!='='){
        counts cur;
        if(s[p]=='('){
            ++p;
            cur=formula();
            ++p;
        }
        else{
            string x(1,s[p++]);
            if(islower(s[p]))x+=s[p++];
            cur[x]=1;
        }
        ll k=num();
        add(ans,cur,k);
    }
    return ans;
}
counts expr(){
    counts ans;
    while(s[p] && s[p]!='='){
        ll k=num();
        counts cur=formula();
        add(ans,cur,k);
        if(s[p]=='+')++p;
        else break;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%1000s",s);
        p=0;
        counts a=expr();
        ++p;
        counts b=expr();
        puts(a==b?"Y":"N");
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 区块链

标签：`图论` · `BFS` · `事件模拟` · `有序映射`

本地验证：83 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201912/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6add9ee174ace1cba9a1f812)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9ee174ace1cba9a1f812)（复刻评测）。

### 题意

网络节点维护从创世块 0 开始的链：收到更长链时替换，等长时取末块编号较小者；本地产生块时接在当前链尾。主链更新后发给邻居，每条边传输耗时 t。

输入节点数 n、边数 m 和网络边，再输入传播延迟 t、操作数 k 及逐行操作，范围为 $n\le500,k\le3\times10^4$。同一时刻先接收再产生，查询排在该时刻全部产生操作之后：

- `节点 时刻 新块编号`：产生区块。
- `节点 时刻`：查询该节点的主链。

每次查询输出链长及从创世块 0 开始的区块编号序列。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912D)。

### 题解

**把每条新链的传播改写为最短路到达**

图的每条边延迟相同，先从每个节点 BFS，求两点最少边数。一个新块生成时，其所在完整链可以认为会在“生成时刻 + 最少边数 × t”抵达每个可达节点。

这一改写需要证明：链可能在中途被更好的链压制，为何还能假想它继续传播？若链 A 在某节点输给 B，那么 B 更长，或等长但末块更小。B 从该处继续沿 A 的后续路线传播，抵达时间不晚于假想 A，且比较结果始终更好；若 B 又被压制，继续使用同样的替代论证。

故假想传播的 A 永远不会造成一次不该发生的有效更新。反过来，真实的传播不可能早于最短路时间。两种模型在每个节点的最优主链完全一致。

**每个节点只保存未来的有效候选**

用 map 按到达时间维护未来主链，越晚的候选必须严格更好。插入新候选时，若它不胜过前一个候选就丢弃；否则删去后方被它压制的候选。查询或生成新块之前，把已经到达的候选推进到当前状态。每个历史区块只存父区块、长度、编号；传播传递链尾下标，输出时沿父指针还原。

比较只依赖长度和唯一末块编号，是一致的全序；被提前到达且更好的链支配的候选永远不可能胜出，故删除安全。最坏时间 $O(n(n+m)+nk\log k+P)$，空间 $O(n^2+nk+k)$，其中 P 为实际输出总长度；候选删除可显著减少实际存储。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100;
struct block{
    int fa,id,len;
};
int n,m,k;
ll delay;
char s[N];
vector<vector<int>> g,d;
vector<block> e{{-1,0,1}};
vector<int> cur;
vector<map<ll,int>> q;
bool better(int a,int b){
    if(e[a].len!=e[b].len)return e[a].len>e[b].len;
    return e[a].id<e[b].id;
}
void advance(int u,ll t){
    auto it=q[u].upper_bound(t);
    if(it!=q[u].begin())cur[u]=prev(it)->second;
    q[u].erase(q[u].begin(),it);
}
void schedule(int u,ll t,int x){
    auto it=q[u].lower_bound(t);
    int pre=it==q[u].begin()?cur[u]:prev(it)->second;
    if(!better(x,pre))return;
    if(it!=q[u].end() && it->first==t && !better(x,it->second))return;
    while(it!=q[u].end() && !better(it->second,x)){
        it=q[u].erase(it);
    }
    q[u][t]=x;
}
int main(){
    scanf("%d%d",&n,&m);
    g.resize(n);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%lld%d",&delay,&k);
    d.assign(n,vector<int>(n,-1));
    for(int st=0;st<n;++st){
        vector<int> v{st};
        d[st][st]=0;
        for(size_t p=0;p<v.size();++p){
            for(int &u:g[v[p]]){
                if(d[st][u]>=0)continue;
                d[st][u]=d[st][v[p]]+1;
                v.push_back(u);
            }
        }
    }
    cur.resize(n);
    q.resize(n);
    fgets(s,N,stdin);
    for(int i=0;i<k;++i){
        fgets(s,N,stdin);
        int u,id;
        ll t;
        bool make=sscanf(s,"%d%lld%d",&u,&t,&id)==3;
        --u;
        advance(u,t);
        if(make){
            int x=e.size();
            e.push_back({cur[u],id,e[cur[u]].len+1});
            cur[u]=x;
            auto it=q[u].begin();
            while(it!=q[u].end() && !better(it->second,x)){
                it=q[u].erase(it);
            }
            for(int v=0;v<n;++v){
                if(v!=u && d[u][v]>=0)schedule(v,t+delay*d[u][v],x);
            }
        }
        else{
            vector<int> ans;
            for(int p=cur[u];p!=-1;p=e[p].fa){
                ans.push_back(e[p].id);
            }
            reverse(ans.begin(),ans.end());
            printf("%d",(int)ans.size());
            for(int &x:ans){
                printf(" %d",x);
            }
            putchar('\n');
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 魔数

标签：`线段树` · `有限群` · `状态压缩` · `数论`

本地验证：61 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201912/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6add9fb574ace1cba9a1f846)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6add9fb574ace1cba9a1f846)（复刻评测）。

### 题意

初始序列为 $A_i=i$。每次给出区间 $[l,r]$，先求 $\sum f(A_i)$，其中 $f(x)=(x\bmod P)\bmod2019$，$P=2009731336725594113$；再令区间内所有数乘上题面五个常数中的 $U_{sum\bmod5}$。

输入 n、q 及 q 个区间，范围为 $n\le10^6,q\le10^5$。只需维护模 $P$ 的值，但不能交换两次取模的顺序。

依次输出每次修改前的区间和。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201912E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201912E)。

### 题解

**关键在五个常数生成的乘法集合**

从 1 开始，不断乘任意一个 $U_i$ 并模 $P$，新得到的余数加入队列。对于题面固定的常数，这个闭包只有 32 个元素。代码直接计算闭包并检查大小，不依赖手写猜测的常数表。随后枚举任意两个状态的乘积，预处理乘积表 `f[a][b]`；题面模数在代码中命名为 `mod`。

**一个区间预存 32 种未来答案**

线段树节点保存

$$s[j]=\sum_{i\text{在区间内}} ((A_i\cdot g_j\bmod P)\bmod2019).$$

其中 $g_0=1$，所以当前答案是 `s[0]`。整段乘 $g_t$ 后，新的 `s[j]` 就是旧的 `s[f[j][t]]`，一次修改只需重排 32 个统计量。懒标记同样通过乘积表合成。

初始叶子 $i$ 需要计算 $i g_s\bmod P$。按 $i$ 递增时，每个状态的余数可由前一个余数加 $g_s$ 获得，只需一次减法取模，避免在百万个叶子上反复做 128 位除法。只有生成闭包和乘积表时使用 `__uint128_t` 安全乘法。

**正确性**

任何实际乘数都由五个常数相乘得到，始终属于闭包；32 个统计量因此涵盖所有可能的未来统一修改。乘法结合律保证状态重排与逐点乘法完全相同，线段树求和和懒标记保持该不变量。

**复杂度**

建树 $O(32n)$，每次询问及随后的修改 $O(32\log n)$，空间 $O(32n)$。本实现把叶子数扩成二的幂，$n=10^6$ 时统计数组约 256 MiB，连同节点端点和标记的节点数组约 280 MiB，适用于题面 1024 MiB 内存限制；不能随意搬到 128 MiB 环境。单个区间和最多 $2018n$，在本题范围内仍可用 32 位整数。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef __uint128_t u128;
const int N=32,M=5;
const ull mod=2009731336725594113ull;
const ull magic[M]={314882150829468584ull,427197303358170108ull,1022292690726729920ull,1698479428772363217ull,2006101093849356424ull};
int n,q,l,r,f[N][N];
ull rem[N];
vector<ull> g{1};
map<ull,int> id{{1,0}};
struct segtree{
    int n;
    struct node{
        int l,r,s[N];
        unsigned char tag;
    };
    vector<node> e;
    #define l(p) e[p].l
    #define r(p) e[p].r
    void pushup(int p){
        for(int i=0;i<N;++i){
            e[p].s[i]=e[p<<1].s[i]+e[p<<1|1].s[i];
        }
    }
    void build(int p,int x,int y,int k){
        l(p)=x;r(p)=y;
        if(x==y){
            if(x>k)return;
            for(int i=0;i<N;++i){
                rem[i]+=g[i];
                if(rem[i]>=mod)rem[i]-=mod;
                e[p].s[i]=rem[i]%2019;
            }
            return;
        }
        int mid=(x+y)>>1;
        build(p<<1,x,mid,k);
        build(p<<1|1,mid+1,y,k);
        pushup(p);
    }
    void init(int k){
        n=1;
        while(n<k){
            n<<=1;
        }
        e.resize(n<<1);
        build(1,1,n,k);
    }
    void set(int p,int s){
        int a[N];
        for(int i=0;i<N;++i){
            a[i]=e[p].s[f[i][s]];
        }
        copy(a,a+N,e[p].s);
        e[p].tag=f[e[p].tag][s];
    }
    void pushdown(int p){
        if(!e[p].tag)return;
        set(p<<1,e[p].tag);
        set(p<<1|1,e[p].tag);
        e[p].tag=0;
    }
    int query(int p,int x,int y){
        if(x<=l(p) && r(p)<=y)return e[p].s[0];
        pushdown(p);
        int mid=(l(p)+r(p))>>1,ans=0;
        if(x<=mid)ans+=query(p<<1,x,y);
        if(y>mid)ans+=query(p<<1|1,x,y);
        return ans;
    }
    void update(int p,int x,int y,int s){
        if(x<=l(p) && r(p)<=y){
            set(p,s);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(x<=mid)update(p<<1,x,y,s);
        if(y>mid)update(p<<1|1,x,y,s);
        pushup(p);
    }
}tr;
int main(){
    scanf("%d%d",&n,&q);
    for(size_t i=0;i<g.size();++i){
        for(const ull &x:magic){
            ull y=u128(g[i])*x%mod;
            if(id.count(y))continue;
            id[y]=g.size();
            g.push_back(y);
        }
    }
    if(g.size()!=N)return 1;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            f[i][j]=id.at(u128(g[i])*g[j]%mod);
        }
    }
    tr.init(n);
    while(q--){
        scanf("%d%d",&l,&r);
        int ans=tr.query(1,l,r);
        printf("%d\n",ans);
        tr.update(1,l,r,id.at(magic[ans%5]));
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201912/VALIDATION.md)
- [b-neighbor-followup-report.json](../tests/201912/b-neighbor-followup-report.json)
- [boundaries.py](../tests/201912/boundaries.py)
- [d-print-followup-report.json](../tests/201912/d-print-followup-report.json)
- [e-constants-followup-report.json](../tests/201912/e-constants-followup-report.json)
- [e-mod-followup-report.json](../tests/201912/e-mod-followup-report.json)
- [refactor-report.json](../tests/201912/refactor-report.json)
- [statements.json](../tests/201912/statements.json)

<!-- local-validation-attachments:end -->
