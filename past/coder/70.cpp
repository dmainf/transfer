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
    const int MOD=1000000007;
    auto modpow=[&](ll m, ll n, int MOD) -> ll {
        ll res=1;
        while(n>0) {
            if(n&1) res=res*m%MOD;
            m=m*m%MOD;
            n>>=1;
        }
        return res;
    };
    int m, n;
    cin >> m >> n;
    cout << modpow(m, n, MOD) << endl;

    return 0;
}
