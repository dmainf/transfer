#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i=0;i<(N);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, m;
    cin >> N >> m;
    vector<int> c(m);
    rep(i, m) cin >> c[i];
    const int INF=1e9;
    vector<vector<int>> dp(m+1, vector<int>(N+1, INF));
    dp[0][0]=0;
    rep(i, m) rep(n, N+1) {
        dp[i+1][n]=min(dp[i+1][n], dp[i][n]);
        if(c[i]<=n) dp[i+1][n]=min(dp[i+1][n-c[i]]+1, dp[i+1][n]);
    }
    cout << dp[m][N] << endl;

    return 0;
}
