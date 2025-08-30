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
    int t;
    cin >> t;
    vector<int> ans;
    rep(ti, t) {
        int n;
        cin >> n;
        vector<int> a(n*2);
        rep(i, n*2) cin >> a[i], a[i]--;
        vector<vector<int>> is(n);
        rep(i, n*2) is[a[i]].push_back(i);
        set<pi> cand;
        //only count pair 1time that 1 swap makes 
        rep(i, n*2-1) {
            int x=a[i], y=a[i+1];
            if(x>y) swap(x, y);
            if(x==y) continue;
            cand.insert({x, y});
        }
        int tmp=0;
        for(auto [x, y]:cand) {
            int xl=is[x][0], xr=is[x][1];
            int yl=is[y][0], yr=is[y][1];
            //already complete
            if(xl+1==xr) continue;
            if(yl+1==yr) continue;
            //x y … x y
            //y x … y x
            if(abs(xl-yl)==1 && abs(xr-yr)==1) tmp++;
        }
        ans.push_back(tmp);
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}