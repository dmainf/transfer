#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> k(n);
    rep(i, n) cin >> k[i];
    
    int ans=INT_MAX;
    rep(i, 1<<n) {
        int a=0, b=0;
        rep(bit, n) {
            if((i>>bit)&1) a+=k[bit];
            else b+=k[bit];
        }
        ans=min(ans, max(a, b));
    }
    cout << ans << endl;

    return 0;
}