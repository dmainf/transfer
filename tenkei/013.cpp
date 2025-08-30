#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> G(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({c, b});
        G[b].push_back({c, a});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq_f;
    pq_f.push({0, 0});
    vector<int> dist_for(n, INF);
    dist_for[0]=0;
    while(!pq_f.empty()) {
        auto [w, v]=pq_f.top();
        pq_f.pop();
        if(dist_for[v]!=w) continue;
        for(auto [nw, nv]:G[v]) {
            nw+=w;
            if(nw>=dist_for[nv]) continue;
            dist_for[nv]=nw;
            pq_f.push({nw, nv});
        }
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq_b;
    pq_b.push({0, n-1});
    vector<int> dist_back(n, INF);
    dist_back[n-1]=0;
    while(!pq_b.empty()) {
        auto [w, v]=pq_b.top();
        pq_b.pop();
        if(dist_back[v]!=w) continue;
        for(auto [nw, nv]:G[v]) {
            nw+=w;
            if(nw>=dist_back[nv]) continue;
            dist_back[nv]=nw;
            pq_b.push({nw, nv});
        }
    }
    rep(k, n) {
        cout << dist_for[k]+dist_back[k] << endl;
    }

    return 0;
}