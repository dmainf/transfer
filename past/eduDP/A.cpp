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
const ll INF=1e18;
template<class T> inline bool chmin(T& a, T b) {
    if (a>b) {
        a=b;
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<ll> dp(n, INF);
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2; i<n; i++) {
        chmin(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
        chmin(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[n-1] << endl;

    return 0;
}