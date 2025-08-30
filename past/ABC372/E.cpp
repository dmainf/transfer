#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    int n, q;
    cin >> n >> q;
    dsu uf(n);
    vector<set<int>> cnt(n);
    rep(i, n) cnt[i].insert(i);
    vector<int> ans;
    rep(qi, q) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru=uf.leader(u);
            int rv=uf.leader(v);
            if(ru==rv) continue;
            //ru<rv
            if(cnt[ru].size()<cnt[rv].size()) swap(ru, rv);
            uf.merge(ru, rv);
            int rnew=uf.leader(ru);
            int rold=(rnew==ru ? rv:ru);
            for (int x:cnt[rold]) cnt[rnew].insert(x);
            cnt[rold].clear();
        }
        if(com==2) {
            int v, k;
            cin >> v >> k;
            v--;
            if(cnt[uf.leader(v)].size()<k) ans.push_back(-1);
            else {
                auto it = cnt[uf.leader(v)].rbegin();
                advance(it, k-1);
                ans.push_back(*it+1);
            }
        }
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}