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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    auto solve=[&](int v) -> char {
        if(v==0) return '^';
        if(v==1) return 'v';
        if(v==2) return '<';
        if(v==3) return '>';
        return '?';
    };
    vector<string> ans=s;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pi> que;
    rep(si, h) rep(sj, w) if(s[si][sj]=='E') {
        que.push({si, sj});
        dist[si][sj]=0;
    }
    while(!que.empty()) {
        auto [i, j]=que.front();
        que.pop();
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#') continue;
            if(dist[ni][nj]!=-1) continue;
            ans[ni][nj]=solve(v);
            dist[ni][nj]=dist[i][j]+1;
            que.push({ni, nj});
        }
    }
    rep(i, h) cout << ans[i] << endl;

    return 0;
}