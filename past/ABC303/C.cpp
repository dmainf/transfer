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
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pi> item; 
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        item.insert({y, x});
    }
    int x=0, y=0;
    rep(i, n) {
        h--;
        if(h<0) {
            NO;
            return 0;
        }
        if(s[i]=='R') x++;
        if(s[i]=='L') x--;
        if(s[i]=='U') y++;
        if(s[i]=='D') y--;
        if(item.count({y, x}) && h<k) {
            h=k;
            item.erase({y, x});
        }
    }
    YES;

    return 0;
}