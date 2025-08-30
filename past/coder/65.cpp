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
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> edge(m);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edge[i].u=a;
        edge[i].v=b;
        edge[i].wei=c;
    }
    sort(all(edge), [](Edge a, Edge b) {
        return a.wei<b.wei;
    });
    int cnt_v=n;
    int ans=0;
    UnionFind uf(n);
    rep(i, m) {
        if(cnt_v<=k) continue;
        if(uf.unite(edge[i].u, edge[i].v)) {
            ans+=edge[i].wei;
            cnt_v--;
        }
    }
    cout << ans << endl;

    return 0;
}
