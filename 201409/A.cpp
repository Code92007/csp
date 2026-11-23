#include<bits/stdc++.h>
using namespace std;
int n,ans;
set<int> a;
int main(){
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        a.insert(x);
    }
    for(const int &x:a){
        ans+=a.count(x+1);
    }
    printf("%d\n",ans);
    return 0;
}
