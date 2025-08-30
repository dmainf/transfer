#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> last;
    vector<int> ans(n);
    rep(i, n) {
        if(last.find(a[i]) != last.end()) ans[i]=last[a[i]];
        else ans[i]=-1;
        last[a[i]]=i+1;
    }
    rep(i, n) cout << ans[i] << " \n"[i==n-1];
    return 0;
}