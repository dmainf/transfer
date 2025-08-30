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
    map<int, int> cnt;
    rep(i, 7) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for(auto [x, c]:cnt) for(auto [y, d]:cnt) {
        if(x==y) continue;
        if(2<=c && 3<=d) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}