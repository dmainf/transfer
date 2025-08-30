#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    rep(i, max(s.size(), t.size())) {
        if(s[i]!=t[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}
