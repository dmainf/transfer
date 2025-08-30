#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using Graph = vector<vector<int>>; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Graph G(n);
    rep(i, n) {
        int u, k, v;
        cin >> u >> k;
        u--;
        rep(j, k) {
            cin >> v;
            v--;
            G[u].push_back(v);
        }
    }
    vector<int> dist(n, -1);
    queue<int> que;
    dist[0]=0;
    que.push(0);
    while(!que.empty()) {
        int v=que.front();
        que.pop();
        for(auto nv:G[v]) {
            if(dist[nv]!=-1) continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }
    rep(i, n) cout << i+1 << " " << dist[i] << endl;

    return 0;
}
