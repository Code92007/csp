#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;++i){
        int l=max(0,i-1),r=min(n-1,i+1),sum=0;
        for(int j=l;j<=r;++j){
            sum+=a[j];
        }
        printf("%d%c",sum/(r-l+1),i==n-1?'\n':' ');
    }
    return 0;
}
