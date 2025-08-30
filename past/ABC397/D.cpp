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
    ll n;
    cin >> n;
    //x^3-y^3=n
    //(x-y)(x^2+xy+y^2)=n
    //d=x-y
    //x=y+d
    //x^3-y^3=(y+d)^3-y^3
    //       =3y^2d+3yd^2+d^3
    //       =d^3+3yd(y+d)  =n
    for(ll d=1; d<=cbrt(n); d++) {
        if((n-d*d*d)%(3*d)!=0) continue;
        ll c=(n-d*d*d)/(3*d);
        //sqrt's type is double
        //so dap happen
        ll S = floor(sqrt((long double)d*d+4*c) + 0.5);
        if (S*S!=d*d+4*c) continue;
        if((-d+(ll)sqrt(d*d+4*c))%2==0) {
            ll y=(-d+(ll)sqrt(d*d+4*c))/2;
            if (y <= 0) continue;
            ll x=y+d;
            cout << x << " " << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}