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
    int n, t;
    cin >> n >> t;
    vector<ll> score(n, 0);
    unordered_map<ll, ll> cnt;
    cnt[0]=n;
    int ans=1;
    rep(i, t) {
        int a, b;
        cin >> a >> b;
        a--;
        if(cnt[score[a]]==1) ans--;
        cnt[score[a]]--;
        score[a]+=b;
        if(cnt[score[a]]==0) ans++;
        cnt[score[a]]++;
        cout << ans << endl;
    }
    return 0;
}
