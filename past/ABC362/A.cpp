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
    int r, g, b;
    cin >> r >> g >> b;
    string c;
    cin >> c;
    if(c=="Red") cout << min(g, b) << endl;
    if(c=="Green") cout << min(r, b) << endl;
    if(c=="Blue") cout << min(r, g) << endl;

    return 0;
}