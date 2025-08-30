#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[0]=0; q.push(0);
    while(!q.empty()) {
        int v=q.front(); q.pop();
        for(auto u:to[v]) {
            if(dist[u]!=INT_MAX) continue;
            dist[u]=dist[v]+1;
            q.push(u);
        }
    }
    int ans=INT_MAX;
    rep(i, n) {
        for(auto u:to[i]) if(u==0 && dist[i]!=INT_MAX) {
            ans=min(ans, dist[i]+1);
        }
    }
    if(ans==INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}