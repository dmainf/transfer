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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n=s.size();
    //dp[i][j]：i文字目で'('-')'がj個
    vector<vector<mint>> dp(n+1, vector<mint>(n+1));
    dp[0][0]=1;
    rep(i, n) rep(j, n) {
        //'('を1増やす
        if(s[i]!=')') dp[i+1][j+1]+=dp[i][j];
        //')'を1増やす
        if(j!=0 && s[i]!='(') dp[i+1][j-1]+=dp[i][j];
    }
    cout << dp[n][0].val() << endl;

    return 0;
}