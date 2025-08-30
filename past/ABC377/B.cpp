#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> s(8);
    rep(i, 8) cin >> s[i];
    vector<bool> row(8, true), col(8, true);
    int ans=0;
    rep(i, 8) rep(j, 8) {
            if (s[i][j] == '#') continue;
            bool flag =true;
            rep(k, 8) if(s[i][k]=='#') flag=false;
            rep(k, 8) if(s[k][j]=='#') flag=false;
            if(flag) ans++;
    }
    cout << ans << endl;
    return 0;
}
