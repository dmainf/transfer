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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> pre(n+1, 0);
    rep(i, n) pre[i+1]=pre[i]+a[i];
    ll ans=0;
    rep(i, n) {
        ans+=a[i]*(pre[n]-pre[i+1]);
    }
    cout << ans << endl;

    return 0;
}