#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
struct Edge {
    int wei;
    vector<pi> edge;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> G(n);
    rep(i, n) cin >> G[i].wei;
    rep(i, m) {
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].edge.push_back({b, v});
        G[v].edge.push_back({b, u});       
    }
    vector<ll> dist(n, INF);
    dist[0]=G[0].wei;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({dist[0], 0});
    while(!pq.empty()) {
        auto [w, v]=pq.top();
        pq.pop();
        if(dist[v]!=w) continue;
        for(auto u:G[v].edge) {
            ll n_wei=u.first;
            int nv=u.second;
            if(dist[v]+n_wei+G[nv].wei<dist[nv]) {
                dist[nv]=dist[v]+n_wei+G[nv].wei;
                pq.push({dist[nv], nv});
            }
        }
    }
    for(int i=1; i<n; i++) cout << dist[i] << " \n"[i==n-1];

    return 0;
}