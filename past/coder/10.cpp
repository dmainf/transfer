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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int q;
    cin >> q;
    auto solve=[&](int m) -> bool {
        rep(x, (1<<n)) {
            int sum=0;
            rep(bit, n) if((x>>bit)&1) {
                sum+=a[bit];
            }
            if(sum==m) return true;
        }
        return false;
    };
    rep(i, q) {
        int m;
        cin >> m;
        if(solve(m)) Yes;
        else No;
    }

    return 0;
}
