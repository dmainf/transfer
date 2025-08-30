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
    int n, w;
    cin >> n >> w;
    vector<int> val(n), wei(n);
    rep(i, n) cin >> val[i] >> wei[i];
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    rep(i, n) rep(j, w+1) {
        dp[i+1][j]=dp[i][j];
        if(wei[i]<=j) dp[i+1][j]=max(dp[i][j], dp[i][j-wei[i]]+val[i]);
    }
    cout << dp[n][w] << endl;

    return 0;
}