#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const ll di[]={+1,-1,+0,+0};
const ll dj[]={+0,+0,+1,-1};
const ll INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    int W=1<<10;
    vector<vector<pi>> G(n);
    rep(i, m) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back({b, w});
    }
    //(v, x)：いま頂点vにいるときXORの状態x
    vector<bool> seen(n*W, false);
    queue<int> que;
    auto push=[&](int v, int w) {
        int tmp=v*W+w;
        if(seen[tmp]) return;
        seen[tmp]=true;
        que.push(tmp);
    };
    push(0, 0);
    while(que.size()) {
        int tmp=que.front();
        que.pop();
        int v=tmp/W, x=tmp%W;
        for(auto [nv, nw]:G[v]) push(nv, x^nw);
    }
    rep(x, W) {
        if(seen[(n-1)*W+x]) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}