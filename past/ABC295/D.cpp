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
    string s;
    cin >> s;
    map<vector<int>, int> mp;
    vector<int> now(10, 0);
    mp[now]++;
    rep(i, s.size()) {
        int tmp=s[i]-'0';
        now[tmp]++;
        now[tmp]%=2;
        mp[now]++;
    }
    ll ans=0;
    for(auto [z, x]:mp) {
        if(x<2) continue;
        ans+=(ll)x*(x-1)/2;
    }
    cout << ans << endl;

    return 0;
}