#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define drep(i, n) for(int i=(n)-1;i>=0;i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans=1e18;
    rep(x, 1<<n) {
        if(__builtin_popcount(x)<k) continue;
        vector<int> b=a;
        ll cost=0;
        int max_val=0;
        rep(i, n) {
            if(x>>i&1) {
                if(b[i]<=max_val) {
                    cost+=max_val+1-b[i];
                    b[i]=max_val+1;
                }
            }
            max_val=max(max_val, b[i]);
        }
        ans=min(ans, cost);
    }
    cout << ans << endl;

    return 0;
}
