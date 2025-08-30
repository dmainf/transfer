#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string t;
    cin >> n >> t;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<int> l(n, 0), r(n, 0);
    rep(i, n) {
        int idx=0;
        rep(j, s[i].size()) {
            if(s[i][j]==t[idx]) idx++;
        }
        l[i]=idx;
    }
    rep(i, n) reverse(all(s[i]));
    reverse(all(t));
    rep(i, n) {
        int idx=0;
        rep(j, s[i].size()) {
            if(s[i][j]==t[idx]) idx++;
        }
        r[i]=idx;
    }
    reverse(all(r));
    sort(all(r));
    ll ans=0;
    rep(i, n) {
        int it=lower_bound(all(r), t.size()-l[i])-r.begin();
        ans+=n-it;
    }
    cout << ans << endl;

    return 0;
}