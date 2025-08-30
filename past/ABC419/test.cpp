#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto conv=[&](const vector<ll>& a, const vector<ll>& b, int m) {
        vector<ll> c(m, INF);
        rep(i, m) rep(j, m) {
            c[i]=min(c[i], a[j]+b[(i-j+m)%m]);
        }
        return c;
    };
    auto f=[&](auto f, int l, int r, const vector<vector<ll>>& cost, int m) {
        if (l==r) return cost[l];
        int mid=l+(r-l)/2;
        vector<ll> left=f(f, l, mid, cost, m);
        vector<ll> right=f(f, mid+1, r, cost, m);
        return conv(left, right, m);
    };
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> cost(l, vector<ll>(m));
    rep(k, l) {
        vector<int> cnt(m, 0);
        int group=0;
        for(int i=k; i<n; i+=l) {
            cnt[a[i]%m]++;
            group++;
        }
        ll now=0;
        rep(v, m) now+=(ll)cnt[v]*((m-v)%m);
        cost[k][0]=now;
        for(int c=1; c<m; c++) {
            now+=(ll)group-(ll)m*cnt[c];
            cost[k][c]=now;
        }
    }
    vector<ll> ans=f(f, 0, l-1, cost, m);
    cout << ans[0] << endl;

    return 0;
}