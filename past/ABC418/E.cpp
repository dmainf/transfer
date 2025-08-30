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
    int n; cin >> n;
    vector<pi> point(n);
    rep(i, n) cin >> point[i].first >> point[i].second;
    map<double, int> mp;
    rep(i, n) rep(j, n) {
        auto [x1, y1]=point[i];
        auto [x2, y2]=point[j];
        int dx=x1-x2, dy=y1-y2;
        int g=__gcd(dy, dx);
        mp[abs((double)dy/dx)]++;
    }
    ll ans=0;
    for(auto [g, cnt]:mp) {
        cnt/=2;
        if(cnt<2) continue;
        ans+=cnt*(cnt-1)/2;
    }
    cout << ans << endl;

    return 0;
}