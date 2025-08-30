#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    int m=0;
    rep(i, n) {
        cin >> s[i];
        m=max((int)s[i].size(), m);
    }
    vector<string> t(m, string(n, '*'));
    rep(i, n)rep(j, s[i].size()) {
        t[j][n-i-1]=s[i][j];
    }
    rep(i, m) {
        while(t[i].back()=='*') t[i].pop_back();
        cout << t[i] << endl;
    }
    
    return 0;
}