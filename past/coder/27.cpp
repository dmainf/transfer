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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> ice(n, vector<int>(m));
    rep(i, n) rep(j, m) cin >> ice[i][j];
    int ans=0;
    vector<vector<int>> seen(n, vector<int>(m, false));
    function<void(int, int, int, vector<vector<int>>&)> dfs = [&](int i, int j, int cnt, vector<vector<int>>& seen) {
        ans=max(ans, cnt);
        rep(x, 4) {
            int ni=i+di[x];
            int nj=j+dj[x];
            if(ni<0 || n<=ni || nj<0 || m<=nj) continue;
            if(!(ice[ni][nj])) continue;
            if(seen[ni][nj]) continue;
            seen[ni][nj]=true;
            dfs(ni, nj, cnt+1, seen);
            seen[ni][nj]=false;
        }
    };
    rep(i, n) rep(j, m) {
        if(ice[i][j]) {
            seen[i][j]=true;
            dfs(i, j, 1, seen);
            seen[i][j]=false;
        }
    }
    cout << ans << endl;

    return 0;
}