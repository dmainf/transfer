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
struct Edge {
    int from;
    int to;
    int wei;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, e, r;
    cin >> V >> e >> r;
    vector<Edge> edge(e);
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        edge[i]={s, t, d};
    }    
    vector<int> dist(V, INF);
    dist[r]=0;
    rep(i, V-1) {
        for(auto [v, nv, w]:edge) {
            if(dist[v]==INF) continue;
            dist[nv]=min(dist[nv], dist[v]+w);
        }
    }
    for(auto [v, nv, w]:edge) {
        if(dist[v]==INF) continue;
        //yet can update dist[]
        if(dist[nv]>dist[v]+w) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;    
        }
    }
    rep(i, V) {
        if(dist[i]==INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}