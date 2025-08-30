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
using S = long long;
using F = long long;
const S INF = 8e18;
S op(S a, S b){ return max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    rep(i, n) {
        int a;
        cin >> a;
        seg.set(i, a);
    }
    rep(i, m) {
        int b;
        cin >> b;
        ll stone=seg.get(b);
        seg.set(b, 0);
        seg.apply(0, n, stone/n);
        stone%=n;
        if(stone==0) continue;
        int start=(b+1)%n;//if n-1, suppose 0
        if(n<start+stone) {
            seg.apply(start, n, 1);
            seg.apply(0, (start+stone)%n, 1);
        } else {
            seg.apply(start, start+stone, 1);
        }
    }
    rep(i, n) cout << seg.get(i) << (i!=n-1 ? " " : "\n");

    return 0;
}