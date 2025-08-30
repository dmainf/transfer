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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));;
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];
    vector<int> p, q;
    rep(i, h) p.push_back(i);
    rep(i, w) q.push_back(i);
    int ans=INF;
    do {
        do {
            int flag=true;
            rep(i, h) rep(j, w) if(a[p[i]][q[j]]!=b[i][j]) {
                flag=false;
            }
            if(!flag) continue;
            int pn=0, qn=0;
            rep(i, h) rep(j, h) if(i<j && p[i]>p[j]) {
                pn++;
            }
            rep(i, w) rep(j, w) if(i<j && q[i]>q[j]) {
                qn++;
            }
            ans=min(ans, pn+qn);
        } while(next_permutation(all(q)));
    } while(next_permutation(all(p)));
    if(ans==INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
