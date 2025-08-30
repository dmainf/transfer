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
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, n) rep(j, n) if(a[i][j]==1) {
        G[i].push_back(j);
    }
    rep(i, n) rep(j, G[i].size()) {
        cout << G[i][j]+1 << " \n"[j==G[i].size()-1];
    }

    return 0;
}