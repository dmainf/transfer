#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, si, sj, gi, gj;
    cin >> r >> c;
    cin >> si >> sj;
    cin >> gi >> gj;
    si--; sj--; gi--; gj--;
    vector<string> s(r);
    rep(i, r) cin >> s[i];
    vector<vector<int>> dist(r, vector<int>(c, -1));
    queue<pair<int, int>> que;
    dist[si][sj]=0;
    que.push({si, sj});
    while(!que.empty()) {
        pair<int, int> v=que.front();
        que.pop();
        rep(i, 4) {
            int ni=v.first+di[i];
            int nj=v.second+dj[i];
            if(ni<0 || r<=ni || nj<0 || c<=nj) continue;
            if(s[ni][nj]=='#' || dist[ni][nj]!=-1) continue;
            dist[ni][nj]=dist[v.first][v.second]+1;
            que.push({ni, nj});
        }
    }
    cout << dist[gi][gj] << endl;

    return 0;
}
