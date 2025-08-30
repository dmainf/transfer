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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    mint ans;
    rep(i, n) ans+=mint(a[i])*i;
    vector<mint> degit(n);
    rep(i, n) {
        degit[i]=1;
        int tmp=a[i];
        while(tmp) {
            tmp/=10;
            degit[i]*=10;
        }
    }
    mint s=0;
    for(int i=n-1; 0<=i; i--) {
        ans+=s*a[i];
        s+=degit[i];
    }
    cout << ans.val() << endl;

    return 0;
}