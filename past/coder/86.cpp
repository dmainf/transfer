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
const int MAX=1e6;
struct Edge {
    int u, v;
};
struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
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
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
        return true;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> edge(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[i]={a, b};
    }
    int ans=0;
    rep(i, m) {
        UnionFind uf(n);
        rep(j, m) if(i!=j) {
            uf.unite(edge[j].u, edge[j].v);
        }
        bool flag=false;
        rep(j, n) if(uf.findRoot(j)!=uf.findRoot(0)) {
            flag=true;
        }
        if(flag) ans++;
    }
    cout << ans << endl;

    return 0;
}
