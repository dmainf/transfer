#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
#include <atcoder/modint>
using namespace atcoder;
using mint=modint998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> card(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        card[i]={a, b};
    }
    vector<vector<mint>> dp(n, vector<mint>(2));
    dp[0][0]=dp[0][1]=1;
    rep(i, n-1) {
        rep(pre, 2) rep(nxt, 2) {
            if(card[i][pre]!=card[i+1][nxt]) {
                dp[i+1][nxt]+=dp[i][pre];
            }
        }
    }
    mint ans=dp[n-1][0]+dp[n-1][1];
    cout << ans.val() << endl;

    return 0;
}