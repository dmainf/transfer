#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int ans=0;
    rep(i, n) {
        if(s[i]=='#' && s[i+2]=='#' && s[i+1]=='.') ans++;
    }
    cout << ans <<  endl;

    return 0;
}
