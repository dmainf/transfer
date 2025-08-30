#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> ans; int count=0;
    rep(i, s.size()) {
        if(i==0) continue;
        if(s[i]=='|') {
            ans.push_back(count);
            count=0;
        } else {
            count++;
        }
    }

    rep(i, ans.size()) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
	return 0;
}