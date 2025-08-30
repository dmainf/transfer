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
    vector<int> a(n), b(n*2);
    rep(i, n) cin >> a[i];
    rep(i, n*2) b[i]=a[i%n];
    vector<vector<ll>> dp(2*n, vector<ll>(2*n, -1));
    function<ll(int, int, int)> f=[&](int l, int r, int s) -> ll {//s=0:JOI s=1:IOI
        if(dp[l][r]!=-1) return dp[l][r];
        if(l==r) {
            if(s) return dp[l][r]=0;
            else return dp[l][r]=b[l];
        }
        if(s) {
            if(b[l]<b[r]) return dp[l][r]=f(l, r-1, 0);
            else return dp[l][r]=f(l+1, r, 0);
        } else {
            return dp[l][r]=max(f(l+1, r, 1)+b[l], f(l, r-1, 1)+b[r]);
        }
    };
    ll ans=0;
    rep(i, n) ans=max(ans, f(i+1, i+n-1, 1)+b[i]);
    cout << ans << endl;

    return 0;
}