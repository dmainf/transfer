#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll d;
    cin >> d;
    ll y=2e6;
    ll ans=d;
    rep(x, 2e6+1) {
        while(0<y && x*x+y*y>d) {
            y--;
        }
        ans=min(ans, abs(x*x+y*y-d));
        ans=min(ans, abs(x*x+(y+1)*(y+1)-d));
    }
    cout << ans << endl;

    return 0;
}