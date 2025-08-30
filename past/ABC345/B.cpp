#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x;
    cin >> x;
    if(x%10==0) cout << x/10 << endl;
    else if(x>=0) cout << x/10+1 << endl;
    else cout << x/10 << endl;

    return 0;
}
