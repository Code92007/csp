#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef __uint128_t u128;
const int N=32,M=5;
const ull mod=2009731336725594113ull;
const ull magic[M]={314882150829468584ull,427197303358170108ull,1022292690726729920ull,1698479428772363217ull,2006101093849356424ull};
int n,q,l,r,f[N][N];
ull rem[N];
vector<ull> g{1};
map<ull,int> id{{1,0}};
struct segtree{
    int n;
    struct node{
        int l,r,s[N];
        unsigned char tag;
    };
    vector<node> e;
    #define l(p) e[p].l
    #define r(p) e[p].r
    void pushup(int p){
        for(int i=0;i<N;++i){
            e[p].s[i]=e[p<<1].s[i]+e[p<<1|1].s[i];
        }
    }
    void build(int p,int x,int y,int k){
        l(p)=x;r(p)=y;
        if(x==y){
            if(x>k)return;
            for(int i=0;i<N;++i){
                rem[i]+=g[i];
                if(rem[i]>=mod)rem[i]-=mod;
                e[p].s[i]=rem[i]%2019;
            }
            return;
        }
        int mid=(x+y)>>1;
        build(p<<1,x,mid,k);
        build(p<<1|1,mid+1,y,k);
        pushup(p);
    }
    void init(int k){
        n=1;
        while(n<k){
            n<<=1;
        }
        e.resize(n<<1);
        build(1,1,n,k);
    }
    void set(int p,int s){
        int a[N];
        for(int i=0;i<N;++i){
            a[i]=e[p].s[f[i][s]];
        }
        copy(a,a+N,e[p].s);
        e[p].tag=f[e[p].tag][s];
    }
    void pushdown(int p){
        if(!e[p].tag)return;
        set(p<<1,e[p].tag);
        set(p<<1|1,e[p].tag);
        e[p].tag=0;
    }
    int query(int p,int x,int y){
        if(x<=l(p) && r(p)<=y)return e[p].s[0];
        pushdown(p);
        int mid=(l(p)+r(p))>>1,ans=0;
        if(x<=mid)ans+=query(p<<1,x,y);
        if(y>mid)ans+=query(p<<1|1,x,y);
        return ans;
    }
    void update(int p,int x,int y,int s){
        if(x<=l(p) && r(p)<=y){
            set(p,s);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(x<=mid)update(p<<1,x,y,s);
        if(y>mid)update(p<<1|1,x,y,s);
        pushup(p);
    }
}tr;
int main(){
    scanf("%d%d",&n,&q);
    for(size_t i=0;i<g.size();++i){
        for(const ull &x:magic){
            ull y=u128(g[i])*x%mod;
            if(id.count(y))continue;
            id[y]=g.size();
            g.push_back(y);
        }
    }
    if(g.size()!=N)return 1;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            f[i][j]=id.at(u128(g[i])*g[j]%mod);
        }
    }
    tr.init(n);
    while(q--){
        scanf("%d%d",&l,&r);
        int ans=tr.query(1,l,r);
        printf("%d\n",ans);
        tr.update(1,l,r,id.at(magic[ans%5]));
    }
    return 0;
}
