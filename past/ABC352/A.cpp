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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    bool flag=false;
    if(x<z && z<y) flag=true;
    if(y<z && z<x) flag=true;
    if(flag) Yes;
    else No;

    return 0;
}
