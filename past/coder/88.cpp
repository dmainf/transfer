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
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pi> s;
    for(int i=1; i<=n; i++) {
        int c;
        cin >> c;
        if(i%2==1) {
            if(s.size() && s.back().first==c) s.back().second++;
            else s.push_back({c, 1});
        } else {
            if(s.back().first==c) s.back().second++;
            else {
                int cnt=s.back().second+1;
                s.pop_back();
                if(!s.empty()) s.back().second += cnt;
                else s.push_back({c, cnt});
            }
        }
    }
    int ans=0;
    rep(i, s.size()) if(s[i].first==0) ans+=s[i].second;
    cout << ans << endl;

    return 0;
}