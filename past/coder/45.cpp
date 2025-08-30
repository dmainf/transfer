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
    int n, m;
    while(cin >> n >> m && !(n==0&&m==0)) {
        vector<int> c(m), x(n);
        rep(i, m) cin >> c[i];
        rep(i, n) cin >> x[i];
        vector<int> dp(256, INF);
        dp[128]=0;
        rep(i, n) {
            vector<int> next_dp(256, INF);
            rep(y, 256) {
                if(dp[y]==INF) continue;
                rep(k, m) {
                    int ny=y+c[k];
                    if(ny<0) ny=0;
                    if(ny>255) ny=255;
                    int cost=(x[i]-ny)*(x[i]-ny);
                    next_dp[ny]=min(next_dp[ny], dp[y]+cost);
                }
            }
            dp.swap(next_dp);
        }
        int ans=INF;
        rep(i, 256) ans=min(ans, dp[i]);
        cout << ans << endl;
    }

    return 0;
}
