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
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<string>> s(n);
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            string tmp;
            cin >> tmp;
            s[i].push_back(tmp);
        }
    }
    //dp[i][j] : to sort of i, to complete j of t
    vector<vector<int>> dp(n+1, vector<int>(t.size()+1, INF));
    dp[0][0]=0;
    rep(i, n) {
        rep(j, t.size()+1) dp[i+1][j]=dp[i][j];
        rep(j, t.size()+1) if(dp[i][j]!=INF) {
            for(auto w:s[i]) {
                if(j+w.size()<=t.size() && t.substr(j, w.size())==w) {
                    dp[i+1][j+w.size()]=min(dp[i+1][j+w.size()], dp[i][j]+1);        
                }
            }
        }
    }
    if(dp[n][t.size()]==INF) cout << -1 << endl;
    else cout << dp[n][t.size()] << endl;

    return 0;
}
