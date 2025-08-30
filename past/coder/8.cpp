#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define drep(i, n) for(int i=(n)-1;i>=0;i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int n;
vector<int> a(39), b(39);
using ll = long long;
long long solve(int x, int y) {
    long long ans=0;
    rep(i, n) {
        ans+=abs(x-a[i]);
        ans+=abs(a[i]-b[i]);
        ans+=abs(y-b[i]);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rep(i, n) cin >> a[i] >> b[i];
    vector<int> v;
    long long ans=1e18;
    rep(i, n) v.push_back(a[i]);
    rep(i, n) v.push_back(b[i]);
    for(long long i:v) for(long long j:v) {
        ans=min(ans, solve(i, j));
    }
    cout << ans << endl;

    return 0;
}
