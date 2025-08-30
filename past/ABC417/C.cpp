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
const ll INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    //j-i = a[i]+a[j]
    //i+a[i] = j-a[j]
    map<ll, ll> cnt;
    ll ans=0;
    rep(j, n) {
        ll r_val=j-a[j];
        ll l_val=j+a[j];
        ans+=cnt[r_val];
        cnt[l_val]++;
    }
    cout << ans << endl;

    return 0;
}