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
    int n, m;
    cin >> n >> m;
    set<int> s;
    rep(i, m) {
       int a;
       cin >> a;
       s.emplace(a); 
    }
    vector<int> b;
    rep(i, n) if(!s.count(i+1)) {
        b.push_back(i+1);
    }
    cout << b.size() << endl;
    rep(i, b.size()) cout << b[i] << " ";
    cout << endl;

    return 0;
}