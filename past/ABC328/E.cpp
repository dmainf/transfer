#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
struct Edge {
    ll wei;
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
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<Edge> edge(m);
    rep(i, m) {
        cin >> edge[i].u >> edge[i].v >> edge[i].wei;
        edge[i].u--;
        edge[i].v--;
    }
    vector<int> p(m, 1);
    rep(i, m-(n-1)) p[i]=0;
    ll ans=k;
    do {
        UnionFind uf(n);
        ll tmp=0;
        int cnt=1;
        rep(bit, m) if(p[bit]==1) {
            if(uf.unite(edge[bit].u, edge[bit].v)) {
                tmp=(tmp+edge[bit].wei)%k;
                cnt++;
            }
        }
        if(cnt==n) ans=min(ans, tmp);
    } while(next_permutation(all(p)));

    cout << ans << endl;

    return 0;
}