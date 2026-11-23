#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,r,x,ans;
vector<ll> a;
int main(){
    scanf("%d%lld",&n,&m);
    a.resize(n+2);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    a[n+1]=m;
    r=m/(n+1);
    int i=0;
    while(x<m){
        while(i<n && a[i+1]<=x){
            ++i;
        }
        ll j=x/r,y=min(a[i+1],(j+1)*r);
        ans+=(y-x)*llabs(j-i);
        x=y;
    }
    printf("%lld\n",ans);
    return 0;
}
