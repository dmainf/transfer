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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    cin >> n >> m >> l;
    vector<pi> a, b;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        a.push_back({tmp, i});
    }
    rep(i, m) {
        int tmp;
        cin >> tmp;
        b.push_back({tmp, i});
    }
    vector<set<int>> dame(n);
    rep(i, l) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        dame[c].insert(d);
    }
    sort(rall(a));
    sort(rall(b));
    ll ans=0;
    for(auto main:a) {
        int mainPrice=main.first;
        int maini=main.second;
        for(auto side:b) {
            int sidePrice=side.first;
            int sidei=side.second;
            if(dame[maini].find(sidei)==dame[maini].end()) {
                ans=max(ans, (ll)mainPrice+sidePrice);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}