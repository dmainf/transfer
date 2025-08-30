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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, e;
    cin >> v >> e;
    vector<vector<ll>> dp(v, vector<ll>(v, INF));
    rep(i, v) dp[i][i]=0;
    rep(i, e) {
        int s, t;
        ll d;
        cin >> s >> t >> d;
        dp[s][t]=d;
    }
    rep(k, v) rep(i, v) rep(j, v) {
        if(dp[i][k]==INF || dp[k][j]==INF) continue;
        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
    }
    rep(i, v) if(dp[i][i]<0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep(i, v) rep(j, v) {
        if(dp[i][j]!=INF) cout << dp[i][j] << " \n"[j==v-1];
        else cout << "INF" << " \n"[j==v-1];
    }

    return 0;
}