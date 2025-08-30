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
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    bool flag=false;
    if(a[0]*a[1]==a[2]) flag=true;
    if(a[0]*a[2]==a[1]) flag=true;
    if(a[1]*a[2]==a[0]) flag=true;
    if(flag) Yes;
    else No;

    return 0;
}