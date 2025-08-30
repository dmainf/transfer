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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n-1, vector<ll>(21, 0));
    dp[0][a[0]]=1;
    rep(i, n-2) rep(v, 21) {
        if(dp[i][v]>0) {
            if(v+a[i+1]<=20) dp[i+1][v+a[i+1]]+=dp[i][v];
            if(v-a[i+1]>=0)dp[i+1][v-a[i+1]]+=dp[i][v];
        }
    }
    cout << dp[n-2][a[n-1]] << endl;

    return 0;
}