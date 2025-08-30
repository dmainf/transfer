#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    vector<pi> ans;
    while(t--) {
        ll n; cin >> n;
        for(ll x=2;; x++) {
            if(n%x!=0) continue;
            n/=x;
            if(n%x==0) {    //x is p2
                ans.push_back({x, n/x});
            } else {        //x is q
                ll p=sqrt(n);
                ans.push_back({p, x});
            }
            break;
        }
    }
    for(auto [p, q]:ans) cout << p << " " << q << endl;

    return 0;
}