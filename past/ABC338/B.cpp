#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    map<char, int> cnt;
    rep(i, s.size()) cnt[s[i]]++;
    char ans=0;
    int mx=0;
    for(auto [c,x]:cnt) {
        if(mx<x) {
            ans=c;
            mx=x;
        }
    }
    cout << ans << endl;

    return 0;
}
