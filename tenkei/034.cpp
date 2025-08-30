#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans=0;
    map<int, int> mp;
    int cnt=0;
    int r=0;
    rep(l, n) {
        while(r<n) {
            if(mp[a[r]]==0) {
                if(cnt==k) break;
                cnt++;
            }
            mp[a[r]]++;
            r++;
        }
        ans=max(ans, r-l);
        mp[a[l]]--;
        if(mp[a[l]]==0) cnt--;
    }
    cout << ans << endl;

    return 0;
}