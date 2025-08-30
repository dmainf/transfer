#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    int m;
    cin >> n >> m;
    vector<pair<ll, ll>> stone;
    rep(i, m) cin >> stone[i].first;
    rep(i, m) cin >> stone[i].second;
    nsort(stone);
    ll ans=0;
    int px=0;//番兵
    ll num=1;
    for(auto [x, a] : stone) {
        ll len=x-px;
        ll carry=num-len;
        ans+=(len-1)*len/2;
        ans+=len*carry;
        if(carry<0) {
            cout << -1 << endl;
            return 0;
        }
        px=x;
        num=carry;
    }
    if(num!=1) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}