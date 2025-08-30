#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, ll>; 
const ll di[]={1,-1,0,0};
const ll dj[]={0,0,1,-1};
const ll INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll ans=0;
    rep(i, n) ans+=a[i]*m;
    rep(i, m) ans+=b[i]*n;
    vector<ll> pre(m+1, 0);
    rep(i, m) pre[i+1]=pre[i]+b[i];
    rep(i, n) {
        ll index=upper_bound(all(b), p-a[i])-b.begin();
        ll cnt=m-index;
        ans-=(cnt*a[i]+pre[m]-pre[index])-cnt*p;
    }
    cout << ans << endl;

    return 0;
}
