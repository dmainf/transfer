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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    struct TAXI {
        int cost;
        int range;
    };
    vector<TAXI> taxi(n);
    rep(i, n) {
        int c, r;
        cin >> c >> r;
        taxi[i].cost=c;
        taxi[i].range=r;
    }
    vector<vector<int>> G(n);
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);        
    }
    //dijkstra
    vector<int> dp(n, INF);
    dp[0]=0;
    vector<bool> used(n, false);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [c, v]=pq.top();
        pq.pop();
        if(c!=dp[v]) continue;
        if(used[v]) continue;
        used[v]=true;
        //bfs
        vector<int> dist(n, INF);
        queue<int> que;
        dist[v]=0;
        que.push(v);
        while(!que.empty()) {
            int u=que.front();
            que.pop();
            if(dist[u]>=taxi[v].range) continue;
            for(int nu:G[u]) {
                if(dist[u]+1<dist[nu]) {
                    dist[nu]=dist[u]+1;
                    if(dist[nu]<=taxi[v].range) que.push(nu);
                }
            }
        }
        //
        rep(i, n) {
            if(taxi[v].range<dist[i]) continue;
            int n_cost=dp[v]+taxi[v].cost;
            if(n_cost<dp[i]) {
                dp[i]=n_cost;
                pq.push({dp[i], i});
            }
        }
    }
    //dijkstra
    cout << dp[n-1] << endl;

    return 0;
}