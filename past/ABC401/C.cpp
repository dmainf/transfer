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
const ll MOD=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n+1, 1);
    vector<ll> pre(n+2, 0);
    for(int i=0; i<n+1; i++) {
        pre[i+1]=(pre[i]+a[i])%MOD;
    }
    for(int i=k; i<=n; i++) {
        a[i]=(pre[i]-pre[i-k]+MOD)%MOD;;
        pre[i+1]=(pre[i]+a[i])%MOD;
    }
    cout << a[n] << endl;

    return 0;
}