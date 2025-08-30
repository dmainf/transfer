#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(coin) coin.begin(),coin.end()
#define rall(coin) coin.rbegin(),coin.rend()
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
    ll n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans=INF;
    rep(i, 10000) {
        if(a*i>n) continue;
        rep(j, 10000) {
            ll tmp=a*i+b*j;
            if(tmp>n) break;
            if((n-tmp)%c==0) ans=min(ans, i+j+(n-tmp)/c);
        }
    }
    cout << ans << endl;

    return 0;
}