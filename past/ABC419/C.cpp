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
    int n;
    cin >> n;
    ll mn_r=INF, mn_c=INF;
    ll mx_r=-INF, mx_c=-INF;
    rep(i, n) {
        ll r, c;
        cin >> r >> c;
        mn_r=min(mn_r, r);
        mx_r=max(mx_r, r);
        mn_c=min(mn_c, c);
        mx_c=max(mx_c, c);
    }
    ll dr=mx_r-mn_r;
    ll dc=mx_c-mn_c;
    ll ans=(max(dr, dc)+1)/2;
    cout << ans << endl;

    return 0;
}