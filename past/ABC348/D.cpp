#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, bool>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
struct State {
    int ene;
    int i;
    int j;
    int used;
    bool operator<(const State &other) const {
        return ene < other.ene;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int n;
    cin >> n;
    vector<vector<int>> med(h, vector<int>(w, -1));
    rep(i, n) {
        int r, c, e;
        cin >> r >> c >> e;
        r--; c--;
        med[r][c]=e;
    }
    int si, sj, gi, gj;
    rep(i, h) rep(j, w) {
        if(s[i][j]=='S') si=i, sj=j;
        if(s[i][j]=='T') gi=i, gj=j;
    }
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, -1)));
    if(med[si][sj]==-1) {
        cout << "No" << endl;
        return 0;
    }
    //1 : already
    //0 : yet
    priority_queue<State> pq;
    pq.push({med[si][sj], si, sj, 1});
    dist[si][sj][1]=med[si][sj];
    while(!pq.empty()) {
        auto [ene,i,j,used]=pq.top();
        pq.pop();
        if(i==gi && j==gj) {
            cout << "Yes" << endl;
            return 0;
        }
        if(ene<dist[i][j][used]) continue;
        if(med[i][j]!=-1 && used==0) {
            int ne=med[i][j];
            if(ne>dist[i][j][1]) {
                dist[i][j][1]=ne;
                pq.push({ne, i, j, 1});
            }
        }
        if(ene<=0) continue;
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            int ne=ene-1;
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#') continue;
            bool nu=med[ni][nj]==-1 ? 1:0;
            if(ne>dist[ni][nj][nu]) {
                dist[ni][nj][nu]=ne;
                pq.push({ne, ni, nj, nu});
            }
        }
    }
    cout << "No" << endl;

    return 0;
}