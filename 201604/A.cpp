#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,a[N],ans;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n-1;++i){
        bool up=(a[i]>a[i-1] && a[i]>a[i+1]);
        bool down=(a[i]<a[i-1] && a[i]<a[i+1]);
        ans+=(up || down);
    }
    printf("%d\n",ans);
    return 0;
}
