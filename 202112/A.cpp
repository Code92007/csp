#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,x,ans;
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&x);
        ans+=m-x;
    }
    printf("%lld\n",ans);
    return 0;
}
