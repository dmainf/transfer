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
    vector<vector<int>> G(n), rG(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        rG[b].push_back(a);
    }

    vector<bool> seen(n, false);
    vector<int> order;  //トポロジカルソート順
    auto dfs=[&](auto dfs, int v) -> void {
        seen[v]=true;
        for(int nv:G[v]) {
            if(seen[nv]) continue;
            dfs(dfs, nv);
        }
        order.push_back(v);
    };

    vector<bool> rseen(n, false);
    ll cnt;
    auto rdfs=[&](auto rdfs, int v) -> void {
        rseen[v]=true;
        cnt++;
        for(int nv:rG[v]) {
            if(rseen[nv]) continue;
            rdfs(rdfs, nv);
        }
    };

    rep(v, n) if(!seen[v]) {
        dfs(dfs, v);
    }
    ll ans=0;
    reverse(all(order));
    for(int v:order) if(!rseen[v]) {
        cnt=0;
        rdfs(rdfs, v);
        ans+=cnt*(cnt-1LL)/2LL;     //cntの点はすべて行き来できる
    }

    cout << ans << endl;

    return 0;
}