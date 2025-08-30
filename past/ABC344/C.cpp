#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    cin >> l;
    vector<int> c(l);
    rep(i, l) cin >> c[i];
    vector<bool> cnt(3*1e8, false);
    rep(i, n) rep(j, m) rep(k, l) {
        cnt[a[i]+b[j]+c[k]]=true;
    }
    int q;
    cin >> q;
    rep(i, q) {
        int x;
        cin >> x;
        if(cnt[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
