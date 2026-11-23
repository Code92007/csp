#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=105;
int n,m,k,v,a[N],h[M];
vector<int>s[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&k);
        s[i].resize(k);
        for(int &x:s[i]){
            scanf("%d",&x);
            h[i]^=a[x];
        }
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&k);
        vector<int>t(k);
        v=0;
        for(int &x:t){
            scanf("%d",&x);
            v^=a[x];
        }
        bool ok=((s[i]==t)==(h[i]==v));
        puts(ok?"correct":"wrong");
    }
    return 0;
}
