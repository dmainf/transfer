#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<string> t(m);
    rep(i, m) cin >> t[i];
    rep(a, n-m+1) rep(b, n-m+1) {
        bool flag=true;
        rep(i, m) rep(j, m) {
            if (s[a+i][b+j]!=t[i][j]) {
                flag=false;
                break;
            }
            if (!flag) break;
        }
        if(flag){
            cout << a+1 << " " << b+1 << endl;
            return 0;
        }
    }

    return 0;
}