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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> seen(n, false);
    queue<int> que;
    rep(i, n) if(G[i].size()==1) {
        seen[i]=true;
        que.push(i);
        break;
    }
    while(!que.empty()) {
        if(1<que.size()) {
            NO;
            return 0;
        }
        int v=que.front();
        que.pop();
        for(int nv:G[v]) {
            if(nv==v) continue;
            if(seen[nv]) continue;
            seen[nv]=true;
            que.push(nv);
        }
    }
    bool flag=true;
    rep(i, n) if(!seen[i]) {
        flag=false;
    }
    if(flag) YES;
    else NO;

    return 0;
}