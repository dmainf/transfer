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
const int MAX=5000000;
const int MOD=1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> fac(MAX), finv(MAX), inv(MAX);
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2; i<MAX; i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
    int w, h;
    cin >> w >> h;
    auto C=[&](int n, int k) {
        return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
    };
    cout << C(w+h-2, h-1) << endl;;

    return 0;
}
