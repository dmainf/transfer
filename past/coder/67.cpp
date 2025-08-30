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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<pair<int,int>> vx(n), vy(n);
    rep(i, n) {
        vx[i] = {x[i], i};
        vy[i] = {y[i], i};
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vector<vector<Edge>> G(n);
    //sharing x-index and y-index is important
    rep(i, n) {
        int u = vx[i].second, v = vx[i+1].second;
        int cost = abs(vx[i+1].first - vx[i].first);
        G[u].push_back({cost, v});
        G[v].push_back({cost, u});
    }
    rep(i, n) {
        int u = vy[i].second, v = vy[i+1].second;
        int cost = abs(vy[i+1].first - vy[i].first);
        G[u].push_back({cost, v});
        G[v].push_back({cost, u});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> used(n, false);
    for(auto u:G[0]) pq.push({u.wei, u.v});
    used[0]=true;
    int ans=0;
    int count=-1;
    while(!pq.empty() && count<n) {
        auto [w, u]=pq.top();
        pq.pop();
        if(used[u]) continue;
        used[u]=true;
        ans+=w;
        count++;
        for(auto nu:G[u]) {
            if(used[nu.v]) continue;
            pq.push({nu.wei, nu.v});
        }
    }
    cout << ans << endl;

    return 0;
}