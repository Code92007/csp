---
title: "CSP 202512 五题题解"
contest: "202512"
contest_month: "2025-12"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "集合比较", "异或", "哈希冲突", "位运算", "枚举", "预处理", "模拟", "逆向操作", "坐标变换", "数论", "线性筛", "积性函数", "容斥", "Trie", "图染色", "可合并数据结构"]
status: "published"
problems: [{"id": "A", "title": "集合", "tags": ["集合比较", "异或", "哈希冲突"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512A"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512A/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0542ace5d1fced2e44df85", "source_sha256": "af7667804637455410c3963f3310620cbe81a8c33cd4d0734f6822708e3221c7", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T07:55:13.377728+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce72ea67df0b81749b5e6"}}, {"id": "B", "title": "数字变换", "tags": ["位运算", "枚举", "预处理"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512B"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512B/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05432ee5d1fced2e44dfdc", "source_sha256": "1492328dcb86414212f59ce97fc0e50fa6d5692c4018ecf879fb3dcbd6f6d559", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T07:57:58.754623+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce72fa67df0b81749b607"}}, {"id": "C", "title": "图片解码", "tags": ["模拟", "逆向操作", "坐标变换"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512C"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512C/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0543afe5d1fced2e44e05e", "source_sha256": "55c55e3daadc8fd30d011358fd4bcb28f96f1e7ae06acab9b3f7b6e36e20c725", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T08:00:33.194767+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce731a67df0b81749b611"}}, {"id": "D", "title": "C 形阵", "tags": ["数论", "线性筛", "积性函数", "容斥"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512D"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512D/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05443ee5d1fced2e44e0ce", "source_sha256": "606c3bb805c8e1cf5a6dd74eff3e7e077a2dfd17fefe5c598dad2c967f1656b5", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T08:02:19.258074+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce733a67df0b81749b625"}}, {"id": "E", "title": "数据抢修", "tags": ["Trie", "图染色", "可合并数据结构"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202512E"}, {"label": "公开题面存档", "url": "https://pcs2.roj.ac.cn/problems/shumeng/CSP202512E/"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0544b1e5d1fced2e44e10f", "source_sha256": "b630cd0290456ab85c5509cb0ffd8e6e14980d98672bd82e250d507350cd9964", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T08:04:51.611391+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce734a67df0b81749b63c"}}]
---
# CSP 202512 五题题解

[原页面](https://code92007.github.io/csp/#/contest/202512) · [验证记录](../tests/202512/VALIDATION.md)

<a id="problem-a"></a>

## A. 集合

标签：`集合比较` · `异或` · `哈希冲突`

本地验证见 [VALIDATION.md](../tests/202512/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0542ace5d1fced2e44df85)。

<!-- refactor-online:A:end -->

### 题意

给定非负整数序列，每个集合的摘要是其中各下标对应数值的异或和。小 C 用摘要是否相同判断两个集合是否相等，需要检查每次判断是否符合真实的集合关系。

输入先给出 `n m` 和长度为 $n$ 的序列 $a$，再依次输入全部 $m$ 个集合 $S_i$、全部 $m$ 个集合 $T_i$。每个集合先给出大小，再给出元素。数据范围为 $1\le n\le10^4$、$1\le m\le100$、$0\le a_i<2^{31}$，每个集合大小不超过 $10^3$；集合非空，元素在 $[1,n]$ 内，按严格递增顺序给出。

输出 $m$ 行：小 C 的判断与真实结论一致时输出 `correct`，否则输出 `wrong`。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512A/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202512A)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce72ea67df0b81749b5e6)。

### 题解

**分别判断集合与摘要是否相等**

读入每个 $S_i$ 时，用 `s[i]` 保存元素，并计算异或值 `h[i]`。再逐个读入 $T_i$，保存到 `t`，同时计算它的异或值 `v`。

输入已经严格递增，两个向量逐项相同就等价于集合相同。因此，`s[i]==t` 是真实结论，`h[i]==v` 是小 C 的结论；比较二者得到 `ok`，再据此输出。

**为什么不能只比较异或值？**

不同集合可能产生相同摘要。例如数值为 `1,2,3` 时，下标集合 `{1,2}` 与 `{3}` 不同，但摘要均为 3。集合相同时摘要一定相同，因此误判只会出现在“集合不同、摘要相同”的情况。

**正确性**

向量比较准确判断集合是否相等，异或值比较准确复现小 C 的判断。两种布尔结论相同，恰好表示小 C 得到了正确答案，所以程序的每次输出都正确。

**复杂度**

设两批集合的元素总数为 $L$，时间复杂度 $O(n+L)$。只需保存全部 $S_i$ 和当前的 $T_i$，空间复杂度 $O(n+L)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=105;
int n,m,k,v,a[N],h[M];
vector<int>s[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&k);
        s[i].resize(k);
        for(int &x:s[i]){
            scanf("%d",&x);
            h[i]^=a[x];
        }
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&k);
        vector<int>t(k);
        v=0;
        for(int &x:t){
            scanf("%d",&x);
            v^=a[x];
        }
        bool ok=((s[i]==t)==(h[i]==v));
        puts(ok?"correct":"wrong");
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 数字变换

标签：`位运算` · `枚举` · `预处理`

本地验证见 [VALIDATION.md](../tests/202512/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05432ee5d1fced2e44dfdc)。

<!-- refactor-online:B:end -->

### 题意

将一个九位二进制整数补足前导零，拆成高、中、低三个三位数 $(a,b,c)$。一轮密钥 $k$ 将它变成 $(b,c\oplus f(b,k),a\oplus f(c,k))$，其中 $f(x,k)=((x^2+k^2)\bmod8)\oplus k$。已知全部密钥和若干最终值，恢复它们各自的初始值。

输入先给出 `n m`，再给出 $m$ 个密钥和 $n$ 个最终值。数据范围为 $1\le n\le5\times10^5$、$1\le m\le10^3$、$0\le k_i<8$，最终值均在 $[0,512)$ 中；每个最终值都有唯一的初始值。

输出一行 $n$ 个整数，按输入顺序给出恢复出的初始值。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512B/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202512B)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce72fa67df0b81749b607)。

### 题解

**枚举全部初始状态**

九位二进制整数只有 512 种。不必对每个最终值单独倒推，可以枚举初始值 `i`，依次执行全部密钥，得到最终值 `x`，记录 `ans[x]=i`。所有查询都直接查这张逆表。

每轮先从旧状态中拆出 `a,b,c`，再分别拼接三个新位段。高三位为 `b`，中三位为 `c^f(b,k)`，低三位为 `a^f(c,k)`；三个位段互不重叠，可以分别按位或到新状态中。

**每轮变换为什么可逆？**

若一轮输出为 $(A,B,C)$，可以依次恢复

$$b=A,\qquad c=B\oplus f(b,k),\qquad a=C\oplus f(c,k).$$

每一步的右侧都已经确定，因此一轮变换是双射，多轮复合仍是双射。枚举得到的 512 个最终值互不相同，逆表的每个位置都会恰好写入一次。

**正确性**

正向模拟完全按照题目规则计算每个初始值的最终值，并将这对关系反向记录。双射性质保证逆表没有冲突或遗漏，所以查询 `ans[x]` 就得到唯一正确的初始值。

**复杂度**

预处理时间 $O(512m)$，查询总时间 $O(n)$，空间复杂度 $O(m+512)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=512;
int n,m,x,k[N],ans[M];
int f(int x,int k){
    return ((x*x+k*k)%8)^k;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d",&k[i]);
    }
    for(int i=0;i<M;++i){
        x=i;
        for(int j=1;j<=m;++j){
            int a=x>>6,b=x>>3&7,c=x&7;
            x=b<<6;
            x|=(c^f(b,k[j]))<<3;
            x|=a^f(c,k[j]);
        }
        ans[x]=i;
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&x);
        printf("%d%c",ans[x]," \n"[i==n]);
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 图片解码

标签：`模拟` · `逆向操作` · `坐标变换`

本地验证见 [VALIDATION.md](../tests/202512/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0543afe5d1fced2e44e05e)。

<!-- refactor-online:C:end -->

### 题意

原图先在右下方补上问号，成为 $Z\times Z$ 方阵，再依次执行局部旋转或翻转。给定最终图像和记录所有操作的密钥，要求还原原图及其尺寸。

输入依次给出 $Z$、最终图像的 $Z$ 行字符、密钥长度 $k$ 和 $k$ 个密钥整数。密钥首数是操作数 $t$，之后每次操作占六个整数，所以 $k=6t+1$。数据范围为 $1\le Z\le400$、$1\le t\le5\times10^4$；局部区域始终在图内，两边长度均不超过 $\min(Z,10)$。原图只含大小写字母、数字和下划线，问号只用于补齐。两种操作如下：

- `1 u v l d r`：将左上角为 `(u,v)`、边长为 `l` 的正方形顺时针旋转 `d` 度，再将整图逆时针旋转 `r` 次，每次 90 度。`d` 为 90、180 或 270，`r` 在 0 到 3 之间。
- `2 u d l r o`：翻转第 `u` 到 `d` 行、第 `l` 到 `r` 列的矩形。`o=1` 表示上下翻转，`o=-1` 表示左右翻转。

第一行输出原图的行数与列数，接下来输出原图的每一行。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512C/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202512C)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce731a67df0b81749b611)。

### 题解

**按相反顺序撤销**

最后一次加密必须最先撤销。旋转加密先处理局部，再处理整图，因此解密时要先撤销整图旋转，再撤销局部旋转。上下、左右翻转都是自身的逆操作，直接再翻转一次即可。

**整图旋转只修改坐标映射**

如果每次整图旋转都搬动字符，最坏会达到 $O(tZ^2)$。实际上只需用 `dir` 记录四种方向，数组 `a` 保持原位；`at(x,y)` 根据方向，把逻辑坐标映射到数组位置，并返回对应字符的引用。

对零起点坐标，一次映射使用 $(x,y)\to(y,Z-1-x)$。它描述的是“新位置应读取哪个旧位置”，方向与图像自身的转动相反。撤销一次整图旋转时，只更新 `dir`，之后的局部访问自然遵循新方向。

**局部操作先复制，再写回**

每个局部区域最多有 100 个字符，先通过 `at` 复制到缓冲数组 `b`，再根据逆旋转或翻转的坐标关系写回。这样不会覆盖尚未读取的字符。

全部撤销后，原图仍位于补齐方阵的左上角。原图中没有问号，因此沿第一列、第一行读到问号前的位置，就能分别确定行数与列数。

**正确性**

坐标映射始终表示当前逻辑图像，改变方向与真实旋转整图等价。缓冲数组使每个局部操作都能按逆映射同时还原，避免写入顺序影响结果。

程序按加密的逆序执行各步逆操作，最终恢复加密前的补齐方阵。问号边界又准确区分原图与补齐区域，因此输出尺寸和内容均正确。

**复杂度**

读取、输出图像共 $O(Z^2)$，每次操作最多处理 100 个字符，总时间复杂度 $O(Z^2+100t)$。保存图像和全部操作，空间复杂度 $O(Z^2+t)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=405,M=50010,K=6,L=15;
int z,k,t,dir,n,m,op[M][K];
char a[N][N],b[L][L];
char &at(int x,int y){
    for(int i=0;i<dir;++i){
        int v=y;
        y=z-1-x;
        x=v;
    }
    return a[x][y];
}
int main(){
    scanf("%d",&z);
    for(int i=0;i<z;++i){
        scanf("%s",a[i]);
    }
    scanf("%d%d",&k,&t);
    for(int i=0;i<t;++i){
        for(int &x:op[i]){
            scanf("%d",&x);
        }
    }
    for(int id=t-1;id>=0;--id){
        int *p=op[id];
        if(p[0]==1){
            int u=p[1]-1,v=p[2]-1;
            int len=p[3],rot=p[4]/90;
            dir=(dir+4-p[5])%4;
            for(int i=0;i<len;++i){
                for(int j=0;j<len;++j){
                    b[i][j]=at(u+i,v+j);
                }
            }
            for(int i=0;i<len;++i){
                for(int j=0;j<len;++j){
                    int x=i,y=j;
                    for(int h=0;h<rot;++h){
                        int q=y;
                        y=len-1-x;
                        x=q;
                    }
                    at(u+i,v+j)=b[x][y];
                }
            }
        }
        else{
            int u=p[1]-1,d=p[2]-1;
            int l=p[3]-1,r=p[4]-1;
            for(int i=u;i<=d;++i){
                for(int j=l;j<=r;++j){
                    b[i-u][j-l]=at(i,j);
                }
            }
            for(int i=u;i<=d;++i){
                for(int j=l;j<=r;++j){
                    at(i,j)=p[5]==1?b[d-i][j-l]:b[i-u][r-j];
                }
            }
        }
    }
    while(n<z && at(n,0)!='?'){
        ++n;
    }
    while(m<z && at(0,m)!='?'){
        ++m;
    }
    printf("%d %d\n",n,m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            printf("%c",at(i,j));
        }
        puts("");
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. C 形阵

标签：`数论` · `线性筛` · `积性函数` · `容斥`

本地验证见 [VALIDATION.md](../tests/202512/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05443ee5d1fced2e44e0ce)。

<!-- refactor-online:D:end -->

### 题意

正整数七元组 $(A,B,C,D,E,F,G)$ 满足 $AC=B^2$、$EG=F^2$、$ABC=CDE=EFG$，称为一个 C 形阵。大小定义为 $B$，价值定义为 $D$；七个位置恰有六种不同数值时，称为完美 C 形阵。

输入一行 `op n`，数据范围为 $op\in\{0,1\}$、$1\le n\le10^7$。`op=0` 统计大小不超过 $n$ 的全部 C 形阵，`op=1` 只统计其中的完美 C 形阵。

输出所统计阵的价值之和，对 $998244353$ 取模。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512D/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202512D)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce733a67df0b81749b625)。

### 题解

**用两个数确定整个阵**

比例关系给出 $ABC=B^3$、$EFG=F^3$，结合二者相等，得到 $B=F=b$。选定 $C,E$ 后，其余三个数唯一确定：

$$A=\frac{b^2}{C},\qquad G=\frac{b^2}{E},\qquad D=\frac{b^3}{CE}.$$

所以只需枚举能使三个分式均为正整数的 $C,E$，累加对应的 $D$。

**按质因子拆分选择**

固定 $p^e\parallel b$，设 $C,E$ 中的指数分别为 $e+x,e+y$。三个分式为整数，等价于

$$-e\le x,y\le e,\qquad x+y\le e.$$

该质因子对价值的贡献为 $p^{e-x-y}$。不同质因子的指数独立选择，因此，固定大小的价值和是积性函数；每个质数幂的局部值可以直接枚举 $(x,y)$ 计算。

**把额外相等归为六种关系**

由于 $B=F$ 恒成立，恰好六种数值等价于 $A,B,C,D,E,G$ 两两不同。把所有质因子上的 $x,y$ 分别看作向量 $X,Y$，六个数的指数偏移依次是

$$-X,\quad0,\quad X,\quad-X-Y,\quad Y,\quad-Y.$$

比较这些偏移，全部额外相等可以归为

$$X=0,\quad Y=0,\quad X=Y,\quad X=-Y,\quad Y=-2X,\quad X=-2Y.$$

例如 $A=D$ 等价于 $Y=0$，$C=D$ 等价于 $Y=-2X$。这些关系是整组指数同时相等，不是只要求某一个质因子相等。

**利用共同交集做容斥**

记全部方案的价值和为 $T$，关系 $X=0,X=Y,X=-Y,Y=-2X$ 下的价值和分别为 $U,V,W,Z$。交换 $X,Y$ 后，另外两种坏关系的和分别仍为 $U,Z$。

任意两种不同坏关系同时成立，都会推出 $X=Y=0$。此时七个数都等于 $b$，只有一个阵，价值为 $b$。所以六个坏集合除共同交集外两两不交，它们的并集价值为 $2U+V+W+2Z-5b$。

固定大小 $b$ 的完美阵价值和因此为

$$T(b)-2U(b)-V(b)-W(b)-2Z(b)+5b.$$

这五个函数都能按质因子独立计算。`op=0` 只需要 $T$，`op=1` 才需要全部五个函数。

**线性筛与积性递推**

先用线性筛得到每个数的最小质因子 `mn[i]`。将 $i=p^er$ 分解到 $p\nmid r$，对每个函数使用

$$F(i)=F(p^e)F(r).$$

对不超过 $\sqrt n$ 的质数，预先枚举各次幂的 $(x,y)$，将五个局部值存入 `g[p]`。大于 $\sqrt n$ 的质数只能出现一次，可以直接使用

$$\begin{aligned}
T(p)&=p^3+2p^2+3p+2,\\
U(p)&=p^2+p+1,\\
V(p)&=p^3+p,\\
W(p)&=3p,\\
Z(p)&=p.
\end{aligned}$$

按大小递增计算，`r` 的值已经求出，便能得到五个函数在 `i` 处的值，再按 `op` 累加。大小 1 时，全部方案只有七个数都为 1 的阵，价值为 1；完美方案则为 0。

**正确性**

参数化与原始约束互相等价，按指数枚举恰好覆盖全部合法的 $C,E$。质因子间独立，局部价值相乘再求和，正好给出固定大小的总价值。

六种坏关系覆盖所有额外相等，容斥公式精确删除非完美方案。筛法和积性递推又按定义求出了各函数值，所以累加后的两种答案均正确。

**复杂度**

线性筛耗时 $O(n)$。提取最小质因子的幂次并递推所有数，可用 $O(n\log n)$ 作保守上界；局部表预处理可用 $O(\sqrt n\log^3 n)$ 作上界。

总空间复杂度 $O(n)$。`op=0` 只分配一行函数值，`op=1` 分配五行，避免无关数组占用内存。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10,M=5,K=3200,L=75;
const int mod=998244353;
typedef array<int,M> A;
int op,n,lim,cnt,mn[N];
ll ans;
vector<int>pr,f[M];
vector<A>g[K];
A calc(int p,int e){
    ll pw[L];
    pw[0]=1;
    for(int i=1;i<=3*e;++i){
        pw[i]=pw[i-1]*p%mod;
    }
    A res;
    res.fill(0);
    for(int x=-e;x<=e;++x){
        for(int y=-e;y<=e;++y){
            if(x+y>e)continue;
            int w=pw[e-x-y];
            res[0]=(res[0]+w)%mod;
            if(!x)res[1]=(res[1]+w)%mod;
            if(x==y)res[2]=(res[2]+w)%mod;
            if(x==-y)res[3]=(res[3]+w)%mod;
            if(y==-2*x)res[4]=(res[4]+w)%mod;
        }
    }
    return res;
}
int main(){
    scanf("%d%d",&op,&n);
    lim=sqrt(n);
    for(int i=2;i<=n;++i){
        if(!mn[i]){
            mn[i]=i;
            pr.push_back(i);
        }
        for(int &p:pr){
            if(p>mn[i] || 1ll*p*i>n)break;
            mn[i*p]=p;
        }
    }
    for(int &p:pr){
        if(p>lim)break;
        ll x=p;
        for(int e=1;x<=n;++e){
            g[p].push_back(calc(p,e));
            x*=p;
        }
    }
    cnt=op?M:1;
    for(int j=0;j<cnt;++j){
        f[j].resize(n+1);
        f[j][1]=1;
    }
    ans=op?0:1;
    for(int i=2;i<=n;++i){
        int p=mn[i],r=i,e=0;
        while(r%p==0){
            r/=p;
            ++e;
        }
        A v;
        if(p<=lim)v=g[p][e-1];
        else{
            ll p2=1ll*p*p%mod,p3=p2*p%mod;
            v[0]=(p3+2*p2+3ll*p+2)%mod;
            v[1]=(p2+p+1)%mod;
            v[2]=(p3+p)%mod;
            v[3]=3ll*p%mod;
            v[4]=p;
        }
        for(int j=0;j<cnt;++j){
            f[j][i]=1ll*f[j][r]*v[j]%mod;
        }
        ll val=f[0][i];
        if(op){
            val+=-2ll*f[1][i]-f[2][i]-f[3][i]-2ll*f[4][i]+5ll*i;
        }
        ans=(ans+val)%mod;
    }
    printf("%lld\n",(ans+mod)%mod);
    return 0;
}
```

<a id="problem-e"></a>

## E. 数据抢修

标签：`Trie` · `图染色` · `可合并数据结构`

本地验证见 [VALIDATION.md](../tests/202512/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0544b1e5d1fced2e44e10f)。

<!-- refactor-online:E:end -->

### 题意

每个数据包是允许重复权值的多重集。将其划分为非空子包，要求同一子包内任意两个数据实例的权值异或至少为 $W$，最少子包数就是维修代价，空包代价为零。由于 $W>0$，同权值的不同实例也不能放在一起。需要维护插入、合并及所有活跃包的代价之和。

输入先给出 `n W`，接下来每包一行，先给元素数，再给各元素权值；随后输入操作数 $q$ 及各次操作。数据范围为 $1\le n,q,\sum m_i\le5\times10^5$，所有权值在 $[0,10^9]$ 内，$W$ 为正整数；单个初始包可以为空，编号从 1 开始。操作如下：

- `1 u x`：向活跃包 `u` 插入一个权值为 `x` 的实例。
- `2 u v`：把活跃包 `v` 并入 `u`，保证二者不同；此后 `v` 注销，不再出现于后续操作。
- `3`：查询所有活跃包的维修代价之和。

每次查询输出一行一个整数，表示所有活跃包的维修代价之和。

来源：[公开题面存档](https://pcs2.roj.ac.cn/problems/shumeng/CSP202512E/)；[曙梦 OJ 原题](https://oj.shumeng.tech/p/CSP202512E)。原版代码评测：[曙梦 OJ 100 分 Accepted（复刻评测）](https://oj.shumeng.tech/record/6adce734a67df0b81749b63c)。

### 题解

**把分包转成冲突图染色**

每个数据实例对应一个顶点。当 $x\oplus y<W$ 时，连一条冲突边。一个稳定子包正好是一个独立集，因此维修代价等于冲突图的最少颜色数。

权值都小于 $2^{30}$。若 $W\ge2^{30}$，所有不同实例都冲突，答案直接等于包内元素个数。下面只讨论较小的 $W$，令最高的 1 位为 $h$，并记 $k=W-2^h$。

**从最少颜色数到最大团**

比第 $h$ 位更高的前缀不同时，两个权值的异或一定大于 $W$，完全没有冲突。各前缀组可以复用颜色，所以包的代价取各组代价的最大值。

在固定前缀内，按第 $h$ 位分成两侧。同侧异或小于 $2^h$，因此每一侧内部都是团。一个颜色至多容纳两点，而且必须来自两侧；能共用颜色的点对，恰好是冲突图补图中的边。

若组内有 $s$ 个点，补图最大匹配大小为 $\nu$，最少颜色数就是 $s-\nu$。补图是二分图，最大匹配等于最小点覆盖；其最大独立集大小也是 $s-\nu$，而该独立集正是原冲突图的最大团。因此只需求每组的最大团。

**把两侧的低位对齐**

跨侧的异或在第 $h$ 位为 1，要形成冲突，低位异或必须严格小于 $k$。为了让相关递归落到同一个节点，对第 $h$ 位为 1 的实例，将低 $h$ 位异或 $k$，再从所有权值中删除第 $h$ 位，用剩下的 29 位建立 Trie。

节点保存来自两侧的实例数 `cnt[0]`、`cnt[1]`，以及最优团大小 `dp`。相同权值的实例沿同一路径累加计数，重数始终保留。

设正在处理的位为 `b`，两个孩子为 `l,r`，按三种情况更新：

- `b>=h`：仍在区分原来的高位前缀，各组之间没有冲突，取两个孩子 `dp` 的最大值。
- `0<=b<h` 且 `k` 的这一位为 1：对齐后，不同孩子之间的跨侧点已经严格满足冲突条件，两个孩子的最优团可以相加。
- 其余情况：若同时选两侧，就只能继续同一个孩子；也可以只选某一侧的全部实例。因此取 `cnt[0]`、`cnt[1]`、两个孩子 `dp` 的最大值。

到达叶子时，所有比较位都相同，严格小于不成立，不能把两侧合在一起。第三种规则自然退化为两侧计数的最大值。

**插入、合并与总答案**

插入只经过一条 Trie 路径，更新计数后自底向上执行 `pull`。合并两包时，递归合并对应孩子、相加两侧计数，再重新计算 `dp`；若一侧为空，直接复用另一侧子树。

全局维护 `ans`。修改一个包前减去它的旧代价，修改后加入新代价；合并时先减去两个旧包，再加入合并包。这样查询只需输出 `ans`。

**正确性**

冲突图染色准确描述稳定划分，高位分组允许颜色复用，而组内的二分图补图使染色数等于最大团大小。对齐后的三种递归覆盖全部跨侧限制，叶子又排除了等于阈值的情况，因此 Trie 的 `dp` 正好等于当前包的维修代价。

插入和合并保持各节点的计数与递推关系，总答案又始终减去旧值、加入新值，所以所有查询都正确。整个过程按实例计数，不会丢失重复权值带来的冲突。

**复杂度**

设初始元素总数与后续插入元素数之和为 $T$，位数为 $B\le30$。每次插入耗时 $O(B)$；合并中每次遇到两个非空节点，都会消耗一个不再作为独立节点使用的节点，因此全部合并的总访问量受已创建节点数约束。

总时间复杂度为 $O(TB+q+n)$，逻辑空间复杂度为 $O(TB+n)$。源码按最大元素总数预留静态节点池，避免动态扩容时的瞬时内存峰值，节点池容量约为 572 MiB。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=2,K=N*60;
int n,q,h,k,op,u,v,x,tot,rt[N],sz[N];
ll w,ans;
bool full;
struct node{
    int ch[M],cnt[M],dp;
}tr[K];
void pull(int u,int b){
    node &t=tr[u];
    int l=t.ch[0],r=t.ch[1];
    if(b>=h){
        t.dp=max(tr[l].dp,tr[r].dp);
    }
    else if(b>=0 && (k>>b&1)){
        t.dp=tr[l].dp+tr[r].dp;
    }
    else{
        t.dp=max({t.cnt[0],t.cnt[1],tr[l].dp,tr[r].dp});
    }
}
int insert(int u,int x,int s,int b){
    if(!u)u=++tot;
    ++tr[u].cnt[s];
    if(b>=0){
        int c=x>>b&1;
        int v=insert(tr[u].ch[c],x,s,b-1);
        tr[u].ch[c]=v;
    }
    pull(u,b);
    return u;
}
int merge(int u,int v,int b){
    if(!u || !v)return u|v;
    for(int i=0;i<2;++i){
        tr[u].cnt[i]+=tr[v].cnt[i];
    }
    if(b>=0){
        for(int i=0;i<2;++i){
            tr[u].ch[i]=merge(tr[u].ch[i],tr[v].ch[i],b-1);
        }
    }
    pull(u,b);
    return u;
}
void add(int u,int x){
    ++sz[u];
    if(full)return;
    int s=x>>h&1,low=x&((1<<h)-1);
    if(s)low^=k;
    int key=((x>>(h+1))<<h)|low;
    rt[u]=insert(rt[u],key,s,28);
}
int val(int u){
    return full?sz[u]:tr[rt[u]].dp;
}
int main(){
    scanf("%d%lld",&n,&w);
    full=w>=(1ll<<30);
    if(!full){
        while((1ll<<(h+1))<=w){
            ++h;
        }
        k=w-(1ll<<h);
    }
    for(int i=1;i<=n;++i){
        int m;
        scanf("%d",&m);
        while(m--){
            scanf("%d",&x);
            add(i,x);
        }
        ans+=val(i);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&u,&x);
            ans-=val(u);
            add(u,x);
            ans+=val(u);
        }
        else if(op==2){
            scanf("%d%d",&u,&v);
            ans-=val(u)+val(v);
            sz[u]+=sz[v];
            sz[v]=0;
            if(!full)rt[u]=merge(rt[u],rt[v],28);
            rt[v]=0;
            ans+=val(u);
        }
        else{
            printf("%lld\n",ans);
        }
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202512/VALIDATION.md)
- [a-style-followup-report.json](../tests/202512/a-style-followup-report.json)
- [ab-report.json](../tests/202512/ab-report.json)
- [ab-style-followup.json](../tests/202512/ab-style-followup.json)
- [ac-constants-cases.json](../tests/202512/ac-constants-cases.json)
- [ac-constants-report.json](../tests/202512/ac-constants-report.json)
- [cd-report.json](../tests/202512/cd-report.json)
- [d-mod-followup-report.json](../tests/202512/d-mod-followup-report.json)
- [e-report.json](../tests/202512/e-report.json)
- [online-update-report.json](../tests/202512/online-update-report.json)
- [online-verdicts.json](../tests/202512/online-verdicts.json)
- [summary.json](../tests/202512/summary.json)
- [verify-ab.py](../tests/202512/verify-ab.py)
- [verify-ac-constants.py](../tests/202512/verify-ac-constants.py)
- [verify-cd.py](../tests/202512/verify-cd.py)
- [verify-e.py](../tests/202512/verify-e.py)

<!-- local-validation-attachments:end -->
