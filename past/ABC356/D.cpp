#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
using mint = modint998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    n++;
    mint ans;
    rep(i, 60) {
        if(!((m>>i)&1)) continue;
        ll p=2LL<<i;
        ll r=n%p;
        ans+=(n-r)/2;
        if(r>=(1LL<<i)) ans+=r-(1LL<<i);
    }
    cout << ans.val() << endl;

    return 0;
}
