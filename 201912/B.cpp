#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=5;
int n,cnt[N];
set<P> a;
bool ok(int x,int y){
    vector<P> g={{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
    for(auto &v:g){
        if(!a.count(v))return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        a.insert({x,y});
    }
    for(const auto &[x,y]:a){
        if(!ok(x,y))continue;
        int sum=0;
        for(int dx:{-1,1}){
            for(int dy:{-1,1}){
                sum+=a.count({x+dx,y+dy});
            }
        }
        ++cnt[sum];
    }
    for(int &x:cnt){
        printf("%d\n",x);
    }
    return 0;
}
