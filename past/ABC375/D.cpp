#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n=s.size();
    vector<int> lcnt(26);
    vector<int> rcnt(26);
    rep(i, n) rcnt[s[i]-'A']++;
    ll ans=0;
    rep(j, n) {
        rcnt[s[j]-'A']--;
        rep(c, 26) ans+=((ll)lcnt[c]*(ll)rcnt[c]);
        lcnt[s[j]-'A']++;
    }
    cout << ans << endl;

    return 0;
}