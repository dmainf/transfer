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
    string s1, s2;
    cin >> s1 >> s2;
    int ans;
    if(s1=="fine") {
        if(s2=="fine") ans=4;
        else ans=3;
    } else {
        if(s2=="fine") ans=2;
        else ans=1;
    }
    cout << ans << endl;

    return 0;
}