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
    vector<pair<char, int>> p;
    rep(i, s.size()) {
        if(!p.empty() && s[i]==p.back().first) p.back().second++;
        else p.push_back({s[i], 1}); 
    }
    if(
    (p.size()==3 && p[0].first<p[1].first && p[1].first<p[2].first) || 
    (p.size()==2 && p[0].first<p[1].first) || 
    (p.size()==1) ||
    (p.size()==0)
    ) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
