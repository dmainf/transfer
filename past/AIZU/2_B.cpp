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
#include <atcoder/dsu>
using namespace atcoder;
struct Edge {
    int weight;
    int from;
    int to;
    bool operator<(const Edge& rhs) const {
        return weight < rhs.weight;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E, r;
    cin >> V >> E >> r;
    vector<Edge> edge(E);
    rep(i, E) {
        int s, t, w;
        cin >> s >> t >> w;
        edge[i] = {w, s, t};
    }
    ll ans=0;
    while(true) {
        vector<int> in_cost(V, INF), in_from(V, -1);
        for (auto [w, v, nv]:edge) {
            if(v!=nv && w<in_cost[nv]) {
                in_cost[nv]=w;
                in_from[nv]=v;
            }
        }
        in_cost[r]=0;
        vector<int> vis(V, -1), id(V, -1);
        int idx=0;
        rep(i, V) {
            int v=i;
            while(vis[v]==-1 && v!=r) {
                vis[v]=i;
                v=in_from[v];
            }
            if(v!=r && vis[v]==i) {
                for(int u=in_from[v]; u!=v; u=in_from[u]) {
                    id[u]=idx;
                }
                id[v]=idx++;
            }
        }
        if(idx==0) {
            rep(i, V) ans+=in_cost[i];
            break;
        }
        rep(i, V) {
            if(id[i]==-1) id[i]=idx++;
        }
    
        vector<Edge> new_edges;
        for (auto [w, v, nv]:edge) {
            int from=id[nv];
            int to=id[nv];
            if (from!=to) {
                int new_cost=w-in_cost[nv];
                new_edges.push_back({from, to, new_cost});
            }
        }
        V=idx;
        r=id[r];
        edge=new_edges;
    }
    cout << ans << endl;
    return 0;
}