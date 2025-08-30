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
    int n;
    cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    //0:a 1:b 2:c
    rep(i, n) {
        vector<int> h(3);
        rep(j, 3) cin >> h[j];
        rep(k, 3) rep(l, 3) if(k!=l) {
            chmax(dp[i+1][k], dp[i][l]+h[l]);
        }
    }
    cout << *max_element(all(dp[n])) << endl;

    return 0;
}