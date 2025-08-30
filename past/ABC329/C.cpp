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
struct RLE {
    char c;
    int cnt;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<RLE> p;
    rep(i, n) {
        if(!p.empty() && p.back().c==s[i]) p.back().cnt++;
        else p.push_back({s[i], 1});
    }
    map<char, int> mp;
    rep(i, p.size()) mp[p[i].c]=max(mp[p[i].c], p[i].cnt);
    int ans=0;
    for(auto [m, x]:mp) {
        ans+=x;
    }
    cout << ans << endl;

    return 0;
}