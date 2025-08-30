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
    int n;
    cin >> n;
    vector<int> w(n), x(n);
    rep(i, n) cin >> w[i] >> x[i];
    int ans=0;
    rep(start, 24) {
        int tmp=0;
        rep(i, n) {
            int time=(start+x[i])%24;
            if(9<=time && time+1<=18) tmp+=w[i];
        }
        ans=max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}