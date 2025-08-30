#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
const int di[]={0,0,-1,1};
const int dj[]={-1,1,0,0};
struct Grid {
    int i;
    int j;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto solve=[&](char c, Grid x) {
        if(c=='L') {
            x.i+=di[0];
            x.j+=dj[0];
        }
        if(c=='R') {
            x.i+=di[1];
            x.j+=dj[1];
        }        
        if(c=='U') {
            x.i+=di[2];
            x.j+=dj[2];
        }        
        if(c=='D') {
            x.i+=di[3];
            x.j+=dj[3];
        }
        return x;
    };
    int h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    Grid now;
    int ans=0;
    rep(i, h) rep(j, w) {
        if(s[i][j]=='#') continue;
        now.i=i;
        now.j=j;
        bool flag=true;
        rep(k, n) {
            now=solve(t[k], now);
            if(now.i<0 || h<=now.i) {
                flag=false;
                break;
            }
            if(now.j<0 || w<=now.j) {
                flag=false;
                break;
            }
            if(s[now.i][now.j]=='#') flag=false;
        }
        if(flag) ans++;
    }
    cout << ans << endl;

    return 0;
}
