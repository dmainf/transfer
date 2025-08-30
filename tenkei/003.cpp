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
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);        
    }
    auto dfs=[&](const auto G, int s) {
        vector<int> dist(n, -1);
        dist[s]=0;
        stack<int> st;
        st.push(s);
        while(!st.empty()) {
            int v=st.top();
            st.pop();
            for(int nv:G[v]) {
                if(dist[nv]!=-1) continue;
                st.push(nv);
                dist[nv]=dist[v]+1;
            }
        }
        return dist;
    };
    vector<int> dist0=dfs(G, 0);
    int mx=-1, mv;
    rep(v, n) {
        if(mx<dist0[v]) {
            mx=dist0[v];
            mv=v;
        }
    }
    vector<int> dist_mv=dfs(G, mv);
    int ans=-1;
    rep(v, n) ans=max(ans, dist_mv[v]);
    cout << ans+1 << endl;

    return 0;
}