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
const ll MOD=1e9;
struct UnionFind {
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (size[rx] < size[ry]) {
            parent[rx] = ry;
            size[ry] += size[rx];
        } else {
            parent[ry] = rx;
            size[rx] += size[ry];
        }
        return true;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    const int INF = n+1;
    vector<int> mn(n+1, INF);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        G[v].push_back(u);
        mn[v] = min(mn[v], u);
    }
    
    vector<bool> conn(n+1, false);
    UnionFind dsu(n+1);
    conn[1] = true;
    for (int i = 2; i <= n; i++){
        for (int u : G[i]){
            dsu.unite(u, i);
        }
        if (dsu.findRoot(1) == dsu.findRoot(i) && dsu.size[dsu.findRoot(1)] == i)
            conn[i] = true;
        else
            conn[i] = false;
    }    
    vector<int> diff(n+2, 0);
    for (int v = 2; v <= n; v++){
        if(mn[v] <= n){
            int L = mn[v];
            int R = v - 1;
            diff[L] += 1;
            diff[R+1] -= 1;
        }
    }
    vector<int> cum(n+1, 0);
    cum[1] = diff[1];
    for (int k = 2; k <= n; k++){
        cum[k] = cum[k-1] + diff[k];
    }
    for (int k = 1; k <= n; k++){
        if(conn[k])
            cout << cum[k] << endl;
        else
            cout << -1 << endl;
    }
    
    return 0;
}