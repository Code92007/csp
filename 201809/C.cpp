#include<bits/stdc++.h>
using namespace std;
const int N=110,M=90;
int n,m,fa[N],st[N],top,ans[N],cnt;
char s[M];
string tag[N],id[N],sel[M];
string lower(string s){
    for(char &c:s){
        c=tolower((unsigned char)c);
    }
    return s;
}
bool match(int u,int k){
    if(sel[k][0]=='#')return id[u]==sel[k];
    return tag[u]==sel[k];
}
int main(){
    scanf("%d%d",&n,&m);
    fgets(s,M,stdin);
    for(int i=1;i<=n;++i){
        fgets(s,M,stdin);
        int d=0;
        while(s[d]=='.'){
            ++d;
        }
        top=d/2;
        fa[i]=top?st[top]:0;
        istringstream in(s+d);
        in>>tag[i]>>id[i];
        tag[i]=lower(tag[i]);
        st[++top]=i;
    }
    while(m--){
        fgets(s,M,stdin);
        istringstream in(s);
        int len=0;
        string t;
        while(in>>t){
            sel[len++]=t[0]=='#'?t:lower(t);
        }
        cnt=0;
        for(int i=1;i<=n;++i){
            int k=len-1;
            if(!match(i,k))continue;
            --k;
            int u=fa[i];
            while(k>=0 && u){
                if(match(u,k))--k;
                u=fa[u];
            }
            if(k<0)ans[cnt++]=i;
        }
        printf("%d",cnt);
        for(int i=0;i<cnt;++i){
            printf(" %d",ans[i]);
        }
        puts("");
    }
    return 0;
}
