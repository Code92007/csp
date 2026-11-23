#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=60,M=5,K=13;
typedef array<bool,N> F;
const int lo[M]={0,0,1,1,0},hi[M]={59,23,31,12,6};
const int days[K]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct rule{
    array<F,M> f;
    vector<int> min,hour;
    string cmd;
};
int n;
ll s,t;
vector<rule> a;
string read(){
    string s;
    int c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(c!=EOF && !isspace(c)){
        s+=char(c);
        c=getchar();
    }
    return s;
}
int value(string s,int kind){
    for(char &c:s){
        c=tolower(c);
    }
    if(isdigit(s[0]))return stoi(s);
    string names=kind==3?"janfebmaraprmayjunjulaugsepoctnovdec":
                         "sunmontuewedthufrisat";
    return names.find(s)/3+(kind==3);
}
F parse(string s,int kind){
    F a;
    a.fill(false);
    if(s=="*"){
        for(int i=lo[kind];i<=hi[kind];++i){
            a[i]=true;
        }
        return a;
    }
    int p=0,len=s.size();
    while(p<len){
        int end=s.find(',',p);
        if(end==-1)end=len;
        string t=s.substr(p,end-p);
        int pos=t.find('-');
        int l=value(t.substr(0,pos),kind);
        int r=pos==-1?l:value(t.substr(pos+1),kind);
        for(int i=l;i<=r;++i){
            a[i]=true;
        }
        p=end+1;
    }
    return a;
}
bool leap(int y){
    return y%400==0 || (y%4==0 && y%100!=0);
}
int main(){
    scanf("%d%lld%lld",&n,&s,&t);
    a.resize(n);
    for(auto &r:a){
        for(int j=0;j<M;++j){
            r.f[j]=parse(read(),j);
        }
        r.cmd=read();
        for(int i=0;i<60;++i){
            if(r.f[0][i])r.min.push_back(i);
        }
        for(int i=0;i<24;++i){
            if(r.f[1][i])r.hour.push_back(i);
        }
    }
    int week=4;
    for(int y=1970;y<=t/100000000;++y){
        for(int mo=1;mo<=12;++mo){
            int last=days[mo]+(mo==2 && leap(y));
            for(int d=1;d<=last;++d,week=(week+1)%7){
                ll date=(y*10000+mo*100+d)*10000ll;
                if(date+2359<s || date>=t)continue;
                vector<pair<ll,int>> q;
                for(int i=0;i<n;++i){
                    auto &r=a[i];
                    if(!r.f[2][d] || !r.f[3][mo] || !r.f[4][week]){
                        continue;
                    }
                    for(int &h:r.hour){
                        for(int &m:r.min){
                            ll time=date+h*100+m;
                            if(s<=time && time<t)q.push_back({time,i});
                        }
                    }
                }
                sort(q.begin(),q.end());
                for(auto &[time,i]:q){
                    printf("%lld %s\n",time,a[i].cmd.c_str());
                }
            }
        }
    }
    return 0;
}
