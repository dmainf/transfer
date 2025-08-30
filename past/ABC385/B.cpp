#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    int h, w, sx, sy;
    cin >> h >> w >> sx >> sy;
    sx--; sy--;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    string t;
    cin >> t;
    int ans=0;
    for(char c : t) {
        int nx=sx, ny=sy;
        if(c=='U') nx--;
        if(c=='D') nx++;
        if(c=='L') ny--;
        if(c=='R') ny++;
        if(s[nx][ny]=='#') continue;
        sx=nx; sy=ny;
        if(s[sx][sy]=='@') {
            s[sx][sy]='.';
            ans++;
        }
    }
    cout << sx+1 << " " << sy+1 << " " << ans << endl;

    return 0;
}