---
title: "CSP 202305 五题题解"
contest: "202305"
contest_month: "2023-05"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "字符串", "频率统计", "矩阵乘法", "结合律", "复杂度优化", "字节解析", "解压缩", "位运算", "图论", "树形DP", "变量消元", "枚举", "状态压缩", "最短路", "Dijkstra", "SOS DP"]
status: "published"
problems: [{"id": "A", "title": "重复局面", "tags": ["字符串", "频率统计"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16667"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0562cae5d1fced2e4517d5", "source_sha256": "cf469ba06e4fcf69f36739059d8813f8a687b8238017030be00322c08f063b5a", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:11:40.673549+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305838806", "source_sha256": "ba3d4be762cf3243170222999ceb6d7dd7daaa79baca9ff90269d30011e138c8"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d0a67df0b81749be5a"}}, {"id": "B", "title": "矩阵运算", "tags": ["矩阵乘法", "结合律", "复杂度优化"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16668"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b056336e5d1fced2e4518e7", "source_sha256": "aaa4eda6f66102f27861a8bce3e279db42d0c0f5d35271ea5dfa1c8a5be14477", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:14:27.197060+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305839266", "source_sha256": "6134c6c0bde54dc73bdf25dda099a587acc970cd484eb82c419496d6b379edd2"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d2a67df0b81749be67"}}, {"id": "C", "title": "解压缩", "tags": ["字节解析", "解压缩", "位运算"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16669"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05638ee5d1fced2e4519f7", "source_sha256": "e6772cbcb6503ca3c3c3b84f4a7f3111231e1435f584e6b2709a583138302bc2", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:14:53.732260+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305839556", "source_sha256": "6d341d5fcc167d14be201984db5b923b0919c1139cf6afe94beb0b87759d1b2f"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d4a67df0b81749be76"}}, {"id": "D", "title": "电力网络", "tags": ["图论", "树形DP", "变量消元", "枚举"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16670"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0563eee5d1fced2e451a95", "source_sha256": "24b806a5a2dcf465c54404ff0bfe23a090b2461fd9184f738602fda7ef28f1ec", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:16:40.247361+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305916957", "source_sha256": "829f3795e6aa8ac84fc225ae3ebdd072531b41c1b5c781fdb6c8f9fc25322b96"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d5a67df0b81749be85"}}, {"id": "E", "title": "闪耀巡航", "tags": ["状态压缩", "最短路", "Dijkstra", "SOS DP"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202305E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16671"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05644fe5d1fced2e451b76", "source_sha256": "6e1d292cd7725bb031fd47b1cef08670b2c3725e6e9ef023318fe215168dd41c", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:18:12.473679+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305917627", "source_sha256": "52b83a2ead5ce02693c2a67654fc6754c208fca306e93d0374608e8ace3b00da"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8d7a67df0b81749be8f"}}]
---

# CSP 202305 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202305/VALIDATION.md)

<a id="problem-a"></a>

## A. 重复局面

标签：`字符串` · `频率统计`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce8d0a67df0b81749be5a)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305838806)。重构版本地验证见 [VALIDATION.md](../tests/202305/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0562cae5d1fced2e4517d5)。

<!-- refactor-online:A:end -->

### 题意

按时间顺序给出若干 $8\times8$ 棋盘局面。只有 64 个对应字符全部相同，才视为同一局面；求每个局面到当前为止出现了多少次。

输入局面数 $n$，再依次输入每个棋盘的 8 行字符。不需要判断任何国际象棋走子规则。

每个局面输出一个整数，表示这是它第几次出现。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305A) · [公开题面存档](https://www.luogu.com.cn/problem/P16667)。

### 题解

把每局 8 行按固定顺序拼成 64 字符字符串，作为哈希表键，计数先加一再输出。

固定行宽使拼接可唯一还原棋盘，因此键相等当且仅当局面相等。哈希表会对完整字符串进行相等比较，不是只比较一个可能碰撞的摘要。期望时间 $O(64n)$，空间为不同局面的总长度，不涉及国际象棋规则。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=8,M=10;
int n;
char s[M];
unordered_map<string,int> cnt;
int main(){
    scanf("%d",&n);
    while(n--){
        string t;
        for(int i=0;i<N;++i){
            scanf("%s",s);
            t+=s;
        }
        printf("%d\n",++cnt[t]);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 矩阵运算

标签：`矩阵乘法` · `结合律` · `复杂度优化`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce8d2a67df0b81749be67)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305839266)。重构版本地验证见 [VALIDATION.md](../tests/202305/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b056336e5d1fced2e4518e7)。

<!-- refactor-online:B:end -->

### 题意

给定 $n\times d$ 矩阵 $Q,K,V$，以及为每行提供权重的向量 $W$，计算 $(W\cdot(QK^T))V$，其中 $W\cdot A$ 表示将 $A$ 的第 $i$ 行乘以 $W_i$。

输入 $n,d$，再输入矩阵 $Q,K,V$ 和向量 $W$。$n\le10000$、$d\le20$，元素绝对值不超过 1000。

输出计算得到的 $n\times d$ 整数矩阵。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305B) · [公开题面存档](https://www.luogu.com.cn/problem/P16668)。

### 题解

不要显式构造 n×n 的 QKᵀ。W 对整行缩放，可以放到最后；利用矩阵乘法结合律，先算 d×d 的 T=KᵀV（代码中存入 `a`），再算 QT，最后把第 i 行乘 W[i]。

展开目标元素可得 `W[i]*Σ_a Q[i][a]*Σ_j K[j][a]*V[j][b]`，交换求和次序正是此算法，因此变形等价。

两次乘法均只需 $O(nd^2)$，空间 $O(nd+d^2)$。最终绝对值上界 $n d\times1000^4\le2\times10^{17}$，需要64位，并确保中间乘法也在64位中进行。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000+10,M=25;
int n,d;
ll q[N][M],k[N][M],v[N][M],w[N],a[M][M];
int main(){
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;++i){
        for(int j=0;j<d;++j){
            scanf("%lld",&q[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<d;++j){
            scanf("%lld",&k[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<d;++j){
            scanf("%lld",&v[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&w[i]);
    }
    for(int i=0;i<n;++i){
        for(int x=0;x<d;++x){
            for(int y=0;y<d;++y){
                a[x][y]+=k[i][x]*v[i][y];
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int y=0;y<d;++y){
            ll sum=0;
            for(int x=0;x<d;++x){
                sum+=q[i][x]*a[x][y];
            }
            printf("%lld%c",sum*w[i],y==d-1?'\n':' ');
        }
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 解压缩

标签：`字节解析` · `解压缩` · `位运算`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce8d4a67df0b81749be76)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305839556)。重构版本地验证见 [VALIDATION.md](../tests/202305/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05638ee5d1fced2e4519f7)。

<!-- refactor-online:C:end -->

### 题意

给定 Snappy 风格压缩字节流，按规则解压。流开头用低 7 位、低位组在前的变长整数表示原始长度，后面由字面量片段与向前引用片段组成。

输入压缩字节数 $S$，再输入这些字节的十六进制表示。压缩与解压长度均不超过约 2 MiB，输入保证合法，不出现类型 3 的片段。

输出原始数据的小写十六进制表示，每行最多 8 字节；换行不属于原始数据。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305C) · [公开题面存档](https://www.luogu.com.cn/problem/P16669)。

### 题解

先把十六进制两个字符还原成一个字节，用指针依次读取。标记字节用 `x` 表示，低两位决定类型。 类型 0 的高六位小于 60 时，长度等于它加 1；否则接下来的“高六位减 59”个字节按小端拼成长度减 1，再复制对应字面量。

类型 1 的长度是 `((x>>2)&7)+4`，偏移为标记最高三位拼接下一字节；类型 2 的长度为 `(x>>2)+1`，偏移由后两字节按小端读取。题目不出现类型 3。

向前引用必须逐字节执行 `b.push_back(b[b.size()-off])`。 例如已有 a、偏移 1、复制 5 字节，应得到六个 a；新增字节可以继续被当前引用读取，所以不能只复制一次固定的旧区间。

每个片段的解码与编码规则互逆，按流顺序归纳即可还原全文。时间 $O(S+U)$，空间 $O(S+U)$，S 为压缩字节数、U 为解压字节数；输出的换行只作用于显示，不属于原数据。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,p;
vector<unsigned char> a,b;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        unsigned x;
        scanf("%2x",&x);
        a.push_back(x);
    }
    int len=0,k=0;
    while(true){
        int x=a[p++];
        len|=(x&127)<<k;
        if(!(x&128))break;
        k+=7;
    }
    b.reserve(len);
    while(p<n){
        int x=a[p++],op=x&3,len,off;
        if(!op){
            len=x>>2;
            if(len<60)++len;
            else{
                int cnt=len-59;
                len=0;
                for(int j=0;j<cnt;++j){
                    len|=int(a[p++])<<(8*j);
                }
                ++len;
            }
            for(int j=0;j<len;++j){
                b.push_back(a[p++]);
            }
        }
        else{
            if(op==1){
                len=((x>>2)&7)+4;
                off=((x>>5)<<8)|a[p++];
            }
            else{
                len=(x>>2)+1;
                off=a[p++];
                off|=int(a[p++])<<8;
            }
            for(int j=0;j<len;++j){
                b.push_back(b[b.size()-off]);
            }
        }
    }
    for(int i=0;i<(int)b.size();++i){
        printf("%02x",b[i]);
        if(i%8==7 || i+1==(int)b.size())puts("");
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 电力网络

标签：`图论` · `树形DP` · `变量消元` · `枚举`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce8d5a67df0b81749be85)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305916957)。重构版本地验证见 [VALIDATION.md](../tests/202305/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0563eee5d1fced2e451a95)。

<!-- refactor-online:D:end -->

### 题意

有 $N$ 个城镇，每个城镇从 $K$ 个地址中选一个建设变电站。每个地址有建设成本，每条给定无向边也有一个 $K\times K$ 费用矩阵，费用取决于两端的选址。求点成本与边成本总和的最小值。

输入 $N,M,K$、各点的选址成本，以及 $M$ 条边的端点和费用矩阵。城镇编号从 0 开始，$N\le10^4$、$K\le10$。各类数据分别保证是小图、树、单环图、删去某点后为树的特定图，或度数大于 2 的点不超过 6 个。

输出最小总成本。边矩阵可以不对称，必须对应输入给定的端点顺序。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305D) · [公开题面存档](https://www.luogu.com.cn/problem/P16670)。

### 题解

这是带点费用的标签分配问题，一般图不能直接用树形 DP。实现按题目提供的结构统一处理两类情况。

**第一类：存在一个点，删掉后剩下森林**

固定该点的选址为 $s$，把它与各邻居的边费用加到邻居的点费用中，剩下每棵树做

$$dp_u[x]=cost_u[x]+\sum_{v\text{ 为子节点}}\min_y\bigl(dp_v[y]+edge_{uv}[x][y]\bigr).$$

枚举被固定点的 $K$ 个地址，取最小值。树、单环图和题目的“删点成树”子任务都属于这一类。

不必逐点删图来试。连通无向图删去点 $u$ 后，剩余图有 $c_u$ 个连通分量，其独立环数为 $M-N+1-\deg(u)+c_u$。 用一次 low-link DFS 求各点删除后的分量数，找到该表达式为 0 的点即可。 DFS 迭代执行，避免深树爆栈。

**第二类：压缩度数不超过 2 的点**

若找不到上述点，把低度点逐个消去，始终保留等价的点费用和边费用。 孤立点取最便宜选址加入常数；叶子 $u$ 对每种邻居选址独立取最小值，并加到邻居点费用；度为 2 的 $u$，邻居为 $v,w$，生成新边费用

$$new[x][y]=\min_z\bigl(edge_{vu}[x][z]+cost_u[z]+edge_{uw}[z][y]\bigr).$$

若 $v,w$ 原本已有边，两份费用相加。每次消元都是在固定剩余变量时，对被消去变量精确求最小值，所以不改变最优答案。 消元不会增加邻居的度数。最后一类数据至多留下原先那 6 个高度点；小图也至多剩 6 点。 直接枚举核心所有选址，累加点边费用即可。

第一类时间 $O(KM+NK^3)$ 的保守界（每个固定选址做一次树形 DP），空间 $O(MK^2+NK)$；第二类消元 $O(NK^3)$，核心枚举 $O(K^h h^2)$、$h\le6$。代码保存边的两个方向时转置矩阵，不能把非对称费用矩阵当成对称矩阵。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> V;
const int N=10010;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m,k,dfn[N],low[N],fa[N],cnt[N],sep[N],st[N];
int ord[N],label[N],top,tot;
bool del[N];
queue<int> q;
map<int,V>::iterator it[N];
V cost;
vector<map<int,V>> g;
vector<int> core;
ll ans=INF;
void connect(int u,int v,const V &a){
    V b(k,vector<ll>(k));
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            b[j][i]=a[i][j];
        }
    }
    g[u][v]=a;
    g[v][u]=b;
}
int check(){
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
    memset(fa,-1,sizeof fa);
    memset(cnt,0,sizeof cnt);
    memset(sep,0,sizeof sep);
    top=tot=0;
    st[++top]=0;
    dfn[0]=low[0]=++tot;
    it[0]=g[0].begin();
    while(top){
        int u=st[top];
        if(it[u]==g[u].end()){
            --top;
            if(fa[u]!=-1){
                int p=fa[u];
                low[p]=min(low[p],low[u]);
                if(low[u]>=dfn[p])++sep[p];
            }
            continue;
        }
        int v=(it[u]++)->first;
        if(v==fa[u])continue;
        if(dfn[v])low[u]=min(low[u],dfn[v]);
        else{
            fa[v]=u;
            ++cnt[u];
            dfn[v]=low[v]=++tot;
            it[v]=g[v].begin();
            st[++top]=v;
        }
    }
    for(int u=0;u<n;++u){
        int cnts=fa[u]==-1?cnt[u]:sep[u]+1;
        if(m-n+1-(int)g[u].size()+cnts==0)return u;
    }
    return -1;
}
ll solve(int root){
    fill(fa,fa+n,-2);
    int num=0;
    fa[root]=-1;
    for(int s=0;s<n;++s){
        if(fa[s]!=-2)continue;
        fa[s]=-1;
        ord[num++]=s;
        for(int i=num-1;i<num;++i){
            int u=ord[i];
            for(auto &[v,a]:g[u]){
                if(fa[v]!=-2)continue;
                fa[v]=u;
                ord[num++]=v;
            }
        }
    }
    ll ans=INF;
    for(int s=0;s<k;++s){
        V dp=cost;
        for(auto &[u,a]:g[root]){
            for(int x=0;x<k;++x){
                dp[u][x]+=a[s][x];
            }
        }
        ll sum=cost[root][s];
        for(int i=num-1;i>=0;--i){
            int u=ord[i],p=fa[u];
            if(p==-1){
                sum+=*min_element(dp[u].begin(),dp[u].end());
                continue;
            }
            auto &a=g[p].at(u);
            for(int x=0;x<k;++x){
                ll best=INF;
                for(int y=0;y<k;++y){
                    best=min(best,a[x][y]+dp[u][y]);
                }
                dp[p][x]+=best;
            }
        }
        ans=min(ans,sum);
    }
    return ans;
}
void dfs(int i,ll val){
    if(val>=ans)return;
    if(i==(int)core.size()){
        ans=val;
        return;
    }
    int u=core[i];
    for(int x=0;x<k;++x){
        ll sum=val+cost[u][x];
        for(int j=0;j<i;++j){
            int v=core[j];
            if(g[u].count(v))sum+=g[u].at(v)[x][label[v]];
        }
        label[u]=x;
        dfs(i+1,sum);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    cost=V(n,vector<ll>(k));
    g.resize(n);
    for(auto &row:cost){
        for(ll &x:row){
            scanf("%lld",&x);
        }
    }
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        V a(k,vector<ll>(k));
        for(auto &row:a){
            for(ll &x:row){
                scanf("%lld",&x);
            }
        }
        connect(u,v,a);
    }
    int root=check();
    if(root!=-1){
        printf("%lld\n",solve(root));
        return 0;
    }
    memset(del,0,sizeof del);
    for(int u=0;u<n;++u){
        if(g[u].size()<=2)q.push(u);
    }
    ll sum=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(del[u] || g[u].size()>2)continue;
        del[u]=true;
        if(g[u].empty()){
            sum+=*min_element(cost[u].begin(),cost[u].end());
            continue;
        }
        int v=g[u].begin()->first;
        if(g[u].size()==1){
            auto &a=g[v].at(u);
            for(int x=0;x<k;++x){
                ll best=INF;
                for(int y=0;y<k;++y){
                    best=min(best,a[x][y]+cost[u][y]);
                }
                cost[v][x]+=best;
            }
            g[v].erase(u);
            q.push(v);
        }
        else{
            int w=next(g[u].begin())->first;
            auto &a=g[v].at(u),&b=g[u].at(w);
            V c(k,vector<ll>(k,INF));
            for(int x=0;x<k;++x){
                for(int y=0;y<k;++y){
                    for(int z=0;z<k;++z){
                        c[x][y]=min(c[x][y],a[x][z]+cost[u][z]+b[z][y]);
                    }
                    if(g[v].count(w))c[x][y]+=g[v].at(w)[x][y];
                }
            }
            g[v].erase(u);
            g[w].erase(u);
            connect(v,w,c);
            q.push(v);
            q.push(w);
        }
        g[u].clear();
    }
    for(int u=0;u<n;++u){
        if(!del[u])core.push_back(u);
    }
    dfs(0,sum);
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-e"></a>

## E. 闪耀巡航

标签：`状态压缩` · `最短路` · `Dijkstra` · `SOS DP`

原版评测：[曙梦 OJ 100 分 accepted](https://oj.shumeng.tech/record/6adce8d7a67df0b81749be8f)；[洛谷民间数据 100 分 Accepted](https://www.luogu.com.cn/record/305917627)。重构版本地验证见 [VALIDATION.md](../tests/202305/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05644fe5d1fced2e451b76)。

<!-- refactor-online:E:end -->

### 题意

每个小写字母串表示一条固定巡航线路，从首字母对应城市出发，在末字母城市结束，中间依次经过其余城市，长度为字符串长度减一。对每条线路，要求先完整乘坐它，再接若干条线路，最终回到这条线路的起点，并经过全部目标城市。

输入线路数、目标字母串和每条线路的字符串。目标字母互不相同，至多 10 个；城市只有 26 个小写字母。

按输入顺序输出每条线路对应的最短总长度，无解输出 $-1$。后半程允许为空，线路可以重复乘坐。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202305E) · [公开题面与样例](https://www.luogu.com.cn/problem/P16671)。

### 题解

**把一条线路压成一条带集合的有向边**

记录首字母 $u$、末字母 $v$、途中目标城市集合 $S$、长度 $w$。 城市只有 26 个，目标集合用至多 10 位二进制表示。 即使首尾相同，线路也可能收集新目标，不能删除自环。

状态 $(u,S)$ 表示当前在城市 $u$，已收集目标集合 $S$。 经过线路 $(u,v,M,w)$，转移到 $(v,S\cup M)$，代价增加 $w$。边权非负，运行 Dijkstra。 分别以 26 个城市为起点预处理，得到各起终点和目标集合的最短距离，保存在 `dis` 中。

对于必须先乘坐的线路 $(u,v,M,w)$，后半程从 $v$ 出发回到 $u$，只需补齐 $\overline M$。 对每个起终点做一次超集最小值 SOS DP，使 `need[S]` 表示至少包含 $S$ 的最短距离；代码直接更新 `dis`，不另开 `need` 数组。 答案即 $w+need[v][u][\overline M]$。后半程可以为空；完整第一段已经满足条件的闭合线路自然会得到其自身长度。

**压缩重复边**

相同首尾和集合只保留最短长度。如果存在相同首尾、集合更大、长度不增的线路，则原边被支配，可以删去。利用超集最小值快速检查支配关系。删边不会降低任何后续可行性，也不会增加代价。

**正确性**

任意合法巡航唯一对应状态图中的一条游走；反之，每个状态转移都代表完整乘坐一条允许线路。固定第一段后，余下要求恰好是终点和缺失集合，因此最短路与超集查询给出最优值。

**复杂度**

设压缩后边数为 $E$、目标数为 $k$。每次最短路有 $26\cdot2^k$ 个状态，最坏扫描 $E2^k$ 条状态边；总时间约为 $O(26E2^k\log(26\cdot2^k)+26^2k2^k)$，空间 $O(26^2 2^k+E)$。 支配删边能减少实际扫描量，但不应把它当作改变最坏复杂度的保证；极限密集数据仍需关注时限。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=26,M=15,INF=0x3f3f3f3f;
struct edge{
    int u,v,s,w;
};
int n,k,m,id[N];
char t[M];
vector<edge> a,g[N];
vector<int> best,dis[N];
priority_queue<P,vector<P>,greater<P>> q;
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
int main(){
    scanf("%d%s",&n,t);
    k=strlen(t);
    m=1<<k;
    memset(id,-1,sizeof id);
    for(int i=0;i<k;++i){
        id[t[i]-'a']=i;
    }
    best.assign(N*N*m,INF);
    for(int i=0;i<n;++i){
        string s=read();
        edge e={s.front()-'a',s.back()-'a',0,(int)s.size()-1};
        for(char &c:s){
            if(id[c-'a']>=0)e.s|=1<<id[c-'a'];
        }
        int &v=best[(e.u*N+e.v)*m+e.s];
        v=min(v,e.w);
        a.push_back(e);
    }
    for(int u=0;u<N;++u){
        for(int v=0;v<N;++v){
            vector<int> sup(m);
            for(int s=0;s<m;++s){
                sup[s]=best[(u*N+v)*m+s];
            }
            for(int b=0;b<k;++b){
                for(int s=0;s<m;++s){
                    if(!(s>>b&1))sup[s]=min(sup[s],sup[s|(1<<b)]);
                }
            }
            for(int s=0;s<m;++s){
                int w=best[(u*N+v)*m+s];
                if(w==INF)continue;
                bool ok=true;
                for(int b=0;b<k;++b){
                    if(!(s>>b&1) && sup[s|(1<<b)]<=w)ok=false;
                }
                if(ok)g[u].push_back({u,v,s,w});
            }
        }
    }
    for(int start=0;start<N;++start){
        auto &d=dis[start];
        d.assign(N*m,INF);
        d[start*m]=0;
        q.push({0,start*m});
        while(!q.empty()){
            auto [val,x]=q.top();
            q.pop();
            if(val!=d[x])continue;
            int u=x/m,s=x%m;
            for(auto &e:g[u]){
                int v=e.v*m+(s|e.s);
                if(val+e.w<d[v]){
                    d[v]=val+e.w;
                    q.push({d[v],v});
                }
            }
        }
        for(int v=0;v<N;++v){
            for(int b=0;b<k;++b){
                for(int s=0;s<m;++s){
                    if(s>>b&1)continue;
                    int x=v*m+s,y=v*m+(s|(1<<b));
                    d[x]=min(d[x],d[y]);
                }
            }
        }
    }
    for(auto &e:a){
        int d=dis[e.v][e.u*m+((m-1)^e.s)];
        printf("%d\n",d==INF?-1:d+e.w);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202305/VALIDATION.md)
- [details.txt](../tests/202305/details.txt)
- [global-storage-before.json](../tests/202305/global-storage-before.json)
- [global-storage-followup.json](../tests/202305/global-storage-followup.json)
- [nightly-review-followup.json](../tests/202305/nightly-review-followup.json)
- [online-update-report.json](../tests/202305/online-update-report.json)
- [online-verdicts.json](../tests/202305/online-verdicts.json)
- [prose-final-review.json](../tests/202305/prose-final-review.json)
- [report.json](../tests/202305/report.json)
- [retained_oracles.py](../tests/202305/retained_oracles.py)
- [verify-global-storage.py](../tests/202305/verify-global-storage.py)
- [verify.py](../tests/202305/verify.py)

<!-- local-validation-attachments:end -->
