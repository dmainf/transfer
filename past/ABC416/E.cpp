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
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i, n) dist[i][i]=0;
    rep(i, m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b]=min(dist[a][b], c);
        dist[b][a]=min(dist[b][a], c);
    }
    rep(k, n) rep(i, n) rep(j, n) {
        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    int k; ll t;
    cin >> k >> t;
    vector<int> d(k);
    rep(i, k) { cin >> d[i]; d[i]--; }
    vector<ll> min_ap(n, INF);
    rep(i, n) for(int x:d) {
        min_ap[i]=min(min_ap[i], dist[i][x]);
    }
    int q; cin >> q;
    vector<ll> ans;
    while (q--) {
        int op; cin >> op;
        if (op==1) {
            int x, y; ll t;
            cin >> x >> y >> t;
            x--; y--;
            vector<vector<ll>> ndist=dist;
            rep(i, n) rep(j, n) {
                ll xy=dist[i][x]+t+dist[y][j];
                ll yx=dist[i][y]+t+dist[x][j];
                ndist[i][j]=min({dist[i][j], xy, yx});
            }
            vector<ll> nmin_ap=min_ap;
            rep(i, n) {
                ll xy=dist[i][x]+t+min_ap[y];
                ll yx=dist[i][y]+t+min_ap[x];
                nmin_ap[i]=min({min_ap[i], xy, yx});
            }
            dist=ndist;
            min_ap=nmin_ap;
        }
        if(op==2) {
            int x; cin >> x;
            x--;
            rep(i, n) min_ap[i]=min(min_ap[i], dist[i][x]);
        }
        if(op==3) {
            ll tmp=0;
            rep(i, n) rep(j, n) {
                ll shortest=min(dist[i][j], min_ap[i]+t+min_ap[j]);
                if(shortest!=INF) tmp+=shortest;
            }
            ans.push_back(tmp);
        }
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}