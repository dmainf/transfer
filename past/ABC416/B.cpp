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
    cin >> s;
    t = string(s.size(), '.');
    rep(i, s.size()) {
        if(s[i]=='#') t[i]='#';
    }
    bool flag=true;
    rep(i, t.size()) {
        if(t[i]=='.' && flag) {
            t[i]='o';
            flag=false;
        }
        if(t[i]=='#') flag=true;
    }
    cout << t << endl;

    return 0;
}