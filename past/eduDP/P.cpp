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
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    rep(i, n-1) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    //dp[v][0]：頂点vを塗らない場合の通り
    //dp[v][1]：頂点vを塗る場合の通り
    vector<vector<mint>> dp(n, vector<mint>(2, 0));
    auto dfs=[&](auto dfs, int v, int parent=-1) -> void {
        dp[v][0]=dp[v][1]=1;
        for(auto nv:G[v]) if(nv!=parent) {
            dfs(dfs, nv, v);
            dp[v][0]*=dp[nv][0]+dp[nv][1];
            dp[v][1]*=dp[nv][0];
        }
    };
    dfs(dfs, 0);
    mint ans=dp[0][0]+dp[0][1];
    cout << ans.val() << endl;

    return 0;
}