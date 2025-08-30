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
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    int n=min(h, w);
    vector<int> ans(n, 0);
    rep(i, h) rep(j, w) if(c[i][j]=='#') {
        int mx_size=-1;
        for(int size=1; size<=n; size++) {
            if(i-size<0 || h<=i+size) break;
            if(j-size<0 || w<=j+size) break;;
            if(c[i+size][j+size]!='#') break;
            if(c[i+size][j-size]!='#') break;
            if(c[i-size][j+size]!='#') break;
            if(c[i-size][j-size]!='#') break;
            mx_size=size;;
        }
        if(mx_size!=-1) ans[mx_size-1]++;
    }
    for(int x:ans) cout << x << " ";
    cout << endl;
    return 0;
}