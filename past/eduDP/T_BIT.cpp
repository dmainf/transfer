#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#include <atcoder/all>
using namespace atcoder;
mint op(mint a, mint b) { return a + b; }
mint e() { return 0; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<mint>> dp(n, vector<mint>(n, 1));
    segtree<mint, op, e> seg(n);
    for(int i=1; i<n; i++) {

    }

    return 0;
}