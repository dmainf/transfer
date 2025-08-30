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
const int MAX=1e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    rep(i, m) {
        int tmp;
        cin >> tmp;
        tmp--;
        p[i]=tmp;
    }
    vector<int> train(MAX+1, 0);
    rep(i, m-1) {
        int l=p[i], r=p[i+1];
        if(r<l) swap(l, r);
        train[l]++;
        train[r]--;
    }
    for(int i=1; i<=MAX; i++) train[i]+=train[i-1];
    vector<int> a(n), b(n), c(n);
    rep(i, n-1) cin >> a[i] >> b[i] >> c[i];
    ll ans=0;
    rep(i, n-1) {
        ans+=min((ll)train[i]*a[i], (ll)train[i]*b[i]+c[i]);
    }
    cout << ans << endl;

    return 0;
}