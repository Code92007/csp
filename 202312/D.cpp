#include<bits/stdc++.h>
using namespace std;
const int N=1<<17,M=32;
const int mod=998244353;
struct mat{
    int a=1,b=0,c=0,d=1;
};
mat mul(const mat &x,const mat &y){
    mat z;
    z.a=(1ll*x.a*y.a+1ll*x.b*y.c)%mod;
    z.b=(1ll*x.a*y.b+1ll*x.b*y.d)%mod;
    z.c=(1ll*x.c*y.a+1ll*x.d*y.c)%mod;
    z.d=(1ll*x.c*y.b+1ll*x.d*y.d)%mod;
    return z;
}
struct prod{
    mat a,b;
};
prod merge(const prod &x,const prod &y){
    return {mul(y.a,x.a),mul(x.b,y.b)};
}
struct segtree{
    int n;
    struct node{
        int l,r,del,sz,cnt;
        prod all,pre;
    }e[N<<1];
    #define l(p) e[p].l
    #define r(p) e[p].r
    prod prefix(int p,int k){
        node &v=e[p];
        if(k==v.sz)return v.all;
        if(!k)return prod();
        if(k<=v.cnt)return prefix(p<<1,k);
        return merge(v.pre,prefix(p<<1|1,k-v.cnt));
    }
    void pushup(int p){
        node &v=e[p],&a=e[p<<1],&b=e[p<<1|1];
        v.cnt=max(0,a.sz-b.del);
        v.sz=v.cnt+b.sz;
        v.del=a.del+max(0,b.del-a.sz);
        v.pre=prefix(p<<1,v.cnt);
        if(!v.cnt)v.all=b.all;
        else if(!b.sz)v.all=v.pre;
        else v.all=merge(v.pre,b.all);
    }
    void set(int p,int type,const mat &v){
        e[p].del=(type==3);
        e[p].sz=(type!=3);
        e[p].all=prod();
        if(type==1)e[p].all.a=v;
        if(type==2)e[p].all.b=v;
    }
    void build(int p,int x,int y){
        l(p)=x;r(p)=y;
        if(x==y)return;
        int mid=(x+y)>>1;
        build(p<<1,x,mid);
        build(p<<1|1,mid+1,y);
    }
    void init(int k){
        n=1;
        while(n<k){
            n<<=1;
        }
        build(1,0,n-1);
    }
    void update(int x,int type,const mat &v){
        int p=n+x;
        set(p,type,v);
        while(p>>=1){
            pushup(p);
        }
    }
    mat query(int x,int y){
        int a[M],b[M],na=0,nb=0;
        for(x+=n,y+=n+1;x<y;x>>=1,y>>=1){
            if(x&1)a[na++]=x++;
            if(y&1)b[nb++]=--y;
        }
        int del=0;
        prod ans;
        bool ok=false;
        auto take=[&](int p){
            node &v=e[p];
            if(v.sz<=del)del+=v.del-v.sz;
            else{
                prod cur=prefix(p,v.sz-del);
                ans=ok?merge(cur,ans):cur;
                ok=true;
                del=v.del;
            }
        };
        for(int i=0;i<nb;++i){
            take(b[i]);
        }
        for(int i=na-1;i>=0;--i){
            take(a[i]);
        }
        return mul(ans.a,ans.b);
    }
}tr;
int n,m,op,x,y,type;
mat read(int t){
    mat v;
    if(t!=3)scanf("%d%d%d%d",&v.a,&v.b,&v.c,&v.d);
    return v;
}
int main(){
    scanf("%d%d",&n,&m);
    tr.init(n);
    for(int i=0;i<n;++i){
        scanf("%d",&type);
        tr.set(tr.n+i,type,read(type));
    }
    for(int p=tr.n-1;p;--p){
        tr.pushup(p);
    }
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&type);
            tr.update(x-1,type,read(type));
        }
        else{
            scanf("%d%d",&x,&y);
            mat ans=tr.query(x-1,y-1);
            printf("%d %d %d %d\n",ans.a,ans.b,ans.c,ans.d);
        }
    }
    return 0;
}
