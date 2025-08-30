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
    int v;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, e;
    cin >> v >> e;
    vector<vector<Edge>> G(v);
    rep(i, e) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back({w, t});
        G[t].push_back({w, s});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<bool> used(v, false);
    used[0]=true;
    for(auto u:G[0]) pq.push({u.wei, u.v});
    int ans=0;
    while(!pq.empty()) {
        auto [w, u]=pq.top();
        pq.pop();
        if(used[u]) continue;
        used[u]=true;
        ans+=w;
        for(auto nu:G[u]) {
            if(used[nu.v]) continue;
            pq.push({nu.wei, nu.v});
        }
    }
    cout << ans << endl;

    return 0;
}