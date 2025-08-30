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
    int h;
    cin >> h;
    long long plant=0;
    for(int i=0;; i++) {
        if(h<plant) {
            cout << i << endl;
            return 0;
        }
        plant+=(1<<i);
    }

    return 0;
}
