#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
using ll = long long;
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i, k) cin >> a[i];
    vector<int> pre(k+1), suf(k+1);
    for(int i=1; i<=k; i++) {
        pre[i]=pre[i-1];
        if(i%2==0) pre[i]+=a[i-1]-a[i-2];
    }
    for(int i=k-1; i>=0; i--) {
        suf[i]=suf[i+1];
        if((k-i)%2==0) suf[i]+=a[i+1]-a[i];
    }
    int ans=1e9;
    for(int i=0; i<=k; i+=2) ans=min(ans, pre[i]+suf[i]);
    cout << ans << endl;

    return 0;
}
