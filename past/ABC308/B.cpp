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
    int n, m;
    cin >> n >> m;
    vector<string> c(n);
    rep(i, n) cin >> c[i];
    vector<string> d(m);
    vector<int> p(m+1);
    map<string, int> mp;
    rep(i, m) cin >> d[i];
    rep(i, m+1) cin >> p[i];
    rep(i, m) mp[d[i]]=p[i+1];
    int ans=0;
    rep(i, n) {
        if(mp.find(c[i])==mp.end()) ans+=p[0];
        else ans+=mp[c[i]];
    }
    cout << ans << endl;

    return 0;
}