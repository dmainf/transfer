#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
const int di[]={1,1,0,-1,-1,-1,0,1};
const int dj[]={0,1,1,1,0,-1,-1,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true) {
        int w, h;
        cin >> w >> h;
        if(w==0 && h==0) break;
        vector<vector<int>> c(h, vector<int>(w));
        rep(i, h) rep(j, w) cin >> c[i][j];
        vector<vector<bool>> seen(h, vector<bool>(w, false));
        function<void(int, int)> dfs = [&](int i, int j) {
            seen[i][j]=true;
            rep(x, 8) {
                int ni=i+di[x]; 
                int nj=j+dj[x];
                if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
                if(seen[ni][nj]) continue;
                if(c[ni][nj]==0) continue;
                dfs(ni, nj);
            }
        };
        int cnt=0;
        rep(i, h) rep(j, w) {
            if(!(c[i][j])) continue;
            if(seen[i][j]) continue;
            dfs(i, j);
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
