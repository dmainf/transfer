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
    int n, m; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    cin >> m;
    vector<set<int>> hunaka(n);
    rep(i, m) {
        int x, y; cin >> x >> y;
        x--; y--;
        hunaka[x].insert(y);
        hunaka[y].insert(x);
    }
    vector<int> p;
    rep(i, n) p.push_back(i);
    int ans=INF;
    do {
        int tmp=0;
        bool flag=false;
        rep(i, n-1) {
            if(hunaka[p[i]].count(p[i+1])) {
                flag=true;
                break;
            }
            tmp+=a[p[i]][i];
        }
        if(flag) continue;
        ans=min(ans, tmp+a[p.back()][n-1]);
    } while(next_permutation(all(p)));
    if(ans==INF) ans=-1;
    cout << ans << endl;

    return 0;
}