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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vector<ll> pre(n+1, 0);
    rep(i, n) pre[i+1]=pre[i]+a[i];
    vector<ll> ans;
    while(q--) {
        ll b; cin >> b;
        if(a.back()<b) {
            ans.push_back(-1);
            continue;
        }
        ll it=lower_bound(all(a), b)-a.begin();
        ans.push_back(pre[it]+(b-1)*(n-it)+1);
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}