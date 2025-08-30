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
    map<char, int> cnt;
    rep(i, s.size()) cnt[s[i]]++;
    vector<int> good(101, 0);
    for(auto c : cnt) good[c.second]++;
    bool flag=true;
    rep(i, 101) if(good[i]!=0 && good[i]!=2) {
        No;
        return 0;
    }
    Yes;

    return 0;
}