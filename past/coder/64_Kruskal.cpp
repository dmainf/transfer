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
struct Edge {
    int wei;
    int u;
    int v;
};
struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
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
    int v, e;
    cin >> v >> e;
    vector<Edge> edge(e);//about edge
    rep(i, e) {
        int s, t, w;
        cin >> s >> t >> w;
        edge[i].wei=w;
        edge[i].u=s;
        edge[i].v=t;
    }
    sort(all(edge), [](Edge a, Edge b) {
        return a.wei<b.wei;
    });
    UnionFind uf(v);
    int ans=0;
    rep(i, e) if(uf.unite(edge[i].u, edge[i].v)) {
        ans+=edge[i].wei;
    }
    cout << ans << endl;

    return 0;
}
