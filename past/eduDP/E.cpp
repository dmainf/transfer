#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const ll INF=1e18;
const int MAX=1e5+9;
template<class T> inline bool chmin(T& a, T b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(n+1, vector<ll>(MAX, INF)); 
    dp[0][0]=0;
    //dp[i][v] i個目の品物までで価値vにできる最小の重み
    rep(i, n) {
        rep(val, MAX) {
            chmin(dp[i+1][val], dp[i][val]);
            if(0<=val-v[i]) chmin(dp[i+1][val], dp[i][val-v[i]]+w[i]);
        }
    }
    int ans=0;
    rep(val, MAX) if(dp[n][val]<=W) {
        ans=max(ans, val);
    }
    cout << ans << endl;

    return 0;
}