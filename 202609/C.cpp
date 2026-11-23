#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,T,t[N],a[N],cur[N],ed[N],st[N],ans[N];
bool pre[N][N];
queue<int>q[N];
int main(){
    scanf("%d%d%d",&n,&m,&T);
    for(int i=0;i<m;++i){
        scanf("%d",&t[i]);
    }
    for(int i=1;i<=n;++i){
        int k,x;
        scanf("%d%d",&a[i],&k);
        while(k--){
            scanf("%d",&x);
            pre[i][x-1]=1;
        }
        q[(i-1)%m].push(i);
    }
    memset(st,-1,sizeof st);
    int cnt=0;
    for(int now=0;cnt<n;++now){
        for(int i=0;i<m;++i){
            int u=cur[i];
            if(!u || ed[i]!=now)continue;
            if(!a[u]){
                ans[u]=now-st[u];
                ++cnt;
            }
            else{
                q[(i+(now-1)/T)%m].push(u);
            }
            cur[i]=0;
        }
        for(int i=0;i<m;++i){
            int id=(i+now/T)%m;
            if(cur[i] || q[id].empty())continue;
            int u=q[id].front();
            q[id].pop();
            int v=pre[u][i]+1;
            int len=min(t[i],(a[u]+v-1)/v);
            if(st[u]==-1){
                st[u]=now;
            }
            a[u]=max(0,a[u]-len*v);
            cur[i]=u;
            ed[i]=now+len;
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}
