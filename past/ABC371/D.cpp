#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
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
    vector<int> x(n);
    vector<int> p(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> p[i];
    vector<ll> summ(n+1, 0);
    rep(i, n) summ[i+1]=summ[i]+p[i];
    int q;
    cin >> q;
    rep(qi, q) {
        int l, r;
        cin >> l >> r;
        auto L=lower_bound(all(x), l)-x.begin();
        auto R=upper_bound(all(x), r)-x.begin();
        cout << summ[R]-summ[L] << endl;
    }

    return 0;
}
