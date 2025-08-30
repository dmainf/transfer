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
    vector<vector<int>> G(n);
    vector<int> deg(n, 0);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        deg[y]++;
    }
    queue<int> que;
    rep(i, n) if(deg[i]==0) {
        que.push(i);
    }
    vector<int> ans;
    while(!que.empty()) {
        if(1<que.size()) {
            NO;
            return 0;
        }
        int v=que.front();
        que.pop();
        for(int nv:G[v]) {
            deg[nv]--;
            if(deg[nv]==0) que.push(nv);
        }
        ans.push_back(v);
    }
    YES;
    vector<int> A(n);
    rep(i, n) A[ans[i]]=i+1;
    for(int x:A) cout << x << " ";
    cout << endl;

    return 0;
}