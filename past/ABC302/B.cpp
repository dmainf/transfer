#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0,+1,+1,-1,-1};
const int dj[]={+0,+0,+1,-1,+1,-1,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    string snuke="snuke";
    rep(i, h) rep(j, w) {
        rep(v, 8) {
            vector<pi> ans;
            int ni=i, nj=j;
            rep(k, snuke.size()) {
                if(s[ni][nj]!=snuke[k]) break;
                ans.push_back({ni+1, nj+1});
                ni+=di[v];
                nj+=dj[v];
                if(ni<0 || h<=ni || nj<0 || w<=nj) break;
            }
            if(ans.size()==snuke.size()) {
                for(auto [x, y]:ans) cout << x << " " << y << endl;
                return 0;
            }
        }
    }

    return 0;
}