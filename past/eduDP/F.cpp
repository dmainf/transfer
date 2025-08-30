#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,string>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
template<class T> inline bool chmax(T& a, T b) {
    if(a<b) {
        a=b;
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    rep(i, s.size()) rep(j, t.size()) {
        if(s[i]==t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
        else {
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }
    string ans="";
    int i=s.size(), j=t.size();
    while(0<i && 0<j) {
        if      (dp[i][j]==dp[i-1][j]) i--;
        else if (dp[i][j]==dp[i][j-1]) j--;
        else {
            ans=s[i-1]+ans;
            i--;
            j--;
        }
    }
    cout << ans << endl;

    return 0;
}