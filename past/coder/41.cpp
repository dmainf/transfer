#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int d, n;
    cin >> d >> n;
    vector<int> t(d), a(n), b(n), c(n);
    rep(i, d) cin >> t[i];
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(d, vector<int>(n, -1));
    //dp[i][j]
    //i日に服jを選んだときの合計の最大値
    rep(i, n) if(a[i]<=t[0] && t[0]<=b[i]) {
        dp[0][i]=0;
    }
    for(int i=1; i<d; i++) {
        rep(j, n) {
            if(!(a[j]<=t[i] && t[i]<=b[j])) continue;
            rep(k, n) {
                if(dp[i-1][k]==-1) continue;
                dp[i][j]=max(dp[i][j], dp[i-1][k]+abs(c[j]-c[k]));
            }
        }
    }
    int ans=0;
    rep(i, n) ans=max(ans, dp[d-1][i]);
    cout << ans << endl;

    return 0;
}