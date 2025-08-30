#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pl=pair<ll,ll>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const ll INF=(1LL<<60);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pl>> G(n);
    rep(i, m) {
        ll u, v, wei;
        cin >> u >> v >> wei;
        u--; v--;
        G[u].push_back({wei, v});
        G[v].push_back({wei, u});
    }
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0, 0});
    vector<ll> dist(n, INF);
    dist[0]=0;
    while(!pq.empty()) {
        auto [wei, v]=pq.top();
        pq.pop();
        if(wei!=dist[v]) continue;
        for(auto [n_wei, nv]:G[v]) {
            ll nor=dist[v]|n_wei;
            if(nor<dist[nv]) {
                dist[nv]=nor;
                pq.push({nor, nv});
            }
        }
    }
    cout << dist[n-1] << endl;

    return 0;
}