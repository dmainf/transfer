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
    int si, sj, gi, gj;
    cin >> si >> sj >> gi >> gj;
    si--; sj--; gi--; gj--;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    deque<pi> deq;
    auto push=[&](int i, int j, int d, int cost) {
        if(dist[i][j]<=d) return;
        dist[i][j]=d;
        if(cost==0) deq.push_front({i, j});
        else deq.push_back({i, j});
    };
    push(si, sj, 0, 0);
    while(deq.size()) {
        auto [i, j]=deq.front();
        deq.pop_front();
        if(seen[i][j]) continue;
        seen[i][j]=true;
        int d=dist[i][j];
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#') continue;
            push(ni, nj, d, 0);
        }
        rep(v, 4) {
            int ni=i;
            int nj=j;
            rep(k, 2) {
                ni+=di[v];
                nj+=dj[v];
                if(ni<0 || h<=ni) break;
                if(nj<0 || w<=nj) break;
                push(ni, nj, d+1, 1);
            }
        }
    }
    int ans=dist[gi][gj];
    cout << ans << endl;

    return 0;
}