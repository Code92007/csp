#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int k,m;
bool check(int x){
    ll t=n;
    for(int i=0;i<m;++i){
        t-=(t*k+99)/100;
        if(t<x)return 0;
        t-=x;
    }
    return 1;
}
int main(){
    scanf("%lld%d%d",&n,&k,&m);
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}
