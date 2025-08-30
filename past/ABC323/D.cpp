#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
using pl = pair<ll, ll>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<ll, ll> mp;
    rep(i, n) {
        int s, c;
        cin >> s >> c;
        mp[s]=c;
    }
    ll ans=0;
    while(mp.size()) {
        auto [size, cnt]=*mp.begin();
        mp.erase(mp.begin());
        ans+=cnt%2;
        if(cnt/2) mp[size*2]+=cnt/2;
    }
    cout << ans << endl;

    return 0;
}
