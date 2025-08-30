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
const int MAX=1e6;
#include <atcoder/all>
using namespace atcoder;
ll op(ll a, ll b) { return max(a, b); }
ll e() { return 0; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h(n), a(n);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> a[i];
    //dp[h]：最後の高さ(1番高い高さ)がhのときの最大値
    //dp[i]=max(dp[i], max(dp[0]...dp[h[i-1]]))+a[i]
    segtree<ll, op, e> dp(MAX);
    rep(i, n) {
        ll cur=dp.prod(0, h[i])+a[i];
        dp.set(h[i], max(dp.get(h[i]), cur));
    }
    cout << dp.prod(0, MAX) << endl;

    return 0;
}