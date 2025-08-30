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
    int ans=0;
    set<pair<int, int>> p;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        if(u==v) {
            ans++;
            continue;
        }
        pair<int, int> tmp1={u, v}, tmp2={v, u};
        if(p.count(tmp1) || p.count(tmp2)) {
            ans++;
            continue;
        }
        p.emplace(tmp1);
    }
    cout << ans << endl;

    return 0;
}