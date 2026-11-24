---
title: "CSP 201703 五题题解"
contest: "201703"
contest_month: "2017-03"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "顺序模拟", "分组", "数组", "模拟", "Markdown", "字符串解析", "递归", "并查集", "排序", "最小瓶颈路径", "最小割", "网格图", "动态规划"]
status: "published"
problems: [{"id": "A", "title": "分蛋糕", "tags": ["顺序模拟", "分组"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版 C++17 编译通过；62 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6adda7e474ace1cba9a1fd43"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "B", "title": "学生排队", "tags": ["数组", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版 C++17 编译通过；101 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addaaf074ace1cba9a20058"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "C", "title": "Markdown", "tags": ["Markdown", "字符串解析", "递归"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版 C++17 编译通过；103 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addab8d74ace1cba9a2018a"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "D", "title": "地铁修建", "tags": ["并查集", "排序", "最小瓶颈路径"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版 C++17 编译通过；92 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addac2c74ace1cba9a20350"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "E", "title": "引水入城", "tags": ["最小割", "网格图", "动态规划"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版 C++17 编译通过；87 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201703E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201703E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addacc574ace1cba9a203ca"}, "original_validation": "C++17 编译通过；4 个保存样例/回归用例通过；80 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}]
---

# CSP 201703 五题题解

[返回总目录](../README.md) · [本地验证](../tests/201703/VALIDATION.md)


<a id="problem-a"></a>

## A. 分蛋糕

标签：`顺序模拟` · `分组`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201703/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6adda7e474ace1cba9a1fd43)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6adda7e474ace1cba9a1fd43)（复刻评测）。

### 题意

按编号依次把整块蛋糕分给朋友，当前朋友累计重量达到 k 后换下一个。蛋糕分完时，即便最后一人所得不足 k，也算分到蛋糕。

输入蛋糕数 n、重量阈值 k 和各块蛋糕的重量。每块蛋糕不可拆分，超过 k 的部分仍属于当前朋友。

输出分到蛋糕的朋友人数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703A)。

### 题解

累加当前朋友所得重量，达到k时人数加一并把当前重量清零。处理完若当前重量仍大于0，再把最后一人计入。

清零表示换人，超过k的部分仍属于上一人的整块蛋糕，不能把超出部分转给下一人。循环逐块执行题意，时间 $O(n)$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,k,sum,ans,x;
int main(){
    scanf("%d%d",&n,&k);
    while(n--){
        scanf("%d",&x);
        sum+=x;
        if(sum>=k){
            ++ans;
            sum=0;
        }
    }
    if(sum)++ans;
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-b"></a>

## B. 学生排队

标签：`数组` · `模拟`

本地验证：101 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201703/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addaaf074ace1cba9a20058)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addaaf074ace1cba9a20058)（复刻评测）。

### 题意

学生初始按学号 1…n 排队。每次指定学号 p，向后移动 q 个位置，q<0 时表示向前。

输入 n、操作数及各次的 p、q，n、操作数≤1000，保证移动后的目标位置合法。

输出最终的学号顺序。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703B)。

### 题解

用 `vector<int> a` 存队伍，每次先用 `find` 找到学号 `p` 的当前下标 `x`，删除该元素，再在下标 `x+q` 处插入 `p`。前后移动都用同一公式，插入位置可以是新数组末尾。

删除后，其余学生相对顺序不变；在目标下标插入恰好跨过q名学生，符合调整规则。特别注意p是学号，不是当前队伍位置。每次查找和移动均 $O(n)$，总时间 $O(nm)$，空间 $O(n)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,p,q;
vector<int> a;
int main(){
    scanf("%d%d",&n,&m);
    a.resize(n);
    iota(a.begin(),a.end(),1);
    while(m--){
        scanf("%d%d",&p,&q);
        int x=find(a.begin(),a.end(),p)-a.begin();
        a.erase(a.begin()+x);
        a.insert(a.begin()+x+q,p);
    }
    for(int i=0;i<n;++i){
        if(i)putchar(' ');
        printf("%d",a[i]);
    }
    puts("");
    return 0;
}
```

<a id="problem-c"></a>

## C. Markdown

标签：`Markdown` · `字符串解析` · `递归`

本地验证：103 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201703/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addab8d74ace1cba9a2018a)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addab8d74ace1cba9a2018a)（复刻评测）。

### 题意

把简化 Markdown 转成 HTML，支持段落、1—6 级标题、单层无序列表，以及强调和超链接。

输入 Markdown 文本至文件结束，各块之间有空行。两种行内格式可以相互嵌套，各自不超过一层；保证语法合法，普通文本不含需要 HTML 转义的特殊符号。

输出转换后的 HTML，删除块间空行，保留段落内部换行。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703C)。

### 题解

先以空行分块，依据块第一行判断段落、标题或列表。段落只在整块首尾加 p 标签；标题数井号并跳过其后空格；列表前后加 ul，每行去掉星号及其后空格再包 li。

行内从左向右扫描：下划线交替输出 em 开闭标签；左方括号读取链接文字和地址，地址原样放入 href，链接文字递归做行内转换。外层强调状态在处理整个链接时保留，从而同时支持“强调包含链接”和“链接文字包含强调”。输入保证语法合法，普通文本不含需 HTML 转义的特殊符号。

分块转换符合三类区块定义，行内递归按语法层次替换且不重复处理生成的标签。总时间与输入和输出长度线性相关，空间为当前块及递归临时字符串；题目限制嵌套层数，递归深度为常数。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
vector<string> v;
string s;
string html(const string &str){
    string ans;
    bool em=false;
    for(size_t i=0;i<str.size();){
        if(str[i]=='_'){
            ans+=em?"</em>":"<em>";
            em=!em;
            ++i;
        }
        else if(str[i]=='['){
            size_t r=str.find(']',i),t=str.find(')',r+2);
            ans+="<a href=\""+str.substr(r+2,t-r-2)+"\">";
            ans+=html(str.substr(i+1,r-i-1))+"</a>";
            i=t+1;
        }
        else ans+=str[i++];
    }
    return ans;
}
string skip(const string &str,size_t p){
    while(p<str.size() && str[p]==' '){
        ++p;
    }
    return str.substr(p);
}
void render(){
    if(v.empty())return;
    if(v[0][0]=='#'){
        size_t k=v[0].find_first_not_of('#');
        string tag="h"+to_string(k);
        string text=html(skip(v[0],k));
        printf("<%s>%s</%s>\n",tag.c_str(),text.c_str(),tag.c_str());
    }
    else if(v[0][0]=='*'){
        puts("<ul>");
        for(string &str:v){
            printf("<li>%s</li>\n",html(skip(str,1)).c_str());
        }
        puts("</ul>");
    }
    else{
        printf("<p>");
        for(size_t i=0;i<v.size();++i){
            if(i)putchar('\n');
            printf("%s",html(v[i]).c_str());
        }
        puts("</p>");
    }
    v.clear();
}
bool read(){
    s.clear();
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        s+=char(c);
    }
    return c!=EOF || !s.empty();
}
int main(){
    while(read()){
        if(s.empty())render();
        else v.push_back(s);
    }
    render();
    return 0;
}
```

<a id="problem-d"></a>

## D. 地铁修建

标签：`并查集` · `排序` · `最小瓶颈路径`

本地验证：92 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201703/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addac2c74ace1cba9a20350)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addac2c74ace1cba9a20350)（复刻评测）。

### 题意

候选隧道连接 n 个交通枢纽，每条隧道的施工天数已知，所有隧道可以同时施工。选择一条从 1 到 n 的线路，求最短完工时间。

输入 n、m 和 m 条 `u v 天数`，范围为 $n\le10^5,m\le2\times10^5$，保证连通。

输出线路的最短完工时间，n=1 时为 0。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703D)。

### 题解

一条线路的所有隧道同时开工，所以完工时间是边权的最大值，不是边权之和。给定天数 T，问题等价于只允许使用权值不超过 T 的边时，1 与 n 是否连通。

将边按时间升序排序，依次用并查集合并端点。第一次 1 与 n 同属一个集合时，当前边权就是答案：此时已找到全部边权不超过该值的线路；更小值对应的边此前已经全部处理，仍不连通，所以不可能更早完成。

时间 $O(m\log m+m\alpha(n))$，空间 $O(n+m)$。n=1 时起点就是终点，答案为 0。这个做法与 Kruskal 共用“排序加并查集”，但这里只需等两个指定点连通，不必把整棵生成树建完。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
int n,m;
vector<edge> e;
vector<int> fa,sz;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    e.resize(m);
    for(edge &v:e){
        scanf("%d%d%d",&v.u,&v.v,&v.w);
    }
    sort(e.begin(),e.end(),[&](const edge &a,const edge &b){
        return a.w<b.w;
    });
    fa.resize(n+1);
    sz.assign(n+1,1);
    iota(fa.begin(),fa.end(),0);
    if(n==1){
        puts("0");
        return 0;
    }
    for(edge &v:e){
        int x=find(v.u),y=find(v.v);
        if(x!=y){
            if(sz[x]<sz[y])swap(x,y);
            fa[y]=x;
            sz[x]+=sz[y];
        }
        if(find(1)==find(n)){
            printf("%d\n",v.w);
            break;
        }
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 引水入城

标签：`最小割` · `网格图` · `动态规划`

本地验证：87 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201703/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addacc574ace1cba9a203ca)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；4 个保存样例/回归用例通过；80 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addacc574ace1cba9a203ca)（复刻评测）。

### 题意

$n\times m$ 的管网中，第一行是水源，最后一行是城市。竖直向下的边有容量限制，向上的容量无限；中间各行的水平边双向具有相同的给定容量。求最大引水量。

输入 `n m A B Q X0`，$n,m\le5000$。按 $X_{i+1}=(AX_i+B)\bmod Q$ 先生成竖边容量，再生成横边容量，两部分均按题面行优先顺序生成。

输出最大引水量。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201703E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201703E)。

### 题解

**从最大流转成最小割**

因为向上边容量无限，任何有限割的源侧在每一列都必须是从第一行开始的一段前缀。否则某个源侧点上方是汇侧，会切断一条无限容量边。设第 $j$ 列前缀高度为 $h_j\in[1,n-1]$，就把一个巨大网络的割压成了每列一个整数。

第 $j$ 列贡献竖边容量 $V_j[h_j]$。相邻列高度若为 $a,b$，在两高度之间的水平边恰好跨割，额外代价是这些水平容量之和。故

$$dp_j[b]=V_j[b]+\min_a\{dp_{j-1}[a]+\text{高度a到b之间的水平容量和}\}.$$

这个最小值不必 $O(n^2)$ 枚举。固定列间边，把上一列的 `dp` 从上往下松弛一次，再从下往上松弛一次，相当于求一条非负加权链上的多源最短路。得到全部高度的最优接入费用后，加上本列对应竖边容量。

**正确性**

每个有限割唯一对应各列前缀高度，反之任何高度序列都给出有限割。DP 精确计算所有这类割的最小容量，由最大流最小割定理就是最大引水量。

**复杂度**

生成与计算均为 $O(nm)$，保存容量需要 $O(nm)$ 空间，DP 本身只用 $O(n)$。代码按输入要求生成，再按列布局保存，方便连续扫描。第一项容量是 $X_1$，不是 $X_0$；生成器乘法和答案都需要 64 位。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,h;
ll a,b,q,x;
vector<int> v,w;
vector<ll> dp;
int gen(){
    x=(a*x+b)%q;
    return x;
}
int main(){
    scanf("%d%d%lld%lld%lld%lld",&n,&m,&a,&b,&q,&x);
    h=n-1;
    v.resize(h*m);
    w.resize((h-1)*(m-1));
    for(int i=0;i<h;++i){
        for(int j=0;j<m;++j){
            v[j*h+i]=gen();
        }
    }
    for(int i=0;i<h-1;++i){
        for(int j=0;j<m-1;++j){
            w[j*(h-1)+i]=gen();
        }
    }
    dp.resize(h);
    for(int i=0;i<h;++i){
        dp[i]=v[i];
    }
    for(int j=1;j<m;++j){
        int off=(j-1)*(h-1);
        for(int i=1;i<h;++i){
            dp[i]=min(dp[i],dp[i-1]+w[off+i-1]);
        }
        for(int i=h-2;i>=0;--i){
            dp[i]=min(dp[i],dp[i+1]+w[off+i]);
        }
        for(int i=0;i<h;++i){
            dp[i]+=v[j*h+i];
        }
    }
    printf("%lld\n",*min_element(dp.begin(),dp.end()));
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201703/VALIDATION.md)
- [b-newline-followup-report.json](../tests/201703/b-newline-followup-report.json)
- [boundaries.py](../tests/201703/boundaries.py)
- [d-find-followup-report.json](../tests/201703/d-find-followup-report.json)
- [d-lambda-report.json](../tests/201703/d-lambda-report.json)
- [refactor-report.json](../tests/201703/refactor-report.json)
- [statements.json](../tests/201703/statements.json)
- [verify-d-lambda.py](../tests/201703/verify-d-lambda.py)

<!-- local-validation-attachments:end -->
