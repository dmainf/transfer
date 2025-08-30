#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, ll>; 
const ll di[]={1,0,-1,0};
const ll dj[]={0,1,0,-1};
const ll INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    using D=map<ll, set<ll>>;
    D row, col;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        row[y].insert(x);
        col[x].insert(y);
    }
    ll ans=0;
    //key==y 横移動
    //key==x 縦移動
    auto f=[&](D& row, D& col, ll key, ll left, ll right) {
        //left→right
        if(left>right) swap(right, left);
        //今回は行の中を移動
        auto& st=row[key];
        while(true) {
            auto it=st.lower_bound(left);
            //右端かrightまで行ったらストップ
            if(it==st.end() || *it>right) break;
            //列のやつを削除
            col[*it].erase(key);
            //行のやつを削除
            st.erase(it);
            ans++;
        }
    };
    rep(i, m) {
        char d;
        ll c;
        cin >> d >> c;
        ll nx=sx, ny=sy;
        if(d=='U') ny+=c;
        if(d=='D') ny-=c;
        if(d=='R') nx+=c;
        if(d=='L') nx-=c;
        {
            //行を横移動
            if(sy==ny) f(row, col, sy, sx, nx);
            //列を縦移動
            else f(col, row, sx, sy, ny);
        }
        sx=nx;
        sy=ny;
    }
    cout << sx << " " << sy << " " << ans << endl;

    return 0;
}