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
const int INF=1e8;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n, 0));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b]=G[b][a]=1;
    }
    //G[]上にもともと何本辺があるか
    auto f=[&](vector<int> c) {
        if(c.size()==0) return 0;
        if(c.size()<=2) return -INF;
        c.push_back(c[0]);  //閉路にする
        int res=0;
        rep(i, c.size()-1) res+=G[c[i]][c[i+1]];
        return res;
    };
    vector<int> p(n);
    rep(i, n) p[i]=i;
    int ans=INF;
    do {
        rep(i, n) {
            int can_left=0;
            can_left+=f(vector<int>(p.begin(), p.begin()+i));
            can_left+=f(vector<int>(p.begin()+i, p.end()));
            ans=min(ans, m+n-2*can_left);
        }
    } while(next_permutation(all(p)));
    cout << ans << endl;

    return 0;
}