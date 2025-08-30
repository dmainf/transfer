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
    vector<int> left(n);
    left[0]=1;
    rep(i, n) {
        if(i==0) continue;
        left[i]=min(left[i-1]+1, a[i]);
    }
    vector<int> b=a;
    reverse(all(b));
    vector<int> right(n);
    right[0]=1;
    rep(i, n) {
        if(i==0) continue;
        right[i]=min(right[i-1]+1, b[i]);
    }
    reverse(all(right));
    int ans=0;
    rep(i, n) ans=max(ans, min(left[i], right[i]));
    cout << ans << endl;

    return 0;
}
