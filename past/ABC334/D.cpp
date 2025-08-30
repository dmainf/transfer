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
    ll n, q;
    cin >> n >> q;
    vector<ll> r(n);
    //5 3 11 8
    //3 5 8 11
    //0 3 8 16 27
    rep(i, n) cin >> r[i];
    sort(all(r));
    vector<ll> pre(n+1, 0);
    rep(i, n) pre[i+1]=pre[i]+r[i];
    rep(qi, q) {
        ll query;
        cin >> query;
        ll it=upper_bound(all(pre), query)-pre.begin();
        cout << it-1 << endl;
    }


    return 0;
}
