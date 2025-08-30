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
    int n; cin >> n;
    string t; cin >> t;
    //num of 0 is even === ok
    vector<int> pre(n+1, 0);
    rep(i, n) pre[i+1]=pre[i]+(t[i]=='0' ? 1:0);
    map<int, ll> mp;
    ll ans=0;
    rep(i, n+1) {
        int tmp=pre[i]%2;
        ans+=mp[tmp];
        mp[tmp]++;
    }
    cout << ans << endl;

    return 0;
}