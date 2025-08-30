#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h(n), s(n);
    rep(i, n) cin >> h[i] >> s[i];
    ll low=0, high=0;
    rep(i, n) {
        low=max(low, (ll)h[i]);
        high=max(high, (ll)h[i]+(ll)s[i]*(n-1));
    }
    auto f=[&](ll x) -> bool {//高さx
        vector<ll> dl(n);//風船ごとのデッドライン(秒)
        rep(i, n) {
            if(x<h[i]) return false;
            dl[i]=(x-h[i])/s[i];
        }
        sort(all(dl));
        rep(i, n) if(dl[i]<i) {
            return false;
        }
        return true;
    };
    ll ans=high;
    while(low<=high) {
        ll mid=(low+high)/2;
        if(f(mid)) {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout << ans << endl;

    return 0;
}