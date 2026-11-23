#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=128;
int n,cnt[M];
char s[N];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        memset(cnt,0,sizeof cnt);
        bool a=false,b=false,c=false,rep=false;
        for(int i=0;s[i];++i){
            unsigned char x=s[i];
            if(isalpha(x))a=true;
            else if(isdigit(x))b=true;
            else c=true;
            if(++cnt[x]>2)rep=true;
        }
        int ans;
        if(!(a && b && c))ans=0;
        else if(rep)ans=1;
        else ans=2;
        printf("%d\n",ans);
    }
    return 0;
}
