#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=1010;
int n,cnt[N],tot;
P a[N];
int main(){
    scanf("%d",&n);
    for(int i=0,x;i<n;++i){
        scanf("%d",&x);
        ++cnt[x];
    }
    for(int i=0;i<N;++i){
        if(cnt[i])a[tot++]=P(-cnt[i],i);
    }
    sort(a,a+tot);
    for(int i=0;i<tot;++i){
        printf("%d %d\n",a[i].second,-a[i].first);
    }
    return 0;
}
