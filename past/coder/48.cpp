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
    while(cin >> n && n!=0) {
        vector<int> w(n);
        rep(i, n) cin >> w[i];
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        function<int(int, int)> f = [&](int l, int r) {
            if(dp[l][r]!=-1) return dp[l][r];
            if(r-l<=1) return dp[l][r]=0;
            if(r-l==2) {
                if(abs(w[r-1]-w[l])<=1) return dp[l][r]=2;
                else return dp[l][r]=0;
            }
            if(abs(w[r-1]-w[l])<=1 && f(l+1, r-1)==r-l-2) return dp[l][r]=r-l;
            int tmp=0;
            for(int i=l+1; i<r; i++) tmp=max(tmp, f(l, i)+f(i, r));
            return dp[l][r]=tmp;
        };
        f(0, n);
        cout << dp[0][n] << endl;
    }

    return 0;
}