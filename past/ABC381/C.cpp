#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
bool check1122(string s) {
    int n=s.size();
    if(n%2!=1) 
        return false;
    for(int i=0; i<n/2; i++) {
        if(s[i]!='1') {
            return false;
        }
    }
    if(s[n/2]!='/') {
            return false;   
    }
    for(int i=n/2+1; i<n; i++) {
        if(s[i]!='2') {
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<string> ans;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            string tmp=s.substr(i, j-i+1);
            if(check1122(tmp)) {
                ans.push_back(tmp);
            }
        }
    }
    int answer=0;
    rep(i, ans.size()) {
        int tmp=ans[i].size();
        answer=max(answer, tmp);
    }
    cout << answer << endl;

	return 0;
}