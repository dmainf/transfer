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
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]%=m;
    vector<int> s(n+1);
    rep(i, n) s[i+1]=(s[i]+a[i])%m;
    int L=s[n];
    ll ans=0;
    vector<int> cnt(m);
    rep(i, n) cnt[s[i]]++;
    rep(r, n) {
        ans+=cnt[s[r]];
        ans+=cnt[(s[r]-L+m)%m];
        cnt[s[r]]++;
    }
    cout << ans << endl;
 
    return 0;
}