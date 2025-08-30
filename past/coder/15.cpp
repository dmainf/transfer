#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define drep(i, n) for(int i=(n)-1;i>=0;i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
struct P {
    int x, y;
    bool operator<(const P &other) const {
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i, n) cin >> p[i].x >> p[i].y;
    sort(all(p));
    double ans=0;
    int cnt=0;
    do {
        rep(i, p.size()) {
            if(i==0) continue;
            ans+=sqrt((double)pow(p[i].x-p[i-1].x, 2)+(double)pow(p[i].y-p[i-1].y, 2));
        }
        cnt++;
    } while(next_permutation(all(p)));
    cout << fixed << setprecision(10) << ans/cnt << endl;

    return 0;
}