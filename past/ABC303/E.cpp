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
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root=-1;
    rep(i, n) if(G[i].size()==1) {
        root=i;
    }
    vector<int> ans;
    auto dfs=[&](auto dfs, int v,int p=-1, int d=0) -> void {
        if(d%3==1) ans.push_back(G[v].size());
        for(int nv:G[v]) if(nv!=p) {
            dfs(dfs, nv, v, d+1);
        };
    };
    dfs(dfs, root);
    sort(all(ans));
    for(int x:ans) cout << x << " ";
    cout << endl;

    return 0;
}