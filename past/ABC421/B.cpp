#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, y;
    cin >> x >> y;
    vector<ll> a(10);
    a[0]=x;
    a[1]=y;
    auto f=[&](ll x) {
        string s=to_string(x);
        reverse(s.begin(), s.end());
        return stoll(s);
    };
    for(int i=2; i<10; i++) {
        a[i]=f(a[i-1]+a[i-2]);
    }
    cout << a[9] << endl;

    return 0;
}