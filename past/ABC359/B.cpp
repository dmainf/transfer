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
    int n;
    cin >> n;
    vector<int> a(2*n);
    rep(i, 2*n) cin >> a[i];
    int ans=0;
    rep(i, 2*n-1) {
        if(a[i]==a[i+2]) ans++;
    }
    cout << ans << endl;

    return 0;
}
