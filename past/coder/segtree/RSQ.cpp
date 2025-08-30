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
int op(int a, int b) { return a+b; }
int e() { return 0; }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    segtree<int, op, e> seg(n);
    vector<int> ans;
    rep(qi, q) {
        int com, x, y;
        cin >> com >> x >> y;
        x--;
        //practically y++
        if(com==0) seg.set(x, seg.get(x)+y);
        if(com==1) ans.push_back(seg.prod(x, y));
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}