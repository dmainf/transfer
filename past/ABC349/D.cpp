#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, ll>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    auto f=[&](ll x) -> int {
        if(x==0) return 63;
        int ret=0;
        while(x%2==0) {
            ret++;
            x/=2;
        }
        return ret;
    };
    vector<pi> ans;
    while(l!=r) {
        int dev;
        if(l==0) for(dev=0; (1LL<<(dev+1))<=r; dev++);
        else dev=f(l);
        ll re=l/(1LL<<dev);
        while((1LL<<dev)*(re+1)>r){
            dev--;
            re*=2;
        }
        ans.push_back({(1LL<<dev)*re, (1LL<<dev)*(re+1)});
        l=(1LL<<dev)*(re+1);
    }
    cout << ans.size() << endl;
    for(auto [li, ri]:ans) {
        cout << li << " " << ri << endl;
    }

    return 0;
}