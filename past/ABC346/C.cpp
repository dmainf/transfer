#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    ll ans=k*(k+1)/2;
    set<ll> st;
    rep(i, n) {
        ll a;
        cin >> a;
        if(1<=a && a<=k) st.insert(a);
    }
    for(auto x:st) ans-=x;
    cout << ans << endl;

    return 0;
}