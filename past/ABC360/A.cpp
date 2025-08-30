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
    string s;
    cin >> s;
    int gohan=0, miso=0;
    rep(i, 3) {
        if(s[i]=='R') gohan=i;
        if(s[i]=='M') miso=i;
    }
    if(gohan<miso) Yes;
    else No;

    return 0;
}
