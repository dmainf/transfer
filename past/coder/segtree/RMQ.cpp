#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
ll op(ll a, ll b) { return min(a, b); }
ll e() { return (1LL<<31)-1; }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    segtree<ll, op, e> seg(n);
    vector<ll> ans;
    rep(qi, q) {
        ll com, x, y;
        cin >> com >> x >> y;
        if(com==0) seg.set(x, y);
        if(com==1) ans.push_back(seg.prod(x, y+1));
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}