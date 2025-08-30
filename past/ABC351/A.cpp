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
    int takahashi=0, aoki=0;
    rep(i, 9) {
        int a;
        cin >> a;
        takahashi+=a;
    }
    rep(i, 8) {
        int b;
        cin >> b;
        aoki+=b;
    }
    cout << takahashi-aoki+1 << endl;

    return 0;
}
