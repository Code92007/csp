#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,K=7,M=64,V=900,H=1<<18;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int T,n,m,p,cnt,last,w[N][K],code[V],id[H],tr[V][M];
int fa[K],on[K],lab[K];
ll dp[V],ndp[V];
char s[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    fa[find(x)]=find(y);
}
void init(){
    memset(id,-1,sizeof id);
    cnt=1;code[0]=0;id[0]=0;
    for(int u=0;u<cnt;++u){
        int c=code[u];
        for(int S=0;S<(1<<p);++S){
            iota(fa,fa+K,0);
            memset(on,0,sizeof on);
            memset(lab,0,sizeof lab);
            for(int i=0;i<p;++i){
                int v=(c>>(i*3))&7;
                on[i]=(v!=0);
                if(!v)continue;
                for(int j=0;j<i;++j){
                    if(((c>>(j*3))&7)==v)merge(i,j);
                }
            }
            for(int j=0;j<p;++j){
                if((S>>j)&1){
                    on[0]=on[j+1]=1;
                    merge(0,j+1);
                }
            }
            if(on[0]){
                bool stay=0,other=0;
                for(int j=1;j<=p;++j){
                    if(!on[j])continue;
                    if(find(j)==find(0))stay=1;
                    else other=1;
                }
                if(!stay){
                    tr[u][S]=other?-1:-2;
                    continue;
                }
            }
            int num=0,v=0;
            for(int j=1;j<=p;++j){
                if(!on[j])continue;
                int r=find(j);
                if(!lab[r])lab[r]=++num;
                v|=lab[r]<<(3*(j-1));
            }
            if(id[v]<0){
                id[v]=cnt;
                code[cnt++]=v;
            }
            tr[u][S]=id[v];
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%s",&n,&m,&p,s);
        last=0;
        for(int i=0;i<n;++i){
            if(s[i]=='1')last=i;
        }
        memset(w,-1,sizeof w);
        for(int i=0,u,v,c;i<m;++i){
            scanf("%d%d%d",&u,&v,&c);
            w[u-1][v-u-1]=c;
        }
        init();
        memset(dp,(int)INF,sizeof dp);
        dp[0]=0;
        ll ans=INF;
        for(int i=0;i<n;++i){
            memset(ndp,(int)INF,sizeof ndp);
            int S=0;
            for(int j=0;j<p;++j){
                if(w[i][j]>=0)S|=1<<j;
            }
            for(int b=S;;b=(b-1)&S){
                ll sum=0;
                for(int j=0;j<p;++j){
                    if((b>>j)&1)sum+=w[i][j];
                }
                for(int u=0;u<cnt;++u){
                    if(dp[u]==INF)continue;
                    if(s[i]=='1' && !(code[u]&7) && !b)continue;
                    int v=tr[u][b];
                    if(v==-2){
                        if(i>=last)ans=min(ans,dp[u]+sum);
                    }
                    else if(v>=0)ndp[v]=min(ndp[v],dp[u]+sum);
                }
                if(!b)break;
            }
            copy(ndp,ndp+cnt,dp);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
