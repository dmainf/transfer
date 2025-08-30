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
#include <atcoder/all>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  n, m;
    cin >> n >> m;
    dsu uf(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf.merge(u, v);
    }
    int k;
    cin >> k;
    set<pi> dame;
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        dame.insert({uf.leader(x), uf.leader(y)});
        dame.insert({uf.leader(y), uf.leader(x)});        
    }
    int q;
    cin >> q;
    vector<bool> ans;
    while(q--) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        if(0<dame.count({uf.leader(p), uf.leader(q)})) ans.push_back(false);
        else ans.push_back(true);
    }
    for(bool flag:ans) {
        if(flag) YES;
        else NO;
    }

    return 0;
}