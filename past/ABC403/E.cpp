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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    int now=0;
    set<string> x, y;
    rep(qi, q) {
        int t;
        string s;
        cin >> t >> s;
        if(t==1) {
            x.insert(s);
            y.count(s);
        }
        if(t==2) {

        }
    }

    return 0;
}