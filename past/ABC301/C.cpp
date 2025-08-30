#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    map<char, int> mp;
    int s_at=0, t_at=0;
    for(char c:s) {
        if(c=='@') s_at++;
        else mp[c]++;
    }
    for(char c:t) {
        if(c=='@') t_at++;
        else mp[c]--;
    }
    set<char> atcoder={'a','t','c','o','d','e','r'};
    for(auto [c, x]:mp) {
        if(x==0) continue;
        if(atcoder.count(c)) {
            if(0<x) t_at-=x;
            else s_at+=x;
        } else {
            NO;
            return 0;
        }
    }
    if(0<=s_at&&0<=t_at) YES;
    else NO;

    return 0;
}