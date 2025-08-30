#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;    
    string s;
    char c1, c2;
    cin >> n;
    cin >> c1 >> c2;
    cin >> s;
    rep(i, n) {
        if(s[i]==c1) {
            cout << c1;
        } else cout << c2;
    }
    cout << endl;
}