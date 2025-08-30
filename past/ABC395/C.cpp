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
    vector<int> dp(1000001, INF);
    int ans=INF;
    rep(i, n) {
        int a;
        cin >> a;
        if(dp[a]!=INF) ans=min(ans, i-dp[a]+1);
        dp[a]=i;
    }
    if(ans==INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}