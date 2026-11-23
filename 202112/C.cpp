#include<bits/stdc++.h>
using namespace std;
const int N=2010,mod=929;
int w,s;
char t[N];
vector<int> a,b,g;
int main(){
    scanf("%d%d%s",&w,&s,t);
    int mode=0;
    for(int i=0;t[i];++i){
        char c=t[i];
        int next=isupper(c)?0:islower(c)?1:2;
        if(mode!=next){
            if(next==1)a.push_back(27);
            else if(next==2)a.push_back(28);
            else{
                a.push_back(28);
                if(mode==1)a.push_back(28);
            }
            mode=next;
        }
        a.push_back(c-(mode==0?'A':mode==1?'a':'0'));
    }
    if(a.size()%2)a.push_back(29);
    b.push_back(0);
    for(int i=0;i<(int)a.size();i+=2){
        b.push_back(a[i]*30+a[i+1]);
    }
    int k=s<0?0:1<<(s+1);
    while((b.size()+k)%w){
        b.push_back(900);
    }
    b[0]=b.size();
    for(int &x:b){
        printf("%d\n",x);
    }
    if(!k)return 0;
    g.push_back(1);
    int power=1;
    for(int i=1;i<=k;++i){
        power=power*3%mod;
        vector<int> h(g.size()+1);
        for(int j=0;j<(int)g.size();++j){
            h[j]=(h[j]+g[j])%mod;
            h[j+1]=(h[j+1]-g[j]*power%mod+mod)%mod;
        }
        g.swap(h);
    }
    vector<int> rem=b;
    rem.resize(b.size()+k);
    for(int i=0;i<(int)b.size();++i){
        int v=rem[i];
        for(int j=0;j<=k;++j){
            rem[i+j]=(rem[i+j]-v*g[j]%mod+mod)%mod;
        }
    }
    for(int i=b.size();i<(int)rem.size();++i){
        printf("%d\n",(mod-rem[i])%mod);
    }
    return 0;
}
