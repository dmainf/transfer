#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    vector<string> s=a;
    rep(i, h) {
        bool flag=false;
        rep(j, w) {
            if(a[i][j]=='>') flag=true;
            if(a[i][j]!='>' && a[i][j]!='.') flag=false;
            if(flag) s[i][j]='#';
        }
        for(int j=w-1; j>=0; j--) {
            if(a[i][j]=='<') flag=true;
            if(a[i][j]!='<' && a[i][j]!='.') flag=false;
            if(flag) s[i][j]='#';
        }
    }
    rep(j, w) {
        bool flag=false;
        rep(i, h) {
            if(a[i][j]=='v') flag=true;
            if(a[i][j]!='v' && a[i][j]!='.') flag=false;
            if(flag) s[i][j]='#';
        }
        for(int i=h-1; i>=0; i--) {
            if(a[i][j]=='^') flag=true;
            if(a[i][j]!='^' && a[i][j]!='.') flag=false;
            if(flag) s[i][j]='#';
        }
    }
    int si, sj, gi, gj;
    rep(i, h) rep(j, w) {
        if(a[i][j]=='S') si=i, sj=j;
        if(a[i][j]=='G') gi=i, gj=j;
    }
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[si][sj]=0;
    queue<pi> que;
    que.push({si, sj});
    while(!que.empty()) {
        auto [i, j]=que.front();
        que.pop();
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#') continue;
            if(dist[ni][nj]!=-1) continue;
            que.push({ni, nj});
            dist[ni][nj]=dist[i][j]+1;
        }
    }
    cout << dist[gi][gj] << endl;

    return 0;
}