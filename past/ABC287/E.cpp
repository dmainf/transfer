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
#include <atcoder/string>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<string, int>> s(n);
    rep(i, n) {
        cin >> s[i].first;
        s[i].second=i;
    }
    sort(all(s));
    vector<int> ans(n);
    rep(i, n-1) {
        auto [a, ai]=s[i];
        auto [b, bi]=s[i+1];
        int now=0;
        while(now<a.size() && now<b.size()) {
            if(a[now]!=b[now]) break;
            now++;
        }
        ans[ai]=max(ans[ai], now);
        ans[bi]=max(ans[bi], now);
    }
    rep(i, n) cout << ans[i] << endl;

    return 0;
}