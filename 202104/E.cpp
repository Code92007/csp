#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 I;
const int N=510;
const I INF=I(1)<<120;
int n,m;
ll p[N],a[N][N];
I d[N],ans[N];
bool vis[N];
ll inv(ll a,ll b){
    ll mod=b,x=1,y=0;
    while(b){
        ll q=a/b,c=a-q*b;
        a=b;b=c;
        c=x-q*y;
        x=y;y=c;
    }
    return (x%mod+mod)%mod;
}
void print(I x){
    if(!x){
        putchar('0');
        return;
    }
    string s;
    while(x){
        s.push_back('0'+x%10);
        x/=10;
    }
    reverse(s.begin(),s.end());
    printf("%s",s.c_str());
}
int main(){
    scanf("%d%d",&n,&m);
    memset(a,-1,sizeof a);
    fill(d,d+m,INF);
    fill(ans,ans+n,INF);
    for(int i=0;i<m;++i){
        int k;
        scanf("%d",&k);
        while(k--){
            int s;
            ll t;
            scanf("%d%lld",&s,&t);
            a[i][s-1]=p[i];
            p[i]+=t;
        }
        if(a[i][0]>=0)d[i]=a[i][0];
    }
    for(int turn=0;turn<m;++turn){
        int u=-1;
        for(int i=0;i<m;++i){
            if(!vis[i] && (u<0 || d[i]<d[u]))u=i;
        }
        if(u<0 || d[u]==INF)break;
        vis[u]=1;
        for(int s=0;s<n;++s){
            if(a[u][s]<0)continue;
            I t=a[u][s];
            if(t<d[u])t+=(d[u]-t+p[u]-1)/p[u]*p[u];
            ans[s]=min(ans[s],t);
        }
        for(int v=0;v<m;++v){
            if(vis[v] || d[v]<=d[u])continue;
            ll g=gcd(p[u],p[v]),mod=p[v]/g;
            ll iv=mod==1?0:inv(p[u]/g,mod),cycle=p[u]*mod;
            for(int s=0;s<n;++s){
                if(a[u][s]<0 || a[v][s]<0)continue;
                ll w=a[v][s]-a[u][s];
                if(w%g)continue;
                ll k=0;
                if(mod>1)k=(w/g*iv%mod+mod)%mod;
                I t=a[u][s]+p[u]*k;
                if(t>=d[v])continue;
                if(t<d[u])t+=(d[u]-t+cycle-1)/cycle*cycle;
                d[v]=min(d[v],t);
            }
        }
    }
    for(int i=1;i<n;++i){
        if(ans[i]==INF)printf("inf");
        else print(ans[i]);
        puts("");
    }
    return 0;
}
