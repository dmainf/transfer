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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int si, sj, gi, gj;
    rep(i, h) rep(j, w) {
        if(s[i][j]=='S') { si=i; sj=j; };
        if(s[i][j]=='G') { gi=i; gj=j; };
    }
    queue<tuple<int, int, int>> que;
    que.push({si, sj, 0});
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, -1)));
    dist[si][sj][0]=0;
    int cnt=0;
    while(!que.empty()) {
        auto [i, j, p]=que.front();
        que.pop();
        if(i==gi && j==gj) {
            cout << dist[i][j][p] << endl;
            return 0;
        }
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            int np=p;
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#') continue;
            if(s[ni][nj]=='o' && p==1) continue;
            if(s[ni][nj]=='x' && p==0) continue;
            if(s[ni][nj]=='?') np=1-p;
            if(dist[ni][nj][np]==-1) {
                dist[ni][nj][np]=dist[i][j][p]+1;
                que.push({ni, nj, np});
            }
        }
    }
    cout << -1 << endl;

    return 0;
}