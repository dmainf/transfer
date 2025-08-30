#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    //dp[i][j]：i人目までにj個の飴を分ける方法の総数
    vector<vector<mint>> dp(n+1, vector<mint>(k+1, 0));
    dp[0][0]=1;
    rep(i, n) {
        vector<mint> sumdp(k+2, 0);
        for(int j=0; j<=k; j++) sumdp[j+1]=sumdp[j]+dp[i][j];
        for(int j=0; j<=k; j++) {
            //i番目の子どもがx個取ったときi-1番目の子どもまでにj-x個を配る方法
            //※j：いままで配った飴の合計個数
            dp[i+1][j]=sumdp[j+1]-sumdp[j-min(j, a[i])];
        }
    }
    cout << dp[n][k].val() << endl;

    return 0;
}