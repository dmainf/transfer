#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> index(n);
    rep(i, n) index[p[i]]=i;
    cin >> q;
    rep(qi, q) {
        int a, b;
        cin >> a >> b;
        if(index[a]<index[b]) cout << a << endl;
        else cout << b << endl;
    }

    return 0;
}
