#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    rep(i, s.size()) if(s[i]!='.') {
        cout << s[i];
    }
    cout << endl;

    return 0;
}
