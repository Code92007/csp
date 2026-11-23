#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b,c,l,r,ans;
int main(){
    scanf("%lld%lld%lld%lld",&b,&c,&l,&r);
    if(l%2)++l;
    for(ll x=l;x<=r;x+=2){
        ans+=2*(x*x+b*x+c);
    }
    printf("%lld\n",ans);
    return 0;
}
