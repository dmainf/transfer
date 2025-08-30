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
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> planet(m);
    rep(i, m) cin >> planet[i];
    vector<vector<int>> jan(m+1, vector<int>(n+1, 0));
    vector<vector<int>> oce(m+1, vector<int>(n+1, 0));
    vector<vector<int>> ice(m+1, vector<int>(n+1, 0));
    rep(i, m) rep(j, n) {
        jan[i+1][j+1]=jan[i+1][j]+jan[i][j+1]-jan[i][j];
        oce[i+1][j+1]=oce[i+1][j]+oce[i][j+1]-oce[i][j];
        ice[i+1][j+1]=ice[i+1][j]+ice[i][j+1]-ice[i][j];
        if(planet[i][j]=='J') jan[i+1][j+1]++;
        if(planet[i][j]=='O') oce[i+1][j+1]++;
        if(planet[i][j]=='I') ice[i+1][j+1]++;
    }
    rep(i, k) {
        int li, lj, ri, rj;
        cin >> li >> lj >> ri >> rj;
        cout << jan[ri][rj]-jan[li-1][rj]-jan[ri][lj-1]+jan[li-1][lj-1] << " ";
        cout << oce[ri][rj]-oce[li-1][rj]-oce[ri][lj-1]+oce[li-1][lj-1] << " ";
        cout << ice[ri][rj]-ice[li-1][rj]-ice[ri][lj-1]+ice[li-1][lj-1] << endl;        
    }

    return 0;
}
