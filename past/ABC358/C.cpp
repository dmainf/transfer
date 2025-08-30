#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int ans=INT_MAX;
	rep(x, 1<<n) {
        vector<bool> flag(m, false);
		rep(bit, n) {
            if((x>>bit)&1) {
                rep(j, m) if(s[bit][j]=='o') flag[j]=true; 
            }
        }
        bool check=true;
        rep(j, m) if(flag[j]!=true) check=false;
        if(check) ans=min(ans, __builtin_popcount(x));
    }
    cout << ans << endl;

    return 0;
}