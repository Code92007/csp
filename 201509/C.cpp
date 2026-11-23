#include<bits/stdc++.h>
using namespace std;
int m,n;
string s;
vector<string> lines;
unordered_map<string,string> mp;
void read(string &str){
    str.clear();
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        str+=char(c);
    }
}
int main(){
    scanf("%d%d",&m,&n);
    read(s);
    lines.resize(m);
    for(string &str:lines){
        read(str);
    }
    while(n--){
        read(s);
        size_t p=s.find(' '),q=s.find('"',p);
        mp[s.substr(0,p)]=s.substr(q+1,s.size()-q-2);
    }
    for(string &str:lines){
        for(size_t p=0;p<str.size();){
            size_t l=str.find("{{ ",p);
            if(l==string::npos){
                printf("%s",str.substr(p).c_str());
                break;
            }
            printf("%s",str.substr(p,l-p).c_str());
            size_t r=str.find(" }}",l+3);
            auto it=mp.find(str.substr(l+3,r-l-3));
            if(it!=mp.end())printf("%s",it->second.c_str());
            p=r+3;
        }
        putchar('\n');
    }
    return 0;
}
