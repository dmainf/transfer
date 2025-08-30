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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> s(n+1);
    rep(i, n) s[i+1]=s[i]^a[i];
    n++;
    ll ans=0;
    //xorが1のときだけ数えればいい(総和に影響するのは1のときだけ)
    //xorが1になるのは(0,1),(1,0)のみ
    rep(bit, 30) {
        int one=0;
        rep(i, n) if((s[i]>>bit)&1) one++;
        ans+=(ll)one*(n-one)*(1<<bit);
    }
    n--;
    //長さ1を引く
    rep(i, n) ans-= a[i];
    cout << ans << endl;

    return 0;
}