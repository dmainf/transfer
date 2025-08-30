#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
using ll = long long;
struct Edge {
    int to, w;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u]. push_back({v, w});
        g[v]. push_back({u, -w});
    }
    vector<bool> used(n, false);
    vector<ll> x(n);
    rep(i, n) {
        if(used[i]) continue;
        auto dfs=[&](auto dfs, int v, ll val) {
            if(used[v]) return;
            used[v]=true;
            x[v]=val;
            for(auto e:g[v]) {
                dfs(dfs, e.to, val+e.w);
            }
        };
        dfs(dfs, i, 0);
    }
    rep(i, n) cout << x[i] << " \n"[i==n-1];

    return 0;
}
