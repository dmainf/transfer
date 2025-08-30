#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
string check(vector<string> tmps) {
    string b;
    b=tmps[0];
    rep(i, tmps.size()) rep(j, b.size()) {
        if(b[j]<tmps[i][j]) {
            break;
        } else if(b[j]==tmps[i][j]) {
            continue;
        } else {
            b=tmps[i];
        }
    }
    return b;
}//minでいけた(T_T)泣
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    vector<string> x;
    while(s!=t) {
        vector<string> tmps;
        rep(i, s.size()) if(s[i]!=t[i]) {
            string tmp=s;
            tmp[i]=t[i];
            tmps.push_back(tmp);
        }
        x.push_back(check(tmps));
        s=check(tmps);
    }
    cout << x.size() << endl;
    rep(i, x.size()) cout << x[i] << endl;

    return 0;
}
