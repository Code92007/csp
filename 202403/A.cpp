#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> cnt,sum,last;
int main(){
    scanf("%d%d",&n,&m);
    cnt.resize(m+1);
    sum.resize(m+1);
    last.resize(m+1);
    for(int i=1;i<=n;++i){
        int k;
        scanf("%d",&k);
        while(k--){
            int x;
            scanf("%d",&x);
            ++sum[x];
            if(last[x]!=i){
                ++cnt[x];
                last[x]=i;
            }
        }
    }
    for(int i=1;i<=m;++i){
        printf("%d %d\n",cnt[i],sum[i]);
    }
    return 0;
}
