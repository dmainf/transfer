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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    const int MAX=3e6+3;
    vector<mint> fact(MAX), invfact(MAX);
    fact[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = fact[i-1] * i;
    }
    invfact[MAX-1] = fact[MAX-1].inv();
    for(int i = MAX-1; 1 <= i; i--){
        invfact[i-1] = invfact[i] * i;
    }
    auto nCr = [&](int n, int r) -> mint {
        if(r < 0 || r > n) return 0;
        return fact[n] * invfact[r] * invfact[n-r];
    };
    mint ans=0;
    //BLOCK 1
    //apple a
    //orange k
    //tail is apple(that's why -1)
    //BLOCK 2
    //orange b-k
    //banana c
    //grape d
    //only banana can put on eveywhere(orange and grape koteied)
    //
    //
    //only orange is included into both 1 and 2 BLOCK
    //so orange key
    rep(k, b+1) {
        ans+=nCr(((a-1)+k), k)*nCr((b-k)+c+d, c);
    }
    cout << ans.val() << endl;

    return 0;
}