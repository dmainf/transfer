#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,0,-1,0};
const int dj[]={0,1,0,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ans=INF;
    rep(pa, 2) {
        vector<vector<int>> dist(h, vector<int>(w, INF));
        queue<pi> que;
        auto push=[&](int i, int j, int d) {
            if(i<0 || h<=i || j<0 || w<=j) return;
            if(s[i][j]=='#') return;
            if(dist[i][j]!=INF) return;
            dist[i][j]=d;
            que.push({i, j});
        };
        rep(i, h) rep(j, w) if(s[i][j]=='S') push(i, j, 0);
        while(!que.empty()){
            auto [vi, vj]=que.front();
            que.pop();
            int d=dist[vi][vj];
            if(s[vi][vj]=='G') ans=min(ans, d);
            if((vi+vj)%2==pa) {
                push(vi-1, vj, d+1);
                push(vi+1, vj, d+1);
            } else {
                push(vi, vj-1, d+1);
                push(vi, vj+1, d+1);
            }
        }
    }
    if(ans==INF) ans=-1;
    cout << ans << endl;

    return 0;
}