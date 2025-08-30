#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=1;i<=(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, ll>;
const ll di[]={1,-1,0,0};
const ll dj[]={0,0,1,-1};
const ll INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll b;
    cin >> b;
    rep(i, INF) {
        ll tmp=1;
        rep(j, i) {
            if(tmp*i>b) {
                cout << -1 << endl;
                return 0;
            }
            tmp*=i;
        }
        if(tmp==b) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}