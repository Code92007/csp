#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=60,K=26;
int n,kind[K];
bool ok[K];
char fmt[M],s[N];
string val[K];
int main(){
    scanf("%s%d",fmt,&n);
    for(int i=0;fmt[i];++i){
        if(fmt[i]==':')continue;
        kind[fmt[i]-'a']=fmt[i+1]==':'?2:1;
    }
    fgets(s,N,stdin);
    for(int t=1;t<=n;++t){
        fgets(s,N,stdin);
        memset(ok,0,sizeof ok);
        istringstream in(s);
        string w;
        in>>w;
        while(in>>w){
            if(w.size()!=2 || w[0]!='-')break;
            if(w[1]<'a' || w[1]>'z')break;
            int c=w[1]-'a';
            if(!kind[c])break;
            string v;
            if(kind[c]==2 && !(in>>v))break;
            ok[c]=1;val[c]=v;
        }
        printf("Case %d:",t);
        for(int c=0;c<K;++c){
            if(!ok[c])continue;
            printf(" -%c",'a'+c);
            if(kind[c]==2)printf(" %s",val[c].c_str());
        }
        puts("");
    }
    return 0;
}
