#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(n%2!=1) {
        cout << "No" << endl;
        return 0;
    }
    for(int i=0; i<n/2; i++) {
        if(s[i]!='1') {
            cout << "No" << endl;
            return 0;
        }
    }
    if(s[n/2]!='/') {
            cout << "No" << endl;
            return 0;   
    }
    for(int i=n/2+1; i<n; i++) {
        if(s[i]!='2') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

	return 0;
}