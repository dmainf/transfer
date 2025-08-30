#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, ll>; 
const ll di[]={1,-1,0,0};
const ll dj[]={0,0,1,-1};
const ll INF=1e9;
const ll MAX=1e6;
struct Edge {
    ll u;
    ll v;
};
struct UnionFind {
    vector<ll> parent, size;
    UnionFind(ll n) : parent(n), size(n, 1) {
        for (ll i = 0; i < n; i++) 
            parent[i] = i;
    }
    ll findRoot(ll x) {
        if (parent[x] != x) 
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    ll unite(ll x, ll y) {
        ll rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return 0;
        if (size[rx] < size[ry]) swap(rx, ry);
        ll dec=size[rx]*size[ry];
        parent[ry]=rx;
        size[rx]+=size[ry];
        return dec;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<Edge> edge(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[i]={a, b};
    }
    UnionFind uf(n);
    vector<ll> ans;
    ll now=n*(n-1)/2;
    ans.push_back(now);
    for(int i=m-1; 0<i; i--) {
        ll dec=uf.unite(edge[i].u, edge[i].v);
        now-=dec;
        ans.push_back(now);
    }
    reverse(all(ans));
    rep(i, m) cout << ans[i] << endl;

    return 0;
}