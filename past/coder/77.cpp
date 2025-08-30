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
const int MOD=1e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> s(n);
    s[0]=0;
    rep(i, n-1) {
        int tmp;
        cin >> tmp;
        s[i+1]=s[i]+tmp;
    }
    int cor=0;
    ll ans=0;
    int dist=0;
    rep(i, m) {
        int a;
        cin >> a;
        dist=cor+a;
        int l = min(cor, dist), r = max(cor, dist);
        ans = (ans + (s[r] - s[l]) % MOD) % MOD;
        cor = dist;
    }
    cout << ans << endl;

    return 0;
}