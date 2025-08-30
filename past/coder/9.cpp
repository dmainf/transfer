#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define drep(i, n) for(int i=(n)-1;i>=0;i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<int> sx(m), sy(m);
    rep(i, m) cin >> sx[i] >> sy[i]; 
    int n;
    cin >> n;
    vector<int> tx(n), ty(n);
    rep(i, n) cin >> tx[i] >> ty[i];
    set<pair<int, int>> star;
    rep(i, n) star.emplace(tx[i], ty[i]);
    rep(i, n) {
        int di=tx[i]-sx[0], dj=ty[i]-sy[0];
        bool flag=true;
        rep(i, m) if(!star.count({sx[i]+di, sy[i]+dj})) {
            flag=false;
        }
        if(flag) {
            cout << di << " " << dj << endl;
            return 0;
        }
    }

    return 0;
}
