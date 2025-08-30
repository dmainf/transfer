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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    rep(i, m) rep(j, n) {
        cin >> a[i][j];
        a[i][j]--;
    }
    vector<vector<bool>> nakayoshi(n, vector<bool>(n, false));
    rep(i, m) rep(j, n-1) {
        nakayoshi[a[i][j]][a[i][j+1]]=true;
        nakayoshi[a[i][j+1]][a[i][j]]=true;
    }
    int ans=0;
    rep(i, n) rep(j, n) if(!nakayoshi[i][j]) {
        ans++;
    }
    ans-=n;
    cout << ans/2 << endl;

    return 0;
}