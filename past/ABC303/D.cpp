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
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, z;
    cin >> x >> y >> z;
    //X：aを押した
    //Y：a+shiftでAを押した
    //Z：CapsLockを切り替えた
    string s;
    cin >> s;
    int n=s.size();
    vector<vector<ll>> dp(n+1, vector<ll>(2, INF));
    dp[0][0]=0;
    dp[0][1]=z;
    //dp[i][j]：i番目までで状態jの最小値
    //0：CapsLockがOFF
    //1：CapsLockがON
    rep(i, n) {
        if(s[i]=='a') {
            dp[i+1][0]=min(dp[i][0]+x, dp[i][1]+z+x);
            dp[i+1][1]=min(dp[i][1]+y, dp[i][0]+z+y);
        }
        if(s[i]=='A') {
            dp[i+1][0]=min(dp[i][0]+y, dp[i][1]+z+y);
            dp[i+1][1]=min(dp[i][1]+x, dp[i][0]+z+x);
        }
    }
    cout << *min_element(all(dp[n])) << endl;
 
    return 0;
}