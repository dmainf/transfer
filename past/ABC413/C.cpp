#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    deque<pi> p;
    vector<ll> ans;
    while(q--) {
        int op; cin >> op;
        if(op==1) {
            int c, x; cin >> c >> x;
            p.push_back({x, c});
        }
        if(op==2) {
            int k; cin >> k;
            ll sakujo=0;
            while(0<k) {
                if(p.front().second<=k) {
                    sakujo+=(ll)p.front().first*p.front().second;
                    k-=p.front().second;
                    p.pop_front();
                } else {
                    sakujo+=(ll)p.front().first*k;
                    p.front().second-=k;
                    k=0;
                }
            }
            ans.push_back(sakujo);
        }
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}