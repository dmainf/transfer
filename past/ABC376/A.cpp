#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    int ans=0;
    int last=0;
    rep(i, n) {
        if(i==0) {
            ans++;
            last=t[i];
            continue;
        }
        if(t[i]-last>=c) {
            ans++;
            last=t[i]; 
        }
    }
    cout << ans << endl;
    return 0;
}
