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
    int n, q;
    cin >> n >> q;
    vector<set<int>> G(n);
    int now=n;
    while(q--) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(G[u].empty()) now--;
            if(G[v].empty()) now--;
            G[u].insert(v);
            G[v].insert(u);
        }
        if(com==2) {
            int v;
            cin >> v;
            v--;
            for(int nv:G[v]) {
                G[nv].erase(v);
                if(G[nv].empty()) now++;
            }
            if(!G[v].empty()) {
                G[v].clear();
                now++;
            }
        }
        cout << now << endl;
    }

    return 0;
}