#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    int t[109], l[109];
    cin >> n >> d;
    rep(i, n) cin >> t[i] >> l[i];
    
    int ans=0;
    rep(j, d) {
        rep(i, n) {
            ans=max(ans, t[i]*(l[i]+j+1));
        }
        cout << ans << endl;
        ans=0;
    }

	return 0;
}