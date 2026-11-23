#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,x;
int main(){
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=0;i<n*m;++i){
        scanf("%d",&x);
        if(i%q)printf(" ");
        printf("%d",x);
        if((i%q)==(q-1))printf("\n");
    }
    return 0;
}
