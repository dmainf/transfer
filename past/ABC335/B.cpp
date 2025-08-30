#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<=(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    rep(i, n) rep(j, n) rep(k, n) if(i+j+k<=n) {
        cout << i << " ";
        cout << j << " ";
        cout << k << endl;
    }

    return 0;
}
