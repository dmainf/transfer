#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<pair<int, int>> ans(n);
    rep(i, n) ans[i]={a[i], i};
    sort(ans.rbegin(), ans.rend());
    cout << ans[1].second+1 << endl;

    return 0;
}
