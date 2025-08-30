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
template<class T> inline bool chmax(T& a, T b) {
    if(a<b) { a=b; return true; }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
    }
    vector<int> dp(n, -1);
    auto f=[&](auto f, int v) {
        if(dp[v]!=-1) return dp[v];
        int res=0;
        for(auto nv:G[v]) chmax(res, f(f, nv)+1);
        return dp[v]=res;
    };
    int ans=0;
    rep(v, n) chmax(ans, f(f, v));
    cout << ans << endl;

    return 0;
}