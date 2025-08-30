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
using Edge = tuple<int, int, int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> edge;
    rep(mi, m) {
        int k, c;
        cin >> k >> c;
        vector<int> a(k);
        rep(i, k) cin >> a[i], a[i]--;
        //スパニングツリーで十分
        sort(all(a));
        rep(i, k-1) edge.push_back({c, a[i+1], a[i]});
    }
    sort(all(edge));
    dsu uf(n);
    ll ans=0;
    int connected=0;
    for(auto [wei, u, v]:edge) if(!uf.same(u, v)) {
        uf.merge(u, v);
        ans+=wei;
        connected++;
    }
    if(connected==n-1) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}