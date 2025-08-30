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
    int m=t.size();
    vector<int> ans(m+1, true);
    rep(k, 2) {
        bool flag=false;
        rep(i, m) {
            if(s[i]!=t[i] && s[i]!='?' && t[i]!='?') {
                ans[i+1]=false;
                flag=true;
            }
            if(flag) ans[i+1]=false;
        }
        reverse(all(s));
        reverse(all(t));
        reverse(all(ans));
    }
    rep(i, m+1) {
        if(ans[i]) YES;
        else NO;
    }

    return 0;
}