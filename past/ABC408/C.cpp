#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    //1 2 3 4 5 6 7 8 9 10
    //111111111-1
    //      1-1
    //        1111111111-1
    //            111111-1
    vector<int> wall(n, 0);
    rep(i, m) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        wall[l]++;
        wall[r+1]--;
    }
    vector<int> pre(n+1, 0);
    rep(i, n) pre[i+1]=pre[i]+wall[i];
    int ans=INF;
    rep(i, n) ans=min(ans, pre[i+1]);
    cout << ans << endl;

    return 0;
}