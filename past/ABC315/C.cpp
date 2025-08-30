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
    int  n;
    cin >> n;
    vector<pi> cream(n);
    rep(i, n) {
        int f, s;
        cin >> f >> s;
        cream[i]={s, f};
    }
    sort(rall(cream));
    ll ans;
    auto [kakuval, kakuaji]=cream[0];
    for(int i=1; i<n; i++) {
        int tmp=cream[i].second==kakuaji ? cream[i].first/2:cream[i].first;
        ans=max(ans, (ll)kakuval+tmp);
    }
    cout << ans << endl;

    return 0;
}