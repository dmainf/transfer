#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, ll>;
const ll di[]={1,-1,0,0};
const ll dj[]={0,0,1,-1};
const ll INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h, w, m;
    cin >> h >> w >> m;
    vector<ll> t(m), a(m), x(m);
    rep(i, m) cin >> t[i] >> a[i] >> x[i];
    map<ll , ll> ans;
    vector<bool> is_row(h+1, false), is_col(w+1, false);
    ll row_cnt=0, col_cnt=0;
    for(ll i=m-1; i>=0; i--) {
        if(t[i]==1) {
            ll row=a[i];
            ll color=x[i];
            if(is_row[row]) continue;
            ll tmp=w-col_cnt;
            if(tmp>0) ans[color]+=tmp;
            is_row[row]=true;
            row_cnt++;
        }
        if(t[i]==2) {
            ll col=a[i];
            ll color=x[i];
            if(is_col[col]) continue;
            ll tmp=h-row_cnt;
            if(tmp>0) ans[color]+=tmp;
            is_col[col]=true;
            col_cnt++;
        }
    }
    ll zero=(h-row_cnt)*(w-col_cnt);
    if(zero>0) ans[0]+=(h-row_cnt)*(w-col_cnt);
    cout << ans.size() << endl;
    for(auto [c, cnt]:ans) cout << c << " " << cnt << endl;

    return 0;
}