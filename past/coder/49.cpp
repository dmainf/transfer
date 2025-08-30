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
    int n, e;
    cin >> n >> e;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t]=d;
    }
    vector<vector<int>> dp(1<<n, vector<int>(n, -1));
    function<int(int, int)> f=[&](int s, int v) -> int {
        if(dp[s][v]!=-1) return dp[s][v];
        if (s==(1<<v)) {//vだけ訪問してる状態
            if(v==0) return dp[s][0]=0;
            else return dp[s][v] = INF;
        }
        int ans=INF;
        int pre_s =s&~(1<<v);
        rep(u, n) {//vに行きたいときどこから(u)行くか
            if(!(pre_s&(1<<u))) continue;
            if(dist[u][v]==INF) continue;
            ans=min(ans, f(pre_s, u)+dist[u][v]);
        }
        return dp[s][v]=ans;
    };
    int ans=INF;
    rep(i, n) {//どの都市から都市0に戻るか
        if(dist[i][0]==INF) continue;
        ans=min(ans, f((1<<n)-1, i)+dist[i][0]);
    }
    cout << (ans==INF ? -1:ans) << endl;

    return 0;
}