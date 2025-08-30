#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using Graph = vector<vector<int>>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Graph G(n);
    rep(i, n) {
        int u, k; 
        cin >> u >> k;
        u--;
        rep(j, k) {
            int v; cin >> v; v--;
            G[u].push_back(v);
        }
    }
    vector<bool> seen(n, false);
    vector<int> first(n), last(n);
    int time=1;
    function<void(const Graph&, int)> dfs = [&](const Graph& G, int v) {
        seen[v]=true;
        first[v]=time++;
        for(auto next_v:G[v]) {
            if(seen[next_v]) continue;
            dfs(G, next_v);
        }
        last[v]=time++;
    };
    rep(i, n) if(!seen[i]) {
        dfs(G, i);
    }
    rep(i, n) cout << i+1 << " " << first[i] << " " << last[i] << endl;

    return 0;
}
