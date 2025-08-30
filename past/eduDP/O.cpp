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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    //dp[x]：xのときの通り
    //x：ペア済みのwomanの集合
    vector<mint> dp(1<<n, 0);
    dp[0]=1;
    for(int x=1; x<1<<n; x++) {
        //manの先頭からwomanを決定する
        //manを固定してwomanの順番だけで決める
        int idx=__builtin_popcount(x);
        //idx-1番目のmanまで済み
        rep(woman, n) if(a[idx-1][woman]==1) {
            if(!(x&(1<<woman))) continue;
            //plus all of previous patarn
            int pre=x^(1<<woman);
            dp[x]+=dp[pre];
        }
    }
    cout << dp[(1<<n)-1].val() << endl;

    return 0;
}