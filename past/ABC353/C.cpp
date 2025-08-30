#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0; i<(n); i++)
#define drep(i, n) for(ll i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll M=1e8;
    ll n;
    cin >> n;
    ll ans=0;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        ans+=a[i]*(n-1);
    }
    sort(all(a));
    ll cnt=0;
    rep(i, n-1) {
        if(a[i]+a[n-1]<M) continue;
        ll it=lower_bound(a.begin()+i+1, a.end(), M-a[i])-a.begin();
        cnt+=n-it;
    }
    cout << ans-cnt*M << endl;

    return 0;
}