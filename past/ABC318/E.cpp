#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> cnt(n+1, 0);
    vector<ll> sum(n+1, 0);
    ll ans=0;
    auto c3=[&](ll n) { return n*(n-1)*(n-2)/6; };
    rep(k, n) {
        //i<j<k
        //j=i+1,i+2,...,k-1
        //1つのi,kに(k-i-1)通りのj
        //iをkまで動かす
        ans+=ll(k-1)*cnt[a[k]]-sum[a[k]];
        cnt[a[k]]++;
        sum[a[k]]+=k;
    }
    rep(i, n) ans-=c3(cnt[i+1]);
    cout << ans << endl;

    return 0;
}