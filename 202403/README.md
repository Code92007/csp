---
title: "CSP 202403 五题题解"
contest: "202403"
contest_month: "2024-03"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "计数", "时间戳", "集合", "哈希", "大小写转换", "字符串解析", "线性代数", "高斯消元", "模运算", "模拟", "双向链表", "优先队列", "树", "链表", "DFS序", "树状数组"]
status: "published"
problems: [{"id": "A", "title": "词频统计", "tags": ["计数", "时间戳"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16031"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202403A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce824a67df0b81749bba4"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305704089", "source_sha256": "996c2338843e673e4a1ec169e06de90b2bee6c94607b6958dafe8ac6d1c72584"}}, {"id": "B", "title": "相似度计算", "tags": ["集合", "哈希", "大小写转换"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16032"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202403B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce826a67df0b81749bbbe"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305705069", "source_sha256": "30ce8de0093ddd70c25bb3cfb9525bc861dcb791c7c378067b3c45fb00a699e4"}}, {"id": "C", "title": "化学方程式配平", "tags": ["字符串解析", "线性代数", "高斯消元", "模运算"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16033"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202403C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce828a67df0b81749bbd1"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305706100", "source_sha256": "8e62d557e567c2b940d63ef864f210972ee802194bbb6648a542f6aa636361b9"}}, {"id": "D", "title": "十滴水", "tags": ["模拟", "双向链表", "优先队列"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16034"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202403D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce829a67df0b81749bbe8"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305707098", "source_sha256": "56cd351dad5356979e24157a51d0d926a323500db0a838858d44d98dfbdac5c5"}}, {"id": "E", "title": "文件夹合并", "tags": ["树", "链表", "DFS序", "树状数组"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P16035"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202403E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202403E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce82ba67df0b81749bbfa"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305803314", "source_sha256": "dee2d9ee55c9b370bc2d6cec4977d220e26fea9b9af6d77d03d10625d712a469"}}]
---

# CSP 202403 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202403/VALIDATION.md)

<a id="problem-a"></a>

## A. 词频统计

标签：`计数` · `时间戳`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce824a67df0b81749bba4)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305704089)。重构版本地验证见 [VALIDATION.md](../tests/202403/VALIDATION.md)，未重新提交在线评测。

### 题意

$n$ 篇文章由 $1\ldots m$ 的单词编号表示。对每个单词，统计它出现过的文章数和总出现次数；同一篇文章内重复出现，只贡献一次文章数。

输入 $n,m$，再逐篇输入文章的词数及单词编号序列。

按单词编号从小到大输出，每行给出出现文章数和总出现次数。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16031) · [曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202403A) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403A/)。

### 题解

为每个词保存 `sum`、`cnt` 和 `last` 三项。每读到一次词就增加 `sum`；只有 `last` 不是当前文章编号时才增加 `cnt`，并更新 `last`。

`last` 标记该词在当前文章是否已经计过，避免为每篇文章清空整个去重数组。两个计数分别统计全部出现和每篇首次出现，准确符合定义。时间 $O(总词数+m)$，空间 $O(m)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> cnt,sum,last;
int main(){
    scanf("%d%d",&n,&m);
    cnt.resize(m+1);
    sum.resize(m+1);
    last.resize(m+1);
    for(int i=1;i<=n;++i){
        int k;
        scanf("%d",&k);
        while(k--){
            int x;
            scanf("%d",&x);
            ++sum[x];
            if(last[x]!=i){
                ++cnt[x];
                last[x]=i;
            }
        }
    }
    for(int i=1;i<=m;++i){
        printf("%d %d\n",cnt[i],sum[i]);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 相似度计算

标签：`集合` · `哈希` · `大小写转换`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce826a67df0b81749bbbe)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305705069)。重构版本地验证见 [VALIDATION.md](../tests/202403/VALIDATION.md)，未重新提交在线评测。

### 题意

两篇文章各由一列英文单词组成，忽略大小写并分别去重后，求两个单词集合的交集与并集大小。

输入两篇文章的单词数 $n,m$，再分别输入两列单词。存档加强范围中，每篇文章可达 $5\times10^5$ 个单词。

依次输出交集和并集的大小，各占一行；不输出相似度小数。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16032) · [曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202403B) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403B/)。

### 题解

把所有单词统一转小写，分别插入两个 `unordered_set`。枚举第一集合，统计也在第二集合中的单词数 `I`；并集大小由容斥得到 `|A|+|B|-I`。

集合插入自动去掉同篇重复词，统一大小写保证比较规则一致；交集统计每个不同词一次，容斥只消除重复计算部分。期望时间为输入总字符数的线性量，空间为不同单词的总长度。只输出两个整数，不计算相似度小数。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
unordered_set<string> a,b;
string read(){
    string s;
    int c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(c!=EOF && !isspace(c)){
        s+=char(tolower(c));
        c=getchar();
    }
    return s;
}
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        a.insert(read());
    }
    while(m--){
        b.insert(read());
    }
    for(auto &s:a){
        cnt+=b.count(s);
    }
    printf("%d\n%zu\n",cnt,a.size()+b.size()-cnt);
    return 0;
}
```

<a id="problem-c"></a>

## C. 化学方程式配平

标签：`字符串解析` · `线性代数` · `高斯消元` · `模运算`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce828a67df0b81749bbd1)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305706100)。重构版本地验证见 [VALIDATION.md](../tests/202403/VALIDATION.md)，未重新提交在线评测。

### 题意

给出若干组物质的化学式，将每种物质的系数视为未知数，判断元素守恒对应的齐次线性方程组是否有非零解。允许部分系数为零，也不要求系数全为正。

输入测试组数，每组输入物质数和各化学式。每种化学式由小写元素名及原子数组成，不含括号，数字 1 不省略。每组物质、元素均不超过 40 种，原子数不超过 50。

每组输出一行：存在非零解输出 `Y`，否则输出 `N`。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16033) · [曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202403C) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403C/)。

### 题解

每个元素一行、每种物质一列，矩阵项就是原子数。设物质数为 m，齐次方程存在非零解当且仅当矩阵秩小于 m；如果元素数少于 m，直接成立。

本实现使用模素数高斯消元，且用明确的整数界保证判定，而非只取一个模数猜测。对 12 个不同且大于 $10^9$ 的素数求秩；任何一个模数下满列秩，都证明某个整数子式不为零，输出 N。

如果 12 个模数下全都不满秩，则每个 m 阶子式都被这 12 个素数整除。 另一方面，Hadamard 不等式给出子式绝对值至多 $(50\sqrt m)^m\le(50\sqrt{40})^{40}<10^{101}$；12 个素数的乘积超过 $10^{108}$。 一个绝对值比乘积小、又被乘积整除的整数只能为零。因此所有子式均为零，输出 Y 是确定正确的。

每轮消元找非零主元，乘模逆元归一化，再消去下方元素。时间 $O(12em\min(e,m))$，空间 $O(em)$，另加一次小规模素数预处理。这个判定只回答题目定义的线性相关性，不能把它解释成每种物质都参与的实际化学反应。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=45;
int t,n,m;
ll a[N][N],b[N][N];
vector<ll> p;
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
ll power(ll x,ll y,ll mod){
    ll ans=1;
    while(y){
        if(y&1)ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int gauss(ll mod){
    memcpy(b,a,sizeof a);
    int r=0;
    for(int c=0;c<m && r<n;++c){
        int u=r;
        while(u<n && !b[u][c]){
            ++u;
        }
        if(u==n)continue;
        for(int j=0;j<m;++j){
            swap(b[u][j],b[r][j]);
        }
        ll inv=power(b[r][c],mod-2,mod);
        for(int j=c;j<m;++j){
            b[r][j]=b[r][j]*inv%mod;
        }
        for(int i=r+1;i<n;++i){
            ll v=b[i][c];
            if(!v)continue;
            for(int j=c;j<m;++j){
                b[i][j]=(b[i][j]-v*b[r][j]%mod+mod)%mod;
            }
        }
        ++r;
    }
    return r;
}
int main(){
    for(ll x=1e9+7;p.size()<12;x+=2){
        bool ok=true;
        for(ll d=3;d*d<=x;d+=2){
            if(x%d==0){
                ok=false;
                break;
            }
        }
        if(ok)p.push_back(x);
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        memset(a,0,sizeof a);
        map<string,int> id;
        n=0;
        for(int c=0;c<m;++c){
            string s=read();
            int i=0,len=s.size();
            while(i<len){
                string key;
                while(i<len && islower(s[i])){
                    key+=s[i++];
                }
                int v=0;
                while(i<len && isdigit(s[i])){
                    v=v*10+s[i++]-'0';
                }
                if(!id.count(key))id[key]=n++;
                a[id[key]][c]=v;
            }
        }
        bool ok=true;
        if(n>=m){
            for(ll &mod:p){
                if(gauss(mod)==m){
                    ok=false;
                    break;
                }
            }
        }
        puts(ok?"Y":"N");
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 十滴水

标签：`模拟` · `双向链表` · `优先队列`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce829a67df0b81749bbe8)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305707098)。重构版本地验证见 [VALIDATION.md](../tests/202403/VALIDATION.md)，未重新提交在线评测。

### 题意

一维格子中，最初有 $m$ 个位置分别含 1 到 4 滴水。每次向一个当前有水的位置加一滴；达到 5 滴的格子会爆开清空，并向左右最近的有水格子各加一滴。若有多个位置待爆，始终先处理最左边的，包括连锁反应中新产生的位置。

输入 `c m n`、$m$ 个 `位置 水量`，再输入 $n$ 个操作位置。$c\le10^9$、$m\le3\times10^5$、$n\le4m$，保证操作目标当时有水。

每次操作及其全部连锁反应结束后，输出剩余有水格子数。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16034) · [曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202403D) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403D/)。

### 题解

**空格子以后不会重新有水**

加水操作只指定已有水的格子，爆炸也只给最近的有水格子加水。 因此位置集合只会删除，可以先按坐标排序，再用两个数组保存存活格子的左邻居、右邻居，构成双向链表。 爆炸时摘掉当前节点，将两个邻居接起来即可。

待爆位置存入小根堆，堆顶始终是当前最左的待爆格子。加水时只在水量从 4 变成 5 的一刻入堆；继续变成 6、7 不再入堆，保证每个格子只排队一次。

取出后先记住左右邻居，再删除当前格子，最后同时向这两个邻居加水。 新到达 5 的格子加入同一个堆，下次重新取最左者，不能用普通 FIFO 队列代替。

输入操作位置通过排序数组二分定位；数组中的坐标始终保留，只修改水量和链表指针。题目保证操作位置当时有水。

链表始终表示当前存活位置的顺序，堆始终包含所有待爆位置，故每一步与规定的游戏过程完全一致。每个格子最多爆一次，总时间 $O((m+n)\log m)$，空间 $O(m)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int c,m,n,cnt;
vector<P> a;
vector<int> l,r;
priority_queue<int,vector<int>,greater<int>> q;
void add(int u){
    if(u>=0 && u<m && ++a[u].second==5)q.push(u);
}
int main(){
    scanf("%d%d%d",&c,&m,&n);
    a.resize(m);
    l.resize(m);
    r.resize(m);
    for(auto &[x,y]:a){
        scanf("%d%d",&x,&y);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;++i){
        l[i]=i-1;
        r[i]=i+1;
    }
    cnt=m;
    while(n--){
        int x;
        scanf("%d",&x);
        int u=lower_bound(a.begin(),a.end(),P(x,-1))-a.begin();
        add(u);
        while(!q.empty()){
            int v=q.top();
            q.pop();
            int s=l[v],t=r[v];
            if(s>=0)r[s]=t;
            if(t<m)l[t]=s;
            a[v].second=0;
            --cnt;
            add(s);
            add(t);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 文件夹合并

标签：`树` · `链表` · `DFS序` · `树状数组`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce82ba67df0b81749bbfa)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305803314)。重构版本地验证见 [VALIDATION.md](../tests/202403/VALIDATION.md)，未重新提交在线评测。

### 题意

给定以 1 为根的文件夹树，每个文件夹有自己的数据量。支持合并一层子文件夹，以及查询访问某个文件夹需要经过多少个存活文件夹。

输入 `n m`、节点 2 到 $n$ 的父亲、各点数据量和 $m$ 条操作。$n\le5\times10^5$、$m\le3n$，操作目标保证仍存活。

- `1 x`：删除 $x$ 当前的全部直接子文件夹，把它们的数据量加给 $x$，并把它们的子文件夹提升为 $x$ 的直接子文件夹。输出新的直接子文件夹数和 $x$ 的数据量。
- `2 z`：输出从根到 $z$ 的路径上存活文件夹数，包括根和 $z$。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P16035) · [曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202403E) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202403E/)。

### 题解

**子文件夹用链表整段拼接**

每个点保存当前孩子链表的头尾和孩子数。 合并 $x$ 时先取走旧孩子链表，再逐个删除旧孩子 $y$，把 $y$ 的整条孩子链表接入新表。 拼接只修改头尾指针，不逐个重设孙子的父亲。

注意不能把刚提升的孙子也在同一次操作中删除，所以代码会保存旧表的 `next` 再拼接。 每个点至多被删除一次，总遍历量为 $O(n)$。

**访问路径沿用原树**

节点被删除后只是从祖先路径中跳过，存活点的原始祖先关系没有改变。 预处理原树 DFS 序，$y$ 的所有后代构成连续区间 $[dfn_y,out_y]$。 删除 $y$，就在这个区间上减一；访问 $z$ 的答案是原深度（根深度为 1）加上 $dfn_z$ 处的累计改变量。

树状数组实现“区间加、单点查”：区间左端加 $-1$，右端后一位加 $1$。单点查取前缀和。被删点本身也在区间内没有问题，因为题目不会再询问它。

**正确性**

链表精确完成一层合并，每个被删除祖先恰好对其后代扣掉一次访问次数，故两种输出分别符合定义。

**复杂度**

$O((n+m)\log n)$ 时间、$O(n)$ 空间。 数据量之和可能超过 32 位，使用 `long long`；DFS 使用显式栈。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,bool> P;
const int N=5e5+10;
int n,m,op,u,head[N],tail[N],nxt[N],cnt[N];
int dep[N],dfn[N],out[N],tot;
ll a[N];
vector<int> g[N];
struct BIT{
    int n,tr[N];
    void init(int x){
        n=x;
        memset(tr,0,sizeof tr);
    }
    void add(int x,int v){
        for(;x<=n;x+=x&-x){
            tr[x]+=v;
        }
    }
    int sum(int x){
        int ans=0;
        for(;x;x-=x&-x){
            ans+=tr[x];
        }
        return ans;
    }
}bit;
void append(int u,int l,int r){
    if(!l)return;
    if(tail[u])nxt[tail[u]]=l;
    else head[u]=l;
    tail[u]=r;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;++i){
        int p;
        scanf("%d",&p);
        g[p].push_back(i);
        append(p,i,i);
        ++cnt[p];
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    vector<P> st;
    st.push_back({1,false});
    dep[1]=1;
    while(!st.empty()){
        auto [x,ed]=st.back();
        st.pop_back();
        if(ed){
            out[x]=tot;
            continue;
        }
        dfn[x]=++tot;
        st.push_back({x,true});
        for(int &v:g[x]){
            dep[v]=dep[x]+1;
            st.push_back({v,false});
        }
    }
    bit.init(n);
    while(m--){
        scanf("%d%d",&op,&u);
        if(op==2){
            int ans=dep[u]+bit.sum(dfn[u]);
            printf("%d\n",ans);
        }
        else{
            int v=head[u];
            head[u]=tail[u]=cnt[u]=0;
            while(v){
                int next=nxt[v];
                nxt[v]=0;
                a[u]+=a[v];
                append(u,head[v],tail[v]);
                cnt[u]+=cnt[v];
                bit.add(dfn[v],-1);
                bit.add(out[v]+1,1);
                v=next;
            }
            printf("%d %lld\n",cnt[u],a[u]);
        }
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202403/VALIDATION.md)
- [details.txt](../tests/202403/details.txt)
- [prose-final-review.json](../tests/202403/prose-final-review.json)
- [report.json](../tests/202403/report.json)
- [retained_oracles.py](../tests/202403/retained_oracles.py)
- [style-followup-before.json](../tests/202403/style-followup-before.json)
- [style-followup-report.json](../tests/202403/style-followup-report.json)
- [verify-style-followup.py](../tests/202403/verify-style-followup.py)
- [verify.py](../tests/202403/verify.py)

<!-- local-validation-attachments:end -->
