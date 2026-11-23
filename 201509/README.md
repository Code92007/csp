---
title: "CSP 201509 五题题解"
contest: "201509"
contest_month: "2015-09"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "连续段", "线性扫描", "日期计算", "模拟", "字符串扫描", "模板替换", "哈希表", "图论", "强连通分量", "Kosaraju", "AC自动机", "矩阵快速幂", "最大加代数"]
status: "published"
problems: [{"id": "A", "title": "数列分段", "tags": ["连续段", "线性扫描"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版 C++17 编译通过；62 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb44174ace1cba9a20918"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "B", "title": "日期计算", "tags": ["日期计算", "模拟"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版 C++17 编译通过；118 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb4db74ace1cba9a209b5"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "C", "title": "模板生成系统", "tags": ["字符串扫描", "模板替换", "哈希表"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版 C++17 编译通过；102 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb56174ace1cba9a20adf"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "D", "title": "高速公路", "tags": ["图论", "强连通分量", "Kosaraju"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版 C++17 编译通过；97 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb5e874ace1cba9a20bc7"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "E", "title": "最佳文章", "tags": ["AC自动机", "矩阵快速幂", "最大加代数"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版 C++17 编译通过；62 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201509E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201509E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb67074ace1cba9a20c6f"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}]
---

# CSP 201509 五题题解

[返回总目录](../README.md) · [本地验证](../tests/201509/VALIDATION.md)


<a id="problem-a"></a>

## A. 数列分段

标签：`连续段` · `线性扫描`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201509/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addb44174ace1cba9a20918)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb44174ace1cba9a20918)（复刻评测）。

### 题意

将数列划分成连续相同值的极大段，求段数。同一个数若被其他值隔开，属于不同的段。

输入数列长度 n 和各项。

输出数列的段数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509A)。

### 题解

第一个元素开启第一段；之后每个元素若不同于前一个，就开启新段。只需保存前值和计数，不必存全数组。

每段唯一对应它的第一个元素，而段首恰好满足“首元素或与前值不同”，所以计数一一对应。时间 $O(n)$，空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,pre,cnt,x;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if(!i || x!=pre)++cnt;
        pre=x;
    }
    printf("%d\n",cnt);
    return 0;
}
```

<a id="problem-b"></a>

## B. 日期计算

标签：`日期计算` · `模拟`

本地验证：118 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201509/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addb4db74ace1cba9a209b5)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb4db74ace1cba9a209b5)（复刻评测）。

### 题意

给定年份 y 及该年的第 d 天，求对应的月份与月内日期。

输入 y、d，保证日期有效；闰年二月有 29 天，其余年份为 28 天。

先输出月份，再输出月内日期。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509B)。

### 题解

按闰年规则设置二月为28或29天，从一月开始：若d大于当前月天数，则减去该月天数并进入下月，否则当前月和剩余d就是答案。

每次减法只去掉完整经过的月份，剩余d始终是从当前月一日数起的日序，因此循环结束给出正确日期。月末边界使用严格大于，不能用大于等于。时间 $O(12)$，空间 $O(1)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=13;
int y,d,m=1,len[N]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    scanf("%d%d",&y,&d);
    if(y%400==0 || (y%4==0 && y%100!=0))len[2]=29;
    while(d>len[m]){
        d-=len[m];
        ++m;
    }
    printf("%d\n%d\n",m,d);
    return 0;
}
```

<a id="problem-c"></a>

## C. 模板生成系统

标签：`字符串扫描` · `模板替换` · `哈希表`

本地验证：102 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201509/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addb56174ace1cba9a20adf)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb56174ace1cba9a20adf)（复刻评测）。

### 题意

将模板中的合法标记 `{{ VAR }}` 替换成变量值。变量名区分大小写，未定义变量替换为空串；替换值中的标记不再递归展开。

输入模板行数 m、变量数 n，随后是 m 行模板及 n 条变量定义。每条定义由变量名和双引号包围的完整值组成，值中可以包含空格和模板标记。

输出替换后的模板，保留其他字符与逐行格式。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509C)。

### 题解

先保存所有模板行，再读取变量定义，用第一个空格取名字、最外层双引号取完整值。扫描原模板时，找到下一个左标记，输出前面的普通文本；找到对应右标记，查询变量并输出值，然后把扫描位置移到原模板标记之后。

扫描指针始终只在原模板中推进，替换值直接输出，因此不会意外递归。每个原字符要么作为普通文本原样输出，要么属于恰好一个被替换标记，故输出符合规则。哈希表下期望时间 $O(L+U)$，空间为模板和变量值总长度；U 是实际输出长度。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int m,n;
string s;
vector<string> lines;
unordered_map<string,string> mp;
void read(string &str){
    str.clear();
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        str+=char(c);
    }
}
int main(){
    scanf("%d%d",&m,&n);
    read(s);
    lines.resize(m);
    for(string &str:lines){
        read(str);
    }
    while(n--){
        read(s);
        size_t p=s.find(' '),q=s.find('"',p);
        mp[s.substr(0,p)]=s.substr(q+1,s.size()-q-2);
    }
    for(string &str:lines){
        for(size_t p=0;p<str.size();){
            size_t l=str.find("{{ ",p);
            if(l==string::npos){
                printf("%s",str.substr(p).c_str());
                break;
            }
            printf("%s",str.substr(p,l-p).c_str());
            size_t r=str.find(" }}",l+3);
            auto it=mp.find(str.substr(l+3,r-l-3));
            if(it!=mp.end())printf("%s",it->second.c_str());
            p=r+3;
        }
        putchar('\n');
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 高速公路

标签：`图论` · `强连通分量` · `Kosaraju`

本地验证：97 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201509/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addb5e874ace1cba9a20bc7)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb5e874ace1cba9a20bc7)（复刻评测）。

### 题意

若两个城市可以沿单向公路互相到达，就构成一对便利城市。每个无序点对只计一次，求便利城市对数。

输入 n、m 及 m 条有向边，范围为 $n\le10^4,m\le10^5$。

输出便利城市对的总数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509D)。

### 题解

互相可达恰好是“属于同一个强连通分量”。大小为 s 的分量内部任意两点都成立，贡献 $s(s-1)/2$；不同分量之间不可能互相可达。

用 Kosaraju 求分量：先在原图做 DFS，记录每个点退出 DFS 的顺序；再反向遍历这个顺序，在所有边反向后的图中搜索，每次搜到的点恰是一整个强连通分量。原图缩点后是 DAG，退出时间顺序保证第二遍不会越过当前应处理分量的边界。

实现两遍都用显式栈。第一遍必须在所有子节点处理完以后才加入退出序列，不能把普通 BFS 的顺序拿来替代。总时间 $O(n+m)$，空间 $O(n+m)$，答案使用 64 位整数。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,size_t> P;
int n,m;
ll ans;
vector<vector<int>> g,rg;
vector<bool> vis;
vector<int> order;
int main(){
    scanf("%d%d",&n,&m);
    g.resize(n);rg.resize(n);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    vis.resize(n);
    for(int i=0;i<n;++i){
        if(vis[i])continue;
        vector<P> st{{i,0}};
        vis[i]=true;
        while(!st.empty()){
            int u=st.back().first;
            size_t &p=st.back().second;
            if(p==g[u].size()){
                order.push_back(u);
                st.pop_back();
            }
            else{
                int v=g[u][p++];
                if(!vis[v]){
                    vis[v]=true;
                    st.push_back({v,0});
                }
            }
        }
    }
    fill(vis.begin(),vis.end(),false);
    for(auto it=order.rbegin();it!=order.rend();++it){
        if(vis[*it])continue;
        vector<int> v{*it};
        vis[*it]=true;
        for(size_t i=0;i<v.size();++i){
            for(int &u:rg[v[i]]){
                if(vis[u])continue;
                vis[u]=true;
                v.push_back(u);
            }
        }
        ll sz=v.size();
        ans+=sz*(sz-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-e"></a>

## E. 最佳文章

标签：`AC自动机` · `矩阵快速幂` · `最大加代数`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/201509/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6addb67074ace1cba9a20c6f)。

原版验证：**完整实现，曙梦 OJ 已验证满分**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb67074ace1cba9a20c6f)（复刻评测）。

### 题意

选定 $n$ 个不同的小写单词。一篇长度为 $m$ 的文章，其重要度为这些单词出现次数之和，允许重叠和包含。求所有同长度文章中的最大重要度。

输入 `n m` 和各单词，单词总长度不超过 100，$m\le10^{15}$。

输出能达到的最大重要度。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201509E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201509E)。

### 题解

**AC 自动机负责“最后一个字符新产生多少匹配”**

建 Trie 并计算 fail 指针，将 fail 节点的终止计数累加到当前节点。到达状态 $v$ 时，`e[v].w` 就是以当前字符结尾的全部重要单词数。重叠不需要特殊处理，后缀匹配由 fail 链自动涵盖。

若只能写较短文章，可以逐字符 DP：`dp[state]` 为当前长度、当前自动机状态的最高分。枚举下一个字母 $c$，转移到 `e[state].ch[c]` 并加上目标状态的奖励。

**把这个转移做快速幂**

构造矩阵 $M[u][v]$：存在字母能从 $u$ 到 $v$ 时取 `e[v].w`，否则取负无穷。矩阵乘法改成

$$C[i][j]=\max_k(A[i][k]+B[k][j]).$$

这叫最大加代数；它表示两段字符串拼接后的最优得分。初始向量只有根状态为 0，其余为负无穷。按 $m$ 的二进制展开，把相应矩阵幂乘到向量上，最后取所有结束状态的最大值。

**正确性**

自动机状态包含后续匹配所需的全部后缀信息，奖励精确计算每次新出现的单词。一次矩阵合并枚举中间状态，因此遍历所有字符串拼接方式且取最优；快速幂仅改变合并顺序。

**复杂度**

状态数 $S\le101$，时间 $O(S^3\log m)$，空间 $O(S^2)$。答案可能达到 $nm$，必须用 64 位；加法前检查负无穷，避免不可达状态参加运算。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
const int N=105,M=26;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n;
ll m;
char s[N];
namespace AC{
    struct node{
        int ch[M],fail,w;
    }e[N];
    int tot;
    void insert(const char *t){
        int u=0;
        for(int i=0;t[i];++i){
            int c=t[i]-'a';
            if(!e[u].ch[c])e[u].ch[c]=++tot;
            u=e[u].ch[c];
        }
        ++e[u].w;
    }
    void build(){
        queue<int> q;
        for(int &v:e[0].ch){
            if(v)q.push(v);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            e[u].w+=e[e[u].fail].w;
            for(int c=0;c<M;++c){
                int v=e[u].ch[c];
                if(v){
                    e[v].fail=e[e[u].fail].ch[c];
                    q.push(v);
                }
                else e[u].ch[c]=e[e[u].fail].ch[c];
            }
        }
    }
}
using namespace AC;
mat mul(const mat &a,const mat &b){
    int len=a.size();
    mat c(len,vector<ll>(len,-INF));
    for(int i=0;i<len;++i){
        for(int k=0;k<len;++k){
            if(a[i][k]==-INF)continue;
            for(int j=0;j<len;++j){
                if(b[k][j]!=-INF){
                    c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
                }
            }
        }
    }
    return c;
}
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%100s",s);
        insert(s);
    }
    build();
    int len=tot+1;
    mat a(len,vector<ll>(len,-INF));
    for(int u=0;u<len;++u){
        for(int &v:e[u].ch){
            a[u][v]=e[v].w;
        }
    }
    vector<ll> dp(len,-INF);
    dp[0]=0;
    while(m){
        if(m&1){
            vector<ll> v(len,-INF);
            for(int i=0;i<len;++i){
                if(dp[i]==-INF)continue;
                for(int j=0;j<len;++j){
                    if(a[i][j]!=-INF){
                        v[j]=max(v[j],dp[i]+a[i][j]);
                    }
                }
            }
            dp.swap(v);
        }
        m>>=1;
        if(m)a=mul(a,a);
    }
    printf("%lld\n",*max_element(dp.begin(),dp.end()));
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201509/VALIDATION.md)
- [boundaries.py](../tests/201509/boundaries.py)
- [e-ac-followup-report.json](../tests/201509/e-ac-followup-report.json)
- [refactor-report.json](../tests/201509/refactor-report.json)
- [statements.json](../tests/201509/statements.json)

<!-- local-validation-attachments:end -->
