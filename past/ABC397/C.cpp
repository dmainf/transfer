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
    rep(i, n) cin >> a[i];
    vector<int> l(n+1, 0), r(n+1, 0);
    int dl = 0, dr = 0;
    for(int x : a) {
        if(r[x] == 0) dr++;
        r[x]++;
    }
    int ans = 0;
    rep(i, n-1) {
        int x = a[i];
        l[x]++;
        if(l[x] == 1) dl++;
        r[x]--;
        if(r[x] == 0) dr--;
        ans = max(ans, dl + dr);
    }
    cout << ans << endl;
    
    return 0;
}