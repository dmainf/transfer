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
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> b(n), w(m);
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int j = 0; j < m; j++){
        cin >> w[j];
    }
    sort(all(b), greater<ll>());
    sort(all(w), greater<ll>());
    vector<ll> preb(n+1, 0);
    for (int i = 0; i < n; i++){
        preb[i+1] = preb[i] + b[i];
    }
    vector<ll> exb(n+1, 0);
    exb[n] = 0;
    for (int i = n - 1; i >= 0; i--){
        exb[i] = exb[i+1] + (b[i] > 0 ? b[i] : 0);
    }
    vector<ll> prew(m+1, 0);
    for (int i = 0; i < m; i++){
        prew[i+1] = prew[i] + w[i];
    }
    
    ll ans = 0;
    int MAXi = min(n, m);
    for (int x = 0; x <= MAXi; x++){
        ll tmp = (preb[x] + exb[x]) + prew[x];
        ans = max(ans, tmp);
    }
    cout << ans << endl;

}