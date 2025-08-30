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
    int n;
    cin >> n;
    vector<int> seito(n), school(n);
    rep(i, n) cin >> seito[i];
    rep(i, n) cin >> school[i];
    sort(all(seito));
    sort(all(school));
    ll ans=0;
    rep(i, n) ans+=abs(seito[i]-school[i]);
    cout << ans << endl;

    return 0;
}