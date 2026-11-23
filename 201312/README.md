---
title: "CSP 201312 五题题解"
contest: "201312"
contest_month: "2013-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "频率统计", "同分规则", "字符串", "校验码", "单调栈", "直方图", "最大矩形", "状态压缩", "计数DP", "图论", "BFS", "反向图", "网格"]
status: "published"
problems: [{"id": "A", "title": "出现次数最多的数", "tags": ["频率统计", "同分规则"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc26374ace1cba9a21910"}}, {"id": "B", "title": "ISBN 号码", "tags": ["字符串", "校验码"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/P1055"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc2ed74ace1cba9a219a9"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/306035824", "source_sha256": "fb2dbaaa5a38e612c92b9e432e0ff9a75fc25dbbdd33a522d2084d2ea8020ec0"}}, {"id": "C", "title": "最大的矩形", "tags": ["单调栈", "直方图", "最大矩形"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "洛谷民间题面（可提交）", "url": "https://www.luogu.com.cn/problem/U281824"}, {"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312C/"}], "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305657951"}, "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addfb8f74ace1cba9a23115", "source_sha256": "a4c57208b2ba6ed54326a0002e455c660500b1319c5a4f0d3c191b6121ef19ab"}}, {"id": "D", "title": "有趣的数", "tags": ["状态压缩", "计数DP"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc37d74ace1cba9a21a93"}}, {"id": "E", "title": "I’m stuck!", "tags": ["图论", "BFS", "反向图", "网格"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201312E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201312E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc40e74ace1cba9a21ab6"}}]
---

# CSP 201312 五题题解

[返回总目录](../README.md) · [本地验证](../tests/201312/VALIDATION.md)

本题组为第 0 次（练习题组），不计入正式认证场次。

<a id="problem-a"></a>

## A. 出现次数最多的数

标签：`频率统计` · `同分规则`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addc26374ace1cba9a21910)。重构版本地验证见 [VALIDATION.md](../tests/201312/VALIDATION.md)，未重新提交在线评测。

### 题意

给出若干整数，找出出现次数最多的数；若并列，选择其中最小的数。

输入整数个数 `n`，随后给出 `n` 个整数。$1\le n\le1000$，整数范围为 $1\ldots10000$。

输出符合要求的整数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312A) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312A/)。

### 题解

用 `map` 统计频次，它会按数值升序遍历。维护当前最高频次，只有遇到严格更高频次时才更新答案；同频不更新，使较小值被保留。

计数准确，扫描后最高频次为全局最大，升序加严格更新保证并列取最小。设不同值个数为 $u$，时间 $O(n\log u+u)$，空间 $O(u)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int n,x,ans,num;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        ++cnt[x];
    }
    for(auto &[x,c]:cnt){
        if(c>num){
            num=c;
            ans=x;
        }
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. ISBN 号码

标签：`字符串` · `校验码`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addc2ed74ace1cba9a219a9)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/306035824)。重构版本地验证见 [VALIDATION.md](../tests/201312/VALIDATION.md)，未重新提交在线评测。

### 题意

ISBN 号码由九位数字、三个连字符和一位校验码组成。九位数字按顺序乘以权重 $1\ldots9$，总和模 11 的结果即为校验码，其中 10 用 `X` 表示。

输入一个格式为 `x-xxx-xxxxx-x` 的 ISBN 号码，末位为数字或 `X`。

若校验码正确，输出 `Right`；否则只修正末位校验码，输出完整号码并保留连字符。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/P1055) · [曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312B) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312B/)。

### 题解

扫描末位之前的字符，遇到数字才乘当前权重并递增，连字符直接跳过。求余后转换为 0…9 或 X，与末位比较；不符时仅替换末位，原有分隔符保留。

数字权重由遇到的数字数量决定，恰好对应定义中的 1 到 9，不受三个连字符位置影响。固定长度输入，时间和空间均为 $O(1)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=20;
char s[N],c;
int n,w=1,sum;
int main(){
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n-1;++i){
        if(s[i]!='-')sum+=(s[i]-'0')*w++;
    }
    int r=sum%11;
    c=r==10?'X':char('0'+r);
    if(s[n-1]==c)puts("Right");
    else{
        s[n-1]=c;
        puts(s);
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 最大的矩形

标签：`单调栈` · `直方图` · `最大矩形`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addfb8f74ace1cba9a23115)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305657951)。重构版本地验证见 [VALIDATION.md](../tests/201312/VALIDATION.md)，未重新提交在线评测。

### 题意

给定若干宽为 1、高度不同的相邻柱子，求直方图内与坐标轴平行的矩形的最大面积。

输入柱子数 `n` 和依次排列的 `n` 个高度。以下实现覆盖公开存档的加强范围 $n\le10^5,h_i\le10^9$。

输出最大矩形面积，结果可能达到 $10^{14}$。

来源：[洛谷民间题面（可提交）](https://www.luogu.com.cn/problem/U281824) · [曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312C) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312C/)。

### 题解

维护高度严格递增的下标栈，左端放高度 0 的哨兵，最右端也补 0。 扫描到 `i` 时，若栈顶高度不小于当前高度，就弹出 `u`：弹出后新栈顶是左侧更低边界，当前 i 是可用于结算的右边界，候选面积为 `h[u]*(i-st[top]-1)`。 随后压入 i。

对相等高度提前弹出不会漏解，后面的同高柱会继承更左边界，最终覆盖整段。任意最优矩形可选一根最低柱作为高度，其最大可扩展宽度会在某次弹栈时被计算，所以取全部候选最大值正确。

每个下标只入栈、出栈一次，时间 $O(n)$，空间 $O(n)$。面积可能达到 $10^{14}$，必须使用 64 位整数。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,st[N],top;
ll h[N],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&h[i]);
    }
    for(int i=1;i<=n+1;++i){
        while(top && h[st[top]]>=h[i]){
            int u=st[top--];
            ans=max(ans,h[u]*(i-st[top]-1));
        }
        st[++top]=i;
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-d"></a>

## D. 有趣的数

标签：`状态压缩` · `计数DP`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addc37d74ace1cba9a21a93)。重构版本地验证见 [VALIDATION.md](../tests/201312/VALIDATION.md)，未重新提交在线评测。

### 题意

统计恰有 `n` 位的十进制数：只使用 0、1、2、3，且四种数字均至少出现一次；所有 0 在所有 1 前面，所有 2 在所有 3 前面，首位不能为 0。

原 CSP 输入一个 `n`，$1\le n\le1000$；公开存档改为先输入组数 `T`，再输入各组的 `n`。下面代码同时支持这两种输入形式。

对每组输入输出符合条件的数的个数，答案模 $10^9+7$。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312D) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312D/)。

### 题解

用四位掩码记录哪些数字已经出现，$dp[S]$ 为当前长度下的合法前缀数。 每次尝试添加一个数字，检查：首位不能为 0；已经出现 1 后不能再放 0；出现 3 后不能再放 2。 还可以提前要求放 1 前必须出现过 0、放 3 前必须出现过 2，因为否则以后无法补齐前置数字。

合法添加后，把对应位设为 1，方案数累加。空串初始 $dp[0]=1$；达到目标长度后只取 `S=15` 的状态，保证四种数字都出现。按这些条件，首位实际上只能是 2，但无需在代码外另加特殊递推。

每个合法数按末位删除后，唯一对应一个合法前缀及添加动作；每个被接受的添加也不会破坏顺序，所以计数无重无漏。 每一位仅 16×4 次转移，时间 $O(n)$、滚动 DP 空间 $O(1)$；为了回答多组输入，额外保存各长度答案，占 $O(n)$ 空间。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=16,mod=1e9+7;
int n,x,dp[M],nd[M],ans[N];
vector<int> a;
int main(){
    while(scanf("%d",&x)==1){
        a.push_back(x);
    }
    if(a.empty())return 0;
    int l=a.size()>1;
    n=*max_element(a.begin()+l,a.end());
    dp[0]=1;
    for(int len=0;len<n;++len){
        memset(nd,0,sizeof nd);
        for(int S=0;S<16;++S){
            for(int d=0;d<4;++d){
                if(!len && !d)continue;
                if(!d && (S&2))continue;
                if(d==1 && !(S&1))continue;
                if(d==2 && (S&8))continue;
                if(d==3 && !(S&4))continue;
                int to=S|(1<<d);
                nd[to]=(nd[to]+dp[S])%mod;
            }
        }
        memcpy(dp,nd,sizeof dp);
        ans[len+1]=dp[15];
    }
    for(int i=l;i<(int)a.size();++i){
        printf("%d\n",ans[a[i]]);
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. I’m stuck!

标签：`图论` · `BFS` · `反向图` · `网格`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addc40e74ace1cba9a21ab6)。重构版本地验证见 [VALIDATION.md](../tests/201312/VALIDATION.md)，未重新提交在线评测。

### 题意

在字符网格中，从起点 `S` 出发，每个格子的字符决定允许离开的方向。若能到达终点 `T`，求从 `S` 能走到、但从该格无法再到达 `T` 的格子数。

输入行列数 `R C` 和网格，$1\le R,C\le50$，其中恰有一个 `S` 和一个 `T`。各字符的规则如下：

- `#`：墙，不能进入。
- `+`、`S`、`T`：可以向上下左右离开。
- `-`：只能向左右离开。
- `|`：只能向上下离开。
- `.`：只能向下离开。

若从 `S` 无法到达 `T`，输出 `I'm stuck!`；否则输出满足条件的格子数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201312E) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201312E/)。

### 题解

**出边取决于当前格，不能看目标格决定方向**

对每个非墙格，按其字符类型枚举允许的离开方向。目标在边界内且不是墙，就建一条有向边，同时在反向图中建反向边。相邻格之间不一定双向可达。

从 S 在原图 BFS，得到 `vis`。如果 T 不在其中，立即输出指定提示。

再从 T 在反向图 BFS，得到 `can`：它表示原图中所有能够到达 T 的格子。 最终统计 `vis[u] && !can[u]`。

**为什么反向搜索等价**

原图中从 $u$ 到 T 的每条路径，翻转所有边后就是反向图中从 T 到 $u$ 的路径，反之也成立。 因此两次搜索的集合差恰好是题目要求的“能走进去但到不了终点”的位置。 无需从每个格子单独搜索一次，也不是简单判断它是否有出边。

**复杂度**

每格至多四条出边，两次 BFS 总时间、空间均为 $O(RC)$。网格越界、单向死路和先判断 S 能否到 T 是主要易错点。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=55,M=4,K=N*N;
int n,m,s,t,ans,dx[M]={-1,1,0,0},dy[M]={0,0,-1,1};
char a[N][N];
bool vis[K],can[K];
vector<int> g[K],h[K];
bool ok(char c,int d){
    if(c=='+' || c=='S' || c=='T')return true;
    if(c=='-')return d>=2;
    if(c=='|')return d<2;
    return c=='.' && d==1;
}
void bfs(int s,vector<int> g[],bool vis[]){
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int &v:g[u]){
            if(vis[v])continue;
            vis[v]=true;
            q.push(v);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%s",a[i]);
    }
    for(int x=0;x<n;++x){
        for(int y=0;y<m;++y){
            char c=a[x][y];
            int u=x*m+y;
            if(c=='S')s=u;
            if(c=='T')t=u;
            if(c=='#')continue;
            for(int d=0;d<4;++d){
                int i=x+dx[d],j=y+dy[d];
                if(!ok(c,d) || i<0 || i>=n || j<0 || j>=m)continue;
                if(a[i][j]=='#')continue;
                int v=i*m+j;
                g[u].push_back(v);
                h[v].push_back(u);
            }
        }
    }
    bfs(s,g,vis);
    if(!vis[t]){
        puts("I'm stuck!");
        return 0;
    }
    bfs(t,h,can);
    for(int u=0;u<n*m;++u){
        ans+=(vis[u] && !can[u]);
    }
    printf("%d\n",ans);
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201312/VALIDATION.md)
- [details.txt](../tests/201312/details.txt)
- [nightly-review-followup.json](../tests/201312/nightly-review-followup.json)
- [prose-final-review.json](../tests/201312/prose-final-review.json)
- [report.json](../tests/201312/report.json)
- [retained_oracles.py](../tests/201312/retained_oracles.py)
- [verify.py](../tests/201312/verify.py)

<!-- local-validation-attachments:end -->
