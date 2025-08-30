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
struct Edge {
    int to;
    int wei;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e, r;
    cin >> n >> e >> r;
    vector<vector<Edge>> G(n);
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }
    vector<int> dist(n, INF);
    dist[r]=0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, r});
    while(!pq.empty()) {
        auto [w, v]=pq.top();
        pq.pop();
        if(w!=dist[v]) continue;
        for(auto e:G[v]) {
            int u=e.to;
            int nw=w+e.wei;
            if(nw<dist[u]) {
                dist[u]=nw;
                pq.push({nw, u});
            }
        }
    }
    rep(i, n) {
        if(dist[i]==INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}
