#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    auto rote=[&](auto s) {
        auto tmp=s;
        rep(i, n) rep(j, n) {
            tmp[j][n-i-1]=s[i][j];
        }
        return tmp;
    };
    auto check=[&](auto s, auto t) -> int {
        int cnt=0;
        rep(i, n) rep(j, n) {
            if(s[i][j]!=t[i][j]) cnt++;
        }
        return cnt;
    };
    int ans=INF;
    rep(i, 4) {
        ans=min(ans, check(s, t)+i);
        s=rote(s);
    }
    cout << ans << endl;

    return 0;
}