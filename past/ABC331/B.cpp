#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
struct Kakuyasu {
    int i;
    int yen;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, m, l;
    cin >> n >> s >> m >> l;
    int ans=INF;
    rep(i, 100) rep(j, 100) rep(k, 100) {
        if(n<=6*i+8*j+12*k) ans=min(ans, s*i+m*j+l*k);
    }
    cout << ans << endl;

    return 0;
}