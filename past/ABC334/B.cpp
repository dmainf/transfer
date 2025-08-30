#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    l-=a; r-=a;
    if(l<0) {
        ll x=-l/m+1;
        l+=x*m; r+=x*m;
    }
    auto f=[&](ll r, ll m) { return r/m; };
    ll ans=f(r, m)-f(l-1, m);
    cout << ans << endl;

    return 0;
}