#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
using Graph = vector<vector<int>>; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h;
    cin >> w >> h;
    w+=2; h+=2;
    vector<vector<int>> s(h, vector<int>(w, -1));
    for(int i=1; i<h-1; i++) for(int j=1; j<w-1; j++) {
        cin >> s[i][j];
    }
    int ans=0;
    queue<pi> que;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    que.push({0, 0});
    seen[0][0]=true;
    while(!que.empty()) {
        auto [vi, vj]=que.front();
        que.pop();
        if(vi%2==0) {
            int di[]={-1, -1, 0, 0, 1, 1};
            int dj[]={0, -1, 1,-1, 0,-1};
            rep(i, 6) {
                int ni=vi+di[i];
                int nj=vj+dj[i];
                if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
                if(s[ni][nj]==1) {
                    ans++;
                    continue;
                }
                if(seen[ni][nj]) continue;
                seen[ni][nj]=true;
                que.push({ni, nj});
            }
        } else {
            int di[6]={-1, -1, 0, 0, 1, 1};
            int dj[6]={ 1,  0, 1,-1, 1, 0};
            rep(i, 6) {
                int ni=vi+di[i];
                int nj=vj+dj[i];
                if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
                if(s[ni][nj]==1) {
                    ans++;
                    continue;
                }
                if(seen[ni][nj]) continue;
                seen[ni][nj]=true;
                que.push({ni, nj});
            }
        }
    }
    cout << ans << endl;

    return 0;
}