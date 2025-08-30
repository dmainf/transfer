#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> len(n);
    rep(i, n) cin >> len[i];
    auto check=[&](ll wide) -> bool {
        int line=1;
        ll tmp=0;
        rep(i, n) {
            if (len[i]>wide) return false;
            if(wide<tmp+(ll)len[i]) {
                line++;
                tmp=0;
            }
            tmp+=len[i]+1;
        }
        return line<=m;
    };
    ll l=0, r=1e18;
    while(l<=r) {
        ll mid=(l+r)/2;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    ll ans=l;
    cout << ans << endl;

    return 0;
}