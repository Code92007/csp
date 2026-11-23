#include<bits/stdc++.h>
using namespace std;
const int N=20010;
int n,m,head[N],to[N<<1],nxt[N<<1],cnt,d[N],q[N];
void add(int u,int v){
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int bfs(int s){
    memset(d,-1,sizeof d);
    int l=0,r=0,u=s;
    q[r++]=s;d[s]=0;
    while(l<r){
        int x=q[l++];
        if(d[x]>d[u])u=x;
        for(int i=head[x];i;i=nxt[i]){
            int v=to[i];
            if(d[v]>=0)continue;
            d[v]=d[x]+1;
            q[r++]=v;
        }
    }
    return u;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int u=1,p;u<n+m;++u){
        scanf("%d",&p);
        --p;
        add(u,p);add(p,u);
    }
    int u=bfs(0),v=bfs(u);
    printf("%d\n",d[v]);
    return 0;
}
