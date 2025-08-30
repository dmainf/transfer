#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    auto chmax=[&](ll &x, ll y) { 
        return x=max(x, y); 
    };
    vector<vector<ll>> dp(n+1, vector<ll>(2, -INF));
    dp[0][0]=0;
    rep(i, n) {
        int ni=i+1;
        rep(j, 2) {
            {//倒す
                int nj=j^1;//反転
                int tmp=(j%2==1) ? a[i]*2 : a[i];
                chmax(dp[ni][nj], dp[i][j]+tmp);
            }
            {//スルー
                int nj=j;
                chmax(dp[ni][nj], dp[i][j]);
            }
        }
    }
    ll ans=max(dp[n][0], dp[n][1]);
    cout << ans << endl;

    return 0;
}