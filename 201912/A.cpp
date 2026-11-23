#include<bits/stdc++.h>
using namespace std;
const int N=4;
int n,cnt[N],sum;
bool skip(int x){
    if(x%7==0)return true;
    while(x){
        if(x%10==7)return true;
        x/=10;
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int x=1;sum<n;++x){
        if(skip(x))++cnt[(x-1)%4];
        else ++sum;
    }
    for(int &x:cnt){
        printf("%d\n",x);
    }
    return 0;
}
