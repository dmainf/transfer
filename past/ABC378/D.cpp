#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
using ll = long long;
const int di[]={-1,0,1,0};
const int dj[]={0,-1,0,1};
int h, w;
int f(int i, int j, int k, vector<string> s) {
    if(k==0) return 1;
    s[i][j]='*';
    int res=0;
    rep(v, 4) {
        int ni=i+di[v], nj=j+dj[v];
        if(ni<0 || nj<0 || h<=ni || w<=nj) continue;
        if(s[ni][nj]!='.') continue;
        res+=f(ni, nj, k-1, s);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ans=0;
    rep(i, h) rep(j, w) {
        if(s[i][j]=='#') continue;
        ans+=f(i, j, k, s);
    }
    cout << ans << endl;

    return 0;
}
