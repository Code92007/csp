#include<bits/stdc++.h>
using namespace std;
const int N=260;
int n,m,l,x,cnt[N];
int main(){
    scanf("%d%d%d",&n,&m,&l);
    for(int i=0;i<n*m;++i){
        scanf("%d",&x);
        ++cnt[x];
    }
    for(int i=0;i<l;++i){
        printf("%d%c",cnt[i],i==l-1?'\n':' ');
    }
    return 0;
}
