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
    int n, q;
    cin >> n >> q;
    Graph G(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ans(n); 
    function<void(int, int)> dfs = [&](int v, int p) {
        for(auto nv:G[v]) {
            if(nv==p) continue;
            ans[nv]+=ans[v];
            dfs(nv, v);
        }
    };
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        p--;
        ans[p]+=x;
    }
    dfs(0, -1);
    rep(i, n) cout << ans[i] << endl;

    return 0;
}
