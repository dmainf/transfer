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
    int n, m;
    cin >> n >> m;
    vector<int> p;
    p.push_back(0);
    rep(i, n) {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    vector<ll> q;
    rep(i, n+1) rep(j, n+1) q.push_back(p[i]+p[j]);
    sort(all(q));
    ll ans=0;
    rep(i, q.size()) {
        if(m<q[i]) continue;
        ll tmp=m-q[i];
        auto it=upper_bound(all(q), tmp)-q.begin();
        ans=max(ans, q[i]+q[it-1]);
    }
    cout << ans << endl;

    return 0;
}
