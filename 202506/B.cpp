#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=105,M=8;
int n,k,x,y,ans,d[N][N];
int dx[M]={1,1,-1,-1,2,2,-2,-2};
int dy[M]={2,-2,2,-2,1,-1,1,-1};
queue<P>q;
bool ok(int a,int b){
    return 0<=a && a<n && 0<=b && b<n && d[a][b]==-1;
}
int main(){
    scanf("%d%d%d%d",&n,&k,&x,&y);
    x--,y--;
    memset(d,-1,sizeof d);
    d[x][y]=0;
    q.push(P(x,y));
    while(!q.empty()){
        auto [u,v]=q.front();
        q.pop();
        ++ans;
        if(d[u][v]==k)continue;
        for(int i=0;i<M;++i){
            int a=u+dx[i],b=v+dy[i];
            if(!ok(a,b))continue;
            d[a][b]=d[u][v]+1;
            q.push(P(a,b));
        }
    }
    printf("%d\n",ans);
    return 0;
}
