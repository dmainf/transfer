#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    rep(i, n-2)if(s[i]=="sweet" && s[i+1]=="sweet") {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}
