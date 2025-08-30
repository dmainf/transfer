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
#include <atcoder/all>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    vector<int> u(m), v(m);
    rep(i, m) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        uf.merge(u[i], v[i]);
    }
    vector<int> point(n, 0), edge(n, 0);
    rep(i, n) point[uf.leader(i)]++;
    rep(i, m) edge[uf.leader(u[i])]++;
    if(point==edge) YES;
    else NO;

    return 0;
}