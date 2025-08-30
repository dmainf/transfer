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
    int a, b;
    cin >> a >> b;
    vector<int> h;
    rep(i, 3) {
        if(i+1==a || i+1==b) continue;
        h.push_back(i);
    }
    if(h.size()>1) cout << -1 << endl;
    else cout << h[0]+1 << endl;

    return 0;
}
