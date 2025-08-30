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
    bool flag=true;
    rep(i, s.size()) {
        if(i==0 && !isupper(s[i])) flag=false;
        if(i!=0 && !islower(s[i])) flag=false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
