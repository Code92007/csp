---
title: "CSP 202609 五题题解"
contest: "202609"
contest_month: "2026-09"
date: "2026-10-23"
updated: "2026-11-25"
tags: ["CSP", "数学", "精度", "查表", "模拟", "动态规划", "01背包", "队列", "调度", "状态机", "图论", "二分图", "带权并查集", "区间", "构造", "树", "点分治", "动态查询", "位运算", "哈希表"]
status: "published"
problems: [{"id": "A", "title": "流程规划（其一）", "tags": ["数学", "精度", "查表", "模拟"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609A"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b053aaee5d1fced2e44d256", "source_sha256": "dd814f4d41176bf7e0954ae14c1a672c74a0aacd048054526d93459dd2009af7", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T07:21:26.555732+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6c2a67df0b81749b341"}}, {"id": "B", "title": "流程规划（其二）", "tags": ["动态规划", "01背包", "精度"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609B"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b053b70e5d1fced2e44d372", "source_sha256": "4103c0cd5c428919f97be1c656c9c02c8137e0ecbbdf8b3db172df611d1c530e", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T07:25:08.363809+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6e0a67df0b81749b3d9"}}, {"id": "C", "title": "轮转调度", "tags": ["模拟", "队列", "调度", "状态机"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609C"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b053bfae5d1fced2e44d470", "source_sha256": "022f313e6279caf09fa08cc7963adc8e67ef5ab39475f0efe7835a1dc5bffd59", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T07:28:21.431850+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6e2a67df0b81749b3e7"}}, {"id": "D", "title": "数字分组", "tags": ["图论", "二分图", "带权并查集", "区间", "构造"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609D"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b053ca3e5d1fced2e44d560", "source_sha256": "b66586cebc5f4c41bdf7c1fc3614ca36cce5df9b07ea676104ae58cad1e30a35", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T07:30:40.051820+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce6e4a67df0b81749b40a"}}, {"id": "E", "title": "奇", "tags": ["树", "点分治", "动态查询", "位运算", "哈希表"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202609E"}, {"label": "公开复刻题面（独立编写）", "url": "https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json"}], "oj": {"score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05d79ce5d1fced2e45d666", "source_sha256": "8e41f632e8516a57e9eb5c663c7936cfbdc9ea058a053c3a8f28708c6f99bd87", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T18:32:58.362674+00:00"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce90ea67df0b81749bfe2"}, "oj_revisions": [{"score": 50.0, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6b053d35e5d1fced2e44d671", "source_sha256": "0d3ca8a7b3c3aece6ae414592803001d2cf9e4a96af421933b0608f9fec3999f", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "failed", "observed_at": "2026-11-24T07:33:07.900743+00:00"}]}]
---
# CSP 202609 五题题解

[原页面](https://code92007.github.io/csp/#/contest/202609) · [本版验证记录](../tests/202609/VALIDATION.md)


<a id="problem-a"></a>

## A. 流程规划（其一）

标签：`数学` · `精度` · `查表` · `模拟`

本版验证：已通过 C++17 编译、292 组精确比较对拍、13 个现有样例与测试点。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053aaee5d1fced2e44d256)。

原版评测记录：[历史记录 1](https://oj.shumeng.tech/record/6adce6c2a67df0b81749b341)。

<!-- refactor-online:A:end -->

### 题意

有 $n$ 个相互独立的制造环节。题目给出各环节的平均耗时 $\mu_i$ 和标准差 $\sigma_i$，总平均耗时为 $\mu=\sum\mu_i$，总标准差为 $\sigma=\sqrt{\sum\sigma_i^2}$。  
给定时间上限 $m$，计算 $z=(m-\mu)/\sigma$，再从一张递增表中选择与 $z$ 横坐标距离最近的表项。若恰好等距，选择横坐标较小的表项。

输入依次为 `n m k`、$n$ 个均值、$n$ 个标准差、$k$ 个横坐标及 $k$ 个函数值；$n,m\le100$，$k\le20$。实数均为三位小数，保证 $z$ 在表内。

输出这一项在输入中的函数值，保留原来的三位小数格式。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609A)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

**第一步：只实现题目给出的公式**

输入已经给出正态分布函数值表，无需自行计算。总方差是各标准差平方之和，不能直接把标准差相加。

**第二步：用相邻表项的中点确定最近项**

对相邻横坐标 $x_i,x_{i+1}$，若 $z\le(x_i+x_{i+1})/2$，就应选左边；从左到右遇到第一个符合的中点即可停止。等号选左边，恰好符合题意。

**第三步：避免浮点数把“等距”判断成“不等距”**

将均值、标准差、表横坐标都放大 1000 倍，分别记为整数 $M_i,S_i,X_i$。令 $D=1000m-\sum M_i$、$V=\sum S_i^2$，则 $z=D/\sqrt V$。

题目保证 $z\ge0$，以下比较两边非负，可以平方：

$$z\le\frac{X_i+X_{i+1}}{2000}
\iff (2000D)^2\le(X_i+X_{i+1})^2V.$$

输入固定为三位小数，直接用 `scanf("%d.%d",&a,&b)` 读取，放大后的值为 `a*1000+b`。代码用 `mu` 保存 $\sum M_i$、`var` 保存 $V$、`num` 保存 $D$，`sum` 保存相邻横坐标之和。

由题目范围可得 $0\le D\le10^5$、$V\le10^{10}$、$X_i+X_{i+1}\le2000$，比较两边均不超过 $4\times10^{16}$，使用 `ll` 即可。函数值用字符数组原样保存，输出时不会丢失末尾的零。

**正确性**

递增表的相邻中点将数轴分成各表项的最近区域。从左到右找到的第一个中点，是当前区域的右边界，等距时归左；若没有中点符合，就选最后一项。整数缩放和平方保持比较结果，因此返回的表项满足最近与并列规则。

**复杂度**

时间 $O(n+k)$，额外空间 $O(k)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=25,M=10;
int n,m,k,a,b;
ll mu,var,x[N];
char phi[N][M];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i){
        scanf("%d.%d",&a,&b);
        mu+=a*1000+b;
    }
    for(int i=0;i<n;++i){
        scanf("%d.%d",&a,&b);
        ll v=a*1000+b;
        var+=v*v;
    }
    for(int i=0;i<k;++i){
        scanf("%d.%d",&a,&b);
        x[i]=a*1000+b;
    }
    for(int i=0;i<k;++i){
        scanf("%s",phi[i]);
    }
    ll num=m*1000-mu;
    int id=k-1;
    for(int i=0;i<k-1;++i){
        ll sum=x[i]+x[i+1];
        if(4000000ll*num*num<=sum*sum*var){
            id=i;
            break;
        }
    }
    printf("%s\n",phi[id]);
    return 0;
}
```

<a id="problem-b"></a>

## B. 流程规划（其二）

标签：`动态规划` · `01背包` · `精度`

本版验证：已通过 C++17 编译、250 组子集枚举对拍、21 个现有样例与测试点。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053b70e5d1fced2e44d372)。

原版评测记录：[历史记录 1](https://oj.shumeng.tech/record/6adce6e0a67df0b81749b3d9)。

<!-- refactor-online:B:end -->

### 题意

从 $n$ 个可选环节中各选或不选一次，求最大收益。选中集合 $S$ 的收益是 $\sum\mu_i$，总标准差是 $\sqrt{\sum\sigma_i^2}$。非空集合需满足 $m/\sqrt{\sum\sigma_i^2}\ge q$；也允许选择空集合，收益为 0。

输入依次为 `n m q`、$n$ 个收益、$n$ 个标准差；$n\le100$，每个整数收益 $\mu_i\le100$。标准差保留一位小数，$q$ 保留三位小数。

输出一个最大收益整数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609B)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

**把条件改写成“总风险受限”**

对非空集合平方移项可得 $q^2\sum\sigma_i^2\le m^2$。每个环节贡献固定收益和方差，且最多选择一次，因此是 01 背包。

**为什么按收益定义状态？**

方差含小数，但总收益最多只有 10000。定义 `dp[v]` 为恰好取得收益 $v$ 所需的最小风险，无法达到时为无穷大。将标准差放大 10 倍后的整数记为 $s_i$，风险取 $s_i^2$，即真实方差的 100 倍。

初始 `dp[0]=0`，处理第 $i$ 个环节时，收益从大到小更新：

$$dp[v]=\min(dp[v],dp[v-\mu_i]+s_i^2).$$

倒序保证每个环节最多使用一次，正序更新则会错误地变成完全背包。

令 $Q=1000q$，最终可行条件完全使用整数判断：

$$dp[v]\cdot Q^2\le100\,m^2\cdot10^6.$$

代码直接用 `%d.%d` 读取小数：`q` 按 1000 倍保存，标准差按 10 倍保存，收益读入 `mu`，总收益上界为 `sum`。从大到小扫描收益，输出第一个可行值。

**正确性**

对每个环节，转移分别覆盖“不选”和“选”两类方案，并取较小风险。归纳得到 `dp[v]` 为收益恰为 $v$ 的最小风险；只有这一最小风险都超限时，该收益才不可行，因此倒序扫描得到最大可行收益。

**复杂度**

设 $U=\sum\mu_i\le10000$，时间 $O(nU)$，空间 $O(U)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,M=10005;
const int INF=0x3f3f3f3f;
int n,m,q,sum,mu[N],dp[M];
int main(){
    int a,b;
    scanf("%d%d%d.%d",&n,&m,&a,&b);
    q=a*1000+b;
    for(int i=1;i<=n;++i){
        scanf("%d",&mu[i]);
    }
    memset(dp,INF,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;++i){
        scanf("%d.%d",&a,&b);
        int w=a*10+b,v=w*w;
        sum+=mu[i];
        for(int j=sum;j>=mu[i];--j){
            dp[j]=min(dp[j],dp[j-mu[i]]+v);
        }
    }
    ll lim=(ll)1e8*m*m;
    for(int i=sum;i>=0;--i){
        if(1ll*dp[i]*q*q<=lim){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 轮转调度

标签：`模拟` · `队列` · `调度` · `状态机`

本版验证：已通过 C++17 编译、400 组逐毫秒模拟对拍、21 个现有样例与测试点。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053bfae5d1fced2e44d470)。

原版评测记录：[历史记录 1](https://oj.shumeng.tech/record/6adce6e2a67df0b81749b3e7)。

<!-- refactor-online:C:end -->

### 题意

有 $n$ 个任务、$m$ 个 CPU 和 $m$ 条任务队列。任务按编号轮流进入各队列，每个 CPU 有自己的时间片长度。CPU 每毫秒完成 1 单位工作；若是任务偏好的 CPU，则速度为 2，不足 2 单位也占 1 毫秒。

每隔 $T$ 毫秒，CPU 对应的队列整体循环移动一位，运行中的任务不中断，也不算在队列中。时间片结束但任务未完成时，放回当时对应队列的末尾。同一时刻先结束时间片并放回旧队列，再改变对应关系，最后由空闲 CPU 取任务。

输入先给 `n m T`，接着给 $m$ 个 CPU 的时间片长度，每个任务一行 `工作量 偏好CPU数 偏好CPU编号列表`。题目规模为 $n,m\le100$，任务工作量和 CPU 时间片均不超过 100，CPU 和任务编号均从 1 开始。

按任务顺序输出 $n$ 个答案，每个答案为该任务从第一次开始执行到最终完成的经过时间。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609C)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

**状态**

每条队列保存等待的任务编号，每个 CPU 保存正在执行的任务及时间片结束时刻，每个任务保存剩余工作量、首次开始时刻和答案。

**为什么逐毫秒模拟可行？**

总工作量 $W\le10000$。只要尚有任务未完成，就至少有一个 CPU 在执行或能立即从非空队列取任务；执行速度至少为 1，因此经过时间不超过 $W$。虽然 $T$ 可很大，也无需模拟到 $T$。

每个整数时刻依次做三件事：

1. 处理所有此时结束的时间片。任务完成则记录答案，未完成则放回旋转前对应的队列。

2. 用 `now/T` 得到旋转次数。CPU `i` 此时对应 `(i+now/T)%m` 号队列。

3. 空闲 CPU 从新对应队列取任务。速度为 `v` 时，本次持续时间为 `min(时间片,ceil(剩余工作量/v))`。

代码中 CPU 和队列从 0 编号，任务从 1 编号。开始时间片时先扣除预计完成的工作量，结束时再处理完成或重新入队；执行中的任务只保存在 CPU 状态中。

**边界**

时间片恰好在旋转时刻结束，放回队列要使用 `(now-1)/T` 对应的旧关系。偏好速度依据 CPU 实际编号判断，不随队列旋转。答案是完成时间减首次执行时间。

**正确性**

初始队列与题意相同，每个时刻又按规定顺序执行取队首、扣减工作量和队尾回插。由时间归纳，任务状态始终与真实过程一致，最终时间差即所求。

**复杂度**

时间 $O(mW+nm)$，空间 $O(nm+n+m)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,T,t[N],a[N],cur[N],ed[N],st[N],ans[N];
bool pre[N][N];
queue<int>q[N];
int main(){
    scanf("%d%d%d",&n,&m,&T);
    for(int i=0;i<m;++i){
        scanf("%d",&t[i]);
    }
    for(int i=1;i<=n;++i){
        int k,x;
        scanf("%d%d",&a[i],&k);
        while(k--){
            scanf("%d",&x);
            pre[i][x-1]=1;
        }
        q[(i-1)%m].push(i);
    }
    memset(st,-1,sizeof st);
    int cnt=0;
    for(int now=0;cnt<n;++now){
        for(int i=0;i<m;++i){
            int u=cur[i];
            if(!u || ed[i]!=now)continue;
            if(!a[u]){
                ans[u]=now-st[u];
                ++cnt;
            }
            else{
                q[(i+(now-1)/T)%m].push(u);
            }
            cur[i]=0;
        }
        for(int i=0;i<m;++i){
            int id=(i+now/T)%m;
            if(cur[i] || q[id].empty())continue;
            int u=q[id].front();
            q[id].pop();
            int v=pre[u][i]+1;
            int len=min(t[i],(a[u]+v-1)/v);
            if(st[u]==-1){
                st[u]=now;
            }
            a[u]=max(0,a[u]-len*v);
            cur[i]=u;
            ed[i]=now+len;
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 数字分组

标签：`图论` · `二分图` · `带权并查集` · `区间` · `构造`

本版验证：已通过 C++17 编译、600 组暴力染色对拍、22 个现有样例与测试点，均检查最优组数和划分合法性。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b053ca3e5d1fced2e44d560)。

原版评测记录：[历史记录 1](https://oj.shumeng.tech/record/6adce6e4a67df0b81749b40a)。

<!-- refactor-online:D:end -->

### 题意

把 $n$ 个互不相同的正整数划分为尽量少的组，每个数恰好出现一次。$op=0$ 时，同组不能出现满足 $x=ky$ 的两个数；$op=1$ 时，同组不能出现满足 $\lfloor x/y\rfloor=k$ 的两个数。

输入给出 `n k op`，随后是 $n$ 个互不相同的正整数。给定 $k\ge2$，规模 $n\le5\times10^5$，数值不超过 $10^{18}$。

输出最少组数，再对每组输出其大小与成员，允许任意最优合法划分。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609D)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

把每个数当成图的顶点，互相冲突的两数之间连边。分组就是给图染色，使每条边两端颜色不同，并最小化颜色数。

**先证明最多三色**

设 $L(x)=\lfloor\log_k x\rfloor$。冲突边取较大端 $x$、较小端 $y$，则 $k\le x/y<k+1\le k^2$，从而 $L(x)-L(y)$ 只可能为 1 或 2。因此按 `L(x)%3` 分组一定合法，实际计算用反复整数除以 $k$，无需浮点对数。

所以答案只有三种：无边时为 1，有边且为二分图时为 2，不是二分图时为 3。

**`op=0` 的边很少**

对每个 $x$，只需在 $k$ 整除 $x$ 时检查 $x/k$ 是否在输入中。每个顶点至多有一个更小的相邻点，图不会出现环，天然为二分图。排序、二分查找并加入异色约束即可。

**`op=1` 不能枚举所有边**

对固定的较大端 $x$，全部较小邻居满足：

$$\frac{x}{k+1}<y\le\frac{x}{k}.$$

排序后，这是连续下标区间 $[l,r]$。二染色要求整段邻居同色，且与 $x$ 异色，因此用带奇偶关系的并查集维护两类约束：`merge(a,b,0)` 同色，`merge(a,b,1)` 异色。

将邻居区间内相邻位置依次加入同色约束，再让 $x$ 与区间第一个点异色。为避免重复合并长区间，再用后继并查集：位置 $j$ 与 $j+1$ 的同色约束加入后，就永久跳过 $j$。每个相邻位置最多处理一次，总约束数为线性级别。

若所有约束不矛盾，输出并查集给出的两色；若发现矛盾，二色不可能，再用前述三色构造。无冲突边则所有点放在同一组。

**正确性**

一个点的邻居全同色且与它异色，等价于该点相连的全部边都满足二染色要求。相邻合并传递地约束整段，跳过的约束此前已成立，不会遗漏。

并查集准确判定约束是否相容，从而区分一色、二色与至少三色；三色构造又给出上界，故组数最优。

**复杂度**

排序及二分 $O(n\log n)$，并查集合并均摊 $O(n\alpha(n))$，空间 $O(n)$。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3;
int n,op,fa[N],sz[N],d[N],nxt[N];
ll k,a[N];
vector<ll>g[M];
int find(int x){
    if(fa[x]==x)return x;
    int y=fa[x];
    fa[x]=find(y);
    d[x]^=d[y];
    return fa[x];
}
int jump(int x){
    while(nxt[x]!=x){
        x=nxt[x]=nxt[nxt[x]];
    }
    return x;
}
bool merge(int x,int y,int w){
    int u=find(x),v=find(y);
    int z=d[x]^d[y]^w;
    if(u==v)return z==0;
    if(sz[u]<sz[v]){
        swap(u,v);
    }
    fa[v]=u;
    d[v]=z;
    sz[u]+=sz[v];
    return 1;
}
int main(){
    scanf("%d%lld%d",&n,&k,&op);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        fa[i]=nxt[i]=i;
        sz[i]=1;
    }
    nxt[n+1]=n+1;
    sort(a+1,a+n+1);
    bool edge=0,ok=1;
    for(int i=1;i<=n && ok;++i){
        int l,r;
        if(!op){
            if(a[i]%k)continue;
            l=lower_bound(a+1,a+n+1,a[i]/k)-a;
            if(l>n || a[l]!=a[i]/k)continue;
            r=l;
        }
        else{
            l=upper_bound(a+1,a+n+1,a[i]/(k+1))-a;
            r=upper_bound(a+1,a+n+1,a[i]/k)-a-1;
        }
        if(l>r)continue;
        edge=1;
        for(int j=jump(l);j<r;j=jump(j)){
            if(!merge(j,j+1,0)){
                ok=0;
                break;
            }
            nxt[j]=jump(j+1);
        }
        if(ok){
            ok=merge(i,l,1);
        }
    }
    int cnt;
    if(!edge)cnt=1;
    else if(ok)cnt=2;
    else cnt=3;
    for(int i=1;i<=n;++i){
        int col=0;
        if(cnt==2){
            find(i);
            col=d[i];
        }
        if(cnt==3){
            for(ll x=a[i];x>=k;x/=k){
                ++col;
            }
            col%=3;
        }
        g[col].push_back(a[i]);
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;++i){
        printf("%d",(int)g[i].size());
        for(ll &x:g[i]){
            printf(" %lld",x);
        }
        puts("");
    }
    return 0;
}
```

<a id="problem-e"></a>

## E. 奇

标签：`树` · `点分治` · `动态查询` · `位运算` · `哈希表`

本版验证：O2、UBSan 各通过 300 组独立随机对拍、44 组定向用例、20 个保存输入及十万点规模构造，详见 [验证记录](../tests/202609/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05d79ce5d1fced2e45d666)。

<!-- refactor-online:E:end -->

### 题意

树的每个点有固定颜色和可开关的灯，边有正整数权重。一个无序点对 $\{u,v\}$（允许 $u=v$）合格，需要两端灯都亮、路径边权和为 $k$ 的倍数，并且路径节点中恰有一种颜色出现奇数次。路径中间的点是否亮灯不影响颜色统计。

输入依次为 `n m k q`、长度为 $n$ 的灯状态 01 字符串、$n$ 个颜色、$n-1$ 条带权边和 $q$ 个待翻转点编号。规模为 $n,q\le10^5$、颜色数 $m\le40$、$k\le4$。点与颜色编号从 1 开始，边权不超过 $10^6$。

先输出初始答案，每次翻转一个点的灯后再次输出，共 $q+1$ 行。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202609E)；[公开复刻题面（独立编写）](https://github.com/Dejoy1202/csp-lab/blob/main/problem-packs/202609/statements.json)

### 题解

**先把“奇数次颜色”变为异或**

颜色 $c$ 对应第 $c-1$ 位的 1。沿路径异或各点的颜色位，所得掩码逐位表示颜色出现次数的奇偶性。“恰有一种奇数次颜色”等价于掩码中只有一个 1。

每次开关都重新统计点对过慢，因此使用点分治：找到连通块重心，删除重心后递归处理各子块。每个点只会经历 $O(\log n)$ 个重心。

**重心处存什么？**

对重心 $c$ 和点 $u$，记录：

- $S_{u,c}$：包含两端的路径颜色异或，对应记录中的 `S`；
- $D_{u,c}$：路径长度对 $k$ 的余数，对应记录中的 `dis`；
- $u$ 属于删除 $c$ 后的哪一个分支。

每个重心维护所有亮点的计数哈希表，并为每个分支另维护计数表，键由颜色掩码与距离余数组成。

**如何查询与 $u$ 合格的亮点数？**

若路径经过 $c$，两端掩码异或会把重心颜色抵消两次，所以实际路径掩码为：

$$S_{u,c}\oplus S_{v,c}\oplus bit(c).$$

枚举出现奇数次的颜色 $b$，另一个端点的掩码应为 $S_{u,c}\oplus bit(c)\oplus bit(b)$，距离余数应为 $(k-D_{u,c})\bmod k$。

查询重心总表，再减去 $u$ 所在分支的表，排除未经过该重心的路径。沿 $u$ 的全部重心祖先累加，即可得到它的全部合格伙伴数。

**开关怎么更新答案？**

- 原来灭灯：先查询已有亮点中的伙伴数，答案加上它，再额外加 1 计入 $\{u,u\}$，最后把 $u$ 加入全部相关计数表。
- 原来亮灯：先查询，此时结果已经包含自身，答案减去查询值，再从各表删除 $u$。

初始从全灭开始，依次加入初始亮灯节点，答案使用 `ll`。代码预先登记所有可能出现的哈希键，用连续数组开放寻址保存计数；开关时仅修改计数，避免反复分配节点。

哈希函数加入进程启动时由 `steady_clock` 取得的随机盐 `seed`，避免输入针对固定桶位置构造长探测链。盐在运行期间保持不变，插入和查询使用同一映射，冲突时仍比较完整键；因此只改变存储位置，不改变计数结果。

**为什么不重不漏？**

对两个不同端点，点分治中第一次把它们分开的重心，是唯一将该点对计入“总表减同分支表”的层。更高层被同分支减掉，更低层不会同时包含两端；自身点对仅在以自身为重心的层保留。

因此每个点对恰好计数一次，距离与掩码条件又准确表达了两项限制。

**复杂度**

预处理约 $O(n\log n)$，每次开关期望 $O(m\log n)$；含初始化，总时间期望 $O((n+q)m\log n)$，计数表和祖先记录空间 $O(n\log n)$。查询次数随颜色数线性增长。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=1e5+10;
const ull seed=chrono::steady_clock::now().time_since_epoch().count();
int n,m,k,q,tot,fa[N],sz[N],ord[N],dis[N];
ll bit[N],S[N],ans;
bool vis[N];
char s[N];
vector<P>g[N];
struct node{
    ll S;
    int rt,id,dis;
};
vector<node>rec[N];
struct Hash{
    int S;
    vector<ll>key;
    vector<int>val;
    void init(int n){
        int s=2;
        while(s<n*2){
            s<<=1;
        }
        S=s-1;
        key.assign(s,-1);
        val.assign(s,0);
    }
    int pos(ll x){
        ull h=x+seed+0x9e3779b97f4a7c15ull;
        h=(h^(h>>30))*0xbf58476d1ce4e5b9ull;
        h=(h^(h>>27))*0x94d049bb133111ebull;
        int p=(h^(h>>31))&S;
        while(key[p]!=-1 && key[p]!=x){
            p=(p+1)&S;
        }
        return p;
    }
    void ins(ll x){
        key[pos(x)]=x;
    }
    void add(ll x,int v){
        val[pos(x)]+=v;
    }
    int get(ll x){
        int p=pos(x);
        return key[p]==x?val[p]:0;
    }
}all[N],sub[N];
int getrt(int s){
    int cnt=1;
    ord[1]=s;
    fa[s]=0;
    for(int i=1;i<=cnt;++i){
        int u=ord[i];
        sz[u]=1;
        for(auto &[v,w]:g[u]){
            if(vis[v] || v==fa[u])continue;
            fa[v]=u;
            ord[++cnt]=v;
        }
    }
    int rt=s,mn=cnt;
    for(int i=cnt;i;--i){
        int u=ord[i],mx=cnt-sz[u];
        for(auto &[v,w]:g[u]){
            if(!vis[v] && fa[v]==u){
                mx=max(mx,sz[v]);
            }
        }
        if(mx<mn){
            mn=mx;
            rt=u;
        }
        if(fa[u]){
            sz[fa[u]]+=sz[u];
        }
    }
    return rt;
}
void solve(int u){
    int rt=getrt(u);
    vis[rt]=1;
    all[rt].init(sz[u]);
    all[rt].ins(bit[rt]<<2);
    rec[rt].push_back({bit[rt],rt,0,0});
    for(auto &[v,w]:g[rt]){
        if(vis[v])continue;
        int id=++tot,cnt=1;
        ord[1]=v;
        fa[v]=rt;
        dis[v]=w%k;
        S[v]=bit[rt]^bit[v];
        for(int i=1;i<=cnt;++i){
            int x=ord[i];
            for(auto &[y,z]:g[x]){
                if(vis[y] || y==fa[x])continue;
                fa[y]=x;
                ord[++cnt]=y;
                dis[y]=(dis[x]+z)%k;
                S[y]=S[x]^bit[y];
            }
        }
        sub[id].init(cnt);
        for(int i=1;i<=cnt;++i){
            int x=ord[i];
            ll key=(S[x]<<2)|dis[x];
            rec[x].push_back({S[x],rt,id,dis[x]});
            all[rt].ins(key);
            sub[id].ins(key);
        }
    }
    for(auto &[v,w]:g[rt]){
        if(!vis[v]){
            solve(v);
        }
    }
}
ll ask(int u){
    ll res=0;
    for(auto &x:rec[u]){
        ll base=x.S^bit[x.rt];
        int d=(k-x.dis)%k;
        for(int i=0;i<m;++i){
            ll key=((base^(1ll<<i))<<2)|d;
            res+=all[x.rt].get(key);
            if(x.id){
                res-=sub[x.id].get(key);
            }
        }
    }
    return res;
}
void add(int u,int v){
    for(auto &x:rec[u]){
        ll key=(x.S<<2)|x.dis;
        all[x.rt].add(key,v);
        if(x.id){
            sub[x.id].add(key,v);
        }
    }
}
int main(){
    scanf("%d%d%d%d%s",&n,&m,&k,&q,s+1);
    for(int i=1;i<=n;++i){
        int c;
        scanf("%d",&c);
        bit[i]=1ll<<(c-1);
    }
    for(int i=1;i<n;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(P(v,w));
        g[v].push_back(P(u,w));
    }
    solve(1);
    for(int i=1;i<=n;++i){
        if(s[i]=='1'){
            ans+=ask(i)+1;
            add(i,1);
        }
    }
    printf("%lld\n",ans);
    while(q--){
        int u;
        scanf("%d",&u);
        if(s[u]=='1'){
            ans-=ask(u);
            add(u,-1);
        }
        else{
            ans+=ask(u)+1;
            add(u,1);
        }
        s[u]^=1;
        printf("%lld\n",ans);
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202609/VALIDATION.md)
- [bd-final-report.json](../tests/202609/bd-final-report.json)
- [current-hash-gnu-revalidation.json](../tests/202609/current-hash-gnu-revalidation.json)
- [e-mask-followup-report.json](../tests/202609/e-mask-followup-report.json)
- [online-update-report.json](../tests/202609/online-update-report.json)
- [online-verdicts.json](../tests/202609/online-verdicts.json)
- [optimization-20261125/collision-report.json](../tests/202609/optimization-20261125/collision-report.json)
- [optimization-20261125/submission.json](../tests/202609/optimization-20261125/submission.json)
- [optimization-20261125/verification.json](../tests/202609/optimization-20261125/verification.json)
- [performance-attempt/202609E/E.cpp](../tests/202609/performance-attempt/202609E/E.cpp)
- [performance-attempt/202609E/attempt.json](../tests/202609/performance-attempt/202609E/attempt.json)
- [previous-versions.md](../tests/202609/previous-versions.md)
- [prior-record-observation.json](../tests/202609/prior-record-observation.json)
- [random-salt-validation.json](../tests/202609/random-salt-validation.json)
- [verify-bd-final.py](../tests/202609/verify-bd-final.py)

<!-- local-validation-attachments:end -->
