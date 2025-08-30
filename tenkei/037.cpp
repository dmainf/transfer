#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const ll di[]={+1,-1,+0,+0};
const ll dj[]={+0,+0,+1,-1};
const ll INF=1e18;
struct Banquet {
    ll l;
    ll r;
    ll v;
};
#include <atcoder/segtree>
using namespace atcoder;
ll op(ll a, ll b) { return max(a, b); }
ll e() { return -INF; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll W, n;
    cin >> W >> n;
    vector<Banquet> banq(n);
    rep(i, n) {
        ll l, r, v;
        cin >> l >> r >> v;
        banq[i]={l, r, v};
    }
    vector<ll> dp(W+1, -INF);
    dp[0]=0;
    for(auto [l, r, v]:banq) {
        segtree<ll, op, e> seg(W+1);
        rep(w, W+1) seg.set(w, dp[w]);
        auto ndp=dp;
        rep(w, W+1) {
            ll L=max(0LL, w-r), R=w-l;
            if(R<0) continue;
            ll now=seg.prod(L, R+1);
            if(now==-INF) continue;
            ndp[w]=max(ndp[w], now+v);
        }
        dp=ndp;
    }
    if(dp[W]==-INF) cout << -1 << endl;
    else cout << dp[W] << endl;

    return 0;
}