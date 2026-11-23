---
title: "CSP 202409 五题题解"
contest: "202409"
contest_month: "2024-09"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "字符分类", "频率统计", "倍增", "函数复合", "字符串", "字符串解析", "KMP", "模拟", "最短路", "Dijkstra", "几何判定", "Treap", "启发式分裂", "哈希表"]
status: "published"
problems: [{"id": "A", "title": "密码", "tags": ["字符分类", "频率统计"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版 C++17 编译通过；62 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409A/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce814a67df0b81749badf"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "B", "title": "字符串变换", "tags": ["倍增", "函数复合", "字符串"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版 C++17 编译通过；102 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409B/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce816a67df0b81749baf4"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "C", "title": "补丁应用", "tags": ["字符串解析", "KMP", "模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版 C++17 编译通过；125 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409C/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce817a67df0b81749bb06"}, "original_validation": "C++17 编译通过；4 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "D", "title": "通讯延迟", "tags": ["最短路", "Dijkstra", "几何判定"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版 C++17 编译通过；123 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409D/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce819a67df0b81749bb1b"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}, {"id": "E", "title": "木板切割", "tags": ["Treap", "启发式分裂", "哈希表"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版 C++17 编译通过；62 个不同输入在优化版与 UBSan 版均通过；原版在线记录保留，重构版未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202409E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202409E/"}], "oj": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce81aa67df0b81749bb21"}, "original_validation": "C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。"}]
---

# CSP 202409 五题题解

[返回总目录](../README.md) · [本地验证](../tests/202409/VALIDATION.md)


<a id="problem-a"></a>

## A. 密码

标签：`字符分类` · `频率统计`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202409/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6adce814a67df0b81749badf)。

原版验证：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

按字符类别和重复次数评定密码等级：缺少字母、数字、特殊字符任一类时为低级 0；三类齐全但某字符出现超过两次时为中级 1；否则为高级 2。

输入密码数 n，随后是 n 个密码。密码长度至少为 6，只包含大小写字母、数字、*、#；大小写字母在重复计数时分别处理。

每个密码输出一行安全等级。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409A/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409A)。

### 题解

一次扫描设置三类是否出现的标志，同时按字符本身计数并记录是否有频次>2。先检查三类齐全，再检查重复条件，按规则输出。

分类条件和频次条件分别完整统计，按安全等级定义组合即可。大小写属于同一“字母类”，但A与a是两个不同字符，频次不能合并。时间 $O(|s|)$，使用固定128格计数数组，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=128;
int n,cnt[M];
char s[N];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        memset(cnt,0,sizeof cnt);
        bool a=false,b=false,c=false,rep=false;
        for(int i=0;s[i];++i){
            unsigned char x=s[i];
            if(isalpha(x))a=true;
            else if(isdigit(x))b=true;
            else c=true;
            if(++cnt[x]>2)rep=true;
        }
        int ans;
        if(!(a && b && c))ans=0;
        else if(rep)ans=1;
        else ans=2;
        printf("%d\n",ans);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 字符串变换

标签：`倍增` · `函数复合` · `字符串`

本地验证：102 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202409/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6adce816a67df0b81749baf4)。

原版验证：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；100 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定字符替换映射，未定义的字符保持不变。每次查询初始字符串替换 k 次后的结果，各查询相互独立。

输入初始字符串、替换规则数及各规则，再输入查询数及各次的 k。字符集共 63 种，k≤$10^9$，查询至多 1000 次；字符串和规则用 # 包围，空格也是普通字符。

每次输出变换后的字符串，仍用 # 包围。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409B/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409B)。

### 题解

预处理 `f[b][c]` 表示字符 c 替换 $2^b$ 次的结果，递推 `f[b][c]=f[b-1][f[b-1][c]]`。对每个字符按 k 的二进制位依次应用对应跳跃，最后重新加上外侧井号。

递推是两个相同长度变换的复合，二进制分解又把 k 拆成这些次数之和，因此结果等于连续 k 次替换。每次查询都从原始串出发，不接着上一查询继续变换。整行读取，保留映射和字符串中的空格。时间 $O(128\log K+m|s|\log K)$，空间 $O(128\log K+|s|)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=31,M=128;
int n,q,k,f[N][M];
string s,t;
void read(string &str){
    str.clear();
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        str+=char(c);
    }
}
int main(){
    read(s);
    s=s.substr(1,s.size()-2);
    for(int i=0;i<M;++i){
        f[0][i]=i;
    }
    scanf("%d",&n);
    read(t);
    while(n--){
        read(t);
        f[0][int(t[1])]=t[2];
    }
    for(int i=1;i<N;++i){
        for(int j=0;j<M;++j){
            f[i][j]=f[i-1][f[i-1][j]];
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&k);
        putchar('#');
        for(char &ch:s){
            int c=ch;
            for(int i=0;i<N;++i){
                if(k>>i&1)c=f[i][c];
            }
            putchar(c);
        }
        puts("#");
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 补丁应用

标签：`字符串解析` · `KMP` · `模拟`

本地验证：125 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202409/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6adce817a67df0b81749bb06)。

原版验证：**已实现**。C++17 编译通过；4 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

给定原文件和补丁，按声明的行号及允许偏移依次替换片段。匹配位置优先选择偏移绝对值最小者，再选择偏移较小者；每块找到的偏移累加给后续块。

输入原文件行数 n 和各行内容，随后读入补丁至文件结束。n≤2000，补丁块数不超过 25。补丁规则如下：

- 块头严格形如 `@@ -NN,MM +nn,mm @@`，四个数都是无前导零的正整数；忽略 nn，原声明区间不得重叠。
- 块内空格／减号行组成原片段，空格／加号行组成新片段，行数分别须与 MM、mm 相符；匹配偏移的绝对值必须小于 MM。
- 补丁中 # 开头的行忽略，首块前的杂项忽略；原文件中的 # 则是正常内容。

成功时输出应用全部补丁后的文件，任一步失败则只输出 `Patch is damaged.`。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409C/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409C)。

### 题解

先读取原文件，再单独解析补丁。原文件里的 # 是正常内容，不能被当成补丁注释删除。收集并校验所有块后才生成结果，避免前面成功的输出在后面发现损坏后无法撤回。

**始终在原文件行号坐标中匹配**

用 `used` 保存尚未消耗的原文起点，`off` 保存累计行号偏移。当前参考起点为 `NN-1+off`；搜索 `used` 之后与原片段相同的连续行，比较允许范围内候选的 `(偏移绝对值,偏移)`。

找到后将尚未修改的原文和新片段追加到答案，推进 `used`，并仅把本次偏移加入 `off`。新旧片段行数之差不混入原文件坐标。

把每一行完整字符串映射为整数编号，原片段与原文件变为整数序列。KMP 在线性时间找出所有匹配起点，比较候选时无需反复比较长行。字典映射按完整字符串比较，不会因哈希碰撞把不同文本当成同一行。

`used` 保证块应用区域不重叠，最小候选排序严格对应题意；按原文顺序拼接未修改片段和替换片段，得到正确结果。设块数 B≤25、原文件行数 n≤2000，行编号之后匹配时间 $O(Bn+\text{补丁行数})$，另计读取、哈希和输出的字符总量。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct block{
    ll st,m,k;
    vector<int> a,b;
};
int n,used;
ll off;
bool ok=true;
string s;
vector<string> text;
vector<int> a,ans;
vector<block> v;
unordered_map<string,int> mp;
bool read(string &str){
    str.clear();
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        str+=char(c);
    }
    return c!=EOF || !str.empty();
}
int id(const string &str){
    auto it=mp.find(str);
    if(it!=mp.end())return it->second;
    int x=text.size();
    text.push_back(str);
    mp[str]=x;
    return x;
}
ll num(const string &str){
    ll x=0;
    for(const char &c:str){
        x=x*10+c-'0';
        if(x>1e12)return 1e12;
    }
    return x;
}
int main(){
    scanf("%d",&n);
    read(s);
    a.resize(n);
    for(int &x:a){
        read(s);
        x=id(s);
    }
    regex re("^@@ -([1-9][0-9]*),([1-9][0-9]*) \\+([1-9][0-9]*),([1-9][0-9]*) @@$");
    while(read(s)){
        if(!s.empty() && s[0]=='#')continue;
        if(!s.empty() && s[0]=='@'){
            smatch match;
            if(!regex_match(s,match,re)){
                ok=false;
                break;
            }
            block cur;
            cur.st=num(match[1]);
            cur.m=num(match[2]);
            cur.k=num(match[4]);
            if(!v.empty() && cur.st<v.back().st+v.back().m){
                ok=false;
                break;
            }
            v.push_back(std::move(cur));
        }
        else if(!v.empty()){
            if(s.empty() || (s[0]!=' ' && s[0]!='+' && s[0]!='-')){
                ok=false;
                break;
            }
            int x=id(s.substr(1));
            if(s[0]!='+')v.back().a.push_back(x);
            if(s[0]!='-')v.back().b.push_back(x);
        }
    }
    if(v.empty())ok=false;
    for(block &cur:v){
        if(cur.m!=(ll)cur.a.size() || cur.k!=(ll)cur.b.size())ok=false;
    }
    if(ok){
        for(block &cur:v){
            int len=cur.a.size();
            vector<int> f(len);
            for(int i=1,j=0;i<len;++i){
                while(j && cur.a[i]!=cur.a[j]){
                    j=f[j-1];
                }
                if(cur.a[i]==cur.a[j])++j;
                f[i]=j;
            }
            ll st=cur.st-1+off,delta=INF;
            int pos=-1;
            for(int i=used,j=0;i<n;++i){
                while(j && a[i]!=cur.a[j]){
                    j=f[j-1];
                }
                if(a[i]==cur.a[j])++j;
                if(j==len){
                    int x=i-len+1;
                    ll d=x-st;
                    bool best=pos==-1 || abs(d)<abs(delta);
                    best=best || (abs(d)==abs(delta) && d<delta);
                    if(abs(d)<len && best){
                        pos=x;
                        delta=d;
                    }
                    j=f[j-1];
                }
            }
            if(pos==-1){
                ok=false;
                break;
            }
            ans.insert(ans.end(),a.begin()+used,a.begin()+pos);
            ans.insert(ans.end(),cur.b.begin(),cur.b.end());
            used=pos+len;
            off+=delta;
        }
    }
    if(!ok){
        puts("Patch is damaged.");
        return 0;
    }
    ans.insert(ans.end(),a.begin()+used,a.end());
    for(int &x:ans){
        puts(text[x].c_str());
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 通讯延迟

标签：`最短路` · `Dijkstra` · `几何判定`

本地验证：123 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202409/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6adce819a67df0b81749bb1b)。

原版验证：**已实现**。C++17 编译通过；1 个保存样例/回归用例通过；120 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

平面上有 $n$ 个节点和 $m$ 个基站。基站 $(x,y,r,t)$ 覆盖满足 $|X-x|\le r,|Y-y|\le r$ 的节点，包括边界；覆盖内任意两点可用延迟 $t$ 通讯。求节点 1 到节点 $n$ 的最短延迟。

输入 n、m，随后输入节点坐标和各基站的 x、y、r、t。范围为 $n,m\le5000$，坐标与半径不超过 $10^9$，延迟为正。

输出最短延迟；无法到达时输出大小写准确的 `Nan`。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409D/)。

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409D)。

### 题解

一个覆盖 $s$ 个点的基站表示一个完全图，直接添加所有点对会浪费 $O(s^2)$ 条边。可以保留基站覆盖集合，在需要时一次展开。

**Dijkstra 确定一个点 $u$ 的最短距离后，检查尚未用过的基站**

如果基站覆盖 $u$，就用 $d_u+t$ 松弛它覆盖的所有点，并永久标记该基站已处理。为什么只展开一次？$u$ 是该基站覆盖的点中第一个被确定的点；其余覆盖点的最终距离不会更小，因此以后从它们进入同一基站，代价至少也是 $d_u+t$。第一次展开已提供该基站能够带来的所有最优松弛。

这里直接扫描所有点选取最小未确定距离，使用朴素 Dijkstra。节点和基站都只有 5000，避免大规模堆更新很合适。一个点确定时扫描 $m$ 个基站，一个基站至多扫描 $n$ 个点一次；总时间 $O(n^2+nm)$，只用 $O(n+m)$ 空间，不保存覆盖边。

边权为正，Dijkstra 每次选出的距离正确；结合基站展开的安全性，目标点被确定时即可结束。几何减法和距离用 64 位整数。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct station{
    ll x,y,r,c;
    bool vis;
}e[N];
int n,m;
ll x[N],y[N],d[N];
bool vis[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%lld%lld%lld%lld",&e[i].x,&e[i].y,&e[i].r,&e[i].c);
    }
    memset(d,(int)INF,sizeof d);
    d[0]=0;
    for(int i=0;i<n;++i){
        int u=-1;
        for(int j=0;j<n;++j){
            if(!vis[j] && (u==-1 || d[j]<d[u]))u=j;
        }
        if(u==-1 || d[u]==INF)break;
        vis[u]=true;
        if(u==n-1)break;
        for(int j=0;j<m;++j){
            station &s=e[j];
            bool in=abs(x[u]-s.x)<=s.r && abs(y[u]-s.y)<=s.r;
            if(s.vis || !in)continue;
            s.vis=true;
            ll val=d[u]+s.c;
            for(int v=0;v<n;++v){
                bool near=abs(x[v]-s.x)<=s.r && abs(y[v]-s.y)<=s.r;
                if(!vis[v] && val<d[v] && near)d[v]=val;
            }
        }
    }
    if(d[n-1]==INF)puts("Nan");
    else printf("%lld\n",d[n-1]);
    return 0;
}
```

<a id="problem-e"></a>

## E. 木板切割

标签：`Treap` · `启发式分裂` · `哈希表`

本地验证：62 个不同输入在优化版与 UBSan 版均通过。[验证记录](../tests/202409/VALIDATION.md)。重构版未重新提交在线评测。

原版评测：[记录](https://oj.shumeng.tech/record/6adce81aa67df0b81749bb21)。

原版验证：**完整实现，未获正式评测确认**。C++17 编译通过；1 个保存样例/回归用例通过；60 组独立随机对拍通过；曙梦 OJ 100 分 Accepted（复刻评测）。

### 题意

初始木板由原始编号 $1\ldots n$ 的段组成，每段带有颜色。每次从指定木板中切出编号位于区间内的段，保持原顺序形成新木板，剩余段重新连接。

输入 `n m k`、$n$ 个颜色及 $k$ 次操作，三者均不超过 $10^5$。第 $i$ 次操作 `x l r` 从木板 $x$ 切出原始编号在 $[l,r]$ 的全部段，形成编号 $i+1$ 的木板；段的原始编号始终不变。

每次输出新木板的不同颜色数和连续颜色段数，空木板两者均为 0。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202409E/)

原站练习：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202409E)。

### 题解

**维护原始编号，不维护当前排名**

每块木板用按原编号为键的 Treap 表示。两次 split 将原树分成编号小于 $l$、处于 $[l,r]$、大于 $r$ 三部分；中间成为新板，首尾 merge 回原板。

**连续颜色段可以局部合并**

每个节点保存子树大小、第一种颜色、最后一种颜色、颜色段数。左右子序列拼接时，若交界两色相同，段数减一。Treap 每次修改后调用节点的 `pushup`，答案从新根直接读取。

**不同颜色数不能简单相加**

每块板再维护一张颜色频次表。分裂后只遍历较小板上的段，建立小板的新表，同时从原有大表中减去这些频次，计数归零就删除。若切出的板较大，应把原频次表交换给新板，而不是坚持把表留在旧编号下。

**摊还证明**

每当一个段被遍历，它进入的板大小不超过原板的一半。一个段最多被遍历 $O(\log n)$ 次。哈希表条目用频次保存，重复颜色不会导致漏减。Treap 的随机优先级只影响树高，不影响切割结果。

**复杂度**

期望时间 $O((n+k)\log n)$；有效颜色记录总数不超过段数。哈希桶可能保留已减少元素的容量，当前实现的空间上界写作 $O(n\log n+k)$，而非保证为严格 $O(n)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int l,r,sz,c,first,last,cnt;
    unsigned pri;
    void read();
    void pushup();
}e[N];
int n,m,k,x,l,r,root[N];
unordered_map<int,int> mp[N];
mt19937 rng(94127);
void node::read(){
    scanf("%d",&c);
    first=last=c;
    sz=cnt=1;
    pri=rng();
}
int size(int u){
    return u?e[u].sz:0;
}
void node::pushup(){
    sz=1+size(l)+size(r);
    first=l?e[l].first:c;
    last=r?e[r].last:c;
    cnt=1;
    if(l)cnt+=e[l].cnt-(e[l].last==c);
    if(r)cnt+=e[r].cnt-(e[r].first==c);
}
void split(int u,int key,int &a,int &b){
    if(!u){
        a=b=0;
        return;
    }
    if(u<=key){
        a=u;
        split(e[u].r,key,e[u].r,b);
        e[u].pushup();
    }
    else{
        b=u;
        split(e[u].l,key,a,e[u].l);
        e[u].pushup();
    }
}
int merge(int a,int b){
    if(!a || !b)return a|b;
    if(e[a].pri<e[b].pri){
        e[a].r=merge(e[a].r,b);
        e[a].pushup();
        return a;
    }
    e[b].l=merge(a,e[b].l);
    e[b].pushup();
    return b;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i){
        e[i].read();
        root[1]=merge(root[1],i);
        ++mp[1][e[i].c];
    }
    for(int id=2;id<=k+1;++id){
        scanf("%d%d%d",&x,&l,&r);
        int a,b,c;
        split(root[x],r,b,c);
        split(b,l-1,a,b);
        root[x]=merge(a,c);
        root[id]=b;
        int u=id,v=x;
        if(size(root[x])<size(root[id])){
            mp[x].swap(mp[id]);
            u=x;
            v=id;
        }
        vector<int> st;
        if(root[u])st.push_back(root[u]);
        while(!st.empty()){
            int p=st.back();
            st.pop_back();
            int col=e[p].c;
            ++mp[u][col];
            auto it=mp[v].find(col);
            if(--it->second==0)mp[v].erase(it);
            if(e[p].l)st.push_back(e[p].l);
            if(e[p].r)st.push_back(e[p].r);
        }
        int cnt=root[id]?e[root[id]].cnt:0;
        printf("%zu %d\n",mp[id].size(),cnt);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202409/VALIDATION.md)
- [a-style-followup-report.json](../tests/202409/a-style-followup-report.json)
- [boundaries.py](../tests/202409/boundaries.py)
- [e-member-pushup-report.json](../tests/202409/e-member-pushup-report.json)
- [e-style-followup-report.json](../tests/202409/e-style-followup-report.json)
- [refactor-report.json](../tests/202409/refactor-report.json)
- [statements.json](../tests/202409/statements.json)

<!-- local-validation-attachments:end -->
