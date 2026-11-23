#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=15;
int n,m,a[N][M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        int ans=0;
        for(int j=1;j<=n;++j){
            bool ok=true;
            for(int k=0;k<m;++k){
                if(a[j][k]<=a[i][k]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                ans=j;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
