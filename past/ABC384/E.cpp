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
    ll h, w, x;
    ll p, q;
    cin >> h >> w >> x >> p >> q;
    p--; q--;
    vector<vector<ll>> s(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> s[i][j];
    ll lv=s[p][q];
    vector<pi> sli;
    sli.push_back({p, q});
    vector<vector<bool>> mine(h, vector<bool>(w, false));
    mine[p][q]=true;
    bool flag=true;
    while(flag) {
        flag=false;
        rep(slii, sli.size()) {
            auto [i, j]=sli[slii];
            rep(v, 4) {
                ll ni=i+di[v];
                ll nj=j+dj[v];
                if(ni<0 || h<=ni) continue;
                if(nj<0 || w<=nj) continue;
                if(mine[ni][nj]) continue;
                if((__int128)s[ni][nj]*x<(__int128)lv) {
                    mine[ni][nj]=true;
                    lv+=s[ni][nj];
                    sli.push_back({ni, nj});
                    flag=true;
                }
            }
        }
    }
    cout << lv << endl;

    return 0;
}