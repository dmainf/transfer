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
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    //dp[i, j)：a[i]からa[j]-1までのX-Y
    //先手←X-Yを最大化する
    //後手←X-Yを最小化する
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for(int len=1; len<=n; len++) {
        for(int i=0; i+len<=n; i++) {
            int j=i+len;
            //n-len：2人で取った個数
            if((n-len)%2==0) dp[i][j]=max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
            else dp[i][j]=min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
        }
    }
    cout << dp[0][n] << endl;

    return 0;
}