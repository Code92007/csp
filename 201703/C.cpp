#include<bits/stdc++.h>
using namespace std;
vector<string> v;
string s;
string html(const string &str){
    string ans;
    bool em=false;
    for(size_t i=0;i<str.size();){
        if(str[i]=='_'){
            ans+=em?"</em>":"<em>";
            em=!em;
            ++i;
        }
        else if(str[i]=='['){
            size_t r=str.find(']',i),t=str.find(')',r+2);
            ans+="<a href=\""+str.substr(r+2,t-r-2)+"\">";
            ans+=html(str.substr(i+1,r-i-1))+"</a>";
            i=t+1;
        }
        else ans+=str[i++];
    }
    return ans;
}
string skip(const string &str,size_t p){
    while(p<str.size() && str[p]==' '){
        ++p;
    }
    return str.substr(p);
}
void render(){
    if(v.empty())return;
    if(v[0][0]=='#'){
        size_t k=v[0].find_first_not_of('#');
        string tag="h"+to_string(k);
        string text=html(skip(v[0],k));
        printf("<%s>%s</%s>\n",tag.c_str(),text.c_str(),tag.c_str());
    }
    else if(v[0][0]=='*'){
        puts("<ul>");
        for(string &str:v){
            printf("<li>%s</li>\n",html(skip(str,1)).c_str());
        }
        puts("</ul>");
    }
    else{
        printf("<p>");
        for(size_t i=0;i<v.size();++i){
            if(i)putchar('\n');
            printf("%s",html(v[i]).c_str());
        }
        puts("</p>");
    }
    v.clear();
}
bool read(){
    s.clear();
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        s+=char(c);
    }
    return c!=EOF || !s.empty();
}
int main(){
    while(read()){
        if(s.empty())render();
        else v.push_back(s);
    }
    render();
    return 0;
}
