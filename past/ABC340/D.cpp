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
    int to;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<Edge>> G(n);
    rep(i, n-1) {
        int a, b, x;
        cin >> a >> b >> x;
        x--;
        G[i].push_back({a, i+1});
        G[i].push_back({b, x});
    }
    vector<ll> dist(n, INF);
    dist[0]=0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [w,v]=pq.top();
        pq.pop();
        if(w!=dist[v]) continue;
        for(auto u:G[v]) {
            int nv=u.to;
            ll n_wei=dist[v]+u.wei;
            if(n_wei<dist[nv]) {
                dist[nv]=n_wei;
                pq.push({n_wei, nv});
            }
        }
    }
    cout << dist[n-1] << endl;
    

    return 0;
}
