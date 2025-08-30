#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pl = pair<ll, ll>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18+9;
/*
struct Human {
    int to;
    int x;
    int y;
};
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  n, m;
    cin >> n >> m;
    vector<vector<tuple<int, int, int>>> G(n);
    rep(i, m) {
        int a, b;
        int x, y;
        cin >> a >> b >> x >> y;
        a--; b--;
        G[a].push_back({b, x, y});
        G[b].push_back({a, -x, -y});
    }
    queue<int> que;
    que.push(0);
    vector<pl> p(n, {INF, INF});
    p[0]={0, 0};
    while(!que.empty()) {
        auto i=que.front();
        que.pop();
        for(auto [to, x, y]:G[i]) {
            if(p[to]!=pl(INF, INF)) continue;
            p[to] = {p[i].first+(ll)x, p[i].second+(ll)y};
            que.push(to);
        }
    }
    rep(i, n) {
        if(p[i]==pl(INF, INF)) cout << "undecidable" << endl;
        else cout << p[i].first << " " << p[i].second << endl;
    }
    
    return 0;
}
