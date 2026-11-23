#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=1010,M=55;
int n,l,s,b[M][M],tot,ans;
P a[N];
int main(){
    scanf("%d%d%d",&n,&l,&s);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    for(int i=s;i>=0;--i){
        for(int j=0;j<=s;++j){
            scanf("%d",&b[i][j]);
            tot+=b[i][j];
        }
    }
    for(int i=0;i<n;++i){
        auto [x,y]=a[i];
        if(x+s>l || y+s>l)continue;
        int cnt=0;
        bool ok=1;
        for(int j=0;j<n;++j){
            auto [u,v]=a[j];
            int dx=u-x,dy=v-y;
            if(dx<0 || dx>s || dy<0 || dy>s)continue;
            ++cnt;
            if(!b[dx][dy]){
                ok=0;
                break;
            }
        }
        ans+=(ok && cnt==tot);
    }
    printf("%d\n",ans);
    return 0;
}
