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
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>> auth(m+1);
    set<int> kami;
    rep(qi, q) {
        int type;
        cin >> type;
        if(type==1) {
            int x, y;
            cin >> x >> y;
            auth[y].insert(x);
        }
        if(type==2) {
            int x;
            cin >> x;
            kami.insert(x);
        }
        if(type==3) {
            int x, y;
            cin >> x >> y;
            if(auth[y].count(x) || kami.count(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}