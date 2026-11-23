#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1<<12,M=75;
int n;
char str[M];
string pre[N];
unordered_map<ull,string>mp;
int num(char c){
    if(c==' ')return 0;
    if(c>='0' && c<='9')return c-'0'+1;
    if(c=='_')return 37;
    return c-'A'+11;
}
char chr(int x){
    if(!x)return ' ';
    if(x<=10)return '0'+x-1;
    if(x==37)return '_';
    return 'A'+x-11;
}
ull code(string s){
    s.resize(11,' ');
    ull v=0;
    for(char &c:s){
        v=v*38+num(c);
    }
    return v;
}
string full(ull x){
    string s(11,' ');
    for(int i=10;i>=0;--i){
        s[i]=chr(x%38);
        x/=38;
    }
    while(!s.empty() && s.back()==' '){
        s.pop_back();
    }
    return s;
}
string typical(ull x){
    string s(6,' ');
    for(int i=5;i>=3;--i){
        s[i]='A'+x%26;
        x/=26;
    }
    s[2]='0'+x%10;
    x/=10;
    int v=x%36;
    x/=36;
    s[1]=v<10?'0'+v:'A'+v-10;
    s[0]=chr(x);
    if(s[0]==' ')s.erase(s.begin());
    return s;
}
void add(const string &s){
    ull h=code(s)*47055833459ull;
    mp[h>>39]=s;
    pre[h>>52]=s;
}
ull f(int l,int len){
    ull x=0;
    for(int i=0;i<len;++i){
        x=x*2+str[l+i]-'0';
    }
    return x;
}
string dec(ull x,bool &ok){
    ok=x>=(1ull<<25);
    if(ok)return typical(x-(1ull<<25));
    auto it=mp.find(x);
    return it==mp.end()?"###":"#"+it->second;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",str);
        string u,v;
        bool du=0,dv=0;
        int pos=0;
        if(str[0]=='0'){
            u=dec(f(1,28),du);
            v=dec(f(29,28),dv);
            pos=f(57,15);
        }
        else{
            string s=full(f(1,58));
            string &old=pre[f(59,12)];
            string t=old.empty()?"###":"#"+old;
            if(str[71]=='0'){
                u=t,v=s,dv=1;
            }
            else{
                u=s,v=t,du=1;
            }
        }
        printf("%s %s",u.c_str(),v.c_str());
        if(pos)printf(" %d",pos);
        puts("");
        if(du)add(u);
        if(dv)add(v);
    }
    return 0;
}
