#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<double, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
struct Edge {
    double wei;
    int v;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin >> n && n!=0) {
        vector<double> x(n), y(n), z(n), r(n);
        rep(i, n) cin >> x[i] >> y[i] >> z[i] >> r[i];
        vector<vector<Edge>> G(n);
        rep(i, n) rep(j, n) {
            double tmp;
            tmp=sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2)+pow(z[i]-z[j], 2));
            if(tmp<=r[i]+r[j]) tmp=0;
            else tmp-=r[i]+r[j];
            G[i].push_back({tmp, j});
            G[j].push_back({tmp, i});        
        }
        vector<int> used(n, false);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        used[0]=true;
        for(auto u:G[0]) pq.push({u.wei, u.v});
        double ans=0.0;
        while(!pq.empty()) {
            auto [w, u]=pq.top();
            pq.pop();
            if(used[u]) continue;
            used[u]=true;
            ans+=w;
            for(auto nu:G[u]) {
                if(used[nu.v]) continue;
                pq.push({nu.wei, nu.v});
            }
        }
        cout << fixed << setprecision(3) << ans << endl;
    }

    return 0;
}