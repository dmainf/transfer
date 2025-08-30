#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,+0};
const int dj[]={+0,+1};
const int INF=1e9;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<mint>> dp(h, vector<mint>(w, 0));
    dp[0][0]=1;
    rep(i, h) rep(j, w) if(s[i][j]!='#') {
        if(i+1<h && s[i+1][j]=='.') dp[i+1][j]+=dp[i][j];
        if(j+1<w && s[i][j+1]=='.') dp[i][j+1]+=dp[i][j];
    }
    cout << dp[h-1][w-1].val() << endl;

    return 0;
}