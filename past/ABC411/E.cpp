#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(6));
    rep(i, n) rep(j, 6) cin >> a[i][j];
    rep(i, n) {
        vector<pi> p;
        sort(all(a[i]));
        rep(j, 6) {
            if(p.empty() && p.back().first==a[i][j]) p.back().second++;
            else p.push_back({a[i][j], 1});
        }
    }
    rep(i, n) rep()

    return 0;
}