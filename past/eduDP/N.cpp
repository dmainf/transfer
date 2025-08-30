#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n), sum(n+1, 0);
    rep(i, n) {
        cin >> a[i];
        sum[i+1]=sum[i]+a[i];
    }
    //dp[l][r]：[r, l)を合成したときの最小値
    //dp[l][r]=min(dp[l][r], dp[r][k]+dp[k][r]+tmp)
    //dp[r][k]+dp[k][r]：合成する前のコスト
    //tmp：いまから合成するコスト(スライムの強さの和)
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INF));
    rep(i, n) dp[i][i+1]=0;
    //should do less length
    for(int len=2; len<=n; len++) {
        for(int l=0; l+len<=n; l++) {
            int r=l+len;
            ll tmp=sum[r]-sum[l];
            for(int k=l+1; k<r; k++) {
                dp[l][r]=min(dp[l][r], dp[l][k]+dp[k][r]+tmp);
            }
        }
    }
    cout << dp[0][n] << endl;

    return 0;
}