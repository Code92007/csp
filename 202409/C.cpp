#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct block{
    ll st,m,k;
    vector<int> a,b;
};
int n,used;
ll off;
bool ok=true;
string s;
vector<string> text;
vector<int> a,ans;
vector<block> v;
unordered_map<string,int> mp;
bool read(string &str){
    str.clear();
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        str+=char(c);
    }
    return c!=EOF || !str.empty();
}
int id(const string &str){
    auto it=mp.find(str);
    if(it!=mp.end())return it->second;
    int x=text.size();
    text.push_back(str);
    mp[str]=x;
    return x;
}
ll num(const string &str){
    ll x=0;
    for(const char &c:str){
        x=x*10+c-'0';
        if(x>1e12)return 1e12;
    }
    return x;
}
int main(){
    scanf("%d",&n);
    read(s);
    a.resize(n);
    for(int &x:a){
        read(s);
        x=id(s);
    }
    regex re("^@@ -([1-9][0-9]*),([1-9][0-9]*) \\+([1-9][0-9]*),([1-9][0-9]*) @@$");
    while(read(s)){
        if(!s.empty() && s[0]=='#')continue;
        if(!s.empty() && s[0]=='@'){
            smatch match;
            if(!regex_match(s,match,re)){
                ok=false;
                break;
            }
            block cur;
            cur.st=num(match[1]);
            cur.m=num(match[2]);
            cur.k=num(match[4]);
            if(!v.empty() && cur.st<v.back().st+v.back().m){
                ok=false;
                break;
            }
            v.push_back(std::move(cur));
        }
        else if(!v.empty()){
            if(s.empty() || (s[0]!=' ' && s[0]!='+' && s[0]!='-')){
                ok=false;
                break;
            }
            int x=id(s.substr(1));
            if(s[0]!='+')v.back().a.push_back(x);
            if(s[0]!='-')v.back().b.push_back(x);
        }
    }
    if(v.empty())ok=false;
    for(block &cur:v){
        if(cur.m!=(ll)cur.a.size() || cur.k!=(ll)cur.b.size())ok=false;
    }
    if(ok){
        for(block &cur:v){
            int len=cur.a.size();
            vector<int> f(len);
            for(int i=1,j=0;i<len;++i){
                while(j && cur.a[i]!=cur.a[j]){
                    j=f[j-1];
                }
                if(cur.a[i]==cur.a[j])++j;
                f[i]=j;
            }
            ll st=cur.st-1+off,delta=INF;
            int pos=-1;
            for(int i=used,j=0;i<n;++i){
                while(j && a[i]!=cur.a[j]){
                    j=f[j-1];
                }
                if(a[i]==cur.a[j])++j;
                if(j==len){
                    int x=i-len+1;
                    ll d=x-st;
                    bool best=pos==-1 || abs(d)<abs(delta);
                    best=best || (abs(d)==abs(delta) && d<delta);
                    if(abs(d)<len && best){
                        pos=x;
                        delta=d;
                    }
                    j=f[j-1];
                }
            }
            if(pos==-1){
                ok=false;
                break;
            }
            ans.insert(ans.end(),a.begin()+used,a.begin()+pos);
            ans.insert(ans.end(),cur.b.begin(),cur.b.end());
            used=pos+len;
            off+=delta;
        }
    }
    if(!ok){
        puts("Patch is damaged.");
        return 0;
    }
    ans.insert(ans.end(),a.begin()+used,a.end());
    for(int &x:ans){
        puts(text[x].c_str());
    }
    return 0;
}
