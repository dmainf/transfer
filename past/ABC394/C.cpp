#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<pair<char, int>> p;
    rep(i, s.size()) {
        if(p.size() && p.back().first==s[i]) p.back().second++;
        else p.push_back({s[i], 1});
    }
    rep(i, p.size()) {
        if(p[i].first=='W' && p[i+1].first=='A') {
            cout << 'A';
            rep(j, p[i].second) cout << 'C';
            p[i+1].second--;
        } else {
            rep(j, p[i].second) cout << p[i].first;
        }
    }
    cout << endl;

    return 0;
}