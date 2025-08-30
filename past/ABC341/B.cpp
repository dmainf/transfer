#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n-1) {
        ll s, t;
        cin >> s >> t;
        ll d=a[i]/s;
        a[i+1]+=t*d;
    }
    cout << a[n-1] << endl;

    return 0;
}