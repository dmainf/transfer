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
const int MAX=1e6+1;
const int MOD=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    if((2*y-x)%3!=0 || (2*x-y)%3!=0) {
        cout << 0 << endl;
        return 0;
    }
    int a=(2*y-x)/3;
    int b=(2*x-y)/3;
    if(a<0 | b<0) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> fac(MAX), finv(MAX), inv(MAX); 
    //fac[i]：i!
    //finv[i]：i!の逆元
    //inv[i]：iの逆元
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2; i<MAX; i++) {
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
    auto nCr=[&](int n, int r) -> int {
        return fac[n]*(finv[r]*finv[n-r]%MOD)%MOD;
    };
    cout << nCr(a+b, a) << endl;

    return 0;
}