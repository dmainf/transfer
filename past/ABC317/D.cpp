#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
const int MAX=1e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int taka=0, ao=0;
    vector<pi> vote;
    rep(i, n) {
        int x, y, earn;
        cin >> x >> y >> earn;
        if(x<y) {
            ao+=earn;
            int cost=(y-x)/2+1;
            vote.push_back({earn, cost});
        } else taka+=earn;
    }
    if(ao<taka) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll>> dp(vote.size()+1, vector<ll>(MAX+1, INF));
    dp[0][0]=0;
    rep(i, vote.size()) {
        auto [earn, cost]=vote[i];
        for(int j=0; j<=MAX; j++) {
            dp[i+1][j]=dp[i][j];
            if(0<=j-earn) dp[i+1][j]=min(dp[i+1][j], dp[i][j-earn]+cost);
        }
    }
    ll ans=INF;
    for(int i=(ao-taka)/2+1; i<=MAX; i++) {
        ans=min(ans, dp[vote.size()][i]);
    }
    cout << ans << endl;

    return 0;
}
