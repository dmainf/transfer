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
    int q;
    cin >> q;
    auto f=[&](string x, string y) {
        int xi=x.size(), yi=y.size();
        vector<vector<int>> dp(xi+1, vector<int>(yi+1, 0));
        rep(i, xi) rep(j, yi) {
            if(x[i]==y[j]) dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+1);
            else dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
        }
        cout << dp[xi][yi] << endl;
    };
    rep(i, q) {
        string x, y;
        cin >> x >> y;
        f(x, y);
    }

    return 0;
}