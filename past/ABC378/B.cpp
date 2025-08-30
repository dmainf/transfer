#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<int> r(109), q(109);
    cin >> n;
    rep(i, n) cin >> q[i] >> r[i];
    int Q;
    int t, d;
    cin >> Q;
    rep(i, Q) {
        cin >> t >> d;
        t--;
        d-=r[t];
        int ans=(d+q[t]-1)/q[t]*q[t];
        cout << ans+r[t] << endl;
    }
    
    return 0;
}