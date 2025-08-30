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
using mint=modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    //dp[i][j]  sのi文字目まででatcoderのj文字目まで一致する場合の数
    string t="atcoder";
    vector<vector<mint>> dp(n+1, vector<mint>(t.size()+1, 0));
    dp[0][0]=1;
    rep(i, n) rep(j, t.size()+1) {
        dp[i+1][j]+=dp[i][j];
        if(s[i]==t[j]) dp[i+1][j+1]+=dp[i][j];
    }
    cout << dp[n].back().val() << endl;

    return 0;
}