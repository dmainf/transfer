#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int groups;
    vector<vector<int>> comp(h, vector<int>(w, -1));
    queue<pi> que;
    int num=0;
    rep(si, h) rep(sj, w) if(s[si][sj]=='#') {
        if(comp[si][sj]!=-1) continue;
        comp[si][sj]=num;
        que.push({si, sj});
        while(!que.empty()) {
            auto [i, j]=que.front();
            que.pop();
            rep(v, 4) {
                int ni=i+di[v];
                int nj=j+dj[v];
                if(ni<0 || h<=ni) continue;
                if(nj<0 || w<=nj) continue;
                if(s[ni][nj]!='#') continue;
                if(comp[ni][nj]!=-1) continue;
                que.push({ni, nj});
                comp[ni][nj]=num;
            }
        }
        num++;
    }
    ll shi=0;
    ll bo=0;
    rep(i, h) rep(j, w) if(s[i][j]=='.') {
        bo++;
        set<int> st;
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]!='#') continue;
            st.insert(comp[ni][nj]);
        }
        shi+=num-(st.size()-1);
    }
    //shi/bo=R
    //shi%=R*bo
    mint p=shi;
    mint q=bo;
    mint ans=p*q.inv();
    cout << ans.val() << endl;

    return 0;
}