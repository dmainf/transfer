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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> v(k);
    rep(i, k) cin >> v[i], v[i]--;
    vector<bool> need(n, false);
    rep(i, k) need[v[i]]=true;
    vector<bool> select(n);
    auto dfs=[&](auto dfs, int v, int p=-1) -> void {
        if(need[v]) select[v]=true;
        for(auto u:G[v]) {
            if(u==p) continue;
            dfs(dfs,u,v);
            select[v] = select[v] || select[u];
        }
    };
    dfs(dfs, v[0]);
    int ans=0;
    rep(i, n) if(select[i]) {
        ans++;
    }
    cout << ans << endl;

    return 0;
}
