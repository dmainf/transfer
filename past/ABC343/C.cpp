#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
ll f(ll x) {
    ll low=0, high=1e6;
    while(low<=high) {
        ll mid=(low+high)/2;
        if(mid*mid*mid<=x) low=mid+1;
        else high=mid-1;
    }
    return low-1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    n=f(n);
    for(ll i=n; i>=0; i--) {
        ll k=i*i*i;
        string s=to_string(k);
        string pre=s.substr(0, s.size()/2);
        string suf;
        if(s.size()%2==0) suf=s.substr(s.size()/2, s.size()/2);
        else suf=s.substr(s.size()/2+1, s.size()/2);
        reverse(suf.begin(), suf.end());
        if(pre==suf) {
            cout << k << endl;
            return 0;
        }
    }

    return 0;
}
