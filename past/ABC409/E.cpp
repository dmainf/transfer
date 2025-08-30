#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<vector<pi>> G(n);
    rep(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({w, v});
        G[v].push_back({w, u});        
    }
    ll ans=0;
    auto dfs=[&](auto dfs, int u, int p=-1) -> ll {
        ll total=x[u];
        for(auto [w, v]:G[u]) {
            if(v==p) continue;
            ll child=dfs(dfs, v, u);
            ans+=abs(child)*w;
            total+=child;
        }
        return total;
    };
    dfs(dfs, 0);
    cout << ans << endl;

    return 0;
}