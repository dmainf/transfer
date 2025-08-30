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
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> left_ant, right_ant;
    rep(i, n) {
        ll x;
        cin >> x;
        if(s[i]=='0') left_ant.push_back(x);
        else right_ant.push_back(x);
    }
    sort(all(left_ant));
    sort(all(right_ant));
    ll ans=0;
    for (int L:left_ant) {
        auto l=lower_bound(all(right_ant), L-2*t);
        auto r=lower_bound(all(right_ant), L);
        ans+=(r-l);
    }
    cout << ans << endl;

    return 0;
}
