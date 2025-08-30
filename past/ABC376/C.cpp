#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n-1) cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    vector<int> p;
    int box=0;
    rep(i, n) {
        if(a[i]>b[box]) {
            p.push_back(a[i]);
            continue;
        } else {
            box++;
        }
    }
    if(p.size()>1) {
        cout << -1 << endl;
    } else {
        cout << p.back() << endl;
    }

    return 0;
}
