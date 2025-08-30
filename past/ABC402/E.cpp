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
    int n, x;
    cin >> n >> x;
    vector<double> s(n), p(n);
    vector<int> c(n);
    rep(i, n) {
        cin >> s[i] >> c[i] >> p[i];
        p[i]/=100.0;
    }
    int m=1<<n;
    vector<vector<double>> dp(m, vector<double>(x+1, 0.0));
    //dp[mask][balance]:maskから始めたとき残りbalace円の最大期待値
    for(int mask=m-1; mask>=0; mask--) {
        for(int balance=0; balance<=x; balance++) {
            double mx=0.0;
            rep(i, n) {
                if(!(mask&(1<<i)) && c[i]<=balance) {
                    int nmask=mask|(1<<i);
                    int now=balance-c[i];
                    double sum=p[i]*(s[i]+dp[nmask][now])+(1.0-p[i])*(dp[mask][now]);
                    mx=max(mx, sum);
                }
            }
            dp[mask][balance]=mx;
        }
    }
    cout << fixed << setprecision(10) << dp[0][x] << endl;
    return 0;
}    