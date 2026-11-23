#include<bits/stdc++.h>
using namespace std;
typedef unsigned short us;
const int N=45,M=410,K=200,V=K*K*K;
const us INF=0x3f3f;
struct job{
    int a,b,c,d;
}a[N];
int n,sum,tot,lim,bs,vol,cnt;
bool ok[M];
us f[V],g[V],*dp=f,*ndp=g;
int x[V],y[V],*cur=x,*nxt=y;
void put(int x,int y,int z,int cost){
    if(cost+max({x,y,z})>=lim)return;
    if(x>y)swap(x,y);
    int id=(x*bs+y)*bs+z;
    if(ndp[id]==INF)nxt[cnt++]=id;
    ndp[id]=min<int>(ndp[id],cost);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        job &v=a[i];
        scanf("%d%d%d%d",&v.a,&v.b,&v.c,&v.d);
        sum+=v.a;tot+=min(v.b,v.d);
    }
    ok[0]=1;
    for(int i=0;i<n;++i){
        for(int s=sum;s>=a[i].a;--s){
            ok[s]=(ok[s] || ok[s-a[i].a]);
        }
    }
    lim=tot;
    for(int s=0;s<=sum;++s){
        if(ok[s])lim=min(lim,max(s,sum-s));
    }
    bs=lim;vol=bs*bs*bs;
    memset(dp,INF,vol*sizeof *dp);
    memset(ndp,INF,vol*sizeof *ndp);
    dp[0]=0;cur[0]=0;
    int len=1;
    for(int i=0;i<n;++i){
        job &v=a[i];
        int both=min(v.b,v.d);
        cnt=0;
        for(int j=0;j<len;++j){
            int id=cur[j],z=id%bs;
            int y=id/bs%bs,x=id/bs/bs,cost=dp[id];
            put(x+v.a,y,z,cost);put(x,y+v.a,z,cost);
            if(v.c<v.a){
                put(x+v.c,y,z+v.c,cost);
                put(x,y+v.c,z+v.c,cost);
            }
            if(both<v.a)put(x,y,z,cost+both);
        }
        for(int j=0;j<len;++j){
            dp[cur[j]]=INF;
        }
        swap(dp,ndp);swap(cur,nxt);
        len=cnt;
    }
    int ans=lim;
    for(int j=0;j<len;++j){
        int id=cur[j],z=id%bs;
        int y=id/bs%bs,x=id/bs/bs;
        ans=min(ans,dp[id]+max({x,y,z}));
    }
    printf("%d\n",ans);
    return 0;
}
