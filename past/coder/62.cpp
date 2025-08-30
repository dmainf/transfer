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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> dp(10, vector<int>(10));
    rep(i, 10) rep(j, 10) cin >> dp[i][j];
    rep(k, 10) rep(i, 10) rep(j, 10) {
        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
    }
    int ans=0;
    rep(i, h) rep(j, w) {
        int a;
        cin >> a;
        if(a==-1) continue;
        ans+=dp[a][1];
    }
    cout << ans << endl;

    return 0;
}
