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
#include <atcoder/dsu>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    dsu uf(n);
    vector<int> cnt(n, 0);
    vector<bool> isblack(n, false);
    vector<bool> ans;
    while(q--) {
        int op, v; cin >> op >> v;
        v--;
        if(op==1) {
            int u; cin >> u;
            u--;
            if(!uf.same(v, u)) {
                //dont know which is new root
                int vr=uf.leader(v);
                int ur=uf.leader(u);
                int nroot=uf.merge(v, u);
                cnt[nroot]=cnt[vr]+cnt[ur];
            }
        }
        if(op==2) {
            if(isblack[v]) {
                isblack[v]=false;
                cnt[uf.leader(v)]--;
            } else {
                isblack[v]=true;
                cnt[uf.leader(v)]++;
            }
        }
        if(op==3) {
            if(0<cnt[uf.leader(v)]) ans.push_back(true);
            else ans.push_back(false);
        }
    }
    for(bool x:ans) {
        if(x) YES;
        else NO;
    }

    return 0;
}