#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll dx,dy,x,y;
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%lld%lld",&x,&y);
        dx+=x,dy+=y;
    }
    while(m--){
        scanf("%lld%lld",&x,&y);
        printf("%lld %lld\n",x+dx,y+dy);
    }
    return 0;
}
