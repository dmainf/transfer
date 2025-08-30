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
    map<int, pi> cnt;
    rep(i, n) {
        int a;
        cin >> a;
        cnt[a].first++;
        cnt[a].second=i+1;
    }
    int ans=0;
    for(auto [num, cnt]:cnt) {
        if(1<cnt.first) continue;
        ans=cnt.second;
    }
    if(ans==0) ans=-1;
    cout << ans << endl;


    return 0;
}