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
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> d(n-1);
    rep(i, n-1) d[i]=(p[i]<p[i+1] ? 1:-1);
    vector<int> pm, mp;
    rep(j, n-1) {
        if(d[j-1]==+1 && d[j]==-1) pm.push_back(j);
        if(d[j-1]==-1 && d[j]==+1) mp.push_back(j);
    }
    ll ans=0;
    rep(i, n-1) {
        if(d[i]!=1) continue;
        auto it_pm=upper_bound(all(pm), i);
        auto it_mp=upper_bound(all(mp), i);
        //nothing
        if(it_pm==pm.end() || it_mp==mp.end()) continue;
        int a=*it_pm;
        int b=*it_mp;
        int a2=(it_pm+1<pm.end() ? *(it_pm+1):INF);
        int b2=(it_mp+1<mp.end() ? *(it_mp+1):INF);
        int mn=max(i+3, max(a, b)+1);
        int mx=min({a2, b2, n-1});
        if(mn<=mx) ans+=ll(mx-mn+1);
    }
    cout << ans << endl;

    return 0;
}