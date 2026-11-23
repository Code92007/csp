#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w,state;
ll ans;
bool had;
string text;
string trim(const string &s){
    int l=s.find_first_not_of(' ');
    if(l==-1)return "";
    return s.substr(l,s.find_last_not_of(' ')-l+1);
}
ll calc(const string &s,int w){
    if(s.empty())return 1;
    ll ans=0;
    int p=0,len=s.size();
    while(p<len){
        ++ans;
        p+=w;
        while(p<len && s[p]==' '){
            ++p;
        }
    }
    return ans;
}
void flush(){
    if(state)ans+=calc(text,state==2?w-3:w);
    text.clear();
}
void start(int kind){
    if(had)++ans;
    had=true;
    state=kind;
}
void append(const string &s){
    string t=trim(s);
    if(t.empty())return;
    if(!text.empty())text+=' ';
    text+=t;
}
bool read(string &s){
    s.clear();
    int c=getchar();
    while(c!=EOF && c!='\n'){
        s+=char(c);
        c=getchar();
    }
    return c!=EOF || !s.empty();
}
int main(){
    scanf("%d",&w);
    string s;
    read(s);
    while(read(s)){
        bool blank=trim(s).empty();
        bool bullet=(s.size()>=2 && s[0]=='*' && s[1]==' ');
        bool indent=(s.size()>=2 && s[0]==' ' && s[1]==' ');
        if(blank){
            flush();
            state=0;
            continue;
        }
        if(bullet){
            if(state==2)flush();
            else{
                flush();
                start(2);
            }
            append(s.substr(2));
        }
        else if(state==2 && indent)append(s.substr(2));
        else{
            if(state!=1){
                flush();
                start(1);
            }
            append(s);
        }
    }
    flush();
    printf("%lld\n",ans);
    return 0;
}
