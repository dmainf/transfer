#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
int main(){
    const int INF=1e9;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> d(n+1, 0), c(m);
    rep(i, n) cin >> d[i];
    rep(i, m) cin >> c[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
    dp[0][0]=0;
    rep(i, n+1) rep(j, m) {
        dp[i][j+1]=min(dp[i][j+1], dp[i][j]);//waiting
        if(i<n) dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]+d[i]*c[j]);//proceed
    }
    cout << dp[n][m] << endl;

    return 0;
}