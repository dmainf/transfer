#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,+0};
const int dj[]={+0,+1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    queue<pair<pi, set<int>>> que;
    set<int> tmp; tmp.insert(a[0][0]);
    que.push({{0, 0}, tmp});
    int ans=0;
    while(!que.empty()) {
        auto [now, st]=que.front();
        que.pop();
        auto [i, j]=now;
        if(i==h-1 && j==w-1) {
            if(st.size()==(h-1)+(w-1)+1) ans++;
            continue;
        }
        rep(v, 2) {
            int ni=i+di[v];
            int nj=j+dj[v];
            auto nst=st;
            if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
            nst.insert(a[ni][nj]);
            que.push({{ni, nj}, nst});
        }
    }
    cout << ans << endl;

    return 0;
}