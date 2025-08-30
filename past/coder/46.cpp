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
    vector<int> p(n+1);
    rep(i, n) {
        int r, c;
        cin >> r >> c;
        if(i==0) {
            p[0]=r;
            p[1]=c;
        } else {
            p[i+1]=c;
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int len=2; len<=n; len++) {
        for(int l=1; l<=n-len+1; l++) {
            int r=l+len-1;
            dp[l][r]=INF;
            for(int k=l; k<r; k++) {
                int cost=dp[l][k]+dp[k+1][r]+p[l-1]*p[k]*p[r];
                dp[l][r]=min(dp[l][r], cost);
            }
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}