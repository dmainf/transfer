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
    vector<vector<int>> a(m);
    rep(mi, m) {
        int k;
        cin >> k;
        a[mi].resize(k);
        rep(ki, k) cin >> a[mi][ki];
    }
    vector<int> day(n+1);
    rep(i, n) {
        int b;
        cin >> b;
        day[b]=i;
    }
    vector<int> cnt(n+1, 0);
    //max day can eat
    rep(i, m) {
        int mx=0;
        for(auto x:a[i]) mx=max(mx, day[x]);
        cnt[mx]++;
    }
    int sum=0;
    rep(i, n) {
        sum+=cnt[i];
        cout << sum << endl;
    }

    return 0;
}