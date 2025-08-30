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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a;
    int one=0, two=0, three=0;
    rep(i, n) {
        cin >> a;
        if(a==1) one++;
        if(a==2) two++;
        if(a==3) three++;
    }
    //dp[i][j][k]：寿司が残り1個の皿がi枚，2個の皿がj枚，3個の皿がk枚
    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(n+1, -1.0)));
    auto rec=[&](auto rec, int i, int j, int k) {
        if(dp[i][j][k]>=0.0) return dp[i][j][k];
        if(i==0 && j==0 && k==0) return 0.0;
        double res=1.0;
        if(0<i) res+=rec(rec, i-1, j, k)*(double)i/n;
        if(0<j) res+=rec(rec, i+1, j-1, k)*(double)j/n;
        if(0<k) res+=rec(rec, i, j+1, k-1)*(double)k/n;
        //p0：空皿を引く確率
        //空皿を引いたとき自分に遷移するから
        //dp[]=X+p0*dp[]
        //dp[]=X/(1-p0)
        double p0=(double)(n-i-j-k)/n;
        return dp[i][j][k]=res/(1-p0);
    };
    double ans=rec(rec, one, two, three);
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}