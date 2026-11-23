#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int n,x,ans,num;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        ++cnt[x];
    }
    for(auto &[x,c]:cnt){
        if(c>num){
            num=c;
            ans=x;
        }
    }
    printf("%d\n",ans);
    return 0;
}
