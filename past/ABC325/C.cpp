#include <bits/stdc++.h>
using namespace std;
#define rep(hi, n) for(int hi=0;hi<(n);hi++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0,1,1,-1,-1};
const int dj[]={0,0,1,-1,1,-1,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(hi, h) cin >> s[hi];
    int ans=0;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    queue<pi> que;
    rep(hi, h) rep(wi, w) if(!seen[hi][wi] && s[hi][wi]=='#') {
        ans++;
        seen[hi][wi]=true;
        que.push({hi, wi});
        while(!que.empty()) {
            auto [i, j]=que.front();
            que.pop();
            rep(v, 8) {
                int ni=i+di[v];
                int nj=j+dj[v];
                if(ni<0 || h<=ni) continue;
                if(nj<0 || w<=nj) continue;
                if(seen[ni][nj]) continue;
                if(s[ni][nj]!='#') continue;
                seen[ni][nj]=true;
                que.push({ni, nj});
            }
        }
    }
    cout << ans << endl;

    return 0;
}