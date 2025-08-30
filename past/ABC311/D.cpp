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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    queue<pi> que;
    que.push({1, 1});
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    seen[1][1]=true;
    while(!que.empty()) {
        auto [i, j]=que.front();
        que.pop();
        rep(v, 4) {
            bool flag=false;
            int ni=i;
            int nj=j;
            while(s[ni][nj]!='#') {
                ni+=di[v];
                nj+=dj[v];
                if(!seen[ni][nj]) flag=true;
                seen[ni][nj]=true;
            }
            if(flag) que.push({ni-di[v], nj-dj[v]});
        }
    }
    int ans=0;
    rep(i, n) rep(j, m) {
        if(seen[i][j] && s[i][j]=='.') ans++;
    }
    cout << ans << endl;

    return 0;
}