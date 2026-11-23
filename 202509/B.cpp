#include<bits/stdc++.h>
using namespace std;
const int N=205,M=65540,H=5,W=10;
int n,m,a[N][N],d[M];
char s[H][W]={"111111111","100100101","100111110","100001100","111111100"};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i+H<=n;++i){
        for(int j=0;j+W-1<=n;++j){
            int l=0,r=m-1;
            for(int u=0;u<H;++u){
                for(int v=0;v<W-1;++v){
                    if(s[u][v]=='1')r=min(r,a[i+u][j+v]);
                    else l=max(l,a[i+u][j+v]+1);
                }
            }
            if(l>r)continue;
            ++d[l];
            --d[r+1];
        }
    }
    int sum=0;
    for(int i=0;i<m;++i){
        sum+=d[i];
        if(sum)printf("%d\n",i);
    }
    return 0;
}
