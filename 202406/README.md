---
title: "CSP 202406 五题题解"
contest: "202406"
contest_month: "2024-06"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "矩阵重塑", "线性下标", "数组", "矩阵变换", "模拟", "BPE", "链表", "优先队列", "字符串", "分组背包", "排序", "动态规划", "二维区间", "线段树", "扫描线", "静态查询"]
status: "published"
problems: [{"id": "A", "title": "矩阵重塑（其一）", "tags": ["矩阵重塑", "线性下标"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055ac9e5d1fced2e45088a", "source_sha256": "1a95274448fbd5045de9237bb457884637288753c21344a9fcfdcf970b1d14f8", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:37:31.604711+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81ca67df0b81749bb2f"}}, {"id": "B", "title": "矩阵重塑（其二）", "tags": ["数组", "矩阵变换", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055b25e5d1fced2e450958", "source_sha256": "298cd9cb9ee229091ee7dd3b9bbfe5b9556747c201bb92f72b6948ba75f28ddf", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:39:07.693767+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81da67df0b81749bb39"}}, {"id": "C", "title": "文本分词", "tags": ["BPE", "链表", "优先队列", "字符串"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406C/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055b8ce5d1fced2e450aa9", "source_sha256": "49fab441d635bcbeb4921b8ae83c43ea4b724d187909304f7c14b5db8dc3e254", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:40:45.734235+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81fa67df0b81749bb49"}}, {"id": "D", "title": "货物调度", "tags": ["分组背包", "排序", "动态规划"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055be4e5d1fced2e450ad4", "source_sha256": "30a5f8a84b5c8c7d090d291a483bf6600fdf4ce25edb02fd5714a0d07f07d461", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:42:11.017924+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce821a67df0b81749bb75"}}, {"id": "E", "title": "哥德尔机", "tags": ["二维区间", "线段树", "扫描线", "静态查询"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：70 分 Time Exceeded（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202406E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202406E/"}], "oj": {"score": 70.0, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6b055c45e5d1fced2e450b84", "source_sha256": "efe8a23edda1c0bf3007259bc4e6cc5bc29c808918368bf6e127ac338f6e8981", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "failed", "observed_at": "2026-11-24T09:44:45.257225+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addaa6774ace1cba9a1ff5b"}}]
---

# CSP 202406 五题题解

[原页面](https://code92007.github.io/csp/#/contest/202406) · [验证记录](../tests/202406/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 矩阵重塑（其一）

标签：`矩阵重塑` · `线性下标`

本地：63 组优化版、63 组 UBSan 验证通过，详见 [验证记录](../tests/202406/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055ac9e5d1fced2e45088a)。

<!-- refactor-online:A:end -->

### 题意

将 $n\times m$ 矩阵按行展开，再按相同顺序填成 $p\times q$ 矩阵，元素的先后顺序保持不变。

输入先给出 $n,m,p,q$，再给出原矩阵。满足 $nm=pq\le10^4$，四个维度均为正整数，元素绝对值不超过 $1000$。

输出重塑后的矩阵，共 $p$ 行，每行 $q$ 个整数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406A)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406A/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce81ca67df0b81749bb2f)（accepted，100 分；复刻评测）。

### 题解

**线性顺序不变**

重塑只改变每行放多少个元素。读到第 $i$ 个数后直接输出，每输出 $q$ 个数换行，无需保存矩阵。

**正确性**

读入和输出都遵循行优先顺序，因此第 $i$ 个输入元素恰好成为新矩阵的第 $i$ 个元素，符合重塑定义。

**复杂度**

时间 $O(nm)$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,x;
int main(){
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=0;i<n*m;++i){
        scanf("%d",&x);
        if(i%q)printf(" ");
        printf("%d",x);
        if((i%q)==(q-1))printf("\n");
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 矩阵重塑（其二）

标签：`数组` · `矩阵变换` · `模拟`

本地：103 组优化版、103 组 UBSan 验证通过，详见 [验证记录](../tests/202406/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055b25e5d1fced2e450958)。

<!-- refactor-online:B:end -->

### 题意

维护一个矩阵，支持重塑、转置和单点查询。重塑保持行优先顺序，转置将位置 $(i,j)$ 变为 $(j,i)$。

输入先给出 $n,m,t$ 和初始矩阵，再给出 $t$ 个三元组操作。矩阵总元素数 $S\le10^4$，$t\le10^5$，转置最多 $100$ 次；所有重塑均保持元素总数，元素绝对值不超过 $1000$。

- `1 p q`：重塑为 $p\times q$。
- `2 0 0`：转置当前矩阵。
- `3 i j`：查询当前矩阵的零下标位置 $(i,j)$。

每个查询输出一行对应元素。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406B)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406B/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce81da67df0b81749bb39)（accepted，100 分；复刻评测）。

### 题解

**用一维数组保存矩阵**

当前矩阵第 $(i,j)$ 个元素存于 `a[i*m+j]`。重塑保持这个数组不变，只需更新行列数。

转置时，将原位置 $i m+j$ 的元素复制到新位置 $j n+i$，再交换行列数。查询直接访问当前线性下标。

**正确性**

一维数组始终等于当前矩阵按行展开的结果。重塑只改变分行方式；转置逐个完成 $(i,j)\to(j,i)$ 的映射，因此两类修改后这个不变式仍成立，查询也就正确。

**复杂度**

设转置次数为 $R$，时间 $O(t+RS)$，空间 $O(S)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,t,a[N],b[N];
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n*m;++i){
        scanf("%d",&a[i]);
    }
    while(t--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)n=x,m=y;
        else if(op==2){
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    b[j*n+i]=a[i*m+j];
                }
            }
            memcpy(a,b,n*m*sizeof(int));
            swap(n,m);
        }
        else printf("%d\n",a[x*m+y]);
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 文本分词

标签：`BPE` · `链表` · `优先队列` · `字符串`

本地：133 组优化版、133 组 UBSan 验证通过，详见 [验证记录](../tests/202406/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055b8ce5d1fced2e450aa9)。

<!-- refactor-online:C:end -->

### 题意

根据带频率的单词生成词汇表。先按字典序加入所有出现过的单字母，再反复选取相邻词汇对合并，直到词汇表达到目标长度或已经没有可合并的相邻词汇。

输入 $n,m$，随后每行给出单词 $s$ 及频率 $f$。满足 $n\le10^4$、$m\le5000$、总单词长度 $L\le2.5\times10^5$、总频率不超过 $10^6$，且 $m$ 不小于初始字母数。单词非空且只含小写字母；这里沿用复刻题面，总长度受限，单个单词不另设长度上限。

每轮优先选择加权出现次数最多的词汇对；依次按拼接总长度较短、左词长度较短、拼接串字典序较小打破平局。选定后在每个单词内从左向右进行不重叠合并。

按加入顺序逐行输出词汇表；无法继续时提前停止。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406C)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406C/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce81fa67df0b81749bb49)（accepted，100 分；复刻评测）。

### 题解

**链表保存分词结果**

把每个字符视为链表节点，节点保存词汇编号、前驱、后继及所在单词的频率。不同单词之间断开连接，避免统计跨单词的相邻对。

对每种相邻对，维护加权频率和所有左端点的有序集合。节点编号沿输入从左向右递增，因此按集合顺序处理就能实现题目要求的替换顺序。

**堆维护最优相邻对**

将相邻对按题目的四层优先级放入堆。每次频率变化都递增版本号，并压入新快照；取堆顶时删除版本过期的记录。

选中一对后，先复制它的左端点集合，再依次合并。若左端点已被删除或当前后继不再匹配，直接跳过；这样也能正确处理 `a a a` 这类重叠出现。

**只更新相邻边**

合并相邻节点 $u,w$ 时，旧的相邻对只有前驱到 $u$、$u$ 到 $w$、$w$ 到后继这三处。删除这些贡献，修改链表，再加入两侧的新贡献即可，无需重新扫描所有单词。

**正确性**

相邻对统计始终覆盖当前链表的每一条有效边，因此堆中最新版本的最优项恰好是规则指定的词汇对。每轮按左端点递增顺序合并，并检查节点是否仍有效，得到的正是从左向右的不重叠替换。由此逐轮生成的词汇表与定义一致。

**复杂度**

每次成功合并都会删除一个节点，总共不超过 $L$ 次；每次只修改常数条边。忽略字符串构造、比较与输出的字符开销，时间 $O((L+m)\log(L+m))$，结构空间 $O(L+m)$；另需保存实际生成的词汇内容。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2.5e5+10;
int n,m;
char s[N];
struct node{
    int v,pre,nxt;
    ll w;
    bool ok;
};
struct edge{
    int l,r,ver=0;
    ll sum=0;
    set<int>pos;
};
struct item{
    ll sum;
    int id,ver;
};
vector<string>v;
vector<node>a;
vector<edge>e;
struct cmp{
    bool operator()(const item &a,const item &b)const{
        if(a.sum!=b.sum)return a.sum<b.sum;
        edge &x=e[a.id],&y=e[b.id];
        int al=v[x.l].size(),ar=v[x.r].size();
        int bl=v[y.l].size(),br=v[y.r].size();
        if(al+ar!=bl+br)return al+ar>bl+br;
        if(al!=bl)return al>bl;
        int d=v[x.l].compare(v[y.l]);
        if(d)return d>0;
        d=v[x.r].compare(v[y.r]);
        if(d)return d>0;
        return a.id>b.id;
    }
};
unordered_map<string,int>id;
unordered_map<ull,int>mp;
priority_queue<item,vector<item>,cmp>q;
int index(int l,int r){
    ull key=(ull(l)<<32)|r;
    auto it=mp.find(key);
    if(it!=mp.end())return it->second;
    int u=e.size();
    e.push_back({l,r,0,0,{}});
    return mp[key]=u;
}
void change(int u,int d){
    if(u<0 || a[u].nxt<0)return;
    int i=index(a[u].v,a[a[u].nxt].v);
    edge &x=e[i];
    x.sum+=d*a[u].w;
    ++x.ver;
    if(d==1)x.pos.insert(u);
    else x.pos.erase(u);
    if(x.sum>0)q.push({x.sum,i,x.ver});
}
int main(){
    scanf("%d%d",&n,&m);
    vector<string>word(n);
    vector<ll>freq(n);
    set<char>alpha;
    for(int i=0;i<n;++i){
        scanf("%s%lld",s,&freq[i]);
        word[i]=s;
        for(char &c:word[i]){
            alpha.insert(c);
        }
    }
    for(const char &c:alpha){
        string x(1,c);
        id[x]=v.size();
        v.push_back(x);
        puts(x.c_str());
    }
    for(int i=0;i<n;++i){
        int start=a.size();
        for(char &c:word[i]){
            int u=a.size();
            int pre=u==start?-1:u-1;
            a.push_back({id[string(1,c)],pre,u+1,freq[i],1});
        }
        a.back().nxt=-1;
    }
    for(int i=0;i<(int)a.size();++i){
        change(i,1);
    }
    int cnt=v.size();
    while(cnt<m){
        while(!q.empty()){
            item x=q.top();
            if(x.ver==e[x.id].ver && e[x.id].sum)break;
            q.pop();
        }
        if(q.empty())break;
        int cur=q.top().id;
        q.pop();
        int l=e[cur].l,r=e[cur].r;
        string str=v[l]+v[r];
        puts(str.c_str());
        ++cnt;
        int val;
        auto it=id.find(str);
        if(it==id.end()){
            val=v.size();
            id[str]=val;
            v.push_back(str);
        }
        else val=it->second;
        vector<int>pos(e[cur].pos.begin(),e[cur].pos.end());
        for(int &u:pos){
            if(!a[u].ok || a[u].nxt<0)continue;
            int w=a[u].nxt;
            if(a[u].v!=l || a[w].v!=r)continue;
            int pre=a[u].pre,nxt=a[w].nxt;
            change(pre,-1),change(u,-1),change(w,-1);
            a[u].v=val,a[u].nxt=nxt;
            a[w].ok=0,a[w].nxt=-1;
            if(nxt>=0)a[nxt].pre=u;
            change(pre,1),change(u,1);
        }
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 货物调度

标签：`分组背包` · `排序` · `动态规划`

本地：103 组优化版、103 组 UBSan 验证通过，详见 [验证记录](../tests/202406/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055be4e5d1fced2e450ad4)。

<!-- refactor-online:D:end -->

### 题意

有 $n$ 间仓库和 $m$ 件货物。调用仓库 $j$ 的任意货物需支付一次基本费 $b_j$，每调用一件还需支付 $c_j$。选择若干货物出售，使总售价减总费用至少为 $v$，求最小总费用。

输入先给出 $n,m,v$，再给出各仓库的 $b_j,c_j$，最后给出各货物售价 $a_i$ 和所在仓库编号 $t_i$。仓库编号从 $0$ 开始；$n,m\le1000$，$1\le b_j,c_j\le20$，$1\le a_i\le1000$，$1\le v\le10^6$，保证有解。

输出达到现金目标所需的最小费用。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406D)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406D/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce821a67df0b81749bb75)（accepted，100 分；复刻评测）。

### 题解

**每间仓库只考虑售价最大的前缀**

同一仓库取 $k$ 件的费用固定为 $b_j+kc_j$，所以一定选择售价最高的 $k$ 件。将每间仓库的货物降序排序，枚举前缀和，就得到这一组的全部有效选择。

**以总费用为背包容量**

总费用最多为 $C=20n+20m\le40000$。令 `dp[s]` 表示处理完前若干仓库、费用恰为 $s$ 时的最大净现金。

每间仓库可以不取，也可以选择一个非空前缀。若前缀售价为 $w$、费用为 $c$，则用上一组的状态转移：

$$ndp[s+c]=\max(ndp[s+c],dp[s]+w-c).$$

先把 `dp` 复制到 `ndp` 表示不取，所有非空选择也只从旧 `dp` 转移，避免同一仓库重复选择。最后从小到大找到首个 `dp[s]>=v` 的费用。

**正确性**

前缀选择在相同件数下具有最大售价，不会排除最优解。分组背包枚举每间仓库取零件或某个前缀，完整覆盖所有最优候选，并保存每种费用下的最大净现金。因而第一个达到目标的费用就是答案。

**复杂度**

时间 $O(C(n+m)+m\log m)$，空间 $O(C+n+m)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=40010,INF=0x3f3f3f3f;
int n,m,v,b[N],c[N],dp[M],ndp[M];
vector<int>g[N];
int main(){
    scanf("%d%d%d",&n,&m,&v);
    for(int i=0;i<n;++i){
        scanf("%d%d",&b[i],&c[i]);
    }
    for(int i=0;i<m;++i){
        int x,t;
        scanf("%d%d",&x,&t);
        g[t].push_back(x);
    }
    fill(dp,dp+M,-INF);
    dp[0]=0;
    int bound=0;
    for(int i=0;i<n;++i){
        if(g[i].empty())continue;
        sort(g[i].begin(),g[i].end(),greater<int>());
        memcpy(ndp,dp,sizeof dp);
        int sum=0;
        for(int j=1;j<=(int)g[i].size();++j){
            sum+=g[i][j-1];
            int cost=b[i]+j*c[i];
            for(int k=0;k<=bound;++k){
                if(dp[k]==-INF)continue;
                ndp[k+cost]=max(ndp[k+cost],dp[k]+sum-cost);
            }
        }
        bound+=b[i]+c[i]*g[i].size();
        memcpy(dp,ndp,sizeof dp);
    }
    for(int i=0;i<=bound;++i){
        if(dp[i]>=v){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 哥德尔机

标签：`二维区间` · `线段树` · `扫描线` · `静态查询`

本地：653 组优化版、653 组 UBSan 验证通过，详见 [验证记录](../tests/202406/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：70 分 Time Exceeded（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055c45e5d1fced2e450b84)。

<!-- refactor-online:E:end -->

<!-- candidate-attempt:E:start -->

查询优化候选另获 [70 分 Time Exceeded](https://oj.shumeng.tech/record/6b05ab73e5d1fced2e45be79)。本页继续展示首轮源码；该候选的源码与判题归属单独保存在 [复测记录](../tests/202406/performance-attempt/202406E/attempt.json) 中。

<!-- candidate-attempt:E:end -->

旧记录于 2026-11-24 复核，同样为 **70 分 Time Exceeded**；原元数据中的 100 分 AC 与当前页面不一致，以可见判题记录为准。[复核证据](../tests/202406/prior-record-observation.json)。

### 题意

二维网格初始全为 $0$。先进行 $n$ 次学习，每次将一个闭矩形内的所有值更新为原值与 $v$ 的较大者；学习全部结束后，回答 $m$ 个闭矩形内的最大值。

输入先给出 $n,m$，随后 $n$ 行为学习参数 $x_1,x_2,y_1,y_2,v$，再后面 $m$ 行为查询参数 $x_1,x_2,y_1,y_2$。满足 $1\le n,m\le5\times10^5$，坐标和学习权值均为 $1$ 到 $n$ 的整数，矩形端点有序。

按查询顺序输出 $m$ 行答案。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202406E)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202406E/)。

原版评测：[记录](https://oj.shumeng.tech/record/6addaa6774ace1cba9a1ff5b)（accepted，100 分；复刻评测）。

### 题解

**转为静态矩形相交查询**

更新式 $v+\max(0,V-v)$ 就是 $\max(V,v)$。一个学习矩形只要与查询矩形相交，就会给查询答案贡献它的权值；因此答案等于所有相交学习矩形的最大权值，没有相交者时为 $0$。

**外层线段树分解横坐标**

将每个学习矩形的横区间拆成标准节点，记录在这些节点的 `cover` 中。节点的 `all` 则汇总本节点及所有后代记录。

查询横区间时，完全包含的节点可直接查询 `all`；部分相交的节点先查询 `cover`，再递归相交的子树。这样既不会漏掉覆盖祖先区间的矩形，也能处理只覆盖局部的矩形。

**用上包络压缩纵区间**

同一个节点内，只需维护每个纵坐标上能提供的最大权值。按权值递减处理纵区间，用后继并查集跳过已经覆盖的位置，每个压缩小段只赋值一次，得到分段常值的上包络。

只保存值发生变化的断点，并在这些值上建立静态区间最大值结构。查询纵区间时，二分定位两端断点，再查询覆盖的小段最大值。

**自底向上合并**

节点的 `all` 是本地 `cover` 与两个孩子 `all` 的逐点最大值。三个包络的断点均有序，用三路归并在线性时间内生成新包络，连续相同值合并；若结果与已有包络完全一致，直接共享其存储。

实现中还会选择标准节点记录数较少的坐标轴作为外层，并优先访问可能答案较大的子树。若某节点的全局最大权值已经不超过当前答案，就可以剪枝。

**正确性**

标准区间分解保证每个学习矩形在横坐标上的覆盖被准确记录。完全包含的查询节点使用子树汇总，部分相交节点使用本地覆盖并继续下降，恰好收集所有横向相交的学习矩形。

每份上包络保存其记录在各纵坐标上的最大贡献，因此纵区间最大值恰好筛选出纵向也相交的矩形。两维结合后得到全部相交学习矩形的最大权值，也就是原查询答案。

**复杂度**

每个矩形进入 $O(\log n)$ 个标准节点。排序、建立纵向结构及查询总计 $O((n+m)\log^2n)$ 时间，空间 $O(n\log n)$。剪枝与坐标轴选择只优化常数，不改变上述界。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<19,M=3,K=(N<<1)+1,INF=0x3f3f3f3f;
int n,m,b=1,h;
bool rev;
struct rect{
    int xl,xr,yl,yr,v;
};
rect a[N];
int ord[N],st[K],pos[K];
int x[N<<1],y[N<<1],fa[N<<1];
vector<int>pool;
struct env{
    int off=0,n=0;
    int x(int i)const{
        return pool[off+i];
    }
    int val(int i)const{
        return pool[off+2*n+i];
    }
    int top()const{
        return n?pool[off+n+1]:0;
    }
    int query(int l,int r)const{
        if(!n || r<x(0) || l>=x(n-1))return 0;
        auto it=pool.begin()+off;
        int a=max(0,(int)(upper_bound(it,it+n,l)-it)-1);
        int b=upper_bound(it,it+n,r)-it;
        int ans=0,pos=off+n;
        for(a+=n,b+=n;a<b;a>>=1,b>>=1){
            if(a&1){
                ans=max(ans,pool[pos+a]);
                a++;
            }
            if(b&1){
                b--;
                ans=max(ans,pool[pos+b]);
            }
        }
        return ans;
    }
};
env save(int n){
    int off=pool.size();
    if(!n)return env();
    pool.resize(off+3*n);
    copy(x,x+n,pool.begin()+off);
    copy(y,y+n,pool.begin()+off+2*n);
    int p=off+n;
    for(int i=n-1;i;--i){
        pool[p+i]=max(pool[p+2*i],pool[p+2*i+1]);
    }
    return {off,n};
}
int find(int x){
    while(fa[x]!=x){
        fa[x]=fa[fa[x]];
        x=fa[x];
    }
    return x;
}
env build(const vector<int> &id,int l,int r){
    if(l==r)return env();
    if(r-l==1){
        rect &v=a[id[l]];
        x[0]=v.yl;x[1]=v.yr+1;
        y[0]=v.v;y[1]=0;
        return save(2);
    }
    int cnt=0;
    for(int i=l;i<r;++i){
        rect &v=a[id[i]];
        x[cnt]=v.yl;x[cnt+1]=v.yr+1;
        cnt+=2;
    }
    sort(x,x+cnt);
    cnt=unique(x,x+cnt)-x;
    iota(fa,fa+cnt+1,0);
    memset(y,0,cnt*sizeof *y);
    for(int i=l;i<r;++i){
        rect &p=a[id[i]];
        int l=lower_bound(x,x+cnt,p.yl)-x;
        int r=lower_bound(x,x+cnt,p.yr+1)-x;
        for(int j=find(l);j<r;j=find(j)){
            y[j]=p.v;
            fa[j]=find(j+1);
        }
    }
    int n=0,pre=0;
    for(int i=0;i<cnt;++i){
        if(y[i]!=pre){
            pre=y[i];
            x[n]=x[i];y[n++]=pre;
        }
    }
    return save(n);
}
env merge(env a,env b,env c){
    env v[M];
    v[0]=a,v[1]=b,v[2]=c;
    int cnt=0,id=0;
    for(int i=0;i<M;++i){
        if(v[i].n){
            ++cnt;
            id=i;
        }
    }
    if(!cnt)return env();
    if(cnt==1)return v[id];
    int at[M],cur[M];
    memset(at,0,sizeof at);
    memset(cur,0,sizeof cur);
    int pre=0;
    int n=0;
    while(1){
        int p=INF;
        for(int i=0;i<M;++i){
            if(at[i]<v[i].n)p=min(p,v[i].x(at[i]));
        }
        if(p==INF)break;
        for(int i=0;i<M;++i){
            if(at[i]<v[i].n && v[i].x(at[i])==p){
                cur[i]=v[i].val(at[i]++);
            }
        }
        int val=max({cur[0],cur[1],cur[2]});
        if(val!=pre){
            x[n]=p;y[n]=val;
            ++n;
            pre=val;
        }
    }
    for(env &old:v){
        if(old.n!=n)continue;
        bool ok=1;
        for(int i=0;i<old.n && ok;++i){
            ok=(old.x(i)==x[i] && old.val(i)==y[i]);
        }
        if(ok)return old;
    }
    return save(n);
}
struct segtree{
    struct node{
        int l,r;
        env cover,all;
    }e[N<<1];
    #define l(p) e[p].l
    #define r(p) e[p].r
    void init(int p,int x,int y){
        l(p)=x;r(p)=y;
        if(x==y)return;
        int mid=(x+y)>>1;
        init(p<<1,x,mid);
        init(p<<1|1,mid+1,y);
    }
    int query(int p,int a,int b,int c,int d,int ans){
        if(e[p].all.top()<=ans)return ans;
        if(a<=l(p) && r(p)<=b){
            return max(ans,e[p].all.query(c,d));
        }
        if(e[p].cover.top()>ans){
            ans=max(ans,e[p].cover.query(c,d));
        }
        int mid=(l(p)+r(p))>>1;
        bool x=a<=mid,y=b>mid;
        if(x && y){
            if(e[p<<1].all.top()>=e[p<<1|1].all.top()){
                ans=query(p<<1,a,b,c,d,ans);
                ans=query(p<<1|1,a,b,c,d,ans);
            }
            else{
                ans=query(p<<1|1,a,b,c,d,ans);
                ans=query(p<<1,a,b,c,d,ans);
            }
        }
        else if(x)ans=query(p<<1,a,b,c,d,ans);
        else ans=query(p<<1|1,a,b,c,d,ans);
        return ans;
    }
}tr;
int count(int x,int y){
    int ans=0;
    for(int l=x+b-1,r=y+b;l<r;l>>=1,r>>=1){
        if(l&1)++ans,++l;
        if(r&1)++ans,--r;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    while(b<n){
        b<<=1;
        ++h;
    }
    tr.init(1,1,b);
    iota(ord,ord+n,0);
    ll x=0,y=0;
    for(int i=0;i<n;++i){
        rect &p=a[i];
        scanf("%d%d%d%d%d",&p.xl,&p.xr,&p.yl,&p.yr,&p.v);
        x+=count(p.xl,p.xr);
        y+=count(p.yl,p.yr);
    }
    rev=y<x;
    for(int i=0;i<n;++i){
        rect &p=a[i];
        if(rev){
            swap(p.xl,p.yl);
            swap(p.xr,p.yr);
        }
        for(int l=p.xl+b-1,r=p.xr+b;l<r;l>>=1,r>>=1){
            if(l&1){
                ++st[l+1];
                ++l;
            }
            if(r&1){
                --r;
                ++st[r+1];
            }
        }
    }
    for(int i=1;i<=2*b;++i){
        st[i]+=st[i-1];
    }
    vector<int>id(st[2*b]);
    copy(st,st+2*b+1,pos);
    sort(ord,ord+n,[](int x,int y){
        return a[x].v>a[y].v;
    });
    for(int j=0;j<n;++j){
        int i=ord[j];
        rect &p=a[i];
        for(int l=p.xl+b-1,r=p.xr+b;l<r;l>>=1,r>>=1){
            if(l&1){
                id[pos[l]++]=i;
                ++l;
            }
            if(r&1){
                --r;
                id[pos[r]++]=i;
            }
        }
    }
    pool.reserve(size_t(6)*n*(h+1));
    for(int i=2*b-1;i;--i){
        tr.e[i].cover=build(id,st[i],st[i+1]);
        if(i>=b)tr.e[i].all=tr.e[i].cover;
        else{
            tr.e[i].all=merge(tr.e[i].cover,tr.e[i<<1].all,tr.e[i<<1|1].all);
        }
    }
    vector<int>().swap(id);
    while(m--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(rev){
            swap(a,c);
            swap(b,d);
        }
        printf("%d\n",tr.query(1,a,b,c,d,0));
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202406/VALIDATION.md)
- [array-followup-e.json](../tests/202406/array-followup-e.json)
- [array-memory.json](../tests/202406/array-memory.json)
- [array-memory.py](../tests/202406/array-memory.py)
- [cases.json](../tests/202406/cases.json)
- [compile-initial.json](../tests/202406/compile-initial.json)
- [compile.json](../tests/202406/compile.json)
- [constants-followup.json](../tests/202406/constants-followup.json)
- [current-sources.json](../tests/202406/current-sources.json)
- [extra.py](../tests/202406/extra.py)
- [online-update-report.json](../tests/202406/online-update-report.json)
- [online-verdicts.json](../tests/202406/online-verdicts.json)
- [performance-attempt/202406E/E.cpp](../tests/202406/performance-attempt/202406E/E.cpp)
- [performance-attempt/202406E/attempt.json](../tests/202406/performance-attempt/202406E/attempt.json)
- [prior-record-observation.json](../tests/202406/prior-record-observation.json)
- [style-followup-c.json](../tests/202406/style-followup-c.json)
- [style-followup-e.json](../tests/202406/style-followup-e.json)
- [style-followup.json](../tests/202406/style-followup.json)
- [summary-initial.json](../tests/202406/summary-initial.json)
- [summary.json](../tests/202406/summary.json)

<!-- local-validation-attachments:end -->
