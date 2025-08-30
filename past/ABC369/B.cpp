#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a; char s;
    map<char, vector<int>> p;
    rep(i, n) {
        cin >> a >> s;
        p[s].push_back(a);
    }
    int ans=0;
    for(int i=1; i<p['L'].size(); i++) ans+=abs(p['L'][i] - p['L'][i-1]);
    for(int i=1; i<p['R'].size(); i++) ans+=abs(p['R'][i] - p['R'][i-1]);
    cout << ans << endl;
    return 0;
}