#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,t,a[N],b[N];
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n*m;++i){
        scanf("%d",&a[i]);
    }
    while(t--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)n=x,m=y;
        else if(op==2){
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    b[j*n+i]=a[i*m+j];
                }
            }
            memcpy(a,b,n*m*sizeof(int));
            swap(n,m);
        }
        else printf("%d\n",a[x*m+y]);
    }
    return 0;
}
