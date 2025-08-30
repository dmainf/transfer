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
    const int n=8;
    int k;
    cin >> k;
    vector<pair<int, int>> a(k);
    rep(i, k) cin >> a[i].first >> a[i].second;
    vector<int> q(n);
    rep(i, n) q[i]=i;
    auto pos=[&]() -> bool {
        const int size=q.size();
        rep(qi, size) for(int r=qi+1; r<size; r++) {
            if (abs(qi-r)==abs(q[qi]-q[r])) return false;
        }
        return true;
    };
    auto given=[&]() -> bool {
        for (auto p:a)
            if(q[p.first]!=p.second) return false;
        return true;
    };
    do {
        if (!given()) continue;
        if (pos()) break;
    } while (next_permutation(all(q)));
    vector<string> b(n, "........");
    rep(i, n) b[i][q[i]] = 'Q';
    rep(i, n) cout << b[i] << endl;

    return 0;
}