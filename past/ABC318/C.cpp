#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<ll,ll>;
const ll di[]={+1,-1,+0,+0};
const ll dj[]={+0,+0,+1,-1};
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, d, p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    rep(i, n) cin >> f[i];
    sort(all(f));
    //7 6 6 3 1
    //0 1 2 3 4
    vector<ll> pre(n+1, 0);
    rep(i, n) pre[i+1]=pre[i]+f[i];
    ll mx=(n+d-1)/d;
    ll ans=p*mx;
    rep(i, mx) ans=min(ans, pre[n-(i*d)]+(p*i));
    cout << ans << endl;

    return 0;
}