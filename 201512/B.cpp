#include<bits/stdc++.h>
using namespace std;
const int N=35;
int n,m,a[N][N];
bool vis[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(j+2<m && a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2]){
                for(int k=0;k<3;++k){
                    vis[i][j+k]=true;
                }
            }
            if(i+2<n && a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j]){
                for(int k=0;k<3;++k){
                    vis[i+k][j]=true;
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            printf("%d%c",vis[i][j]?0:a[i][j],j==m-1?'\n':' ');
        }
    }
    return 0;
}
