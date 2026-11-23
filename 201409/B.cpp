#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,x,y,u,v,ans;
bool a[N][N];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&x,&y,&u,&v);
        for(int i=x;i<u;++i){
            for(int j=y;j<v;++j){
                a[i][j]=true;
            }
        }
    }
    for(auto &row:a){
        for(bool &val:row){
            ans+=val;
        }
    }
    printf("%d\n",ans);
    return 0;
}
