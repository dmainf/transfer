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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int si=0, sj=0;
    int gi=h-1, gj=w-1;
    //snuke
    queue<pi> que;
    que.push({si, sj});
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[si][sj]=0;
    if(s[si][sj]!='s') {
        NO;
        return 0;
    }
    string snuke="snuke";
    while(!que.empty()) {
        auto [i, j]=que.front();
        que.pop();
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(dist[ni][nj]!=-1) continue;
            int tmp=(dist[i][j]+1)%5;
            if(snuke[tmp]!=s[ni][nj]) continue;
            dist[ni][nj]=tmp;
            que.push({ni, nj});
        }
    }
    if(dist[gi][gj]==-1) NO;
    else YES;

    return 0;
}