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
    ll x=0;
    rep(i, m+1) {
        ll tmp=1;
        rep(j, i) tmp*=n;
        x+=tmp;
        if(x>1e9) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << x << endl;

    return 0;
}