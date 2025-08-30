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
    int a, b;
    ll c;
    cin >> a >> b >> c;
    auto f=[&](ll z) -> int {
        return __builtin_popcountll(z);
    };
    //1 : 1|0, 0|1
    //0 : 0|0, 1|1
    ll x=0, y=0;
    rep(bit, 60) if((c>>bit)&1) {
        if(a-f(x)>b-f(y)) x+=1LL<<bit;
        else y+=1LL<<bit; 
    }
    rep(bit, 60) if(!((c>>bit)&1)) {
        if(a>f(x) || b>f(y)) {
            x+=1LL<<bit;
            y+=1LL<<bit;
        }
    }
    if(f(x)==a && f(y)==b) cout << x << " " << y << endl;
    else cout << -1 << endl;

    return 0;
}
