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
    vector<int> event;
    rep(i, n) {
        int t, x;
        cin >> t >> x;
        if(t==1) event.push_back(x);
        if(t==2) event.push_back(-x);
    }
    reverse(all(event));
    vector<int> cnt(n+1);
    vector<int> ans;
    int now=0, mx=0;
    for(auto x:event) {
        if(x>0) {
            if(cnt[x]) {
                cnt[x]--;
                now--;
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        } else {
            cnt[-x]++;
            now++;
        }
        mx=max(mx, now);
    }
    if(now>0) cout << -1 << endl;
    else {
        cout << mx << endl;
        reverse(all(ans));
        for(auto x:ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}