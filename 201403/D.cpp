#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=210,M=110;
int n,m,k,tot,d[N][M],head,tail;
ll r,x[N],y[N];
bool g[N][N];
P q[N*M];
int main(){
    scanf("%d%d%d%lld",&n,&m,&k,&r);
    tot=n+m;
    for(int i=0;i<tot;++i){
        scanf("%lld%lld",&x[i],&y[i]);
        for(int j=0;j<i;++j){
            ll dx=x[i]-x[j],dy=y[i]-y[j];
            if(dx*dx+dy*dy<=r*r)g[i][j]=g[j][i]=1;
        }
    }
    memset(d,-1,sizeof d);
    d[0][0]=0;q[tail++]=P(0,0);
    while(head<tail){
        auto [u,c]=q[head++];
        if(u==1){
            printf("%d\n",d[u][c]-1);
            return 0;
        }
        for(int v=0;v<tot;++v){
            if(!g[u][v])continue;
            int t=c+(v>=n);
            if(t>k || d[v][t]>=0)continue;
            d[v][t]=d[u][c]+1;
            q[tail++]=P(v,t);
        }
    }
    return 0;
}
