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
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    vector<int> r;
    rep(i, n) r.push_back(i+1);
    int a, b;
    int cnt=0;
    do {
        cnt++;
        if(r==p) a=cnt;
        if(r==q) b=cnt;
    } while(next_permutation(all(r)));
    cout << abs(a-b) << endl;

    return 0;
}
