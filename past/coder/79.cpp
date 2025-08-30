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
    vector<vector<int>> s(n+1, vector<int>(n+1, 0));
    rep(i, m) {
        int l, r;
        cin >> l >> r;
        s[l][r]++;
    }
    rep(i, n) rep(j, n) {
        s[i+1][j+1]+=s[i+1][j]+s[i][j+1]-s[i][j];
    }
    rep(i, q) {
        int p, q;
        cin >> p >> q;
        cout << s[q][q]-s[p-1][q]-s[q][p-1]+s[p-1][p-1] << endl;
    }

    return 0;
}