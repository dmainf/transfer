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
    int n;
    cin >> n;
    vector<pi> p;
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        p.push_back({l, 0});
        p.push_back({r, 1});
    }
    sort(all(p));
    int rs=0;
    ll ans=n*ll(n-1)/2LL;
    for(auto [x,t] : p) {
        if(t==0) ans-=rs;
        else rs++;
    }
    cout << ans << endl;

    return 0;
}
