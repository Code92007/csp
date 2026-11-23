#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1010;
int n;
ld a[N],mu,var;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%Lf",&a[i]);
        mu+=a[i];
    }
    mu/=n;
    for(int i=1;i<=n;++i){
        ld x=a[i]-mu;
        var+=x*x;
    }
    var=sqrtl(var/n);
    for(int i=1;i<=n;++i){
        printf("%.10Lf\n",(a[i]-mu)/var);
    }
    return 0;
}
