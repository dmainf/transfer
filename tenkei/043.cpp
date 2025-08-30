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
struct Now {
    int i, j, v;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w; cin >> h >> w;
    int si, sj, gi, gj;
    cin >> si >> sj >>  gi >> gj;
    si--; sj--; gi--; gj--;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(4, INF)));
    // 0
    //1 3
    // 2
    rep(v, 4) dist[si][sj][v]=0;
    queue<Now> que;
    rep(v, 4) que.push({si, sj, v});
    while(!que.empty()) {
        auto [i, j, v]=que.front();
        que.pop();
        rep(nv, 4) {
            int ni=i+di[nv];
            int nj=j+dj[nv];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#') continue;
            int ncost=dist[i][j][v]+(v==nv ? 0:1);
            if(ncost<dist[ni][nj][nv]) {
                dist[ni][nj][nv]=ncost;
                que.push({ni, nj, nv});
            }
        }
    }
    cout << *min_element(all(dist[gi][gj])) << endl;

    return 0;
}