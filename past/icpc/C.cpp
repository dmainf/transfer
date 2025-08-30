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
    while(true) {
        ll n, m;
        cin >> n >> m;
        if(n==0 && m==0) break;
        set<ll> holiday;
        rep(i, n) {
            ll x; cin >> x;
            holiday.insert(x);
        }
        ll weeks=m/7;
        ll yasumi=weeks*2;
        for(int i=1; i<=m%7; i++) {
            ll day=weeks*7+i;
            int w=(day-1)%7;
            if(w==5|| w==6) yasumi++;
        }
        ll ans=m-yasumi;
        for(ll x:holiday) {
            if(x>m) continue;
            int w=(x-1)%7;
            if(w==5 || w==6) continue;
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}