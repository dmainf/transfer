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
    int n, k, p;
    cin >> n >> k >> p;
    map<vector<int>, ll> dp;
    dp[vector<int>(k)]=0;
    rep(i, n) {
        int c;
        vector<int> a(k);
        cin >> c;
        rep(j, k) cin >> a[j];
        auto old=dp;
        for(auto [d, v]:old) {
            vector<int> nd=d;
            //pであればいい
            rep(j, k) nd[j]=min(nd[j]+a[j], p);
            //mapでINFで初期化できないからこれ
            if(dp.count(nd)) dp[nd]=min(dp[nd], v+c);
            else dp[nd]=v+c;
        }
    }
    vector<int> t(k, p);
    if(dp.count(t)) cout << dp[t] << endl;
    else cout << -1 << endl;

    return 0;
}