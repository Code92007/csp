#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=2010;
int n,i,j,ans;
P a[N],b[N];
int main(){
    scanf("%d",&n);
    for(int k=0;k<n;++k){
        scanf("%d%d",&a[k].first,&a[k].second);
    }
    for(int k=0;k<n;++k){
        scanf("%d%d",&b[k].first,&b[k].second);
    }
    while(i<n && j<n){
        int l=max(a[i].first,b[j].first);
        int r=min(a[i].second,b[j].second);
        ans+=max(0,r-l);
        if(a[i].second<b[j].second)++i;
        else ++j;
    }
    printf("%d\n",ans);
    return 0;
}
