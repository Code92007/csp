#include<bits/stdc++.h>
using namespace std;
const int N=8,M=10;
int n;
char s[M];
unordered_map<string,int> cnt;
int main(){
    scanf("%d",&n);
    while(n--){
        string t;
        for(int i=0;i<N;++i){
            scanf("%s",s);
            t+=s;
        }
        printf("%d\n",++cnt[t]);
    }
    return 0;
}
