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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    //010 011 101
    //0 1 1
    //1
    vector<vector<int>>  dp(s.size(), vector<int>(2, 1));
    rep(i, s.size()) dp[i][s[i]-'0']=0;
    while(dp.size()>1) {
        vector<vector<int>> old(dp.size()/3, vector<int>(2, INF));
        swap(dp, old);
        for(int l=0; l<old.size(); l+=3) {
            rep(s, 8) {
                int cost=0;
                rep(i, 3) cost+=old[l+i][s>>i&1];
                int x=__builtin_popcount(s)>=2 ? 1:0;
                dp[l/3][x]=min(dp[l/3][x], cost);
            }
        }
    }
    //defalt's cost is 0, so max means answer
    int ans=max(dp[0][0], dp[0][1]);
    cout << ans << endl;

    return 0;
}