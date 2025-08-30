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
    int n, q;
    cin >> n >> q;
    vector<bool> tooth(n, true);
    rep(i, q) {
        int t;
        cin >> t;
        t--;
        if(tooth[t]) tooth[t]=false;
        else tooth[t]=true;
    }
    int ans=0;
    rep(i, n) if(tooth[i]) {
        ans++;
    }
    cout << ans << endl;

    return 0;
}
