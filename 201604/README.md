---
title: "CSP 201604 五题题解"
contest: "201604"
contest_month: "2016-04"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "局部极值", "数组扫描", "碰撞检测", "网格模拟", "栈", "路径解析", "字符串", "BFS", "时间状态", "网格", "状态压缩", "连通性DP", "Steiner树", "轮廓线DP"]
status: "published"
problems: [{"id": "A", "title": "折点计数", "tags": ["局部极值", "数组扫描"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b059294e5d1fced2e45859f", "source_sha256": "27d88683255a5d09be05ffc2bcf1f18fe671e1dd572d1763fbc9f542f698ff65", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:37:23.562827+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addad4c74ace1cba9a20424"}}, {"id": "B", "title": "俄罗斯方块", "tags": ["碰撞检测", "网格模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b059315e5d1fced2e45874f", "source_sha256": "12fd5ff0d46471dc167332d7ed78cedc2c2b7cf0c9838a24e915832540603d96", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:38:31.895765+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addaddf74ace1cba9a20472"}}, {"id": "C", "title": "路径解析", "tags": ["栈", "路径解析", "字符串"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604C/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b059359e5d1fced2e458859", "source_sha256": "28f32713b74769230bb19018acabc706552366946bc4350d74c9409bb2da91eb", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:39:44.939165+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addae9574ace1cba9a2058d"}}, {"id": "D", "title": "游戏", "tags": ["BFS", "时间状态", "网格"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0593a2e5d1fced2e458989", "source_sha256": "4cfb2a6bcf223cb1e9fb3d9d58d2baa399b6c95cb6709810117d30e73e9b1191", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:40:37.441372+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addaf1b74ace1cba9a20648"}}, {"id": "E", "title": "网络连接", "tags": ["状态压缩", "连通性DP", "Steiner树", "轮廓线DP"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201604E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201604E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0593dfe5d1fced2e458a3f", "source_sha256": "82f9682e208f9618d97df7b7cc755db4d8aa82121dd31fbb04fe2a27b43bfd0d", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T13:41:46.756219+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb00e74ace1cba9a206db"}}]
---

# CSP 201604 五题题解

[原页面](https://code92007.github.io/csp/#/contest/201604) · [验证记录](../tests/201604/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 折点计数

标签：`局部极值` · `数组扫描`

本地：63 组优化版、63 组 UBSan 验证通过，详见 [验证记录](../tests/201604/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059294e5d1fced2e45859f)。

<!-- refactor-online:A:end -->

### 题意

给定连续 $n$ 天的销售量，统计由增长转为减少、或由减少转为增长的折点。首尾没有两侧邻居，不计为折点。

输入 $n$ 和 $n$ 个销售量。$1\le n\le1000$，销售量在 $[0,10^4]$ 内，保证相邻两天不同。

输出折点总数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604A)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604A/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addad4c74ace1cba9a20424)（accepted，100 分；复刻评测）。

### 题解

扫描除首尾之外的每个位置：严格大于左右两项时为峰，严格小于左右两项时为谷，满足任一条件就计数。

**正确性**

峰对应增长转减少，谷对应减少转增长。这两种情况覆盖所有折点，且互不重叠。$n<3$ 时循环为空，答案自然为零。

**复杂度**

时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,a[N],ans;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n-1;++i){
        bool up=(a[i]>a[i-1] && a[i]>a[i+1]);
        bool down=(a[i]<a[i-1] && a[i]<a[i+1]);
        ans+=(up || down);
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 俄罗斯方块

标签：`碰撞检测` · `网格模拟`

本地：101 组优化版、101 组 UBSan 验证通过，详见 [验证记录](../tests/201604/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059315e5d1fced2e45874f)。

<!-- refactor-online:B:end -->

### 题意

给定 $15\times10$ 棋盘、一个 $4\times4$ 板块图案及它的水平位置。板块沿竖直方向下落，遇到已有方块或底边时停下，求放置后的棋盘，不执行消行。

输入棋盘的 $15$ 行、图案的 $4$ 行，最后输入图案左边所在列。格子用 $0,1$ 表示，图案有四个实心格；棋盘前四行为空，起点及水平位置合法。

输出放置后的 $15$ 行棋盘。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604B)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604B/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addaddf74ace1cba9a20472)（accepted，100 分；复刻评测）。

### 题解

提取图案中实心格的相对坐标。假设图案顶端位于 `top`，检查每个实心格是否在棋盘内，且不与已有方块重叠。只要 `top+1` 合法就继续下落，否则将当前位置的实心格写入棋盘。

图案中的空白边也属于输入定位的一部分，不能删掉空白列后仍沿用原列号。

**正确性**

初始位置合法，循环逐行模拟下落。停止时当前位置合法、下一位置发生碰撞，恰好是题目要求的终态。

**复杂度**

棋盘与板块大小固定，时间、额外空间均为 $O(1)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=15,M=10,K=4,L=16;
int a[N][M],col,top,cnt;
P b[L];
bool check(int x){
    for(int i=0;i<cnt;++i){
        int r=x+b[i].first,c=col+b[i].second;
        if(r>=N || a[r][c])return false;
    }
    return true;
}
int main(){
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<K;++i){
        for(int j=0,x;j<K;++j){
            scanf("%d",&x);
            if(x)b[cnt++]=P(i,j);
        }
    }
    scanf("%d",&col);
    --col;
    while(check(top+1)){
        ++top;
    }
    for(int i=0;i<cnt;++i){
        a[top+b[i].first][col+b[i].second]=1;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            printf("%d%c",a[i][j],j==M-1?'\n':' ');
        }
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 路径解析

标签：`栈` · `路径解析` · `字符串`

本地：102 组优化版、102 组 UBSan 验证通过，详见 [验证记录](../tests/201604/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b059359e5d1fced2e458859)。

<!-- refactor-online:C:end -->

### 题意

给定正规化的当前目录，将若干绝对或相对路径转换成正规绝对路径。忽略重复斜杠和 `.`，`..` 返回父目录但不能越过根；空路径表示当前目录。结果末尾不留斜杠，根目录 `/` 除外。

输入路径数 $1\le n\le10$、当前目录，再逐行输入待处理路径。名字可含字母、数字、点、减号和下划线，目录间用斜杠分隔；单条路径长度不超过 $1000$，待处理路径可以为空。

每条路径输出一行正规化结果。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604C)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604C/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addae9574ace1cba9a2058d)（accepted，100 分；复刻评测）。

### 题解

按斜杠分割路径，用字符串栈保存目录名。绝对路径从空栈开始，相对路径先放入当前目录的各部分，然后依次处理：

- 空片段或 `.`：忽略。
- `..`：栈非空时弹出栈顶，否则仍停留在根目录。
- 其他名字：压入栈中。

最后在各个目录名前输出斜杠，空栈则输出 `/`。`...`、`a..` 等都是普通名字，不能直接删除所有点号。

**正确性**

处理任意前缀后，栈始终保存该前缀所指位置从根出发的目录链。各项操作分别对应保持位置、返回上层和进入下层，因此输出与原路径等价，且符合正规形式。

**复杂度**

设当前目录及单条路径的总长度为 $L$，每次处理时间、空间均为 $O(L)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n;
char s[N];
vector<string> parse(const string &s,vector<string> a={}){
    istringstream in(s);
    string t;
    while(getline(in,t,'/')){
        if(t.empty() || t==".")continue;
        if(t==".."){
            if(!a.empty())a.pop_back();
        }
        else a.push_back(t);
    }
    return a;
}
int main(){
    scanf("%d%s",&n,s);
    vector<string> base=parse(s);
    fgets(s,N,stdin);
    while(n--){
        fgets(s,N,stdin);
        s[strcspn(s,"\r\n")]=0;
        vector<string> a;
        if(s[0]!='/')a=base;
        a=parse(s,a);
        if(a.empty())putchar('/');
        for(string &t:a){
            printf("/%s",t.c_str());
        }
        puts("");
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 游戏

标签：`BFS` · `时间状态` · `网格`

本地：96 组优化版、96 组 UBSan 验证通过，详见 [验证记录](../tests/201604/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0593a2e5d1fced2e458989)。

<!-- refactor-online:D:end -->

### 题意

从 $n\times m$ 网格的左上角出发，求最早到达右下角的时刻。每秒必须向上、下、左、右移动一格，不能原地等待。部分格子在指定闭区间内危险，不能在危险时刻进入。

输入 `n m k`，再输入 $k$ 行危险格子的行、列及时间区间 $[a,b]$。$n,m\le100$，$b\le100$，保证终点可达。

输出最早到达时刻。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604D)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604D/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addaf1b74ace1cba9a20648)（accepted，100 分；复刻评测）。

### 题解

同一位置在不同时刻，后续能走的方向可能不同，因此 BFS 状态应为“位置、时刻”，不能每个格子只访问一次。初态为左上角、时刻零；从时刻 $t$ 只转移到时刻 $t+1$ 的四个邻格，检查边界及危险区间。

**限制时间维的长度**

设最晚危险结束于 $B$。取一条保证存在的成功路线：若在 $B$ 前到达则无需继续；否则取其 $B$ 时刻的位置，此后所有格子都安全，至多再走 $n+m-2$ 步即可到终点。因此保留到 $B+n+m$ 足够。

**正确性**

每条转移恰好耗时一秒，BFS 首次取出终点状态时，得到最短到达时间。代码只允许走向邻格；为了消耗时间，可以在安全格子间往返，但没有原地等待的转移。

**复杂度**

时间、空间均为 $O(nm(B+n+m))$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=110,M=310,K=4;
const int dx[K]={1,-1,0,0},dy[K]={0,0,1,-1};
int n,m,k,l[N][N],r[N][N],last,q[M*N*N],head,tail;
bool vis[M][N][N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0,x,y,a,b;i<k;++i){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        --x,--y;
        l[x][y]=a,r[x][y]=b;
        last=max(last,b);
    }
    q[tail++]=0;
    vis[0][0][0]=1;
    int lim=last+n+m;
    while(head<tail){
        int v=q[head++],t=v/(n*m),u=v%(n*m);
        int x=u/m,y=u%m;
        if(x==n-1 && y==m-1){
            printf("%d\n",t);
            return 0;
        }
        if(t==lim)continue;
        for(int d=0;d<K;++d){
            int a=x+dx[d],b=y+dy[d];
            if(a<0 || a>=n || b<0 || b>=m)continue;
            if(l[a][b]<=t+1 && t+1<=r[a][b])continue;
            if(vis[t+1][a][b])continue;
            vis[t+1][a][b]=1;
            q[tail++]=(t+1)*n*m+a*m+b;
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 网络连接

标签：`状态压缩` · `连通性DP` · `Steiner树` · `轮廓线DP`

本地：189 组优化版、189 组 UBSan 验证通过，详见 [验证记录](../tests/201604/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0593dfe5d1fced2e458a3f)。

<!-- refactor-online:E:end -->

### 题意

有 $n$ 台设备，其中一些是必须两两连通的用户设备。可以选用其他设备作为中转，并从候选边中选择连线，求连接所有用户设备的最小总费用。每条候选边的端点编号之差不超过 $p$，边费非负。

输入测试组数 $T\le5$；每组输入 `n m p`、长度为 $n$ 的终端标记 01 串，以及 $m$ 条边 `u v w`。$n\le500$，$p\le6$，$0\le w\le10^6$；终端至少两个，任意两点间最多一条候选边，保证有解。

每组输出一行最小费用。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201604E)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201604E/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addb00e74ace1cba9a206db)（accepted，100 分；复刻评测）。

### 题解

终端数可能很多，不适合按终端子集做 Steiner Tree DP。本题可利用的是边的编号跨度很小：从左到右处理设备，在处理 $i$ 前，只需要记录窗口 $i,\ldots,i+p-1$，更早的设备不会直接连向更远的未来。

**记录窗口内的连通关系**

每个位置用 $0$ 表示未选中，非零标签表示它所属的连通块。按标签首次出现的顺序重新编号，使同一种分区只有一种编码。窗口最多六个位置，连同空位，状态数不超过 $\operatorname{Bell}(7)=877$。

处理设备 $i$ 时，枚举它到后方 $p$ 个位置的出边子集，加入费用、合并连通块，再忘掉最左端点并右移窗口。终端必须已经被选中，或通过本次出边加入；非终端可以完全跳过。不存在的边不能选择。

**检查消失的连通块**

若忘掉 $i$ 后，它所属连通块在窗口中不再有代表，该块以后就无法连接其他点。只有它是唯一连通块，且全部终端都已处理时，才能将其作为完整答案结束；其他情况丢弃。

即使消失的块不含终端，也可以丢弃该方案：费用非负，最优方案总能删去不连接终端的多余分量。不能简单把最后的空状态当成成功，否则会混入从未连接终端的方案。

**预计算转移**

先枚举规范状态，预计算每个状态与出边子集对应的新状态，或“不合法”“完整关闭”两种结果。每组数据再按实际存在的边枚举子集费用，进行最小值 DP。每组重新初始化状态编号、边表和 DP，保留 `dp[0]=0`。

**正确性**

窗口保存过去与未来间所有可能连接的接口，分区足以描述后续合并，关闭规则保证不留下孤立终端。每条边只在较小端点处决策一次，累计费用恰好等于所选网络费用。枚举覆盖全部可能的连通方案，取最小值即为答案。

**复杂度**

记状态数为 $s\le877$，主体时间 $O(ns2^p)$，预计算 $O(s2^p p^2)$，空间 $O(s2^p+np)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,K=7,M=64,V=900,H=1<<18;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int T,n,m,p,cnt,last,w[N][K],code[V],id[H],tr[V][M];
int fa[K],on[K],lab[K];
ll dp[V],ndp[V];
char s[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    fa[find(x)]=find(y);
}
void init(){
    memset(id,-1,sizeof id);
    cnt=1;code[0]=0;id[0]=0;
    for(int u=0;u<cnt;++u){
        int c=code[u];
        for(int S=0;S<(1<<p);++S){
            iota(fa,fa+K,0);
            memset(on,0,sizeof on);
            memset(lab,0,sizeof lab);
            for(int i=0;i<p;++i){
                int v=(c>>(i*3))&7;
                on[i]=(v!=0);
                if(!v)continue;
                for(int j=0;j<i;++j){
                    if(((c>>(j*3))&7)==v)merge(i,j);
                }
            }
            for(int j=0;j<p;++j){
                if((S>>j)&1){
                    on[0]=on[j+1]=1;
                    merge(0,j+1);
                }
            }
            if(on[0]){
                bool stay=0,other=0;
                for(int j=1;j<=p;++j){
                    if(!on[j])continue;
                    if(find(j)==find(0))stay=1;
                    else other=1;
                }
                if(!stay){
                    tr[u][S]=other?-1:-2;
                    continue;
                }
            }
            int num=0,v=0;
            for(int j=1;j<=p;++j){
                if(!on[j])continue;
                int r=find(j);
                if(!lab[r])lab[r]=++num;
                v|=lab[r]<<(3*(j-1));
            }
            if(id[v]<0){
                id[v]=cnt;
                code[cnt++]=v;
            }
            tr[u][S]=id[v];
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%s",&n,&m,&p,s);
        last=0;
        for(int i=0;i<n;++i){
            if(s[i]=='1')last=i;
        }
        memset(w,-1,sizeof w);
        for(int i=0,u,v,c;i<m;++i){
            scanf("%d%d%d",&u,&v,&c);
            w[u-1][v-u-1]=c;
        }
        init();
        memset(dp,(int)INF,sizeof dp);
        dp[0]=0;
        ll ans=INF;
        for(int i=0;i<n;++i){
            memset(ndp,(int)INF,sizeof ndp);
            int S=0;
            for(int j=0;j<p;++j){
                if(w[i][j]>=0)S|=1<<j;
            }
            for(int b=S;;b=(b-1)&S){
                ll sum=0;
                for(int j=0;j<p;++j){
                    if((b>>j)&1)sum+=w[i][j];
                }
                for(int u=0;u<cnt;++u){
                    if(dp[u]==INF)continue;
                    if(s[i]=='1' && !(code[u]&7) && !b)continue;
                    int v=tr[u][b];
                    if(v==-2){
                        if(i>=last)ans=min(ans,dp[u]+sum);
                    }
                    else if(v>=0)ndp[v]=min(ndp[v],dp[u]+sum);
                }
                if(!b)break;
            }
            copy(ndp,ndp+cnt,dp);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201604/VALIDATION.md)
- [cases.json](../tests/201604/cases.json)
- [compile.json](../tests/201604/compile.json)
- [current-sources.json](../tests/201604/current-sources.json)
- [dsu-followup.json](../tests/201604/dsu-followup.json)
- [extra.py](../tests/201604/extra.py)
- [online-update-report.json](../tests/201604/online-update-report.json)
- [online-verdicts.json](../tests/201604/online-verdicts.json)
- [summary.json](../tests/201604/summary.json)

<!-- local-validation-attachments:end -->
