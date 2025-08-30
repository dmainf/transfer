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
#include <atcoder/all>
using namespace atcoder;
struct S {
    long long value;
    int size;
};
using F = long long;
const F ID = 8e18;
S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) {
    if (f != ID) x.value = f * x.size;
    return x;
}
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<S> z(n, {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(z);
    vector<int> ans;
    while(q--) {
        int com, s, t;
        cin >> com >> s >> t;
        if(com==0) {
            int x;
            cin >> x;
            seg.apply(s, t+1, x);
        }
        if(com==1)
            ans.push_back(seg.prod(s, t+1).value);
        }
    for(auto x:ans) cout << x << endl;

    return 0;
}