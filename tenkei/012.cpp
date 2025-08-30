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
#include <atcoder/dsu>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    int q; cin >> q;
    vector<vector<bool>> b(h, vector<bool>(w, false));
    dsu uf(h*w);
    vector<bool> ans;
    while(q--) {
        int op; cin >> op;
        if(op==1) {
            int r, c; cin >> r >> c;
            r--; c--;
            b[r][c]=true;
            if(r+1<h && b[r+1][c]) uf.merge(r*w+c, (r+1)*w+c);
            if(c+1<w && b[r][c+1]) uf.merge(r*w+c, r*w+(c+1));
            if(0<=r-1 && b[r-1][c]) uf.merge(r*w+c, (r-1)*w+c);
            if(0<=c-1 && b[r][c-1]) uf.merge(r*w+c, r*w+(c-1));
        }
        if(op==2) {
            int sr, sc, gr, gc;
            cin >> sr >> sc >> gr >> gc;
            sr--; sc--; gr--; gc--;
            if(!(b[sr][sc] && b[gr][gc])) {
                ans.push_back(false);
                continue;
            }
            if(uf.same(sr*w+sc, gr*w+gc)) ans.push_back(true);
            else ans.push_back(false);
        }
    }
    for(bool x:ans) {
        if(x) YES;
        else NO;
    }

    return 0;
}