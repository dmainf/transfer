#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n=s.size();
    int ans=0;
    rep(i, n) rep(j, n) rep(k, n) {
        if(!(i<j && j<k)) continue;
        if(j-i==k-j) if(s[i]=='A' && s[j]=='B' && s[k]=='C') {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}