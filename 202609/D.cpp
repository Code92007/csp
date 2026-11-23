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
