---
title: "CSP 201809 五题题解"
contest: "201809"
contest_month: "2018-09"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "数组", "同时更新", "双指针", "区间交集", "树", "祖先关系", "字符串", "贪心", "记忆化搜索", "动态规划", "字典序", "线性递推", "多项式", "NTT", "生成函数"]
status: "published"
problems: [{"id": "A", "title": "卖菜", "tags": ["数组", "同时更新"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "当前重构版：C++17 编译通过，1 个保存用例、60 组独立对拍及 1 组边界/压力通过；UBSan 共 62 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda03c74ace1cba9a1f8b7"}}, {"id": "B", "title": "买菜", "tags": ["双指针", "区间交集"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "当前重构版：C++17 编译通过，1 个保存用例、100 组独立对拍及 1 组边界/压力通过；UBSan 共 102 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda10674ace1cba9a1f946"}}, {"id": "C", "title": "元素选择器", "tags": ["树", "祖先关系", "字符串", "贪心"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "当前重构版：C++17 编译通过，1 个保存用例、100 组独立对拍及 1 组边界/压力通过；UBSan 共 102 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda1a174ace1cba9a1f972"}}, {"id": "D", "title": "再卖菜", "tags": ["记忆化搜索", "动态规划", "字典序"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "当前重构版：C++17 编译通过，1 个保存用例、90 组独立对拍及 2 组边界/压力通过；UBSan 共 93 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda24c74ace1cba9a1f9b0"}}, {"id": "E", "title": "线性递推式", "tags": ["线性递推", "多项式", "NTT", "生成函数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "当前重构版：C++17 编译通过，3 个保存用例、580 组独立对拍及 4 组边界/压力通过；UBSan 共 587 组通过。尚未在线重新提交；oj 字段保留原版记录。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201809E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201809E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda98c74ace1cba9a1fe91"}}]
---

# CSP 201809 五题题解

[原页面](https://code92007.github.io/csp/#/contest/201809) · [验证记录](../tests/201809/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 卖菜

标签：`数组` · `同时更新`

本地：62 组优化版、62 组 UBSan 验证通过，详见 [验证记录](../tests/201809/VALIDATION.md)。

### 题意

一排商店同时调整菜价：第二天的价格等于自己和相邻商店第一天价格的平均值，向下取整。两端只有一个邻居，求全部新价格。

输入商店数 $n$，再输入 $n$ 个原价。$2\le n\le1000$，原价为不超过 $10^4$ 的正整数。

输出一行 $n$ 个整数，依次表示第二天的价格。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809A)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809A/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adda03c74ace1cba9a1f8b7)（accepted，100 分；复刻评测）。

### 题解

保存完整的原价数组。对于位置 $i$，求区间 $[\max(0,i-1),\min(n-1,i+1)]$ 内的价格之和，再除以区间长度。

**正确性**

区间恰好包含本店及存在的邻居，正整数除法实现向下取整。所有计算始终读取原数组，符合同时调整的要求；若边算边覆盖，就会误用已经更新的价格。

**复杂度**

每家最多读取三个数，时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;++i){
        int l=max(0,i-1),r=min(n-1,i+1),sum=0;
        for(int j=l;j<=r;++j){
            sum+=a[j];
        }
        printf("%d%c",sum/(r-l+1),i==n-1?'\n':' ');
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 买菜

标签：`双指针` · `区间交集`

本地：102 组优化版、102 组 UBSan 验证通过，详见 [验证记录](../tests/201809/VALIDATION.md)。

### 题意

两个人各有 $n$ 个装车时间段，求两人同时装车的总时长。区间 $[s,t]$ 的时长为 $t-s$，仅在端点接触时贡献为零。

输入 $n$，接着分别输入两人的 $n$ 个区间。$1\le n\le2000$，时间在 $[1,10^6]$ 内；每个人的区间按时间递增，且前一区间的右端严格小于后一区间的左端。

输出一个整数，表示总时长。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809B)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809B/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adda10674ace1cba9a1f946)（accepted，100 分；复刻评测）。

### 题解

用两个指针分别指向当前区间，交集长度为

$$\max\bigl(0,\min(r_1,r_2)-\max(l_1,l_2)\bigr).$$

累加交集后，移动右端点较早的区间；另一个区间保留，继续尝试与后续区间相交。右端相同时移动任意一边即可。

**正确性**

结束较早的区间，不可能再与另一人更晚的区间产生正长度交集，因此可以安全丢弃。每个人的区间互不相交，累加也不会重复计时。

**复杂度**

每个指针最多移动 $n$ 次，时间 $O(n)$，空间 $O(n)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=2010;
int n,i,j,ans;
P a[N],b[N];
int main(){
    scanf("%d",&n);
    for(int k=0;k<n;++k){
        scanf("%d%d",&a[k].first,&a[k].second);
    }
    for(int k=0;k<n;++k){
        scanf("%d%d",&b[k].first,&b[k].second);
    }
    while(i<n && j<n){
        int l=max(a[i].first,b[j].first);
        int r=min(a[i].second,b[j].second);
        ans+=max(0,r-l);
        if(a[i].second<b[j].second)++i;
        else ++j;
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. 元素选择器

标签：`树` · `祖先关系` · `字符串` · `贪心`

本地：102 组优化版、102 组 UBSan 验证通过，详见 [验证记录](../tests/201809/VALIDATION.md)。

### 题意

文档按行描述一棵元素树，每级缩进用两个点号表示。每个元素有标签和可选的 `#id`：标签不区分大小写，id 区分大小写。查询可为标签、id，或用空格连接的后代选择器链；链中相邻条件要求严格祖先关系，允许跨过若干层。

输入 `n m`，接着输入 $n$ 行文档和 $m$ 行选择器。$1\le n\le100$，$1\le m\le10$，每行长度不超过 $80$。输入合法，文档中的 id 各不相同。

每个查询输出一行，先输出选中数量，再按递增顺序输出元素行号。父元素被选中不会使未匹配的后代自动入选。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809C)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809C/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adda1a174ace1cba9a1f972)（accepted，100 分；复刻评测）。

### 题解

**建立父指针**

维护各深度最近出现的元素。当前行深度为 $d$，父亲就是深度 $d-1$ 的最近元素，再更新深度 $d$ 的记录。标签及标签选择器统一转小写，id 保留原样。

**沿祖先链匹配**

枚举元素作为最后一级选择器的候选，先检查自身是否匹配。然后沿父指针向上，依次寻找前一个选择器对应的最近祖先；命中后继续向更高处寻找，不重复使用同一个元素。

**正确性**

若存在合法匹配，选择最近的可用祖先只会为前面的条件留下更多祖先，不会减少可选范围。因此从右向左贪心能找到匹配，当且仅当候选确实满足整条选择器链。按行号枚举候选即可得到递增且无重复的结果。

**复杂度**

设树高为 $h$、单行长度上限为 $L$，每次查询时间 $O(L+nh)$，存储文档与查询的空间 $O(nL)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=110,M=90;
int n,m,fa[N],st[N],top,ans[N],cnt;
char s[M];
string tag[N],id[N],sel[M];
string lower(string s){
    for(char &c:s){
        c=tolower((unsigned char)c);
    }
    return s;
}
bool match(int u,int k){
    if(sel[k][0]=='#')return id[u]==sel[k];
    return tag[u]==sel[k];
}
int main(){
    scanf("%d%d",&n,&m);
    fgets(s,M,stdin);
    for(int i=1;i<=n;++i){
        fgets(s,M,stdin);
        int d=0;
        while(s[d]=='.'){
            ++d;
        }
        top=d/2;
        fa[i]=top?st[top]:0;
        istringstream in(s+d);
        in>>tag[i]>>id[i];
        tag[i]=lower(tag[i]);
        st[++top]=i;
    }
    while(m--){
        fgets(s,M,stdin);
        istringstream in(s);
        int len=0;
        string t;
        while(in>>t){
            sel[len++]=t[0]=='#'?t:lower(t);
        }
        cnt=0;
        for(int i=1;i<=n;++i){
            int k=len-1;
            if(!match(i,k))continue;
            --k;
            int u=fa[i];
            while(k>=0 && u){
                if(match(u,k))--k;
                u=fa[u];
            }
            if(k<0)ans[cnt++]=i;
        }
        printf("%d",cnt);
        for(int i=0;i<cnt;++i){
            printf(" %d",ans[i]);
        }
        puts("");
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 再卖菜

标签：`记忆化搜索` · `动态规划` · `字典序`

本地：93 组优化版、93 组 UBSan 验证通过，详见 [验证记录](../tests/201809/VALIDATION.md)。

### 题意

已知一排商店第二天的菜价。第二天的价格等于自己和相邻商店第一天价格的平均值，向下取整；两端只涉及两家。恢复一个全部为正整数、且字典序最小的第一天价格序列。

输入商店数 $n$ 及第二天的 $n$ 个价格 $b_i$。$2\le n\le300$，$1\le b_i\le100$，保证有解。第一天的价格可以超过 $100$。

输出一行 $n$ 个正整数，表示字典序最小的原价序列。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809D)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809D/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adda24c74ace1cba9a1f9b0)（accepted，100 分；复刻评测）。

### 题解

**缩小每步的选择范围**

已知相邻原价 $x,y$，由中间商店的价格 $b_i$ 可得

$$3b_i\le x+y+z\le3b_i+2.$$

因此下一项 $z$ 只能是 $3b_i-x-y$ 及随后两个整数，再排除非正数。端点则要求两项之和为 $2b_i$ 或 $2b_i+1$。

**记忆化后缀可行性**

定义 `check(i,x,y)`：已经固定 $a_{i-1}=x,a_i=y$，能否完成后缀并满足 $b_i,\ldots,b_{n-1}$。到末尾检查 $(x+y)/2=b_i$；否则枚举至多三个下一项，递归判断并缓存结果。

原价只需考虑 $1$ 到 $302$。任一三项和最多为 $302$，各项均为正数；端点两项和最多为 $201$。因此有限状态覆盖所有可能的解，缓存用单字节保存未知、失败和成功三态。

**按字典序重建**

先升序枚举 $a_0$，再升序枚举满足首端均值的 $a_1$，保留第一个后缀可行的组合。之后每步也选择最小的可行下一项。

每次只选取存在完整后缀的最小值，与其他解在第一个不同位置比较，该值一定不大于其他解，因此最终序列字典序最小。

**复杂度**

记原价容量为 $V=303$，最多 $O(nV^2)$ 个状态，每个状态至多三个转移。时间、空间均为 $O(nV^2)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=310,M=303;
int n,a[N],b[N];
signed char dp[N][M][M];
bool check(int i,int x,int y){
    if(x<1 || x>=M || y<1 || y>=M)return false;
    signed char &v=dp[i][x][y];
    if(v!=-1)return v;
    if(i==n-1)return v=((x+y)/2==b[i]);
    int l=3*b[i]-x-y;
    for(int z=l;z<=l+2;++z){
        if(check(i+1,y,z))return v=1;
    }
    return v=0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&b[i]);
    }
    memset(dp,-1,sizeof dp);
    for(int x=1;x<=2*b[0] && !a[0];++x){
        int l=max(1,2*b[0]-x),r=2*b[0]+1-x;
        for(int y=l;y<=r;++y){
            if(check(1,x,y)){
                a[0]=x,a[1]=y;
                break;
            }
        }
    }
    for(int i=1;i<n-1;++i){
        int l=3*b[i]-a[i-1]-a[i];
        for(int z=l;z<=l+2;++z){
            if(check(i+1,a[i],z)){
                a[i+1]=z;
                break;
            }
        }
    }
    for(int i=0;i<n;++i){
        printf("%d%c",a[i],i==n-1?'\n':' ');
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 线性递推式

标签：`线性递推` · `多项式` · `NTT` · `生成函数`

本地：587 组优化版、587 组 UBSan 验证通过，详见 [验证记录](../tests/201809/VALIDATION.md)。

### 题意

给定 $a_0=1$，对于 $n>0$ 有

$$a_n=\sum_{i=1}^{\min(n,m)}k_i a_{n-i}\pmod{998244353}.$$

求连续区间 $a_l,a_{l+1},\ldots,a_r$。

输入 `m l r` 及 $m$ 个系数。$1\le m\le10^5$，$1\le l\le10^{12}$，$0\le r-l\le3\times10^5$，$0\le k_i<998244353$。

输出 $r-l+1$ 行，依次给出区间内各项对 $998244353$ 取模的值。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201809E)；[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201809E/)。

原版评测：[记录](https://oj.shumeng.tech/record/6adda98c74ace1cba9a1fe91)（accepted，100 分；复刻评测）。

### 题解

**第一步：求递推序列的前缀**

令 $C(x)=1-k_1x-\cdots-k_mx^m$。由递推式可得生成函数

$$A(x)=\sum_{i\ge0}a_ix^i=\frac1{C(x)}.$$

使用多项式牛顿迭代 $B_{\mathrm{new}}=B(2-CB)\bmod x^{2t}$，每次把逆多项式的已知长度翻倍；卷积用模 $998244353$ 下的 NTT 计算。

**第二步：把巨大下标压回 $m$ 维**

定义特征多项式 $P(x)=x^m-k_1x^{m-1}-\cdots-k_m$，计算

$$R(x)=x^l\bmod P(x)=\sum_{j=0}^{m-1}r_jx^j.$$

从最高二进制位向最低位处理 $l$。若已处理前缀为 $s$，保持 $R=x^s\bmod P$；下一位为 $b$ 时，更新为 $R^2x^b\bmod P$。

平方后用逆序多项式除法求余：逆序 $P$ 恰好是 $C$，因此可复用 $1/C$ 的前缀。乘 $x$ 只需移位，再利用 $x^m=k_1x^{m-1}+\cdots+k_m$ 消去最高项，耗时 $O(m)$。次数较小时保留实际长度。

**第三步：一次卷积求出整个区间**

递推关系保证任意 $t\ge0$ 都有

$$a_{l+t}=\sum_{j=0}^{m-1}r_ja_{t+j}.$$

将 $R$ 逆序，与序列前缀卷积，下标 $m-1+t$ 的项就是所求值。若代码只保留了 $u$ 个系数，则求出 $a_0$ 至 $a_{u+d-2}$ 即可，读取卷积下标 $u-1+t$，其中 $d=r-l+1$。

$m=1$ 时直接求等比数列；实现也兼容 $l=0$ 和全零系数。

**降低 NTT 常数**

平方只变换一个因子；固定除式及其逆多项式缓存频域结果。牛顿迭代扩展到 $2t$ 项时，仅计算误差的高半段：循环卷积回卷只影响将被舍弃的低半段，因此每步用五次长度 $2t$ 的变换。

正变换采用 DIF、逆变换采用 DIT，共享倒位序的频率排列，并缓存各层单位根。多项式及变换长度随阶段变化，使用动态存储保留实际长度。

**正确性**

二进制更新保持 $R=x^s\bmod P$，最后得到 $x^l$ 的余式。除法中减去的 $P$ 的倍数，对应递推等式的线性组合，在任意非负位移处均为零。因此余式给出的线性组合成立，最终卷积同时计算全部位移。

**复杂度**

时间 $O(m\log m\log(l+1)+(m+d)\log(m+d))$，空间 $O(m+d)$。这里的小规模直接乘法、平方优化、频域缓存及逆多项式优化均予以保留。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> poly;
const int mod=998244353;
int m,d;
ll l,r;
int qpow(int a,ll n){
    int res=1;
    for(;n;n>>=1,a=(ll)a*a%mod){
        if(n&1)res=(ll)res*a%mod;
    }
    return res;
}
int size(int x){
    int n=1;
    while(n<x){
        n<<=1;
    }
    return n;
}
void ntt(poly &a,bool op){
    static poly w{0,1},iw{0,1};
    int n=a.size();
    while((int)w.size()<n){
        int h=w.size();
        w.resize(h*2);iw.resize(h*2);
        int x=qpow(3,(mod-1)/(h*2)),y=qpow(x,mod-2);
        w[h]=iw[h]=1;
        for(int j=1;j<h;++j){
            w[h+j]=(ll)w[h+j-1]*x%mod;
            iw[h+j]=(ll)iw[h+j-1]*y%mod;
        }
    }
    if(!op){
        for(int h=n/2;h;h>>=1){
            for(int p=0;p<n;p+=h*2){
                for(int j=0;j<h;++j){
                    int u=a[p+j],v=a[p+j+h];
                    int x=u+v,y=u-v;
                    if(x>=mod)x-=mod;
                    if(y<0)y+=mod;
                    a[p+j]=x;
                    a[p+j+h]=(ll)y*w[h+j]%mod;
                }
            }
        }
    }
    else{
        for(int h=1;h<n;h<<=1){
            for(int p=0;p<n;p+=h*2){
                for(int j=0;j<h;++j){
                    int u=a[p+j],v=(ll)a[p+j+h]*iw[h+j]%mod;
                    int x=u+v,y=u-v;
                    if(x>=mod)x-=mod;
                    if(y<0)y+=mod;
                    a[p+j]=x,a[p+j+h]=y;
                }
            }
        }
        int v=qpow(n,mod-2);
        for(int &x:a){
            x=(ll)x*v%mod;
        }
    }
}
poly mul(poly a,poly b){
    if(a.empty() || b.empty())return {};
    int len=a.size()+b.size()-1;
    if(min(a.size(),b.size())<=32){
        poly c(len);
        for(int i=0;i<(int)a.size();++i){
            for(int j=0;j<(int)b.size();++j){
                c[i+j]=(c[i+j]+(ll)a[i]*b[j])%mod;
            }
        }
        return c;
    }
    int n=size(len);
    a.resize(n);b.resize(n);
    ntt(a,0);ntt(b,0);
    for(int i=0;i<n;++i){
        a[i]=(ll)a[i]*b[i]%mod;
    }
    ntt(a,1);
    a.resize(len);
    return a;
}
poly inv(const poly &a,int len){
    poly b{qpow(a[0],mod-2)};
    while((int)b.size()<len){
        int h=b.size(),n=h*2;
        poly f=b,g(n);
        f.resize(n);
        copy_n(a.begin(),min(n,(int)a.size()),g.begin());
        ntt(f,0);ntt(g,0);
        for(int i=0;i<n;++i){
            g[i]=(ll)g[i]*f[i]%mod;
        }
        ntt(g,1);
        fill(g.begin(),g.begin()+h,0);
        ntt(g,0);
        for(int i=0;i<n;++i){
            g[i]=(ll)g[i]*f[i]%mod;
        }
        ntt(g,1);
        b.resize(n);
        for(int i=h;i<n;++i){
            b[i]=g[i]?mod-g[i]:0;
        }
    }
    b.resize(len);
    return b;
}
struct rem{
    int m,n;
    poly c,b,f,g;
    rem(const poly &a):m(a.size()-1),n(size(m*2-1)),
        c(a.rbegin(),a.rend()),b(inv(a,m)){}
    poly square(const poly &a){
        int len=a.size()*2-1;
        poly v;
        if(a.size()<=32)v=mul(a,a);
        else{
            v=a;
            v.resize(size(len));
            ntt(v,0);
            for(int &x:v){
                x=(ll)x*x%mod;
            }
            ntt(v,1);
            v.resize(len);
        }
        if(len<=m)return v;
        int k=len-m;
        poly q(v.rbegin(),v.rbegin()+k);
        if(k<m-1 || m<=32){
            poly t(b.begin(),b.begin()+k);
            q=mul(q,t);
            q.resize(k);
            reverse(q.begin(),q.end());
            t=mul(q,c);
            v.resize(m);
            for(int i=0;i<m;++i){
                v[i]-=t[i];
                if(v[i]<0)v[i]+=mod;
            }
        }
        else{
            if(f.empty()){
                f=c;g=b;
                f.resize(n);g.resize(n);
                ntt(f,0);ntt(g,0);
            }
            q.resize(n);
            ntt(q,0);
            for(int i=0;i<n;++i){
                q[i]=(ll)q[i]*g[i]%mod;
            }
            ntt(q,1);
            q.resize(k);
            reverse(q.begin(),q.end());
            q.resize(n);
            ntt(q,0);
            for(int i=0;i<n;++i){
                q[i]=(ll)q[i]*f[i]%mod;
            }
            ntt(q,1);
            v.resize(m);
            for(int i=0;i<m;++i){
                v[i]-=q[i];
                if(v[i]<0)v[i]+=mod;
            }
        }
        return v;
    }
    void shift(poly &a){
        if((int)a.size()<m){
            a.insert(a.begin(),0);
            return;
        }
        int t=a.back();
        for(int i=m-1;i>=0;--i){
            int v=i?a[i-1]:0;
            v=(v-(ll)t*c[i])%mod;
            if(v<0)v+=mod;
            a[i]=v;
        }
    }
};
int main(){
    scanf("%d%lld%lld",&m,&l,&r);
    d=r-l+1;
    poly c(m+1);
    c[0]=1;
    for(int i=1,k;i<=m;++i){
        scanf("%d",&k);
        c[i]=k?mod-k:0;
    }
    if(m==1){
        int k=c[1]?mod-c[1]:0,a=qpow(k,l);
        for(int i=0;i<d;++i){
            printf("%d\n",a);
            a=(ll)a*k%mod;
        }
        return 0;
    }
    poly a{1};
    if(l){
        rem tr(c);
        int h=0;
        while((1ll<<(h+1))<=l){
            ++h;
        }
        for(int i=h;i>=0;--i){
            a=tr.square(a);
            if((l>>i)&1)tr.shift(a);
        }
    }
    int len=a.size();
    poly b=inv(c,len+d-1);
    reverse(a.begin(),a.end());
    poly ans=mul(a,b);
    for(int i=0;i<d;++i){
        printf("%d\n",ans[len-1+i]);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201809/VALIDATION.md)
- [cases.json](../tests/201809/cases.json)
- [compile.json](../tests/201809/compile.json)
- [current-sources.json](../tests/201809/current-sources.json)
- [extra.py](../tests/201809/extra.py)
- [naming-followup.json](../tests/201809/naming-followup.json)
- [summary.json](../tests/201809/summary.json)

<!-- local-validation-attachments:end -->
