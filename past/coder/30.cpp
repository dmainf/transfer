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
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<pi> fac(n+1);
    rep(i, h) rep(j, w) {
        if(s[i][j]=='S') fac[0]={i, j};
        if('1'<=s[i][j] && s[i][j]<='9') {
            int num=s[i][j]-'0';
            fac[num]={i, j};
        }
    }
    int ans=0;
    auto bfs=[&](int si, int sj, int gi, int gj) {
        vector<vector<int>> dist(h, vector<int>(w, -1));
        queue<pi> que;
        dist[si][sj]=0;
        que.push({si, sj});
        while(!que.empty()) {
            pi v=que.front();
            que.pop();
            rep(i, 4) {
                int ni=v.first+di[i];
                int nj=v.second+dj[i];
                if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
                if(s[ni][nj]=='X' || dist[ni][nj]!=-1) continue;
                dist[ni][nj]=dist[v.first][v.second]+1;
                que.push({ni, nj});
            }
        }
        ans+=dist[gi][gj];
    };
    rep(i, n) {
        bfs(fac[i].first, fac[i].second, fac[i+1].first, fac[i+1].second);
    }
    cout << ans << endl;

    return 0;
}