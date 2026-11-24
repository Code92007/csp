---
title: "CSP 202309 五题题解"
contest: "202309"
contest_month: "2023-09"
date: "2026-10-23"
updated: "2026-11-24"
tags: ["CSP", "累加", "平移变换", "前缀积", "前缀和", "旋转变换", "自动微分", "表达式", "栈", "有序集合", "几何", "模拟", "动态树", "树的直径", "动态规划"]
status: "published"
problems: [{"id": "A", "title": "坐标变换（其一）", "tags": ["累加", "平移变换"], "status": "implemented", "code": "A.cpp", "anchor": "problem-a", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309A"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16054"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0560b9e5d1fced2e45143c", "source_sha256": "e0e1026922b26c7a030358b3cf15b0130c67af36cf22171d01e2390d43cf1953", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:03:04.039086+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305812891", "source_sha256": "0279d6eff2d720df137c232c32f82dd060f4a83ca77eda7cd91d28fbf406eef0"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8c8a67df0b81749bdf6"}}, {"id": "B", "title": "坐标变换（其二）", "tags": ["前缀积", "前缀和", "旋转变换"], "status": "implemented", "code": "B.cpp", "anchor": "problem-b", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309B"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16055"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b05612de5d1fced2e4514dc", "source_sha256": "9892d789c821e38057d82f9427f61f2133b793936a35faacaa04213d9d5b9cab", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:05:05.776847+00:00"}, "previous_luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490746", "code_git_blob": "20776d0627c78f6c02502fc311a5648a5f01a3cb", "note": "上一版代码记录；本版新增高低角度前缀精度修复，以曙梦复验为准"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305835741", "source_sha256": "6a128e8d781e9fde0cb77ad2fa22862e21d8b03b9afeb979f5fad8c2c84f0bfc"}, "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addb80574ace1cba9a20d52"}}, {"id": "C", "title": "梯度求解", "tags": ["自动微分", "表达式", "栈"], "status": "implemented", "code": "C.cpp", "anchor": "problem-c", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309C"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16056"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b056192e5d1fced2e451598", "source_sha256": "12d1b3aa35786a9ab6557c570f472a8a8bb804071caf1d60dadc6a5f96590e3c", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:06:37.944298+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305836471", "source_sha256": "4f46c6f4886a14d0390fc781dfbf15d9ce6abc98426c177a272efd4e7ec99fb2"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8cca67df0b81749be25"}}, {"id": "D", "title": "阴阳龙", "tags": ["有序集合", "几何", "模拟"], "status": "implemented", "code": "D.cpp", "anchor": "problem-d", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309D"}, {"label": "公开题面存档", "url": "https://www.luogu.com.cn/problem/P16057"}], "previous_oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addfd5374ace1cba9a2324b", "source_sha256": "746784b9f38218ef1ad4b9f61f94c36aa4d8fa809310df1fee29028a4b61e83a", "note": "上一版快版的评测记录；当前宽坐标源码已单独在两平台复验。"}, "previous_luogu": {"status": "failed", "score": 30, "verdict": "Unaccepted (Wrong Answer on 14/20 tests)", "record": "https://www.luogu.com.cn/record/305837114", "source_sha256": "746784b9f38218ef1ad4b9f61f94c36aa4d8fa809310df1fee29028a4b61e83a", "note": "上一版快版的评测记录；当前宽坐标源码已单独在两平台复验。"}, "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b0561ffe5d1fced2e4515db", "source_sha256": "ab83002cedddbfbdb3f37dcaf4ff25caa17c8398a75ef169eb4b2434f1d35b85", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:08:23.080094+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305916165", "source_sha256": "7582da8d38df5972c56e08c065b30d2add892ced43ea695e431a262a65f8b815"}, "validation_history": [{"source_sha256": "746784b9f38218ef1ad4b9f61f94c36aa4d8fa809310df1fee29028a4b61e83a", "oj": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6addfd5374ace1cba9a2324b", "source_sha256": "746784b9f38218ef1ad4b9f61f94c36aa4d8fa809310df1fee29028a4b61e83a"}, "luogu": {"status": "failed", "score": 30, "verdict": "Unaccepted (Wrong Answer on 14/20 tests)", "record": "https://www.luogu.com.cn/record/305837114", "source_sha256": "746784b9f38218ef1ad4b9f61f94c36aa4d8fa809310df1fee29028a4b61e83a"}, "note": "旧快版：曙梦100分、洛谷30分。失败的具体根因尚未定位。"}, {"source_sha256": "cf65f5b624668a7c99fc6d7e9412abbd41af73b15b9ba405bf15aad1eb59f553", "oj": {"status": "failed", "score": 15, "verdict": "Time Exceeded", "record": "https://oj.shumeng.tech/record/6addca8774ace1cba9a21e22", "source_sha256": "cf65f5b624668a7c99fc6d7e9412abbd41af73b15b9ba405bf15aad1eb59f553", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}, "luogu": {"status": "accepted", "score": 100, "record": "https://www.luogu.com.cn/record/305490899", "source_sha256": "cf65f5b624668a7c99fc6d7e9412abbd41af73b15b9ba405bf15aad1eb59f553", "note": "上一版源码的评测记录；当前版本已更换实现，成绩单独核验。"}}], "oj_before_refactor": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6ade253b74ace1cba9a24563", "source_sha256": "7582da8d38df5972c56e08c065b30d2add892ced43ea695e431a262a65f8b815"}}, {"id": "E", "title": "阻击", "tags": ["动态树", "树的直径", "动态规划"], "status": "implemented", "code": "E.cpp", "anchor": "problem-e", "validation": "重构版评测：100 分 Accepted（C++20/O2）。原版记录保留；本地验证见 VALIDATION.md。", "sources": [{"label": "曙梦 OJ 原题（可提交）", "url": "https://oj.shumeng.tech/p/CSP202309E"}, {"label": "公开题面与样例", "url": "https://www.luogu.com.cn/problem/P16058"}], "oj": {"score": 100.0, "verdict": "Accepted", "record": "https://oj.shumeng.tech/record/6b056263e5d1fced2e4516b8", "source_sha256": "f354d1795cf5471e77d4553bf89a2aa7bce5c9e125399be5ee5539321d6bd40e", "language_id": "cc.cc20o2", "language": "C++20/O2", "status": "accepted", "observed_at": "2026-11-24T10:10:06.441488+00:00"}, "luogu": {"status": "accepted", "score": 100, "verdict": "Accepted", "record": "https://www.luogu.com.cn/record/305838452", "source_sha256": "390e1e27f14b0e1b2b7b4a87d6d843c5179d50d32ff03fdf9fa9608b41359b8a"}, "oj_before_refactor": {"status": "accepted", "score": 100, "record": "https://oj.shumeng.tech/record/6adce8cfa67df0b81749be4d"}}]
---

# CSP 202309 五题题解

[原页面](https://code92007.github.io/csp/#/contest/202309) · [验证记录](../tests/202309/VALIDATION.md) · [返回总目录](../README.md)

<a id="problem-a"></a>

## A. 坐标变换（其一）

标签：`累加` · `平移变换`

本地：61 组优化版、61 组 UBSan 验证通过，详见 [验证记录](../tests/202309/VALIDATION.md)。

<!-- refactor-online:A:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0560b9e5d1fced2e45143c)。

<!-- refactor-online:A:end -->

### 题意

给出 $n$ 次平移操作，将同一组操作依次作用于 $m$ 个初始点，求每个点的最终坐标。

输入先给出 $n,m$，随后 $n$ 行为位移 $dx_i,dy_i$，最后 $m$ 行为初始坐标。满足 $n,m\le100$，所有坐标和位移均为绝对值不超过 $10^5$ 的整数。

按输入顺序逐行输出变换后的两个坐标。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309A)；[公开题面存档](https://www.luogu.com.cn/problem/P16054)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce8c8a67df0b81749bdf6)（accepted，100 分；复刻评测）。

### 题解

**合并平移**

先分别累计横、纵方向的总位移，再给每个初始点加上这两个总量。

**正确性**

平移仅对两个坐标分别做加法。由加法结合律，逐次平移等价于一次加上全部位移之和。

**复杂度**

时间 $O(n+m)$，额外空间 $O(1)$。

### 代码

独立源码：[A.cpp](A.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll dx,dy,x,y;
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%lld%lld",&x,&y);
        dx+=x,dy+=y;
    }
    while(m--){
        scanf("%lld%lld",&x,&y);
        printf("%lld %lld\n",x+dx,y+dy);
    }
    return 0;
}
```

<a id="problem-b"></a>

## B. 坐标变换（其二）

标签：`前缀积` · `前缀和` · `旋转变换`

本地：612 组优化版、612 组 UBSan 验证通过，详见 [验证记录](../tests/202309/VALIDATION.md)。

<!-- refactor-online:B:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b05612de5d1fced2e4514dc)。

<!-- refactor-online:B:end -->

### 题意

有一串围绕原点的等比例缩放和逆时针旋转。每个查询给出操作区间及一个初始点，求依次执行区间内操作后的坐标。

输入先给出 $n,m$，随后为 $n$ 个操作和 $m$ 个查询。满足 $n,m\le10^5$，初始坐标为绝对值不超过 $10^6$ 的整数；单次缩放系数在 $[0.5,2]$，任意区间内缩放系数的乘积在 $[0.001,1000]$。

- `1 k`：两个坐标同时乘 $k$。
- `2 θ`：绕原点逆时针旋转 $\theta$ 弧度，$0\le\theta<2\pi$。
- 查询 `l r x y`：将第 $l$ 至第 $r$ 个操作作用于 $(x,y)$。

每个查询输出两个实数，绝对误差不超过 $0.1$。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309B)；[公开题面存档](https://www.luogu.com.cn/problem/P16055)。

原版评测：[记录](https://oj.shumeng.tech/record/6addb80574ace1cba9a20d52)（accepted，100 分；复刻评测）。

### 题解

**合并缩放与旋转**

等比例缩放与绕原点旋转可以交换顺序。设区间内缩放系数乘积为 $k$、旋转角度和为 $\theta$，则

$$x'=k(x\cos\theta-y\sin\theta),\qquad y'=k(x\sin\theta+y\cos\theta).$$

缩放前缀积相除、角度前缀和相减，就能在常数时间提取任意操作区间。

**保留大前缀中的低位误差**

角度可能保留很多小数位，不能先乘固定倍数取整。连续累加后，两个较大前缀相减也可能丢失有效低位；误差再被坐标与缩放倍数放大，就可能超过要求。

每个角度前缀用 `hi,lo` 两部分保存。加入角度时，`hi` 接收常规加法结果，`lo` 通过补偿公式累积该次加法舍去的低位。区间相减时也恢复减法误差，得到高位 $d$ 和残差 $e$。

不要立刻把两部分加回一个数，而是分别求三角函数，再用角度和公式合成：

$$\cos(d+e)=\cos d\cos e-\sin d\sin e,$$
$$\sin(d+e)=\sin d\cos e+\cos d\sin e.$$

也无需用近似 $2\pi$ 常量手工对大角度取模，避免额外放大周期常量的误差。

**正确性**

缩放系数相乘，旋转角度相加，前缀运算准确对应所选区间的数学变换。补偿表示和角度和公式仅改变数值计算方式，因此仍表示同一缩放与旋转。实际误差由独立高精度回归检查，详见验证记录。

**复杂度**

预处理 $O(n)$，每个查询 $O(1)$，总时间 $O(n+m)$，空间 $O(n)$。

### 代码

独立源码：[B.cpp](B.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1e5+10;
int n,m;
ld k[N];
struct angle{
    ld hi=0,lo=0;
    void add(ld x){
        ld y=hi+x;
        if(fabsl(hi)>=fabsl(x))lo+=(hi-y)+x;
        else lo+=(x-y)+hi;
        hi=y;
    }
}a[N];
int main(){
    scanf("%d%d",&n,&m);
    k[0]=1;
    for(int i=1;i<=n;++i){
        int op;
        ld x;
        scanf("%d%Lf",&op,&x);
        k[i]=k[i-1];
        a[i]=a[i-1];
        if(op==1)k[i]*=x;
        else a[i].add(x);
    }
    while(m--){
        int l,r;
        ld x,y;
        scanf("%d%d%Lf%Lf",&l,&r,&x,&y);
        ld u=a[r].hi,v=a[l-1].hi;
        ld d=u-v,b=u-d;
        ld e=(u-(d+b))+(b-v);
        e+=a[r].lo-a[l-1].lo;
        ld c=cosl(d),s=sinl(d);
        ld p=cosl(e),q=sinl(e);
        ld co=c*p-s*q,si=s*p+c*q;
        ld w=k[r]/k[l-1];
        ld rx=w*(x*co-y*si),ry=w*(x*si+y*co);
        printf("%.10Lf %.10Lf\n",rx,ry);
    }
    return 0;
}
```

<a id="problem-c"></a>

## C. 梯度求解

标签：`自动微分` · `表达式` · `栈`

本地：102 组优化版、102 组 UBSan 验证通过，详见 [验证记录](../tests/202309/VALIDATION.md)。

<!-- refactor-online:C:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b056192e5d1fced2e451598)。

<!-- refactor-online:C:end -->

### 题意

给出由整数、变量 $x_1,\ldots,x_n$ 和加减乘组成的后缀表达式。每次查询指定一个变量和一组赋值，求表达式对该变量在该点的偏导数。

输入先给出 $n,m$，第二行为表达式，之后每行给出求导变量编号和全部变量值。满足 $n,m\le100$，表达式不超过 $120$ 个元素，整常数和赋值均在 $[-10^5,10^5]$ 内，表达式合法。

每次输出偏导数对 $10^9+7$ 取模后的非负余数。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309C)；[公开题面存档](https://www.luogu.com.cn/problem/P16056)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce8cca67df0b81749be25)（accepted，100 分；复刻评测）。

### 题解

**求值与求导同时进行**

栈中每项保存二元组 $(v,d)$，分别表示子表达式的值和对当前变量的导数。常数导数为 $0$；当前求导变量的导数为 $1$，其他变量为 $0$。

遇到运算符时，先弹出右操作数，再弹出左操作数。加减法对两个分量分别计算；乘法使用

$$(u,u')\times(v,v')=(uv,u'v+uv').$$

每一步都取模，负数与减法结果规范为非负余数。

**正确性**

后缀表达式的运算符出现时，两个子表达式都已计算完毕。对表达式树归纳，求值规则和求导公式保证栈中二元组始终正确，因此最后唯一一项的导数就是答案。

**复杂度**

设表达式长度为 $L$，每次查询时间 $O(n+L)$，空间 $O(n+L)$。

### 代码

独立源码：[C.cpp](C.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=110,M=1e5+10,mod=1e9+7;
int n,m;
ll a[N];
char s[M];
vector<string>v;
ll norm(ll x){
    return (x%mod+mod)%mod;
}
int main(){
    scanf("%d%d",&n,&m);
    int c;
    while((c=getchar())!='\n' && c!=EOF){
    }
    fgets(s,M,stdin);
    istringstream in(s);
    string t;
    while(in>>t){
        v.push_back(t);
    }
    while(m--){
        int id;
        scanf("%d",&id);
        for(int i=1;i<=n;++i){
            scanf("%lld",&a[i]);
            a[i]=norm(a[i]);
        }
        vector<P>st;
        for(string &s:v){
            if(s=="+" || s=="-" || s=="*"){
                auto [y,dy]=st.back();
                st.pop_back();
                auto [x,dx]=st.back();
                st.pop_back();
                if(s=="+")st.push_back({(x+y)%mod,(dx+dy)%mod});
                else if(s=="-")st.push_back({norm(x-y),norm(dx-dy)});
                else st.push_back({x*y%mod,(dx*y+x*dy)%mod});
            }
            else if(s[0]=='x'){
                int k=stoi(s.substr(1));
                st.push_back({a[k],k==id});
            }
            else st.push_back({norm(stoll(s)),0});
        }
        printf("%lld\n",st.back().second);
    }
    return 0;
}
```

<a id="problem-d"></a>

## D. 阴阳龙

标签：`有序集合` · `几何` · `模拟`

本地：1082 组优化版、1082 组 UBSan 验证通过，详见 [验证记录](../tests/202309/VALIDATION.md)。

<!-- refactor-online:D:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b0561ffe5d1fced2e4515db)。

原版评测记录：[历史记录 1](https://oj.shumeng.tech/record/6addfd5374ace1cba9a2324b)。

<!-- refactor-online:D:end -->

### 题意

在 $n\times m$ 网格上有 $p$ 名位置互异的员工。事件 $(u,v,t)$ 从中心沿八个方向寻找最近员工，不包括中心员工；设最近距离为 $k$，若八个方向走 $k$ 步不能全部留在网格内，则本次不动。否则，将八个方向上恰好相距 $k$ 的员工同时逆时针轮转 $t$ 个方向。

输入先给出 $n,m,p,q$，再给出各员工的初始坐标和 $q$ 次事件。满足 $1\le n,m\le10^9$、$1\le p,q\le10^5$、$1\le t\le7$，所有输入位置均在网格内。水平和竖直距离按步数计算，斜向距离按横坐标差计算。

处理完事件后，输出 $\bigoplus_{i=1}^p(i x_i+y_i)$。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309D)；[公开题面存档](https://www.luogu.com.cn/problem/P16057)。

原版评测：[记录](https://oj.shumeng.tech/record/6ade253b74ace1cba9a24563)（accepted，100 分；复刻评测）。

### 题解

**四个有序集合查询八条射线**

八个方向组成水平、竖直及两条对角线。分别维护四个 `set`，排序键如下：

| 直线 | 排序键 | 第二项增大的方向 |
| --- | --- | --- |
| 水平 | $(y,x)$ | 右 |
| 竖直 | $(x,y)$ | 上 |
| 斜率 $1$ | $(x-y,x)$ | 右上 |
| 斜率 $-1$ | $(x+y,x)$ | 右下 |

每个集合先按直线编号分组，再按线上位置排序。同线严格前驱和后继分别对应两个方向最近的人；中心员工要排除，查到其他直线的记录也要排除。

八个方向都不会越界的最大距离为

$$b=\min(u-1,n-u,v-1,m-v).$$

取全部候选的最小距离，若大于 $b$ 则不动；否则只移动距离等于这个最小值的员工。

**把占用位置与员工身份分开**

每个占用位置用一个槽位保存坐标、员工编号以及四个集合的迭代器。先完整记录每个目标方向应接收的员工，再统一修改，避免破坏同时轮转的含义。

轮转前后都被占用的位置，只需更换员工编号。只有从有人变为空位的位置需要搬走槽位，再用于从空位变为有人的位置。

设前后的占用方向集合为 $A,B$，且 $|A|=|B|=s$。需要搬动的槽位数满足

$$|A\setminus B|\le\min(s,8-s)\le4.$$

两侧差集数量相等，可以逐一配对。搬动时用 C++17 的节点句柄取出四个 `set` 节点，修改排序键后再插回，复用其存储。所有待搬节点先统一取出，再统一插入。

**正确性**

同线前驱和后继完整给出八个方向的最近候选，再结合边界就能确定全部参与员工。方向映射 $d\mapsto(d+t)\bmod8$ 是双射；目标位置若原来有人，该人也必然参加这次轮转，因此不会撞上未参与员工。

先保存目标身份，再更新重合位置和两个差集，恰好完成同时轮转；四个索引始终对应当前占用位置。最终按槽位保存的员工编号计算异或，而不是按槽位编号计算。

**复杂度**

初始化 $O(p\log p)$，每次事件 $O(\log p)$，总时间 $O((p+q)\log p)$，空间 $O(p)$。坐标、直线编号和最终乘法使用 64 位整数。

### 代码

独立源码：[D.cpp](D.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=1e5+10,M=4,K=8;
const int dx[K]={1,1,0,-1,-1,-1,0,1};
const int dy[K]={0,1,1,1,0,-1,-1,-1};
const int to[M]={0,2,1,7};
ll n,m;
int p,q;
struct entry{
    P k;
    int id;
    bool operator<(const entry &x)const{
        return k<x.k;
    }
};
typedef set<entry> S;
struct slot{
    ll x,y;
    int id;
    S::iterator at[M];
}a[N];
S g[M];
array<P,M> keys(ll x,ll y){
    return {P(y,x),P(x,y),P(x-y,x),P(x+y,x)};
}
int main(){
    scanf("%lld%lld%d%d",&n,&m,&p,&q);
    for(int i=1;i<=p;++i){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].id=i;
        auto k=keys(a[i].x,a[i].y);
        for(int j=0;j<M;++j){
            a[i].at[j]=g[j].insert({k[j],i}).first;
        }
    }
    while(q--){
        ll u,v;
        int t;
        scanf("%lld%lld%d",&u,&v,&t);
        ll b=min({u-1,n-u,v-1,m-v});
        if(!b)continue;
        ll len=b+1,d[K];
        int near[K];
        memset(d,0,sizeof d);
        memset(near,0,sizeof near);
        auto k=keys(u,v);
        for(int j=0;j<M;++j){
            auto it=g[j].upper_bound({k[j],0});
            auto check=[&](S::iterator it,int dir){
                if(it->k.first!=k[j].first)return;
                ll dis=abs(it->k.second-k[j].second);
                near[dir]=it->id;
                d[dir]=dis;
                len=min(len,dis);
            };
            if(it!=g[j].end())check(it,to[j]);
            if(it!=g[j].begin()){
                auto pre=prev(it);
                if(pre->k==k[j]){
                    if(pre==g[j].begin())continue;
                    --pre;
                }
                check(pre,(to[j]+4)&7);
            }
        }
        if(len>b)continue;
        int old[K],nxt[K];
        memset(old,0,sizeof old);
        memset(nxt,0,sizeof nxt);
        for(int i=0;i<K;++i){
            if(near[i] && d[i]==len){
                old[i]=near[i];
                nxt[(i+t)&7]=a[near[i]].id;
            }
        }
        int src[M],dst[M],cnt=0,tot=0;
        for(int i=0;i<K;++i){
            if(old[i] && nxt[i])a[old[i]].id=nxt[i];
            else if(old[i])src[cnt++]=old[i];
            else if(nxt[i])dst[tot++]=i;
        }
        S::node_type h[M][M];
        for(int i=0;i<cnt;++i){
            for(int j=0;j<M;++j){
                h[i][j]=g[j].extract(a[src[i]].at[j]);
            }
        }
        for(int i=0;i<cnt;++i){
            int id=src[i],d=dst[i];
            a[id].x=u+len*dx[d];
            a[id].y=v+len*dy[d];
            a[id].id=nxt[d];
            auto k=keys(a[id].x,a[id].y);
            for(int j=0;j<M;++j){
                h[i][j].value().k=k[j];
                a[id].at[j]=g[j].insert(std::move(h[i][j])).position;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=p;++i){
        ans^=a[i].id*a[i].x+a[i].y;
    }
    printf("%lld\n",ans);
    return 0;
}
```

<a id="problem-e"></a>

## E. 阻击

标签：`动态树` · `树的直径` · `动态规划`

本地：83 组优化版、83 组 UBSan 验证通过，详见 [验证记录](../tests/202309/VALIDATION.md)。

<!-- refactor-online:E:start -->

重构版评测：100 分 Accepted（C++20/O2） [真实记录](https://oj.shumeng.tech/record/6b056263e5d1fced2e4516b8)。

<!-- refactor-online:E:end -->

### 题意

一棵树的每条边有宝物收益 $w_e$ 和阻击损失 $b_e$。选择两个城市，允许相同，沿它们之间的简单路径行动，总损失为 $\sum(b_e-w_e)$；每次修改指定边的 $w_e$，维护最大的总损失。

输入先给出 $n,m$，随后 $n-1$ 行为 `u v w b`，最后 $m$ 行为边编号和新的 $w$。满足 $2\le n\le10^5$、$0\le m\le10^5$，各项权值在 $[0,10^9]$ 内，边编号从 $1$ 开始。

输出初始答案和每次修改后的答案，共 $m+1$ 行。

来源：[曙梦 OJ 原题（可提交）](https://oj.shumeng.tech/p/CSP202309E)；[公开题面与样例](https://www.luogu.com.cn/problem/P16058)。

原版评测：[记录](https://oj.shumeng.tech/record/6adce8cfa67df0b81749be4d)（accepted，100 分；复刻评测）。

### 题解

**允许负权的动态直径**

令边权 $c_e=b_e-w_e$，问题就是动态维护最大路径和。边权可能为负，不能套用正权树两次寻找最远点的方法。

把每条边拆成一个权值为 $c_e$ 的新点，原城市点权为 $0$，边修改就变成点修改。拆边点度数为 $2$，路径若结束在这里，可延伸到相邻的零权城市而不降低权值，因此最大点权路径与原问题等价。

**实链上的路径信息**

使用 Link-Cut Tree。每段实链记录 `sum,l,r,ans`：实链点权和、从左端出发的最大路径、从右端出发的最大路径、整个结构的最大路径。

相邻段 $A,B$ 合并时，

$$sum=sum_A+sum_B,$$
$$l=\max(l_A,sum_A+l_B),\qquad r=\max(r_B,sum_B+r_A),$$
$$ans=\max(ans_A,ans_B,r_A+l_B).$$

端点路径允许进入一棵虚子树，`sum` 则只包含实链点权。

**虚子树贡献**

每个点用两个多重集合保存虚孩子的端点路径和内部最优路径。设最大的两个非负分支为 $x,y$，点权为 $w$，局部状态为

$$(w,w+x,w+x,\max(\text{虚子树最优路径},w+x+y)).$$

`access` 时，把原实右子树加入虚集合，把新实右子树移出。删除相同贡献时只删一次出现，不能删除全部同值项。修改点权前先 `access`，使祖先仍能移除旧贡献。

**正确性**

一条最优路径要么完全在某个分支内部，要么经过连接点并使用至多两个分支，局部状态覆盖这两类情况。实链合并时，路径要么在一侧，要么由左段右端路径与右段左端路径连接，合并式也完整覆盖全部可能。

动态树维护这些状态后，整树的 `ans` 就是最大路径和，再与 $0$ 取最大值即可包括起终点相同的选择。

**复杂度**

多重集合使每次修改摊还 $O(\log^2n)$，初始化 $O(n\log^2n)$，空间 $O(n)$。

### 代码

独立源码：[E.cpp](E.cpp)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=2;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll b[N];
struct info{
    ll sum=0,l=-INF,r=-INF,ans=-INF;
};
info merge(info a,info b){
    info c;
    c.sum=a.sum+b.sum;
    c.l=max(a.l,a.sum+b.l);
    c.r=max(b.r,b.sum+a.r);
    c.ans=max({a.ans,b.ans,a.r+b.l});
    return c;
}
struct LCT{
    struct node{
        int ch[M],fa;
        bool rev;
        ll w;
        multiset<ll>f,g;
        info v;
    }e[N];
    int st[N];
    bool isroot(int u){
        int p=e[u].fa;
        return e[p].ch[0]!=u && e[p].ch[1]!=u;
    }
    info local(int u){
        ll x=0,y=0;
        auto it=e[u].f.rbegin();
        if(it!=e[u].f.rend()){
            x=max(0ll,*it);
            ++it;
        }
        if(it!=e[u].f.rend())y=max(0ll,*it);
        ll w=e[u].w;
        ll ans=e[u].g.empty()?-INF:*e[u].g.rbegin();
        return {w,w+x,w+x,max(ans,w+x+y)};
    }
    void pushup(int u){
        e[u].v=merge(merge(e[e[u].ch[0]].v,local(u)),e[e[u].ch[1]].v);
    }
    void flip(int u){
        if(!u)return;
        swap(e[u].ch[0],e[u].ch[1]);
        swap(e[u].v.l,e[u].v.r);
        e[u].rev^=1;
    }
    void pushdown(int u){
        if(e[u].rev){
            flip(e[u].ch[0]);
            flip(e[u].ch[1]);
            e[u].rev=0;
        }
    }
    void rotate(int u){
        int p=e[u].fa,g=e[p].fa;
        int d=e[p].ch[1]==u,v=e[u].ch[d^1];
        if(!isroot(p))e[g].ch[e[g].ch[1]==p]=u;
        e[u].fa=g;
        e[u].ch[d^1]=p;
        e[p].fa=u;
        e[p].ch[d]=v;
        if(v)e[v].fa=p;
        pushup(p);
        pushup(u);
    }
    void splay(int u){
        int cnt=0,v=u;
        st[++cnt]=v;
        while(!isroot(v)){
            v=e[v].fa;
            st[++cnt]=v;
        }
        while(cnt){
            pushdown(st[cnt--]);
        }
        while(!isroot(u)){
            int p=e[u].fa,g=e[p].fa;
            if(!isroot(p)){
                bool same=((e[p].ch[1]==u)==(e[g].ch[1]==p));
                rotate(same?p:u);
            }
            rotate(u);
        }
    }
    void add(int u,int v){
        if(!v)return;
        e[u].f.insert(e[v].v.l);
        e[u].g.insert(e[v].v.ans);
    }
    void del(int u,int v){
        if(!v)return;
        e[u].f.erase(e[u].f.find(e[v].v.l));
        auto it=e[u].g.find(e[v].v.ans);
        e[u].g.erase(it);
    }
    void access(int u){
        int v=0,x=u;
        while(x){
            splay(x);
            add(x,e[x].ch[1]);
            del(x,v);
            e[x].ch[1]=v;
            pushup(x);
            v=x;
            x=e[x].fa;
        }
        splay(u);
    }
    void makeroot(int u){
        access(u);
        flip(u);
    }
    void link(int u,int v){
        makeroot(u);
        access(v);
        e[u].fa=v;
        add(v,u);
        pushup(v);
    }
    void update(int u,ll x){
        access(u);
        e[u].w=x;
        pushup(u);
    }
    ll query(int u){
        makeroot(1);
        access(u);
        return local(u).ans;
    }
}tr;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        tr.pushup(i);
    }
    for(int i=1;i<n;++i){
        int u,v;
        ll w;
        scanf("%d%d%lld%lld",&u,&v,&w,&b[i]);
        int p=n+i;
        tr.e[p].w=b[i]-w;
        tr.pushup(p);
        tr.link(u,p);
        tr.link(p,v);
    }
    printf("%lld\n",max(0ll,tr.query(1)));
    while(m--){
        int id;
        ll x;
        scanf("%d%lld",&id,&x);
        tr.update(n+id,b[id]-x);
        printf("%lld\n",max(0ll,tr.query(1)));
    }
    return 0;
}
```

<!-- local-validation-attachments:start -->

### 验证附件

- [VALIDATION.md](../tests/202309/VALIDATION.md)
- [cases.json](../tests/202309/cases.json)
- [compile.json](../tests/202309/compile.json)
- [constants-followup.json](../tests/202309/constants-followup.json)
- [current-sources.json](../tests/202309/current-sources.json)
- [extra.py](../tests/202309/extra.py)
- [naming-followup.json](../tests/202309/naming-followup.json)
- [online-update-report.json](../tests/202309/online-update-report.json)
- [online-verdicts.json](../tests/202309/online-verdicts.json)
- [summary.json](../tests/202309/summary.json)

<!-- local-validation-attachments:end -->
