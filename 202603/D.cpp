#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<19,M=12;
int n,m,d,op,l,r;
ll k,a[M],ans[M];
void split(ll x,ll *v){
    for(int j=0;j<d;++j){
        v[j]=x%k;
        x/=k;
    }
}
struct segtree{
    int n;
    struct node{
        int l,r;
        ll s[M],p[M],tag[M];
    }e[N<<1];
    #define l(p) e[p].l
    #define r(p) e[p].r
    void pushup(int p){
        for(int j=0;j<d;++j){
            e[p].s[j]=(e[p<<1].s[j]+e[p<<1|1].s[j])%k;
            e[p].p[j]=(e[p<<1].p[j]+e[p<<1|1].p[j])%k;
        }
    }
    void apply(int p,ll *v){
        node &t=e[p];
        int len=r(p)-l(p)+1;
        for(int j=0;j<d;++j){
            ll w=v[0]*v[j]%k;
            t.p[j]=(t.p[j]+v[0]*t.s[j]+v[j]*t.s[0]+w*len)%k;
        }
        for(int j=0;j<d;++j){
            t.s[j]=(t.s[j]+v[j]*len)%k;
            t.tag[j]=(t.tag[j]+v[j])%k;
        }
    }
    void pushdown(int p){
        bool ok=0;
        for(int j=0;j<d;++j){
            ok|=e[p].tag[j]!=0;
        }
        if(!ok)return;
        apply(p<<1,e[p].tag);
        apply(p<<1|1,e[p].tag);
        memset(e[p].tag,0,sizeof e[p].tag);
    }
    void build(int p,int x,int y){
        l(p)=x;r(p)=y;
        if(x==y){
            ll v;
            scanf("%lld",&v);
            split(v,e[p].s);
            for(int j=0;j<d;++j){
                e[p].p[j]=e[p].s[0]*e[p].s[j]%k;
            }
            return;
        }
        int mid=(x+y)>>1;
        build(p<<1,x,mid);
        build(p<<1|1,mid+1,y);
        pushup(p);
    }
    void init(int x){
        n=x;
        build(1,1,n);
    }
    void update(int p,int x,int y){
        if(x<=l(p) && r(p)<=y){
            apply(p,a);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(x<=mid)update(p<<1,x,y);
        if(y>mid)update(p<<1|1,x,y);
        pushup(p);
    }
    void query(int p,int x,int y){
        if(x<=l(p) && r(p)<=y){
            for(int j=0;j<d;++j){
                ans[j]=(ans[j]+e[p].s[j]+e[p].p[j])%k;
            }
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(x<=mid)query(p<<1,x,y);
        if(y>mid)query(p<<1|1,x,y);
    }
}tr;
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    for(ll x=1e12;x;x/=k){
        ++d;
    }
    tr.init(n);
    while(m--){
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            ll x;
            scanf("%lld",&x);
            split(x,a);
            tr.update(1,l,r);
        }
        else{
            memset(ans,0,sizeof ans);
            tr.query(1,l,r);
            ans[0]=ans[0]*((k+1)/2)%k;
            ll val=0;
            for(int j=d-1;j>=0;--j){
                val=val*k+ans[j];
            }
            printf("%lld\n",val);
        }
    }
    return 0;
}
