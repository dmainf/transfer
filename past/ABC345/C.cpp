#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0; i<(n); i++)
#define drep(i, n) for(ll i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    ll n=s.size();
    map<char, ll> m;
    rep(i, n) m[s[i]]++;
    ll same=0;
    for(auto num:m) {
        same+=num.second*(num.second-1)/2;
    }
    ll ans=n*(n-1)/2;
    ans-=same;
    if(same) ans++;
    cout << ans << endl;

    return 0;
}
