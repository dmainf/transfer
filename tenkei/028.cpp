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
const int MAX=1e3+1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> imos(MAX, vector<int>(MAX, 0));
    rep(i, n) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        imos[lx][ly]++;
        imos[rx][ry]++;
        imos[lx][ry]--;
        imos[rx][ly]--;
    }
    rep(i, MAX) for(int j=1; j<MAX; j++) {
        imos[i][j]+=imos[i][j-1];
    }
    for(int i=1; i<MAX; i++) rep(j, MAX) {
        imos[i][j]+=imos[i-1][j];
    }
    vector<int> ans(n+1, 0);
    rep(i, MAX) rep(j, MAX) {
        ans[imos[i][j]]++;
    }
    for (int i=1; i<=n; i++) cout << ans[i] << endl;

    return 0;
}