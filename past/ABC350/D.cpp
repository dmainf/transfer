#include <bits/stdc++.h>
using namespace std;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> visited(n, false);
    ll ans=0;
    rep(i, n) {
        if(visited[i]) continue;
        visited[i]=true;
        queue<int> q;
        q.push(i);
        int size=0;
        int follow=0;
        while(!q.empty()) {
            int v=q.front();
            q.pop();
            size++;
            follow+=G[v].size();
            for(auto u:G[v]) {
                if(visited[u]) continue;
                visited[u]=true;
                q.push(u);
            }
        }
        ans+=(ll)size*(size-1)/2-(ll)follow/2;
    }
    cout << ans << endl;

    return 0;
}
