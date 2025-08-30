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
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans=0; 
    rep(i, n) {
        ll cntA=lower_bound(all(a), b[i])-a.begin();
        ll cntB=c.size()-(upper_bound(all(c), b[i])-c.begin());
        ans+=cntA*cntB;
    }
    cout << ans << endl;

    return 0;
}
