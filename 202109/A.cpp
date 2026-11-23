#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll pre,mn,mx,x;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&x);
        mx+=x;
        if(x>pre)mn+=x;
        pre=x;
    }
    printf("%lld\n%lld\n",mx,mn);
    return 0;
}
