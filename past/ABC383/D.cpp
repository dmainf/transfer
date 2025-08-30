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
    ll n;
    cin >> n;
    const ll MAX=1e6;
    vector<bool> num(MAX+1, true);
    num[0] = false;
    num[1] = false;
    for (ll i = 2; i * i <= MAX; i++) {
        if (num[i]) {
            for (ll j = i * i; j <= MAX; j += i) {
                num[j] = false;
            }
        }
    }
    vector<ll> prime;
    rep(i, MAX) if(num[i]) {
        prime.push_back(i);
    }
    //(8), (2, 2)
    auto p8=[&](ll x) -> ll {
        ll tmp=1;
        rep(i, 8) {
            if (tmp>n/x) return n+1;
            tmp*=x;
        }
        return tmp;
    };
    ll ans=0;
    ll Size=prime.size();
    rep(i, Size) {
        if(n<p8(prime[i])) break;
        ans++;
    }
    for(auto &x:prime) x*=x;
    ll r=Size-1;
    rep(l, Size) {
        while(l<r && (__int128)prime[l]*prime[r]>n) {
            r--;
        }
        if(!(l<r)) break;
        ans+=(r-l);
    }
    cout << ans << endl;

    return 0;
}