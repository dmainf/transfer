#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    vector<vector<int>> a(m);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int tmp;
            cin >> tmp;
            tmp--;
            a[i].push_back(tmp);
        }
    }
    vector<set<int>> zoo(n);
    rep(i, m) for(auto x:a[i]) {
        zoo[x].insert(i);
    }
    ll ans=INF;
    rep(x, 1<<n) {
        vector<int> animalx(m, 0);
        ll costx=0;
        rep(bitx, n) if((x>>bitx)&1) {
            costx+=(ll)c[bitx];
            for(auto tmpx:zoo[bitx]) {
                animalx[tmpx]++;
            }
        }
        rep(y, 1<<n) {
            auto animal=animalx;
            ll cost=costx;
            rep(bit, n) if((y>>bit)&1) {
                cost+=(ll)c[bit];
                for(auto tmp:zoo[bit]) {
                    animal[tmp]++;
                }
            }
            bool flag=true;
            rep(i, m) if(animal[i]<2) {
                flag=false;
            }
            if(flag) ans=min(ans, cost);
        }
    }
    cout << ans << endl;

    return 0;
}