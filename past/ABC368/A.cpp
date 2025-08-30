#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b;
    for (int i = n - k; i < n; i++) b.push_back(a[i]);
    for (int i = 0; i < n - k; i++) b.push_back(a[i]);
    rep(i, n) cout << b[i]  << " \n"[i==n-1];

    return 0;
}
