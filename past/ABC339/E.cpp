#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int op(int a, int b) { return max(a, b); }
int e() { return 0; }
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
const int MAX=5e5+1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    //dp[j]：最後に選んだ要素がjのときの最大値
    segtree<int, op, e> dp(MAX);
    rep(i, n) {
        int l=a[i]-d, r=a[i]+d+1;
        l=max(l, 0);
        r=min(r, MAX);
        //dp.prod(l, r)：l~rの最大値
        //dp[a[i]]に書き込む
        dp.set(a[i], dp.prod(l, r)+1);
    }
    cout << dp.prod(0, MAX) << endl;

    return 0;
}