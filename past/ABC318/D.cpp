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
    vector<vector<int>> d(n, vector<int>(n));
    rep(i, n) for(int j=i+1; j<n; j++) {
        cin >> d[i][j];
    }
    //dp[mask]：頂点の集合，1なら済
    vector<ll> dp(1<<n, 0LL);
    rep(mask, (1<<n)-1) {
        int l;
        rep(bit, n) if(!(mask>>bit&1)) {
            l=bit;
            break;
        }
        //配るDP
        for(int r=l+1; r<n; r++) if(!(mask>>r&1)) {
            int n_mask=mask|(1<<l)|(1<<r);
            dp[n_mask]=max(dp[n_mask], dp[mask]+d[l][r]);
        }
    }
    cout << dp.back() << endl;

    return 0;
}
