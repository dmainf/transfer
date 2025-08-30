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
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i], a[i]--;
    rep(i, m) cin >> b[i], b[i]--;
    vector<vector<int>> G(n);
    rep(i, m) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    vector<int> cnt(n, -1);
    auto dfs=[&](auto dfs, int v, int c=0) -> void {
        if(cnt[v]!=-1) return;
        cnt[v]=c;
        for(auto u:G[v]) dfs(dfs, u, c^1);
    };
    rep(v, n) if(cnt[v]==-1) {
        dfs(dfs, v);
    }
    rep(i, m) if(cnt[a[i]]==cnt[b[i]]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}
