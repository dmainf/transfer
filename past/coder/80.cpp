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
    int h, w, k;
    ll v;
    cin >> h >> w >> k >> v;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<vector<ll>> s(h+1, vector<ll>(w+1, 0));
    rep(i, h) rep(j, w) {
        s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+a[i][j];
    }
    ll ans=0;
    rep(i, h) for(int ni=i+1; ni<=h; ni++) {
        rep(j, w) for(int nj=j+1; nj<=w; nj++) {
            ll size=(ni-i)*(nj-j);
            if((s[ni][nj]-s[i][nj]-s[ni][j]+s[i][j])+size*k<=v) {
                ans=max(ans, size);
            }
        }
    }
    cout << ans << endl;

    return 0;
}