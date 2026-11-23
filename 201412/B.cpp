#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,a[N][N],cnt;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int s=0;s<=2*n-2;++s){
        int l=max(0,s-n+1),r=min(n-1,s);
        for(int k=l;k<=r;++k){
            int i=s&1?k:l+r-k,j=s-i;
            printf("%d%c",a[i][j],++cnt==n*n?'\n':' ');
        }
    }
    return 0;
}
