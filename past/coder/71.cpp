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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MOD=1000000007;
    int n, q;
    cin >> n >> q;
    vector<int> a(n), c(q);
    rep(i, n) cin >> a[i];
    rep(i, q) {
        int tmp;
        cin >> tmp;
        tmp--;
        c[i]=tmp;
    }
    auto modpow=[&](ll m, ll n) -> int {
        ll res=1;
        while(0<n) {
            if(n&1) res=res*m%MOD;
            m=m*m%MOD;
            n>>=1;
        }
        return res;
    };
    //*--*--*--*
    vector<int> dist(n-1);
    rep(i, n-1) {
        dist[i]=modpow(a[i], a[i+1]);
    }
    vector<ll> prefix(n, 0);
    prefix[0] = 0;
    rep(i, n) prefix[i+1] = (prefix[i]+dist[i])%MOD;
    vector<int> route;
    route.push_back(0);
    for (int x:c) route.push_back(x);
    route.push_back(0);
    ll ans=0;
    rep(i, route.size()-1) {
        int u=route[i], v=route[i+1];
        int L=min(u, v), R=max(u, v);
        ll tmp=(prefix[R]-prefix[L]+MOD) % MOD;
        ans=(ans+tmp)%MOD;
    }

    cout << ans << endl;

    return 0;
}
