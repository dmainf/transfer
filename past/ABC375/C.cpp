#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    vector<string> b=a;
    rep(i, n) rep(j, n) {
        int ni=i, nj=j;
        int level=min({ni, nj, n-ni-1, n-nj-1});
        rep(k, level%4+1) {
            swap(ni, nj);
            nj=n-1-nj;
        }
        b[ni][nj]=a[i][j];
    }
    rep(i, n) cout << b[i] << endl;
    return 0;
}
