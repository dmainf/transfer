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
    multiset<int> ms;
    rep(i, n) {
        int a;
        cin >> a;
        ms.insert(a);
    }
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    ll ans=0;
    rep(i, m) {
        auto it=ms.lower_bound(b[i]);
        if(it==ms.end()) {
            cout << -1 << endl;
            return 0;
        }
        ans+=*it;
        ms.erase(it);
    }
    cout << ans << endl;

    return 0;
}