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
    vector<int> h(n);
    rep(i, n) {
        cin >> h[i];
        if(i==0) continue;
        if(h[0]<h[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
