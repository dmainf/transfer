#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    int q;
    cin >> q;
    int ans=0;
    rep(i, q) {
        int t;
        cin >> t;
        if(binary_search(all(s), t)) ans++;
    }
    cout << ans << endl;

    return 0;
}