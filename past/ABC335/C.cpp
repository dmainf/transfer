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
    int n, q;
    cin >> n >> q;
    vector<pi> dra;
    rep(i, n) dra.push_back({n-i, 0});
    auto f=[&](char x) {
        pi p=dra.back();
        if(x=='R') p.first++;
        if(x=='L') p.first--;
        if(x=='U') p.second++;
        if(x=='D') p.second--;
        return p;
    };
    vector<pi> ans;
    rep(qi, q) {
        int query;
        cin >> query;
        if(query==1) {
            char c;
            cin >> c;
            auto tmp=f(c);
            dra.push_back(tmp);
        } else {
            int p;
            cin >> p;
            int index=dra.size()-p;
            ans.push_back(dra[index]);
        }
    }
    for(auto [x,y]:ans) cout << x << " " << y << endl;

    return 0;
}