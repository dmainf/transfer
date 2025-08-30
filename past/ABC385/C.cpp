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
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    int ans=0;
    for(int w=1; w<=n; w++) {
        rep(si, w) {
            vector<pi> p;
            for(int i=si; i<n; i+=w) {
                if(p.size() && p.back().first==h[i]) p.back().second++;
                else p.push_back({h[i], 1});
            }
            rep(i, p.size()) ans=max(ans, p[i].second);
        }
    }
    cout << ans << endl;

    return 0;
}