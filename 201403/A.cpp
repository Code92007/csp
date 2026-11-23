#include<bits/stdc++.h>
using namespace std;
int n,ans;
set<int> a;
int main(){
    scanf("%d",&n);
    for(int i=0,x;i<n;++i){
        scanf("%d",&x);
        a.insert(x);
    }
    for(const int &x:a){
        if(x>0 && a.count(-x))++ans;
    }
    printf("%d\n",ans);
    return 0;
}
