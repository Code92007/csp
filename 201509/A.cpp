#include<bits/stdc++.h>
using namespace std;
int n,pre,cnt,x;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if(!i || x!=pre)++cnt;
        pre=x;
    }
    printf("%d\n",cnt);
    return 0;
}
