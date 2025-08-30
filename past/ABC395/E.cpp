#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, ll>; 
const ll di[]={1,-1,0,0};
const ll dj[]={0,0,1,-1};
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, x;
    cin >> n >> m >> x;
    vector<vector<ll>> forward(n+1), back(n+1);
    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        forward[u].push_back(v);
        back[v].push_back(u);
    }
    vector<vector<long long>> dist(n+1, vector<long long>(2, INF));
    priority_queue<
        tuple<long long,ll,ll>,
        vector<tuple<long long,ll,ll>>,
        greater<tuple<long long,ll,ll>>
    > pq;
    dist[1][0]=0;
    pq.push({0, 1, 0});
    while(!pq.empty()){
        auto [cost, v, f]=pq.top();
        pq.pop();
        if(dist[v][f]<cost) continue;
        long long tmp=cost+x;
        if(tmp<dist[v][1-f]){
            dist[v][1-f]=tmp;
            pq.push({tmp, v, 1 - f});
        }
        if(f==0){
            for(ll u : forward[v]){
                long long nxtCost=cost+1;
                if(nxtCost<dist[u][0]){
                    dist[u][0]=nxtCost;
                    pq.push({nxtCost, u, 0});
                }
            }
        } else {
            for(ll u:back[v]){
                long long nxtCost=cost+1;
                if(nxtCost<dist[u][1]){
                    dist[u][1]=nxtCost;
                    pq.push({nxtCost, u, 1});
                }
            }
        }
    }
    long long ans=min(dist[n][0], dist[n][1]);
    cout << ans << endl;

    return 0;
}
