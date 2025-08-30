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
    ll l;
    vector<int> n(2);
    cin >> l >> n[0] >> n[1];
    vector<pair<ll, pi>> event;
    rep(d, 2) {
        ll t=0;
        rep(i, n[d]) {
            int v; ll l;
            cin >> v >> l;
            event.push_back({t, {d, v}});
            t+=l;
        }
    }
    sort(all(event));
    event.push_back({l, {0, 0}});
    vector<int> val(2);
    ll pre_t=0;
    ll ans=0;
    for(auto [t, p]:event) {
        if(val[0]==val[1]) ans+=t-pre_t;
        auto [i, v]=p;
        val[i]=v;
        pre_t=t;
    }
    cout << ans << endl;

    return 0;
}