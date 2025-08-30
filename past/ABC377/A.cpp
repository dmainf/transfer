#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool flag=true;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s=="ABC") cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
