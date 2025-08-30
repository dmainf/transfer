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
    vector<vector<int>> a(9, vector<int>(9));
    rep(i, 9) rep(j, 9) cin >> a[i][j];
    vector<set<int>> row(9), col(9);
    vector<vector<set<int>>> squ(3, vector<set<int>>(3)); 
    rep(i, 9) rep(j, 9) {
        row[i].insert(a[i][j]);
        col[j].insert(a[i][j]);
        squ[i/3][j/3].insert(a[i][j]);
    }
    bool flag=true;
    rep(i, 9) if(row[i].size()!=9) flag=false;
    rep(i, 9) if(col[i].size()!=9) flag=false;
    rep(i, 3) rep(j, 3) if(squ[i][j].size()!=9) flag=false;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}