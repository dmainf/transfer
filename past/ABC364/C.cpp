#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nall(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define nfor(i,s,n) for(int i=s; i<n; i--)
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    ll sumx=0, sumy=0;
    rep(i, n) {
        sumx+=a[i]; sumy+=b[i];
        if(sumx>x || sumy>y) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}
