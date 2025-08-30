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
    vector<int> s(8);
    rep(i, 8) cin >> s[i];
    bool flag=true;
    rep(i, 7) {
        if(!(s[i]<=s[i+1])) flag=false;
    }
    rep(i, 8) {
        if(!(100<=s[i] && s[i]<=675)) flag=false;
        if(!(s[i]%5==0)) flag=false;
    }
    if(flag) YES;
    else NO;

    return 0;
}