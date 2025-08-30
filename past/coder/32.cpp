#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        vector<vector<int>> hwall(h, vector<int>(w, 0));
        vector<vector<int>> vwall(h - 1, vector<int>(w, 0));
        rep(i, h) {
            rep(j, w-1) cin >> hwall[i][j];
            if(i<h-1) {
                rep(j, w) cin >> vwall[i][j];
            }
        }
        vector<vector<int>> dist(h, vector<int>(w, -1));
        queue<pair<int,int>> que;
        dist[0][0] = 1;
        que.push({0, 0});
        while(!que.empty()){
            auto [i, j] = que.front();
            que.pop();
            if(j+1<w && hwall[i][j]==0 && dist[i][j+1]==-1){
                dist[i][j+1]=dist[i][j]+1;
                que.push({i, j+1});
            }
            if(j-1>= 0 && hwall[i][j-1]==0 && dist[i][j-1]==-1){
                dist[i][j-1]=dist[i][j]+1;
                que.push({i, j-1});
            }
            if(i+1<h && vwall[i][j]==0 && dist[i+1][j]==-1){
                dist[i+1][j]=dist[i][j]+1;
                que.push({i+1, j});
            }
            if(i-1>=0 && vwall[i-1][j]==0 && dist[i-1][j]==-1){
                dist[i-1][j]=dist[i][j]+1;
                que.push({i-1, j});
            }
        }
        if(dist[h-1][w-1]==-1) cout << 0 << endl;
        else cout << dist[h-1][w-1] << endl;
    }
    
    return 0;
}
