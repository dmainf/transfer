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
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    rep(i, n) {
        int c;
        cin >> c;
        rep(j, c) {
            int p;
            cin >> p;
            p--;
            G[i].push_back(p);
        }
    }
    vector<bool> done(n, false);
    vector<int> order;
    auto dfs=[&](auto dfs, int u) -> void {
        done[u]=true;
        for(int v:G[u]) {
            if(done[v]) continue;
            dfs(dfs, v);
        }
        order.push_back(u);
    };
    dfs(dfs, 0);
    for(int x:order) {
        x++;
        if(x==1) cout << endl;
        else cout << x << " ";
    }

    return 0;
}