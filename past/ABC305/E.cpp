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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);        
    }
    vector<int> HP(n, -1);
    priority_queue<pi, vector<pi>, less<pi>> pq;
    rep(i, k) {
        int p, h;
        cin >> p >> h;
        p--;
        HP[p]=h;
        pq.push({h, p});
    }
    while(!pq.empty()) {
        auto [h, v]=pq.top();
        pq.pop();
        if(h<HP[v]) continue;
        for(int nv:G[v]) {
            int nh=h-1;
            if(HP[nv]<nh) {
                HP[nv]=nh;
                pq.push({nh, nv});
            }
        }
    }
    vector<int> ans;
    rep(i, n) if(0<=HP[i]) {
        ans.push_back(i+1);
    }
    sort(all(ans));
    cout << ans.size() << endl;
    for(int x:ans) cout << x << " ";
    cout << endl;

    return 0;
}