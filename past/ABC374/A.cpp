#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    bool flag=true;
    if(s[s.size()-1]!='n') flag=false;
    if(s[s.size()-2]!='a') flag=false;
    if(s[s.size()-3]!='s') flag=false;

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
