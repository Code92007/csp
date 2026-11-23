#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],b[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int x,y;
        scanf("%d.%d",&x,&y);
        a[i]=x+(y>=5);
        b[i]=x+(y>5 || (y==5 && x%2));
    }
    for(int i=1;i<=n;++i){
        printf("%d%c",a[i]," \n"[i==n]);
    }
    for(int i=1;i<=n;++i){
        printf("%d%c",b[i]," \n"[i==n]);
    }
    return 0;
}
