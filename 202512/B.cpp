#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=512;
int n,m,x,k[N],ans[M];
int f(int x,int k){
    return ((x*x+k*k)%8)^k;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d",&k[i]);
    }
    for(int i=0;i<M;++i){
        x=i;
        for(int j=1;j<=m;++j){
            int a=x>>6,b=x>>3&7,c=x&7;
            x=b<<6;
            x|=(c^f(b,k[j]))<<3;
            x|=a^f(c,k[j]);
        }
        ans[x]=i;
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&x);
        printf("%d%c",ans[x]," \n"[i==n]);
    }
    return 0;
}
