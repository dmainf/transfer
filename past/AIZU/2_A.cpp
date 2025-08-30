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
    int weight;
    int from;
    int to;
    bool operator<(const Edge& rhs) const {
        return weight < rhs.weight;
    }
};
#include <atcoder/dsu>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    cin >> V >> E;
    vector<Edge> edge(E);
    dsu uf(V);
    rep(i, E) {
        int s, t, w;
        cin >> s >> t >> w;
        edge[i]={w, s, t};
    }
    sort(all(edge));
    ll ans=0;
    for(auto [w, u, v]:edge) {
        if(uf.same(u, v)) continue;
        uf.merge(u, v);
        ans+=w;
    }
    cout << ans << endl;

    return 0;
}