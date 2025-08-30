#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int MOD = 10000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(k), b(k);
    vector<int> pasta(n, 0);
    rep(i, k) {
        cin >> a[i] >> b[i];
        a[i]--;
        pasta[a[i]]=b[i];
    }
    //dp[i][j][k]：i日，j：当日のパスタ，k：昨日のパスタの通り
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(4, 0)));
    if(pasta[0]==0) {
        for(int j=1; j<=3; j++) dp[0][j][0]=1;
    } else {
        dp[0][pasta[0]][0]=1;
    }
    for(int i=1; i<n; i++) {
        for(int j=1; j<=3; j++) {//今日
            if(pasta[i]!=0 && pasta[i]!=j) continue;
            for(int k=1; k<=3; k++) {//昨日
                for(int l=0; l<=3; l++) {//一昨日
                    if(l!=0 && j==k && k==l) continue;
                    dp[i][j][k]=(dp[i][j][k]+(dp[i-1][k][l]))%MOD;
                }
            }
        }
    }
    int ans=0;
    for(int j=1; j<=3; j++) {
        for(int k=1; k<=3; k++) ans=(ans+dp[n-1][j][k])%MOD;
    }
    cout << ans << endl;

    return 0;
}