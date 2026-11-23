#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,l,r;
ll m;
vector<P> a;
int main(){
    scanf("%d%lld%d",&n,&m,&k);
    a.resize(n);
    l=r=k;
    for(auto &[t,c]:a){
        scanf("%d%d",&t,&c);
        r=max(r,t);
    }
    while(l<r){
        int mid=l+(r-l)/2;
        ll sum=0;
        for(auto &[t,c]:a){
            if(t>mid)sum+=1ll*(t-mid)*c;
        }
        if(sum<=m)r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
