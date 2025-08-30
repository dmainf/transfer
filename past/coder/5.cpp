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
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans=1e9;
    rep(i, 2*max(x, y)) {
        ans=min(2*c*i+max(0, x-i)*a+max(0, y-i)*b, ans);
    }
    cout << ans << endl;
    return 0;
}
