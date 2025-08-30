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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll now=0;
    rep(i, n) now+=min(a[i], b[i]);
    vector<ll> ans;
    while(q--) {
        char c;
        ll x, v;
        cin >> c >> x >> v;
        x--;
        //now-tmp+v
        //now-(tmp-v)
        now-=min(a[x], b[x]);
        if(c=='A') a[x]=v;
        if(c=='B') b[x]=v;
        now+=min(a[x], b[x]);
        ans.push_back(now);
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}