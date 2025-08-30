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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, n) {
        if(G[i].size()!=2) {
            cout << "No" << endl;
            return 0;
        }
    }
    vector<bool> seen(n, false);
    auto dfs=[&](auto dfs, int v) -> void {
        seen[v]=true;
        for(auto nv:G[v]) {
            if(seen[nv]) continue;
            dfs(dfs, nv);
        }
    };
    dfs(dfs, 0);
    bool flag=true;
    rep(i, n) if(!seen[i]) flag=false;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}