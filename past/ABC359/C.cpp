#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll sx, sy;
    cin >> sx >> sy;
    ll tx, ty;
    cin >> tx >> ty;
    if((sx+sy)%2==1) sx--;
    if((tx+ty)%2==1) tx--;
    ll x=abs(tx-sx), y=abs(ty-sy);
    ll ans=0;
    if(x<y) ans=y;
    else ans=(x+y)/2;
    cout << ans << endl;

    return 0;
}
