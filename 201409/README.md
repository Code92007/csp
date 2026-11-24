---
title: "CSP 201409 五题题解"
contest: "201409"
contest_month: "2014-09"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "集合", "计数", "网格覆盖", "面积并", "字符串匹配", "大小写转换", "多源BFS", "最短路", "网格", "轮廓线DP", "状态压缩", "矩阵快速幂"]
status: "published"
problems: [{"id": "A", "title": "相邻数对", "tags": ["集合", "计数"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a3fae5d1fced2e45aeb9", "source_sha256": "9479dd8401bd3c673c4276e82c5cbacda77b472ce6d1bb026df64d67d9f04f24", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:50:35.613384+00:00"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addbe9474ace1cba9a2168f"}}, {"id": "B", "title": "画图", "tags": ["网格覆盖", "面积并"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a43ce5d1fced2e45af87", "source_sha256": "2c5c82af0cd1afde575aa2cbff37b22afcffec95197e535d728594b901536247", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:52:06.764724+00:00"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addbf1c74ace1cba9a216e8"}}, {"id": "C", "title": "字符串匹配", "tags": ["字符串匹配", "大小写转换"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409C/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a47ae5d1fced2e45b01f", "source_sha256": "b3a839e2b26d73c7353f1ddab30d26d505c2bc8fe38872a9ab55e60799cffaf9", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:52:09.042323+00:00"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addbfa574ace1cba9a21719"}}, {"id": "D", "title": "最优配餐", "tags": ["多源BFS", "最短路", "网格"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a4b7e5d1fced2e45b0b6", "source_sha256": "aaa7c38a2377bfba59e3dc0ca48e33c89a4f0de974f9d48c513d5377552dc13e", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:54:21.001194+00:00"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc02f74ace1cba9a217cd"}}, {"id": "E", "title": "拼图", "tags": ["轮廓线DP", "状态压缩", "矩阵快速幂"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201409E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201409E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05a4f5e5d1fced2e45b154", "source_sha256": "6ac324fc58dec85d44a521b16b3bd50bc1ef0ce65f121c758324b8c0463d635a", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T14:54:24.330306+00:00"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addc0c074ace1cba9a21859"}}]
---

# CSP 201409 五题题解

[返回总目录](../README.md) · [本地验证](../tests/201409/VALIDATION.md)


<a id="problem-a"></a>

## A. 相邻数对

标签：`集合` · `计数`

本地验证：63 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201409/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6addbe9474ace1cba9a2168f)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addbe9474ace1cba9a2168f)（复刻评测）。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a3fae5d1fced2e45aeb9)。

<!-- refactor-online:A:end -->

### 题意

给定互不相同的非负整数，求数值恰好相差 1 的无序数对数量。

输入整数个数 n 和各个整数。这里的相邻指值相邻，与输入位置无关。

输出满足条件的数对数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409A)。

### 题解

把所有数放入集合，枚举x，只检查x+1是否存在，存在就加一。不再检查x-1，避免同一对被计算两次。

每个合法数对唯一由较小的那个数代表，因此不重不漏。set实现时间 $O(n\log n)$，空间 $O(n)$；这里“相邻”指值相邻，不是输入位置相邻。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,ans;
set<int> a;
int main(){
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        a.insert(x);
    }
    for(const int &x:a){
        ans+=a.count(x+1);
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 画图

标签：`网格覆盖` · `面积并`

本地验证：103 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201409/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6addbf1c74ace1cba9a216e8)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addbf1c74ace1cba9a216e8)（复刻评测）。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a43ce5d1fced2e45af87)。

<!-- refactor-online:B:end -->

### 题意

在整数坐标纸上涂若干轴对齐矩形，求涂色区域的总面积，重叠部分只计一次。

输入矩形数和每个矩形的左下角、右上角坐标。矩形数≤100，坐标范围为 0…100。

输出总涂色面积。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409B)。

### 题解

用布尔数组表示单位小方格：`a[x][y]` 代表 [x,x+1]×[y,y+1]。矩形(x1,y1,x2,y2)覆盖的格子下标为x1≤x<x2、y1≤y<y2，逐格置true，最后数true个数。

整数边界矩形恰好由这些单位格组成，布尔值使重叠格只计一次，因此数量就是并集面积。右上界必须用严格小于，不能把顶点数当成面积。时间 $O(nV^2)$，空间 $O(V^2)$，V=100。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,x,y,u,v,ans;
bool a[N][N];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&x,&y,&u,&v);
        for(int i=x;i<u;++i){
            for(int j=y;j<v;++j){
                a[i][j]=true;
            }
        }
    }
    for(auto &row:a){
        for(bool &val:row){
            ans+=val;
        }
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. 字符串匹配

标签：`字符串匹配` · `大小写转换`

本地验证：103 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201409/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6addbfa574ace1cba9a21719)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addbfa574ace1cba9a21719)（复刻评测）。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a47ae5d1fced2e45b01f)。

<!-- refactor-online:C:end -->

### 题意

给定模式串和大小写敏感开关，从若干字符串中找出包含该模式的字符串。

输入模式串、开关和字符串数 n，随后是 n 个字符串，每串长度至多 100。开关为 0 时忽略大小写，为 1 时严格区分。

按输入顺序输出匹配的原字符串。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409C)。

### 题解

敏感模式直接查找子串；不敏感模式把模式和待匹配字符串的副本统一转小写，再用 find 查找。始终输出原字符串，不能输出转换后的副本。

大小写折叠后同一字母的两种形式映射到相同字符，因此子串匹配等价于题目定义。最坏时间 $O(nLM)$，L 为文本长、M 为模式长；额外空间 $O(L+M)$，本题范围无需额外实现 KMP。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int op,n;
char pat[N],s[N];
string lower(string str){
    for(char &c:str){
        c=tolower((unsigned char)c);
    }
    return str;
}
int main(){
    scanf("%s%d%d",pat,&op,&n);
    string p=op?pat:lower(pat);
    while(n--){
        scanf("%s",s);
        string key=op?s:lower(s);
        if(key.find(p)!=string::npos)puts(s);
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 最优配餐

标签：`多源BFS` · `最短路` · `网格`

本地验证：83 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201409/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6addc02f74ace1cba9a217cd)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addc02f74ace1cba9a217cd)（复刻评测）。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a4b7e5d1fced2e45b0b6)。

<!-- refactor-online:D:end -->

### 题意

n×n 网格中有餐厅、客户和不可经过的位置。餐厅供餐量无限，每份餐每移动一格花费 1，求满足全部客户的最低总配送费用。

输入 n、m、k、d，依次输入餐厅位置、客户位置与订餐量、障碍位置，范围为 $n\le1000$。多个客户可以位于同一坐标，保证可以送达。

输出最低总费用。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409D)。

### 题解

每个客户都独立选择最近餐厅即可，因为餐厅没有容量限制，不存在客户之间争用资源的问题。答案为每个位置的订餐量乘它到最近餐厅的距离之和。

把所有餐厅同时放进 BFS 队列，初始距离都为 0；其余位置未访问，障碍另作标记。这样 BFS 每一层同时扩展所有餐厅的波前，一个位置首次被访问时，距离就是所有源点到它的最短距离。相比逐餐厅搜索，只需遍历整个网格一次。

同一位置的多份订单必须累加，不能覆盖。网格四方向边权均为 1，BFS 的分层性质保证距离正确，独立选择最近餐厅则保证费用最小。时间 $O(n^2+m+k+d)$，空间 $O(n^2)$；总费用用 64 位。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=4;
int n,m,k,d;
ll ans;
int dx[M]={1,-1,0,0},dy[M]={0,0,1,-1};
vector<int> dis,q;
vector<ll> need;
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&d);
    dis.assign(n*n,-1);
    need.resize(n*n);
    for(int i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        int u=(x-1)*n+y-1;
        if(dis[u]<0){
            dis[u]=0;
            q.push_back(u);
        }
    }
    for(int i=0;i<k;++i){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        need[(x-1)*n+y-1]+=c;
    }
    for(int i=0;i<d;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        dis[(x-1)*n+y-1]=-2;
    }
    for(size_t p=0;p<q.size();++p){
        int u=q[p];
        ans+=need[u]*dis[u];
        for(int i=0;i<M;++i){
            int x=u/n+dx[i],y=u%n+dy[i];
            if(x<0 || x>=n || y<0 || y>=n)continue;
            int v=x*n+y;
            if(dis[v]!=-1)continue;
            dis[v]=dis[u]+1;
            q.push_back(v);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-e"></a>

## E. 拼图

标签：`轮廓线DP` · `状态压缩` · `矩阵快速幂`

本地验证：28 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201409/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6addc0c074ace1cba9a21859)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addc0c074ace1cba9a21859)（复刻评测）。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05a4f5e5d1fced2e45b154)。

<!-- refactor-online:E:end -->

### 题意

用由 3 个单位格组成的 L 形拼图铺满 $n\times m$ 的矩形。拼图可以旋转，但不能重叠或越界；每块是一个 $2\times2$ 方块去掉一个角。

输入 `n m`，范围为 $n\le10^{15},m\le7$。

输出铺法数对 $10^9+7$ 取模的结果。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201409E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201409E)。

### 题解

**按行看边界**

一块 L 形最多跨相邻两行。用 $m$ 位二进制表示当前行中哪些格已经被上一行放下的拼图占据。固定上一行留下的占用状态 `st`，用 `S` 记录当前行填充过程中的占用情况，`next` 记录下一行已占的格子，递归枚举得到转移次数 `a[st][next]`。

递归每次找当前行最左侧空格，枚举所有覆盖它的合法 L 形。它所在的 $2\times2$ 方块左列可能是该列，也可能是前一列；再枚举缺失的四个角，检查当前行和下一行均无冲突。漏掉“方块左列在前一列”的情况，会漏算当前行只有一个右侧格、下一行占两个格的形状。

当前行全满时，把对应 `next` 的转移次数加一。总共只有 $2^m\le128$ 个边界状态；把行数 $n$ 作为矩阵幂次，初始向量仅空掩码为 1，最终答案是处理完 $n$ 行后空掩码的计数。非空掩码表示拼图伸出了最后一行，不能接受。

**正确性**

最左空格的覆盖拼图在任意完整铺法中唯一确定，递归不会重复或遗漏；边界掩码保留跨行影响的全部信息，矩阵乘法对中间边界求和正好拼接行段。

**复杂度**

预处理宽度对应的有限转移后，时间 $O(2^{3m}\log n)$，空间 $O(2^{2m})$。面积不是 3 的倍数时可直接输出 0。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> mat;
const int mod=1e9+7;
ll n;
int m,len,full,st;
mat a;
mat mul(const mat &x,const mat &y){
    int size=x.size();
    mat z(size,vector<int>(size));
    for(int i=0;i<size;++i){
        for(int k=0;k<size;++k){
            if(!x[i][k])continue;
            for(int j=0;j<size;++j){
                if(y[k][j]){
                    z[i][j]=(z[i][j]+1ll*x[i][k]*y[k][j])%mod;
                }
            }
        }
    }
    return z;
}
void dfs(int S,int next){
    if(S==full){
        ++a[st][next];
        return;
    }
    int c=0;
    while(S>>c&1){
        ++c;
    }
    for(int l=c-1;l<=c;++l){
        if(l<0 || l+1>=m)continue;
        for(int miss=0;miss<4;++miss){
            int up=0,down=0;
            for(int i=0;i<4;++i){
                if(i==miss)continue;
                if(i<2)up|=1<<(l+i);
                else down|=1<<(l+i-2);
            }
            if(!(up>>c&1) || (up&S) || (down&next))continue;
            dfs(S|up,next|down);
        }
    }
}
int main(){
    scanf("%lld%d",&n,&m);
    if((n%3)*(m%3)%3){
        puts("0");
        return 0;
    }
    len=1<<m;
    full=len-1;
    a.assign(len,vector<int>(len));
    for(st=0;st<len;++st){
        dfs(st,0);
    }
    vector<int> dp(len);
    dp[0]=1;
    while(n){
        if(n&1){
            vector<int> v(len);
            for(int i=0;i<len;++i){
                if(!dp[i])continue;
                for(int j=0;j<len;++j){
                    v[j]=(v[j]+1ll*dp[i]*a[i][j])%mod;
                }
            }
            dp.swap(v);
        }
        n>>=1;
        if(n)a=mul(a,a);
    }
    printf("%d\n",dp[0]);
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201409/VALIDATION.md)
- [boundaries.py](../tests/201409/boundaries.py)
- [e-branch-followup-report.json](../tests/201409/e-branch-followup-report.json)
- [e-mask-followup-report.json](../tests/201409/e-mask-followup-report.json)
- [e-mod-followup-report.json](../tests/201409/e-mod-followup-report.json)
- [online-update-report.json](../tests/201409/online-update-report.json)
- [online-verdicts.json](../tests/201409/online-verdicts.json)
- [refactor-report.json](../tests/201409/refactor-report.json)
- [statements.json](../tests/201409/statements.json)

<!-- local-validation-attachments:end -->
