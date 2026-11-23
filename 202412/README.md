---
title: "CSP 202412 五题题解"
contest: "202412"
contest_month: "2024-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "模拟", "边界判断", "前缀和", "前后缀最大值", "LRU", "链表", "哈希表", "BFS", "并查集", "区间遍历", "贪心", "单调栈"]
status: "published"
problems: [{"id": "A", "title": "移动", "tags": ["模拟", "边界判断"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "原版曙梦 OJ 100 分 Accepted（复刻评测）；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c2a67df0b81749b98e"}}, {"id": "B", "title": "梦境巡查", "tags": ["前缀和", "前后缀最大值"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "原版曙梦 OJ 100 分 Accepted（复刻评测）；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c3a67df0b81749b994"}}, {"id": "C", "title": "缓存模拟", "tags": ["LRU", "链表", "哈希表", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "原版曙梦 OJ 100 分 Accepted（复刻评测）；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c5a67df0b81749b99a"}}, {"id": "D", "title": "跳房子", "tags": ["BFS", "并查集", "区间遍历"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "原版曙梦 OJ 100 分 Accepted（复刻评测）；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c6a67df0b81749b99e"}}, {"id": "E", "title": "梦魔", "tags": ["贪心", "单调栈", "前缀和"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "原版曙梦 OJ 100 分 Accepted（复刻评测）；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202412E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202412E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7c9a67df0b81749b9c2"}}]
---

# CSP 202412 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202412/VALIDATION.md)

<a id="problem-a"></a>

## A. 移动

标签：`模拟` · `边界判断`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce7c2a67df0b81749b98e)。重构版本地验证见 [VALIDATION.md](../tests/202412/VALIDATION.md)，未重新提交在线评测。

### 题意

机器人在坐标均为 $1\ldots n$ 的方格场地上移动。指令 `f/b/l/r` 分别使 $y$ 加一、$y$ 减一、$x$ 减一、$x$ 加一；如果下一步出界，则忽略该指令。

输入场地大小 $n$ 与独立任务数 $k$，每个任务给出起点坐标及指令串。各任务从自己的起点出发，互不影响。

每个任务输出执行全部指令后的终点坐标。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412A/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202412A)。

### 题解

**逐步模拟**

每次只更新指令对应的坐标，再将它限制在 $[1,n]$ 内。由于一步只移动一格，出界时限制后的坐标恰好等于原坐标，等价于忽略该指令。

**正确性**

每次更新都准确对应题目的一步，逐步执行即可得到终点。不能只统计四个方向的净位移，因为被边界挡住的指令不会生效。

**复杂度**

时间为指令总长度，额外空间 $O(1)$。代码逐个读取指令字符，无需保存整个字符串。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,k,x,y;
int main(){
    scanf("%d%d",&n,&k);
    while(k--){
        scanf("%d%d",&x,&y);
        int c=getchar();
        while(isspace(c)){
            c=getchar();
        }
        while(c!=EOF && !isspace(c)){
            if(c=='f')y=min(n,y+1);
            else if(c=='b')y=max(1,y-1);
            else if(c=='l')x=max(1,x-1);
            else x=min(n,x+1);
            c=getchar();
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 梦境巡查

标签：`前缀和` · `前后缀最大值`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce7c3a67df0b81749b994)。重构版本地验证见 [VALIDATION.md](../tests/202412/VALIDATION.md)，未重新提交在线评测。

### 题意

依次经过地点 $0\ldots n$，再返回起点。离开地点 $i$ 消耗 $a_i$，到达地点 $i\ge1$ 时获得补给 $b_i$。对每个地点独立假设该处补给取消，求完成全程所需的最小初始能量，过程中能量不能为负。

输入 $n$、$a_0\ldots a_n$ 和 $b_1\ldots b_n$，$n\le10^5$。

依次输出取消每个地点补给后的最小初始能量。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412B/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202412B)。

### 题解

**把能量限制写成前缀最大值**

令 $c_j$ 表示支付离开地点 $j$ 的消耗后，累计支出减去已获得的补给。先付出 $a_0$，之后每到一个地点就加入 $a_j-b_j$，得到：

$$c_j=\sum_{t=0}^{j}a_t-\sum_{t=1}^{j}b_t.$$

初始能量必须不小于每个 $c_j$，所以未取消补给时，答案是全部 $c_j$ 的最大值。

**独立取消一次补给**

取消 $b_i$ 不影响 $j<i$ 的限制，却使全部 $j\ge i$ 的限制增加 $b_i$。用 `pre`、`suf` 保存 $c$ 的前缀和后缀最大值，则答案为：

$$\max(\operatorname{pre}_{i-1},\operatorname{suf}_i+b_i).$$

前后缀各扫描一次，每个位置即可常数时间回答。

**正确性**

公式枚举了全程每一步的能量非负限制，取最大值同时满足全部限制；再小则必定违反其中一项，因此得到最小可行初始能量。

**复杂度**

时间、空间均为 $O(n)$，累计量使用 64 位整数。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n;
ll a[N],b[N],c[N],pre[N],suf[N],sum;
int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&b[i]);
    }
    for(int i=0;i<=n;++i){
        sum+=a[i]-b[i];
        c[i]=sum;
        pre[i]=i?max(pre[i-1],c[i]):c[i];
    }
    suf[n+1]=-INF;
    for(int i=n;i>=0;--i){
        suf[i]=max(suf[i+1],c[i]);
    }
    for(int i=1;i<=n;++i){
        printf("%lld%c",max(pre[i-1],suf[i]+b[i]),i==n?'\n':' ');
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 缓存模拟

标签：`LRU` · `链表` · `哈希表` · `模拟`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce7c5a67df0b81749b99a)。重构版本地验证见 [VALIDATION.md](../tests/202412/VALIDATION.md)，未重新提交在线评测。

### 题意

模拟 $n$ 路、$N$ 组缓存，块地址 $a$ 只能进入组 $(a\div n)\bmod N$。组内采用 LRU：读写命中均更新最近访问顺序，未命中则载入新块；组满时淘汰最久未访问的块，若为脏块则先写回内存。

输入 $n,N,q$，再输入 $q$ 条处理器读写请求，每条由操作类型和块地址组成。$nN\le65536$、$q\le10^5$，操作 `0` 表示读，`1` 表示写。写过的缓存块标记为脏，读命中不会清除脏标记。

按发生顺序输出实际访问内存的读写操作，格式仍为 `操作类型 块地址`。结束时不统一写回剩余脏块。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412C/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202412C)。

### 题解

**链表维护访问顺序**

每组用双向链表保存缓存块，表头最近使用，表尾最久未使用。哈希表记录块地址对应的链表迭代器，命中时用 `splice` 把节点移到表头；写命中再设置脏标记，读命中保留原标记。

未命中且组满时，检查表尾是否为脏块，若是则先输出写回；随后从链表和哈希表删除旧块。无论处理器请求读还是写，都先输出读入新块，再插入表头，脏标记取决于原请求是否为写。

**正确性**

每次处理后，链表顺序都与最近访问顺序一致，脏标记准确表示载入后是否被写过。因此淘汰对象和内存访问顺序均符合题目规则。组编号必须按 $(a\div n)\bmod N$ 计算，不能写成常见的 $a\bmod N$。

**复杂度**

期望时间 $O(q)$，空间 $O(nN+N)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
struct node{
    int id;
    bool dirty;
};
int n,m,q;
vector<list<node>> g;
unordered_map<int,list<node>::iterator> mp;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    g.resize(m);
    mp.reserve(min(q,n*m)*2+1);
    while(q--){
        int op,x;
        scanf("%d%d",&op,&x);
        auto &cur=g[x/n%m];
        auto it=mp.find(x);
        if(it!=mp.end()){
            it->second->dirty|=(op==1);
            cur.splice(cur.begin(),cur,it->second);
            continue;
        }
        if((int)cur.size()==n){
            node v=cur.back();
            if(v.dirty)printf("1 %d\n",v.id);
            mp.erase(v.id);
            cur.pop_back();
        }
        printf("0 %d\n",x);
        cur.push_front({x,op==1});
        mp[x]=cur.begin();
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 跳房子

标签：`BFS` · `并查集` · `区间遍历`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce7c6a67df0b81749b99e)。重构版本地验证见 [VALIDATION.md](../tests/202412/VALIDATION.md)，未重新提交在线评测。

### 题意

共有 $n$ 个格子，从 1 出发。站在格子 $i$ 时，可以跳到任意 $j\in[i+1,\min(n,i+k_i)]$，随后立即后退 $a_j$ 格，最终站在 $j-a_j$。求到达格子 $n$ 的最少跳数。

输入 $n$、数组 $a$ 和数组 $k$。$n\le10^5$，$0\le a_i<i$，$a_n=0$，$k_i\le10^9$。

输出最少跳数；不可达时输出 $-1$。$n=1$ 时答案为 0。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412D/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202412D)。

### 题解

**先看普通 BFS**

把实际站立位置当作节点，选择落点 $j$ 就是沿一条边到达 $j-a_j$。所有边的代价均为 1，可以用 BFS 求最短路，但逐次枚举全部可选落点，最坏需要 $O(n^2)$ 次扫描。

**同一个落点只处理第一次**

BFS 出队顺序的距离不递减。落点 $j$ 第一次被覆盖时，已经以尽可能少的跳数到达，而它总是回退到同一个 $j-a_j$；以后再使用它不可能产生更短路径。

删除的是“供选择的落点”，并非“人可以站立的状态”。例如处理过落点 5 后，状态 5 仍能正常入队并向外跳。

**并查集跳过已处理落点**

维护 `find(x)`，返回不小于 $x$ 的第一个尚未处理的落点。处理 $j$ 后，让它指向 `find(j+1)`；扫描从 `find(i+1)` 开始，超过右端点就结束。查找使用迭代路径压缩，避免深递归。

**正确性**

BFS 的最短路性质保证删除安全，每个落点至多处理一次。所有可能改善距离的转移都被保留，因此得到的仍是最少跳数。

**复杂度**

后继结构采用路径压缩，通常接近线性；保守估计时间 $O(n\log n)$，空间 $O(n)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,a[N],k[N],fa[N],dis[N],q[N];
int find(int x){
    while(x!=fa[x]){
        x=fa[x]=fa[fa[x]];
    }
    return x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&k[i]);
    }
    for(int i=1;i<=n+1;++i){
        fa[i]=i;
    }
    memset(dis,-1,sizeof dis);
    dis[1]=0;
    int head=0,tail=1;
    q[0]=1;
    while(head<tail){
        int u=q[head++];
        int r=min((ll)n,u+(ll)k[u]);
        for(int j=find(u+1);j<=r;j=find(j)){
            int v=j-a[j];
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q[tail++]=v;
            }
            fa[j]=find(j+1);
        }
    }
    printf("%d\n",dis[n]);
    return 0;
}
```

<a id="problem-e"></a>

## E. 梦魔

标签：`贪心` · `单调栈` · `前缀和`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce7c9a67df0b81749b9c2)。重构版本地验证见 [VALIDATION.md](../tests/202412/VALIDATION.md)，未重新提交在线评测。

### 题意

一列梦魔的防御力为 $a_i$，击杀收益为 $b_i>0$。从相邻两只之间出发，每次只能攻击左右最近的一只；攻击力至少等于其防御力才能击杀，之后增加对应收益。求每个起始间隙所需的最小初始攻击力，并将全部结果异或。

输入 $n$、原始数组 $a,b$ 和询问数 $q$。每次询问给出若干位置的新 $a,b$，修改均基于原始数组，询问之间不累积。$n\le2\times10^6$、$q\le20$，修改总数不超过 $5\times10^5$。

每次询问输出所有起始间隙答案的异或和。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202412E/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202412E)。

### 题解

**固定落点的贪心**

两个可选端点中，先杀防御力较小的不会更差：把这次击杀提前不会提高门槛，还能提前取得正收益，其余攻击仍然可行。对于固定击杀顺序，最小初始攻击力就是每步“当前防御减此前收益”的最大值。

**找出真正的瓶颈**

令 $L_j,R_j$ 分别为位置 $j$ 左右最近的、防御力不小于 $a_j$ 的位置，不存在时取 $0,n+1$。令 $B$ 为收益前缀和。

若起始间隙 $p<j$ 且位于 $[L_j,j-1]$，在 $j$ 形成门槛前，可先清掉它左侧直到 $L_j$ 之间防御更小的梦魔，所以得到下界：

$$a_j-(B_{j-1}-B_{L_j}).$$

对称地，起点位于 $[j,R_j-1]$ 时，下界为：

$$a_j-(B_{R_j-1}-B_j).$$

每个起始间隙的答案，就是所有覆盖它的下界的最大值。相等防御不能弹出，左右边界都找“最近大于等于”；否则会越过相等端点，多算可以提前取得的收益。

**用栈维护区间最大值**

右向区间 $[j,R_j-1]$ 只能嵌套或分离。按 $j$ 从小到大扫描，已开始且未结束的区间形成一个栈，每项保存右端点和栈内最大下界。左向区间 $[L_j,j-1]$ 同理，从右向左扫描。

两遍结果逐点取最大值，再异或即可。两类区间分别处理，不需要比较排序，也就避免了额外的 $\log n$ 因子。每次询问开始先复制原数组，再应用本次修改。

**正确性**

贪心交换论证给出最优击杀顺序，最近不小于边界准确划分每个梦魔可能成为瓶颈的起始间隙。两遍栈维护全部必要下界的最大值，合并后便是每个间隙的最小初始攻击力。

**复杂度**

每次询问时间 $O(n+k)$，空间 $O(n)$。累计收益可能达到 $2\times10^{15}$，差值和前缀和必须使用 64 位有符号整数。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int n,q,a[N],b[N],x[N],y[N],l[N],r[N],st[N],top;
ll pre[N],ans[N],mx[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&b[i]);
    }
    scanf("%d",&q);
    while(q--){
        memcpy(x,a,(n+2)*sizeof *a);
        memcpy(y,b,(n+2)*sizeof *b);
        int k;
        scanf("%d",&k);
        while(k--){
            int i;
            scanf("%d",&i);
            scanf("%d%d",&x[i],&y[i]);
        }
        for(int i=1;i<=n;++i){
            pre[i]=pre[i-1]+y[i];
        }
        top=0;
        for(int i=1;i<=n;++i){
            while(top && x[st[top]]<x[i]){
                --top;
            }
            l[i]=top?st[top]:0;
            st[++top]=i;
        }
        top=0;
        for(int i=n;i>=1;--i){
            while(top && x[st[top]]<x[i]){
                --top;
            }
            r[i]=top?st[top]:n+1;
            st[++top]=i;
        }
        top=0;
        for(int i=1;i<n;++i){
            while(top && st[top]<i){
                --top;
            }
            ll val=x[i]-(pre[r[i]-1]-pre[i]);
            st[++top]=r[i]-1;
            mx[top]=max(val,mx[top-1]);
            ans[i]=mx[top];
        }
        top=0;
        ll res=0;
        for(int i=n-1;i>=1;--i){
            while(top && st[top]>i){
                --top;
            }
            int j=i+1;
            ll val=x[j]-(pre[j-1]-pre[l[j]]);
            st[++top]=l[j];
            mx[top]=max(val,mx[top-1]);
            res^=max(ans[i],mx[top]);
        }
        printf("%lld\n",res);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202412/VALIDATION.md)
- [details.txt](../tests/202412/details.txt)
- [e-sizeof-before.json](../tests/202412/e-sizeof-before.json)
- [e-sizeof-followup-report.json](../tests/202412/e-sizeof-followup-report.json)
- [prose-final-review.json](../tests/202412/prose-final-review.json)
- [report.json](../tests/202412/report.json)
- [retained_oracles.py](../tests/202412/retained_oracles.py)
- [verify-e-sizeof.py](../tests/202412/verify-e-sizeof.py)
- [verify.py](../tests/202412/verify.py)

<!-- local-validation-attachments:end -->
