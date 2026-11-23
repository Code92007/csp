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
