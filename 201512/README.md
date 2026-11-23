---
title: "CSP 201512 五题题解"
contest: "201512"
contest_month: "2015-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "数位分解", "网格扫描", "同时更新", "BFS", "连通块", "网格模拟", "欧拉路径", "Hierholzer", "字典序", "线性代数", "GF(2)", "线性基", "多项式", "bitset"]
status: "published"
problems: [{"id": "A", "title": "数位之和", "tags": ["数位分解"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512A/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb0ce74ace1cba9a20733"}}, {"id": "B", "title": "消除类游戏", "tags": ["网格扫描", "同时更新"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512B/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb15174ace1cba9a207cc"}}, {"id": "C", "title": "画图", "tags": ["BFS", "连通块", "网格模拟"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512C/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb24a74ace1cba9a2083e"}}, {"id": "D", "title": "送货", "tags": ["欧拉路径", "Hierholzer", "字典序"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512D/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb32d74ace1cba9a20871"}}, {"id": "E", "title": "矩阵", "tags": ["线性代数", "GF(2)", "线性基", "多项式", "bitset"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "原版在线评测记录保留；重构版本地 C++17 编译、保存样例及独立对拍见 VALIDATION.md，未重新提交。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP201512E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP201512E/"}], "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb3b974ace1cba9a2089c"}}]
---

# CSP 201512 五题题解

[返回总目录](../README.md) · [本地验证](../tests/201512/VALIDATION.md)

<a id="problem-a"></a>

## A. 数位之和

标签：`数位分解`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb0ce74ace1cba9a20733)。重构版本地验证见 [VALIDATION.md](../tests/201512/VALIDATION.md)，未重新提交在线评测。

### 题意

给定一个十进制非负整数，求它各位数字之和。

输入整数 $n$，$0\le n\le10^9$。

输出数位之和，输入 0 时输出 0。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512A) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512A/)。

### 题解

反复把 `n%10` 加入答案，再令 `n/=10` 删除最低位，直到 n 为 0。每轮处理一个且仅一个数位，最终得到所有数位之和。

初始答案设为 0，输入 0 时无需进入循环也能正确输出 0。时间 $O(\log(n+1))$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,sum;
int main(){
    scanf("%d",&n);
    while(n){
        sum+=n%10;
        n/=10;
    }
    printf("%d\n",sum);
    return 0;
}
```

<a id="problem-b"></a>

## B. 消除类游戏

标签：`网格扫描` · `同时更新`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb15174ace1cba9a207cc)。重构版本地验证见 [VALIDATION.md](../tests/201512/VALIDATION.md)，未重新提交在线评测。

### 题意

棋盘的任意一行或一列中，连续至少三个同色棋子会同时消除为 0。只执行这一轮消除，不继续下落或连锁消除。

输入行列数 $n,m$ 和棋盘颜色，行列数均不超过 30。

输出这一轮同时消除后的棋盘。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512B) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512B/)。

### 题解

保留原棋盘，另开布尔标记。枚举每格作为水平或竖直三个相邻格的起点，三者同色就全部标记。最后统一把标记格输出为 0。

长度至少三的同色段由若干重叠三元组覆盖，因此标记全部且只标记应消除的棋子。先改棋盘会破坏另一方向的判断，必须延后统一输出。时间、空间均为 $O(nm)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=35;
int n,m,a[N][N];
bool vis[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(j+2<m && a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2]){
                for(int k=0;k<3;++k){
                    vis[i][j+k]=true;
                }
            }
            if(i+2<n && a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j]){
                for(int k=0;k<3;++k){
                    vis[i+k][j]=true;
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            printf("%d%c",vis[i][j]?0:a[i][j],j==m-1?'\n':' ');
        }
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 画图

标签：`BFS` · `连通块` · `网格模拟`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb24a74ace1cba9a2083e)。重构版本地验证见 [VALIDATION.md](../tests/201512/VALIDATION.md)，未重新提交在线评测。

### 题意

在初始全为点号的画布上依次画线、填充。横线显示为 `-`，竖线显示为 `|`，交叉显示为 `+`；填充沿上下左右传播，只受线段与画布边界阻挡，原有填充字母不阻挡。

输入宽度 $m$、高度 $n$、操作数和各条操作，宽高至多 100。坐标原点在左下角。

- 操作 `0 x1 y1 x2 y2`：画闭区间水平或竖直线段，可以覆盖之前填入的字母。
- 操作 `1 x y c`：从指定位置填充字符 $c$，同一连通区域中的旧填充字符均可经过。

输出最终画布，按纵坐标从大到小逐行输出。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512C) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512C/)。

### 题解

画线时枚举闭区间上的格子：原本是 + 或另一方向线段则写 +，否则写本方向线符号。画线可以覆盖之前的填充字母。

填充时从起点 BFS，允许经过全部非线段格子，另开 `vis` 记录本轮访问。 不能把“字符已等于填充颜色”当作访问过，因为先前操作可能已留下同色区域，它仍须允许本轮穿过。 处理完成按 y 从大到小输出。

画线逐格维持正确交叉状态；BFS 恰好到达忽略旧填充颜色后的四连通块，所以写入范围符合定义。每次操作最坏 $O(mn)$，空间 $O(mn)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=110,M=4;
const int dx[M]={1,-1,0,0},dy[M]={0,0,1,-1};
int n,m,k;
char a[N][N];
bool vis[N][N];
bool wall(char c){
    return c=='-' || c=='|' || c=='+';
}
int main(){
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            a[i][j]='.';
        }
    }
    while(k--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(!op){
            int u,v;
            scanf("%d%d",&u,&v);
            bool row=(y==v);
            if(x>u)swap(x,u);
            if(y>v)swap(y,v);
            for(int i=y;i<=v;++i){
                for(int j=x;j<=u;++j){
                    char &c=a[i][j];
                    if(c=='+' || (row?c=='|':c=='-'))c='+';
                    else c=row?'-':'|';
                }
            }
        }
        else{
            char c;
            scanf(" %c",&c);
            memset(vis,0,sizeof vis);
            queue<P> q;
            q.push({x,y});
            vis[y][x]=true;
            while(!q.empty()){
                auto [u,v]=q.front();
                q.pop();
                a[v][u]=c;
                for(int i=0;i<M;++i){
                    int x=u+dx[i],y=v+dy[i];
                    if(x<0 || x>=m || y<0 || y>=n)continue;
                    if(vis[y][x] || wall(a[y][x]))continue;
                    vis[y][x]=true;
                    q.push({x,y});
                }
            }
        }
    }
    for(int y=n-1;y>=0;--y){
        puts(a[y]);
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 送货

标签：`欧拉路径` · `Hierholzer` · `字典序`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb32d74ace1cba9a20871)。重构版本地验证见 [VALIDATION.md](../tests/201512/VALIDATION.md)，未重新提交在线评测。

### 题意

给定无向街道图，从路口 1 出发，要求每条边恰好经过一次，求字典序最小的路口序列。

输入点数 $n$、边数 $m$ 和每条街道的两端，$n\le10^4$、$m\le10^5$。

有解时输出完整路口序列，无解时输出 $-1$。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512D) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512D/)。

### 题解

先检查无向欧拉路径的度数条件：奇度点必须为 0 个，或恰好 2 个且起点 1 是其中之一。仅有度数条件还不够，最后还需确认全部边都被遍历。

将各点邻边按邻居编号升序排序，使用 Hierholzer：用栈沿未用边前进，走不动时把当前点加入答案并退栈，最后反转答案。每条无向边使用唯一编号，两侧邻接记录共用访问标记，不能仅标记点。

为什么不能直接把前进顺序当答案？最小邻居可能通向应最后走的死路。 回溯逆序输出会把这类分支放到正确的末尾。 按升序选边时，能够先完成的最小可行分支优先保留；不得不推迟的终止分支由回溯自动后置，因此得到最小字典序的欧拉路线。

最终序列长度必须是 m+1，否则存在与起点不连通的边，输出 -1。

排序时间 $O(m\log m)$，排序后构造 $O(n+m)$，空间 $O(n+m)$。代码用显式栈，避免长度十万的递归调用。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=10010,M=1e5+10;
int n,m,pos[N],st[M],ans[M],top,cnt;
bool vis[M];
vector<vector<P>> g;
int main(){
    scanf("%d%d",&n,&m);
    g.assign(n+1,vector<P>());
    memset(vis,0,sizeof vis);
    memset(pos,0,sizeof pos);
    top=cnt=0;
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    int odd=0;
    for(int u=1;u<=n;++u){
        sort(g[u].begin(),g[u].end());
        odd+=g[u].size()%2;
    }
    if(odd && (odd!=2 || g[1].size()%2==0)){
        puts("-1");
        return 0;
    }
    st[++top]=1;
    while(top){
        int u=st[top];
        int &i=pos[u];
        while(i<(int)g[u].size() && vis[g[u][i].second]){
            ++i;
        }
        if(i==(int)g[u].size()){
            ans[cnt++]=u;
            --top;
        }
        else{
            auto [v,id]=g[u][i++];
            vis[id]=true;
            st[++top]=v;
        }
    }
    if(cnt!=m+1){
        puts("-1");
        return 0;
    }
    reverse(ans,ans+cnt);
    for(int i=0;i<cnt;++i){
        printf("%d%c",ans[i],i+1==cnt?'\n':' ');
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 矩阵

标签：`线性代数` · `GF(2)` · `线性基` · `多项式` · `bitset`

原版评测：[曙梦 OJ 100 分 Accepted](https://oj.shumeng.tech/record/6addb3b974ace1cba9a2089c)。重构版本地验证见 [VALIDATION.md](../tests/201512/VALIDATION.md)，未重新提交在线评测。

### 题意

给定 $m\times m$ 的 01 矩阵 $A$ 和 01 列向量 $b$，在 $GF(2)$ 上计算矩阵乘法，即加法为异或、乘法为与。对每个指数 $k$，求 $A^kb$。

输入维数、矩阵、向量和查询指数。$m\le1000$，查询至多 100 个，$k\le10^9$；矩阵每行和列向量均用没有空格的 01 串表示。

每次查询输出一个 01 串。$k=0$ 时输出原向量。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP201512E) · [公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP201512E/)。

### 题解

**只关心矩阵作用在这个向量上的轨道**

依次生成 $v_0=b,v_1=Ab,v_2=A^2b,\ldots$，并向带表达式的线性基插入这些向量。至多 $m+1$ 个向量就线性相关。设第一次出现

$$v_d=\sum_{j<d}c_jv_j.$$

每个基向量同时保存它由哪些 $v_j$ 异或组成，消元时同步异或表达式，即可求出这组系数。得到多项式 $P(x)=x^d+\sum c_jx^j$，满足 $P(A)b=0$。

**大指数改为多项式取模**

计算 $R(x)=x^k\bmod P(x)$，则 $A^kb=R(A)b$，直接异或 $R$ 中为 1 的系数对应的 $v_j$。预处理 $x^{2^t}\bmod P$，每个询问按二进制组合。

所有向量用 `bitset` 保存。矩阵乘向量的某一位，是该行与向量按位与后的 1 的个数的奇偶。 多项式乘法是若干左移后异或，取余则从高位到低位消去最高项，完全不需要浮点数，也不需要常规三次方矩阵乘法。 若 $b=0$，第一次关系的次数为 0，所有答案直接输出零向量。

**正确性**

将线性相关式两边同时作用任意次 $A$ 后，等式仍成立，故其多项式倍数作用于 $b$ 都是零，指数取余不会改变答案。这里求的是当前向量的湮灭多项式，不要求先算整个矩阵的特征多项式。

**复杂度**

用机器字长 $w$ 表示并行位数，生成和消元约 $O(m^3/w)$；多项式幂约 $O((q+1)m^2\log k/w)$，空间 $O(m^2/w)$ 个机器字。实际性能取决于 `bitset::count` 和移位实现；编译开启优化。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=2048,K=31;
typedef bitset<N> B;
typedef bitset<M> F;
int m,q,d;
char s[N];
B a[N],base[N],f[N];
F rel,pw[K];
vector<B> v;
F rem(F x){
    for(int i=2*d-1;i>=d;--i){
        if(x[i])x^=rel<<(i-d);
    }
    return x;
}
F mul(const F &x,const F &y){
    F z;
    for(int i=0;i<d;++i){
        if(x[i])z^=y<<i;
    }
    return rem(z);
}
int main(){
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%s",s);
        for(int j=0;j<m;++j){
            a[i][j]=(s[j]=='1');
        }
    }
    scanf("%s",s);
    B cur;
    for(int j=0;j<m;++j){
        cur[j]=(s[j]=='1');
    }
    for(int i=0;i<=m;++i){
        B x=cur,e;
        e[i]=1;
        bool ok=false;
        for(int p=m-1;p>=0;--p){
            if(!x[p])continue;
            if(base[p].none()){
                base[p]=x;
                f[p]=e;
                ok=true;
                break;
            }
            x^=base[p];
            e^=f[p];
        }
        if(!ok){
            d=i;
            for(int j=0;j<=d;++j){
                rel[j]=e[j];
            }
            break;
        }
        v.push_back(cur);
        B next;
        for(int j=0;j<m;++j){
            next[j]=(a[j]&cur).count()%2;
        }
        cur=next;
    }
    if(d){
        pw[0][1]=1;
        pw[0]=rem(pw[0]);
        for(int j=1;j<K;++j){
            pw[j]=mul(pw[j-1],pw[j-1]);
        }
    }
    scanf("%d",&q);
    while(q--){
        unsigned k;
        scanf("%u",&k);
        B ans;
        if(d){
            F p;
            p[0]=1;
            for(int j=0;j<K;++j){
                if(k>>j&1)p=mul(p,pw[j]);
            }
            for(int j=0;j<d;++j){
                if(p[j])ans^=v[j];
            }
        }
        for(int j=0;j<m;++j){
            putchar(ans[j]?'1':'0');
        }
        puts("");
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/201512/VALIDATION.md)
- [array-name-followup-report.json](../tests/201512/array-name-followup-report.json)
- [details.txt](../tests/201512/details.txt)
- [nightly-review-followup.json](../tests/201512/nightly-review-followup.json)
- [prose-final-review.json](../tests/201512/prose-final-review.json)
- [report.json](../tests/201512/report.json)
- [retained_oracles.py](../tests/201512/retained_oracles.py)
- [verify-array-name-followup.py](../tests/201512/verify-array-name-followup.py)
- [verify.py](../tests/201512/verify.py)

<!-- local-validation-attachments:end -->
