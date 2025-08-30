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
    vector<vector<bool>> x(h, vector<bool>(w, false));
    rep(i, h) rep(j, w) if(s[i][j]=='#') {
        x[i][j]=true;
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            x[ni][nj]=true;
        }
    }
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<vector<int>> last(h, vector<int>(w));
    int time=0;
    int ans=1;
    rep(si, h) rep(sj, w) if(!x[si][sj]) {
        if(seen[si][sj]) continue;
        time++;
        int sum=0;
        queue<pi> que;
        que.push({si, sj});
        seen[si][sj]=true;
        while(!que.empty()) {
            auto [i, j]=que.front();
            que.pop();
            sum++;
            rep(v, 4) {
                int ni=i+di[v];
                int nj=j+dj[v];
                if(ni<0 || h<=ni) continue;
                if(nj<0 || w<=nj) continue;
                if(seen[ni][nj]) continue;
                if(x[ni][nj]) {
                    if(last[ni][nj]!=time) {
                        sum++;
                        last[ni][nj]=time;
                    }
                    continue;
                }
                que.push({ni, nj});
                seen[ni][nj]=true;
            }
        }
        ans=max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}