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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int ans=0;
    int r=0;
    rep(l, n) {
        while(r<n) {
            if(l<r && a[r]-a[l]>=m) break; 
            r++;
        }
        ans=max(ans, r-l);
    }
    cout << ans << endl;

    return 0;
}