#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(k, n) rep(i, n) rep(j, n) {
        if(a[i][j]>a[i][k]+a[k][j]) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans=0;
    rep(i, n) rep(j, n) if(i<j) {
        bool flag=true;
        rep(k, n) {
            if(i==k || j==k) continue;
            //最短であることは前で保証されている
            if(a[i][j]==a[i][k]+a[k][j]) flag=false;
        }
        if(flag) ans+=a[i][j];
    }
    cout << ans << endl;

    return 0;
}