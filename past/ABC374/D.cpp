#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) sort(a.begin(), a.end())
#define rall(a) sort(a.rbegin(), a.rend())
double dist(pair<int, int> pos, pair<int, int> a) {
    double dx=pos.first-a.first;
    double dy=pos.second-a.second;
    return sqrt(dx*dx+dy*dy);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, t;
    cin >> n >> s >> t;
    vector<pair<pair<int, int>, pair<int, int>>> line(n);
    rep(i, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        line[i]={{a, b}, {c, d}};
    }
    vector<int> p(n);
    rep(i, n) p[i]=i;
    int dx=0, dy=0;
    double ans=1e18;
    do {
    //線の順番
        rep(x, 1<<n) {
        //線の順番に毎回ビットを割り当てる
            double now=0;
            pair<int, int> pos={0, 0};
            rep(bit, n) {
            //始点と終点をswapするか
                pair<int, int> a={line[p[bit]].first.first, line[p[bit]].first.second};
                pair<int, int> b={line[p[bit]].second.first, line[p[bit]].second.second};
                if(x>>bit&1) swap(a, b);
                now+=dist(pos, a)/s;
                now+=dist(a, b)/t;
                pos=b;
            }
            ans=min(ans, now);
        }
    } while(next_permutation(p.begin(), p.end()));
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
