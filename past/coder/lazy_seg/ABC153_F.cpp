#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
#include <atcoder/all>
using namespace atcoder;
struct S {
    long long value;
    int size;
};
using F = long long;
S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d, a;
    cin >> n >> d >> a;
    vector<pi> mon;
    rep(i, n) {
        int x, h;
        cin >> x >> h;
        mon.push_back({x, h});
    }
    sort(all(mon));
    vector<int> si;
    for(auto [tmp,z]:mon) si.push_back(tmp);
    //si is only used to transform index
    //compress index
    si.erase(unique(all(si)), si.end());
    //sum of damage
    vector<S> z(si.size(), {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(z);
    ll ans=0;
    //manage seg'index by si
    rep(i, n) {
        auto [nx, nh]=mon[i];
        //i change to be si's index
        int idx = lower_bound(all(si), nx)-si.begin();
        ll damage = seg.get(idx).value;
        ll noko=nh-damage;
        if(noko<=0) continue;
        ll cnt=(noko+a-1)/a;
        ans+=cnt;
        ll reach=nx+2LL*d;
        int r=upper_bound(all(si), reach)-si.begin();
        seg.apply(i, r, cnt*a);
    }
    cout << ans << endl;

    return 0;
}