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
    int b, g;
    cin >> b >> g;
    if(b<g) cout << "Glove" << endl;
    else cout << "Bat" << endl;

    return 0;
}
