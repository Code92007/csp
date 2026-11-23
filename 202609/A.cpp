#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=25,M=10;
int n,m,k,a,b;
ll mu,var,x[N];
char phi[N][M];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i){
        scanf("%d.%d",&a,&b);
        mu+=a*1000+b;
    }
    for(int i=0;i<n;++i){
        scanf("%d.%d",&a,&b);
        ll v=a*1000+b;
        var+=v*v;
    }
    for(int i=0;i<k;++i){
        scanf("%d.%d",&a,&b);
        x[i]=a*1000+b;
    }
    for(int i=0;i<k;++i){
        scanf("%s",phi[i]);
    }
    ll num=m*1000-mu;
    int id=k-1;
    for(int i=0;i<k-1;++i){
        ll sum=x[i]+x[i+1];
        if(4000000ll*num*num<=sum*sum*var){
            id=i;
            break;
        }
    }
    printf("%s\n",phi[id]);
    return 0;
}
