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
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;
    auto c2=[&](ll x) -> ll { return x*(x-1)/2; };
    vector<vector<int>> is(n);
    rep(i, n) is[a[i]].push_back(i);
    ll ans=0;
    rep(x, n) {
        ll sx=0;
        {
            //番兵
            is[x].push_back(n);
            int pre=-1;
            //
            for(auto i:is[x]) {
                sx+=c2(i-pre);
                pre=i;
            }
        }
        ans+=c2(n+1)-sx;
    }
    cout << ans << endl;

    return 0;
}