#include<bits/stdc++.h>
using namespace std;
const int N=1000+10;
int n,x,cnt[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        printf("%d%c",++cnt[x],i==n-1?'\n':' ');
    }
    return 0;
}
