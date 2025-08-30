#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<char, int>> p;
    for(char c:s) {
        if(p.size() && p.back().first==c) p.back().second++;
        else p.push_back({c, 1}); 
    }
    int one=0;
    rep(i, p.size()) {
        if(p[i].first=='1') one++;
        if(one==k) {
            swap(p[i], p[i-1]);
            break;
        }
    }
    rep(i, p.size()) rep(j, p[i].second) cout << p[i].first;
    cout << endl;

    return 0;
}