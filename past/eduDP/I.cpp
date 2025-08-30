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
    vector<double> p(n);
    rep(i, n) cin >> p[i];
    //dp[i][j] i枚まで投げたときに表がj枚
    vector<vector<double>> dp(n+1, vector<double>(n+1, 0.0));
    dp[0][0]=1.0;
    rep(i, n) for(int j=0; j<=i; j++) {
        dp[i+1][j+1]+=dp[i][j]*p[i];
        dp[i+1][j]+=dp[i][j]*(1.0-p[i]);
    }
    double ans=0.0;
    for(int i=n/2+1; i<=n; i++) ans+=dp[n][i];
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}