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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n+1,  vector<int>(3, 0));
    rep(i, n) {
        int tmp;
        if(s[i]=='R') tmp=0;
        if(s[i]=='P') tmp=1;
        if(s[i]=='S') tmp=2;
        rep(j, 3) {
            int val=0;
            if(j==(tmp+1)%3) val=1;
            if(j==(tmp+2)%3) continue;;
            rep(pj, 3) {
                if(j==pj) continue;
                dp[i+1][j]=max(dp[i+1][j], dp[i][pj]+val);
            }
        }
    }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans << endl;

    return 0;
}