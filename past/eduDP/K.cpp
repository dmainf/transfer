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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    //dp[i]：i個の石が残っているとき先手が勝てるか
    vector<bool> dp(k+1, false);
    for(int i=1; i<=k; i++) {
        rep(j, n) {
            if(0<=i-a[j]) dp[i]=dp[i]||!dp[i-a[j]];
        }
    }
    for(auto x:dp) cout << x << " ";
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}