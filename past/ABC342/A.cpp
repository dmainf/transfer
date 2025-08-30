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
    string s;
    cin >> s;
    for(int i=1; i<s.size()-1; i++) {
        if(s[i-1]!=s[i] && s[i]!=s[i+1]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    if(s[0]!=s[1]) cout << 1 << endl;
    else cout << s.size() << endl;

    return 0;
}
