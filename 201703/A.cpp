#include<bits/stdc++.h>
using namespace std;
int n,k,sum,ans,x;
int main(){
    scanf("%d%d",&n,&k);
    while(n--){
        scanf("%d",&x);
        sum+=x;
        if(sum>=k){
            ++ans;
            sum=0;
        }
    }
    if(sum)++ans;
    printf("%d\n",ans);
    return 0;
}
