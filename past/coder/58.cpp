#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, int>; 
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
    int n, m, k, s;
    cin >> n >> m >> k >>s;
    int p, q;
    cin >> p >> q;
    vector<bool> zombie(n, false);
    rep(i, k) {
        int c;
        cin >> c;
        c--;
        zombie[c]=true;
    }
    vector<vector<int>> G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(n, INF);
    queue<int> que;
    rep(i, n) {
        if(zombie[i]) {
            dist[i]=0;
            que.push(i);//ゾンビ都市を一気にやっちゃう
        }
    }
    while(!que.empty()) {
        int v=que.front();
        que.pop();
        if(dist[v]>=s) continue;
        for(auto nv:G[v]) {
            if(dist[v]+1<dist[nv]) {//一つでも短かったらゾンビ来る
                dist[nv]=dist[v]+1;
                que.push(nv);
            }
        }
    }
    vector<int> danger(n, false);
    rep(i, n) if(!zombie[i] && dist[i]<=s) {
        danger[i]=true;
    }
    vector<ll> cost(n, 1e16);
    cost[0]=0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [w, v]=pq.top();
        pq.pop();
        if(w!=cost[v]) continue;
        for(auto nv:G[v]) {
            if(zombie[nv]) continue;
            int c;
            if(danger[nv]) c=q;
            else c=p;
            if(nv==n-1) c=0;
            if(cost[nv]>cost[v]+c) {
                cost[nv]=min(cost[nv], cost[v]+c);
                pq.push({cost[nv], nv});
            }
        }
    }
    cout << cost[n-1] << endl;

    return 0;
}