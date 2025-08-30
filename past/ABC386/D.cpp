#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,0,-1,0};
const int dj[]={0,1,0,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, char>> p;
    rep(i, m) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        p.push_back({x, y, c});
    }
    sort(rall(p));
    int maxY=0;
    for(auto [x, y, c]:p) {
        if(c=='B') {
            maxY=max(maxY, y);
        } else if(y<=maxY) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}