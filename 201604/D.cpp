#include<bits/stdc++.h>
using namespace std;
const int N=110,M=310,K=4;
const int dx[K]={1,-1,0,0},dy[K]={0,0,1,-1};
int n,m,k,l[N][N],r[N][N],last,q[M*N*N],head,tail;
bool vis[M][N][N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0,x,y,a,b;i<k;++i){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        --x,--y;
        l[x][y]=a,r[x][y]=b;
        last=max(last,b);
    }
    q[tail++]=0;
    vis[0][0][0]=1;
    int lim=last+n+m;
    while(head<tail){
        int v=q[head++],t=v/(n*m),u=v%(n*m);
        int x=u/m,y=u%m;
        if(x==n-1 && y==m-1){
            printf("%d\n",t);
            return 0;
        }
        if(t==lim)continue;
        for(int d=0;d<K;++d){
            int a=x+dx[d],b=y+dy[d];
            if(a<0 || a>=n || b<0 || b>=m)continue;
            if(l[a][b]<=t+1 && t+1<=r[a][b])continue;
            if(vis[t+1][a][b])continue;
            vis[t+1][a][b]=1;
            q[tail++]=(t+1)*n*m+a*m+b;
        }
    }
    return 0;
}
