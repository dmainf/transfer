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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> c;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        rep(j, b) c.push_back(a);
    }
    int m=c.size();
    vector<vector<bool>> dp(m+1, vector<bool>(x+1, false));
    dp[0][0]=true;
    rep(i, m) rep(j, x+1) {
        if(!dp[i][j]) continue;
        dp[i+1][j]=true;
        int nv=j+c[i];
        if(nv<=x) dp[i+1][nv]=true;
    }
    cout << (dp[m][x] ? "Yes":"No") << endl;

    return 0;
}