#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,a[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int j=m-1;j>=0;--j){
        for(int i=0;i<n;++i){
            printf("%d%c",a[i][j],i==n-1?'\n':' ');
        }
    }
    return 0;
}
