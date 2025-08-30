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
    int N, W;
    cin >> N >> W;
    vector<int> val(N), wei(N);
    rep(i, N) cin >> val[i] >> wei[i];
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    rep(i, N) rep(w, W+1) {
        if(wei[i]<=w) dp[i+1][w]=max(dp[i+1][w-wei[i]]+val[i], dp[i][w]);
        else dp[i+1][w]=dp[i][w];
    }
    cout << dp[N][W] << endl;

    return 0;
}