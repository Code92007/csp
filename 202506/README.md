---
title: "CSP 202506 五题题解"
contest: "202506"
contest_month: "2025-06"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "整数运算", "坐标映射", "BFS", "网格最短路", "位运算", "进制转换", "哈希表", "模拟", "字符串", "自动机", "矩阵快速幂", "计数DP", "圆方树", "虚树", "LCA", "图论"]
status: "published"
problems: [{"id": "A", "title": "正态分布", "tags": ["整数运算", "坐标映射"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b054d84e5d1fced2e44efe4", "source_sha256": "3bcb74d3952c1f6de0b6b1a903d1eb920af8d67e8ddf47f25eceb91f2abe9ea4", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:03:34.664132+00:00"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b2a67df0b81749b8ec"}}, {"id": "B", "title": "机器人复健指南", "tags": ["BFS", "网格最短路"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05531de5d1fced2e44f9a7", "source_sha256": "0e69c7258195d5c5019875ce1c29b4aa3aadac5102e613d10a044b195898b673", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:05:21.671918+00:00"}, "original_validation": "C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b3a67df0b81749b902"}}, {"id": "C", "title": "消息解码", "tags": ["位运算", "进制转换", "哈希表", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506C/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055380e5d1fced2e44faa1", "source_sha256": "500837767022031d280ebcf635869a3f11505db5391f41bf85e93d5b97459521", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:06:33.335472+00:00"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b5a67df0b81749b914"}}, {"id": "D", "title": "月票发行", "tags": ["字符串", "自动机", "矩阵快速幂", "计数DP"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0553dce5d1fced2e44fb4f", "source_sha256": "4785fd2db7b5d58c48f3de914cf866399d1500a9577e20606ba5da3210841620", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:08:07.322119+00:00"}, "original_validation": "C++17 编译通过；3 个保存样例/回归用例通过；71 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b6a67df0b81749b92b"}}, {"id": "E", "title": "博物馆", "tags": ["圆方树", "虚树", "LCA", "图论"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202506E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202506E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b055437e5d1fced2e44fc3e", "source_sha256": "51d8ecd0ceb1a648be49fadf554848ef88a68921309bef255504294fcc3f660e", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T09:10:04.253924+00:00"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。", "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce7b8a67df0b81749b940"}}]
---

# CSP 202506 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202506/VALIDATION.md)


<a id="problem-a"></a>

## A. 正态分布

标签：`整数运算` · `坐标映射`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202506/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7b2a67df0b81749b8ec)。

原版验证：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b054d84e5d1fced2e44efe4)。

<!-- refactor-online:A:end -->

### 题意

把正态分布查询标准化为 z=(n−μ)/σ，并求它在标准表中的行列号。行按 0.0、0.1… 排列，列按百分位 0…9 排列，均从 1 开始编号。

输入查询数 k，随后每组输入 μ、σ、n；σ 是 100 的因子，标准化结果可用两位小数精确表示。

每组输出对应的行号与列号。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506A)。

### 题解

计算整数v=100*(n-μ)/σ，题设保证整除。v/10表示z的整数部分与十分位，v%10是百分位，答案为(v/10+1,v%10+1)。

相当于把两位小数拆成表格的行、列下标，全程整数可避免3.45在浮点中略小于3.45导致截断。每个查询 $O(1)$ 时间、$O(1)$ 空间。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int k,mu,sig,n;
int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d%d%d",&mu,&sig,&n);
        int v=100*(n-mu)/sig;
        printf("%d %d\n",v/10+1,v%10+1);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 机器人复健指南

标签：`BFS` · `网格最短路`

本地验证：100 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202506/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7b3a67df0b81749b902)。

原版验证：**已实现**。C++17 编译通过；2 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05531de5d1fced2e44f9a7)。

<!-- refactor-online:B:end -->

### 题意

机器人在 n×n 场地内按马步移动，即 (±1,±2) 或 (±2,±1)。求它从指定格子出发，不超过 k 步可以到达的不同格子数，包括起点。

输入依次为 n、k、起点横纵坐标 x、y，其中 n、k≤100，坐标从 1 开始编号。

输出可以到达的格子数。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506B)。

### 题解

把格子视为图顶点，八种合法马步为等权边，从起点 BFS。首次入队时记录最短距离并标记，距离达到 k 的点计入答案但不再扩展。

BFS 按距离递增处理结点，因此第一次访问得到最少步数；一个格子能在 k 步内到达，当且仅当其最短距离≤k。注意“八方向”指题图中的马步，并非相邻八格。每格至多入队一次，时间和空间均为 $O(n^2)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=105,M=8;
int n,k,x,y,ans,d[N][N];
int dx[M]={1,1,-1,-1,2,2,-2,-2};
int dy[M]={2,-2,2,-2,1,-1,1,-1};
queue<P>q;
bool ok(int a,int b){
    return 0<=a && a<n && 0<=b && b<n && d[a][b]==-1;
}
int main(){
    scanf("%d%d%d%d",&n,&k,&x,&y);
    x--,y--;
    memset(d,-1,sizeof d);
    d[x][y]=0;
    q.push(P(x,y));
    while(!q.empty()){
        auto [u,v]=q.front();
        q.pop();
        ++ans;
        if(d[u][v]==k)continue;
        for(int i=0;i<M;++i){
            int a=u+dx[i],b=v+dy[i];
            if(!ok(a,b))continue;
            d[a][b]=d[u][v]+1;
            q.push(P(a,b));
        }
    }
    printf("%d\n",ans);
    return 0;
}
```

<a id="problem-c"></a>

## C. 消息解码

标签：`位运算` · `进制转换` · `哈希表` · `模拟`

本地验证：102 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202506/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7b5a67df0b81749b914)。

原版验证：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055380e5d1fced2e44faa1)。

<!-- refactor-online:C:end -->

### 题意

按历史记录解码 72 位消息中的接收方、发送方及位置。代号只能由此前消息直接给出的代号推断；散列冲突取最近消息，同条消息优先发送方。

输入消息数 n，随后输入 n 条 72 位二进制消息，n≤10^5。消息分两类：

- 简单消息：1 位类型、28 位接收方、28 位发送方、15 位位置。代号字段小于 $2^{25}$ 时是 25 位散列；否则减去 $2^{25}$ 得到典型代号的混合进制短编码。
- 复杂消息：1 位类型、58 位完整代号、12 位另一方散列及 1 位方向。

依次输出每条消息的接收方、发送方和位置。散列推断的代号前加 #，找不到输出 ###；位置为 0 时省略位置。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506C)。

### 题解

把二进制字段按规定位置读成无符号整数。完整代号用 38 进制反解 11 个字符，再去掉末尾空格。典型代号依次使用基数 37、36、10、26、26、26，反解时从最后一位开始取余，首位空格则去掉。

维护 12 位和 25 位散列到最近直接代号的映射。每条消息必须先把两方都解码、输出，然后才更新映射；更新时先接收方后发送方，使同条消息冲突时发送方覆盖。通过散列猜出的代号不回写，防止错误地刷新历史优先级。

散列可用无符号 64 位乘法：`数字表示 * 47055833459` 的溢出按模 $2^{64}$ 定义，再右移 64-b 位，恰好得到题目要求的 b 位散列。因为更高的乘积位在最终对 $2^b$ 取模时本来就会被消去，这并非依赖未定义的有符号溢出。

进制反解与编码互逆，延后更新映射保证只查看历史消息，覆盖次序保证冲突规则。每条消息固定 72 位且代号至多 11 字符，期望总时间 $O(n)$，空间 $O(n+2^{12})$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1<<12,M=75;
int n;
char str[M];
string pre[N];
unordered_map<ull,string>mp;
int num(char c){
    if(c==' ')return 0;
    if(c>='0' && c<='9')return c-'0'+1;
    if(c=='_')return 37;
    return c-'A'+11;
}
char chr(int x){
    if(!x)return ' ';
    if(x<=10)return '0'+x-1;
    if(x==37)return '_';
    return 'A'+x-11;
}
ull code(string s){
    s.resize(11,' ');
    ull v=0;
    for(char &c:s){
        v=v*38+num(c);
    }
    return v;
}
string full(ull x){
    string s(11,' ');
    for(int i=10;i>=0;--i){
        s[i]=chr(x%38);
        x/=38;
    }
    while(!s.empty() && s.back()==' '){
        s.pop_back();
    }
    return s;
}
string typical(ull x){
    string s(6,' ');
    for(int i=5;i>=3;--i){
        s[i]='A'+x%26;
        x/=26;
    }
    s[2]='0'+x%10;
    x/=10;
    int v=x%36;
    x/=36;
    s[1]=v<10?'0'+v:'A'+v-10;
    s[0]=chr(x);
    if(s[0]==' ')s.erase(s.begin());
    return s;
}
void add(const string &s){
    ull h=code(s)*47055833459ull;
    mp[h>>39]=s;
    pre[h>>52]=s;
}
ull f(int l,int len){
    ull x=0;
    for(int i=0;i<len;++i){
        x=x*2+str[l+i]-'0';
    }
    return x;
}
string dec(ull x,bool &ok){
    ok=x>=(1ull<<25);
    if(ok)return typical(x-(1ull<<25));
    auto it=mp.find(x);
    return it==mp.end()?"###":"#"+it->second;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",str);
        string u,v;
        bool du=0,dv=0;
        int pos=0;
        if(str[0]=='0'){
            u=dec(f(1,28),du);
            v=dec(f(29,28),dv);
            pos=f(57,15);
        }
        else{
            string s=full(f(1,58));
            string &old=pre[f(59,12)];
            string t=old.empty()?"###":"#"+old;
            if(str[71]=='0'){
                u=t,v=s,dv=1;
            }
            else{
                u=s,v=t,du=1;
            }
        }
        printf("%s %s",u.c_str(),v.c_str());
        if(pos)printf(" %d",pos);
        puts("");
        if(du)add(u);
        if(dv)add(v);
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 月票发行

标签：`字符串` · `自动机` · `矩阵快速幂` · `计数DP`

本地验证：78 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202506/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7b6a67df0b81749b92b)。

原版验证：**已实现**。C++17 编译通过；3 个保存样例/回归用例通过；71 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0553dce5d1fced2e44fb4f)。

<!-- refactor-online:D:end -->

### 题意

长度为 n 的月票编号中，一些位置固定为 #，其余位置可填小写字母。统计先出现 ccf、后出现 cspark 的编号数量，两段不能重叠，也不能跨越 #。

输入 n、固定位置数 m，以及严格递增的 m 个位置。范围为 n≤10^9、m≤10^6。两段之间允许有其他字符或 #。

输出编号数量对 998244353 取模的结果。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506D)。

### 题解

**用状态表示已经完成了哪一步**

找到第一个 `ccf` 之前，只记录当前后缀匹配了它的多少个字符，得到状态 0、1、2。找到后改为匹配 `cspark`，得到状态 3 到 8；两者都按顺序找到则进入永久接受状态 9。

对每个状态和字母，取“拼上字母后的字符串”和目标模式的最长前缀匹配后缀，得到下一状态。两个模式无法相互重叠，所以识别到第一个模式时，可以从第二个模式的空前缀开始。

为什么只需记第一次 `ccf`？如果后面任意一个 `ccf` 能与某个 `cspark` 配对，那么最早的 `ccf` 也能与它配对。因此这个状态机恰好识别题目要求，既不遗漏也不重复。

**逐字 DP 改为整段转移**

井号把模式匹配的后缀清空，但保留“没找到第一个／找到第一个／已经成功”这三个阶段。对于长为 $L$ 的自由段，设 $A$ 为从阶段 0 到阶段 0 的数量，$B$ 为从阶段 0 到阶段 1 的数量，$C$ 为从阶段 1 留在阶段 1 的数量，$T=26^L$。这些数量都由十状态转移矩阵的 $L$ 次幂得到。

三个全局计数 $(u,w,z)$ 依次表示上述阶段，经过该段后变成

$$u'=uA,\quad w'=uB+wC,\quad z'=zT+w(T-C)+u(T-A-B).$$

空段也适用：$A=C=T=1,B=0$。最终输出 $z$。

**兼顾很多短段和少量长段**

预计算长度不超过 $H=10^5$ 的段转移，长段用矩阵快速幂，重复长度缓存。所有段长总和不超过 $n$，所以长段数量至多 $n/(H+1)$，不会给一百万个井号逐个做快速幂。设状态数 $S=10$，时间上界为 $O(HS^2+S^3\log n+m+\frac nH S^2\log n)$，空间 $O(m+H+S^2\log n+n/H)$。矩阵内积使用无符号 64 位累加，十项乘积之和仍在其范围内。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=10;
typedef array<int,N> A;
typedef array<A,N> Mat;
const int M=4,K=30,H=1e5;
const int mod=998244353;
int n,m;
ll u=1,w,z;
Mat tr,pw[K];
A a,b;
vector<int>g;
vector<array<int,M>>dp;
unordered_map<int,array<int,M>>mp;
A mul(const A &x,const Mat &y){
    A res;
    for(int j=0;j<N;++j){
        ull sum=0;
        for(int k=0;k<N;++k){
            sum+=(ull)x[k]*y[k][j];
        }
        res[j]=sum%mod;
    }
    return res;
}
int step(int s,char c){
    if(s==9)return 9;
    string p=s<3?"ccf":"cspark";
    int off=s<3?0:3;
    string t=p.substr(0,s-off)+c;
    for(int len=(int)p.size();len>=0;--len){
        if(t.size()>=(size_t)len &&
           t.compare(t.size()-len,len,p,0,len)==0){
            return off+len;
        }
    }
    return off;
}
array<int,M> f(const A &x,const A &y){
    array<int,M>res;
    res.fill(0);
    for(int s=0;s<N;++s){
        if(s<3)res[0]=(res[0]+x[s])%mod;
        if(s>=3 && s<9)res[1]=(res[1]+x[s])%mod;
        if(s<9)res[2]=(res[2]+y[s])%mod;
        res[3]=(res[3]+x[s])%mod;
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    int pre=0;
    for(int i=0;i<m;++i){
        int x;
        scanf("%d",&x);
        g.push_back(x-pre-1);
        pre=x;
    }
    g.push_back(n-pre);
    for(int s=0;s<N;++s){
        for(char c='a';c<='z';++c){
            ++tr[s][step(s,c)];
        }
    }
    pw[0]=tr;
    for(int i=1;i<K;++i){
        for(int j=0;j<N;++j){
            pw[i][j]=mul(pw[i-1][j],pw[i-1]);
        }
    }
    dp.resize(min(n,H)+1);
    a[0]=b[3]=1;
    for(int i=0;i<(int)dp.size();++i){
        dp[i]=f(a,b);
        a=mul(a,tr);b=mul(b,tr);
    }
    for(int &len:g){
        array<int,M>v;
        if(len<(int)dp.size())v=dp[len];
        else if(mp.count(len))v=mp[len];
        else{
            a.fill(0);b.fill(0);
            a[0]=b[3]=1;
            for(int i=0;i<K;++i){
                if(len>>i&1){
                    a=mul(a,pw[i]);b=mul(b,pw[i]);
                }
            }
            v=mp[len]=f(a,b);
        }
        auto [x,y,c,t]=v;
        ll cur=(t-x-y+2ll*mod)%mod;
        z=(z*t+w*(t-c+mod)+u*cur)%mod;
        w=(w*c+u*y)%mod;
        u=u*x%mod;
    }
    printf("%lld\n",z);
    return 0;
}
```

<a id="problem-e"></a>

## E. 博物馆

标签：`圆方树` · `虚树` · `LCA` · `图论`

本地验证：97 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202506/VALIDATION.md)。。

原版评测：[记录](https://oj.shumeng.tech/record/6adce7b8a67df0b81749b940)。

原版验证：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b055437e5d1fced2e44fc3e)。

<!-- refactor-online:E:end -->

### 题意

博物馆道路构成连通无向图。每位导游有一组标记展厅，删除任意一个展厅后，他选择剩余连通块中标记数最多的一个住宿。对每位导游，求删除各展厅时最多可保留标记数的总和。

输入 n、m、q，随后是 m 条无向边及 q 位导游各自的标记展厅集合。范围为 n、q≤10^5、m≤2×10^5，所有集合的大小之和不超过 3×10^5；同一集合中的展厅互不相同。

对每位导游输出删除各展厅时最大标记数的总和。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202506E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202506E)。

### 题解

**图先变树**

Tarjan 求点双连通分量；每个原顶点建圆点，每个点双分量建方点，成员与分量之间连边。得到圆方树。删原图顶点后的连通块，对应圆方树删去该圆点后的各分支。于是只需计算每个圆点周围各分支包含多少标记。

**设一个便于修正的基准**

一份攻略有 $C$ 个标记。假设删任意点都不分裂标记，那么普通点贡献 $C$，标记点贡献 $C-1$，合计 $(n-1)C$。只有标记点之间的树路径上的圆点可能需要修正。

将标记点按 DFS 序排序，加入相邻标记的 LCA，再加入根，构建虚树。逆序求每个虚树点的标记子树大小 $sub[u]$。对于虚树上的圆点 $u$，父亲方向有 $C-sub[u]$ 个标记，各虚树孩子方向各有 $sub[v]$ 个；这些分支属于不同的原树孩子方向，因为所有必要 LCA 已加入。最大值就是实际贡献，减去原基准完成修正。

**压缩边中间也要算**

虚树边 $p\to u$ 的中间点均未被标记，也没有额外含标记分支。删去任何一个这样的圆点，标记分成 $sub[u]$ 和 $C-sub[u]$ 两部分，因此每个中间圆点都要从基准减去 $\min(sub[u],C-sub[u])$。预处理根路径上的圆点数量，即可常数时间求中间圆点个数；方点不参与最终答案。

**正确性**

虚树点、中间链上的圆点、虚树外的圆点三类互不重叠且覆盖全部原点，分别使用精确分支计数、二分支公式、基准值，故总和正确。实现用显式栈做原图和树的 DFS，避免长链递归爆栈。

**复杂度**

预处理 $O(n+m+n\log n)$；一份 $C$ 点攻略 $O(C\log C+C\log n)$。空间 $O(n\log n+m+C)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+10,M=20;
int n,m,q,tot,tim;
int dfn[N],low[N],fa[N],pe[N],pos[N],in[N],out[N],pre[N];
int up[M][N],mark[N],sub[N],mx[N],vp[N];
vector<P>g[N];
vector<int>tr[N],vs,dfs;
void build(){
    tot=n;
    pe[1]=-1;
    dfn[1]=low[1]=++tim;
    dfs.push_back(1);
    vs.push_back(1);
    while(!dfs.empty()){
        int u=dfs.back();
        if(pos[u]<(int)g[u].size()){
            auto [v,id]=g[u][pos[u]++];
            if(id==pe[u])continue;
            if(!dfn[v]){
                fa[v]=u;
                pe[v]=id;
                dfn[v]=low[v]=++tim;
                vs.push_back(v);
                dfs.push_back(v);
            }
            else low[u]=min(low[u],dfn[v]);
        }
        else{
            dfs.pop_back();
            int p=fa[u];
            if(!p)continue;
            low[p]=min(low[p],low[u]);
            if(low[u]>=dfn[p]){
                ++tot;
                tr[tot].push_back(p);
                tr[p].push_back(tot);
                int v=0;
                while(v!=u){
                    v=vs.back();
                    vs.pop_back();
                    tr[tot].push_back(v);
                    tr[v].push_back(tot);
                }
            }
        }
    }
    vector<P>st;
    st.push_back(P(1,0));
    tim=0;
    while(!st.empty()){
        auto [u,flag]=st.back();
        st.pop_back();
        if(flag){
            out[u]=tim;
            continue;
        }
        in[u]=++tim;
        pre[u]=pre[up[0][u]]+(u<=n);
        for(int j=1;j<M;++j){
            up[j][u]=up[j-1][up[j-1][u]];
        }
        st.push_back(P(u,1));
        for(int &v:tr[u]){
            if(v==up[0][u])continue;
            up[0][v]=u;
            st.push_back(P(v,0));
        }
    }
}
bool anc(int u,int v){
    return in[u]<=in[v] && out[v]<=out[u];
}
int lca(int u,int v){
    if(anc(u,v))return u;
    if(anc(v,u))return v;
    for(int j=M-1;j>=0;--j){
        if(up[j][u] && !anc(up[j][u],v))u=up[j][u];
    }
    return up[0][u];
}
bool cmp(int x,int y){
    return in[x]<in[y];
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(P(v,i));
        g[v].push_back(P(u,i));
    }
    build();
    for(int id=1;id<=q;++id){
        int c;
        scanf("%d",&c);
        vector<int>v(c);
        for(int &x:v){
            scanf("%d",&x);
            mark[x]=id;
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=1;i<c;++i){
            v.push_back(lca(v[i-1],v[i]));
        }
        v.push_back(1);
        sort(v.begin(),v.end(),cmp);
        v.erase(unique(v.begin(),v.end()),v.end());
        vector<int>st;
        for(int &u:v){
            sub[u]=(mark[u]==id);
            mx[u]=0;
            while(!st.empty() && !anc(st.back(),u)){
                st.pop_back();
            }
            vp[u]=st.empty()?0:st.back();
            st.push_back(u);
        }
        ll ans=1ll*(n-1)*c;
        for(int i=(int)v.size()-1;i>=0;--i){
            int u=v[i],p=vp[u];
            int best=max(mx[u],c-sub[u]);
            if(u<=n)ans+=best-(c-(mark[u]==id));
            if(p){
                int cnt=pre[u]-pre[p]-(u<=n);
                ans-=1ll*cnt*min(sub[u],c-sub[u]);
                sub[p]+=sub[u];
                mx[p]=max(mx[p],sub[u]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202506/VALIDATION.md)
- [b-style-followup-report.json](../tests/202506/b-style-followup-report.json)
- [boundaries.py](../tests/202506/boundaries.py)
- [c-style-followup-report.json](../tests/202506/c-style-followup-report.json)
- [d-mod-followup-report.json](../tests/202506/d-mod-followup-report.json)
- [d-style-followup-report.json](../tests/202506/d-style-followup-report.json)
- [online-update-report.json](../tests/202506/online-update-report.json)
- [online-verdicts.json](../tests/202506/online-verdicts.json)
- [refactor-report.json](../tests/202506/refactor-report.json)
- [statements.json](../tests/202506/statements.json)

<!-- local-validation-attachments:end -->
