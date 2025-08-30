#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    rep(i, n) if(i%2==1) {
        s[i]=s[i]^'0'^'1';
    }
    ll ans=INF;
    rep(bi, 2) {
        ll now=0;
        //to be 111111111
        rep(i, n) if(s[i]=='0') {
            now+=c[i];
        }
        //to be 00001111
        rep(i, n-1) {
            if(s[i]=='0') now-=c[i];
            else now+=c[i];
            ans=min(ans, now);
        }
        rep(i, n) s[i]=s[i]^'0'^'1';
    }
    cout << ans << endl;

    return 0;
}
