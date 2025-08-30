#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
using Graph = vector<vector<int>>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    queue<pi> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0]=0;
    que.push({0, 0});
    while(!que.empty()) {
        auto [vi,vj]=que.front();
        que.pop();
        rep(i, 4) {
            int ni=vi+di[i];
            int nj=vj+dj[i];
            if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#' || dist[ni][nj]!=-1) continue;
            dist[ni][nj]=dist[vi][vj]+1;
            que.push({ni, nj});
        }
    }
    int white=0;
    rep(i, h) rep(j, w) if(s[i][j]=='.') white++;
    if(dist[h-1][w-1]==-1) cout << -1 << endl;
    else cout << white-(dist[h-1][w-1]+1) << endl;

    return 0;
}