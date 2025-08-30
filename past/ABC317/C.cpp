#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int, ll>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> G(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    ll ans=0;
    rep(start, n) {
        vector<ll> dist(n, -1);
        dist[start]=0;
        auto dfs=[&](auto dfs, int v) -> void {
            rep(i, n) ans=max(ans, dist[i]);
            for(auto [nv, nc]:G[v]) {
                if(dist[nv]!=-1) continue;
                dist[nv]=dist[v]+nc;
                dfs(dfs, nv);
                dist[nv]=-1;
            }
        };
        dfs(dfs, start);
    }
    cout << ans << endl;

    return 0;
}