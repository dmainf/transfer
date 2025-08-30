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
#include <atcoder/modint>
using namespace atcoder;
using mint=modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; cin >> k;
    if(k%9!=0) {
        cout << 0 << endl;
        return 0;
    }
    vector<mint> dp(k+1);
    //dp[x] when sum of degit is x, num of ans
    dp[0]=1;
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=min(i, 9); j++) dp[i]+=dp[i-j];
    }
    cout << dp[k].val() << endl;

    return 0;
}