#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,st[N],top;
ll h[N],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&h[i]);
    }
    for(int i=1;i<=n+1;++i){
        while(top && h[st[top]]>=h[i]){
            int u=st[top--];
            ans=max(ans,h[u]*(i-st[top]-1));
        }
        st[++top]=i;
    }
    printf("%lld\n",ans);
    return 0;
}
