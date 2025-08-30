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
    int n; cin >> n;
    vector<vector<int>> G(n);
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    que.push(0);
    vector<int> seen(n, -1);
    seen[0]=0;
    while(!que.empty()) {
        int v=que.front();
        que.pop();
        for(int nv:G[v]) {
            if(seen[nv]!=-1) continue;
            seen[nv]=(seen[v]==0 ? 1:0);
            que.push(nv);
        }
    }
    vector<int> white, black;
    rep(v, n) {
        if(seen[v]==0) white.push_back(v+1);
        else black.push_back(v+1);
    }
    auto output=[&](vector<int> tmp) {
        rep(i, n/2) {
            if(i!=0) cout << " ";
            cout << tmp[i];
        }
        cout << endl;
    };
    if(white.size()>=n/2) output(white);
    else output(black);

    return 0;
}