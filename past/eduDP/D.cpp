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
const int INF=1e9;
template<class T> inline bool chmax(T& a, T b) {
    if(a<b) {
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
    vector<vector<ll>> dp(n+1, vector<ll>(W+1, 0));
    rep(i, n) rep(wei, W+1) {
        chmax(dp[i+1][wei], dp[i][wei]);
        if(0<=wei-w[i]) chmax(dp[i+1][wei], dp[i][wei-w[i]]+v[i]);
    }
    cout << dp[n][W] << endl;

    return 0;
}