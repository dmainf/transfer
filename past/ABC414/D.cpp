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
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    //7 3
    //5 10 15 20  8 14 15
    //5  8 10 14 15 15 20
    sort(all(x));
    vector<ll> dist(n, 0);
    rep(i, n-1) dist[i+1]=x[i+1]-x[i];
    ll ans=0;
    sort(rall(dist));
    int cnt=0;
    rep(i, n) {
        cnt++;
        if(cnt<=m-1) continue;
        ans+=dist[i];
    }
    cout << ans << endl;

    return 0;
}