#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans=0;
    int r=0;
    rep(l, n) {
        while(r<n) {
            if(r>l+1 && a[r]-a[r-1] != a[r-1]-a[r-2]) break;
            r++; 
        }
        ans+=r-l;
    }
    cout << ans << endl;
    return 0;
}
