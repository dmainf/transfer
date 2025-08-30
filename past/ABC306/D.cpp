#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
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
    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    //dp[i][j]：i番目の料理の状態j
    //j==0  通常
    //j==1  お腹壊してる
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        dp[i+1][0]=dp[i][0];
        dp[i+1][1]=dp[i][1];
        if(x==0) {
            ll tmp=max(dp[i][0], dp[i][1]);
            dp[i+1][0]=max(dp[i+1][0], tmp+y);
        }
        if(x==1) {
            dp[i+1][1]=max(dp[i+1][1], dp[i][0]+y);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}