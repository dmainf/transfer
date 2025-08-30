#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const char c[]={'R','B','W'};
int main(){
    const int INF=1e9;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(5);
    rep(i, 5) cin >> s[i];
    vector<vector<int>> dp(n, vector<int>(3, INF));
    rep(i, 3) {
        int cost=0;
        rep(j, 5) {
            if(c[i]!=s[j][0]) cost++;
        }
        dp[0][i]=cost;
    }
    for(int i=1; i<n; i++) {
        rep(j, 3) {
            rep(k, 3) {
                if(j==k) continue;
                int cost=0;
                rep(x, 5) if(s[x][i]!=c[j]) {
                    cost++;
                }
                dp[i][j]=min(dp[i][j], dp[i-1][k]+cost);
            }
        }
    }
    int ans=INF;
    rep(i, 3) ans=min(ans, dp[n-1][i]);
    cout << ans << endl;

    return 0;
}