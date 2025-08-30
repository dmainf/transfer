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
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> diff(n-1);
    rep(i, n-1) diff[i]=(a[i]!=a[i+1]);
    int ans=0;
    int cnt=0;
    int l=0;
    rep(r, n-1) {
        if(diff[r]==0) cnt++;
        while(cnt>2) {
            if(diff[l]==0) cnt--;
            l++;
        }
        ans=max(ans, r-l+1);
    }
    ans++;
    if(ans>n) ans=n;
    cout << ans << endl;

    return 0;
}