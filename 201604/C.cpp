#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n;
char s[N];
vector<string> parse(const string &s,vector<string> a={}){
    istringstream in(s);
    string t;
    while(getline(in,t,'/')){
        if(t.empty() || t==".")continue;
        if(t==".."){
            if(!a.empty())a.pop_back();
        }
        else a.push_back(t);
    }
    return a;
}
int main(){
    scanf("%d%s",&n,s);
    vector<string> base=parse(s);
    fgets(s,N,stdin);
    while(n--){
        fgets(s,N,stdin);
        s[strcspn(s,"\r\n")]=0;
        vector<string> a;
        if(s[0]!='/')a=base;
        a=parse(s,a);
        if(a.empty())putchar('/');
        for(string &t:a){
            printf("/%s",t.c_str());
        }
        puts("");
    }
    return 0;
}
