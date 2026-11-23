#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=610;
int n,l,r,t,ans;
ll s[N][N];
int main(){
    scanf("%d%d%d%d",&n,&l,&r,&t);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x;
            scanf("%d",&x);
            s[i][j]=x+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int a=max(1,i-r),b=max(1,j-r);
            int c=min(n,i+r),d=min(n,j+r);
            ll sum=s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
            ans+=(sum<=1ll*t*(c-a+1)*(d-b+1));
        }
    }
    printf("%d\n",ans);
    return 0;
}
