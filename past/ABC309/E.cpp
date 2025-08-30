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
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(int i=1; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> dp(n, -1);
    //dp[i]：最大i代先まで保証対象者
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        dp[x]=max(dp[x], y);
    }
    for(int i=1; i<n; i++) {
        dp[i]=max(dp[i], dp[p[i]]-1);
    }
    int ans=0;
    rep(i, n) if(0<=dp[i]) {
        ans++;
    }
    cout << ans << endl;

    return 0;
}