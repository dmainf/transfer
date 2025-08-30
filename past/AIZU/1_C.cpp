#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const ll di[]={+1,-1,+0,+0};
const ll dj[]={+0,+0,+1,-1};
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll V, E;
    cin >> V >> E;
    vector<vector<ll>> dist(V, vector<ll>(V, INF));
    rep(i, V) dist[i][i]=0;
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;
        dist[s][t]=d;
    }
    rep(k, V) rep(i, V) rep(j, V) {
        if(dist[i][k]==INF || dist[k][j]==INF) continue;
        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    rep(i, V) {
        if(dist[i][i]<0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i, V) {
        rep(j, V) {
            if(j!=0) cout << " ";
            if(dist[i][j]==INF) cout << "INF";
            else cout << dist[i][j];
        }
        cout << endl;
    }

    return 0;
}