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
struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
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
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
            rank[ry]+=rank[rx];
        } else {
            parent[ry] = rx;
            rank[rx]+=rank[ry];
        }
        return true;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    UnionFind uf(n);
    rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(u==0 || v==0) continue;
        uf.unite(u, v);
    }
    int ms=0;
    rep(i, n) if(uf.findRoot(i)==i) {
        ms=max(ms, uf.rank[i]);
    }
    cout << n-ms << endl;

    return 0;
}
