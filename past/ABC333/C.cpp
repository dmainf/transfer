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
    vector<ll> a;
    a.push_back(1);
    rep(i, 19) a.push_back(a.back()*10+1);
    set<ll> s;
    rep(i, 19) rep(j, 19) rep(k, 19) {
        s.emplace(a[i]+a[j]+a[k]);
    }
    int cnt=0;
    for(ll v:s) {
        cnt++;
        if(cnt==n) {
            cout << v << endl;
            return 0;
        }
    }

    return 0;
}