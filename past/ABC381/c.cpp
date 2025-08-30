#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; string s;
    cin >> n >> s;

    s="$"+s+"$";
    n=s.size();
    vector<int> ans;
    rep(i, n) if (s[i]=='/') {
        int x=1;
        while(s[i-x]=='1' && s[i+x]=='2') x++;
        int now=2*x-1;
        ans.push_back(now);
    }
    int answer=0;
    rep(i, ans.size()) {
        answer=max(answer, ans[i]);
    }
    cout << answer << endl;

	return 0;
}