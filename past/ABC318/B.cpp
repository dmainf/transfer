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
    int n;
    cin >> n;
    vector<vector<bool>> b(109, vector<bool>(109, false));
    rep(i, n) {
        int xs, xg, ys, yg;
        cin >> xs >> xg >> ys >> yg;
        for(int i=ys; i<yg; i++) {
            for(int j=xs; j<xg; j++) {
                b[i][j]=true;
            }
        }
    }
    int ans=0;
    rep(i, 109) rep(j, 109) {
        if(b[i][j]) ans++;
    }
    cout << ans << endl;

    return 0;
}