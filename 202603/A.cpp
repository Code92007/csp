#include<bits/stdc++.h>
using namespace std;
int n,ans,x,cnt,len;
int main(){
    scanf("%d",&n);
    while(n--){
        cnt=len=0;
        scanf("%d",&x);
        while(x){
            cnt+=x&1;
            ++len;
            x>>=1;
        }
        ans+=(cnt*2==len);
    }
    printf("%d\n",ans);
    return 0;
}
