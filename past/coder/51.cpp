#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
const int MOD=10007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n, vector<int>((1<<3), -1));
    function<int(int, int)> f=[&](int d, int m) -> int {
        if(d==n-1) return 1;
        if(dp[d][m]!=-1) return dp[d][m];
        int ans=0;
        rep(i, (1<<3)) {//次の日のメンツ
            if(s[d+1]=='J' && !(i&(1<<0))) continue;
            if(s[d+1]=='O' && !(i&(1<<1))) continue;
            if(s[d+1]=='I' && !(i&(1<<2))) continue;
            if(m&i) ans=(ans+f(d+1, i))%MOD;
        }
        return dp[d][m]=ans;
    };
    int ans=0;
    rep(i, (1<<3)) {//初日のメンツ
        if(!(i & (1<<0))) continue;//Jが欠席
        if(s[0]=='J' && !(i&(1<<0))) continue;
        if(s[0]=='O' && !(i&(1<<1))) continue;
        if(s[0]=='I' && !(i&(1<<2))) continue;
        ans=(ans+f(0, i))%MOD;
    }
    cout << ans << endl;

    return 0;
}
