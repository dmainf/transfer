#include <bits/stdc++.h>
using namespace std;
#define rep(nv,n) for(ll nv=0;nv<(n);nv++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const ll di[]={+1,-1,+0,+0};
const ll dj[]={+0,+0,+1,-1};
const ll INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<vector<ll>> G(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> dp(n);
    auto dfs=[&](auto dfs, ll v, ll pre=-1) -> void {
        dp[v]=1;
        for(ll nv:G[v]) {
            //practically seem to directed edges, dont back to parent
            if(nv!=pre) {
                dfs(dfs, nv, v);
                dp[v]+=dp[nv];
            }
        }
    };
    dfs(dfs, 0);
    ll ans=0;
    rep(v, n) for(ll nv:G[v]) {
        if(dp[nv]<dp[v]) ans+=dp[nv]*(n-dp[nv]);
    }
    cout << ans << endl;

    return 0;
}