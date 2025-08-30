#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> s(1009);
    rep(i, h) cin >> s[i];

    int minh=1009, minw=1009;
    int maxh=-1, maxw=-1;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                minh=min(minh, i);
                minw=min(minw, j);
            }
        }
    }
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                maxh=max(maxh, i);
                maxw=max(maxw, j);
            }
        }
    }
    for(int i=minh; i<=maxh; i++) {
        for(int j=minw; j<=maxw; j++) {
            if(s[i][j]=='.') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

	return 0;
}