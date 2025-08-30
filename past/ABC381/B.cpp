#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    if(n%2!=0){
        cout << "No" << endl;
        return 0; 
    }
    vector<char> c;
    rep(i, n/2) {
        c.push_back(s[2*i]);
        if(s[2*i]!=s[2*i+1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i, c.size()) {
        if(count(c.begin(), c.end(), c[i])!=1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

	return 0;
}