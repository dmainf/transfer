#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using Graph = vector<vector<int>>;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
struct Edge{
    int to;
    int wei;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<Edge>> G(n);
    auto dijkstra=[&](vector<vector<Edge>> &G, int a, int b) -> void {
        vector<int> dist(n, -1);
        dist[a]=0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, a});
        while(!pq.empty()) {
            auto [w, v]=pq.top();
            pq.pop();
            if(w!=dist[v]) continue;
            for(auto u:G[v]) {
                int nv=u.to;
                int n_wei=w+u.wei;
                if(n_wei<dist[nv] || dist[nv]==-1) {
                    dist[nv]=n_wei;
                    pq.push({n_wei, nv});
                }
            }
        }
        cout << dist[b] << endl;
    };
    rep(i, k) {
        int x;
        cin >> x;
        if(x) {
            int c, d, e;
            cin >> c >> d >> e;
            c--; d--;
            G[c].push_back({d, e});
            G[d].push_back({c, e});
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            dijkstra(G, a, b);
        }
    }

    return 0;
}