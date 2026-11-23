#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000+10,M=25;
int n,d;
ll q[N][M],k[N][M],v[N][M],w[N],a[M][M];
int main(){
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;++i){
        for(int j=0;j<d;++j){
            scanf("%lld",&q[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<d;++j){
            scanf("%lld",&k[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<d;++j){
            scanf("%lld",&v[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&w[i]);
    }
    for(int i=0;i<n;++i){
        for(int x=0;x<d;++x){
            for(int y=0;y<d;++y){
                a[x][y]+=k[i][x]*v[i][y];
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int y=0;y<d;++y){
            ll sum=0;
            for(int x=0;x<d;++x){
                sum+=q[i][x]*a[x][y];
            }
            printf("%lld%c",sum*w[i],y==d-1?'\n':' ');
        }
    }
    return 0;
}
