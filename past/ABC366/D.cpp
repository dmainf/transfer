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
struct LR {
    int l;
    int r;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 0)));
    rep(x, n) rep(y, n) rep(z, n) {
        int a;
        cin >> a;
        dp[x+1][y+1][z+1]=a
                    +dp[x][y+1][z+1]+dp[x+1][y][z+1]+dp[x+1][y+1][z]
                    -dp[x][y][z+1]-dp[x+1][y][z]-dp[x][y+1][z]
                    +dp[x][y][z];
    }
    int q;
    cin >> q;
    rep(i, q) {
        LR x, y, z;
        cin >> x.l >> x.r;
        cin >> y.l >> y.r;
        cin >> z.l >> z.r;
        ll ans=dp[x.r][y.r][z.r]
                -dp[x.l-1][y.r][z.r]-dp[x.r][y.l-1][z.r]-dp[x.r][y.r][z.l-1]
                +dp[x.l-1][y.l-1][z.r] + dp[x.l-1][y.r][z.l-1] + dp[x.r][y.l-1][z.l-1]
                -dp[x.l-1][y.l-1][z.l-1];
        cout << ans << endl;
    }


    return 0;
}
