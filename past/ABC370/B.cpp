#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, i+1) cin >> a[i][j];
    int atom=1;
    rep(i, n) {
        if(atom-1>=i) atom=a[atom-1][i];
        else atom=a[i][atom-1];
    }
    cout << atom << endl;
    return 0;
}
