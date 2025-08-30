#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, Q;
    cin >> n >> Q;
    vector<pi> p(n);
    ll min_x=INF, max_x=-INF;
    ll min_y=INF, max_y=-INF;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        ll X=x-y;
        ll Y=x+y;
        min_x=min(min_x, X);
        max_x=max(max_x, X);
        min_y=min(min_y, Y);
        max_y=max(max_y, Y);
        p[i]={X, Y};
    }
    vector<ll> ans;
    while(Q--) {
        int q; cin >> q;
        q--;
        auto [x, y]=p[q];
        ll a=abs(min_x-x);
        ll b=abs(max_x-x);
        ll c=abs(min_y-y);
        ll d=abs(max_y-y);
        ans.push_back(max({a, b, c, d}));
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}