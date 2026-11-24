---
title: "CSP 202509 五题题解"
contest: "202509"
contest_month: "2025-09"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "几何判断", "定点数", "计数", "矩阵枚举", "差分", "区间并集", "字符串解析", "Huffman", "双端队列", "模拟", "树", "mex", "动态规划", "离散凸性", "优先队列", "拉格朗日优化", "排列", "线性预处理"]
status: "published"
problems: [{"id": "A", "title": "蒙特卡洛", "tags": ["几何判断", "定点数", "计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b054563e5d1fced2e44e250", "source_sha256": "ebec3287fd4999bc4e9b986691e1526e7b58bc3e2651034abfb9c2f4d83fada7", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T08:07:09.705867+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce736a67df0b81749b65c"}}, {"id": "B", "title": "水印检查", "tags": ["矩阵枚举", "差分", "区间并集"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0545cfe5d1fced2e44e2f0", "source_sha256": "0b3b127e87de2706f8c194544025e02b807687714d7f0d380b4512344bd0a2d8", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T08:08:38.008971+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce738a67df0b81749b678"}}, {"id": "C", "title": "HTTP 头信息", "tags": ["字符串解析", "Huffman", "双端队列", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509C/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05464fe5d1fced2e44e407", "source_sha256": "e9d6976a5a6a902e5cfa1f3f6320acead297ab8fff6b12b84f709036476ca2a9", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T08:10:43.189587+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce739a67df0b81749b685"}}, {"id": "D", "title": "造题计划（上）", "tags": ["树", "排列", "mex", "线性预处理"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05ab06e5d1fced2e45bdac", "source_sha256": "6d340704052cfdf30dbaba52b2636e7ec91a72a16cdf56e81188759e3b19f632", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T15:20:33.765126+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce73ba67df0b81749b69a"}, "oj_revisions": [{"score": 70.0, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6b0546dee5d1fced2e44e4b5", "source_sha256": "9132211a9175bee8afe2165aeadf144a23c9c91edacdb0749e661f94a1bd09da", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "failed", "observed_at": "2026-11-24T08:13:58.489531+00:00"}]}, {"id": "E", "title": "造题计划（下）", "tags": ["动态规划", "离散凸性", "优先队列", "拉格朗日优化"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202509E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202509E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05477ce5d1fced2e44e5ea", "source_sha256": "f30997019754ecdbad11e1e9a94bec8515d9360f4681cd3deeaded7e9d073288", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T08:15:49.681826+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce73ca67df0b81749b6b1"}}]
---

# CSP 202509 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202509/VALIDATION.md)

<a id="problem-a"></a>

## A. 蒙特卡洛

标签：`几何判断` · `定点数` · `计数`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce736a67df0b81749b65c)。本次重构的本地验证见 [VALIDATION.md](../tests/202509/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b054563e5d1fced2e44e250)。

<!-- refactor-online:A:end -->

### 题意

给定正方形 $[-a,a]^2$ 内的 $n$ 个点，统计落在以原点为圆心、$a$ 为半径的圆内（含边界）的点数 $m$，用 $4m/n$ 估计圆周率。

输入 $n,a$，再输入 $n$ 个点的坐标。$n,a\le1000$，坐标最多两位小数，可以为负数。

输出估计值 $4m/n$，保留足够的小数位。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509A/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202509A)。

### 题解

**转成整数判断**

把坐标精确转换成百分之一单位的整数，例如 `-3.01` 变为 $-301$，整数 `4` 变为 $400$。半径同样乘以 100，然后用 64 位整数比较 $x^2+y^2\le r^2$。坐标有负数且小数位数不固定，读入时需处理符号并补足两位小数，不能直接拼接整数、小数部分。

**正确性**

统一放大 100 倍不改变点与圆的位置关系，整数平方比较准确包含圆周上的点。统计得到 $m$ 后，只有最后的 $4m/n$ 使用浮点除法。

**复杂度**

时间 $O(n)$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=25;
int n,a,cnt;
char s[M];
int read(){
    scanf("%s",s);
    int i=0,x=0,k=-1,sgn=1;
    if(s[i]=='-' || s[i]=='+'){
        if(s[i]=='-')sgn=-1;
        ++i;
    }
    for(;s[i];++i){
        if(s[i]=='.')k=0;
        else{
            x=x*10+s[i]-'0';
            if(k>=0)++k;
        }
    }
    if(k<0)k=0;
    while(k<2){
        x*=10;
        ++k;
    }
    return x*sgn;
}
int main(){
    scanf("%d%d",&n,&a);
    ll r=a*100;
    for(int i=0;i<n;++i){
        ll x=read(),y=read();
        cnt+=(x*x+y*y<=r*r);
    }
    printf("%.8f\n",4.0*cnt/n);
    return 0;
}
```

<a id="problem-b"></a>

## B. 水印检查

标签：`矩阵枚举` · `差分` · `区间并集`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce738a67df0b81749b678)。本次重构的本地验证见 [VALIDATION.md](../tests/202509/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0545cfe5d1fced2e44e2f0)。

<!-- refactor-online:B:end -->

### 题意

对一张 $n\times n$ 灰度图选阈值 $k$，将灰度不小于 $k$ 的格子变白，其余变黑。找出所有能在图中出现指定 $5\times9$ CSP 水印的阈值，水印不能旋转或翻转。

输入 $n,L$ 和灰度矩阵，$n\le200$、$L\le65536$，灰度和阈值均在 $[0,L-1]$ 内。固定水印中 `1` 表示白色，`0` 表示黑色：

```text
111111111
100100101
100111110
100001100
111111100
```

按从小到大的顺序输出所有合法阈值，每行一个；没有合法阈值时不输出。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509B/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202509B)。

### 题解

**每个位置对应一个阈值区间**

固定水印左上角，所有白格要求 $k$ 不大于对应灰度，所有黑格要求 $k$ 大于对应灰度。因此合法阈值恰为：

$$[\text{黑格最大值}+1,\ \text{白格最小值}]\cap[0,L-1].$$

枚举所有能容纳水印的位置，每个位置检查 45 个格子。区间为空则跳过，否则在左端点加一、右端点后一位减一，用差分记录这些区间的并集。

**正确性**

白格和黑格的限制都是必要且充分的，取交集恰好得到该位置的全部合法阈值。差分前缀和大于 0，等价于至少一个位置可以呈现水印；按阈值顺序扫描即可避免重复输出。

**复杂度**

时间 $O(45n^2+L)$，空间 $O(n^2+L)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=205,M=65540,H=5,W=10;
int n,m,a[N][N],d[M];
char s[H][W]={"111111111","100100101","100111110","100001100","111111100"};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i+H<=n;++i){
        for(int j=0;j+W-1<=n;++j){
            int l=0,r=m-1;
            for(int u=0;u<H;++u){
                for(int v=0;v<W-1;++v){
                    if(s[u][v]=='1')r=min(r,a[i+u][j+v]);
                    else l=max(l,a[i+u][j+v]+1);
                }
            }
            if(l>r)continue;
            ++d[l];
            --d[r+1];
        }
    }
    int sum=0;
    for(int i=0;i<m;++i){
        sum+=d[i];
        if(sum)printf("%d\n",i);
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. HTTP 头信息

标签：`字符串解析` · `Huffman` · `双端队列` · `模拟`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce739a67df0b81749b685)。本次重构的本地验证见 [VALIDATION.md](../tests/202509/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05464fe5d1fced2e44e407)。

<!-- refactor-online:C:end -->

### 题意

模拟简化的 HPACK 头信息解码。静态表保存固定条目，动态表保存最近插入的条目；每个条目包含字段名与字段值。

输入静态表大小 $S$、动态表容量 $D$，再输入静态条目、Huffman 树的前序编码和指令数，最后依次输入各条指令。表索引从 1 开始，静态表在前、动态表在后；新条目插入动态表最前端，超出容量时删除末项。

- 指令 `1`：按索引引用完整条目。
- 指令 `2`：指定字段名与字段值，输出后加入动态表。
- 指令 `3`：指定字段名与字段值，仅输出，不加入动态表。

后两种指令的字段名既可以按索引引用，也可以在索引为 0 时直接给出。指令中的普通字符串原样使用，`HH` 开头的字符串去掉一个 `H`；只有一个前导 `H` 时，后面是十六进制 Huffman 数据，末字节表示补零位数。静态表的字符串已经是原文。

每条指令输出一行 `key: value`。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509C/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202509C)。

### 题解

**重建并解码 Huffman 树**

前序编码中，读到 `1` 后再读一个字符，建立叶子；读到 `0` 则递归建立左右子树。用节点下标连接子树，避免容器扩容时引用失效。

解码十六进制串时，最后一字节表示补零位数，不属于实际内容。剩余数据从高位向低位沿树行走，到叶子就输出字符并回到根；末尾的补零位不参与解码。`HH` 的转义优先判断，普通字符串直接返回。

**维护两张表**

静态表存入顺序表 `a`，动态表用 `deque` `d`，统一通过 `f(x)` 按索引取条目。索引 $1$ 到 $S$ 对应静态条目，其余减去 $S$ 后对应动态表。每条指令先完整取得字段名、字段值，输出后才按指令 `2` 插入动态表，避免插入造成索引偏移。

静态表中保存的已经是原文，只有指令内的字面量才执行解码。动态表取得的字段也不能重复解码。

**正确性**

Huffman 编码是前缀码，到达叶子即可确定唯一字符。两张表的索引、插入和淘汰顺序与指令一致，因此每条指令都能取得正确条目，逐条输出即为答案。

**复杂度**

时间与输入解码位数及输出字符总数线性相关；空间为 Huffman 树与两张表保存的字符串总量。动态表每次插入、淘汰只需常数次操作。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> P;
struct node{
    int l,r;
    char c;
};
int n,m,q,p;
string s;
vector<node> tr(1);
vector<P> a;
deque<P> d;
string read(){
    string t;
    int c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(c!=EOF && !isspace(c)){
        t+=char(c);
        c=getchar();
    }
    return t;
}
int build(){
    int u=tr.size();
    tr.push_back({0,0,0});
    if(s[p++]=='1')tr[u].c=s[p++];
    else{
        tr[u].l=build();
        tr[u].r=build();
    }
    return u;
}
int hex(char c){
    return c<='9'?c-'0':c-'a'+10;
}
string decode(string t){
    if(t[0]!='H')return t;
    if(t.size()>1 && t[1]=='H')return t.substr(1);
    int len=t.size();
    int w=hex(t[len-2])*16+hex(t[len-1]);
    int b=((len-1)/2-1)*8-w,u=1;
    string ans;
    for(int i=0;i<b;++i){
        int v=(hex(t[1+i/4])>>(3-i%4))&1;
        u=v?tr[u].r:tr[u].l;
        if(tr[u].c){
            ans+=tr[u].c;
            u=1;
        }
    }
    return ans;
}
P f(int x){
    return x<=n?a[x-1]:d[x-n-1];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        string k=read(),v=read();
        a.push_back({k,v});
    }
    s=read();
    build();
    scanf("%d",&q);
    while(q--){
        int op,x;
        scanf("%d%d",&op,&x);
        P cur;
        if(op==1)cur=f(x);
        else{
            cur.first=x?f(x).first:decode(read());
            cur.second=decode(read());
        }
        printf("%s: %s\n",cur.first.c_str(),cur.second.c_str());
        if(op==2){
            d.push_front(cur);
            if((int)d.size()>m)d.pop_back();
        }
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 造题计划（上）

标签：`树` · `排列` · `mex` · `线性预处理`

原版历史记录为 [100 分 Accepted](https://oj.shumeng.tech/record/6adce73ba67df0b81749b69a)；首轮重构版为 [70 分 Time Exceeded](https://oj.shumeng.tech/record/6b0546dee5d1fced2e44e4b5)。下方为本次线性版本，两个已有记录分别保留原版与首轮版本的归属。

本地已通过独立路径枚举对拍及最大规模链、星形树检查；详见 [本地结果](../tests/202509/performance-revision/202509D/initial-linear-report.json)和[独立复核](../tests/202509/performance-revision/202509D/independent-review-review.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05ab06e5d1fced2e45bdac)。

<!-- refactor-online:D:end -->

### 题意

给定一棵 $n$ 个点的树，点权恰为 $0,1,\ldots,n-1$ 的排列。每次询问两点间简单路径上的权值集合的 mex，即最小未出现的非负整数。

输入 $n,m$、各点点权、$n-1$ 条边和 $m$ 对查询端点，$n,m\le2\times10^5$。

每次查询输出一个整数，表示该路径的 mex。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509D/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202509D)。

### 题解

**把 mex 转成路径外的最小值**

所有点权恰好组成 $0,1,\ldots,n-1$ 的排列，因此一个数没有出现在路径上，当且仅当它对应的点在路径外。于是答案就是路径外的最小点权；若路径经过所有点，答案为 $n$。

设权值为 $0$ 的点是 $z$，以它为根。用 $\operatorname{bel}[u]$ 表示 $u$ 所在的根子分支，即根到 $u$ 的路径经过的第一个儿子；根自身的标记为 $0$。

若两个端点位于同一个根子分支，路径不经过 $z$，答案直接为 $0$。其余情况下，路径经过根，可以拆成从根到两个端点的两条链。

**预处理一条根链之外的最小值**

对于非根节点 $u$，设 $b[u]$ 为它所在根子分支中，不在根到 $u$ 这条链上的最小点权；若不存在这样的点，就记为无穷大。根不属于任何子分支，令 $b[z]=\mathrm{INF}$。

先自底向上求每个子树的最小点权 $\operatorname{sub}[u]$。同时记录 $u$ 的儿子子树中最小、次小的 $\operatorname{sub}$，分别为 $\operatorname{mn}[u]$、$\operatorname{sn}[u]$，并用 $\operatorname{id}[u]$ 记录最小值来自哪个儿子。

再自顶向下计算 $\operatorname{out}[u]$：它表示同一根子分支内，挂在 $u$ 的严格祖先旁边、没有进入通向 $u$ 的儿子子树的最小点权。根的儿子没有这种旁支，初值都是无穷大。

对于非根节点 $u$ 的儿子 $v$，原有旁支和 $v$ 的兄弟子树共同构成新的旁支，因此

$$
\operatorname{out}[v]
=\min\left(\operatorname{out}[u],\min_{\substack{w\text{ 是 }u\text{ 的儿子}\\w\ne v}}\operatorname{sub}[w]\right).
$$

排除 $v$ 后的儿子最小值，可以由 $\operatorname{mn}[u]$、$\operatorname{sn}[u]$ 在常数时间内得到。链外剩余的点还包括 $u$ 的所有严格后代，所以

$$b[u]=\min\bigl(\operatorname{out}[u],\operatorname{mn}[u]\bigr).$$

代码用队列式数组记录遍历顺序，逆序处理子树信息，再顺序处理旁支信息，避免长链递归。

**常数时间回答查询**

对于经过根的路径，路径外的点分成三部分：端点 $u$ 所在分支的链外部分、端点 $v$ 所在分支的链外部分，以及其他完整的根子分支。前两部分的最小值就是 $b[u]$ 和 $b[v]$。

最后一部分只需在根子分支中排除至多两个。预先保存根的儿子子树中最小的三个 $\operatorname{sub}$ 及其分支编号，查询时检查这三个候选即可。若还有未被排除的分支，其中最小者一定在这三个候选内。

将上述最小值合并即可得到答案；如果结果仍为无穷大，说明没有路径外的点，输出 $n$。

**正确性**

当两端点处于同一个非空根子分支时，路径不含唯一权值为 $0$ 的点，故答案为 $0$。否则路径恰好是两条根链的并集。

对于一条根链，它所在分支的链外点，要么是终点的严格后代，要么位于某个严格祖先的其他儿子子树。两类分别由 $\operatorname{mn}$ 和 $\operatorname{out}$ 完整覆盖，递推不会纳入链上的点，因此 $b$ 恰好是所需最小值。

查询再加入两端分支之外的所有根子分支，就覆盖了全部路径外的点。根分支至多排除两个，前三小候选足以保留剩余最小值。由点权是排列，最终得到的路径外最小值就是 mex；路径外为空时答案为 $n$。

**复杂度**

两次遍历预处理共 $O(n)$，每次询问 $O(1)$，总时间 $O(n+m)$，空间 $O(n)$。

### 代码

独立源码：[linear.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=2e5+10,M=3,INF=0x3f3f3f3f;
int n,m,z,a[N],fa[N],bel[N],ord[N],sub[N];
int mn[N],sn[N],id[N],out[N],b[N];
vector<int>g[N];
P best[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        sub[i]=a[i];
        if(!a[i])z=i;
    }
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);g[v].push_back(u);
    }
    int cnt=1;
    ord[1]=z;
    for(int i=1;i<=cnt;++i){
        int u=ord[i];
        for(int &v:g[u]){
            if(v==fa[u])continue;
            fa[v]=u;
            bel[v]=u==z?v:bel[u];
            ord[++cnt]=v;
        }
    }
    memset(mn,INF,sizeof mn);
    memset(sn,INF,sizeof sn);
    for(int i=n;i;--i){
        int u=ord[i],p=fa[u];
        if(!p)continue;
        sub[p]=min(sub[p],sub[u]);
        if(sub[u]<mn[p]){
            sn[p]=mn[p];mn[p]=sub[u];
            id[p]=u;
        }
        else sn[p]=min(sn[p],sub[u]);
    }
    fill(best,best+M,P(INF,0));
    for(int &v:g[z]){
        P p=P(sub[v],v);
        for(P &q:best){
            if(p<q)swap(p,q);
        }
    }
    out[z]=INF;
    for(int i=1;i<=n;++i){
        int u=ord[i];
        b[u]=u==z?INF:min(out[u],mn[u]);
        for(int &v:g[u]){
            if(v==fa[u])continue;
            if(u==z)out[v]=INF;
            else out[v]=min(out[u],id[u]==v?sn[u]:mn[u]);
        }
    }
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        if(bel[u] && bel[u]==bel[v]){
            puts("0");
            continue;
        }
        int ans=min(b[u],b[v]);
        for(P &p:best){
            if(p.second!=bel[u] && p.second!=bel[v]){
                ans=min(ans,p.first);
            }
        }
        printf("%d\n",ans==INF?n:ans);
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 造题计划（下）

标签：`动态规划` · `离散凸性` · `优先队列` · `拉格朗日优化`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adce73ca67df0b81749b6b1)。本次重构的本地验证见 [VALIDATION.md](../tests/202509/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05477ce5d1fced2e44e5ea)。

<!-- refactor-online:E:end -->

### 题意

共 $n$ 天，第 $i$ 天上午至多造一题，费用为 $a_i$；下午至多验一题，费用为 $b_i$。验题之前必须已经造好，同一天上午造的题可以在下午验。给定预算 $m$，求最多能完成多少题。

输入 `n m`，再输入两行造题、验题费用。$n\le5\times10^5$，费用在 $[1,10^9]$ 内，预算不超过 $10^{18}$。

输出预算内最多能完成的题数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202509E/) · [曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202509E)。

### 题解

**从余额 DP 开始**

余额 $h$ 表示已造未验的题数，始终不能为负。若固定完成题数，直接 DP 需要同时记录天数、余额和完成数，状态过多。给每完成一题奖励 $\lambda$，把验题费用改为 $b_i-\lambda$，便只需最小化“真实费用减奖励”。

设 $F(h)$ 为余额 $h$ 的最小调整费用。它是离散凸函数，即相邻差 $D_h=F(h)-F(h-1)$ 不递减，用小根堆保存全部斜率，并另外保存 $F(0)$。

上午可以不造或造一题，转移相当于与序列 $(0,a_i)$ 做最小卷积，也就是把斜率 $a_i$ 插入堆。下午令 $c=b_i-\lambda$，转移为：

$$F_{\mathrm{new}}(h)=\min(F(h),F(h+1)+c).$$

若最小斜率 $d$ 满足 $d+c<0$，把 $F(0)$ 加上 $d+c$，弹出 $d$ 并插入 $-c$；否则保持不变。相邻候选在斜率首次超过 $-c$ 处切换，因此斜率多重集恰好替换一次。

**同时恢复题数**

堆元素和 $F(0)$ 都用二元组 `(调整费用, -完成数)`，按字典序比较，费用相等时选择完成数最多的方案。加减二元组，就是对整个目标函数做相同运算；最终从第二维恢复完成数，再加回奖励得到真实费用。

**找到预算对应的断点**

固定完成数的最小费用 $C(k)$ 是整数离散凸函数。可将它看作单位容量费用流的最小费用，逐次增广的边际费用不递减。二分最大的整数奖励 `l`，使选出的方案仍在预算内；下一个奖励 `r=l+1` 对应一段边际费用均为 `r` 的题目。

若 `l` 对应真实费用和题数为 $(cost,cnt)$，还可以增加的题数是：

$$\left\lfloor\frac{m-cost}{r}\right\rfloor.$$

先判断全部题都能完成的情况，避免二分没有越过预算的右边界。每题造、验费用之和至多 $2\times10^9$，所以右边界取 $2\times10^9+1$。

**复杂度**

每次参数求解 $O(n\log n)$，总时间 $O(n\log n\log(2\times10^9))$，空间 $O(n)$。费用、预算及乘积使用 64 位整数。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const int N=5e5+10;
int n;
ll m,sum,a[N],b[N];
P operator+(P x,P y){
    return {x.first+y.first,x.second+y.second};
}
P operator-(P x){
    return {-x.first,-x.second};
}
pair<ll,ll> check(ll k){
    priority_queue<P,vector<P>,greater<P>> q;
    P dp={0,0};
    for(int i=1;i<=n;++i){
        q.push({a[i],0});
        P val={b[i]-k,-1};
        P cur=q.top()+val;
        if(cur<P{0,0}){
            dp=dp+cur;
            q.pop();
            q.push(-val);
        }
    }
    ll cnt=-dp.second;
    return {dp.first+k*cnt,cnt};
}
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&b[i]);
        sum+=b[i];
    }
    if(sum<=m){
        printf("%d\n",n);
        return 0;
    }
    ll l=0,r=(ll)2e9+1;
    while(l+1<r){
        ll mid=(l+r)/2;
        P res=check(mid);
        if(res.first<=m)l=mid;
        else r=mid;
    }
    auto [cost,cnt]=check(l);
    printf("%lld\n",cnt+(m-cost)/r);
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202509/VALIDATION.md)
- [online-update-report.json](../tests/202509/online-update-report.json)
- [online-verdicts.json](../tests/202509/online-verdicts.json)
- [performance-revision/202509D/cpp17-compilation.json](../tests/202509/performance-revision/202509D/cpp17-compilation.json)
- [performance-revision/202509D/independent-review-review.json](../tests/202509/performance-revision/202509D/independent-review-review.json)
- [performance-revision/202509D/independent-review-review.md](../tests/202509/performance-revision/202509D/independent-review-review.md)
- [performance-revision/202509D/initial-linear-report.json](../tests/202509/performance-revision/202509D/initial-linear-report.json)
- [performance-revision-D.json](../tests/202509/performance-revision-D.json)
- [prose-final-review.json](../tests/202509/prose-final-review.json)
- [report.json](../tests/202509/report.json)
- [retained_oracles.py](../tests/202509/retained_oracles.py)
- [style-before.json](../tests/202509/style-before.json)
- [style-followup-report.json](../tests/202509/style-followup-report.json)
- [verify-style-followup.py](../tests/202509/verify-style-followup.py)
- [verify.py](../tests/202509/verify.py)

<!-- local-validation-attachments:end -->
