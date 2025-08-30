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
    int n, d;
    cin >> n >> d;
    d*=d;
    vector<pi> human(n);
    rep(i, n) {
        int x, y; cin >> x >> y;
        human[i]={x, y};
    }
    vector<vector<int>> G(n);
    rep(i, n) rep(j, n) if(i!=j) {
        auto [ix, iy]=human[i];
        auto [jx, jy]=human[j];
        int tmp=(ix-jx)*(ix-jx)+(iy-jy)*(iy-jy);
        if(tmp<=d) G[i].push_back(j);
    }
    queue<int> que;
    que.push(0);
    vector<bool> seen(n, false);
    seen[0]=true;
    while(!que.empty()) {
        int v=que.front(); que.pop();
        for(int nv:G[v]) {
            if(seen[nv]) continue;
            que.push(nv);
            seen[nv]=true;
        }
    }
    rep(i, n) {
        if(seen[i]) YES;
        else NO;
    }

    return 0;
}