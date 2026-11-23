#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,x,pre,cur,ans,d[N];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x>pre){
            ++d[pre+1];
            --d[x+1];
        }
        pre=x;
    }
    for(int i=1;i<=10000;++i){
        cur+=d[i];
        ans=max(ans,cur);
    }
    printf("%d\n",ans);
    return 0;
}
