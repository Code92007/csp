#include<bits/stdc++.h>
using namespace std;
int k,mu,sig,n;
int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d%d%d",&mu,&sig,&n);
        int v=100*(n-mu)/sig;
        printf("%d %d\n",v/10+1,v%10+1);
    }
    return 0;
}
