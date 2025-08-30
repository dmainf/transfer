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
    ll n, m;
    cin >> n >> m;
    //5
    //5 1   -4
    //4 3   -1
    //3 1   -2
    //gready?
    //5
    //4
    //3
    //1
    vector<pi> bin(m);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        bin[i]={a-b, a};
    }
    sort(all(bin));
    ll ans=0;
    rep(i, m) {
        auto [val, min]=bin[i];
        if(min<=n) {
            ll cnt=(n-min)/val+1;
            n-=cnt*val;
            ans+=cnt;
        }
    }
    cout << ans << endl;

    return 0;
}