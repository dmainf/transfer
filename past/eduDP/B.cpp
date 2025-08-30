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
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<ll> dp(n, INF);
    dp[0]=0;
    for(int i=1; i<n; i++) {
        for(int j=1; j<=k; j++) if(0<=i-j) {
            //dp[i]=min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
            chmin(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout << dp[n-1] << endl;

    return 0;
}