#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    map<char, int> key;
    rep(i, 26) key[s[i]]=i+1;
    int ans=0;
    char pre='A';
    for(char c='B'; c<='Z'; c++) {
        ans+=abs(key[c]-key[pre]);
        pre=c;
    }
    cout << ans << endl;

    return 0;
}
