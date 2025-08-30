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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<int> row(h, 0), col(w, 0);
    rep(i, h) rep(j, w) {
        row[i]+=a[i][j];
        col[j]+=a[i][j];
    }
    rep(i, h) {
        rep(j, w) {
            if(j!=0) cout << " ";
            cout << row[i]+col[j]-a[i][j];
        }
        cout << endl;
    }

    return 0;
}