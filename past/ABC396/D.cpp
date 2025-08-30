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
const int MAX=1e6;
struct Edge {
    int v;
    ll wei;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> G(n);
    rep(i, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    ll ans = numeric_limits<ll>::max();
    function<void(int, ll, vector<bool>&)> dfs=[&](int v, ll sum, vector<bool> seen) {
        if(v==n-1) {
            ans=min(ans, sum);
            return;
        }
        for(auto nv:G[v]){
            if(seen[nv.v]) continue;
            seen[nv.v]=true;
            dfs(nv.v, sum^nv.wei, seen);
            seen[nv.v]=false;
        }
    };
    vector<bool> seen(n, false);
    seen[0]=true;
    dfs(0, 0, seen);
    cout << ans << endl;
    return 0;
}