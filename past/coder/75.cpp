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
const int MOD=1e9+7;
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    auto modpow=[&](ll base, ll exp) {
        ll res=1;
        while(exp) {
            if(exp&1) res=res*base%MOD;
            base=base*base%MOD;
            exp>>=1;
        }
        return res;
    };
    vector<int> subtree(n);
    function<int(int, int)> dfs=[&](int v, int parent) {
        subtree[v]=1;
        for(int u:G[v]) {
            if(u==parent) continue;
            subtree[v]+=dfs(u, v);
        }
        return subtree[v];
    };
    dfs(1, 0);
    ll inv=modpow(2, MOD-2);
    vector<ll> inv2(n+1, 1);
    for(int i=1; i<=n; i++) inv2[i]=(inv2[i-1]*inv)%MOD;
    

    return 0;
}
