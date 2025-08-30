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
const int MAX=1e6;
struct Circle {
    double x;
    double y;
    double r;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Circle> cir(n);
    rep(i, n) cin >> cir[i].x >> cir[i].y >> cir[i].r;
    vector<double> x(m), y(m);
    rep(i, m) cin >> x[i] >> y[i];
    if(m==0){
        double ans = numeric_limits<double>::max();
        rep(i, n) ans=min(ans, cir[i].r);
        cout << fixed << setprecision(10) << ans << endl;
        return 0;
    }
    vector<vector<double>> dist(m);
    rep(i, m) rep(j, n) {
        double tmp;
        tmp=sqrt(pow(x[i]-cir[j].x, 2)+pow(y[i]-cir[j].y, 2));
        tmp-=cir[j].r;
        dist[i].push_back(tmp);
    }
    rep(i, m) rep(j, m) {
        if(i==j) continue;
        double tmp;
        tmp=sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2));
        tmp/=2;
        dist[i].push_back(tmp);
    }
    double ans = numeric_limits<double>::max();
    rep(i, m) rep(j, dist[i].size()) ans=min(ans, dist[i][j]);
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
