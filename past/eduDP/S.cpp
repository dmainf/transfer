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
    string k;
    int d;
    cin >> k >> d;
    int n=k.size();
    //dp[i][r][t]：左からi桁まで，dの余りがr，タイトフラグt
    //t==1 いままでの文字列がkに一致している 
    //t==0 自由
    vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(d, vector<mint>(2, 0)));
    dp[0][0][1]=1;
    rep(i, n) {
        int digit=k[i]-'0';
        rep(r, d) rep(t, 2) {
            if(dp[i][r][t].val()==0) continue;
            int limit=(t==1) ? digit:9;
            rep(x, limit+1) {
                int nr=(r+x)%d;
                int nt=(t==1 && x==digit) ? 1:0;
                dp[i+1][nr][nt]+=dp[i][r][t];
            }
        }
    }
    //0分を引く
    mint ans=dp[n][0][0]+dp[n][0][1]-1;
    cout << ans.val() << endl;

    return 0;
}