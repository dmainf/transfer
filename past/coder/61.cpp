#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    rep(i, n) dp[i][i]=0;
    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        dp[a][b]=t;
        dp[b][a]=t;
    }
    rep(k, n) rep(i, n) rep(j, n) {
        if(dp[i][k]==INF || dp[k][j]==INF) continue;
        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
    }
    int ans=INF;
    rep(i, n) {
        int tmp=0;
        rep(j, n) tmp=max(tmp, dp[i][j]);
        ans=min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
