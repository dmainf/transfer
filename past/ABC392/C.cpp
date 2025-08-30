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
    vector<int> P(n);
    rep(i, n){
        cin >> P[i];
        P[i]--;
    }
    vector<int> Q(n);
    rep(i, n) cin >> Q[i];

    vector<int> index(n + 1, -1);
    rep(i, n) index[Q[i]] = i;
    for(int i=1; i<=n; i++) {
        cout << Q[P[index[i]]] << (i == n ? "\n" : " ");
    }
    
    return 0;
}
